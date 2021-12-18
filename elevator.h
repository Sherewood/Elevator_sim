#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "elevator.h"
#include <vector>
#include<QString>
/* The purpose of this class is to simulate the movement of the elevator
 * -Elevator can either be created by default creation or by calling variables which the program will do, in order to define a starting floor, a numerical name, and the state of the elevator
 * -Movement(floors) is the main method of movement. If the current_floor is greater than the target floor, the elevator will move down and vice versa. floors should be brought in by the observer call.
 * Refresh and InUse are a Setter/Getter for the busy state. Meant to check if the Elevator is 'busy.'
 * */
class Elevator
{
public:
    Elevator();
    Elevator(int name, int floor);
   ~Elevator();
    QString Movement(int x);
    void Refresh();
    bool InUse();
private:
    int current_floor;
    int name;
    bool busy;
};

#endif // ELEVATOR_H
