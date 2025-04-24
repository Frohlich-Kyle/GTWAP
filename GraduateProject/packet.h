//Author: Kyle Frohlich
//Date: 18Feb2025
//Name: GTWAP

#ifndef PACKET_H
#define PACKET_H

using namespace std;
#include <iostream>
#include "network.h"

class Packet
{
    string name, priorityLevel;
    int priority, logSize;
    NetworkDevice apLog[Length];
    bool isDropped;

    public:
        Packet();
        Packet(Packet&);

        string getName();
        string getPriorityLevel();
        int getPriority();
        NetworkDevice* getApLog();
        int getLogSize();
        bool getIsDropped();

        void setName(string);
        void setPriorityLevel(string);
        void setPriority(int);
        void setApLog(NetworkDevice*, int);
        void setLogSize(int);
        void setIsDropped(bool);

        void addNetDev(NetworkDevice);
        void statLogs();
};

#endif