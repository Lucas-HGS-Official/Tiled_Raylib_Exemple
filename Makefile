TARGET = bin/raylib_tiled_test
SRC = $(wildcard code/src/*.c)
OBJ = $(patsubst code/src/%.c, obj/%.o, $(SRC))


build: clean $(TARGET)

$(TARGET): $(OBJ)
	gcc -o $@ $? -Wall -std=c99 -lraylib -ldl -lGL -lm -lpthread -ldl -lrt -lX11
	
obj/%.o : code/src/%.c
	gcc -c $< -o $@ -Icode/include


clean:
	rm -f obj/*.o
	rm -f bin/*

run:
	./$(TARGET)