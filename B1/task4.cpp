#include "functions.hpp"

void fourthTask(const std::string &direction, int size)
{
  const bool reverse = isDescending(direction);

  if (size <= 0) {
    throw std::runtime_error("You've just sent invalid size. It must be more than 0!\n");
  }

  std::vector<double> vector(size);
  fillRandom(vector.data(), size);
  print(vector);
  sortSelection<IteratorAccess>(vector, reverse);
  print(vector);
}
