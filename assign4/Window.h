#include <iostream>
using namespace std;
class Window
{
public:
    int m_idleTime;
    int getIdle();
    void setIdle(int i);
    //int m_openWindowTime;
    bool m_isOpen;
    bool getWindowOpen();
    void setWindowOpen(bool t);

    Window();
    Window(int idleTime, bool isOpen);


};
