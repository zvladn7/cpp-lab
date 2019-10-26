#include "phonenote.hpp"
#include <iostream>

int main()
{
  std::cout << "1\n";
  PhoneBook b;
  std::cout << "2\n";
  PhoneBook::listIter iter = b.begin();
  std::cout << "3\n";
  for (int i = 1; i <= 5; ++i) {
    std::cout << "4\n";
    PhoneBook::note note{"name", i};
    std::cout << note.name << " " << note.phone << "\n";
    std::cout << "5\n";
    iter = b.insert(iter, note);
    std::cout << "6\n";
  }
  std::cout << "7\n";
  PhoneBook::listIter it = b.begin();
  std::cout << "8\n";
  it = b.move(it, -2);
  b.show(it, std::cout);
  return 0;
}
