CFLAGS := -ggdb3 -O2 -Wall -Wextra -std=gnu11
CFLAGS += -Wmissing-prototypes

# To force build a test shell run:
#     make -B -e WIKI_TEST=true

EXEC := wiki
SRCS := $(wildcard *.c)
OBJS := $(SRCS:%.c=%.o)

run:
	cmake -S . -B build
	cmake --build build
	./build/Wiki



test:
	cmake -S . -B build
	cmake --build build
	./build/WikiTests

format: .clang-files .clang-format
	xargs -r clang-format -i <$<

clean:
	rm -rf $(EXEC) *.o core vgcore.*

.PHONY: all clean format valgrind test
