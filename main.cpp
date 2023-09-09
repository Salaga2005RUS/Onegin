#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int read_data(char *buf, char* file_name);
void array_of_pointers_generator(char **text, char *buf, int amount_of_cymbols);

int main()
{
    char *data;
    char file_name[] = "data.txt";
    char *buf;
    char *text[40000] = {};

    int amount_of_cymbols = read_data(data, file_name);
    array_of_pointers_generator(text, buf, amount_of_cymbols);

    printf ("%s %s", text[0], text[1]);

    return 0;

}






int read_data(char *buf, char* file_name)
    {
        FILE *fp = fopen(file_name, "r+");

        struct stat statbuf;

        fstat(fileno(fp), &statbuf);

        off_t text_size = statbuf.st_size;

        buf = (char*) calloc(statbuf.st_size, sizeof(char)) + 1;

        fread(buf, sizeof(char), text_size, fp);
 
        fclose(fp);
        
        return (statbuf.st_size + 1);
    }

void array_of_pointers_generator(char **text, char *buf, int amount_of_cymbols)
    {
    int line = 0;
    int i = 0;

    for (i = 0; i < amount_of_cymbols; i++)
         {
            if (buf[i] = '\n')
             {
                 text[line++] = buf + i + 1;
             }
        }
    
    }