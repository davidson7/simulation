#include "ListNode.h"
#include<iostream>
#include <cstdlib>
using namespace std;


template <class T>
class GenDLinkedList
{
public:
  ListNode<T> *m_head;
  ListNode<T> *m_tail;
  int m_size;

  // constructor
  GenDLinkedList();
  //destructor
  ~GenDLinkedList();

  // member functions
  void insertFront(T val);
  void insertBack(T val);
  T removeFront();
  //T removeBack();
  int deletePosition(T position);
  int find (T val);
  bool isEmpty();
  void printList();
  unsigned int getSize();

};

//////////////////////**********Implementions**********/////////////////////////
// constructor
template <class T>
GenDLinkedList<T>::GenDLinkedList()
{
  m_size = 0;
  m_head = NULL;
  m_tail = NULL;
}

///////////////////////////////////////////////////////////////////////////////
// destructor
template <class T>
GenDLinkedList<T>::~GenDLinkedList()
{
  ListNode<T> *current = m_head;
  ListNode<T> *next = NULL;

  while(current != NULL)
  {
    next = current -> m_next;
    delete current;
    current = next;
  }
}

///////////////////////////////////////////////////////////////////////////////
//getSize function
// int GenDLinkedList<T>::getSize(): return the size of the list
template <class T>
unsigned int GenDLinkedList<T>::getSize()
{
  return m_size;
}

///////////////////////////////////////////////////////////////////////////////
//isEmpty fucntion
// bool GenDLinkedList<T>::isEmpty(): returns if the list is empty; otherwise
//                                    false
template <class T>
bool GenDLinkedList<T>::isEmpty()
{
  if(m_size == 0)
  {
    return true;
  }

  return false;
}

///////////////////////////////////////////////////////////////////////////////
// printList() function
// void GenDLinkedList<T>::printList: print the entire list
template <class T>
void GenDLinkedList<T>::printList()
{
  ListNode<T> *tempNode = m_head;

  while(tempNode != NULL)
  {
    cout << tempNode -> m_value  << " ";
    tempNode = tempNode -> next;
  }
}

///////////////////////////////////////////////////////////////////////////////
// insertFront function
// void GenDLinkedList<T>::insertFront: puts the value at the beginning of the
//                                      list
template <class T>
void GenDLinkedList<T>::insertFront(T val)
{
  // creating a new node with the new val
  ListNode<T> *newNode = new ListNode<T>(val);

  if(isEmpty())
  {
    m_tail = newNode;
  }
  else
  {
    newNode -> m_next = m_head;
    m_head-> m_prev = newNode;
  }

  // updating the head of the list
  m_head = newNode;
  m_size++;
}

///////////////////////////////////////////////////////////////////////////////
// insertBack
// void GenDLinkedList<T>::insertBack: puts the value at the end of the list
template <class T>
void GenDLinkedList<T>::insertBack(T val)
{
  ListNode<T> *newNode = new ListNode<T>(val);

  if(isEmpty())
  {
    m_head = newNode;
    return;
  }
  else
  {
    m_tail -> m_next = newNode;
    newNode -> m_prev = m_tail;
  }

  m_tail = newNode;
  m_size++;
}

///////////////////////////////////////////////////////////////////////////////
// removeFront
// int GenDLinkedList<T>::removeFront: removes the value at the beginning of
//                                     the list

template <class T>
T GenDLinkedList<T>::removeFront()
{
  ListNode<T> *tempNode = m_head;
  T tempVal= NULL;

  if(isEmpty()){
    cout<<"List is empty"<<endl;
    return;
  }

    // checks if only one element exists
  if(m_head -> m_next == NULL)
  {
    m_tail = NULL;
    //throw exception or return false
  }
  else // one or more elements
  {
    m_head -> m_next -> m_prev = NULL;
  }

  m_head = m_head -> m_next;
  tempVal = tempNode -> m_value;
  tempNode -> m_next = NULL;
  delete tempNode;

  m_size--;
  return tempVal;
}

///////////////////////////////////////////////////////////////////////////////
// removeBack function
// int GenDLinkedList<T>::removeBack(): removes the value at the end of the list
/*template <class T>
T GenDLinkedList<T>::removeBack()
{
  ListNode<T> *tempNode = m_head;
  int tempVal = 0;

  if(isEmpty())
  {
    // throw an exception
    cout << "Cannot remove from the empty list" << endl;
    return;
  }
  // checks if only one element exists
  if(m_head -> m_next == NULL)
  {
    m_tail = NULL;
    //throw exception or return false
  }
  else // one or more elements
  {
    m_tail -> m_next -> m_prev = NULL;
  }

  m_tail = m_tail -> m_next;
  tempVal = tempNode -> m_value;
  tempNode -> m_next = NULL;
  delete tempNode;

  m_size--;
  return tempVal;
}
*/

///////////////////////////////////////////////////////////////////////////////
// deletePosition funtion
// int GenDLinkedList<T>::deletePosition(T position): removes a position from
//                                                    the list
template <class T>
int GenDLinkedList<T>::deletePosition(T position)
{
  int index = 0;
  ListNode<T> *current = m_head;
  ListNode<T> *previous = m_head;
  int tempVal = 0;

  while(index != position)
  {
    previous = current;
    current = current -> m_next;
    ++index;
  }
  // index == position
  // when the position is found, update the pointers
  previous -> m_next = current -> m_next;
  current -> m_next = NULL;
  tempVal = current -> m_value;

  delete current;
  m_size--;

  return tempVal;

}

///////////////////////////////////////////////////////////////////////////////
// find function
// int GenDLinkedList<T>::find(T val): returns the position of the value exist
//                                     in the list
template <class T>
int GenDLinkedList<T>::find(T val)
{
  int index = -1;
  ListNode<T> *tempNode = m_head;

  while(tempNode != NULL)
  {
    ++index;
    // if the value if found
    if(tempNode -> value == val)
    {
      break;
    }
    else // if the value is not found
    {
      tempNode = tempNode -> next;
    }

    // if the value is at the end of the list
    if(tempNode == NULL)
    {
      index = -1;
    }

    return index;
  }
}
