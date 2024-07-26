#include <iostream>
#include "../core/array/array.h"
#include <unistd.h>
int main()
{
    {
        Array<int> array(10);
        array.change_element(5, 0);
    }
    sleep(5);
}