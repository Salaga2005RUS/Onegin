#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int read_data(char **buf, char* file_name);
void array_of_pointers_generator(char **text, char *buf, int amount_of_cymbols);
int n_0_replacement(char *buf, int amount_of_cymbols);
void print_line(char **text, char *buf, int counter);

int main()
{
    char file_name[] = "data.txt";
    char *buf;
    char *text[40000] = {};
    int counter = 0;

    int amount_of_cymbols = read_data(&buf, file_name);
    array_of_pointers_generator(text, buf, amount_of_cymbols);

    printf ("%p %p \n", text[0], text[1]); //Проверка выдачи адрессов в переменной text

    int n_counter = n_0_replacement(buf, amount_of_cymbols);
    
    print_line (text, buf, counter);

    return 0;

}






int read_data(char **buf, char* file_name)
{
    FILE *fp = fopen(file_name, "r+");

    struct stat statbuf;

    fstat(fileno(fp), &statbuf);

    off_t text_size = statbuf.st_size;

    *buf = (char*) calloc(statbuf.st_size + 1, sizeof(char));

    fread(*buf, sizeof(char), text_size, fp);
 
    fclose(fp);

    return (statbuf.st_size + 1);
}

void array_of_pointers_generator(char **text, char *buf, int amount_of_cymbols)
{
    int line = 0;
    int i = 0;

    for (i = 0; i < amount_of_cymbols; i++)
    {
        if (buf[i] == '\n')
        {
            text[line] = (buf + i + 1);
            line++;
        }
    }       
}

int n_0_replacement(char *buf, int amount_of_cymbols)
{
    int n_counter = 0;

    for (int i = 0; i < amount_of_cymbols; i++)
    {
        if (buf[i] == '\n') 
        {
            buf[i] = '\0';
            n_counter++;
        }
    }

    return n_counter;
}

void print_line(char **text, char *buf, int counter)
{   
        printf ("%s\n", text[counter]);
}