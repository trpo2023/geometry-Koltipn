CC = gcc
CFLAGS = -Wall -Werror

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

APP_NAME = ge

GEOMETRY_OBJ = $(OBJ_DIR)/geometry/ge.o
GEOMETRY_CALC_A= $(OBJ_DIR)/libgeometry/ge_calc.a
GEOMETRY_CALC_OBJ= $(OBJ_DIR)/libgeometry/ge_calc.o

APP_DEPS = $(GEOMETRY_OBJ) $(GEOMETRY_CALC_A)
APP_OBJ = $(BIN_DIR)/$(APP_NAME)

.PHONY: all clean test

all: $(APP_OBJ)

$(APP_OBJ): $(APP_DEPS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^

$(GEOMETRY_OBJ): $(SRC_DIR)/geometry/ge.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(GEOMETRY_CALC_A): $(OBJ_DIR)/libgeometry/ge_calc.o
	ar rcs $@ $<
$(GEOMETRY_CALC_OBJ): $(SRC_DIR)/libgeometry/ge_calc.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

-include $(OBJ_DIR)/geometry/ge.d $(OBJ_DIR)/libgeometry/ge_calc.d

$(OBJ_DIR)/geometry:
	mkdir -p $@

$(OBJ_DIR)/libgeometry:
	mkdir -p $@
