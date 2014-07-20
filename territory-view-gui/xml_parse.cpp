#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "rapidxml.hpp"
#include "xml_parse.h"
#include "sites.h"

using namespace std;
using namespace rapidxml;

xml_parse::xml_parse()
{
    x = 0;
    id = 0;
    num_sites = 0;
    xml_loaded = false;
}

void xml_parse::process_xml(string filename)
{
    ifstream in(filename.c_str());

    //Read file into string variable
    while(getline(in, line))
    {
        input_xml += line;
    }

    //Create safely modifiable copy of input_xml
    vector<char> xml_copy(input_xml.begin(), input_xml.end());
    xml_copy.push_back('\0');

    xml_document<> doc;
    doc.parse<0>(&xml_copy[0]);

    xml_node<> *pRoot = doc.first_node();
    vector<string> strs;

    //Gets number of sites and assigns array dynamically
    num_sites = boost::lexical_cast<int>(pRoot->first_node("sites")->last_node()->first_node("id")->value()) + 1;
    _site = new site[num_sites];

    //Iterates through the sites in the XML file
    for(xml_node<> *siteNode = pRoot->first_node("sites")->first_node(); siteNode; siteNode = siteNode->next_sibling())
    {
        try {
            id = boost::lexical_cast<int>(siteNode->first_node("id")->value());
        } catch( boost::bad_lexical_cast const& ) {
            std::cout << "Error: input string was not valid" << std::endl;
        }
        _site[id].name = siteNode->first_node("name")->value();
        _site[id].type = siteNode->first_node("type")->value();
        string coords = siteNode->first_node("coords")->value();
        boost::split(strs, coords, boost::is_any_of(","));
        try {
            _site[id].x = boost::lexical_cast<int>(strs[0]);
        } catch( boost::bad_lexical_cast const& ) {
            std::cout << "Error: input string was not valid" << std::endl;
        }
        try {
            _site[id].y = boost::lexical_cast<int>(strs[1]);
        } catch( boost::bad_lexical_cast const& ) {
            std::cout << "Error: input string was not valid" << std::endl;
        }
    }
    if(id != 0)
    {
        xml_loaded = true;
    }
}

//Prints the parsed XML
void xml_parse::print_xml()
{
    for(int i=1;i<num_sites;i++)
    {
        cout << "Site ID: " << i << endl;
        cout << "Name: " << _site[i].name << endl;
        cout << "Type: " << _site[i].type << endl;
        cout << "Coordinates:" << endl;
        cout << "x: " << _site[i].x << endl;
        cout << "y: " << _site[i].y << endl << endl;
    }
}

site* xml_parse::return_site()
{
    return _site;
}

int xml_parse::get_num_sites()
{
    return num_sites;
}

bool xml_parse::get_xml_load_status()
{
    return xml_loaded;
}
