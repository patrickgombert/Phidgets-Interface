#include <iostream>
#include "phidgetcall.h"

using namespace std;

void printResult(int value, string arg) {
  if(value == -1) {
    cout << "No attached phidget named: " + arg << endl;
  } else {
    cout << value << endl;
  }
}

void printUsage() {
  cout << "Usage:\n  readphidget <alias>\n" << endl;
  cout << "Define Phidget aliases in mapping.txt" << endl;
  cout << "Use the following convention:" << endl;
  cout << "  key:value" << endl;
  cout << "Where key is the phidget's alias (defined by you)" << endl;
  cout << "And value is the port that phidget is using on the interface kit" << endl;
}

int main(int args, char *argv[]) {
  Call *c = new Call();
  if(args == 2) {
    int value = c->getValue(argv[1]);
    printResult(value, argv[1]);
  } else {
    printUsage();
  }
  delete c;
  return 0;
}
