/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if building static binary. */
/* #undef BUILD_STATIC */

/* Define if CPU temperature option should be enabled. */
/* #undef BUILD_WITH_CPU_TEMP */

/* Configuration path. */
#define CONFIGDIR "/.config"

/* Copyright message. */
#define COPYRIGHT "(C) 2004-2019 Hisham Muhammad. (C) 2020-2025 htop dev team."

/* Predefine ncurses macro. */
/* #undef ERR */

/* Define if sched_setaffinity and sched_getaffinity are to be used. */
#define HAVE_AFFINITY 1

/* Define if ancient vserver support enabled. */
/* #undef HAVE_ANCIENT_VSERVER */

/* The access attribute is supported. */
/* #undef HAVE_ATTR_ACCESS */

/* The alloc_size attribute is supported. */
#define HAVE_ATTR_ALLOC_SIZE 1

/* The nonnull attribute is supported. */
#define HAVE_ATTR_NONNULL 1

/* The returns_nonnull attribute is supported. */
#define HAVE_ATTR_RETNONNULL 1

/* Define to 1 if the compiler supports '__builtin_ctz' function. */
#define HAVE_BUILTIN_CTZ 1

/* Define to 1 if you have the `clock_gettime' function. */
#define HAVE_CLOCK_GETTIME 1

/* Define to 1 if you have the <curses.h> header file. */
/* #undef HAVE_CURSES_H */

/* Define if delay accounting support should be enabled. */
/* #undef HAVE_DELAYACCT */

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
#define HAVE_DIRENT_H 1

/* Define to 1 if you have the `dladdr' function. */
#define HAVE_DLADDR 1

/* Define to 1 if you have the <execinfo.h> header file. */
#define HAVE_EXECINFO_H 1

/* Define to 1 if you have the `faccessat' function. */
#define HAVE_FACCESSAT 1

/* Define to 1 if you have the `fstatat' function. */
#define HAVE_FSTATAT 1

/* Define to 1 if you have the `getmouse' function. */
#define HAVE_GETMOUSE 1

/* Define to 1 if you have the `host_get_clock_service' function. */
/* #undef HAVE_HOST_GET_CLOCK_SERVICE */

/* Define to 1 if you have the `host_statistics64' function. */
/* #undef HAVE_HOST_STATISTICS64 */

/* Define to 1 if you have the <hwloc.h> header file. */
/* #undef HAVE_HWLOC_H */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `cap' library (-lcap). */
/* #undef HAVE_LIBCAP */

/* Define to 1 if you have the 'hwloc' library (-lhwloc). */
/* #undef HAVE_LIBHWLOC */

/* Define to 1 if you have the `lzma' library (-llzma). */
/* #undef HAVE_LIBLZMA */

/* libcurses is present */
/* #undef HAVE_LIBNCURSES */

/* libncursesw is present */
#define HAVE_LIBNCURSESW 1

/* Define to 1 if you have the `sensors' library (-lsensors). */
/* #undef HAVE_LIBSENSORS */

/* Define to 1 if you have the `systemd' library (-lsystemd). */
/* #undef HAVE_LIBSYSTEMD */

/* Define to 1 if you have the `unwind' library (-lunwind). */
/* #undef HAVE_LIBUNWIND */

/* Define to 1 if you have the <libunwind.h> header file. */
/* #undef HAVE_LIBUNWIND_H */

/* Define to 1 if you have the <libunwind/libunwind.h> header file. */
/* #undef HAVE_LIBUNWIND_LIBUNWIND_H */

/* Define to 1 if you have the <mach/mach_time.h> header file. */
/* #undef HAVE_MACH_MACH_TIME_H */

/* Define to 1 if <wchar.h> declares mbstate_t. */
#define HAVE_MBSTATE_T 1

/* Define to 1 if you have the `memfd_create' function. */
#define HAVE_MEMFD_CREATE 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <ncursesw/curses.h> header file. */
#define HAVE_NCURSESW_CURSES_H 1

/* Define to 1 if you have the <ncursesw/term.h> header file. */
#define HAVE_NCURSESW_TERM_H 1

/* Define to 1 if you have the <ncurses/curses.h> header file. */
/* #undef HAVE_NCURSES_CURSES_H */

/* Define to 1 if you have the <ncurses.h> header file. */
/* #undef HAVE_NCURSES_H */

/* Define to 1 if you have the <ncurses/ncurses.h> header file. */
/* #undef HAVE_NCURSES_NCURSES_H */

/* Define to 1 if you have the <ncurses/term.h> header file. */
/* #undef HAVE_NCURSES_TERM_H */

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
/* #undef HAVE_NDIR_H */

/* Define to 1 if you have the <netlink/attr.h> header file. */
/* #undef HAVE_NETLINK_ATTR_H */

/* Define to 1 if you have the <netlink/handlers.h> header file. */
/* #undef HAVE_NETLINK_HANDLERS_H */

/* Define to 1 if you have the <netlink/msg.h> header file. */
/* #undef HAVE_NETLINK_MSG_H */

/* Define to 1 if you have the `openat' function. */
#define HAVE_OPENAT 1

/* Define if openvz support enabled. */
/* #undef HAVE_OPENVZ */

/* Define to 1 if you have the <pcp/pmapi.h> header file. */
/* #undef HAVE_PCP_PMAPI_H */

/* Define to 1 if you have the `pmLookupDescs' function. */
/* #undef HAVE_PMLOOKUPDESCS */

/* Define to 1 if you have the `readlinkat' function. */
#define HAVE_READLINKAT 1

