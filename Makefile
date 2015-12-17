
EDITOR = /usr/bin/vim
INDENT = /usr/bin/indent

CC        = clang
LDFLAGS   = -O
LDFLAGS   = -lm
CFLAGS    = -Weverything -Wextra -pedantic $(LDFLAGS)
#LDLIBS   = -lm -lgsl -lgslcblas
LDLIBS    = $(shell gsl-config --libs)

.SUFFIXES:
.SUFFIXES:  .c .o .h

.PHONY: edit clean veryclean

target    = hw07

$(target) : $(target).c

edit : $(target).c
	$(EDITOR) $<
	$(INDENT) $<

clean : 
	rm -f *.o
	rm -f *.*~

veryclean : clean
	rm  -f $(target)
