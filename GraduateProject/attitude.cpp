//Author: Kyle Frohlich
//Date: 18Feb2025
//Name: GTWAP


#include "attitude.h"


Attitude::Attitude()
{
    personality = "unset";
    percentDrop = -1;
}

Attitude::Attitude(string newPersonality, float newPercentDrop)
{
    personality = newPersonality;
    percentDrop = newPercentDrop;
}

Attitude::Attitude(Attitude& newAttitude)
{
    personality = newAttitude.personality;
    percentDrop = newAttitude.percentDrop;
}

Attitude Attitude::operator=(const Attitude& otherAttitude)
{
    this->personality = otherAttitude.getPersonality();
    this->percentDrop = otherAttitude.getPercentDrop();

    return *this;
}


string Attitude::getPersonality() const
{
    return personality;
}

float Attitude::getPercentDrop() const
{
    return percentDrop;
}



void Attitude::setPersonality(string newPersonality)
{
    personality = newPersonality;
}

void Attitude::setPercentDrop(float newPercentDrop)
{
    percentDrop = newPercentDrop;
}


void Attitude::randomPersonality(int personalityNum)
{
    switch(personalityNum)
    {
        case 0:
            this->personality == "Selfish";
            this->percentDrop = 40;
            break;
        case 1:
            this->personality == "Reserved";
            this->percentDrop = 30;
            break;
        case 2:
            this->personality == "Middling";
            this->percentDrop = 20;
            break;
        case 3:
            this->personality == "Giving";
            this->percentDrop = 10;
            break;
        case 4:
            this->personality == "Generous";
            this->percentDrop = 0;
            break;
    }
}

void Attitude::setAttributes()
{
    if(personality == "unset")
    {
        percentDrop = -1;
    }
    if(personality == "Selfish")
    {
        percentDrop = 40;
    }
    if(personality == "Reserved")
    {
        percentDrop = 30;
    }
    if(personality == "Middling")
    {
        percentDrop = 20;
    }
    if(personality == "Giving")
    {
        percentDrop = 10;
    }
    if(personality == "Generous")
    {
        percentDrop = 0;
    }
}