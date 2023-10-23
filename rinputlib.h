#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <rstrlib.h>
#ifndef RINPUTLIB_H
#define RINPUTLIB_H

char * inputstr(char * askStr, int strSize, char * lengthError, int acceptNull, char * nullError) {
    // Get a string input
    static char str[1024];
    int isInputValid;

    if (strcmp(askStr, "") == 0) {
        askStr = ">>> ";
    }

    if (strSize == 0) {
        strSize = 1024;
    }

    if (strcmp(lengthError, "") == 0) {
        lengthError = "La longueur de l'entrée est invalide.";
    }

    if (acceptNull != 0 && acceptNull != 1) {
        acceptNull = 0;
    }

    if (strcmp(nullError, "") == 0) {
        nullError = "L'entrée est invalide.'";
    }
    
    if (acceptNull == 0) {
        do {
            printf("%s", askStr);
            if (!fgets(str, 1024, stdin)) {
                printf("\033[1;31mErreur: %s\n", strerror(errno));
                printf("Une erreur inattendue est survenue. Sortie...");
                exit(EXIT_FAILURE);
            }

            cleanstr(str);

            if (strlen(str) > strSize) {
                printf("%s\n", lengthError);
                isInputValid = 0;
            } else {
                isInputValid = 1;
            }
        } while (!isInputValid);
    } else if (acceptNull == 1) {
        do {
            printf("%s", askStr);
            if (!fgets(str, 1024, stdin)) {
                printf("\033[1;31mErreur: %s\n", strerror(errno));
                printf("Une erreur inattendue est survenue. Sortie...");
                exit(EXIT_FAILURE);
            }
            cleanstr(str);
            if (strlen(str) > strSize) {
                printf("%s\n", lengthError);
                isInputValid = 0;
            } else if (strcmp(str, "") == 0) {
                printf("%s\n", nullError);
                isInputValid = 0;
            } else {
                isInputValid = 1;
            }
        } while (!isInputValid);
    }

    char * returnStr = (char *) malloc(strSize);
    strcpy(returnStr, str);

    return returnStr;
}

int inputint(char * askStr, int intSize, char * lengthError, int acceptNull, char * nullError) {
    // Get an integer input
    static char str[1024];
    long convertedLong;
    int isInputValid;
    int nbr;

    if (strcmp(askStr, "") == 0) {
        askStr = ">>> ";
    }

    if (intSize == 0 || intSize > 10) {
        intSize = 10;
    }

    if (strcmp(lengthError, "") == 0) {
        lengthError = "La longueur de l'entrée est invalide.";
    }

    if (strcmp(nullError, "") == 0) {
        nullError = "L'entrée est invalide.'";
    }

    if (acceptNull == 0) {
        do {
            printf("%s", askStr);
            if (!fgets(str, 1024, stdin)) {
                printf("\033[1;31mErreur: %s\n", strerror(errno));
                printf("Une erreur inattendue est survenue. Sortie...");
                exit(EXIT_FAILURE);
            }

            cleanstr(str);

            char *endPtr;

            errno = 0;
            convertedLong = strtol(str, &endPtr, 10);
            if (errno == ERANGE) {
                printf("\033[1;31mErreur: %s\n", strerror(errno));
                printf("\033[0m%s\n", lengthError);
                isInputValid = 0;
            } else if (strlen(str) > intSize) {
                printf("%s\n", lengthError);
                isInputValid = 0;
            } else if (*endPtr && *endPtr != '\n') {
                isInputValid = 0;
            } else {
                nbr = (int)convertedLong;
                isInputValid = 1;
            }
        } while (!isInputValid);
    } else if (acceptNull == 1) {
        do {
            printf("%s", askStr);
            if (!fgets(str, 1024, stdin)) {
                printf("\033[1;31mErreur: %s\n", strerror(errno));
                printf("Une erreur inattendue est survenue. Sortie...");
                exit(EXIT_FAILURE);
            }

            cleanstr(str);

            char *endPtr;

            errno = 0;
            convertedLong = strtol(str, &endPtr, 10);
            if (errno == ERANGE) {
                printf("\033[1;31mErreur: %s\n", strerror(errno));
                printf("\033[0m%s\n", lengthError);
                isInputValid = 0;
            } else if (strlen(str) > intSize) {
                printf("%s\n", lengthError);
                isInputValid = 0;
            } else if (endPtr == str) {
                printf("%s\n", nullError);
                isInputValid = 0;
            } else if (*endPtr && *endPtr != '\n') {
                isInputValid = 0;
            } else {
                nbr = (int)convertedLong;
                isInputValid = 1;
            }
        } while (!isInputValid);
    } else {
        nbr = 0;
    }

    return nbr;
}

#endif // RINPUTLIB_H
