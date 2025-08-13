
LPC_DIR = lpcDir
CFLAGS = -Wall -Wextra -Werror -g -O0 -I$(LPC_DIR)

MY_LIBS = $(wildcard $(LPC_DIR)/*)
TARGET = main.cpp
OUTPUT = lpc

all: $(OUTPUT)

$(OUTPUT): $(TARGET) $(MY_LIBS)
	g++ $(CFLAGS) -o $(OUTPUT) $(TARGET) 

run: $(OUTPUT)
	./$(OUTPUT) < input.txt

clean:
	rm -f ./$(OUTPUT) 

find_error: $(OUTPUT)
	@gdb -x find_error ./$(OUTPUT)

ready: clean
	rm -fi find_error debug.cpp 
	echo "recuerda colocar -O3"
	echo "borra las cosas innecesarias del makefile por favor"

remember:
	cat notas.txt

.PHONY: clean run find_error 
