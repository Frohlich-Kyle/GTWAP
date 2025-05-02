//Author: Kyle Frohlich
//Date: 23Jan2025
//Name: GTWAP

#include "packet.h"
#include "network.h"

#define WAPresources 10

void initializePackets(Packet*, int);
void initializeDevice(int, int, NetworkDevice&);
bool hopNode(int, Network, Packet&);

int main()
{
    int numPackets = 10;
    cout << "Packet initialize started" << endl;

    //step 1 set up the packets
    Packet allPackets[numPackets];
    initializePackets(allPackets, numPackets);

    cout << "Packet Initialize Ended" << endl;


    cout << "Network Initialize Started" << endl;

    //our graph is 5 columns and 3 rows
    Network networkGraph;
    networkGraph.setColumnNum(Length);
    networkGraph.setRowNum(Height);
    NetworkDevice tempDevice;
    //int tempRow = 0, tempColumn = 0;

    initializeDevice(0, 0, tempDevice);
    networkGraph.addDevice(0, 0, tempDevice);
    // cout << tempDevice.getDeviceAttitude().getPersonality() << endl;
    // cout << "personality check " << networkGraph.getDevice(0,0).getDeviceAttitude().getPersonality() << endl;
    // cout << "percent drop check " << networkGraph.getDevice(0,0).getDeviceAttitude().getPercentDrop() << endl;
    // cout << "num resources check " << networkGraph.getDevice(0,0).getNumResources() << endl;
    // cout << "name check " << networkGraph.getDevice(0,0).getName() << endl;

    initializeDevice(0, 1, tempDevice);
    networkGraph.addDevice(0, 1, tempDevice);

    initializeDevice(0, 2, tempDevice);
    networkGraph.addDevice(0, 2, tempDevice);

    initializeDevice(0, 3, tempDevice);
    networkGraph.addDevice(0, 3, tempDevice);

    initializeDevice(0, 4, tempDevice);
    networkGraph.addDevice(0, 4, tempDevice);

    initializeDevice(1, 0, tempDevice);
    networkGraph.addDevice(1, 0, tempDevice);

    initializeDevice(1, 1, tempDevice);
    networkGraph.addDevice(1, 1, tempDevice);

    initializeDevice(1, 2, tempDevice);
    networkGraph.addDevice(1, 2, tempDevice);

    initializeDevice(1, 3, tempDevice);
    networkGraph.addDevice(1, 3, tempDevice);

    initializeDevice(1, 4, tempDevice);
    networkGraph.addDevice(1, 4, tempDevice);

    initializeDevice(2, 0, tempDevice);
    networkGraph.addDevice(2, 0, tempDevice);

    initializeDevice(2, 1, tempDevice);
    networkGraph.addDevice(2, 1, tempDevice);

    initializeDevice(2, 2, tempDevice);
    networkGraph.addDevice(2, 2, tempDevice);

    initializeDevice(2, 3, tempDevice);
    networkGraph.addDevice(2, 3, tempDevice);

    initializeDevice(2, 4, tempDevice);
    networkGraph.addDevice(2, 4, tempDevice);

    cout << "Network Initialized Ended" << endl;


    cout << "Simlatuion Run Started" << endl;

    bool wasDropped;
    int index = 0, index2 = 0;

    for(index = 0; index < numPackets; index++)
    {
        cout << "Packet #" << index << " started" << endl;
        wasDropped = false;
        index2 = 0;
        for(index2 = 0; index2 < Length; index2++)
        {
            //cout << "Node hop #" << index2 << endl;
            wasDropped = hopNode(index2, networkGraph, allPackets[index]);

            if(wasDropped == true)
            {
                break;
            }
        }
        cout << "Packet #" << index << " ended" << endl;
    }


    for(int index3 = 0; index3 < numPackets; index3++)
    {
        allPackets[index3].statLogs();
    }

    cout << endl << "Simulation Run Ended" << endl;

    return 0;
}




