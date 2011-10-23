#include <iostream>
#include "phidgetcall.h"
using namespace std;

int main(int args, char *argv[]) {
  Call *c = new Call();
  if(args == 2) {
    cout << c->getValue(argv[1]) << endl;
  } else {
    cout << "Usage:\n  readphidget <alias>" << endl;
    cout << args << endl;
  }
  delete c;
  return 0;
}
