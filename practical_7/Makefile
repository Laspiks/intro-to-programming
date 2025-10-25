CC = gcc
CFLAGS = -Wall -Wextra -std=c99

PKGCONFIG = pkg-config
GSTREAMER_CFLAGS = $(shell $(PKGCONFIG) --cflags gstreamer-1.0)
LIBS = $(shell $(PKGCONFIG) --libs gstreamer-1.0)

# extend with gtest-demo
all: gstreamer-demo pointers

gstreamer-demo: gstreamer-demo/demo.c
	$(CC) $(CFLAGS) $(GSTREAMER_CFLAGS) $(LIBS) gstreamer-demo/demo.c -o gstreamer-demo/demo

pointers: pointers/examples.c
	$(CC) $(CFLAGS) pointers/examples.c -o pointers/examples

clean:
	rm -f gstreamer-demo/demo pointers/examples
