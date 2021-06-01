#pragma once
#include "Node.hpp"
#include "Config.hpp"

struct XYNode
{
  uint8_t x;
  uint8_t y;

  XYNode() : x(0), y(0) {}

  XYNode(uint8_t x, uint8_t y) : x(x), y(y) {}

  bool operator==(const XYNode &N)
  {
    return (N.x == x && N.y == y);
  }
};

template <class T>
class LinkedList
{
private:
  Node<T> *head_;
  Node<T> *tail_;

public:
  LinkedList() : head_(nullptr), tail_(nullptr) {}

  T getFront()
  {
    return head_->getElement();
  }

  T getLast()
  {
    return tail_->getElement();
  }

  Node<T> *getHead()
  {
    return head_;
  }

  void addFront(T element)
  {
    Node<T> *temp = new Node<T>(element, head_);
    head_ = temp;
    if (tail_ == nullptr)
      tail_ = temp;
  }

  void addLast(T element)
  {
    Node<T> *temp = new Node<T>(element, nullptr);
    if (tail_ == nullptr)
    {
      head_ = temp;
      tail_ = temp;
    }
    else
    {
      tail_->setNext(temp);
      tail_ = temp;
    }
    if (head_ == nullptr)
      tail_ = head_;
  }

  void removeLast()
  {
    Node<T> *temp = head_;

    if (temp != nullptr)
    {
      if(temp->getNext() == nullptr)
      {
        delete temp;
        head_ = nullptr;
        tail_ = nullptr;
      }
      else
      {
        while (temp->getNext()->getNext() != nullptr)
        {
          temp = temp->getNext();
        }
        delete tail_;
        temp->setNext(nullptr);
        tail_ = temp;
      }
    }
  }

  void removeAll()
  {
      Node<T> *temp = head_;
      while (temp != nullptr)
      {
        temp = temp->getNext();
        delete head_;
        head_ = temp;
      }
  }

  Node<T> *search(T el, Node<T> *begin = nullptr)
  {
    Node<T> *temp;
    if (begin == nullptr)
     temp = head_;
    else
      temp = begin;

    while (temp != nullptr)
    {
      if (temp->getElement() == el)
        break;

      temp = temp->getNext();
    }

    return temp;
  }

  static void print(Node<T> *head)
  {
    while (head != nullptr)
    {
      Serial.print("(");
      Serial.print(head->getElement().x);
      Serial.print(", ");
      Serial.print(head->getElement().y);
      Serial.print(") ");

      head = head->getNext();
    }
  }
};
