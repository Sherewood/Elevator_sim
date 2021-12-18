#include "Observer.h"

Observer::Observer()
{
    SetupFloorsElevators(ELEVATORS,FLOORS);

}
Observer::~Observer()
{

}
void Observer::SetupFloorsElevators(int elevators, int floors)
{
    M=elevators;
    N=floors;
    if (Ele.size()!=0)
    {
        Ele.clear();
    }
    for (int init=0; init<M; init++)
    {
        int start_floor= rand()%N;
        Elevator add= Elevator(init,start_floor);
        Ele.push_back(add);

    }
}
QString Observer::SignalCthr(int command, int floor)
{
    switch (command) {
    //UP
    case 1:
    {
        QString str= QString::number(floor);
        send= ("You pressed the up button, you are currently at "+str+"\n");
        for (int check=0; check<Ele.size();check++)
        {
            if (check==Ele.size()-1)
            {
                for (int reset=check-1; reset>=0;reset--)
                {
                    Ele[reset].Refresh();

                }
                send+= "\nAll Elevators busy. \nWaiting for an elevator to be open... \n";
            }

            if (!Ele[check].InUse())
            {
                QString find_avail_Elevator=Ele[check].Movement(floor);
                send+=find_avail_Elevator;
                break;
            }

        }
        return send;
        break;
    }
    //DOWN
    case 2:
    {
        QString str= QString::number(floor);
        send=("You pressed the down button, you are currently at \n"+str);
        for (int check=0; check<Ele.size();check++)
        {
            if (check==Ele.size()-1)
            {
                for (int reset=check-1; reset>=0;reset--)
                {
                    Ele[reset].Refresh();
                }
               send+= "\n All Elevators busy. \n Waiting for an elevator to be open... \n";
            }

            if (!Ele[check].InUse())
            {
                QString find_avail_Elevator=Ele[check].Movement(floor);
                send+=find_avail_Elevator;
                break;
            }

        }
         return send;
        break;
    }
    //FIRE
    case 3:
        send=("\n[LOUD RINING NOISES]\nYou pressed the fire button! Sending all Elevators to Ground floor\n");
        for (int check=0; check<Ele.size();check++)
        {
            QString find_avail_Elevator=Ele[check].Movement(0);
            send+=find_avail_Elevator;

        }

        for (int reset=Ele.size()-1; reset>=0;reset--)
        {
            Ele[reset].Refresh();
        }
        send+=("\n Please exit in an orderly fashion and evacuate the building");
         return send;
        break;
     //POWER_OUTAGE
    case 4:
        send=("\n[BWEEP]\nPower Outage! Sending all elevators to the ground floor");
        for (int check=0; check<Ele.size();check++)
        {
            QString find_avail_Elevator=Ele[check].Movement(0);
            send+=find_avail_Elevator;

        }

        for (int reset=Ele.size()-1; reset>=0;reset--)
        {
            Ele[reset].Refresh();
        }
        send+=("\n Please exit in an orderly fashion and find a safe area");

         return send;
        break;

     //OVERLOAD
    case 5:
        send= "Overloaded, please reduce elevator weight and then press solved and the Overload button again";
         return send;

        break;
     //HELP
    case 6:
        send="HELP! Button Pressed! Contacting services...";

         return send;
        break;
     //DOOR_OBSTACLES
    case 7:
        send="Door Obstructed. \n Opening door again...\n When the Door is no longer blocked, pressed solved and Door Obstacles again.";
         return send;
        break;
    }


}
