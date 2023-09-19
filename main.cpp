#include "onegin.hpp"

#include <stdlib.h>

int main()
{
    char input_file_name[] = "data.txt";
    char output_file_name[] = "data_sort.txt";
    char output_file_name_back[] = "data_sort_back.txt";
    char *buf = NULL;
    char **text1 = NULL;
    char **text2 = NULL;

    file_information.amount_of_cymbols = read_file_to_buffer(&buf, input_file_name);

    file_information.n_counter = separate_buf_on_lines(buf, file_information.amount_of_cymbols);

    initialize_array_of_pointers(&text1, file_information.file_information.n_counter + 1);
    fill_array_of_pointers(text1, buf, file_information.amount_of_cymbols);

    initialize_array_of_pointers(&text2, file_information.n_counter + 1);
    fill_array_of_pointers(text2, buf, file_information.amount_of_cymbols);

    qsort(text1, file_information.n_counter, sizeof(char*), compare_strings_alphabet);

    print_array (text1, file_information.n_counter, output_file_name);

    qsort(text2, file_information.n_counter, sizeof(char*), compare_strings_alphabet_back);

    print_array (text2, file_information.n_counter, output_file_name_back);

    free(text1);
    free(text2);
    free(buf);
    
    return 0;

}