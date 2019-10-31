#include <iostream>
#include "phonebook.hpp"

int main()
{
  std::string number;
  std::string name;
  std::cin >> number >> name;
  name = name.substr(1, name.length() - 2);
  int size = name.length();
  for (int i = 0; i < size; ++i) {
    if (name[i] == '\\')
    {
      name = name.erase(i, 1);
    }
  }
  std::cout << name << "\n";
  return 0;
}
