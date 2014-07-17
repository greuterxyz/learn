#include "dyna_class.h"
#include <cstddef> //For NULL

dyna_class::dyna_class(int max)
{
    index = new int[max];
}

dyna_class::~dyna_class()
{
    if (index != NULL) delete [] index;
}
