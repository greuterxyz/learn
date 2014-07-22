#ifndef TXT_PARSE_H
#define TXT_PARSE_H

#include <iostream>
#include <fstream>

class txt_parse
{
public:
    txt_parse();
    void read_file(std::string fileName);
    void parse_line(std::string line);

private:
    std::string line;
};


#endif // TXT_PARSE_H
