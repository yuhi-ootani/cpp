
#include <fstream>
#include <iostream>
#include <string>

bool invalid_args(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <search> <replace>" << std::endl;
        return true;
    }

    std::string filename = argv[1];
    std::string find = argv[2];

    if (filename.empty() || find.empty()) {
        std::cerr << "Error: filename and search string must not be empty" << std::endl;
        return true;
    }

    return false;
}

// std::string::npos represents “no position” or “not found.” Specifically:
std::string replace_string(const std::string &line, const std::string &s1, const std::string &s2) {
    std::string result = line;
    size_t pos = 0;

    while ((pos = result.find(s1, pos)) != std::string::npos) {
        result.erase(pos, s1.size());
        result.insert(pos, s2);
        pos += s2.size();
    }

    return result;
}

int main(int argc, char **argv) {

    if (invalid_args(argc, argv))
        return 1;

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream in(filename.c_str());
    if (!in) {
        std::cerr << "Error: cannot open input file " << filename << '\n';
        return 1;
    }

    std::ofstream out((filename + ".replace").c_str());
    if (!out) {
        std::cerr << "Error: cannot open output file " << filename << '\n';
        return 1;
    }

    std::string line;
    bool first = true;

    while (std::getline(in, line)) {
        if (!first)
            out << '\n';
        first = false;
        std::string append = replace_string(line, s1, s2);

        out << append;
        if (out.fail()) {
            std::cerr << "failed to write into the file." << std::endl;
            return 1;
        }

        // distinguish EOF and fail to read
        if (in.bad()) {
            std::cerr << "Error: failed while reading " << filename << "\n";
            return 1;
        }
    }
    return 0;
}
