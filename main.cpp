//main_file TODO: isn't this obvious?)

#include "functions.h" // TODO: what is functions.h? This name is as good as no name at all.
                       //
	               //       It's highly obvious that most header files contain functions
                       //       to anyone who has any knowledge about C programming language.
                       //
                       //       The main thing you should have told through your name is what
                       //       kind of functions are inside of there. Rename it at once!

#include <stdlib.h>

int main()
{
    char input_file_name[] = "data.txt";
    char output_file_name[] = "data_sort.txt";
    char *buf; // TODO: always initialize your variables, it's much safer to have a predictable
               //       value inside of your variables, not random junk.
    char **text; // TODO: same thing applies everywhere

    // TODO: You should create struct that will hold all this data (number of symbols, lines, ...),
    //       instead of just passing it around chaotically. This of a good name too...
    int amount_of_cymbols = read_data(&buf, input_file_name);

    int n_counter = n_0_replacement(buf, amount_of_cymbols);

    array_of_pointers_init(&text, n_counter + 1);
    array_of_pointers_generator(text, buf, amount_of_cymbols);

    qsort(text, n_counter + 1, sizeof(char*), compare_strings_alphabet);
    
    print_line(text, n_counter);
    print_array_in_file (text, n_counter, output_file_name);

    free(text);
    free(buf);
    
    return 0;

}
