BUILDIR = ./build
BINDIR = ./bin
CFILES = $(wildcard *.c)
OBJFILES = $(wildcard *.o)
LIBDESTDIR = /usr/lib
HEADERDESTDIR = /usr/include
HEADERS = $(wildcard *.h)

all: obj lib

obj:
	mkdir -p $(BUILDIR)
	cp -v $(CFILES) $(HEADERS) $(BUILDIR) && cd $(BUILDIR) && gcc -c $(CFILES)

lib:
	mkdir -p $(BUILDIR)
	mkdir -p $(BINDIR)
	cd $(BUILDIR) && ar rcs reddlibc.a *.o && mv reddlibc.a ../$(BINDIR)

install:
	cp -v $(BINDIR)/reddlibc.a $(LIBDESTDIR)
	for header in $(HEADERS); do cp -v $$header $(HEADERDESTDIR); done

uninstall:
	rm -fv $(LIBDESTDIR)/reddlibc.a
	for header in $(HEADERS); do rm -fv $(HEADERDESTDIR)/$$header; done

format:
	for f in $(CFILES); do clang-format -i $$f; done

lint:
	for f in $(CFILES); do clang-tidy $$f -- -Imy_project/include -DMY_DEFINES && cppcheck $$f && cpplint $$f && include-what-you-use $$f; done

clean:
	rm -rf $(BUILDIR)
	rm -rf $(BINDIR)