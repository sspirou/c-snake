PROG=c-snake

# Remove -DNDEBUG during development if assert(3) is used
#
override CPPFLAGS += -DNDEBUG

CC = clang

# Replace -O1 with -g for a debug version during development
#
CFLAGS = -Wall -Werror -O1

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

.PHONY : clean

$(PROG) : $(OBJS)
	$(CC) -o $@ $^

clean :
	$(RM) $(OBJS) $(PROG)