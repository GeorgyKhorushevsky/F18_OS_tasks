#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main() {
    int str_size;
    int fd1;
    int fd2;
    void *fm1;
    void *fm2;
    fd1 = open("ex1.txt", O_RDONLY);
    fd2 = open("ex1.memcpy.txt", O_RDWR | O_TRUNC);

    struct stat f1stat;

    fstat(fd1, &f1stat);
    str_size = f1stat.st_size;
    lseek(fd2, str_size, SEEK_SET);
    write(fd2, "", 1);

    fm1 = mmap(NULL, str_size, PROT_READ, MAP_SHARED, fd1, 0);
    fm2 = mmap(NULL, str_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd2, 0);
    memcpy(fm2, fm1, str_size);
    return 0;
}