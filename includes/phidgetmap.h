#include <map>
#include <string>

typedef std::map<std::string, int> PhidgetMap;

class Alias {
  public:
    Alias();
    ~Alias();
    int getPortNumber(std::string);
    void addEntry(std::string, int);
    void removeEntry(std::string);
  private:
    void readConfigFile();
    void setMappingFromString(std::string);
    PhidgetMap aliases;
};
