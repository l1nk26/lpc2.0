#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>

#define MILLISECONDS_SLEEP_TIME 300
int ejecuciones_totales = 0;
#define LOOP_SECURITY(max_ejecuciones) \
    if (max_ejecuciones <= ejecuciones_totales) { \
            std::cout << "LIMITE DE SEGURIDAD SUPERADO\n"; \
            break; \
    }else ejecuciones_totales++;

template <typename T>
void debug_variables(const char* names, T value) {
    std::cout.write(names, strlen(names)) << ": " << value << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(MILLISECONDS_SLEEP_TIME));
}

template<typename T, typename... Args>
void debug_variables(const char* names, T value, Args... args) {
    const char* comma = strchr(names, ',');

    if (comma) {
        std::cout.write(names, comma - names) << ": " << value << " ";
        debug_variables(comma + 1, args...);
    } else {
        std::cout.write(names, strlen(names)) << ": " << value << std::endl;
        std::cout << std::endl;
    }
}

#define debug(...) debug_variables(#__VA_ARGS__, __VA_ARGS__);