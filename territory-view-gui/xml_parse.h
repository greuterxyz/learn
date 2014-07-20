#ifndef XML_PARSE_H
#define XML_PARSE_H
#include "sites.h"

class xml_parse
{
private:
    struct site* _site;
    std::string input_xml;
    std::string line;
    int x;
    int id;
    int num_sites;
    bool xml_loaded;

public:
    xml_parse();
    void process_xml(std::string filename);
    void print_xml();
    site* return_site();
    int get_num_sites();
    bool get_xml_load_status();
};

#endif // XML_PARSE_H
