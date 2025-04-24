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