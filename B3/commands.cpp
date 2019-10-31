#include "commands.hpp"
#include <sstream>
#include <algorithm>
#include <functional>
#include "functions.hpp"

void add(MarksMap &map, std::stringstream &stream)
{
  std::string number;
  std::string name;
  stream >> number >> name;
  checkNumber(number);
  if (name[0] != '\"' && name[name.length() - 1] == '\"' || name.empty()) {
    throw std::invalid_argument("You've just sent to console without quotes!\n");
  }
  name = adaptName(name);
  PhoneBook::note_t note = {name, number};
  map.add(note);
}

void store(MarksMap &map, std::stringstream &stream)
{
  std::string markName;
  std::string newMarkName;
  stream >> markName >> newMarkName;
  checkMarkName(markName);
  checkMarkName(newMarkName);

  map.store(markName, newMarkName);
}

void insert(MarksMap &map, std::stringstream &stream)
{
  std::string insertPosition;
  std::string markName;
  std::string number;
  std::string name;
  stream >> insertPosition >> markName >> number >> name;
  bool isBefore = isBefore(insertPosition);
  checkMarkName(markName);
  checkNumber(number);
  name = adaptName(name);
  PhoneBook::note_t note = {name, number};
  map.insert(isBefore, markName, note);
}

void remove(MarksMap &map, std::stringstream &stream)
{
  std::string markName;
  stream >> markName;
  checkMarkName(markName);

  map.remove(markName);
}

void show(MarksMap &map, std::stringstream &stream)
{
  std::string markName;
  stream >> markName;
  checkMarkName(markName);

  map.show(markName);
}

void move(MarksMap &map, std::stringstream &stream)
{
  std::string markName;
  std::string steps;
  stream >> markName >> steps;
  checkMarkName(markName);

  if (steps == "first" || steps == "last")
  {
    map.move(mark, steps);
  }
  else
  {
  checkNumber(steps);

  map.move(markName, std::atoi(steps));
  }
}
