CC = gcc

CFLAGS = `pkg-config --cflags poppler-glib`
LDFLAGS = `pkg-config --libs poppler-glib`

TARGET = nftwpdf

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/error.c $(SRC_DIR)/annot_check.c $(SRC_DIR)/suppress.c

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean

