#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

main() {
  struct stat info;

  if (stat("/home/uceccf/Desktop/allbin_os_lab/april11/wait.c", &info) != 0)
    perror("stat() error");
  else {
    puts("/home/uceccf/Desktop/allbin_os_lab/fibi.sh");
    printf("  inode:   %d\n",   (int) info.st_ino);
    printf(" dev id:   %d\n",   (int) info.st_dev);
    printf("   mode:   %08x\n",       info.st_mode);
    printf("  links:   %d\n",         info.st_nlink);
    printf("    uid:   %d\n",   (int) info.st_uid);
    printf("    gid:   %d\n",   (int) info.st_gid);
  }
}
