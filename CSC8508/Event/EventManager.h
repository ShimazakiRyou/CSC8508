//
// Contributors: Alfie
//

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#define QUEUE PriorityQueue<EventListener<E>*>

#include "EventListener.h"
#include "EventPriority.h"
#include "PriorityQueue.h"

class EventManager {
public:
    template <typename E>
    static void Call(E* e);

    template <typename E>
    static void RegisterListener(EventListener<E>* listener, EventPriority priority = DEFAULT);

protected:
    template <typename E>
    static QUEUE listeners;
};


template <typename E>
QUEUE EventManager::listeners = QUEUE(EARLY); // EARLY because that's the highest value of the priority enum (i.e. the max)


template<typename E>
void EventManager::Call(E* e) {
    for (int i = 0; i < listeners<E>.get_length(); i++) listeners<E>[i]->OnEvent(e);
}


template<typename E>
void EventManager::RegisterListener(EventListener<E>* listener, EventPriority priority) {
    listeners<E>.add(listener, priority);
}

#endif //EVENTMANAGER_H
