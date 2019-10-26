#include <iostream>
#include "tasks.hpp"

enum tasks {
  FIRST = 1,
  SECOND
};

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Incorrect count of arguments which are sent from the console!";
    return 1;
  }
  try {
    char* checkedPtr = nullptr;
    const int switcher = std::strtoll(argv[1], &checkedPtr, 10);
    if (*checkedPtr != '\x00')
    {
      std::cerr << "The first argument is incorrect!\n";
      return 1;
    }

    switch(switcher) {
    case FIRST:
    {
      task1();
      break;
    }
    case SECOND:
    {
      task2();
      break;
    }
    default: {
      std::cerr << "The wrong number of task!\n";
      return 1;
    }
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
  return 0;
}
