
#include "PmergeMe.hpp"

// long global_count = 0;

static int parse_positive_int_strict(const char *str) {
    if (!str || !*str)
        throw std::invalid_argument("empty argument");

    if (str[0] == '+' || str[0] == '-')
        throw std::invalid_argument(std::string("sign not allowed: '") + str + "'");

    if (str[0] == '0')
        throw std::invalid_argument(std::string("leading zero or zero value: '") + str + "'");

    errno = 0;
    char *end = 0;
    long vl = std::strtol(str, &end, 10); // 10 = decimal

    if (errno != 0)
        throw std::out_of_range(std::string("overflow while parsing '") + str + "'");

    if (end == str || *end != '\0')
        throw std::invalid_argument(std::string("invalid characters in '") + str + "'");

    if (vl < 1L)
        throw std::out_of_range(std::string("value < 1: '") + str + "'");

    if (vl > static_cast<long>(std::numeric_limits<int>::max()))
        throw std::out_of_range(std::string("value > INT_MAX: '") + str + "'");

    return static_cast<int>(vl);
}

static std::string to_string98(int v) {
    std::ostringstream os;
    os << v;
    return os.str();
}

static void args_into_vector(int argc, char **argv, std::vector<int> &dst) {
    dst.clear();
    dst.reserve(static_cast<size_t>(argc - 1));

    std::set<int> seen;

    for (int i = 1; i < argc; ++i) {
        const int val = parse_positive_int_strict(argv[i]);

        if (!seen.insert(val).second) {
            throw std::invalid_argument("duplicate value: " + to_string98(val));
        }
        dst.push_back(val);
    }

    if (dst.empty())
        throw std::invalid_argument("no numbers after parsing");
}

static inline double now_us() {
    timeval tv;           // time struct
    gettimeofday(&tv, 0); // time zone
    return static_cast<double>(tv.tv_sec * 1e6) + static_cast<double>(tv.tv_usec);
}

static void print_result(std::vector<int> &before, PmergeMe &Ford, double vec_us, double deq_us) {
    std::cout << "Before: ";
    print_container(before);

    // std::cout << "After: ";
    // print_container(Ford.getVec());

    std::cout << "After: ";
    print_container(Ford.getDeque());

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    std::cout << "Time to process a range of " << before.size()
              << " elements with std::vector : " << vec_us << " us\n";

    std::cout << "Time to process a range of " << before.size()
              << " elements with std::deque  : " << deq_us << " us\n";
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: The number of arguments must be more than 2\n";
        return 1;
    }

    try {
        std::vector<int> before;
        args_into_vector(argc, argv, before);
        PmergeMe Ford(before);

        double start = now_us();
        Ford.sortVec();
        double vec_us = now_us() - start;

        start = now_us();
        Ford.sortDeque();
        double deq_us = now_us() - start;

        print_result(before, Ford, vec_us, deq_us);

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
    }

    return 0;
}
