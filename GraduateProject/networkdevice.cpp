//Author: Kyle Frohlich
//Date: 18Feb2025
//Name: GTWAP

#include "networkdevice.h"

NetworkDevice::NetworkDevice()
{

}



string NetworkDevice::getName()
{
    return name;
}

int* NetworkDevice::getPosition()
{
    return position;
}

int NetworkDevice::getNumResources()
{
    return numResources;
}

int NetworkDevice::getNumPacketsDropped()
{
    return numPacketsDropped;
}

int NetworkDevice::getNumPacketsForwarded()
{
    return numPacketsForwarded;
}

Attitude NetworkDevice::getDeviceAttitude()
{
    return deviceAttitude;
}




void NetworkDevice::setName(string newName)
{
    name = newName;
}

void NetworkDevice::setPosition(int* newPosition)
{
    position[0] = newPosition[0];
    position[1] = newPosition[1];
}

void NetworkDevice::getNumResources(int newNumResources)
{
    numResources = newNumResources;
}

void NetworkDevice::getNumPacketsDropped(int newNumPacketsDropped)
{
    numPacketsDropped = newNumPacketsDropped;
}

void NetworkDevice::getNumPacketsForwarded(int newNumPacketsForwarded)
{
    numPacketsForwarded = newNumPacketsForwarded;
}

void getDeviceAttitude(Attitude newAttitude)
{
    
}