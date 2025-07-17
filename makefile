CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -Ilpc -O0

MY_LIBS = $(wildcard lpc/*)
HEADERS = $(wildcard lpc/*.hpp)
NO_HEADERS = $(wildcard lpc/*.cpp)
OBJECTS = $(patsubst lpc/%.cpp, object/%.o, $(NO_HEADERS))
TARGET = main.cpp
OUTPUT = build

$(OUTPUT): $(TARGET) $(HEADERS) $(OBJECTS)
	g++ $(CFLAGS) -o $(OUTPUT) $(TARGET) $(OBJECTS)

# antigua regla de compilacion
# $(OUTPUT): $(TARGET) $(MY_LIBS) 
# 	g++ $(CFLAGS) -o $(OUTPUT) $(TARGET)

run: $(OUTPUT)
	./$(OUTPUT)

run_txt: $(OUTPUT)
	./$(OUTPUT) < input.txt

object/%.o: lpc/%.cpp
	g++ $(CFLAGS) -o $@ -c $<

clean:
	rm -f ./$(OUTPUT) object/*

generic_types:
	bash add_generic.txt

find_error: $(OUTPUT)
	@gdb -x find_error ./$(OUTPUT)

personalized: $(OUTPUT)
	@gdb -x personalized ./$(OUTPUT)

ready: clean
	rm -fi find_error personalized tests.py
	echo "recuerda colocar -O3 y -s"

tests: $(OUTPUT)
	python tests.py

.PHONY: clean run find_error personalized
