//Author: Kyle Frohlich
//Date: 18Feb2025
//Name: GTWAP

#ifndef NETWORKDEVICE_H
#define NETWORKDEVICE_H

//How many network devices need to go across (from one WAP to another WAP)
//For example a length of 5 means you will find 2 WAP on the ends which means 5-2=3 where 3 switches will be found in between
#define Length 5

//How many network devices are found in each "row"
//For example a height of 3 means theres 3 possible switches a packet could see before it gets to the next length section
#define Height 3

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
        void setNumResources(int);
        void setNumPacketsDropped(int);
        void setNumPacketsForwarded(int);
        void setDeviceAttitude(Attitude);

        bool willForward(int, int);
};

#endif