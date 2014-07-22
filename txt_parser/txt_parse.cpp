#include "txt_parse.h"

using namespace std;

txt_parse::txt_parse()
{
}

void txt_parse::read_file(std::string fileName)
{
    std::ifstream file(fileName.c_str());
    while (std::getline(file, line))
        parse_line(line);
}

void txt_parse::parse_line(std::string line)
{
    std::cout << line << endl;
}
