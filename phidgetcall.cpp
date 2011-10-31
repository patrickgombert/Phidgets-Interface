#include <string>
#include "includes/phidgetcall.h"

using namespace std;

Call::Call() {
  initializeIFKit();
  aliases = new Alias();
}

Call::~Call() {
  delete aliases;
}

int Call::getValue(string alias) {
  int port = aliases->getPortNumber(alias);
  if(port >= 0) {
    int sensorVal;
    CPhidgetInterfaceKit_getSensorValue(ifKit, port, &sensorVal);
    return sensorVal;
  } else {
    return -1;
  }
}

void Call::initializeIFKit() {
  CPhidgetInterfaceKit_create(&ifKit);
  CPhidget_open((CPhidgetHandle)ifKit, -1);
  CPhidget_waitForAttachment((CPhidgetHandle)ifKit, 1000);
}

