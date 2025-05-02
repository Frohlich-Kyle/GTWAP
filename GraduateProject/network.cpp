//Author: Kyle Frohlich
//Date: 18Feb2025
//Name: GTWAP

#include "network.h"

Network::Network()
{
    //network graph has already been intialized by the class itself
}

int Network::getRowNum()
{
    return rows;
}
int Network::getColumnNum()
{
    return columns;
}



void Network::setRowNum(int newRows)
{
    rows = newRows;
}

void Network::setColumnNum(int newColumns)
{
    columns = newColumns;
}



void Network::addDevice(int rowSpot, int columnSpot, NetworkDevice& newDevice)
{
    
    if(rowSpot < rows && columnSpot < columns)
    {
        // cout << rowSpot << " " << columnSpot << endl;
        // cout << "adding a device " << newDevice.getDeviceAttitude().getPersonality() << endl;
        networkGraph[rowSpot][columnSpot] = newDevice;

        // cout << "Device added too- ";
        // cout << "row: " << rowSpot;
        // cout << " column: " << columnSpot << endl;

        //cout << networkGraph[rowSpot][columnSpot].getDeviceAttitude().getPersonality() << endl;
    }
    else
    {
        cout << "Trying to add network device out of bounds of graph" << endl;
    }
}

NetworkDevice Network::getDevice(int row, int column)
{
    return networkGraph[row][column];
}