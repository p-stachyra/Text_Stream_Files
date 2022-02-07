#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "calculateFrequencies.h"
#include "convertTextCase.h"

int main(int argc, char *argv[]) {

    struct counts w_c_occurrences;
    /* pointer to a potential user generated file */
    FILE *file_pointer = NULL;
    /* for indicating if copying and modifying file contents was successful */
    int success_flag = 1;

    /* user-generated file's name was provided */
    if (argc == 2) {

        /* read the provided file */
        file_pointer = fopen(argv[1], "r");
        if (file_pointer) {

            w_c_occurrences = calculateFrequencies(file_pointer);

            /* the while stream was processed by the function, start from the
             * beginning of the file again and perform another operation
             */
            fseek(file_pointer, 0, SEEK_SET);

            /* the original text was manipulated and
             * can be saved to a temporary file. If 0 is returned, it can be
             * renamed to other filename
             */
            success_flag = convertTextCase(file_pointer);
            if (success_flag == 0) {
                /* rename the copy from temporary file to indicate that the file was modified */
                if (rename("temporary_file.txt", "modified_file.txt") && (remove("temporary_file.txt"))) {
                    printf("The text stream was modified and saved to a temporary file.\nThe temporary file's name was changed successfully.\n");
                }
                else {
                    printf("The text stream was modified and saved to a temporary file, however, changing the temporary file's name failed.\n");
                }
            }
            /* close the original file - the operation was performed successfully */
            fclose(file_pointer);

        }
        else {
            perror("Memory allocation task failed. The file could not be read.\nError");
            exit(-1);
        }

    }

    /* read from STDIN */
    else if (argc == 1) {
        w_c_occurrences = calculateFrequencies(stdin);
    }

    else {
        /* exception handling - unknown command line arguments */
        printf("The command could not be recognized.\n0 (read from STDIN stream) or 1 (read from user-generated file stream) command line arguments are expected.\n");
        exit(-1);
    }

    printf("Frequencies of words and characters in the original file\nWords: %d\nCharacters: %d\n",
           w_c_occurrences.words_c, w_c_occurrences.characters_c);

    return 0;
}



