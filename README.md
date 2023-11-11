# reddlibc

A static C library used for my convenience.

## TODO

- [ ] Make a binary release
- [ ] Write some documentation

## Installation
To install this library you must :

1. [Compile the library](https://github.com/redds-be/reddlibc/wiki/Compiling).
2. [Install the library](https://github.com/redds-be/reddlibc/wiki/Installing).

## Uninstalling
Follow these [instructions](https://github.com/redds-be/reddlibc/wiki/Uninstalling).

## Usage when compiling your program

Exemple :

```console
user@host:cproject$ gcc main.c -l:reddlibc.a
```

`main.c` : Your program

`-l:reddlibc.a` : Name of the library

> NOTE : If the library was installed in a directory were gcc does not look for libraries by default, add `-L /path/to/lib/dir` before `-l:reddlibc.a`.

## LICENSING

*Why didn't you put it under **LGPL** ?* : If one day the library is used by anyone other than me, I **DO NOT** want it to be used in a proprietary project.

*Project under the [GPLv3 License](https://www.gnu.org/licenses/gpl-3.0.html).*

*Copyright (C) 2023 redd*