void initializePackets(Packet* allPackets, int numPackets)
{
    int rng = 0;
    srand(time(0));

    for(int index = 0; index < numPackets; index++)
    {   
        //set all the values for a packet
        //allPackets[index].setName(to_string(index + 1));
        string packetName = ("Packet " + index + 1);  // Set name based on the index
        allPackets[index].setName(packetName);
        //cout << "Packet name: " << packetName << endl;
        allPackets[index].setLogSize(0);
        allPackets[index].setIsDropped(false);

        rng = rand() %  (5 + 1 - 1) + 1;
        allPackets[index].setPacketSize(rng);
        rng = rand() %  (3 + 1 - 1) + 1;
        allPackets[index].setPriority(rng);
    }
}


void initializeDevice(int row, int column, NetworkDevice& modifyDevice)
{
    Attitude newAttitude;
    int position[2];
    string tempPersonality;
    int tempPercentDrop;

    if(column == 0 || column == Length - 1)
    {
        modifyDevice.setName("WAP " + to_string(column) + "-" + to_string(row));
        //cout << modifyDevice.getName() << endl;
    }
    else
    {
        modifyDevice.setName("Switch " + to_string(column) + "-" + to_string(row));
        //cout << modifyDevice.getName() << endl; 
    }

    //0 to 4 for values of rng
    int rng = rand() % 5;

    //defined macro in this file
    modifyDevice.setNumResources(WAPresources);
    position[0] = column;
    position[1] = row;
    modifyDevice.setPosition(position);
    //cout << rng << endl;
    //newAttitude.randomPersonality(rng);
    //cout << newAttitude.getPersonality() << endl;
    switch(rng)
    {
        case 0:
            tempPersonality = "Selfish";
            tempPercentDrop = 40;
            break;
        case 1:
            tempPersonality = "Reserved";
            tempPercentDrop = 30;
            break;
        case 2:
            tempPersonality = "Middling";
            tempPercentDrop = 20;
            break;
        case 3:
            tempPersonality = "Giving";
            tempPercentDrop = 10;
            break;
        case 4:
            tempPersonality = "Generous";
            tempPercentDrop = 0;
            break;
    }

    newAttitude.setPersonality(tempPersonality);    

    newAttitude.setPercentDrop(tempPercentDrop);

    modifyDevice.setDeviceAttitude(newAttitude);

    //cout << newDevice.getDeviceAttitude().getPersonality() << " ";
}


bool hopNode(int currentColumn, Network theNetwork, Packet& movingPacket)
{
    int rng = 0;
    bool willDrop = false;

    //cout << theNetwork.getDevice(0,0).getName() << endl << endl;

    //check if we've reach the end
    //cout << "Current Column: " << currentColumn << endl;

    if(currentColumn < Length)
    {
        //pick random number between 0 and row number
        rng = rand() % Height;       
        //cout << "Next device to hop too: " << rng << endl;
        //check network device there
        if(theNetwork.getDevice(rng, currentColumn).getName() == "noName")
        {
            cout << "There wasn't a device there, something has gone wrong" << endl;
            cout << "Device that somehow couldn't be found: " << theNetwork.getDevice(0,0).getName() << endl << endl;
        }
        else
        {
            willDrop = theNetwork.getDevice(rng, currentColumn).willForward(movingPacket.getPacketSize(), movingPacket.getPriority());

            if(willDrop == false)
            {
                movingPacket.addNetDev(theNetwork.getDevice(rng, currentColumn));
                cout << "Packet Forwarded" << endl;
                willDrop = false;
            }
            else
            {
                movingPacket.addNetDev(theNetwork.getDevice(rng, currentColumn));
                movingPacket.setIsDropped(true);
                willDrop = true;
                cout << "Packet Dropped" << endl;
            }
        }
    }
    else
    {
        cout << "End of network has already been reached" << endl;
    }

    return willDrop;
}