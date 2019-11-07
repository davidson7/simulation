#include <iostream>
using namespace std;

class Student
{
public:
  int m_arrivalTime;
  //int m_openQueueTime;
  int m_waitTime;
  // when the window is full, we will then use the processTime
  // to see the how much time the student has left at the window
  int m_timeNeed;

  // member functions
  Student();
  Student(int arrivalTime, int waitTime, int timeNeed);

  //void pushToRecords(GenDLinkedList<Student> list);


};
