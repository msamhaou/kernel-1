
CC=gcc
FLAGS=-m32	\
	-fno-builtin  \
	-fno-stack-protector    \
	-nostdlib               \
	-nodefaultlibs	\

INC=-Isrc/driver/ -Isrc/utils/
OBJ_DIR=obj
SRC_DIR= src
TARGET=kernel.elf
LINKER = ld
LFLAGS=-T linker.ld -m elf_i386
OSNAME=bestOs
SRCS = $(shell find . -name "*.c" | sed 's|^\./||')
ASM_SRCS= $(shell find . -name "*.asm" | sed 's|^\./||')
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
ASM_OBJS = $(patsubst %.asm, $(OBJ_DIR)/%.o, $(ASM_SRCS))

ALL_OBJ = $(ASM_OBJS) $(OBJS)
BOOTLOADER_OBJ = $(OBJ_DIR)/bootloader.o
all:$(TARGET) 

$(TARGET) :  $(ALL_OBJ)
	$(LINKER) $(LFLAGS) -o $@ $^

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC) -c -o $@ $<

$(OBJ_DIR)/%.o : %.asm | $(OBJ_DIR)
	mkdir -p $(dir $@)
	nasm -f elf32 -o $@ $<


$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(TARGET)
	rm -rf iso/boot/$(TARGET)
	rm -rf $(OSNAME).iso

bestos: $(TARGET)
	cp $(TARGET) iso/boot
	grub-mkrescue -o $(OSNAME).iso iso

