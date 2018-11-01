#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
    setvbuf(stdout, NULL, _IOLBF, 0);
    char *small_data = "Hello\n";
    int n = strlen(small_data);
    for(int i =0; i<n; i++){
        printf("%c", small_data[i]);
        if (i != n-1){
            sleep(i);
        }
    }
    return 0;
}
