//Author: Kyle Frohlich
//Date: 18Feb2025
//Name: GTWAP

#ifndef PACKET_H
#define PACKET_H

using namespace std;
#include <iostream>
#include "networkdevice.h"


class Packet
{
    string name;
    //string priorityLevel
    int priority, logSize, packetSize;
    NetworkDevice apLog[Length];
    bool isDropped;

    public:
        Packet();
        Packet(Packet&);

        string getName();
        //string getPriorityLevel();
        int getPriority();
        NetworkDevice* getApLog();
        int getLogSize();
        bool getIsDropped();
        int getPacketSize();

        void setName(string);
        //void setPriorityLevel(string);
        void setPriority(int);
        void setApLog(NetworkDevice*, int);
        void setLogSize(int);
        void setIsDropped(bool);
        void setPacketSize(int);

        void addNetDev(NetworkDevice);
        void statLogs();
};

#endif