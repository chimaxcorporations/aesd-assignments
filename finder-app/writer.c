#include <syslog.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *argv[]){
  if(argc < 3){
    syslog(LOG_ERR, "Incomplete number of arguments.");
    return EXIT_FAILURE;
  }

  int fd = open(argv[1], O_WRONLY);
  if(fd < 0){
    syslog(LOG_ERR, "Error opening file %s: %s", argv[1], strerror(errno));
    printf("Error opening file %s: %s\n", argv[1], strerror(errno));
    return EXIT_FAILURE;
  }
  if(write(fd, argv[2], strlen(argv[2]))< 0){
    syslog(LOG_ERR, "Error writing to file %s: %s", argv[1], strerror(errno));
    printf("Error writing to file %s: %s\n", argv[1], strerror(errno));
    close(fd);
    return EXIT_FAILURE;
  }
  syslog(LOG_DEBUG, "Successfully wrote to file %s", argv[1]);
  printf("Successfully wrote to file %s\n", argv[1]);
  close(fd);
  return 0;
}