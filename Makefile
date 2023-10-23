DESTDIR = /usr/include
FILES = $(wildcard *.h)

all:
	@echo Run \'make install\' to install the headers.

# I know i could just do a simple cp but there can be exceptions.
install:
	for header in $(FILES); do cp -v $$header $(DESTDIR); done

uninstall:
	for header in $(FILES); do rm -fv $(DESTDIR)/$$header; done