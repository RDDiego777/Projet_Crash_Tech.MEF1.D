CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
TARGET = crashTech
SRCS = main.c csv.c year_data.c age_data.c crash_data.c avl.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c crash_tech.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
