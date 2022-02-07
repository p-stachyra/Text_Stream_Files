#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "calculateFrequencies.h"

/* a function returning a structure containing the details
 * on the number of words and characters */
struct counts calculateFrequencies(FILE *textstream) {
    /* store frequencies */
    struct counts occurrences;
    /* int for characters to handle EOF */
    int character = 0;
    /* counts for words */
    int w = 0;
    /* counts for characters */
    int c = 0;
    /* check if a new word is started.
     * If yes, change the status and count new word */
    bool in_word = false;

    /* Until end-of-file is encountered,
     * perform counting for words and characters */
    while ((character = getc(textstream)) != EOF) {
        /* do not count spaces */
        if (isspace(character)) {
            /* in case of space, change the flag
             * the assumption is that a word has ended
             * and a new word may start
             */
            in_word = false;
        }
        else {
            /* is this is not a space or something else than alphanumerical,
             * a new character is counted
             */
            if (isalpha(character)) {
                c++;
                /* only if moving from space, count the starting character as a new word */
                if (in_word == false) {
                    w++;
                    in_word = true;
                }
            }
        }
    }
    /* set the contents of the structure to respectively: the number of characters
     * and the number of words.
     */
    occurrences.characters_c = c;
    occurrences.words_c = w;

    /* return a structure */
    return occurrences;
}

