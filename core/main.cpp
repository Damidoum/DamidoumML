#include <unistd.h>

#include <iostream>

#include "../core/array/array.h"
int main() {
  {
    Array<int> array(10);
    array.change_element(5, 0);
  }
  sleep(5);
}
