#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main() {
    char *str_data = "Ono rabotaet\n";
    int str_size = strlen(str_data);
    int discriptor;
    void *fm;
    fd = open("ex1.txt", O_RDWR | O_TRUNC);
    lseek(fd, str_size+1, SEEK_SET);
    write(fd, "", 1);
    fm = mmap(NULL, str_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    memcpy(fm, str_data, str_size);
    return 0;
}