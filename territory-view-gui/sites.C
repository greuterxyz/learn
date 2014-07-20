#include <iostream>
#include "sites.h"
#include "xml_parse.h"

using namespace std;

sites::sites()
{
    vert_tiles = 65;
    horz_tiles = 65;
}

void sites::load_sites(site _site_parse[])
{
    _site = _site_parse;
}

void sites::print_sites()
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

void sites::load_num_sites(int input)
{
    num_sites = input;
}

void sites::load_world_dimensions()
{
    _tile = new tile*[vert_tiles];
    for(int i=0;i<vert_tiles;i++)
        _tile[i] = new tile[horz_tiles];

    for(int i=0;i<vert_tiles;i++)
        for(int j=0;j<horz_tiles;j++) _tile[j][i].x = '-';
}

void sites::load_map()
{
    load_world_dimensions();
    //Place sites with first letter of name (for debug, needs to change)
    for(int i=1;i<num_sites;i++)
    {
        _tile[_site[i].x][_site[i].y].x = _site[i].name.c_str()[0];
    }
}

void sites::print_map()
{
    for(int i=0;i<vert_tiles;i++)
        for(int j=0;j<horz_tiles;j++)
        {
            if(j==horz_tiles-1)
            {
                cout << _tile[j][i].x << endl;
            }
            else cout << _tile[j][i].x;
        };
}
