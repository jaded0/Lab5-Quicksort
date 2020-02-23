
#include "QS.h"
#include <string>
using namespace std;
int main() {
  QS thing;
  thing.createArray(10);
  cout << thing.getArray() << endl;
  thing.clear();
  cout << thing.getArray() << endl;
  thing.createArray(10);
  cout << thing.getArray() << endl;
  cout << thing.getSize() << endl;

}
