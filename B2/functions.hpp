#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <string>
#include <sstream>
#include <list>

template <typename QueueElement>
class QueueWithPriority;

void add(QueueWithPriority<std::string> &, std::stringstream &);
void get(QueueWithPriority<std::string> &, std::stringstream &);
void accelerate(QueueWithPriority<std::string> &, std::stringstream &);
void printNumbers(std::list<int> &list);
template <typename Char, typename CharTraits>
std::basic_istream<Char, CharTraits> & blank(std::basic_istream<Char, CharTraits> & is);


#endif // FUNCTIONS_HPP
