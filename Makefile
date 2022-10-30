# BUILD_VERSION < 0

prefix = /usr/local
prefix = /usr/local
mandir = $(prefix)/share/man
man1dir = $(mandir)/man1

# Compiler settings - Can be customized.
CXX = g++
CXXFLAGS = -Wall -std=c++17 -DDEBUG -ggdb

# lib settings
LDFLAGS = -static -lcppunit -L/usr/local/lib/
INCLUDES = -I/usr/local/include/cppunit/

# Makefile settings - Can be customized.
APPNAME = music_sync
EXT = cpp
ROOTDIR  = .
BUILDDIR = ./build
OBJDIR = $(BUILDDIR)
SRCDIR = ./src
# OBJ_COUNT=$(shell ls *.o | wc -l 2> /dev/null)
# OBJ_COUNT=$(shell ls *.o | wc -l)   

# compile & link for debug
# debug_first: 
# 	$(CXXFLAGS) += $(CXXFLAGS) -DDEBUG -g
# debug: debug_first all

all: $(APPNAME) add_files readlines merge bash_color_test

# link
$(APPNAME): $(APPNAME).o main.o
	 $(CXX) $(CXXFLAGS) $(BUILDDIR)/$(APPNAME).o $(BUILDDIR)/main.o  -o $(BUILDDIR)/$(APPNAME)

# compile only
$(APPNAME).o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$(APPNAME).$(EXT) -o $(BUILDDIR)/$(APPNAME).o
	
main.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main.$(EXT) -o $(BUILDDIR)/main.o
	# $(CXX) $(CXXFLAGS) $(INCLUDES) $(BUILDDIR)/$(APPNAME).o $(LDFLAGS) -o $(BUILDDIR)/$(APPNAME)_test

# link
$(APPNAME)_test: $(APPNAME)_test.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(BUILDDIR)/$(APPNAME)_test.o $(BUILDDIR)/$(APPNAME).o $(LDFLAGS) -o $(BUILDDIR)/$(APPNAME)_test

# add files exe
# link
add_files: add_files.o main.o  
	 $(CXX) $(CXXFLAGS) $(BUILDDIR)/add_files.o $(BUILDDIR)/main.o  -o $(BUILDDIR)/add_files

# compile only
add_files.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/add_files.$(EXT) -o $(BUILDDIR)/add_files.o

readlines: readlines.o main.o  
	 $(CXX) $(CXXFLAGS) $(BUILDDIR)/readlines.o $(BUILDDIR)/main.o  -o $(BUILDDIR)/readlines

# compile only
readlines.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/readlines.$(EXT) -o $(BUILDDIR)/readlines.o

merge: merge.o main.o  
	 $(CXX) $(CXXFLAGS) $(BUILDDIR)/merge.o $(BUILDDIR)/main.o  -o $(BUILDDIR)/merge

# compile only
merge.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/merge.$(EXT) -o $(BUILDDIR)/merge.o
	
# compile only
$(APPNAME)_test.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$(APPNAME)_test.cpp -o $(BUILDDIR)/$(APPNAME)_test.o

bash_color_test: bash_color_test.o
	$(CXX) $(CXXFLAGS) $(BUILDDIR)/bash_color_test.o -o $(BUILDDIR)/bash_color_test

bash_color_test.o:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/bash_color_test.cpp -o $(BUILDDIR)/bash_color_test.o


## auto gernerated here ##

# install man pages
.PHONY: man
man:
	cp ../man/$(APPNAME).1 $(man1dir)
	# gzip $(man1dir)/$(APPNAME).1
	mandb

.PHONY: unman
unman:
	rm $(man1dir)/$(APPNAME).1.gz
	mandb

# install 
.PHONY: install
install: man
	cp $(BUILDDIR)/$(APPNAME) $(prefix)/bin/$(APPNAME)
	rm $(prefix)/bin/$(APPNAME)

# delete object files & app executable
.PHONY: clean
clean:
	# -rm -f $(BUILDDIR)/$(APPNAME)
	# -rm -f $(BUILDDIR)/$(APPNAME)_test 
	# -rm -f $(BUILDDIR)/add_files
	# -rm -f $(BUILDDIR)/add_files_test
	# -rm -f $(BUILDDIR)/readlines
	# -rm -f $(BUILDDIR)/merge
	# -rm -f $(BUILDDIR)/bash_color_test
	# -rm -f $(BUILDDIR)/$(APPNAME).$(BUILD_VERSION).tar.gz
	# -rm -f $(BUILDDIR)/*.o
	# -rm -f $(BUILDDIR)/*.xml  
	-rm -rf ./build/*
	
# delete all auto generated files
.PHONY: distclean
distclean: clean
	-rm -f $(SRCDIR)/config.* $(SRCDIR)/Makefile $(SRCDIR)/Makefile.in $(SRCDIR)/INSTALL $(SRCDIR)/configure 
	-rm ../stamp-h1 ../aclocal.m4 ../compile ../install-sh ../libtool ../ltmain.sh ../stamp-h1 ../missing ../depcomp
	-rm ../src/Makefile ../src/Makefile.in
	-rm -rf ../autom4te.cache ../src/.deps ../src/.libs
	-rm ../src/.o

dist: 
	git archive HEAD | gzip > $(BUILDDIR)/$(APPNAME).$(BUILD_VERSION).tar.gz
