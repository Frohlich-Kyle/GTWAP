//Author: Kyle Frohlich
//Date: 18Feb2025
//Name: GTWAP

#ifndef NETWORKDEVICE_H
#define NETWORKDEVICE_H

#include "attitude.h"


class NetworkDevice
{
    string name;
    //holds the x,y coordinates in the graph
    int position[2];
    int numResources;
    int numPacketsDropped;
    int numPacketsForwarded;
    Attitude deviceAttitude;
    
    public:
        NetworkDevice(); 

        string getName();
        int* getPosition();
        int getNumResources();
        int getNumPacketsDropped();
        int getNumPacketsForwarded();
        Attitude getDeviceAttitude();

        void setName(string);
        void setPosition(int*);
        void getNumResources(int);
        void getNumPacketsDropped(int);
        void getNumPacketsForwarded(int);
        void getDeviceAttitude(Attitude);
};

#endif