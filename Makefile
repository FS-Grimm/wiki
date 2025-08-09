CFLAGS := -ggdb3 -O2 -Wall -Wextra -std=gnu11
CFLAGS += -Wmissing-prototypes

# To force build a test shell run:
#     make -B -e WIKI_TEST=true

EXEC := wiki
SRCS := $(wildcard *.c)
OBJS := $(SRCS:%.c=%.o)

all: $(EXEC)

$(EXEC): $(OBJS)

valgrind: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC)

test:
	./tests/run

test-%:
	./tests/run $*

format: .clang-files .clang-format
	xargs -r clang-format -i <$<

clean:
	rm -rf $(EXEC) *.o core vgcore.*

.PHONY: all clean format valgrind test
