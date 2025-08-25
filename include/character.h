
/* -----
The header guard was suggested by ChatGPT when prompted 
'What headers should be written at the top of a C++ when defining a class in a separate file from main.cpp?'
The header gaurd prevents errors due to multiple definitions.
Accessed May 15 2024
 -------- */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
using namespace std;

class Character {

public:

//Functions
  void setName(string newName);
  void setRole(string newRole);
  string getName();
  string getRole();

private:
  string name = "UNKNOWN";
  string role = "UNKNOWN";

};

#endif