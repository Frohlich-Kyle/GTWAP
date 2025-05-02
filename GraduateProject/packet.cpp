//Author: Kyle Frohlich
//Date: 18Feb2025
//Name: GTWAP

#include "packet.h"


Packet::Packet()
{
    name = "noName";
    //priorityLevel = "unset";
    priority = -1;
    logSize = 0;
    isDropped = false;
}

Packet::Packet(Packet& copyPacket)
{

}



string Packet::getName()
{
    return name;
}

// string Packet::getPriorityLevel()
// {
//     return priorityLevel;
// }

int Packet::getPriority()
{
    return priority;
}

NetworkDevice* Packet::getApLog()
{
    return apLog;
}

int Packet::getLogSize()
{
    return logSize;
}

bool Packet::getIsDropped()
{
    return isDropped;
}

int Packet::getPacketSize()
{
    return packetSize;
}




void Packet::setName(string newName)
{
    name = newName;
}

// void Packet::setPriorityLevel(string newPriorityLevel)
// {
//     priorityLevel = newPriorityLevel;
// }

void Packet::setPriority(int newPriority)
{
    priority = newPriority;
}

void Packet::setApLog(NetworkDevice* newApLog, int newLength)
{
    for(int index = 0; index < newLength; index++)
    {
        apLog[index] = newApLog[index];
    }
}

void Packet::setLogSize(int newLogSize)
{
    logSize = newLogSize;
}

void Packet::setIsDropped(bool newIsDropped)
{
    isDropped = newIsDropped;
}

void Packet::setPacketSize(int newPacketSize)
{
    packetSize = newPacketSize;
}


void Packet::addNetDev(NetworkDevice loggedDevice)
{
    if(logSize < Length)
    {
        apLog[logSize] = loggedDevice;
        logSize++;
        //cout << "Current Logged Devices: " << logSize << endl;
    }
    else if(logSize >= Length)
    {
        cout << "Log size cap has been hit (# of devices logged = length of network)" << endl;
        cout << "Something has gone terribly wrong!" << endl;
        cout << "Current Logged Devices: " << logSize << endl;
    }
}

void Packet::statLogs()
{
    cout << "Network Devices Passed Through: ";

    for(int index = 0; index < logSize; index++)
    {
        if(index == logSize - 1)
        {
            cout << " " << apLog[index].getName() << " (" << apLog[index].getDeviceAttitude().getPersonality() << ") " << endl;
        }
        else
        {
            cout << " " << apLog[index].getName() << " (" << apLog[index].getDeviceAttitude().getPersonality() << ") " << ",";
        }
    }


    cout << "Did I make it through the network?: ";

    if(isDropped == false)
    {
        cout << "Yes! " << endl;
    }
    //implies that isDropped is true since this is binary n shi
    else
    {
        cout << "No... :(" << endl;
    }
}