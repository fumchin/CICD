CC = clang
CFLAGS = -Iinclude
LDFLAGS = -lcunit

all: build test

# 編譯主程式
build:
	mkdir -p bin
	$(CC) $(CFLAGS) src/main.c src/add.c -o bin/main

# 編譯並運行測試 (不編譯 src/main.c，只編譯測試和函數實現)
test:
	mkdir -p bin
	$(CC) $(CFLAGS) tests/test_main.c src/add.c -o bin/test $(LDFLAGS)
	./bin/test

clean:
	rm -rf bin/*
