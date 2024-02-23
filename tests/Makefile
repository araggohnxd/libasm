TARGET := a.out

HEADER_PATH := ./includes
HEADER_FILES := tests.h

UNITY_PATH := ./unity
UNITY := unity.c

SOURCE_PATH := ./sources ./unity
SOURCE_FILES := $(shell ls $(SOURCE_PATH) | grep .c$)

OBJECT_PATH := ./objects
OBJECT_FILES := $(SOURCE_FILES:%.c=$(OBJECT_PATH)/%.o)

LIBASM_PATH := ..
LIBASM := $(LIBASM_PATH)/libasm.a

CC := cc
CFLAGS := -Wall -Wextra -g3
IFLAGS := -I $(HEADER_PATH)
IFLAGS += -I $(UNITY_PATH)
IFLAGS += -I $(LIBASM_PATH)/includes
LDFLAGS := -L $(LIBASM_PATH) -lasm
VALGRIND := valgrind
VGFLAGS := --leak-check=full --show-leak-kinds=all --track-fds=yes
REMOVE := rm -rf

vpath %.c $(SOURCE_PATH)
vpath %.h $(HEADER_PATH)

all: test

$(TARGET): $(LIBASM) $(OBJECT_FILES)
	$(CC) $(CFLAGS) -o $@ $(OBJECT_FILES) $(LDFLAGS)

test: $(TARGET)
	./$(TARGET)

vg:	$(TARGET)
	$(VALGRIND) $(VGFLAGS) ./$(TARGET)

$(OBJECT_PATH)/%.o: %.c $(HEADER_FILES) Makefile | $(OBJECT_PATH)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJECT_PATH):
	mkdir -p $@

$(LIBASM):
	make -C $(LIBASM_PATH)

clean:
	$(REMOVE) $(OBJECT_PATH)

fclean: clean
	$(REMOVE) $(TARGET)

re: fclean all

.PHONY: all clean fclean re test vg
