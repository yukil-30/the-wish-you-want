#include "character.h"
#include <iostream>

using namespace std;

void Character::setName(string newName) {
  name = newName;
}
void Character::setRole(string newRole) {
  role = newRole;
}
string Character::getName() {
  return name;
}
string Character::getRole() {
  return role;
}