//main_file

#include "functions.h"

#include <stdlib.h>

int main()
{
    char input_file_name[] = "data.txt";
    char output_file_name[] = "data_sort.txt";
    char *buf;
    char **text;

    int amount_of_cymbols = read_data(&buf, input_file_name);

    int n_counter = n_0_replacement(buf, amount_of_cymbols);

    array_of_pointers_init(&text, n_counter + 1);
    array_of_pointers_generator(text, buf, amount_of_cymbols);

    qsort(text, n_counter, sizeof(char*), compare_strings_alphabet);

    // print_line(text, n_counter);
    print_array_in_file (text, n_counter, output_file_name);

    free(text);
    free(buf);
    
    return 0;

}