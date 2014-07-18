#include <iostream>
#include <fstream>
#include <vector>
#include "rapidxml.hpp"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace rapidxml;

struct site
{
    string name;
    string type;
    int x;
    int y;
};

//int main(int argc, char *argv[])
int main(void)
{
    string input_xml;
    string line;
    struct site* _site;
    int num_sites;

    ifstream in("/home/astraeus/prog/learn/xml-parser/region1-legends.xml");
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
    int id;

    //Find the number of sites
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
    cout << "Total number of sites " << id << endl;

    //Prints the structure as a debug
    for(int i=1;i<=id;i++)
    {
        cout << "Site ID: " << i << endl;
        cout << "Name: " << _site[i].name << endl;
        cout << "Type: " << _site[i].type << endl;
        cout << "Coordinates:" << endl;
        cout << "x: " << _site[i].x << endl;
        cout << "y: " << _site[i].y << endl << endl;
    }

    cout << "Number of sites: " << num_sites << endl;

}
