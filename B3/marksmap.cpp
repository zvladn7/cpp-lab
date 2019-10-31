#include "marksmap.hpp"

MarksMap::MarksMap()
{
  marksMap_["current"] = phonebook_.begin();
}

void MarksMap::add(const PhoneBook::note_t &note)
{
  phonebook_.insert(phonebook_.end(), note);

  if (phonebook_.begin() == std::prev(phonebook_.end()))
  {
    marksMap_["current"] = phonebook_.begin();
  }
}

void MarksMap::store(const std::string &mark, const std::string &newMark)
{
  mapIter it = getIter(mark);
  marksMap_.emplace(newMark, it->second);
}

void MarksMap::insert(bool after, const std::string &mark, const PhoneBook::note_t &note)
{
  PhoneBook::iterator it = getIter(mark)->second;
  if (after)
  {
    ++it;
  }
  phonebook_.insert(it, note);
}

void MarksMap::remove(const std::string &mark)
{
  PhoneBook::iterator it = getIter(mark)->second;
  if (phonebook_.end() != it)
  {
    throw std::logic_error("You've just tried to delete element which aren't at the list");
  }
  it = phonebook_.remove(it);
  marksMap_[mark] = it;
}

void MarksMap::show(std::ostream &out, const std::string &mark)
{
  PhoneBook::iterator it = getIter(mark)->second;
  if (phonebook_.end() != it)
  {
    throw std::logic_error("You've just tried to delete element which aren't at the list");
  }
  phonebook_.show(it, out);
}

void MarksMap::move(const std::string &mark, int steps)
{
  PhoneBook::iterator it = getIter(mark)->second;
  phonebook_.move(it, steps);
}

void MarksMap::move(const std::string &mark, const std::string &position)
{
  mapIter it = getIter(mark);
  it->second = position == "first" ? phonebook_.begin() : phonebook_.end();
}

std::map<std::string, PhoneBook::iterator>::iterator MarksMap::getIter(const std::string &mark)
{
  mapIter it = marksMap_.find(mark);
  if (marksMap_.end() == it)
  {
    throw std::invalid_argument("The mark sent to the program doesn't exist!\n");
  }
  return it;
}
