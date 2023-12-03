// Automatically generated by ./tools/gen_syscall_strings.py

#include "syscall_strings.h"

const char* syscall_string(int syscall_number) {
  switch (syscall_number) {
#ifdef TARGET_IA32
    case 0:
      return "restart_syscall";
    case 1:
      return "exit";
    case 2:
      return "fork";
    case 3:
      return "read";
    case 4:
      return "write";
    case 5:
      return "open";
    case 6:
      return "close";
    case 7:
      return "waitpid";
    case 8:
      return "creat";
    case 9:
      return "link";
    case 10:
      return "unlink";
    case 11:
      return "execve";
    case 12:
      return "chdir";
    case 13:
      return "time";
    case 14:
      return "mknod";
    case 15:
      return "chmod";
    case 16:
      return "lchown";
    case 17:
      return "break";
    case 18:
      return "oldstat";
    case 19:
      return "lseek";
    case 20:
      return "getpid";
    case 21:
      return "mount";
    case 22:
      return "umount";
    case 23:
      return "setuid";
    case 24:
      return "getuid";
    case 25:
      return "stime";
    case 26:
      return "ptrace";
    case 27:
      return "alarm";
    case 28:
      return "oldfstat";
    case 29:
      return "pause";
    case 30:
      return "utime";
    case 31:
      return "stty";
    case 32:
      return "gtty";
    case 33:
      return "access";
    case 34:
      return "nice";
    case 35:
      return "ftime";
    case 36:
      return "sync";
    case 37:
      return "kill";
    case 38:
      return "rename";
    case 39:
      return "mkdir";
    case 40:
      return "rmdir";
    case 41:
      return "dup";
    case 42:
      return "pipe";
    case 43:
      return "times";
    case 44:
      return "prof";
    case 45:
      return "brk";
    case 46:
      return "setgid";
    case 47:
      return "getgid";
    case 48:
      return "signal";
    case 49:
      return "geteuid";
    case 50:
      return "getegid";
    case 51:
      return "acct";
    case 52:
      return "umount2";
    case 53:
      return "lock";
    case 54:
      return "ioctl";
    case 55:
      return "fcntl";
    case 56:
      return "mpx";
    case 57:
      return "setpgid";
    case 58:
      return "ulimit";
    case 59:
      return "oldolduname";
    case 60:
      return "umask";
    case 61:
      return "chroot";
    case 62:
      return "ustat";
    case 63:
      return "dup2";
    case 64:
      return "getppid";
    case 65:
      return "getpgrp";
    case 66:
      return "setsid";
    case 67:
      return "sigaction";
    case 68:
      return "sgetmask";
    case 69:
      return "ssetmask";
    case 70:
      return "setreuid";
    case 71:
      return "setregid";
    case 72:
      return "sigsuspend";
    case 73:
      return "sigpending";
    case 74:
      return "sethostname";
    case 75:
      return "setrlimit";
    case 76:
      return "getrlimit";
    case 77:
      return "getrusage";
    case 78:
      return "gettimeofday";
    case 79:
      return "settimeofday";
    case 80:
      return "getgroups";
    case 81:
      return "setgroups";
    case 82:
      return "select";
    case 83:
      return "symlink";
    case 84:
      return "oldlstat";
    case 85:
      return "readlink";
    case 86:
      return "uselib";
    case 87:
      return "swapon";
    case 88:
      return "reboot";
    case 89:
      return "readdir";
    case 90:
      return "mmap";
    case 91:
      return "munmap";
    case 92:
      return "truncate";
    case 93:
      return "ftruncate";
    case 94:
      return "fchmod";
    case 95:
      return "fchown";
    case 96:
      return "getpriority";
    case 97:
      return "setpriority";
    case 98:
      return "profil";
    case 99:
      return "statfs";
    case 100:
      return "fstatfs";
    case 101:
      return "ioperm";
    case 102:
      return "socketcall";
    case 103:
      return "syslog";
    case 104:
      return "setitimer";
    case 105:
      return "getitimer";
    case 106:
      return "stat";
    case 107:
      return "lstat";
    case 108:
      return "fstat";
    case 109:
      return "olduname";
    case 110:
      return "iopl";
    case 111:
      return "vhangup";
    case 112:
      return "idle";
    case 113:
      return "vm86old";
    case 114:
      return "wait4";
    case 115:
      return "swapoff";
    case 116:
      return "sysinfo";
    case 117:
      return "ipc";
    case 118:
      return "fsync";
    case 119:
      return "sigreturn";
    case 120:
      return "clone";
    case 121:
      return "setdomainname";
    case 122:
      return "uname";
    case 123:
      return "modify_ldt";
    case 124:
      return "adjtimex";
    case 125:
      return "mprotect";
    case 126:
      return "sigprocmask";
    case 127:
      return "create_module";
    case 128:
      return "init_module";
    case 129:
      return "delete_module";
    case 130:
      return "get_kernel_syms";
    case 131:
      return "quotactl";
    case 132:
      return "getpgid";
    case 133:
      return "fchdir";
    case 134:
      return "bdflush";
    case 135:
      return "sysfs";
    case 136:
      return "personality";
    case 137:
      return "afs_syscall";
    case 138:
      return "setfsuid";
    case 139:
      return "setfsgid";
    case 140:
      return "_llseek";
    case 141:
      return "getdents";
    case 142:
      return "_newselect";
    case 143:
      return "flock";
    case 144:
      return "msync";
    case 145:
      return "readv";
    case 146:
      return "writev";
    case 147:
      return "getsid";
    case 148:
      return "fdatasync";
    case 149:
      return "_sysctl";
    case 150:
      return "mlock";
    case 151:
      return "munlock";
    case 152:
      return "mlockall";
    case 153:
      return "munlockall";
    case 154:
      return "sched_setparam";
    case 155:
      return "sched_getparam";
    case 156:
      return "sched_setscheduler";
    case 157:
      return "sched_getscheduler";
    case 158:
      return "sched_yield";
    case 159:
      return "sched_get_priority_max";
    case 160:
      return "sched_get_priority_min";
    case 161:
      return "sched_rr_get_interval";
    case 162:
      return "nanosleep";
    case 163:
      return "mremap";
    case 164:
      return "setresuid";
    case 165:
      return "getresuid";
    case 166:
      return "vm86";
    case 167:
      return "query_module";
    case 168:
      return "poll";
    case 169:
      return "nfsservctl";
    case 170:
      return "setresgid";
    case 171:
      return "getresgid";
    case 172:
      return "prctl";
    case 173:
      return "rt_sigreturn";
    case 174:
      return "rt_sigaction";
    case 175:
      return "rt_sigprocmask";
    case 176:
      return "rt_sigpending";
    case 177:
      return "rt_sigtimedwait";
    case 178:
      return "rt_sigqueueinfo";
    case 179:
      return "rt_sigsuspend";
    case 180:
      return "pread64";
    case 181:
      return "pwrite64";
    case 182:
      return "chown";
    case 183:
      return "getcwd";
    case 184:
      return "capget";
    case 185:
      return "capset";
    case 186:
      return "sigaltstack";
    case 187:
      return "sendfile";
    case 188:
      return "getpmsg";
    case 189:
      return "putpmsg";
    case 190:
      return "vfork";
    case 191:
      return "ugetrlimit";
    case 192:
      return "mmap2";
    case 193:
      return "truncate64";
    case 194:
      return "ftruncate64";
    case 195:
      return "stat64";
    case 196:
      return "lstat64";
    case 197:
      return "fstat64";
    case 198:
      return "lchown32";
    case 199:
      return "getuid32";
    case 200:
      return "getgid32";
    case 201:
      return "geteuid32";
    case 202:
      return "getegid32";
    case 203:
      return "setreuid32";
    case 204:
      return "setregid32";
    case 205:
      return "getgroups32";
    case 206:
      return "setgroups32";
    case 207:
      return "fchown32";
    case 208:
      return "setresuid32";
    case 209:
      return "getresuid32";
    case 210:
      return "setresgid32";
    case 211:
      return "getresgid32";
    case 212:
      return "chown32";
    case 213:
      return "setuid32";
    case 214:
      return "setgid32";
    case 215:
      return "setfsuid32";
    case 216:
      return "setfsgid32";
    case 217:
      return "pivot_root";
    case 218:
      return "mincore";
    case 219:
      return "madvise";
    case 220:
      return "getdents64";
    case 221:
      return "fcntl64";
    case 224:
      return "gettid";
    case 225:
      return "readahead";
    case 226:
      return "setxattr";
    case 227:
      return "lsetxattr";
    case 228:
      return "fsetxattr";
    case 229:
      return "getxattr";
    case 230:
      return "lgetxattr";
    case 231:
      return "fgetxattr";
    case 232:
      return "listxattr";
    case 233:
      return "llistxattr";
    case 234:
      return "flistxattr";
    case 235:
      return "removexattr";
    case 236:
      return "lremovexattr";
    case 237:
      return "fremovexattr";
    case 238:
      return "tkill";
    case 239:
      return "sendfile64";
    case 240:
      return "futex";
    case 241:
      return "sched_setaffinity";
    case 242:
      return "sched_getaffinity";
    case 243:
      return "set_thread_area";
    case 244:
      return "get_thread_area";
    case 245:
      return "io_setup";
    case 246:
      return "io_destroy";
    case 247:
      return "io_getevents";
    case 248:
      return "io_submit";
    case 249:
      return "io_cancel";
    case 250:
      return "fadvise64";
    case 252:
      return "exit_group";
    case 253:
      return "lookup_dcookie";
    case 254:
      return "epoll_create";
    case 255:
      return "epoll_ctl";
    case 256:
      return "epoll_wait";
    case 257:
      return "remap_file_pages";
    case 258:
      return "set_tid_address";
    case 259:
      return "timer_create";
    case 260:
      return "timer_settime";
    case 261:
      return "timer_gettime";
    case 262:
      return "timer_getoverrun";
    case 263:
      return "timer_delete";
    case 264:
      return "clock_settime";
    case 265:
      return "clock_gettime";
    case 266:
      return "clock_getres";
    case 267:
      return "clock_nanosleep";
    case 268:
      return "statfs64";
    case 269:
      return "fstatfs64";
    case 270:
      return "tgkill";
    case 271:
      return "utimes";
    case 272:
      return "fadvise64_64";
    case 273:
      return "vserver";
    case 274:
      return "mbind";
    case 275:
      return "get_mempolicy";
    case 276:
      return "set_mempolicy";
    case 277:
      return "mq_open";
    case 278:
      return "mq_unlink";
    case 279:
      return "mq_timedsend";
    case 280:
      return "mq_timedreceive";
    case 281:
      return "mq_notify";
    case 282:
      return "mq_getsetattr";
    case 283:
      return "kexec_load";
    case 284:
      return "waitid";
    case 286:
      return "add_key";
    case 287:
      return "request_key";
    case 288:
      return "keyctl";
    case 289:
      return "ioprio_set";
    case 290:
      return "ioprio_get";
    case 291:
      return "inotify_init";
    case 292:
      return "inotify_add_watch";
    case 293:
      return "inotify_rm_watch";
    case 294:
      return "migrate_pages";
    case 295:
      return "openat";
    case 296:
      return "mkdirat";
    case 297:
      return "mknodat";
    case 298:
      return "fchownat";
    case 299:
      return "futimesat";
    case 300:
      return "fstatat64";
    case 301:
      return "unlinkat";
    case 302:
      return "renameat";
    case 303:
      return "linkat";
    case 304:
      return "symlinkat";
    case 305:
      return "readlinkat";
    case 306:
      return "fchmodat";
    case 307:
      return "faccessat";
    case 308:
      return "pselect6";
    case 309:
      return "ppoll";
    case 310:
      return "unshare";
    case 311:
      return "set_robust_list";
    case 312:
      return "get_robust_list";
    case 313:
      return "splice";
    case 314:
      return "sync_file_range";
    case 315:
      return "tee";
    case 316:
      return "vmsplice";
    case 317:
      return "move_pages";
    case 318:
      return "getcpu";
    case 319:
      return "epoll_pwait";
    case 320:
      return "utimensat";
    case 321:
      return "signalfd";
    case 322:
      return "timerfd_create";
    case 323:
      return "eventfd";
    case 324:
      return "fallocate";
    case 325:
      return "timerfd_settime";
    case 326:
      return "timerfd_gettime";
    case 327:
      return "signalfd4";
    case 328:
      return "eventfd2";
    case 329:
      return "epoll_create1";
    case 330:
      return "dup3";
    case 331:
      return "pipe2";
    case 332:
      return "inotify_init1";
    case 333:
      return "preadv";
    case 334:
      return "pwritev";
    case 335:
      return "rt_tgsigqueueinfo";
    case 336:
      return "perf_event_open";
#else
    case 0:
      return "read";
    case 1:
      return "write";
    case 2:
      return "open";
    case 3:
      return "close";
    case 4:
      return "stat";
    case 5:
      return "fstat";
    case 6:
      return "lstat";
    case 7:
      return "poll";
    case 8:
      return "lseek";
    case 9:
      return "mmap";
    case 10:
      return "mprotect";
    case 11:
      return "munmap";
    case 12:
      return "brk";
    case 13:
      return "rt_sigaction";
    case 14:
      return "rt_sigprocmask";
    case 15:
      return "rt_sigreturn";
    case 16:
      return "ioctl";
    case 17:
      return "pread64";
    case 18:
      return "pwrite64";
    case 19:
      return "readv";
    case 20:
      return "writev";
    case 21:
      return "access";
    case 22:
      return "pipe";
    case 23:
      return "select";
    case 24:
      return "sched_yield";
    case 25:
      return "mremap";
    case 26:
      return "msync";
    case 27:
      return "mincore";
    case 28:
      return "madvise";
    case 29:
      return "shmget";
    case 30:
      return "shmat";
    case 31:
      return "shmctl";
    case 32:
      return "dup";
    case 33:
      return "dup2";
    case 34:
      return "pause";
    case 35:
      return "nanosleep";
    case 36:
      return "getitimer";
    case 37:
      return "alarm";
    case 38:
      return "setitimer";
    case 39:
      return "getpid";
    case 40:
      return "sendfile";
    case 41:
      return "socket";
    case 42:
      return "connect";
    case 43:
      return "accept";
    case 44:
      return "sendto";
    case 45:
      return "recvfrom";
    case 46:
      return "sendmsg";
    case 47:
      return "recvmsg";
    case 48:
      return "shutdown";
    case 49:
      return "bind";
    case 50:
      return "listen";
    case 51:
      return "getsockname";
    case 52:
      return "getpeername";
    case 53:
      return "socketpair";
    case 54:
      return "setsockopt";
    case 55:
      return "getsockopt";
    case 56:
      return "clone";
    case 57:
      return "fork";
    case 58:
      return "vfork";
    case 59:
      return "execve";
    case 60:
      return "exit";
    case 61:
      return "wait4";
    case 62:
      return "kill";
    case 63:
      return "uname";
    case 64:
      return "semget";
    case 65:
      return "semop";
    case 66:
      return "semctl";
    case 67:
      return "shmdt";
    case 68:
      return "msgget";
    case 69:
      return "msgsnd";
    case 70:
      return "msgrcv";
    case 71:
      return "msgctl";
    case 72:
      return "fcntl";
    case 73:
      return "flock";
    case 74:
      return "fsync";
    case 75:
      return "fdatasync";
    case 76:
      return "truncate";
    case 77:
      return "ftruncate";
    case 78:
      return "getdents";
    case 79:
      return "getcwd";
    case 80:
      return "chdir";
    case 81:
      return "fchdir";
    case 82:
      return "rename";
    case 83:
      return "mkdir";
    case 84:
      return "rmdir";
    case 85:
      return "creat";
    case 86:
      return "link";
    case 87:
      return "unlink";
    case 88:
      return "symlink";
    case 89:
      return "readlink";
    case 90:
      return "chmod";
    case 91:
      return "fchmod";
    case 92:
      return "chown";
    case 93:
      return "fchown";
    case 94:
      return "lchown";
    case 95:
      return "umask";
    case 96:
      return "gettimeofday";
    case 97:
      return "getrlimit";
    case 98:
      return "getrusage";
    case 99:
      return "sysinfo";
    case 100:
      return "times";
    case 101:
      return "ptrace";
    case 102:
      return "getuid";
    case 103:
      return "syslog";
    case 104:
      return "getgid";
    case 105:
      return "setuid";
    case 106:
      return "setgid";
    case 107:
      return "geteuid";
    case 108:
      return "getegid";
    case 109:
      return "setpgid";
    case 110:
      return "getppid";
    case 111:
      return "getpgrp";
    case 112:
      return "setsid";
    case 113:
      return "setreuid";
    case 114:
      return "setregid";
    case 115:
      return "getgroups";
    case 116:
      return "setgroups";
    case 117:
      return "setresuid";
    case 118:
      return "getresuid";
    case 119:
      return "setresgid";
    case 120:
      return "getresgid";
    case 121:
      return "getpgid";
    case 122:
      return "setfsuid";
    case 123:
      return "setfsgid";
    case 124:
      return "getsid";
    case 125:
      return "capget";
    case 126:
      return "capset";
    case 127:
      return "rt_sigpending";
    case 128:
      return "rt_sigtimedwait";
    case 129:
      return "rt_sigqueueinfo";
    case 130:
      return "rt_sigsuspend";
    case 131:
      return "sigaltstack";
    case 132:
      return "utime";
    case 133:
      return "mknod";
    case 134:
      return "uselib";
    case 135:
      return "personality";
    case 136:
      return "ustat";
    case 137:
      return "statfs";
    case 138:
      return "fstatfs";
    case 139:
      return "sysfs";
    case 140:
      return "getpriority";
    case 141:
      return "setpriority";
    case 142:
      return "sched_setparam";
    case 143:
      return "sched_getparam";
    case 144:
      return "sched_setscheduler";
    case 145:
      return "sched_getscheduler";
    case 146:
      return "sched_get_priority_max";
    case 147:
      return "sched_get_priority_min";
    case 148:
      return "sched_rr_get_interval";
    case 149:
      return "mlock";
    case 150:
      return "munlock";
    case 151:
      return "mlockall";
    case 152:
      return "munlockall";
    case 153:
      return "vhangup";
    case 154:
      return "modify_ldt";
    case 155:
      return "pivot_root";
    case 156:
      return "_sysctl";
    case 157:
      return "prctl";
    case 158:
      return "arch_prctl";
    case 159:
      return "adjtimex";
    case 160:
      return "setrlimit";
    case 161:
      return "chroot";
    case 162:
      return "sync";
    case 163:
      return "acct";
    case 164:
      return "settimeofday";
    case 165:
      return "mount";
    case 166:
      return "umount2";
    case 167:
      return "swapon";
    case 168:
      return "swapoff";
    case 169:
      return "reboot";
    case 170:
      return "sethostname";
    case 171:
      return "setdomainname";
    case 172:
      return "iopl";
    case 173:
      return "ioperm";
    case 174:
      return "create_module";
    case 175:
      return "init_module";
    case 176:
      return "delete_module";
    case 177:
      return "get_kernel_syms";
    case 178:
      return "query_module";
    case 179:
      return "quotactl";
    case 180:
      return "nfsservctl";
    case 181:
      return "getpmsg";
    case 182:
      return "putpmsg";
    case 183:
      return "afs_syscall";
    case 184:
      return "tuxcall";
    case 185:
      return "security";
    case 186:
      return "gettid";
    case 187:
      return "readahead";
    case 188:
      return "setxattr";
    case 189:
      return "lsetxattr";
    case 190:
      return "fsetxattr";
    case 191:
      return "getxattr";
    case 192:
      return "lgetxattr";
    case 193:
      return "fgetxattr";
    case 194:
      return "listxattr";
    case 195:
      return "llistxattr";
    case 196:
      return "flistxattr";
    case 197:
      return "removexattr";
    case 198:
      return "lremovexattr";
    case 199:
      return "fremovexattr";
    case 200:
      return "tkill";
    case 201:
      return "time";
    case 202:
      return "futex";
    case 203:
      return "sched_setaffinity";
    case 204:
      return "sched_getaffinity";
    case 205:
      return "set_thread_area";
    case 206:
      return "io_setup";
    case 207:
      return "io_destroy";
    case 208:
      return "io_getevents";
    case 209:
      return "io_submit";
    case 210:
      return "io_cancel";
    case 211:
      return "get_thread_area";
    case 212:
      return "lookup_dcookie";
    case 213:
      return "epoll_create";
    case 214:
      return "epoll_ctl_old";
    case 215:
      return "epoll_wait_old";
    case 216:
      return "remap_file_pages";
    case 217:
      return "getdents64";
    case 218:
      return "set_tid_address";
    case 219:
      return "restart_syscall";
    case 220:
      return "semtimedop";
    case 221:
      return "fadvise64";
    case 222:
      return "timer_create";
    case 223:
      return "timer_settime";
    case 224:
      return "timer_gettime";
    case 225:
      return "timer_getoverrun";
    case 226:
      return "timer_delete";
    case 227:
      return "clock_settime";
    case 228:
      return "clock_gettime";
    case 229:
      return "clock_getres";
    case 230:
      return "clock_nanosleep";
    case 231:
      return "exit_group";
    case 232:
      return "epoll_wait";
    case 233:
      return "epoll_ctl";
    case 234:
      return "tgkill";
    case 235:
      return "utimes";
    case 236:
      return "vserver";
    case 237:
      return "mbind";
    case 238:
      return "set_mempolicy";
    case 239:
      return "get_mempolicy";
    case 240:
      return "mq_open";
    case 241:
      return "mq_unlink";
    case 242:
      return "mq_timedsend";
    case 243:
      return "mq_timedreceive";
    case 244:
      return "mq_notify";
    case 245:
      return "mq_getsetattr";
    case 246:
      return "kexec_load";
    case 247:
      return "waitid";
    case 248:
      return "add_key";
    case 249:
      return "request_key";
    case 250:
      return "keyctl";
    case 251:
      return "ioprio_set";
    case 252:
      return "ioprio_get";
    case 253:
      return "inotify_init";
    case 254:
      return "inotify_add_watch";
    case 255:
      return "inotify_rm_watch";
    case 256:
      return "migrate_pages";
    case 257:
      return "openat";
    case 258:
      return "mkdirat";
    case 259:
      return "mknodat";
    case 260:
      return "fchownat";
    case 261:
      return "futimesat";
    case 262:
      return "newfstatat";
    case 263:
      return "unlinkat";
    case 264:
      return "renameat";
    case 265:
      return "linkat";
    case 266:
      return "symlinkat";
    case 267:
      return "readlinkat";
    case 268:
      return "fchmodat";
    case 269:
      return "faccessat";
    case 270:
      return "pselect6";
    case 271:
      return "ppoll";
    case 272:
      return "unshare";
    case 273:
      return "set_robust_list";
    case 274:
      return "get_robust_list";
    case 275:
      return "splice";
    case 276:
      return "tee";
    case 277:
      return "sync_file_range";
    case 278:
      return "vmsplice";
    case 279:
      return "move_pages";
    case 280:
      return "utimensat";
    case 281:
      return "epoll_pwait";
    case 282:
      return "signalfd";
    case 283:
      return "timerfd_create";
    case 284:
      return "eventfd";
    case 285:
      return "fallocate";
    case 286:
      return "timerfd_settime";
    case 287:
      return "timerfd_gettime";
    case 288:
      return "accept4";
    case 289:
      return "signalfd4";
    case 290:
      return "eventfd2";
    case 291:
      return "epoll_create1";
    case 292:
      return "dup3";
    case 293:
      return "pipe2";
    case 294:
      return "inotify_init1";
    case 295:
      return "preadv";
    case 296:
      return "pwritev";
    case 297:
      return "rt_tgsigqueueinfo";
    case 298:
      return "perf_event_open";
#endif
    default:
      return "(unknown)";
  }
}
