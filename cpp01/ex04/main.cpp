
#include <fstream>
#include <iostream>

int is_invalid(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <search> <replace>" << std::endl;
        return -1;
    }

    std::string find = argv[2];

    if (find.empty()) {
        std::cerr << "Error: serach string must not be empty" << std::endl;
        return -1;
    }
    return 0;
}

int main(int argc, char **argv) {

    if (is_invalid(argc, argv) == -1)
        return 1;

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream in(filename);
    std::ofstream out(filename + ".replace");

    if (!in || !out) {
        std::cerr << "Error opening files" << std::endl;
        return 1;
    }
    
    std::string line;
    while(std::getline(in, line)) {
        
        for(int i=0; s1.size() + i > line.size(); i++)
        {   
            if(line.compare(i, s1.size(), s1) == 0)
            {

            }
        }
    }

}