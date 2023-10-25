#include <iostream>

__attribute__((constructor)) void dylib_main() {
    std::cout << "Hello from blehware-module!\n";
    std::cout << "This is a dynamic library that is loaded into the main executable.\n";
}