#include <iostream>

using namespace std;

void procedure (int arg[], int length)
{
    for(int i=0;i<length;i++) cout << arg[i] << endl;
}

void fill_array(int* arr, int length)
{
    for(int i=0;i<length;i++) arr[i]=i;
}

int* fill_array_and_return(int arr[], int length)
{
    for(int i=0;i<length;i++)
    {
        arr[i] = i*5;
    }
    return arr;
}

int main()
{
    int myarray[] = {1,2,3,4,5};
    procedure(myarray, 5);

    int *my_other_array;

    my_other_array = fill_array_and_return(myarray, 5);

    procedure(my_other_array, 5);

    return 0;
}

