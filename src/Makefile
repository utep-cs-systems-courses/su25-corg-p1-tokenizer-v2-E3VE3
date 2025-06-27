# comments begin with #

# list of object files for this project
OBJS = tokenizer.o history.o uimain.o

# compiler flags: -g for debugging, -O3 for optimization
CFLAGS = -g -O3

# default target to build
all: tokenizer

# tokenizer (target) depends on all object files
tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

# remove all generated object files and the final executable
clean:
	rm -f *.o tokenizer

# run the program after building it
run: tokenizer
	./tokenizer
