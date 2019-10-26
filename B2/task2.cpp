#include <list>
#include <iostream>
#include "functions.hpp"

void task2()
{
  std::list<int> list;
  int nextNumber = -1;
  const int maxLength = 20;
  const int max = 20;
  const int min = 1;

  while (std::cin && !(std::cin >> nextNumber).eof())
  {
    if (std::cin.fail())
    {
      throw std::ios_base::failure("Error has occured while the command was written!\n");
    }
    if (list.size() == maxLength)
    {
      throw std::logic_error("The list's already full!\n");
    }
    if (nextNumber > max || nextNumber < min)
    {
      throw std::invalid_argument("You've just sent the number which isn't included in range from 1 to 20!\n");
    }
    list.push_back(nextNumber);
  }

  printNumbers(list);
}
