#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int read_data(char **buf, char *file_name);
void array_of_pointers_init(char ***text, int amount_of_cymbols);
void array_of_pointers_generator(char **text, char *buf, int amount_of_cymbols);
int n_0_replacement(char *buf, int amount_of_cymbols);
void print_line(char **text, int counter);
int my_strcmp(char *String1, char *String2);
int compare_strings_alphabet (const void *String1, const void *String2);
int fake_cymbol(char cymbol);
void print_array_in_file (char **text, int n_counter, char *output_file_name);
int compare_strings_alphabet_back (const void *String1, const void *String2);
int my_strcmp_back(char *String1, char *String2);

#endif