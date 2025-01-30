//
// Contributors: Alfie
//

#ifndef EVENTPRIORITY_H
#define EVENTPRIORITY_H
#include <cstdint>

enum EventPriority : uint8_t
{
    MONITOR, // Events should NOT be cancelled or edited when listener to using this priority
    LATE,
    DEFAULT,
    EARLY
};

//EVENTPRIORITY_H
