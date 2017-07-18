#define ZPL_IMPLEMENTATION
#include "zpl.h"

int main() {
    // NOTE(inlife): create and allocate a bitstream
    // with size of 100 bytes
    zpl_bs_t bsp;
    zpl_bs_init(bsp, zpl_heap_allocator(), 100);

zpl_printf("sizeof f64: %zu\n", zpl_size_of(f64));

// zpl_printf("before: capacity %zu, size: %zu\n", zpl_bs_capacity(bsp), zpl_bs_size(bsp));

    // NOTE(inlife): write a typed values
    // (values will be automatically casted)
    zpl_bs_write_u8(bsp, 1);

zpl_printf("after: capacity %zu, size: %zu\n", zpl_bs_write_pos(bsp), zpl_bs_read_pos(bsp));
    // zpl_bs_write_i64(bsp, -42230);
    // zpl_bs_write_u64(bsp, 32);

    // // NOTE(inlife): read a typed value
    // f64 boo = zpl_bs_read_f64(bsp);

    // // NOTE(inlife): read a data from a particular place
    // i64 foo = zpl_bs_read_i64_at(bsp, 8);

    // // NOTE(inlife): write a data into particular place
    // zpl_bs_write_u64_at(bsp, 8, 8 + 4);

    // zpl_printf("%f %lld\n", boo, foo);

    // // NOTE(inlife): helper methods
    // zpl_bs_size(bsp); // get actual written size of the bitstream
    // zpl_bs_capacity(bsp); // get allocated capacity
    // zpl_bs_read_pos(bsp);
    // zpl_bs_write_pos(bsp);

    // NOTE(inlife): free the resources
    zpl_bs_free(bsp);

    return 0;
}
