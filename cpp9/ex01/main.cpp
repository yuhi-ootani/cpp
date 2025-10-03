
#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: wrong command arguments\n";
        return 1;
    }

    try {
        RPN rpn(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what();
        return 1;
    }
    return 0;
}
