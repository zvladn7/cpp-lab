#include "tasks.hpp"
#include <forward_list>
#include "functions.hpp"

void firstTask(const std::string &direction) {
  const bool reverse = isDescending(direction);

  std::vector<int> vectorAt;
  int nextNum = -1;
  while (std::cin && !(std::cin >> nextNum).eof())
  {
    if (std::cin.fail())
    {
      throw std::ios_base::failure("Error has occurred while the number was written!\n");
    }
    vectorAt.push_back(nextNum);
  }

  std::vector<int> vectorBrackets(vectorAt);
  std::forward_list<int> list(vectorBrackets.begin(), vectorBrackets.end());

  sortSelection<BracketsAccess>(vectorBrackets, reverse);
  sortSelection<AtAccess>(vectorAt, reverse);
  sortSelection<IteratorAccess>(list, reverse);

  print(vectorBrackets);
  print(vectorAt);
  print(list);
}
