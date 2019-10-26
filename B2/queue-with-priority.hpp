#ifndef B2_QUEUE_WITH_PRIORITY
#define B2_QUEUE_WITH_PRIORITY

#include <list>

typedef enum
{
  LOW,
  NORMAL,
  HIGH
} ElementPriority;

template <typename QueueElement>
class QueueWithPriority
{
public:
  template <typename Handler>
  void apply(Handler handler);
  void push(const QueueElement &element, ElementPriority priority);
  void pop();
  void accelerate();
  bool empty();
private:
  std::list<QueueElement> high_;
  std::list<QueueElement> normal_;
  std::list<QueueElement> low_;
};

template <typename QueueELement>
template <typename Handler>
void QueueWithPriority<QueueELement>::apply(Handler handler) {
  if (!high_.empty()) {
    handler(high_.front());
    high_.pop_front();
  } else if (!normal_.empty()) {
    handler(normal_.front());
    normal_.pop_front();
  } else if (!low_.empty()){
    handler(low_.front());
    low_.pop_front();
  }
}

template <typename QueueELement>
void QueueWithPriority<QueueELement>::push(const QueueELement &element, ElementPriority priority)
{
  switch (priority)
  {
  case ElementPriority::HIGH:
    high_.push_back(element);
    break;
  case ElementPriority::NORMAL:
    normal_.push_back(element);
    break;
   case ElementPriority::LOW:
    low_.push_back(element);
    break;
  }
}

template <typename QueueELement>
void QueueWithPriority<QueueELement>::pop()
{
  if (!high_.empty())
  {
    high_.pop_front();
  } else if (!normal_.empty()) {
    normal_.pop_front();
  } else if (!low_.empty()) {
    low_.pop_front();

  }
}

template <typename QueueELement>
void QueueWithPriority<QueueELement>::accelerate()
{
  high_.splice(high_.end(), low_);
}

template <typename QueueELement>
bool QueueWithPriority<QueueELement>::empty()
{
  return low_.empty() && normal_.empty() && high_.empty();
}

#endif
