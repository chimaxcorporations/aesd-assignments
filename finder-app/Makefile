CC = gcc
CFLAGS = -Wall -Wextra -Werror
CROSS_COMPILE = aarch64-none-linux-gnu-
.PHONY: build run clean

build: 
	@$(CC) $(CFLAGS) -o writer writer.c

run: build
	@test -e /tmp/aeld-data || mkdir -p /tmp/aeld-data 
	@touch /tmp/aeld-data/hello.txt
	@./writer /tmp/aeld-data/hello.txt "Hello World

clean:
	@rm -f writer