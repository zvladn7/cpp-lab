#ifndef MARKSMAP_HPP
#define MARKSMAP_HPP
#include <map>
#include "phonebook.hpp"

class MarksMap
{
public:
  MarksMap();
  void add(const PhoneBook::note_t &note);
  void store(const std::string &mark, const std::string &newMark);
  void insert(bool before, const std::string &mark, const PhoneBook::note_t &note);
  void remove(const std::string &mark);
  void show(std::ostream &out, const std::string &mark);
  void move(const std::string &mark, int steps);
  void move(const std::string &mark, const std::string &first);
  void next(const std::string &mark);
  void prev(const std::string &mark);
private:
  using marksmap = std::map<std::string, PhoneBook::iterator>;
  using mapIter = marksmap::iterator;
  mapIter getIter(const std::string &mark);
  marksmap marksMap_;
  PhoneBook phonebook_;
};

#endif // MARKSMAP_HPP
