#include "tasks.hpp"
#include <vector>
#include "functions.hpp"

void addAfter(std::vector<int> &vector) {
  if (vector.back() == 1) {
    for (auto it = vector.begin(); it != vector.end();) {
      if ((*it % 2) == 0) {
        it = vector.erase(it);
        continue;
      }
      ++it;
    }
  } else if (vector.back() == 2) {
    for (auto it = vector.begin(); it != vector.end();) {
      if ((*it % 3) == 0) {
        it = vector.insert(++it, 3, 1);
        std::advance(it, 3);
        continue;
      }
      ++it;
    }
  }
}

void thirdTask() {
  std::vector<int> vector;
  int nextNumber = -1;
  while (std::cin && !(std::cin >> nextNumber).eof()) {
    if (std::cin.fail()) {
      throw std::ios_base::failure("The error has occurred while the number was written!\n");
    }
    if (nextNumber == 0) {
      break;
    }
    vector.push_back(nextNumber);
  }

  if (vector.empty()) {
    return;
  }

  if (std::cin.eof() && nextNumber != 0) {
    throw std::invalid_argument("Zero was expected at the end!\n");
  }

  addAfter(vector);

  print(vector);
}
