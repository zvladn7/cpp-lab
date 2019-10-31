#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include <string>
#include <iostream>
#include "marksmap.hpp"

void add(MarksMap &map, std::stringstream &stream);
void store(MarksMap &map, std::stringstream &stream);
void insert(MarksMap &map, std::stringstream &stream);
void remove(MarksMap &map, std::stringstream &stream);
void show(MarksMap &map, std::stringstream &stream);
void move(MarksMap &map, std::stringstream &stream);

#endif // COMMANDS_HPP
