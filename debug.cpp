#include <iostream>
#include <cstring>

template <typename T>
void debug_variables(const char* names, T value) {
    std::cout.write(names, strlen(names)) << std::endl;
}

template<typename T, typename... Args>
void debug_variables(const char* names, T value, Args... args) {
    const char* comma = strchr(names, ',');

    if (comma) {
        std::cout.write(names, comma - names) << ": " << value << " ";
        debug_variables(comma + 2, args...);
    } else {
        std::cout.write(names, strlen(names)) << ": " << value << std::endl;
        std::cout << std::endl;
    }
}

#define debug(...) debug_variables(#__VA_ARGS__, __VA_ARGS__);