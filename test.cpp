
#include "QS.h"
#include <string>
using namespace std;
int main() {
  QS thing;
  thing.createArray(10);\
  thing.addToArray(1);
  thing.addToArray(9);
  thing.addToArray(8);
  thing.addToArray(7);
  thing.addToArray(6);
  thing.addToArray(5);
  thing.addToArray(4);
  thing.addToArray(3);
  thing.addToArray(2);
  thing.addToArray(10);

  cout << thing.getArray() << endl;
  cout << thing.partition(0,4,2) << endl;
  //cout << thing.medianOfThree(0,8) << endl;
  //thing.sortAll();
  cout << thing.getArray() << endl;
  //
  // thing.createArray(10);
  // thing.addToArray(1);
  // thing.addToArray(2);
  // thing.addToArray(3);
  // thing.addToArray(4);
  // thing.addToArray(5);
  // thing.addToArray(6);
  // thing.addToArray(7);
  // thing.addToArray(8);
  // thing.addToArray(9);
  // thing.addToArray(10);
  // cout << endl;
  // cout << thing.getArray() << endl;
  // cout << thing.partition(0,3,2) << endl;
  // cout << thing.getArray() << endl;





}
