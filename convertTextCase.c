#include <stdio.h>
#include <ctype.h>
#include "convertTextCase.h"

int convertTextCase(FILE *textstream) {
    /* create a pointer for a temporary file */
    FILE *p_temp_file = NULL;
    /* int for characters to handle EOF */
    int character = 0;
    /* indication of the completion */
    int exitcode = -1;

    p_temp_file = fopen("temporary_file.txt", "w");

    /* check if the memory address was given to the pointer */
    if (p_temp_file) {
        /* Until the end-of-file, read the characters
         * convert lowercase to upper case and vice versa.
         * If the character is not a letter and does not have a case
         * then, just copy the character to the new file
         */
        while ((character = getc(textstream)) != EOF) {
            if (isupper(character)) {
                character = tolower(character);
            }
            else if (islower(character)) {
                character = toupper(character);
            }
            fputc(character, p_temp_file);
        }
        /* close the opened file and set the exitcode to success (0) */
        fclose(p_temp_file);
        exitcode = 0;
    }
    else {
        perror("Memory allocation task failed. The file could not be read.\nError");
    }

    return exitcode;
}