#include <iostream>
#include "tasks.hpp"

enum tasks {
  FIRST = 1,
  SECOND,
  THIRD,
  FOURTH
};

int main(int argc, char *argv[])
{
  try
  {
    if ((argc < 2) || (argc > 4))
    {
      std::cerr << "Incorrect count of arguments which are sent from the console!";
      return 1;
    }

    char* checkedPtr = nullptr;
    const int switcher = std::strtoll(argv[1], &checkedPtr, 10);
    if (*checkedPtr != '\x00')
    {
      std::cerr << "The first argument is incorrect!\n";
      return 1;
    }

    switch (switcher)
    {
    case tasks::FIRST:
    {
      if (argc != 3)
      {
        std::cerr << "Incorrect count of arguments which is sent from the console!\n";
        return 1;
      }
      firstTask(argv[2]);
      break;
    }
    case tasks::SECOND:
    {
      if (argc != 3)
      {
        std::cerr << "Incorrect count of arguments which is sent from the console!\n";
        return 1;
      }
      secondTask(argv[2]);
      break;
    }
    case tasks::THIRD:
    {
      if (argc != 2)
      {
        std::cerr << "The third task: Wrong number of arguments!\n";
        return 1;
      }
      thirdTask();
      break;
    }
    case tasks::FOURTH:
    {
      if (argc != 4)
      {
        std::cerr << "The wrong number of arguments are sent from the console!\n";
        return 1;
      }
      srand(time(0));
      fourthTask(argv[2], std::stoi(argv[3]));
      break;
    }
    default: {
      std::cerr << "The wrong number of task!\n";
      return 1;
    }
    }
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << "\n";

    return 1;
  }

  return 0;
}
