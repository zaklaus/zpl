#define ZPL_IMPLEMENTATION
#define ZPL_NANO
#define ZPL_ENABLE_JOBS
#define ZPL_JOBS_ENABLE_DEBUG
#include <zpl.h>

int rand(void);

#define N (10 * 1000)
#define NL 1000
#define CORES 4
#define RAND_RANGE(min,max) (min + rand() % (max-min))

zpl_global zpl_u64 counter = 0;
zpl_global zpl_u32 iter = 0;
zpl_global zpl_atomic32 total_jobs;

#if defined(ZPL_MODULE_THREADING)

void do_work(void *data) {
    zpl_unused(data);
    zpl_atomic32_fetch_add(&total_jobs, 1);
}

const char *levels[] = {
    "REALTIME",
    "HIGH",
    "NORMAL",
    "LOW",
    "IDLE",
};

int main() {
    zpl_thread_pool p={0};
    zpl_jobs_init_with_limit(&p, zpl_heap(), CORES, NL);
    zpl_u64 process_time = 0;
    zpl_f64 avg_delta_time = 0;
    zpl_atomic32_store(&total_jobs, 0);
    counter = N;

    printf("Jobs test, run duration: %d ms. Ran on %d cores.\nWe spawn %d jobs per cycle.\n", N, CORES, NL);

    while (counter > 0) {
        zpl_u64 last_time = zpl_time_rel_ms();
        for (int i=0; i<NL; i++) {
            zpl_u32 prio = i % ZPL_JOBS_MAX_PRIORITIES;
            zpl_jobs_enqueue_with_priority(&p, do_work, 0, (zpl_jobs_priority)prio);
        }

        if (iter % 15 == 0) {
            printf("Time left: %lld ms            \r", counter);
        }

        zpl_u64 curr_time = zpl_time_rel_ms();
        zpl_jobs_process(&p);
        zpl_u64 delta_time = zpl_time_rel_ms() - curr_time;
        avg_delta_time += delta_time;
        iter++;
        counter -= zpl_time_rel_ms() - last_time;
    }

    process_time = avg_delta_time;
    avg_delta_time /= iter;
    zpl_u32 jobs_result = zpl_atomic32_load(&total_jobs);
    printf("%-80s\n", "Done!");
    printf("\nTest is done, results:\n* %lld ms total.\n* %.08f ms average.\n* total jobs processed: %d.\n", process_time, avg_delta_time, jobs_result);
    printf("\nPer priority queue stats:\n");
    for (int i = 0; i < ZPL_JOBS_MAX_PRIORITIES; ++i) {
        zpl_thread_queue *q = &p.queues[i];
        printf("* %-8s chance: %-4d hits: %d.\n", levels[i], q->chance, q->hits);
    }

    printf("\nPer thread worker stats:\n");
    for (zpl_usize i = 0; i < p.max_threads; ++i) {
        zpl_thread_worker *tw = p.workers + i;
        printf("* worker %-2d hits: %-8d idle: %d cy.\n", i, tw->hits, tw->idle);
    }
    zpl_jobs_free(&p);
    return 0;
}
#else
int main(){return 0;}
#endif
