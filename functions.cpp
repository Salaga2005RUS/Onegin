#include "functions.h"

#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int read_data(char **buf, char *file_name)
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


void array_of_pointers_init(char ***text, int number_of_elements)
{
    *text = (char**) calloc(number_of_elements, sizeof(char*));
}


void array_of_pointers_generator(char **text, char *buf, int amount_of_cymbols)
{
    int line = 0;
    int i = 0;

    for (i = 0; i < amount_of_cymbols; i++)
    {
        if (buf[i] == '\0')
        {   
            if (buf[i + 1] == '\0') continue;
            
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


int fake_cymbol(char cymbol)
{
    if (cymbol == '\'') return 1;
    else if (cymbol == '\"') return 1;
    else if (cymbol == '\n') return 1;
    else if (cymbol == '\0') return 1;
    else if (cymbol == '(')  return 1;
    else if (cymbol == '[')  return 1;
    else if (cymbol == '{')  return 1;
    else if (cymbol == '-')  return 1;
    else if (cymbol == '.')  return 1;  
    else return 0;
}


void print_line(char **text, int n_counter)
{   
    int i = 0;

    for (i = 0; i < n_counter + 1; i++)
    {
        if (!fake_cymbol (text[i][0]))
        { 
            printf ("%s\n", text[i]);
        }
    }
}


int my_strcmp(char *String1, char *String2)
{
    int i;

    for (i = 0; String1[i] == String2[i]; i++)
    {
        if (String1[i] == '\0') 
        {
            return 0;
        }
    }

    return String1[i] - String2[i];
}


int compare_strings_alphabet (const void *String1, const void *String2)
{   
    return my_strcmp (*(char**) String1, *(char**) String2);
}

void print_array_in_file (char **text, int n_counter, char *file_name)
{
   FILE *output = fopen(file_name, "w+");
   int i = 0;

   for (i = 0; i < n_counter; i++)
    {
        if (!fake_cymbol (text[i][0]))
        {
            fprintf (output, "%s\n", text[i]);
        }
    }
    fclose (output);
}