/**
  ZPL - Your (almost) C99 Powerkit

Usage:
  #define ZPL_IMPLEMENTATION exactly in ONE source file right BEFORE including the library, like:

  #define ZPL_IMPLEMENTATION
  #include "zpl.h"

  You can also use a freestanding version of ZPL by using ZPL_NANO, like:

  #define ZPL_IMPLEMENTATION
  #define ZPL_NANO
  #include "zpl.h"

Options:

  ZPL_EDITOR - This macro should be used by the IDE's Intellisense to parse ZPL correctly. It can NEVER be used for actual compilation of the library!
  ZPL_EXPOSE_TYPES - exposes all ZPL defined types to the global namespace. This means type such as `zpl_u32` is now available as `u32` globally.
  ZPL_DEFINE_NULL_MACRO - to let ZPL define what NULL stands for in case it is undefined.
  ZPL_NO_MATH_H - disables the use of math.h library and replaces it with custom routines or SIMD.

Credits:
  Read AUTHORS.md

GitHub:
  https://github.com/zpl-c/zpl

Version History:
  12.0.0  - New jobs system

  11.0.0  - Rewrite the timer module

  10.13.0 - Initial ARM threading support
  10.12.1 - Fix missing zpL_alloc_str
  10.12.0 - Add zpl_crc64
  10.11.1 - Fix zpl_time_utc_ms on 32-bit OSes
  10.11.0 - Added zpl_file_stream_buf
  10.10.3 - Math type-punning fixes
  10.10.1 - Fix memory writing issue + new write-only in-situ flag
  10.10.0 - Implement memory streaming API
  10.9.1  - Support ARMv6, ARMv7 and ARMv8-a builds
  10.9.0  - Improve the time API
  10.8.3  - zpl_file_close tempfile Windows fixes
  10.8.2  - zpl_file_temp disallow some operations
  10.8.1  - zpl_file_temp Windows fixes
  10.8.0  - Implemented zpl_json_write_string
  10.7.1  - Fix zpl_file_temp platform bug
  10.7.0  - Add zpl_file_write_contents
  10.6.6  - Fix type mismatch in Jobs system
  10.6.0  - Remove event system
  10.5.8  - Remove zpl__memcpy_4byte
  10.5.7  - zpl_file_new is now OS-agnostic constructor
  10.5.6  - Fix coroutine creation
  10.5.5  - Jobs system uses zpl_f32 for priority setting
  10.5.4  - zpl_buffer_free no longer takes the 2nd argument (allocator)
  10.5.3  - Removed crc64 and annotated some hashing methods
  10.5.2  - Don't expose ZPL types anymore
  10.5.1  - Fixed zpl_rdtsc for Emscripten
  10.5.0  - Changed casts to memcopy in random methods, added embed cmd
  10.4.1  - Jobs system now enqueues jobs with def priority of 1.0
  10.4.0  - [META] version bump
  10.3.0  - Pool allocator now supports zpl_free_all
  10.2.0  - [META] version bump
  10.1.0  - Additional math methods (thanks to funZX and msmshazan)
  10.0.15 - WIP Emscripten fixes
  10.0.14 - FreeBSD support
  10.0.13 - OpenBSD support
  10.0.12 - Cygwin fixes
  10.0.11 - Tweak module dependencies
  10.0.10 - Fix zero-allocation regression in filesystem module
  10.0.9 - Fix multi-compilation unit builds
  10.0.8 - Fix zpl_printf "%0d" format specifier
  10.0.4 - Flush tester output to fix ordering
  10.0.3 - Fix ZPL_STATIC_ASSERT under MSVC
  10.0.0 - Major overhaul of the library

  9.8.10 - JSON fix array-based documents with objects
  9.8.9 - JSON document structured as array now properly recognizes the root object as array.
  9.8.8 - Fixed an incorrect parsing of empty array nodes.
  9.8.7 - Improve FreeBSD support
  9.8.6 - WIP: Handle inlined methods properly
  9.8.5 - Fix incorrect usage of EOF and opts dependency on JSON5 module's methods
  9.8.4 - Fix MSVC ZPL_NO_MATH_H code branch using incorrect methods internally
  9.8.3 - Fix MinGW GCC related issue with zpl_printf %lld format
  9.8.2 - Fix VS C4190 issue
  9.8.1 - Fix several C++ type casting quirks
  9.8.0 - Incorporated OpenGL into ZPL core as an optional module
  9.7.0 - Added co-routine module
  9.6.0 - Added process module for creation and manipulation
  9.5.2 - zpl_printf family now prints (null) on NULL string arguments
  9.5.1 - Fixed JSON5 real number export support + indentation fixes
  9.5.0 - Added base64 encode/decode methods
  9.4.10- Small enum style changes
  9.4.9 - Remove #undef for cast and hard_cast (sorry)
  9.4.8 - Fix quote-less JSON node name resolution
  9.4.7 - Additional change to the code
  9.4.6 - Fix issue where zpl_json_find would have false match on substrings
  9.4.5 - Mistakes were made, fixed compilation errors
  9.4.3 - Fix old API shenanigans
  9.4.2 - Fix small API typos
  9.4.1 - Reordered JSON5 constants to integrate better with conditions
  9.4.0 - JSON5 API changes made to zpl_json_find
  9.3.0 - Change how zpl uses basic types internally
  9.2.0 - Directory listing was added. Check dirlist_api.c test for more info
  9.1.1 - Fix WIN32_LEAN_AND_MEAN redefinition properly
  9.1.0 - get_env rework and fixes
  9.0.3 - Small fixes and removals
  9.0.0 - New documentation format, removed deprecated code, changed styles

  8.14.1 - Fix string library
  8.14.0 - Added zpl_re_match_all
  8.13.0 - Update system command API
  8.12.6 - Fix warning in CLI options parser
  8.12.5 - Support parametric options preceding positionals
  8.12.4 - Fixed opts positionals ordering
  8.12.3 - Fixed incorrect handling of flags preceding positionals
  8.12.2 - JSON parsing remark added
  8.12.1 - Fixed a lot of important stuff
  8.12.0 - Added helper constructors for containers
  8.11.2 - Fix bug in opts module
  8.11.1 - Small code improvements
  8.11.0 - Ported regex processor from https://github.com/gingerBill/gb/ and applied fixes on top of it
  8.10.2 - Fix zpl_strtok
  8.10.1 - Replace zpl_strchr by zpl_char_last_occurence
  8.10.0 - Added zpl_strchr
  8.9.0  - API improvements for JSON5 parser
  8.8.4  - Add support for SJSON formatting http://bitsquid.blogspot.com/2009/10/simplified-json-notation.html

  6.8.3  - JSON5 exp fix
  6.8.2  - Bugfixes applied from gb
  6.8.1  - Performance improvements for JSON5 parser
  6.8.0  - zpl.h is now generated by build.py
  6.7.0  - Several fixes and added switches
  6.6.0  - Several significant changes made to the repository
  6.5.0  - Ported platform layer from https://github.com/gingerBill/gb/
  6.4.1  - Use zpl_strlen in zpl_strdup
  6.4.0  - Deprecated zpl_buffer_free and added zpl_array_end, zpl_buffer_end
  6.3.0  - Added zpl_strdup
  6.2.1  - Remove math redundancies
  6.2.0  - Integrated zpl_math.h into zpl.h
  6.1.1  - Added direct.h include for win c++ dir methods
  6.1.0  - Added zpl_path_mkdir, zpl_path_rmdir, and few new zplFileErrors
  6.0.4  - More MSVC(++) satisfaction by fixing warnings
  6.0.3  - Satisfy MSVC by fixing a warning
  6.0.2  - Fixed warnings for json5 i64 printfs
  6.0.1  - Fixed warnings for particual win compiler in dirlist method
  6.0.0  - New build, include/ was renamed to code/

  5.8.3  - Naming fixes
  5.8.2  - Job system now supports prioritized tasks
  5.8.1  - Renames zpl_pad to zpl_ring
  5.8.0  - Added instantiated scratch pad (circular buffer)
  5.7.2  - Added Windows support for zpl_path_dirlist
  5.7.1  - Fixed few things in job system + macOS support for zpl_path_dirlist
  5.7.0  - Added a job system (zpl_thread_pool)
  5.6.5  - Fixes extra error cases for zpl_opts when input is:
         - missing a value for an option,
         - having an extra value for a flag (e.g. --enable-log shouldn't get a value.)
  5.6.4  - Several tweaks to the zpl_opts API
  5.6.3  - Added support for flags without values
  5.6.2  - Improve error handling for zpl_opts
  5.6.1  - Added support for strings with spaces in zpl_opts
  5.6.0  - Added zpl_opts for CLI argument parsing
  5.5.1  - Fixed time method for win
  5.5.0  - Integrate JSON5 writer into the core
  5.4.0  - Improved storage support for numbers in JSON5 parser
  5.3.0  - Integrated zpl_json into ZPL
  5.2.0  - Added zpl_string_sprintf
  5.1.1  - Added zpl_system_command_nores for output-less execution
  5.1.0  - Added event handler
  5.0.4  - Fix alias for zpl_list
  5.0.3  - Finalizing syntax changes
  5.0.2  - Fix segfault when using zpl_stack_memory
  5.0.1  - Small code improvements
  5.0.0  - Project structure changes

  4.7.2  - Got rid of size arg for zpl_str_split_lines
  4.7.1  - Added an example
  4.7.0  - Added zpl_path_dirlist
  4.6.1  - zpl_memcopy x86 patch from upstream
  4.6.0  - Added few string-related functions
  4.5.9  - Error fixes
  4.5.8  - Warning fixes
  4.5.7  - Fixed timer loops. zpl_time* related functions work with seconds now
  4.5.6  - Fixed zpl_time_now() for Windows and Linux
  4.5.5  - Small cosmetic changes
  4.5.4  - Fixed issue when zpl_list_add would break the links
         - when adding a new item between nodes
  4.5.3  - Fixed malformed enum values
  4.5.1  - Fixed some warnings
  4.5.0  - Added zpl_array_append_at
  4.4.0  - Added zpl_array_back, zpl_array_front
  4.3.0  - Added zpl_list
  4.2.0  - Added zpl_system_command_str
  4.1.2  - GG, fixed small compilation error
  4.1.1  - Fixed possible security issue in zpl_system_command
  4.1.0  - Added zpl_string_make_reserve and small fixes
  4.0.2  - Warning fix for _LARGEFILE64_SOURCE
  4.0.1  - include stdlib.h for getenv (temp)
  4.0.0  - ARM support, coding style changes and various improvements

  3.4.1  - zpl_memcopy now uses memcpy for ARM arch-family
  3.4.0  - Removed obsolete code
  3.3.4  - Added Travis CI config
  3.3.3  - Small macro formatting changes + ZPL_SYSTEM_IOS
  3.3.2  - Fixes for android arm
  3.3.1  - Fixed some type cast warnings
  3.3.0  - Added Android support
  3.1.5  - Renamed userptr to user_data in timer
  3.1.4  - Fix for zpl_buffer not allocating correctly
  3.1.2  - Small fix in zpl_memcompare
  3.1.1  - Added char* conversion for data field in zpl_array_header
  3.1.0  - Added data field to zpl_array_header
  3.0.7  - Added timer userptr as argument to callback
  3.0.6  - Small changes
  3.0.5  - Fixed compilation for emscripten
  3.0.4  - Small fixes for tiny cpp warnings
  3.0.3  - Small fixes for various cpp warnings and errors
  3.0.2  - Fixed linux part, and removed trailing spaces
  3.0.1  - Small bugfix in zpl_file_open
  3.0.0  - Added several fixes and features

  2.4.0  - Added remove to hash table
  2.3.3  - Removed redundant code
  2.3.2  - Eliminated extra warnings
  2.3.1  - Warning hunt
  2.3.0  - Added the ability to copy array/buffer and fixed bug in hash table.
  2.2.1  - Used tmpfile() for Windows
  2.2.0  - Added zpl_file_temp
  2.1.1  - Very small fix (forgive me)
  2.1.0  - Added the ability to resize bitstream
  2.0.8  - Small adjustments
  2.0.7  - MinGW related fixes
  2.0.0  - New NPM based version

  1.2.2  - Small fix
  1.2.1  - Macro fixes
  1.2.0  - Added zpl_async macro
  1.1.0  - Added timer feature
  1.0.0  - Initial version

  This Software is dual licensed under the following licenses:

  Unlicense
  This is free and unencumbered software released into the public domain.

  Anyone is free to copy, modify, publish, use, compile, sell, or
  distribute this software, either in source code form or as a compiled
  binary, for any purpose, commercial or non-commercial, and by any
  means.

  In jurisdictions that recognize copyright laws, the author or authors
  of this software dedicate any and all copyright interest in the
  software to the public domain. We make this dedication for the benefit
  of the public at large and to the detriment of our heirs and
  successors. We intend this dedication to be an overt act of
  relinquishment in perpetuity of all present and future rights to this
  software under copyright law.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
  IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
  OTHER DEALINGS IN THE SOFTWARE.

  For more information, please refer to <http://unlicense.org/>

  BSD 3-Clause

  Copyright (c) 2016-2021 Dominik Madarász. All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  1. Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
  3. Neither the name of the copyright holder nor the names of its contributors
    may be used to endorse or promote products derived from this software without
    specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


*/

