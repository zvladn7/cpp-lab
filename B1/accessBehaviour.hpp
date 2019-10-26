#ifndef B1_ACCESS_BEHAVIOUR_HPP
#define B1_ACCESS_BEHAVIOUR_HPP

#include <iostream>
#include <vector>

template <typename Container>
struct BracketsAccess {
  typedef std::size_t index_type;

  static typename Container::reference get(Container &collection, index_type index) {
    return collection[index];
  }

  static index_type next(std::size_t index) {
    return index + 1;
  }

  static index_type begin(const Container &) {
    return 0;
  }

  static index_type end(const Container &container) {
    return container.size();
  }
};

template <typename Container>
struct AtAccess {
  typedef std::size_t index_type;

  static typename Container::reference get(Container &collection, index_type index) {
    return collection.at(index);
  }

  static index_type next(std::size_t index) {
    return index + 1;
  }

  static index_type begin(const Container &) {
    return 0;
  }

  static index_type end(const Container &container) {
    return container.size();
  }
};

template <typename Container>
struct IteratorAccess {
  typedef typename Container::iterator index_type;

  static typename Container::reference get(Container &, index_type it) {
    return *it;
  }

  static index_type next(index_type it) {
    return  ++it;
  }

  static index_type begin(Container &container) {
    return container.begin();
  }

  static index_type end(Container &container) {
    return container.end();
  }
};

#endif //B1_ACCESS_BEHAVIOUR_HPP
