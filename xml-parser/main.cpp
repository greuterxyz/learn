#include <iostream>
#include <fstream>
#include <vector>
#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;

//int main(int argc, char *argv[])
int main(void)
{
    string input_xml;
    string line;

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
    cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
    cout << pRoot->first_node("sites")->first_node()->value() << endl;
    pRoot = pRoot->first_node("sites");
    cout << pRoot->first_node()->name() << endl;

    xml_node<> *siteNode = pRoot->first_node();
    cout << siteNode->name() << endl;

    for(siteNode = pRoot->first_node(); siteNode; siteNode = siteNode->next_sibling())
    {
        cout << siteNode->first_node("name")->value() << endl;
        cout << siteNode->first_node("coords")->value() << endl;
    }
}
