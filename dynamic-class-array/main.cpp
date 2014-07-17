#include <iostream>
#include "dyna_class.h"

using namespace std;

int main()
{
    dyna_class dyna(10);
    dyna.index[5] = 10;
    cout << dyna.index[5] << endl;

    return 0;
}

