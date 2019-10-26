#include "functions.hpp"

bool isDescending(const std::string &direction)
{
  bool descending = true;

  if (direction == "ascending") {
    descending = false;
  }
  else if (direction != "descending") {
    throw std::invalid_argument("You've sent the invalid the second argument!\n");
  }
  return descending;
}

void fillRandom(double *array, int size)
{
  for (int i = 0; i < size; ++i)
  {
    array[i] = (rand() % 21 - 10) * 1.0 / 10;
  }
}
