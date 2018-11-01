#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main() {
    char *str_data = "Ono ne rabotaet\n";
    int str_size;
    int fd1;
    int fd2;
    void *fm;
    fd1 = open("ex1.txt", O_RDWR | O_TRUNC);
    fd2 = open("ex1.memcpy.txt", O_RDWR | O_TRUNC);
    *str_data = read(fd1, "", 1);
    str_size = strlen(str_data);
    lseek(fd2, str_size+1, SEEK_SET);
    write(fd2, "", 1);
    fm = mmap(NULL, str_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd2, 0);
    memcpy(fm, str_data, str_size);
    return 0;
}