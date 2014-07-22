#include "txt_parse.h"
#include <regex>

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
    //std::cout << line << std::endl;
    if (line[0] == '\t')
        //std::cout << "First character is a tab." << std::endl;
        ;
    else
    {
        std::cout << line << std::endl;
        std::regex regex("([A-Za-z]+)");
        std::cout << std::regex_match(line, regex) << std::endl;
    }
}
