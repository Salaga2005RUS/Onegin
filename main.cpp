//main_file

#include "functions.h"

#include <stdlib.h>

int main()
{
    char input_file_name[] = "data.txt";
    char output_file_name[] = "data_sort.txt";
    char output_file_name_back[] = "data_sort_back.txt";
    char *buf;
    char **text1;
    char **text2;

    int amount_of_cymbols = read_data(&buf, input_file_name);

    int n_counter = n_0_replacement(buf, amount_of_cymbols);

    array_of_pointers_init(&text1, n_counter + 1);
    array_of_pointers_generator(text1, buf, amount_of_cymbols);

    array_of_pointers_init(&text2, n_counter + 1);
    array_of_pointers_generator(text2, buf, amount_of_cymbols);

    qsort(text1, n_counter, sizeof(char*), compare_strings_alphabet);

    print_array_in_file (text1, n_counter, output_file_name);

    qsort(text2, n_counter, sizeof(char*), compare_strings_alphabet_back);

    print_array_in_file (text2, n_counter, output_file_name_back);

    free(text1);
    free(text2);
    free(buf);
    
    return 0;

}