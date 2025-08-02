CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror -pedantic
PROGRAM = test
OBJS = main.o infix.o stack.o

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM) -lm 

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PROGRAM) $(OBJS)
