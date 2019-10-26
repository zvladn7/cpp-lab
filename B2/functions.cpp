#include "functions.hpp"
#include <algorithm>
#include <iostream>
#include <functional>
#include "queue-with-priority.hpp"

void add(QueueWithPriority<std::string> &queue, std::stringstream &stream)
{
  const static struct {
    const std::string name;
    ElementPriority priority;
  } levels[] = {
  {"low", ElementPriority::LOW},
  {"normal", ElementPriority::NORMAL},
  {"high", ElementPriority::HIGH}
};

  std::string priority;
  stream >> priority;
  auto iter = std::find_if(std::begin(levels), std::end(levels), [&](const auto &pr) {return pr.name == priority;});

  if (iter == std::end(levels)) {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }
  stream >> std::ws;
  std::string addable;
  getline(stream, addable);
  if (addable.empty()) {
    std::cout << "<INVALID COMMAND>\n";
  }

  queue.push(addable, iter->priority);
}

void get(QueueWithPriority<std::string> &queue, std::stringstream &stream)
{
  if (!stream.eof()) {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }

  if (queue.empty()) {
    std::cout << "<EMPTY>\n";
    return;
  }

  queue.apply([](const auto &gettingEl) { std::cout << gettingEl << "\n"; });
}

void accelerate(QueueWithPriority<std::string> &queue, std::stringstream &stream)
{
  if (!stream.eof()) {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }

  queue.accelerate();
}

void printNumbers(std::list<int> &list)
{
  if (list.empty())
  {
    return;
  }
  std::list<int>::const_iterator lft = list.cbegin();
  std::list<int>::const_iterator rht = list.cend();
  while (lft != rht)
  {
    --rht;
    if (rht == lft) {
      break;
    }
    if (lft != list.cbegin()) {
      std::cout << " ";
    }
    std::cout << *lft << " " << *rht;
    ++lft;
  }
  if (list.size() % 2) {
    if (list.size() != 1) {
      std::cout << " ";
    }
    std::cout << *lft;
  }
  std::cout << "\n";
}

template <typename Char, typename CharTraits>
std::basic_istream<Char, CharTraits> & blank(std::basic_istream<Char, CharTraits> & is)
{
  while (std::isblank(static_cast<char>(is.peek()), std::locale("")))
  {
    is.ignore();
  }
  return is;
}

