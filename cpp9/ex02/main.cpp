
#include "PmergeMe.hpp"

static bool int_validation(const char *str, int &value) {
    if (!str || !*str)
        return false;

    if (str[0] == '+' || str[0] == '-' || str[0] == '0')
        return false;

    errno = 0;
    char *end = 0;
    long vl = std::strtol(str, &end, 10); // 10 = decimal

    if (errno != 0 || end == str || *end != '\0')
        return false;

    if (vl < 1 || vl > INT_MAX)
        return false;

    value = static_cast<int>(vl);
    return true;
}

static bool args_into_vector(int argc, char **argv, std::vector<int> &dst) {
    dst.clear();
    dst.reserve(static_cast<size_t>(argc - 1));

    std::set<int> set_dup;

    for (int i = 1; i < argc; ++i) {
        int value = 0;
        if (!int_validation(argv[i], value))
            return false;

        std::pair<std::set<int>::iterator, bool> is_dup = set_dup.insert(value);
        if (!is_dup.second)
            return false;

        dst.push_back(value);
    }

    if (dst.empty()) {
        return false;
    }
    return true;
}

int main(int argc, char **argv) {
    if (argc < 2 || argc > 3001) {
        std::cerr << "Error\n";
        return 1;
    }

    std::vector<int> before;
    if (!args_into_vector(argc, argv, before)) {
        std::cerr << "Error: invalid input\n";
        return 2;
    }

    PmergeMe Ford(before);
}

