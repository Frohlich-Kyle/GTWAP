//Author: Kyle Frohlich
//Date: 18Feb2025
//Name: GTWAP

#ifndef NETWORK_H
#define NETWORK_H

#include "networkdevice.h"

class NetworkDevice;


class Network
{
    int rows = Height;
    int columns = Length;
    NetworkDevice networkGraph[Height][Length];

    public:
        Network();
        
        int getRowNum();
        int getColumnNum();

        void setRowNum(int);
        void setColumnNum(int);

        void addDevice(int, int, NetworkDevice&);
        NetworkDevice getDevice(int, int);
};

#endif