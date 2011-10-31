#include <phidget21.h>
#include <string>
#include "phidgetmap.h"

class Call {
  public:
    Call();
    ~Call();
    int getValue(std::string);
  private:
    void initializeIFKit();
    Alias *aliases;
    CPhidgetInterfaceKitHandle ifKit;
};
