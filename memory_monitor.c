#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

void get_memory_usage() {
    struct sysinfo si;
    if (sysinfo(&si) != 0) {
        perror("sysinfo");
        exit(EXIT_FAILURE);
    }

    long total_memory = si.totalram / 1024 / 1024;
    long free_memory = si.freeram / 1024 / 1024;
    long used_memory = total_memory - free_memory;

    printf("Total Memory: %ld MB\n", total_memory);
    printf("Used Memory: %ld MB\n", used_memory);
    printf("Free Memory: %ld MB\n", free_memory);
    printf("Memory Usage: %.2f%%\n", (double)used_memory / total_memory * 100);
}

int main() {
    get_memory_usage();
    return 0;
}
