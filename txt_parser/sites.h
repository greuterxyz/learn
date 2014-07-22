#ifndef SITES_H
#define SITES_H
#include <iostream>
#include <vector>
//#include <QtWidgets>

struct site
{
    std::string name;
    std::string nonEngName;
    std::string type;
    std::string owner;
    std::string civ;
    std::string race;
    std::string population[4]; //1 slot for each race: 0 Dwarf, 1 human, 2 elf, 3 goblin
    int x;
    int y;
};

struct tile
{
    std::string x;
};

class sites
{
private:
    int num_sites;
    struct tile** _tile;
    int vert_tiles;
    int horz_tiles;
public:
    sites();
    struct site* _site;
    void load_sites(site _site_parse[]); //Load site data structure from parser
    void load_num_sites(int input); //Load number of sites from parser
    void print_sites(); //Prints out the parsed XML data
    void load_world_dimensions(); //Loads in world dimensions and assigns 2D array
    void load_map(); //Loads the DF world map with site data
    void print_map(); //Prints an ASCII world map
    //void print_map_qt(QTextBrowser *textbrowser);
};

#endif
