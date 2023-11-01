/*
A C program that handles some int manipulation.
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
#include "./rlibint.h"
#include <stdio.h>

void intobinary(unsigned int nbr, unsigned int length) {
    unsigned int i;
    length = length-1;

    if (length > 30) {
        length = 30;
    }

    for (i = 1 << length; i > 0; i = i / 2)
        (nbr & i) ? printf("1") : printf("0");
}

/*
               _     _
              | |   | |
  _ __ ___  __| | __| |
 | '__/ _ \/ _` |/ _` |
 | | |  __/ (_| | (_| |
 |_|  \___|\__,_|\__,_|
*/