#ifndef ZPL_H
#define ZPL_H

#define ZPL_VERSION_MAJOR 10
#define ZPL_VERSION_MINOR 13
#define ZPL_VERSION_PATCH 2
#define ZPL_VERSION_PRE ""

#include "zpl_hedley.h"

#define ZPL_VERSION ZPL_VERSION_ENCODE(ZPL_VERSION_MAJOR, ZPL_VERSION_MINOR, ZPL_VERSION_PATCH)

#ifdef ZPL_IMPL
    #ifndef ZPL_IMPLEMENTATION
    #define ZPL_IMPLEMENTATION
    #endif
#endif

#if defined(__cplusplus) && !defined(ZPL_EXTERN)
    #define ZPL_EXTERN extern "C"
#else
    #define ZPL_EXTERN extern
#endif

#ifndef ZPL_DEF
    #if defined(ZPL_SHARED_LIB)
        #ifdef ZPL_IMPLEMENTATION
            #define ZPL_DEF ZPL_PUBLIC
        #else
            #define ZPL_DEF ZPL_IMPORT
        #endif
    #elif defined(ZPL_STATIC_LIB)
        #ifdef ZPL_IMPLEMENTATION
            #define ZPL_DEF
        #else
            #define ZPL_DEF ZPL_EXTERN
        #endif
    #elif defined(ZPL_STATIC)
        #define ZPL_DEF static
    #else
        #define ZPL_DEF ZPL_EXTERN
    #endif
