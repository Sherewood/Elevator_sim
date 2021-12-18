#ifndef OBSERVER_H
#define OBSERVER_H
// values which set up the number of Elevators and floors in the simulator
#define ELEVATORS 10
#define FLOORS 10


#include "qstring.h"
#include <string>
#include "elevator.h"

#include <QVector>
#include <random>
/*Observer:
 * This file will function as the Observer of the implemtation. Taking in what mainwindows sends and creating a response in return.
 * Observer will hold response messages in hold and a vector array of Elevators up to the MAX_ELEVATORS definition
 * SignalCthr:
 * This function acts as the response function for the program, will return a QString to be displayed on the interface.
 * The function itself is a switch which gives a response based off of the commands given. While this is in mainwindows.h, the key is:
 * 1=Up,2=Down,3=fire, 4=Power_Outage,5=Overload,6=Help, 7=Door Obstacles.
 *
 * SetupFloorsElevators:
 * void method to set the number of elevators and the number of floors there are in program. Will start with the default of ELEVATORS and FLOORS in case the user never enters anything.
 * */

class Elevator; //declaration of elevator class used for vector array
class Observer
{
public:
    Observer();
    ~Observer();
    QString SignalCthr( int c, int f);
    void SetupFloorsElevators(int elevators, int floors);
private:
   QString send;
   QVector<Elevator> Ele;
   int M;//number of Elevators, If the actor sends a select number to the program with the enter custom button, it will change the number of elevators and floors
   int N; //number of floors
};

#endif // OBSERVER_H
