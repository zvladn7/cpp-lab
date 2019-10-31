#ifndef PHONENOTE_HPP
#define PHONENOTE_HPP
#include <string>
#include <list>

class PhoneBook
{
public:
  struct note_t {
    std::string name;
    std::string phone;
  };

  using listOfNotes = std::list<note_t>;
  using iterator = std::list<note_t>::iterator;

  iterator insert(const iterator position, const note_t &newNote);
  iterator remove(const iterator position);
  void show(const iterator position, std::ostream &out) const;
  iterator move(iterator position, int steps);

  iterator begin();
  iterator end();
  //????????
  iterator next(iterator position);
  iterator prev(iterator position);

  std::size_t size() const;
  bool empty() const;
private:
  listOfNotes listOfNotes_;
};

#endif // PHONENOTE_HPP
