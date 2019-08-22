#include <iostream>
#include "Figures.h"

using namespace std;

int main(int argc, char const *argv[]) {
  float arr[2] = {0, 0};
  Rectangle<float> rectangle(3.0, 4.0, arr);

  cout << rectangle.calcularArea() << endl;
}