#endif

#ifndef ZPL_DEF_INLINE
    #if defined(ZPL_STATIC)
        #define ZPL_DEF_INLINE
        #define ZPL_IMPL_INLINE
    #else
        #define ZPL_DEF_INLINE ZPL_ALWAYS_INLINE
        #define ZPL_IMPL_INLINE ZPL_INLINE
    #endif
#endif

/* Architecture-specific overrides */
#if defined(__ARM_ARCH) && defined(__cplusplus)
    #define ZPL_DISABLE_THREADING
#endif

/* Distributions */
#ifndef ZPL_CUSTOM_MODULES
    /* default distribution */
    #define ZPL_MODULE_CORE
    #define ZPL_MODULE_TIMER
    #define ZPL_MODULE_HASHING
    #define ZPL_MODULE_REGEX
    #define ZPL_MODULE_EVENT
    #define ZPL_MODULE_DLL
    #define ZPL_MODULE_OPTS
    #define ZPL_MODULE_PROCESS
    #define ZPL_MODULE_MATH
    #define ZPL_MODULE_JSON
    #define ZPL_MODULE_THREADING
    #define ZPL_MODULE_JOBS
    #define ZPL_MODULE_COROUTINES

    /* zpl nano distribution */
    #if defined(ZPL_NANO)
        #undef ZPL_MODULE_TIMER
        #undef ZPL_MODULE_HASHING
        #undef ZPL_MODULE_REGEX
        #undef ZPL_MODULE_EVENT
        #undef ZPL_MODULE_DLL
        #undef ZPL_MODULE_OPTS
        #undef ZPL_MODULE_PROCESS
        #undef ZPL_MODULE_MATH
        #undef ZPL_MODULE_JSON
        #undef ZPL_MODULE_THREADING
        #undef ZPL_MODULE_JOBS
        #undef ZPL_MODULE_COROUTINES
    #endif

    /* module enabling overrides */
    #if defined(ZPL_ENABLE_CORE) && !defined(ZPL_MODULE_CORE)
        #define ZPL_MODULE_CORE
    #endif
    #if defined(ZPL_ENABLE_TIMER) && !defined(ZPL_MODULE_TIMER)
        #define ZPL_MODULE_TIMER
    #endif
    #if defined(ZPL_ENABLE_HASHING) && !defined(ZPL_MODULE_HASHING)
        #define ZPL_MODULE_HASHING
    #endif
    #if defined(ZPL_ENABLE_REGEX) && !defined(ZPL_MODULE_REGEX)
        #define ZPL_MODULE_REGEX
    #endif
    #if defined(ZPL_ENABLE_DLL) && !defined(ZPL_MODULE_DLL)
        #define ZPL_MODULE_DLL
    #endif
    #if defined(ZPL_ENABLE_OPTS) && !defined(ZPL_MODULE_OPTS)
        #define ZPL_MODULE_OPTS
    #endif
    #if defined(ZPL_ENABLE_PROCESS) && !defined(ZPL_MODULE_PROCESS)
        #define ZPL_MODULE_PROCESS
    #endif
    #if defined(ZPL_ENABLE_MATH) && !defined(ZPL_MODULE_MATH)
        #define ZPL_MODULE_MATH
    #endif
    #if defined(ZPL_ENABLE_JSON) && !defined(ZPL_MODULE_JSON)
        #define ZPL_MODULE_JSON
    #endif
    #if defined(ZPL_ENABLE_THREADING) && !defined(ZPL_MODULE_THREADING)
        #define ZPL_MODULE_THREADING
    #endif
    #if defined(ZPL_ENABLE_JOBS) && !defined(ZPL_MODULE_JOBS)
        #ifndef ZPL_MODULE_THREADING
        #define ZPL_MODULE_THREADING /* dependency */
        #endif
        #define ZPL_MODULE_JOBS
    #endif
    #if defined(ZPL_ENABLE_COROUTINES) && !defined(ZPL_MODULE_COROUTINES)
        #ifndef ZPL_MODULE_THREADING
        #define ZPL_MODULE_THREADING /* dependency */
        #endif

        #ifndef ZPL_MODULE_JOBS
        #define ZPL_MODULE_JOBS /* dependency */
        #endif

        #define ZPL_MODULE_COROUTINES
    #endif

    /* module disabling overrides */
    #if defined(ZPL_DISABLE_CORE) && defined(ZPL_MODULE_CORE)
        #undef ZPL_MODULE_CORE
    #endif
    #if defined(ZPL_DISABLE_TIMER) && defined(ZPL_MODULE_TIMER)
        #undef ZPL_MODULE_TIMER
    #endif
    #if defined(ZPL_DISABLE_HASHING) && defined(ZPL_MODULE_HASHING)
        #undef ZPL_MODULE_HASHING
    #endif
    #if defined(ZPL_DISABLE_REGEX) && defined(ZPL_MODULE_REGEX)
        #undef ZPL_MODULE_REGEX
    #endif
    #if defined(ZPL_DISABLE_DLL) && defined(ZPL_MODULE_DLL)
        #undef ZPL_MODULE_DLL
    #endif
    #if defined(ZPL_DISABLE_OPTS) && defined(ZPL_MODULE_OPTS)
        #undef ZPL_MODULE_OPTS
    #endif
    #if defined(ZPL_DISABLE_PROCESS) && defined(ZPL_MODULE_PROCESS)
        #undef ZPL_MODULE_PROCESS
    #endif
    #if defined(ZPL_DISABLE_MATH) && defined(ZPL_MODULE_MATH)
        #undef ZPL_MODULE_MATH
    #endif
    #if defined(ZPL_DISABLE_JSON) && defined(ZPL_MODULE_JSON)
        #undef ZPL_MODULE_JSON
    #endif
    #if defined(ZPL_DISABLE_THREADING) && defined(ZPL_MODULE_THREADING)
        #ifdef ZPL_MODULE_JOBS
        #undef ZPL_MODULE_JOBS /* user */
        #endif

        #ifdef ZPL_MODULE_COROUTINES
        #undef ZPL_MODULE_COROUTINES /* user */
        #endif

        #undef ZPL_MODULE_THREADING
    #endif
    #if defined(ZPL_DISABLE_JOBS) && defined(ZPL_MODULE_JOBS)
        #ifdef ZPL_MODULE_COROUTINES
        #undef ZPL_MODULE_COROUTINES /* user */
        #endif

        #undef ZPL_MODULE_JOBS
    #endif
    #if defined(ZPL_DISABLE_COROUTINES) && defined(ZPL_MODULE_COROUTINES)
        #undef ZPL_MODULE_COROUTINES
    #endif
