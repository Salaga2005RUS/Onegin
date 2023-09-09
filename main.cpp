#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int i = 0;
    int n_counter = 0;

    char data[] = "data.txt";
    FILE *fp = fopen("data.txt", "r+");

    struct stat statbuf;

    fstat(fileno(fp), &statbuf);

    off_t text_size = statbuf.st_size;

    char *buf;
    buf = (char*) calloc (statbuf.st_size, sizeof(char));

    // TODO free all allocated memory

    return 0;

}