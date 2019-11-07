#include "GenDLinkedList.h"
#include "Student.h"
#include "Window.h"
#include <iostream>
#include <cstddef>
#include <vector>
#include <fstream>

using namespace std;

int main (int argc, char ** argv)
{
  GenDLinkedList<int> textFile;
  GenDLinkedList<Student> *studentList = new GenDLinkedList<Student>;
  //Student s1 = new Student();

  // Error handling for files
  //if not enough arguments
  if (argc != 2)
  { // line args error
    cout << "Error: Incorrect command line arguments" << endl;
    cout << "   expecting 2 arguments; received " << argc << endl;
    cout << "Suggestion: Check spacing" << endl;
    return 0;
  }
  else
  {
    //if file cannot open
    ifstream infile(argv[1]);
    if (!infile.is_open())
    {
      cout << "Error: Could not open file" << endl; // file opening error
    }
    else
    //file opened correctly
    {
    //read file into Queue of integers
      int n;
      while (infile >> n)
      {
        textFile.insertBack(n);
      }
      int numWindows = textFile.removeFront();

      //read student info into list of students until end of queue
      while(!textFile.isEmpty()){
        int arrivalTime = textFile.removeFront();
        int numStudentsAtTime = textFile.removeFront();
        for(int i =0;i< numStudentsAtTime; ++i){
          int timeAtWindow = textFile.removeFront();
          Student *s1 = new Student(arrivalTime, 0, timeAtWindow);
          studentList->insertBack(*s1);
          cout<<timeAtWindow;
        }
      }


      //start simulation
    int universalTime=0;

//create WindowArray and fill with window objects
    Window WindowArray[numWindows];

    for(int i=0; i<numWindows;++i){
      Window w1 = new Window(0,true);
      WindowArray[i]= w1;
    }
    Student StudentArray[numWindows];

    GenDLinkedList<Student> *waitQueue = new GenDLinkedList<Student>;

    //permanent metrics
    vector<int> studentWaitTimes;
    vector<int> WindowIdleTimes;

    while(!studentList.isEmpty())
    {
      //if student time at window is done, remove and set isOpen to true
      for(int i =0; i<numWindows; ++i){
        Student temp = StudentArray[i];

        if(temp.m_timeNeed == 0){
          StudentArray[i]=NULL;
          Window temp =WindowArray[i];
          temp.setWindowOpen(true);
        }
      }
      //move students that match "arrive time" to waitQueue
      //if they match universal time
      while(true){
        Student temp = StudentList.peek();
        if(temp.m_arrivalTime ==universalTime){
          waitQueue.insertBack(temp);
        }
        else
          break;
      }
      //if any windows are open, remove from waitqueue, add wait time to studentRecords, and add student to studentARray
      for(int i = 0; i<numWindows;++i){
        Window temp =WindowArray[i];
        if(temp.getWindowOpen()==true){
          Student s = waitQueue.removeFront();
          studentWaitTimes.push_back(s.m_waitTime);
          StudentArray[i]=s;
          WindowIdleTimes.push_back(temp.getIdle());

        }
        //deincrement student.timeNeed by one
        Student s1 = studentArray[i];
        s1.m_timeNeed--;

      }

      //wait time for students in wait queue ++

      while(waitQueue.m_head!=NULL)
      {
        Student s = new Student();
        s.m_waitTime++;
      }

      //window idle time ++
      for(int i =0; i<numWindows;++i){
        Window w= windowArray[i];
        w.m_idleTime++;
      }
      universalTime++;




    }//StudentLIst is empty







    }
  }


  return 0;
}
