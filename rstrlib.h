#include <string.h>
#include <ctype.h>
#ifndef RSTRLIB_H
#define RSTRLIB_H

char * cleanstr(char * inputToClean) {
    // Clean the input
    inputToClean[strcspn(inputToClean, "\r\n")] = 0;
    return inputToClean;
}

char * lowerstr(char * str) {
    for (int i = 0; str[i]; i++) {
        int letter = (int)str[i];
        letter = tolower(letter);
        str[i] = (char)letter;
    }
    return str;
}

char * upperstr(char * str) {
    for (int i = 0; str[i]; i++) {
        int letter = (int)str[i];
        letter = toupper(letter);
        str[i] = (char)letter;
    }
    return str;
}

#endif // RSTRLIB_H
