# Define compiler and flags
CC = avr-gcc
CFLAGS = -Wall -Os -mmcu=atmega32

# Source files
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

# Target
TARGET = program

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	avr-objcopy -j .text -j .data -O ihex $(TARGET) $(TARGET).hex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) $(TARGET).hex

.PHONY: all clean