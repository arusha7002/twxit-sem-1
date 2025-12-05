
CC = gcc

CFLAGS = -Wall -g

SRCS = printtwixt.c main.c playerinput.c printboardaftereachmove.c recordamove.c linkvaliditycheck.c winnerwinner.c


OBJS = $(SRCS:.c=.o)


TARGET = twixt

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(TARGET)

