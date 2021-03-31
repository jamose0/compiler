#include "readfile.h"

#include <fstream>
#include <cstdlib>
#include <iostream>

std::string readFile(std::string_view fname)
{
    std::ifstream inf{fname.data()};

    if (!inf) {
        std::cerr << "Couldn't open file\n";
        std::exit(1);
    }

    std::string s{};

    while (inf) {
        std::string line{};
        std::getline(inf, line);
        s += line + '\n';
    }

    return s;
}
