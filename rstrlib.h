#include <string.h>
#include <ctype.h>
#ifndef RSTRLIB_H
#define RSTRLIB_H

char * cleanstr(char * strToClean) {
    // Clean a string
    strToClean[strcspn(strToClean, "\r\n")] = 0;
    return strToClean;
}

char * lowerstr(char * str) {
    // Transform a string into lowercase
    for (int i = 0; str[i]; i++) {
        int letter = (int)str[i];
        letter = tolower(letter);
        str[i] = (char)letter;
    }
    return str;
}

char * upperstr(char * str) {
    // Transform a string into uppercase
    for (int i = 0; str[i]; i++) {
        int letter = (int)str[i];
        letter = toupper(letter);
        str[i] = (char)letter;
    }
    return str;
}

#endif // RSTRLIB_H
