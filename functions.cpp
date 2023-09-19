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
    // TODO: spaces are good, but now you have too much of it.
    //       You are writing a space affter every single line.
    //
    //       What's the point? Use them as a contrast to 
    //       separate logic blocks.

    FILE *fp = fopen(file_name, "r+");

    struct stat statbuf;

    fstat(fileno(fp), &statbuf);

    off_t text_size = statbuf.st_size;

    // TODO: I think I would rather insert '\0' explicitly.
    *buf = (char*) calloc(statbuf.st_size + 1, sizeof(char));

    fread(*buf, sizeof(char), text_size, fp);
 
    fclose(fp);

    return (statbuf.st_size + 1);
}


// TODO: and again, a completely meaningless name...
void array_of_pointers_init(char ***text, int number_of_elements)
{
    *text = (char**) calloc(number_of_elements, sizeof(char*));
}


// TODO: another one...
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


// TODO: explain not what exactly it does, but why it does it...
//       For example, this function definitely replaces '\0', but
//       if we think a bit more it does it to split text in lines
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


int fake_cymbol(char cymbol) // TODO: what does it mean to be a "fake symbol"?
{
    // TODO: do you know about switch..case?
    if (cymbol == '\'') return 1;
    else if (cymbol == '\"') return 1; // I mean, this symbol isn't a fake
    else if (cymbol == '\n') return 1; // And this isn't either...
    else if (cymbol == '\0') return 1;
    else if (cymbol == '(')  return 1; // TODO: Do you know about "||" operator?
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
	// TODO: Why are you filtering by first symbol?
	// NOTE: Also, think, maybe it's better to filter before outputing?
        if (!fake_cymbol (text[i][0]))
        { 
            printf ("%s\n", text[i]);
        }
    }
}


int my_strcmp(char *String1, char *String2)
{
    int i;

    // TODO: What about big and small letters?
    //       This way all the big letters will be compare bigger than all the
    //       small letters, and this is not how lexicographical order works!
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

// TODO: What is difference between printing text to console and to
//       a file. None! It's really easy to generalize this, so do it!
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
