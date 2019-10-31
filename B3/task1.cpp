#include "tasks.hpp"
#include <stdexcept>
#include <iostream>
#include "marksmap.hpp"

void task1()
{
  const static struct {
    const std::string name;
    std::function<void(MarksMap &map, std::stringstream &args)> fun;
  } commands[] = {
    {"add", &add},
    {"store", &store},
    {"insert", &insert},
    {"remove", &remove},
    {"show", &show},
    {"move", &move}
  };

  MarksMap marksMap;
  std::string line;
  while (std::getline(std::cin, line))
  {
     if (std::cin.fail())
     {
       throw std::ios_base::failure("Error has occured while the comman was written!\n");
     }

     std::stringstream stream(line);
     std::string command;
     stream >> command >> std::ws;
     auto iter = std::find_if(std::begin(commands), std::end(commands), [&](const auto &cmnd) {return cmnd.name = command;});

     if (iter != std::end(commands))
     {
       iter->fun(marksMap, stream);
     }
     else
     {
       std::cout << "<INVALID COMMAND>\n";
     }
  }
}
