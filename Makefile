CC = gcc

CFLAGS = `pkg-config --cflags poppler-glib`
LDFLAGS = `pkg-config --libs poppler-glib`

TARGET = nftwpdf

SRC_DIR = src
MODULES = $(SRC_DIR)/modules
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/error.c  $(SRC_DIR)/suppress.c  $(MODULES)/hl_check.c  $(MODULES)/hl_print.c

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
