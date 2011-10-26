#include <iostream>
#include "phidgetcall.h"

using namespace std;

int main(int args, char *argv[]) {
  Call *c = new Call();
  if(args == 2) {
    cout << c->getValue(argv[1]) << endl;
  } else {
    cout << "Usage:\n  readphidget <alias>\n" << endl;
    cout << "Define Phidget aliases in mapping.txt" << endl;
    cout << "Use the following convention:" << endl;
    cout << "  key:value" << endl;
    cout << "Where key is the phidget's alias (defined by you)" << endl;
    cout << "And value is the port that phidget is using on the interface kit" << endl;
  }
  delete c;
  return 0;
}
