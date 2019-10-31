#include "phonebook.hpp"
#include <iostream>

PhoneBook::iterator PhoneBook::insert(const iterator position, const note_t &newNote)
{
  return listOfNotes_.insert(position, newNote);
}

PhoneBook::iterator PhoneBook::remove(const iterator position)
{
  return listOfNotes_.erase(position);
}

void PhoneBook::show(const iterator position, std::ostream &out) const
{
  out << position->name << " " << position->phone << "\n";
}

PhoneBook::iterator PhoneBook::move(iterator position, int steps)
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

PhoneBook::iterator PhoneBook::begin()
{
  return listOfNotes_.begin();
}

PhoneBook::iterator PhoneBook::end()
{
  return listOfNotes_.end();
}

PhoneBook::iterator PhoneBook::next(iterator position)
{
  return (std::next(position) == listOfNotes_.end()) ? position : ++position;
}

PhoneBook::iterator PhoneBook::prev(iterator position)
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
