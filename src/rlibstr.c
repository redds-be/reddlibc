/*
A C program that handles some string manipulation.
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
#include "../include/rlibstr.h"
#include <ctype.h>
#include <string.h>

// Clean a string by removing \r and \n at the end of the string
char *cleanstr(char *strToClean) {
    // Clean a string
    strToClean[strcspn(strToClean, "\r\n")] = 0;
    return strToClean;
}

// Convert upper-case string to lower-case string
char *lowerstr(char *str) {
    // Transform a string into lowercase
    for (int i = 0; str[i]; i++) {
        int letter = (int) str[i];
        letter = tolower(letter);
        str[i] = (char) letter;
    }
    return str;
}

// Convert lower-case string to upper-case string
char *upperstr(char *str) {
    // Transform a string into uppercase
    for (int i = 0; str[i]; i++) {
        int letter = (int) str[i];
        letter = toupper(letter);
        str[i] = (char) letter;
    }
    return str;
}
