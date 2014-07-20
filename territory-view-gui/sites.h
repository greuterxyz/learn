#ifndef SITES_H
#define SITES_H
#include <iostream>
#include <vector>

struct site
{
    std::string name;
    std::string type;
    int x;
    int y;
};

struct tile
{
    char x;
};

class sites
{
private:
    int num_sites;
    struct site* _site;
    struct tile** _tile;
    int vert_tiles;
    int horz_tiles;
public:
    sites();
    void load_sites(site _site_parse[]); //Load site data structure from parser
    void load_num_sites(int input); //Load number of sites from parser
    void print_sites(); //Prints out the parsed XML data
    void load_world_dimensions(); //Loads in world dimensions and assigns 2D array
    void load_map(); //Loads the DF world map with site data
    void print_map(); //Prints an ASCII world map
};

#endif
