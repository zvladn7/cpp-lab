#include "tasks.hpp"
#include <functional>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "queue-with-priority.hpp"
#include "functions.hpp"

void task1() {
  const static struct {
    const std::string name;
    std::function<void(QueueWithPriority<std::string> &queue, std::stringstream &args)> fun;
  } commands[] = {
    {"add", &add},
    {"get", &get},
    {"accelerate", &accelerate}
  };
  QueueWithPriority<std::string> queue;
  std::string line;
  while (std::getline(std::cin, line)) {
    if (std::cin.fail())
    {
      throw std::ios_base::failure("Error has occured while the command was written!\n");
    }
    std::stringstream stream(line);
    std::string command;
    stream >> command;
    auto iter = std::find_if(std::begin(commands), std::end(commands), [&](const auto &pr) {return pr.name == command;});

    std::string paramets;
    if (iter != std::end(commands)) {
      iter->fun(queue, stream);
    } else {
      std::cout << "<INVALID COMMAND>\n";
    }
  }
}
