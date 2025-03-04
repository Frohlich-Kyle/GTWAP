//Author: Kyle Frohlich
//Date: 18Feb2025
//Name: GTWAP


#ifndef ATTITUDE_H
#define ATTITUDE_H

using namespace std;
#include <iostream>


class Attitude
{
    string personality;
    float percentDrop;

    public:
        Attitude();
        Attitude(string, float);
        Attitude(Attitude&);

        string getPersonality();
        float getPercentDrop();

        void setPersonality(string);
        void setPercentDrop(float);

        void setAttributes();
};

#endif