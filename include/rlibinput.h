/*
A C header that handles some user inputs.
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

#ifndef REDDLIBC_RLIBINPUT_H
#define REDDLIBC_RLIBINPUT_H

// Get a string (char *) input from the user
char *inputstr(char *askStr, int strSize, char *lengthError, int acceptNull, char *nullError);

// Get a char input from the user
char inputchar(char *askStr);

// Get an int input from the user
int inputint(char *askStr, int intSize, char *lengthError, int acceptNull, char *nullError);

// Get a double input from the user
double inputdbl(char *askStr, int dblSize, char *lengthError, int acceptNull, char *nullError);

// Get a float input from the user
float inputfloat(char *askStr, int floatSize, char *lengthError, int acceptNull, char *nullError);

// Get a long input from the user
long inputlong(char *askStr, int longSize, char *lengthError, int acceptNull, char *nullError);

#endif// REDDLIBC_RLIBINPUT_H
