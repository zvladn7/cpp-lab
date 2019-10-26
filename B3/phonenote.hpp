#ifndef PHONENOTE_HPP
#define PHONENOTE_HPP
#include <string>
#include <list>

class PhoneBook
{
public:
  struct note {
    std::string name;
    int phone;
  };

  using listOfNotes = std::list<note>;
  using listIter = std::list<note>::iterator;

  listIter insert(const listIter position, const note &newNote);
  listIter remove(const listIter position);
  void show(const listIter position, std::ostream &out) const;
  listIter move(listIter position, int steps);

  listIter begin();
  listIter end();
  listIter next(listIter position);
  listIter prev(listIter position);

  std::size_t size() const;
  bool empty() const;
private:
  listOfNotes listOfNotes_;
};

#endif // PHONENOTE_HPP
