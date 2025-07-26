CFLAGS = -Wall -Wextra -s -O3

LPC_DIR = lpcDir
MY_LIBS = $(wildcard $(LPC_DIR)/*)
HEADERS = lpcDir/List.hpp lpcDir/Queue.hpp lpcDir/Stack.hpp
NO_HEADERS = lpcDir/List.cpp lpcDir/Queue.cpp lpcDir/Stack.cpp
OBJECTS = $(patsubst $(LPC_DIR)/%.cpp, object/%.o, $(NO_HEADERS))
TARGET = main.cpp
OUTPUT = lpc

$(OUTPUT): $(TARGET) $(HEADERS) $(OBJECTS)
	g++ $(CFLAGS) -o $(OUTPUT) $(TARGET) $(OBJECTS)

# antigua regla de compilacion
# $(OUTPUT): $(TARGET) $(MY_LIBS) 
# 	g++ $(CFLAGS) -o $(OUTPUT) $(TARGET)

object/%.o: lpcDir/%.cpp
	g++ $(CFLAGS) -o $@ -c $<

run: generic_types $(OUTPUT)
	./$(OUTPUT) < input.txt

clean:
	rm -f ./$(OUTPUT) object/*

generic_types:
	@python generic_types.py

find_error: $(OUTPUT)
	@gdb -x find_error ./$(OUTPUT)

ready: clean
	rm -fi find_error debug.cpp generic_types.py
	echo "recuerda colocar -O3 y -s"

remember:
	cat notas.txt

.PHONY: clean run find_error generic_types