#endif

#if defined(__GCC__) || defined(__GNUC__) || defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunused-function"
    #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
    #pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#endif

#if defined(_MSC_VER)
    #pragma warning(push)
    #pragma warning(disable : 4201)
    #pragma warning(disable : 4127) // Conditional expression is constant
#endif

/* general purpose includes */

#include "header/core/system.h"

#include <stdarg.h>
#include <stddef.h>

#if defined(ZPL_SYSTEM_WINDOWS)
    #include <intrin.h>
#endif

#include "header/core/types.h"
#include "header/core/helpers.h"

#if defined(ZPL_MODULE_CORE)
    #include "header/core/debug.h"
    #include "header/core/memory.h"
    #include "header/core/memory_virtual.h"
    #include "header/core/memory_custom.h"
    #include "header/core/collections/array.h"
    #include "header/core/collections/buffer.h"
    #include "header/core/collections/list.h"
    #include "header/core/collections/ring.h"
    #include "header/core/collections/hashtable.h"
    #include "header/core/string.h"
    #include "header/core/stringlib.h"
    #include "header/core/file.h"
    #include "header/core/file_stream.h"
    #include "header/core/file_misc.h"
    #include "header/core/print.h"
    #include "header/core/time.h"
    #include "header/core/random.h"
    #include "header/core/misc.h"
    #include "header/core/sort.h"
