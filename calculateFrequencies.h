#ifndef CHALLENGECHARIO_CALCULATEFREQUENCIES_H
#define CHALLENGECHARIO_CALCULATEFREQUENCIES_H
struct counts {
    int words_c;
    int characters_c;
};

struct counts calculateFrequencies(FILE *textstream);
#endif //CHALLENGECHARIO_CALCULATEFREQUENCIES_H
