#include "../core/array/array.h"
#include <iostream>
#include <unistd.h>
int main() {
  {
    Array<int> array(10);
    array.change_element(5, 0);
  }
  sleep(5);
}