#endif

#if defined(ZPL_MODULE_TIMER)
    #include "header/timer.h"
#endif

#if defined(ZPL_MODULE_HASHING)
    #include "header/hashing.h"
#endif

#if defined(ZPL_MODULE_REGEX)
    #include "header/regex.h"
#endif

#if defined(ZPL_MODULE_DLL)
    #include "header/dll.h"
#endif

#if defined(ZPL_MODULE_OPTS)
    #include "header/opts.h"
#endif

#if defined(ZPL_MODULE_PROCESS)
    #include "header/process.h"
#endif

#if defined(ZPL_MODULE_MATH)
    #include "header/math.h"
#endif

#if defined(ZPL_MODULE_JSON)
    #include "header/json.h"
#endif

#if defined(ZPL_MODULE_THREADING)
    #if defined(ZPL_SYSTEM_UNIX) || defined(ZPL_SYSTEM_MACOS)
        #include <pthread.h>
    #endif

    #if defined(ZPL_SYSTEM_WINDOWS)
        #if !defined(ZPL_NO_WINDOWS_H)
            #ifndef WIN32_LEAN_AND_MEAN
                #define NOMINMAX
                #define WIN32_LEAN_AND_MEAN
                #define WIN32_MEAN_AND_LEAN
                #define VC_EXTRALEAN
            #endif
            #include <windows.h>
            #undef NOMINMAX
            #undef WIN32_LEAN_AND_MEAN
            #undef WIN32_MEAN_AND_LEAN
            #undef VC_EXTRALEAN

            /* prevent it from including later */
            #define ZPL_NO_WINDOWS_H
        #endif

        // include errno.h for MinGW
        #if defined(ZPL_COMPILER_GCC)
            #include <errno.h>
        #endif
    #endif

    #if !defined(zpl_thread_local)
        #if defined(_MSC_VER) && _MSC_VER >= 1300
            #define zpl_thread_local __declspec(thread)
        #elif defined(__GNUC__)
            #define zpl_thread_local __thread
        #else
            #define zpl_thread_local thread_local
        #endif
    #endif

    #include "header/threading/atomic.h"
    #include "header/threading/fence.h"
    #include "header/threading/sem.h"
    #include "header/threading/mutex.h"
    #include "header/threading/thread.h"
    #include "header/threading/sync.h"
    #include "header/threading/affinity.h"

    #if defined(ZPL_MODULE_JOBS)
        #include "header/jobs.h"
    #endif

    #if defined(ZPL_MODULE_COROUTINES)
        #include "header/coroutines.h"
    #endif
