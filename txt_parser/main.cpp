#include <iostream>
#include "txt_parse.h"

using namespace std;

int main()
{
    txt_parse _txt_parse;
    std::string fileName = "/media/linux-data/Downloads/DF40.04/region2-world_sites_and_pops.txt";
    _txt_parse.read_file(fileName);
    return 0;
}

