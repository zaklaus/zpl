#ifdef ZPL_EDITOR
    #include <zpl.h>
    #include "unit.h"
#endif

MODULE(stream, {
    const char test[] = "Hello World!";
    char buf[80] = {0};
    zpl_isize len = zpl_strlen(test);
    zpl_file f;

    IT("can read data from the stream", {
        zpl_file_stream_open(&f, zpl_heap(), cast(zpl_u8*) test, len, 0);
        zpl_file_read(&f, buf, len);
        zpl_file_close(&f);
        STREQUALS(buf, test);
    });

    IT("can append data to the stream", {
        const char hello2yello[] = "Yello";
        zpl_file_stream_open(&f, zpl_heap(), cast(zpl_u8*) test, len, ZPL_FILE_STREAM_CLONE_WRITABLE);
        zpl_file_write_at(&f, hello2yello, zpl_strlen(hello2yello), 0);
        zpl_file_read(&f, buf, len);
        zpl_file_close(&f);
        STREQUALS(buf, "Yello World!");
    });

    IT("can create a new memory stream", {
        const char message[] = "Ryan started the fire!";
        zpl_isize msglen = zpl_strlen(message);
        zpl_file_stream_new(&f, zpl_heap());
        zpl_file_write(&f, message, msglen);
        zpl_file_seek(&f, 0);
        zpl_file_read(&f, buf, msglen);
        zpl_file_close(&f);
        STREQUALS(buf, message);
    });
});
