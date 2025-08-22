

#include "ScalarConverter.hpp"

void prepared_test() {
    // Test inputs for ScalarConverter
    const char *tests[] = {
        "",        // empty string
        " ",       // single space
        "foobar",  // non-numeric text
        "123..45", // multiple dots
        ".123",    // dot at start
        "123.",    // dot at end
        "007",     // leading zeros
        "40",
        "0",
        "2147483647",                                 // INT_MAX
        "2147483648",                                 // INT_MAX + 1
        "-2147483648",                                // INT_MIN
        "-2147483649",                                // INT_MIN - 1
        "-2147483649.1",                              // INT_MIN - 1 in double
        "999999999999999999999",                      // very large integer
        "340282346638528859811704183484516925440.0f", // overflow float
        "1e309",                                      // exponent notation (invalid)
        "nan",
        "nanf",
        "+inf",
        "-inf",
        "+inff",
        "-inff",
        "42.0",
        "126.0",
        "128.0",
        "42.0f",
        "42.0ff",
        "3.14",
        "3.14f",
        "0.0",
        "0.0f",
        "-0.0",
        "-0.0f",
        "424dafa", // invalid mix
        "323f",    // invalid float (no dot)
        "'a'",
        "'Z'",
        "'0'",
        "' '", // space char literal
        NULL   // sentinel
    };

    for (int i = 0; tests[i] != NULL; ++i) {
        std::string lit(tests[i]);
        std::cout << "=== Input: " << lit << " ===" << std::endl;
        ScalarConverter::convert(lit);
        std::cout << std::endl;
    }
}

int main(int argc, char **argv) {
    if (argc == 1)
        std::cerr << "too less arguments\n";
        // prepared_test();
    else if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else
        std::cerr << "too many arguments\n";
    return 0;
}
