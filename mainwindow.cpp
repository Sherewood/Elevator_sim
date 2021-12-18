#include "mainwindow.h"
#include "ui_mainwindow.h"
int command;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Output="";
    cur_floor=0;
    M=0;
    N=0;
    ui->setupUi(this);
    Setup();



}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow:: Setup()
{
    connect(ui->Down, SIGNAL (released()), this, SLOT(GoDown()));
    connect(ui->up, SIGNAL (released()), this, SLOT(GoUp()));
    connect(ui->fire, SIGNAL (released()), this, SLOT(Fire()));
    connect(ui->power_outage, SIGNAL (released()), this, SLOT(Power_Outage()));
    connect(ui->Door_OBS, SIGNAL (released()), this, SLOT(Obstacle()));
    connect(ui->help, SIGNAL (released()), this, SLOT(Help()));
    connect(ui->overload, SIGNAL (released()), this, SLOT(Overloaded()));
    connect(ui->floor_lvl, SIGNAL(valueChanged(int)),this, SLOT(At_Floor(int)));
    connect(ui->Solved, SIGNAL(released()),this,SLOT(Solved()));
    connect(ui->Custom,SIGNAL(released()),this,SLOT(Custom()));
    connect(ui->DoorClose,SIGNAL(released()),this,SLOT(DoorClose()));
    connect(ui->DoorOpen,SIGNAL(released()),this,SLOT(DoorOpen()));
}
void MainWindow:: GoUp()
{
    command=1;
    Output= o.SignalCthr(command,cur_floor);
    ui->Output->clear();
    ui->Output->append(Output);
}
void MainWindow:: GoDown()
{
    command=2;
    Output= o.SignalCthr(command,cur_floor);
    ui->Output->clear();
    ui->Output->append(Output);
}
void MainWindow:: Obstacle()
{
    command=7;
    Output= o.SignalCthr(command,cur_floor);
    ui->Output->clear();
    ui->Output->append(Output);
    if (Solution)
    {
        ui->Output->append("No Obstructions detected");
    }
}
void MainWindow:: Fire()
{
    command=3;
    Output= o.SignalCthr(command,cur_floor);
    ui->Output->clear();
    ui->Output->append(Output);
}
void MainWindow:: Help()
{
    ui->Output->clear();
    command=6;
    Output= o.SignalCthr(command,cur_floor);
    ui->Output->append(Output);
    ui->Output->append("Waiting.");
    if(Solution)
    {
    ui->Output->append("Response recieved. In communication with passenger");
    }
    else
    {
    ui->Output->append("No Response found, dialing 911");
    }
}
void MainWindow:: Power_Outage()
{
    command=4;
    Output= o.SignalCthr(command,cur_floor);
    ui->Output->clear();
    ui->Output->append(Output);

}
void MainWindow:: Overloaded()
{
    command=5;
    Output= o.SignalCthr(command,cur_floor);
    ui->Output->clear();
    ui->Output->append(Output);
    if (Solution)
    {
        ui->Output->append("No longer Overloaded");
    }
}
void MainWindow:: Custom()
{
    M=ui->Total_Elevators->value();
    N=ui->Total_floors->value();
    ui->floor_lvl->setMaximum(N);
    o.SetupFloorsElevators(M,N);
    ui->Output->append("Custom specifciations recognized");

}
void MainWindow:: At_Floor(int i)
{
    cur_floor=i;
}
void MainWindow:: Solved()
{
    if(Solution){
        ui->Output->append("\n all events are now in their worse case scenario");
        Solution=false;
    }
    else{

        ui->Output->append("\n all events are now in their best case scenario");
        Solution=true;
    }

}
void MainWindow:: DoorOpen(){ ui->Output->append("\n Doors opening.....");}
void MainWindow:: DoorClose(){ui->Output->append("\n Doors Closing....");}
