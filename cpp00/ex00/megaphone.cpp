
#include <iostream>
#include <vector>

bool is_alpha_small(char c) { return (c >= 'a' && c <= 'z'); }

void print_in_large(int argc, char **argv) {
  for (int i = 0; i < argc; i++) {
    for (int j = 0; argv[i][j] != '\0'; j++) {
      if (is_alpha_small(argv[i][j])) {
        std::cout << static_cast<char>(argv[i][j] - 32);
      } else {
        std::cout << argv[i][j];
      }
    }
  }
  std::cout << std::endl;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 1;
  }
  print_in_large(argc - 1, argv + 1);
  return 0;
}