#endif

#if defined(ZPL_COMPILER_MSVC)
    #pragma warning(pop)
#endif

#if defined(__GCC__) || defined(__GNUC__) || defined(__clang__)
    #pragma GCC diagnostic pop
#endif

#if defined(ZPL_IMPLEMENTATION) && !defined(ZPL_IMPLEMENTATION_DONE)
#define ZPL_IMPLEMENTATION_DONE

#if defined(__GCC__) || defined(__GNUC__) || defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wattributes"
    #pragma GCC diagnostic ignored "-Wunused-value"
    #pragma GCC diagnostic ignored "-Wunused-function"
    #pragma GCC diagnostic ignored "-Wwrite-strings"
    #pragma GCC diagnostic ignored "-Wunused-parameter"
    #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    #pragma GCC diagnostic ignored "-Wmissing-braces"
    #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
    #pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
    #pragma GCC diagnostic ignored "-Wignored-qualifiers"
#endif

#if defined(_MSC_VER)
    #pragma warning(push)
    #pragma warning(disable : 4201)
    #pragma warning(disable : 4996) // Disable deprecated POSIX functions warning
    #pragma warning(disable : 4127) // Conditional expression is constant
#endif

/* general purpose includes */

#include <stdio.h>

#if defined(ZPL_SYSTEM_UNIX) || defined(ZPL_SYSTEM_MACOS)
    #include <unistd.h>
    #include <errno.h>
