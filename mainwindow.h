#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Observer.h"
#include <QMainWindow>
#include <string>
#include <QObject>
#include <QThread>
/*MainWindows:
 * The goal of this file is to produce the interface the subject will be interacting with.
 * This is our main signal handleing class, and will contain our slots for all signals from the ui.
 * Slots:
 * GoUp()-calls for the Observer with the Up command and carries in the current floor, found in cur_floor variable
 * GoDown- Calls for the Observer with the Down command and carries the current floor
 * Obstacle()-Calls for the Observer with the Obstacles command. If someone pressed the SOLVED button, it will also display that the issue has been aliviated
 * Fire()-Calls for the Observer with the fire command
 * Overloaded()-Calls for the Observer with the Overloaded command. Is SOLVED is true, then pressing this will also simulate it no longer being overloaded
 * Help()-Calls for the Observer with the help command. If SOLVED has been pressed, the command will act as if the elevator service has been dialed. If not, then command will simulate dialing 911
 * Power_Outage()-Calls for the Observer with the Power_Outage command
 * At_Floor()-Takes in the number which is present on the current floor QT object. Updates the curr_floor variable
 * Custom()- Takes in the values of the Floors and Elevator spinbox and uses them to create the system and floors
 *
 * NOTE: All commands used do not go by name but rather by number: 1=Up,2=Down,3=fire, 4=Power_Outage,5=Overload,6=Help, 7=Door Obstacles.
 *
 *Solved()- Recives contact when the SOLVED button is pressed. Meant to simulate the subject Solving the problem.
 *
 * Setup()-makes the connections.
 * */


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
//class Observer{};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Setup();
private:
    Ui::MainWindow *ui;
    QString Output;
    Observer o;
    int cur_floor;
    bool Solution;
    int M; //elevators, as specified in the Documentation
    int N; //number of elevators custom made
private slots:
    void GoUp();
    void GoDown();
    void Obstacle();
    void Fire();
    void Help();
    void Power_Outage();
    void Overloaded();
    void At_Floor(int i);
    void Solved();
    void Custom();
    void DoorOpen();
    void DoorClose();
};
#endif // MAINWINDOW_H
