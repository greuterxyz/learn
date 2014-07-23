#include "txt_parse.h"
#include <regex>
#include <stdio.h>

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
        char num[100];
        char string2[100];
        char string3[100];
        std::cout << line << std::endl;
        //std::regex regex("([A-Za-z]+)");
        //std::cout << std::regex_match(line, regex) << std::endl;
        sscanf(line.c_str(), "%s, &s, &s", &num, &string2, &string3);
        cout << num << " " << string2 << " " << string3 << endl;
    }
}