#elif defined(ZPL_SYSTEM_WINDOWS)
    #if !defined(ZPL_NO_WINDOWS_H)
        #ifndef WIN32_LEAN_AND_MEAN
            #ifndef NOMINMAX
            #define NOMINMAX
            #endif

            #define WIN32_LEAN_AND_MEAN
            #define WIN32_MEAN_AND_LEAN
            #define VC_EXTRALEAN
        #endif
        #include <windows.h>
        #undef NOMINMAX
        #undef WIN32_LEAN_AND_MEAN
        #undef WIN32_MEAN_AND_LEAN
        #undef VC_EXTRALEAN
    #endif
#endif

#if defined(ZPL_MODULE_CORE)
    #include "source/core/debug.c"
    #include "source/core/memory.c"
    #include "source/core/memory_virtual.c"
    #include "source/core/memory_custom.c"
    #include "source/core/array.c"
    #include "source/core/string.c"
    #include "source/core/stringlib.c"
    #include "source/core/file.c"
    #include "source/core/file_stream.c"
    #include "source/core/file_misc.c"
    #include "source/core/print.c"
    #include "source/core/time.c"
    #include "source/core/random.c"
    #include "source/core/misc.c"
    #include "source/core/sort.c"
#endif

#if defined(ZPL_MODULE_TIMER)
    #include "source/timer.c"
#endif

#if defined(ZPL_MODULE_HASHING)
    #include "source/hashing.c"
#endif

