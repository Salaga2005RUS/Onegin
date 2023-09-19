// TODO: name of this file is a disaster (.cpp also), I've already written about it somewhere...

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// TODO: write documentation!
//       Writing docs is like washing dishes: the less write it, the more you need it
//       and the less enjoyable it is to start. So, don't be a fool, start early!
//


// TODO: this header should be separated into logical parts

int read_data(char **buf, char *file_name);

// TODO: I have other name critiques, read functions.cpp
void array_of_pointers_init(char ***text, int amount_of_cymbols);
void array_of_pointers_generator(char **text, char *buf, int amount_of_cymbols);
int n_0_replacement(char *buf, int amount_of_cymbols);
void print_line(char **text, int counter);
int my_strcmp(char *String1, char *String2);
int compare_strings_alphabet (const void *String1, const void *String2);
// TODO:                    ^ what is this space too?


int fake_cymbol(char cymbol); // TODO: cymbol is not how you spell it.
//  ^~~~ TODO: I think I've alread told you, you should write your functions
//             using verbs, because they are actions.

void print_array_in_file (char **text, int n_counter, char *output_file_name);
// TODO:                ^ what is this space?     ^~ TODO: counter? What is it counting?
//                                                        (maybe it's count or just size)

#endif
