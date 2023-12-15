
TARGET=kemieBSD
C_FILES=./libc/string/memcmp.c \
	./libc/string/memset.c \
	./libc/string/strcat.c \
	./libc/string/strchr.c \
	./libc/string/strcmp.c \
	./libc/string/strcpy.c \
	./libc/string/strlen.c \
	./libc/string/strncmp.c \
	./libc/string/strstr.c \
	./libc/string/strutil.c \
	./libc/string/ctos.c \
	./kernel/tty.c \
	./kernel/io.c \
	./kernel.c

ASM_FILE = start.asm
ASM_OBJ = $(ASM_FILE:.asm=.o)

OBJS = $(C_FILES:.c=.o)

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as

CFLAGS = -ffreestanding -fno-exceptions

all: $(TARGET)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

$(ASM_OBJ): $(ASM_FILE)
	$(AS) -o $@ $<

$(TARGET): $(ASM_OBJ) $(OBJS)
	$(CC) -nostdlib -nodefaultlibs -lgcc $^ -T linker.ld -o $@

.PHONY: all clean

clean:
	rm -f *.o $(TARGET)