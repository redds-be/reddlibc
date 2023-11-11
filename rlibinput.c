/*
A C program that handles some user inputs.
Copyright (C) 2023 redd

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

// HEADERS
#include "./rlibinput.h"
#include "./rlibstdio.h"
#include "./rlibstr.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Get a string (char *) input from the user
char *inputstr(char *askStr, int strSize, char *lengthError, int acceptNull, char *nullError) {
    static char str[1024];
    int isInputValid;

    if (strSize != 0) {
        if (strcmp(lengthError, "") == 0) {
            lengthError = "The length of the input is invalid.";
        }
    } else {
        strSize = 1024;
    }

    if (acceptNull != 0 && acceptNull != 1) {
        acceptNull = 0;
    }

    if (acceptNull == 1) {
        if (strcmp(nullError, "") == 0) {
            nullError = "The input is invalid.";
        }
    }

    if (acceptNull == 0) {
        do {
            printf("%s", askStr);
            if (!fgets(str, 1024, stdin)) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("An unexpected error has occurred. Exiting...");
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
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("An unexpected error has occurred. Exiting...");
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

    char *returnStr = (char *) malloc(strSize);
    snprintf(returnStr, strSize, "%s", str);

    return returnStr;
}

// Get a char input from the user
char inputchar(char *askStr) {
    printf("%s", askStr);
    char outchar = (char) getchar();

    clearstdin();

    return outchar;
}

// Get an int input from the user
int inputint(char *askStr, int intSize, char *lengthError, int acceptNull, char *nullError) {
    static char str[1024];
    long convertedLong;
    int isInputValid;
    int nbr;

    if (intSize == 0 || intSize > 9) {
        if (strcmp(lengthError, "") == 0) {
            lengthError = "The length of the input is invalid.";
        }
        intSize = 9;
    }

    if (acceptNull != 0 && acceptNull != 1) {
        acceptNull = 0;
    }

    if (acceptNull == 1) {
        if (strcmp(nullError, "") == 0) {
            nullError = "The input is invalid.";
        }
    }

    if (acceptNull == 0) {
        do {
            printf("%s", askStr);
            if (!fgets(str, 1024, stdin)) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("An unexpected error has occurred. Exiting...");
                exit(EXIT_FAILURE);
            }

            cleanstr(str);

            char *endPtr;

            errno = 0;
            convertedLong = strtol(str, &endPtr, 10);
            if (errno == ERANGE) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("\033[0m%s\n", lengthError);
                isInputValid = 0;
            } else if (strlen(str) > intSize) {
                printf("%s\n", lengthError);
                isInputValid = 0;
            } else if (*endPtr && *endPtr != '\n') {
                isInputValid = 0;
            } else {
                nbr = (int) convertedLong;
                isInputValid = 1;
            }
        } while (!isInputValid);
    } else if (acceptNull == 1) {
        do {
            printf("%s", askStr);
            if (!fgets(str, 1024, stdin)) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("An unexpected error has occurred. Exiting...");
                exit(EXIT_FAILURE);
            }

            cleanstr(str);

            char *endPtr;

            errno = 0;
            convertedLong = strtol(str, &endPtr, 10);
            if (errno == ERANGE) {
                printf("\033[1;31mError: %s\n", strerror(errno));
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
                nbr = (int) convertedLong;
                isInputValid = 1;
            }
        } while (!isInputValid);
    } else {
        nbr = 0;
    }

    return nbr;
}

// Get a double input from the user
double inputdbl(char *askStr, int dblSize, char *lengthError, int acceptNull, char *nullError) {
    static char str[1024];
    double nbr;
    int isInputValid;

    if (dblSize == 0 || dblSize > 9) {
        if (strcmp(lengthError, "") == 0) {
            lengthError = "The length of the input is invalid.";
        }
        dblSize = 9;
    }

    if (acceptNull != 0 && acceptNull != 1) {
        acceptNull = 0;
    }

    if (acceptNull == 1) {
        if (strcmp(nullError, "") == 0) {
            nullError = "The input is invalid.";
        }
    }

    if (acceptNull == 0) {
        do {
            printf("%s", askStr);
            if (!fgets(str, 1024, stdin)) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("An unexpected error has occurred. Exiting...");
                exit(EXIT_FAILURE);
            }

            cleanstr(str);

            char *endPtr;

            errno = 0;
            nbr = strtod(str, &endPtr);
            if (errno == ERANGE) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("\033[0m%s\n", lengthError);
                isInputValid = 0;
            } else if (strlen(str) > dblSize) {
                printf("%s\n", lengthError);
                isInputValid = 0;
            } else if (*endPtr && *endPtr != '\n') {
                isInputValid = 0;
            } else {
                isInputValid = 1;
            }
        } while (!isInputValid);
    } else if (acceptNull == 1) {
        do {
            printf("%s", askStr);
            if (!fgets(str, 1024, stdin)) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("An unexpected error has occurred. Exiting...");
                exit(EXIT_FAILURE);
            }

            cleanstr(str);

            char *endPtr;

            errno = 0;
            nbr = strtod(str, &endPtr);
            if (errno == ERANGE) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("\033[0m%s\n", lengthError);
                isInputValid = 0;
            } else if (strlen(str) > dblSize) {
                printf("%s\n", lengthError);
                isInputValid = 0;
            } else if (endPtr == str) {
                printf("%s\n", nullError);
                isInputValid = 0;
            } else if (*endPtr && *endPtr != '\n') {
                isInputValid = 0;
            } else {
                isInputValid = 1;
            }
        } while (!isInputValid);
    } else {
        nbr = 0.0;
    }

    return nbr;
}

// Get a float input from the user
float inputfloat(char *askStr, int floatSize, char *lengthError, int acceptNull, char *nullError) {
    static char str[1024];
    float nbr;
    int isInputValid;

    if (floatSize == 0 || floatSize > 9) {
        if (strcmp(lengthError, "") == 0) {
            lengthError = "The length of the input is invalid.";
        }
        floatSize = 9;
    }

    if (acceptNull != 0 && acceptNull != 1) {
        acceptNull = 0;
    }

    if (acceptNull == 1) {
        if (strcmp(nullError, "") == 0) {
            nullError = "The input is invalid.";
        }
    }

    if (acceptNull == 0) {
        do {
            printf("%s", askStr);
            if (!fgets(str, 1024, stdin)) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("An unexpected error has occurred. Exiting...");
                exit(EXIT_FAILURE);
            }

            cleanstr(str);

            char *endPtr;

            errno = 0;
            nbr = (float) strtod(str, &endPtr);
            if (errno == ERANGE) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("\033[0m%s\n", lengthError);
                isInputValid = 0;
            } else if (strlen(str) > floatSize) {
                printf("%s\n", lengthError);
                isInputValid = 0;
            } else if (*endPtr && *endPtr != '\n') {
                isInputValid = 0;
            } else {
                isInputValid = 1;
            }
        } while (!isInputValid);
    } else if (acceptNull == 1) {
        do {
            printf("%s", askStr);
            if (!fgets(str, 1024, stdin)) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("An unexpected error has occurred. Exiting...");
                exit(EXIT_FAILURE);
            }

            cleanstr(str);

            char *endPtr;

            errno = 0;
            nbr = (float) strtod(str, &endPtr);
            if (errno == ERANGE) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("\033[0m%s\n", lengthError);
                isInputValid = 0;
            } else if (strlen(str) > floatSize) {
                printf("%s\n", lengthError);
                isInputValid = 0;
            } else if (endPtr == str) {
                printf("%s\n", nullError);
                isInputValid = 0;
            } else if (*endPtr && *endPtr != '\n') {
                isInputValid = 0;
            } else {
                isInputValid = 1;
            }
        } while (!isInputValid);
    } else {
        nbr = 0;
    }

    return nbr;
}

// Get a long input from the user
long inputlong(char *askStr, int longSize, char *lengthError, int acceptNull, char *nullError) {
    static char str[1024];
    long nbr;
    int isInputValid;

    if (longSize == 0 || longSize > 9) {
        if (strcmp(lengthError, "") == 0) {
            lengthError = "The length of the input is invalid.";
        }
        longSize = 9;
    }

    if (acceptNull != 0 && acceptNull != 1) {
        acceptNull = 0;
    }

    if (acceptNull == 1) {
        if (strcmp(nullError, "") == 0) {
            nullError = "The input is invalid.";
        }
    }

    if (acceptNull == 0) {
        do {
            printf("%s", askStr);
            if (!fgets(str, 1024, stdin)) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("An unexpected error has occurred. Exiting...");
                exit(EXIT_FAILURE);
            }

            cleanstr(str);

            char *endPtr;

            errno = 0;
            nbr = strtol(str, &endPtr, 10);
            if (errno == ERANGE) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("\033[0m%s\n", lengthError);
                isInputValid = 0;
            } else if (strlen(str) > longSize) {
                printf("%s\n", lengthError);
                isInputValid = 0;
            } else if (*endPtr && *endPtr != '\n') {
                isInputValid = 0;
            } else {
                isInputValid = 1;
            }
        } while (!isInputValid);
    } else if (acceptNull == 1) {
        do {
            printf("%s", askStr);
            if (!fgets(str, 1024, stdin)) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("An unexpected error has occurred. Exiting...");
                exit(EXIT_FAILURE);
            }

            cleanstr(str);

            char *endPtr;

            errno = 0;
            nbr = strtol(str, &endPtr, 10);
            if (errno == ERANGE) {
                printf("\033[1;31mError: %s\n", strerror(errno));
                printf("\033[0m%s\n", lengthError);
                isInputValid = 0;
            } else if (strlen(str) > longSize) {
                printf("%s\n", lengthError);
                isInputValid = 0;
            } else if (endPtr == str) {
                printf("%s\n", nullError);
                isInputValid = 0;
            } else if (*endPtr && *endPtr != '\n') {
                isInputValid = 0;
            } else {
                isInputValid = 1;
            }
        } while (!isInputValid);
    } else {
        nbr = 0;
    }

    return nbr;
}

/*
               _     _
              | |   | |
  _ __ ___  __| | __| |
 | '__/ _ \/ _` |/ _` |
 | | |  __/ (_| | (_| |
 |_|  \___|\__,_|\__,_|
*/
