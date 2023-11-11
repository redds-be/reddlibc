BUILDIR = ./build
BINDIR = ./bin
CFILES = $(wildcard *.c)
OBJFILES = $(wildcard *.o)
LIBDESTDIR = /usr/lib
HEADERDESTDIR = /usr/include
HEADERS = $(wildcard *.h)
MANPAGES = $(shell find ./man -type f -name '*' -exec basename \{} \;)
MANDIR = /usr/share/man/man3

all: obj lib manpage

obj:
	@mkdir -p $(BUILDIR)
	@cp $(CFILES) $(HEADERS) $(BUILDIR) && cd $(BUILDIR) && gcc -c $(CFILES)

lib:
	@mkdir -p $(BUILDIR)
	@mkdir -p $(BINDIR)
	@cd $(BUILDIR) && ar rcs reddlibc.a *.o && mv reddlibc.a ../$(BINDIR)

manpage:
	@for m in $(MANPAGES); do gzip < man/$$m > man/$$m.3.gz; done

install:
	@install -o root -g root -m 0644 $(BINDIR)/reddlibc.a $(LIBDESTDIR)
	@for header in $(HEADERS); do install -o root -g root -m 0644 $$header $(HEADERDESTDIR); done
	@for m in $(MANPAGES); do install -o root -g root -m 0644 man/$$m.3.gz $(MANDIR) && links=$$(cat man/$$m | grep "()" | sed 's/.B //g' | sed 's/()//g') && for l in $$links; do ln -sf $(MANDIR)/$$m.3.gz $(MANDIR)/$$l.3.gz; done; done

uninstall:
	@rm -f $(LIBDESTDIR)/reddlibc.a
	@for header in $(HEADERS); do rm -f $(HEADERDESTDIR)/$$header; done
	@for m in $(MANPAGES); do find -L $(MANDIR) -samefile $(MANDIR)/$$m.3.gz -delete; done

format:
	@for f in $(CFILES); do clang-format -i $$f; done

lint:
	@for f in $(CFILES); do clang-tidy $$f -- -Imy_project/include -DMY_DEFINES && cppcheck $$f && cpplint $$f && include-what-you-use $$f; done

clean:
	@rm -rf $(BUILDIR)
	@rm -rf $(BINDIR)
	@for m in $(MANPAGES); do rm -f man/$$m.3.gz; done
