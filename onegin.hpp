#ifndef ONEGIN_HPP
#define ONEGIN_HPP

typedef struct
{
    int amount_of_cymbols = 0;
    int n_counter = 0;
} file_information;


int read_file_to_buffer(char **buf, char *file_name);
void initialize_array_of_pointers(char ***text, int amount_of_cymbols);
void fill_array_of_pointers(char **text, char *buf, int amount_of_cymbols);
int separate_buf_on_lines(char *buf, int amount_of_cymbols);
void print_line(char **text, int counter);
int my_strcmp(char *String1, char *String2);
int compare_strings_alphabet (const void *String1, const void *String2);
int fake_symbol_define(char cymbol);
void print_array (char **text, int n_counter, char *output_file_name);
int compare_strings_alphabet_back (const void *String1, const void *String2);
int my_strcmp_back(char *String1, char *String2);

#endif