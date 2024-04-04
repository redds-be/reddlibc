/*
A C program that handles some char manipulation.
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
#include "../include/rlibchar.h"
#include <ctype.h>

// Convert upper-case char to lower-case char
char lowerchar(char character) {
    character = tolower(character);
    return character;
}

// Convert lower-case char to upper-case char
char upperchar(char character) {
    character = toupper(character);
    return character;
}

/*
               _     _
              | |   | |
  _ __ ___  __| | __| |
 | '__/ _ \/ _` |/ _` |
 | | |  __/ (_| | (_| |
 |_|  \___|\__,_|\__,_|
*/
