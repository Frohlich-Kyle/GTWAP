//Author: Kyle Frohlich
//Date: 18Feb2025
//Name: GTWAP

#ifndef NETWORK_H
#define NETWORK_H

//How many network devices need to go across (from one WAP to another WAP)
//For example a length of 5 means you will find 2 WAP on the ends which means 5-2=3 where 3 switches will be found in between
#define Length 5

//How many network devices are found in each "row"
//For example a height of 5 means theres 5 possible switches a packet could see before it gets to the next length section
#define Height 5

#include "networkdevice.h"


class Network
{
    int rows = Height;
    int columns = Length;
    int networkGraph[Length][Height];

    public:
    
};

#endif