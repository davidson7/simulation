#include "Window.h"
#include <iostream>
using namespace std;

Window::Window(){
  m_idleTime=0;
  m_isOpen=true;
}

Window::Window(int idleTime, bool isOpen){
  m_idleTime = idleTime;
  m_isOpen= isOpen;
}

bool Window::getWindowOpen()
{
  return m_isOpen;

}

void Window::setWindowOpen(bool t){
  m_isOpen = t;
}

int Window::getIdle(){
  return m_idleTime;

}

void Window::setIdle(int i){
  m_idleTime=i;
}