/* Define to 1 if you have the `sched_getscheduler' function. */
#define HAVE_SCHED_GETSCHEDULER 1

/* Define to 1 if you have the `sched_setscheduler' function. */
#define HAVE_SCHED_SETSCHEDULER 1

/* Define to 1 if you have the <sensors/sensors.h> header file. */
/* #undef HAVE_SENSORS_SENSORS_H */

/* Define to 1 if you have the `set_escdelay' function. */
#define HAVE_SET_ESCDELAY 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the 'strchrnul' function. */
#define HAVE_STRCHRNUL 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if the system has the type `struct vm_statistics64'. */
/* #undef HAVE_STRUCT_VM_STATISTICS64 */

/* Define to 1 if you have the <sys/capability.h> header file. */
/* #undef HAVE_SYS_CAPABILITY_H */

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_DIR_H */

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_NDIR_H */

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/utsname.h> header file. */
#define HAVE_SYS_UTSNAME_H 1

/* Define to 1 if you have the <term.h> header file. */
/* #undef HAVE_TERM_H */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define if VServer support enabled. */
/* #undef HAVE_VSERVER */

/* Building for Darwin. */
/* #undef HTOP_DARWIN */

/* Building for DragonFlyBSD. */
/* #undef HTOP_DRAGONFLYBSD */

/* Building for FreeBSD. */
/* #undef HTOP_FREEBSD */

/* Building for Linux. */
#define HTOP_LINUX /**/

/* Building for NetBSD. */
/* #undef HTOP_NETBSD */

/* Building for OpenBSD. */
/* #undef HTOP_OPENBSD */

/* Define if building pcp-htop binary. */
/* #undef HTOP_PCP */

/* Building for Solaris. */
/* #undef HTOP_SOLARIS */

/* Building for an unsupported platform. */
/* #undef HTOP_UNSUPPORTED */

/* Define to 1 if `major', `minor', and `makedev' are declared in <mkdev.h>.
   */
/* #undef MAJOR_IN_MKDEV */

/* Define to 1 if 'major', 'minor', and 'makedev' are declared in
   <sys/sysmacros.h>. */
#define MAJOR_IN_SYSMACROS 1

/* Define to enable stdbool.h in ncurses */
#define NCURSES_ENABLE_STDBOOL_H 1

/* File with OS release details. */
#define OSRELEASEFILE "/etc/os-release"

/* Name of package */
#define PACKAGE "htop"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "htop@groups.io"

/* Define to the full name of this package. */
#define PACKAGE_NAME "htop"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "htop 3.4.1-c452511-dirty"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "htop"

/* Define to the home page for this package. */
#define PACKAGE_URL "https://htop.dev/"

/* Define to the version of this package. */
#define PACKAGE_VERSION "3.4.1-c452511-dirty"

/* Path of proc filesystem. */
#define PROCDIR "/proc"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif


/* Version number of package */
#define VERSION "3.4.1-c452511-dirty"

/* Enable large inode numbers on Mac OS X 10.5.  */
#ifndef _DARWIN_USE_64_BIT_INODE
# define _DARWIN_USE_64_BIT_INODE 1
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* Define to 1 if on MINIX. */
/* #undef _MINIX */

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
/* #undef _POSIX_1_SOURCE */

/* Define to 1 if you need to in order for `stat' and other things to work. */
/* #undef _POSIX_SOURCE */

/* Define for Solaris 2.5.1 so the uint32_t typedef from <sys/synch.h>,
   <pthread.h>, or <semaphore.h> is not used. If the typedef were allowed, the
   #define below would cause a syntax error. */
/* #undef _UINT32_T */

/* Define for Solaris 2.5.1 so the uint64_t typedef from <sys/synch.h>,
   <pthread.h>, or <semaphore.h> is not used. If the typedef were allowed, the
   #define below would cause a syntax error. */
/* #undef _UINT64_T */

/* Define for Solaris 2.5.1 so the uint8_t typedef from <sys/synch.h>,
   <pthread.h>, or <semaphore.h> is not used. If the typedef were allowed, the
   #define below would cause a syntax error. */
/* #undef _UINT8_T */

/* Enables XPG4v2 (SUSv1) interfaces if they are not enabled already with _XOPEN_SOURCE */
#ifndef _XOPEN_SOURCE_EXTENDED
#define _XOPEN_SOURCE_EXTENDED 1
#endif


/* Define to `int' if <sys/types.h> doesn't define. */
/* #undef gid_t */

/* Define to a type if <wchar.h> does not define. */
/* #undef mbstate_t */

/* Define to `int' if <sys/types.h> does not define. */
/* #undef mode_t */

/* Define to `long int' if <sys/types.h> does not define. */
/* #undef off_t */

/* Define to `int' if <sys/types.h> does not define. */
/* #undef pid_t */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* Define to `int' if <sys/types.h> does not define. */
/* #undef ssize_t */

/* Define to `int' if <sys/types.h> doesn't define. */
/* #undef uid_t */

/* Define to the type of an unsigned integer type of width exactly 16 bits if
   such a type exists and the standard includes do not define it. */
/* #undef uint16_t */

/* Define to the type of an unsigned integer type of width exactly 32 bits if
   such a type exists and the standard includes do not define it. */
/* #undef uint32_t */

/* Define to the type of an unsigned integer type of width exactly 64 bits if
   such a type exists and the standard includes do not define it. */
/* #undef uint64_t */

/* Define to the type of an unsigned integer type of width exactly 8 bits if
   such a type exists and the standard includes do not define it. */
/* #undef uint8_t */
