#ifndef B1_PRINT_HPP
#define B1_PRINT_HPP

#include <iostream>

template <typename T, typename = typename T::iterator>
void print(const T &container)
{
  if (container.empty()) {
    return;
  }

  for (auto it = container.begin(); it != container.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}

#endif //B1_PRINT_HPP
