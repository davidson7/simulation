#include "Student.h"
#include<iostream>
#include <vector>
using namespace std;

// calculations
// mean student wait time
// median student wait time
// longest student wait time
// # of students waiting for 10 mins

// constructor
Student::Student()
{
  m_arrivalTime = 0;
  //m_openQueueTime = 0;
  m_waitTime = 0;
  m_timeNeed = 0;
}
// overloaded constructor
Student::Student(int arrivalTime, int waitTime, int timeNeed)
{
  m_arrivalTime = arrivalTime;
  //m_openQueueTime = openQueueTime;
  m_waitTime = waitTime;
  m_timeNeed = timeNeed;

}
//Student::~Student(){}



/*void Student::pushToRecords(GenDLinkedList<Student> *list, vector<Student> arr)
{
  Student *s = list->remove();
  arr.push_back(s->m_waitTime);
}
*/
