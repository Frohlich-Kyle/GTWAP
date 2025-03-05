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


string Attitude::getPersonality()
{
    return personality;
}

float Attitude::getPercentDrop()
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
    else if(personality == "Selfish")
    {
        percentDrop = 40;
    }
    else if(personality == "Stingy")
    {
        percentDrop = 25;
    }
    else if(personality == "Cheap")
    {
        percentDrop = 15;
    }
    else if(personality == "Nice")
    {
        percentDrop = 5;
    }
    else if(personality == "Generous")
    {
        percentDrop = 1;
    }
}