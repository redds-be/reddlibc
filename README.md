# reddlibc

A static C library used for my convenience.

## TODO

- [ ] Make a binary release
- [ ] Write some documentation

## Compiling

*You must have `make, gcc, binutils` installed to follow this step.*

Run `make` as any user (preferably **not** `root`).

```console
user@host:reddlibc$ make
```

## Installing

### Makefile

*You must have `make` installed to follow this step.*

Run `make install` as `root`.

```console
root@host:reddlibc# make install
```

### Manually

1. Copy all the header files into `/usr/include` or another directory fitting for header files.
2. Copy `bin/reddlibc.a` into `/usr/lib` or another directory fitting for a library.

## Uninstalling

### Makefile

*You must have `make` installed to follow this step.*

Run `make uninstall` as `root`.

```console
root@host:reddlibc# make uninstall
```

### Manually

1. Delete all the previously installed header files from `/usr/include` or another directory you choose when installing manually.
2. Delete `reddlibc.a` from `/usr/lib` or another directory you choose when installing manually.

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