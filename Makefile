CC = gcc

CFLAGS = `pkg-config --cflags poppler-glib`
LDFLAGS = `pkg-config --libs poppler-glib`

TARGET = nftwpdf


SRC_DIR = src
NFTW_WRAPPERS_DIR = $(SRC_DIR)/nftw_wrappers
NFTW_WRAPPERS = $(NFTW_WRAPPERS_DIR)/hl_check.c $(NFTW_WRAPPERS_DIR)/hl_print.c


SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(NFTW_WRAPPERS)

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
