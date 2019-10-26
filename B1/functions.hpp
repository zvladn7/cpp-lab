#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <functional>
#include "accessBehaviour.hpp"

bool isDescending(const std::string &direction);

void fillRandom(double *array, int size);

template <typename T, typename = typename T::iterator>
void print(const T &container)
{
  if (container.empty()) {
    return;
  }

  for (auto it = container.begin(); it != container.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}

template <template <class T> class TAccess, typename TCollection>
void sortSelection(TCollection &collection, bool reverse)
{
  typedef TAccess<TCollection> Policy;
  typedef typename TCollection::value_type value_type;
  typedef typename TAccess<TCollection>::index_type index_type;

  std::function<bool(value_type, value_type)> compare = reverse
      ? std::function<bool(value_type, value_type)>(std::less<value_type>())
      : std::function<bool(value_type, value_type)>(std::greater<value_type>());

  for (index_type i = Policy::begin(collection); i != Policy::end(collection); ++i)
  {
    index_type curr = i;
    for (index_type j = Policy::next(i); j != Policy::end(collection); ++j)
    {
      if (compare(Policy::get(collection, curr), Policy::get(collection, j)))
      {
        curr = j;
      }
    }

    if (curr != i)
    {
      std::swap(Policy::get(collection, i), Policy::get(collection, curr));
    }
  }
}

#endif // FUNCTIONS_HPP
