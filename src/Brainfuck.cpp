#include "Brainfuck.hpp"
#include "../include/debugPrinter.hpp"
#include "Memory.hpp"
#include <string>

std::string Brainfuck::interpret(Code const &code, Input const &input) const {
    Memory memory;
    std::string result;
    auto j = input.begin();
    // BRAINFUCK INTERPRETER
    for (auto i = code.begin(); i < code.end(); i++) {
        switch (*i) {
        case '>':
            memory.moveRight();
            break;
        case '<':
            memory.moveLeft();
            break;
        case '+':
            memory.increment();
            break;
        case '-':
            memory.decrement();
            break;
        case '.':
            result += memory.get();
            break;
        case ',':
            memory.set(*j++);
            break;
        case '[':
            if (memory.get() == '\0') {
                int depth = 1;
                while (depth > 0) {
                    i++;
                    if (*i == '[') {
                        ++depth;
                    } else if (*i == ']') {
                        --depth;
                    }
                }
            }
            break;
        case ']':
            if (memory.get() != '\0') {
                int depth = 1;
                while (depth > 0) {
                    i--;
                    if (*i == '[') {
                        --depth;
                    } else if (*i == ']') {
                        ++depth;
                    }
                }
            }
            break;
        default:
            break;
        }
    }

    return result;
}