#if defined(ZPL_MODULE_REGEX)
    #include "source/regex.c"
#endif

#if defined(ZPL_MODULE_DLL)
    #include "source/dll.c"
#endif

#if defined(ZPL_MODULE_OPTS)
    #include "source/opts.c"
#endif

#if defined(ZPL_MODULE_PROCESS)
    #include "source/process.c"
#endif

#if defined(ZPL_MODULE_MATH)
    #include "source/math.c"
#endif

#if defined(ZPL_MODULE_JSON)
    #include "source/json.c"
#endif

#if defined(ZPL_MODULE_THREADING)
    #include "source/threading/fence.c"
    #include "source/threading/atomic.c"
    #include "source/threading/sem.c"
    #include "source/threading/mutex.c"
    #include "source/threading/thread.c"
    #include "source/threading/sync.c"
    #include "source/threading/affinity.c"

    #if defined(ZPL_MODULE_JOBS)
        #include "source/jobs.c"
    #endif

    #if defined(ZPL_MODULE_COROUTINES)
        #include "source/coroutines.c"
    #endif
#endif


#if defined(ZPL_COMPILER_MSVC)
    #pragma warning(pop)
#endif

#if defined(__GCC__) || defined(__GNUC__) || defined(__clang__)
    #pragma GCC diagnostic pop
#endif

#endif // ZPL_IMPLEMENTATION

#if defined(ZPL_EXPOSE_TYPES)
    typedef zpl_u8 u8;
    typedef zpl_i8 i8;
    typedef zpl_u16 u16;
    typedef zpl_i16 i16;
    typedef zpl_u32 u32;
    typedef zpl_i32 i32;
    typedef zpl_u64 u64;
    typedef zpl_i64 i64;
    typedef zpl_b8 b8;
    typedef zpl_b16 b16;
    typedef zpl_b32 b32;
    typedef zpl_f32 f32;
    typedef zpl_f64 f64;
    typedef zpl_rune rune;
    typedef zpl_usize usize;
    typedef zpl_isize isize;
    typedef zpl_uintptr uintptr;
    typedef zpl_intptr intptr;
#endif // ZPL_EXPOSE_TYPES

#endif // ZPL_H

// TOC:
// zpl.h
// zpl_hedley.h
// header/core/system.h
// header/core/types.h
// header/core/helpers.h
// header/core/debug.h
// header/core/memory.h
// header/core/memory_virtual.h
// header/core/memory_custom.h
// header/core/collections/array.h
// header/core/collections/buffer.h
// header/core/collections/list.h
// header/core/collections/ring.h
// header/core/collections/hashtable.h
// header/core/string.h
// header/core/stringlib.h
// header/core/file.h
// header/core/file_stream.h
// header/core/file_misc.h
// header/core/print.h
// header/core/time.h
// header/core/random.h
// header/core/misc.h
// header/core/sort.h
// header/timer.h
// header/hashing.h
// header/regex.h
// header/event.h
// header/dll.h
// header/opts.h
// header/process.h
// header/math.h
// header/json.h
// header/threading/atomic.h
// header/threading/fence.h
// header/threading/sem.h
// header/threading/mutex.h
// header/threading/thread.h
// header/threading/sync.h
// header/threading/affinity.h
// header/jobs.h
// header/coroutines.h
// source/core/debug.c
// source/core/memory.c
// source/core/memory_virtual.c
// source/core/memory_custom.c
// source/core/array.c
// source/core/string.c
// source/core/stringlib.c
// source/core/file.c
// source/core/file_stream.c
// source/core/file_misc.c
// source/core/print.c
// source/core/time.c
// source/core/random.c
// source/core/misc.c
// source/core/sort.c
// source/timer.c
// source/hashing.c
// source/regex.c
// source/event.c
// source/dll.c
// source/opts.c
// source/process.c
// source/math.c
// source/json.c
// source/threading/atomic.c
// source/threading/fence.c
// source/threading/sem.c
// source/threading/mutex.c
// source/threading/thread.c
// source/threading/sync.c
// source/threading/affinity.c
// source/jobs.c
// source/coroutines.c
