#include <iostream>
#include <fstream>
#include <vector>
#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;

int main(int argc, char *argv[])
{
    string input_xml;
    string line;

    ifstream in("C:\\Users\\Vladimir\\Documents\\GitHub\\xml-parser\\samplexml.txt");
    //Read file into string variable
    while(getline(in, line))
    {
        input_xml += line;
    }
    //cout << input_xml << endl;

    //Create safely modifiable copy of input_xml
    vector<char> xml_copy(input_xml.begin(), input_xml.end());
    xml_copy.push_back('\0');

    xml_document<> doc;
    doc.parse<0>(&xml_copy[0]);

    xml_node<> *pRoot = doc.first_node();
    cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
    cout << pRoot->first_node()->first_node()->name() << endl;

    for (xml_attribute<> *attr = pRoot->first_attribute(); attr; attr = attr->next_attribute())
    {
        cout << "O hai" << endl;
        cout << "Node with foobar has attribute " << attr->name() << " ";
        cout << "with value " << attr->value() << endl;
    }

/*
    for(xml_node<> *pNode=pRoot->first_node("book"); pNode; pNode=pNode->next_sibling())
    {
        xml_node<> *pNode = pRoot->first_node("book");

    }
*/
}
