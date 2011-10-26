#include <cstdlib>
#include <fstream>
#include <iostream>
#include "phidgetmap.h"

using namespace std;

Alias::Alias() {
  readConfigFile();
}

Alias::~Alias() {

}

int Alias::getPortNumber(string alias) {
  PhidgetMap::iterator iter = aliases.find(alias);
  if(iter != aliases.end()) {
    return iter->second;
  } else {
    return -1;
  }
}

void Alias::addEntry(string alias, int port) {
  aliases.insert(pair<string, int>(alias, port));
}

void Alias::removeEntry(const string alias) {
  PhidgetMap::iterator iter = aliases.find(alias);
  aliases.erase(iter);
}

void Alias::readConfigFile() {
  string json;
  ifstream file ("mapping.txt");
  if (file.is_open()) {
    while (file.good()) {
      string temp;
      file >> temp;
      if(temp != "") {
        setMappingFromString(temp);
      }
    }
    file.close();
  }
}

void Alias::setMappingFromString(string mapping) {
  int colonPosition = mapping.find(':');
  string key = mapping.substr(0, (colonPosition));
  string value = mapping.substr(colonPosition + 1, mapping.length()-colonPosition);
  addEntry(key, atoi(value.c_str()));
}
