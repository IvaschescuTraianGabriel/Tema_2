CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-Iinclude

SRC_DIR=src
OBJ_DIR=obj

SRCS=$(wildcard $(SRC_DIR)/*.c)

OBJS=$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: file_processor


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@


file_processor: $(OBJS)
	$(CC) $(OBJS) -o $@

clean:
	rm -rf $(OBJ_DIR) file_processor

.PHONY: all clean
