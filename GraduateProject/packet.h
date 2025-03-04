//Author: Kyle Frohlich
//Date: 18Feb2025
//Name: GTWAP

using namespace std;
#include <iostream>

class Packet
{
    string name, priorityLevel;
    int priority;

    public:
        string getName();
        string getPriorityLevel();
        int getPriority();

        void setName(string);
        void setPriorityLevel(string);
        void setPriority(int);
};