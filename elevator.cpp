#include "elevator.h"

Elevator::Elevator()
{
    name=0;
}
Elevator::Elevator(int title, int floor)
{
    name=title;
    current_floor=floor;
    busy=false;

}

Elevator::~Elevator()
{}

QString Elevator::Movement(int floor_call)
{
    QString id= QString::number(name);
    QString target_floor=QString::number(floor_call);
    if (current_floor<=floor_call)
    {
        QString arrival= QString::number(current_floor);

        while (current_floor<floor_call)
        {
            current_floor++;

        }

         busy=true;
         return "\n Elevator "+id+" has arrived from floor "+arrival+" To floor "+target_floor+"\n[DING] \n Doors Opening..."+"\n [DING] \n Doors Closing ";
    }
    else
    {
        QString arrival= QString::number(current_floor);

        while (current_floor>floor_call)
        {
            current_floor--;
            //sleep(1000);
        }
          busy=true;
         return "\n Elevator "+id+" has arrived from floor "+arrival+" To floor "+target_floor+"\n[DING] \n Doors Opening..."+"\n [DING] \n Doors Closing ";
    }




}
//
void Elevator::Refresh(){busy=false;}
bool Elevator::InUse(){return busy;}
