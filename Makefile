NAME			:= libasm.a

AS				:= nasm
ASFLAGS			:= -f elf64
AR				:= ar
ARFLAGS			:= rcs
REMOVE			:= rm -rf

HEADER_PATH		:= ./includes
HEADER_FILES	:= $(wildcard $(HEADER_PATH)/*.h)

SOURCE_PATH		:= ./sources
SOURCE_FILES	:= $(wildcard $(SOURCE_PATH)/*.s)

OBJECT_PATH		:= ./objects
OBJECT_FILES	:= $(patsubst $(SOURCE_PATH)/%.s,$(OBJECT_PATH)/%.o,$(SOURCE_FILES))

TEST_PATH		:= tests

vpath			%.s $(SOURCE_PATH)
vpath			%.h $(HEADER_PATH)

all: $(NAME)

$(OBJECT_PATH)/%.o: %.s Makefile | $(OBJECT_PATH)
	$(AS) $(ASFLAGS) -o $@ $<

$(NAME): $(OBJECT_FILES)
	$(AR) $(ARFLAGS) -o $@ $^

$(OBJECT_PATH):
	mkdir -p $@

clean:
	$(REMOVE) $(OBJECT_PATH)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

test: all
	make -C $(TEST_PATH)

vgtest: all
	make -C $(TEST_PATH) vg

.PHONY: all clean fclean re test vgtest
