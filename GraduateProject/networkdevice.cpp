//Author: Kyle Frohlich
//Date: 18Feb2025
//Name: GTWAP

#include "networkdevice.h"

NetworkDevice::NetworkDevice()
{
    name = "noName";
    //holds the x,y coordinates in the graph
    position[0] = 0;
    position[1] = 0;
    numResources = -1;
    numPacketsDropped = 0;
    numPacketsForwarded = 0;    
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

void NetworkDevice::setNumResources(int newNumResources)
{
    numResources = newNumResources;
}

void NetworkDevice::setNumPacketsDropped(int newNumPacketsDropped)
{
    numPacketsDropped = newNumPacketsDropped;
}

void NetworkDevice::setNumPacketsForwarded(int newNumPacketsForwarded)
{
    numPacketsForwarded = newNumPacketsForwarded;
}

void NetworkDevice::setDeviceAttitude(Attitude newAttitude)
{
    //deviceAttitude = newAttitude;

    //cout << "Assigning new attitude" << endl;

    deviceAttitude.setPercentDrop(newAttitude.getPercentDrop());
    //cout << newAttitude.getPercentDrop() << endl;
    deviceAttitude.setPersonality(newAttitude.getPersonality());
    //cout << newAttitude.getPersonality() << endl << endl;
}

bool NetworkDevice::willForward(int packetSize, int packetPriority)
{
    //do first in case device runs out of resources
    if(packetSize > numResources)
    {
        numPacketsDropped++;
        return false;
    }
    //This gives us a total value of the package in percent
    //ie prio = 3 and size = 5 is 15 util score so 100 * 1.15 is 115
    //then we multiply by our drop value after since its important to give greater value to the packet
    //so drop % of 40 is 115 * .4 = 46
    //46 is the value that we use for the game

    //utility score is to weigh more towards high size / prio packets
    int utilityScore = packetPriority * packetSize;
    float utilityRatio = utilityScore / 100;
    utilityScore = (utilityScore + 100) / 100;
    //int packetValue = 100 * utilityScore;
    //dropSkew modifies the chance of dropping to be higher or lower based on value
    float dropSkew = deviceAttitude.getPercentDrop() - (deviceAttitude.getPercentDrop() * (utilityRatio * 2));
    //int percentForward = 100 - deviceAttitude.getPercentDrop()

    int rng = rand() % 100;

    if (rng < dropSkew)
    {
        cout << "Dropped because " << rng << " was less than " << dropSkew << endl;
        cout << "Value too low" << endl;
        numPacketsDropped++;
        return true;
    }
    else
    {
        numPacketsForwarded++;
        this->numResources = numResources - packetSize;
        return false;
    }
}