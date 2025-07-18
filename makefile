CFLAGS = -Wall -Wextra -std=c++11 -g -O0

MY_LIBS = $(wildcard lpcDir/*)
HEADERS = lpcDir/List.hpp lpcDir/Queue.hpp lpcDir/Stack.hpp
NO_HEADERS = lpcDir/List.cpp lpcDir/Queue.cpp lpcDir/Stack.cpp
OBJECTS = $(patsubst lpcDir/%.cpp, object/%.o, $(NO_HEADERS))
TARGET = main.cpp
OUTPUT = lpc

$(OUTPUT): $(TARGET) $(HEADERS) $(OBJECTS)
	g++ $(CFLAGS) -o $(OUTPUT) $(TARGET) $(OBJECTS)

# antigua regla de compilacion
# $(OUTPUT): $(TARGET) $(MY_LIBS) 
# 	g++ $(CFLAGS) -o $(OUTPUT) $(TARGET)

run: generic_types $(OUTPUT)
	./$(OUTPUT)

run_txt: generic_types $(OUTPUT)
	./$(OUTPUT) < input.txt

object/%.o: lpcDir/%.cpp
	g++ $(CFLAGS) -o $@ -c $<

clean:
	rm -f ./$(OUTPUT) object/*

generic_types:
	python generic_types.py

find_error: $(OUTPUT)
	@gdb -x find_error ./$(OUTPUT)

personalized: $(OUTPUT)
	@gdb -x personalized ./$(OUTPUT)

ready: clean
	rm -fi find_error personalized tests.py
	echo "recuerda colocar -O3 y -s"

tests: $(OUTPUT)
	python tests.py

.PHONY: clean run find_error personalized generic_types
