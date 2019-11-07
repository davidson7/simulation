#include<iostream>
using namespace std;

template <class T>
class ListNode
{
public:
  T m_value;
  ListNode<T> *m_prev;
  ListNode<T> *m_next;

  // member functions
  // constuctor
  ListNode<T>();
  // overloaded constuctor
  ListNode<T>(T val);
  // destructor
  ~ListNode<T>();
};

//////////////////////**********Implementions**********/////////////////////////

template <class T>
ListNode<T>::ListNode()
{
  m_value = NULL;
  m_prev = NULL;
  m_next = NULL;
}

template <class T>
ListNode<T>::ListNode(T val)
{
  m_value = val;
  m_prev = NULL;
  m_next = NULL;
}


template <class T>
ListNode<T>::~ListNode()
{
  m_prev = NULL;
  m_next = NULL;
}
