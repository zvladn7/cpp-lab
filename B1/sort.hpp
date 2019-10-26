#ifndef B1_SORT_HPP
#define B1_SORT_HPP
#include <iostream>
#include <functional>
#include "accessBehaviour.hpp"

template <template <class T> class TAccess, typename TCollection>
void sortSelection(TCollection &collection, bool reverse)
{
  typedef TAccess<TCollection> Policy;
  typedef typename TCollection::value_type value_type;

  std::function<bool(value_type, value_type)> compare = reverse
      ? std::function<bool(value_type, value_type)>(std::less<value_type>())
      : std::function<bool(value_type, value_type)>(std::greater<value_type>());

  for (auto i = Policy::begin(collection); i != Policy::end(collection); ++i)
  {

    auto curr = i;
    for (auto j = Policy::next(i); j != Policy::end(collection); ++j)
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

#endif //B1_SORT_HPP
