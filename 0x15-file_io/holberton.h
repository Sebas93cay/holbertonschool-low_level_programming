#ifndef thelib

#define thelib

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> /*O_flags*/
#include <stdlib.h> /*exit*/
#include <unistd.h> /*close*/

ssize_t read_textfile(const char *filename, size_t letters);



#endif