#include "phonenote.hpp"
#include <iostream>

PhoneBook::listIter PhoneBook::insert(const listIter position, const note &newNote)
{
  return listOfNotes_.insert(position, newNote);
}

PhoneBook::listIter PhoneBook::remove(const listIter position)
{
  return listOfNotes_.erase(position);
}

void PhoneBook::show(const listIter position, std::ostream &out) const
{
  out << position->name << " " << position->phone << "\n";
}

PhoneBook::listIter PhoneBook::move(listIter position, int steps)
{
  using diff_type = std::list<int>::difference_type;
  if (steps > 0)
  {
    diff_type diff = std::distance(position, listOfNotes_.end()) - 1;
    if (steps >= diff)
    {
      steps = diff;
    }
  } else {
    diff_type diff = std::distance(position, listOfNotes_.begin());
    if (steps <= diff)
    {
      steps = -diff;
    }
  }
  std::advance(position, steps);
  return position;
}

PhoneBook::listIter PhoneBook::begin()
{
  return listOfNotes_.begin();
}

PhoneBook::listIter PhoneBook::end()
{
  return listOfNotes_.end();
}

PhoneBook::listIter PhoneBook::next(listIter position)
{
  return (std::next(position) == listOfNotes_.end()) ? position : ++position;
}

PhoneBook::listIter PhoneBook::prev(listIter position)
{
  return (position == listOfNotes_.begin()) ? position : --position;
}

std::size_t PhoneBook::size() const
{
  return listOfNotes_.size();
}

bool PhoneBook::empty() const
{
  return listOfNotes_.empty();
}
