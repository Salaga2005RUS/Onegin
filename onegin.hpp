#ifndef ONEGIN_HPP
#define ONEGIN_HPP
/*!
    @brief this struct contains information about the file with text

    @param[in] amount_of_symbols number of characters in the buf buffer
    @param[in] n_counter number of line in the buffer

*/
typedef struct
{
    int amount_of_symbols = 0;
    int n_counter = 0;
} FileInformation;

/*!
    @brief This function reads information from a file named file_name into the buffer buf

    @param[in] buf array of characters
    @param[in] file_name the name of the file from which the information is to be read
    @return number of characters in the file + 1

*/
int read_file_to_buffer(char **buf, char *file_name);

/*!
    @brief This function dynamically allocates memory under the accumt_of_symbols for an array of text pointers

    @param[in] text array of pointers to buf
    @param[in] amount_of_symbols number of characters in the buf buffer
*/
void initialize_array_of_pointers(char ***text, int amount_of_symbols);

/*!
    @brief This function constructs pointers to the buffer in the text array

    @param[in] text array of pointers to buf
    @param[in] buf array of characters
    @param[in] amount_of_symbols number of characters in the buf buffer
*/
void fill_array_of_pointers(char **text, char *buf, int amount_of_symbols);

/*!
    @brief This function replaces the \n characters with \0 in the buffer

    @param[in] buf array of characters
    @param[in] amount_of_symbols number of characters in the buf buffer
    @return number of line in the buffer
*/
int separate_buf_on_lines(char *buf, int amount_of_symbols);

/*!
    @brief This function is my custom version of strcmp, it skips non-letter characters

    @param[in] String1 line 1
    @param[in] String2 line 2
    @return line length difference
*/
int my_strcmp(char *String1, char *String2);

/*!
    @brief This comparator function is passed to qsort

    @param[in] String1 line 1
    @param[in] String2 line 2
    @return my_strcmp function
*/
int compare_strings_alphabet (const void *String1, const void *String2);

/*!
    @brief This function returns 1 for the most problematic characters (it is used in the array output function)

    @param[in] symbol
    @return 0 or 1
*/
int fake_symbol_define(char symbol);

/*!
    @brief This function outputs information from the buffer using text pointers to it in the output_file_name file

    @param[in] text array of pointers to buf
    @param[in] n_counter number of line in the buffer
    @param[in] output_file_name the file name for the output
*/
void print_array (char **text, int n_counter, char *output_file_name);

/*!
    @brief This comparator function is passed to qsort

    @param[in] String1 line 1
    @param[in] String2 line 2
    @return my_strcmp_back function
*/
int compare_strings_alphabet_back (const void *String1, const void *String2);

/*!
    @brief This function is my custom version of strcmp (back), it skips non-letter characters

    @param[in] String1 line 1
    @param[in] String2 line 2
    @return line length difference
*/
int my_strcmp_back(char *String1, char *String2);

#endif