BUILDIR = ./build
BINDIR = ./bin
CFILES = $(shell find ./src -type f -name '*.c' -exec basename \{} \;)
OBJFILES = $(shell find . -type f -name '*.o' -exec basename \{} \;)
LIBDESTDIR = /usr/lib
HEADERDESTDIR = /usr/include
HEADERS = $(shell find ./include -type f -name '*.h' -exec basename \{} \;)
MANPAGES = $(shell find ./man -type f -name '*' -exec basename \{} \;)
COMPMANPAGES = $(wildcard man/*.3.gz)
MANDIR = /usr/share/man/man3

all: clean obj lib manpage

prep: clean format lint

obj:
	@mkdir -p $(BUILDIR)
	@for c in $(CFILES); do gcc -c src/$$c; done && mv $(OBJFILES) build/

lib:
	@mkdir -p $(BUILDIR)
	@mkdir -p $(BINDIR)
	@cd $(BUILDIR) && ar rcs reddlibc.a *.o && mv reddlibc.a ../$(BINDIR)

manpage:
	@for m in $(MANPAGES); do gzip < man/$$m > man/$$m.3.gz; done

install:
	@install -o root -g root -m 0644 $(BINDIR)/reddlibc.a $(LIBDESTDIR)
	@for header in $(HEADERS); do install -o root -g root -m 0644 include/$$header $(HEADERDESTDIR); done
	@for m in $(COMPMANPAGES); do install -o root -g root -m 0644 $$m $(MANDIR); done
	@for m in $(MANPAGES); do links=$$(cat man/$$m | grep "()" | sed 's/.B //g' | sed 's/()//g') && for l in $$links; do ln -sf $(MANDIR)/$$m.3.gz $(MANDIR)/$$l.3.gz; done; done

uninstall:
	@rm -f $(LIBDESTDIR)/reddlibc.a
	@for header in $(HEADERS); do rm -f $(HEADERDESTDIR)/$$header; done
	@for m in $(MANPAGES); do find -L $(MANDIR) -samefile $(MANDIR)/$$m.3.gz -delete; done

format:
	@for f in $(CFILES); do clang-format -i src/$$f; done

lint:
	@for f in $(CFILES); do clang-tidy src/$$f -- -Imy_project/include -DMY_DEFINES && cppcheck src/$$f && cpplint src/$$f && include-what-you-use src/$$f; done

clean:
	@rm -rf $(BUILDIR)
	@rm -rf $(BINDIR)
	@for m in $(MANPAGES); do rm -f man/$$m.3.gz; done
