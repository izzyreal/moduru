#include <stdio.h>
#include "Logger.hpp"

int main() {
    moduru::Logger::l.setPath("moduru.log");
    moduru::Logger::l.log("Yay!");
    printf("Moduru test successful");
}
