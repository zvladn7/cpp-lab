#include "functions.hpp"
#include <stdexcept>
#include <functional>


bool checkMarkName(std::string &markName)
{
  if (std::end(markName) != std::find_if(std::begin(markName), std::end(markName), [&](char c) { return !isalnum(c) && (c != '-'); }))
  {
    throw std::invalid_argument("You've just sent wrong sequence of chars of mark name!\n");
  }
}

bool isBefore(std::string insertPosition)
{
  if (insertPosition == "after")
  {
    return false;
  }
  else if (insertPosition == "before")
  {
    return true;
  }

  throw std::invalid_argument("You've sent the wrong position of insertion!\n");
}

void checkNumber(std::string &number)
{
  if (std::end(number) != std::find_if(std::begin(number), std::end(number), [&](char c) {return !isdigit(c); }) || number.empty())
  {
    throw std::invalid_argument("You've just sent the number which contains incoreccted symbols!|n");
  }
}

std::string &adaptName(std::string &name)
{
  name = name.substr(1, name.length() - 2);
  int size = name.length();
  for (int i = 0; i < size; ++i) {
    if (name[i] == '\\')
    {
      name = name.erase(i, 1);
    }
  }
  return name;
}
