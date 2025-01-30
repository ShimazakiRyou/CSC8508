﻿//
// Contributors: Alfie
//

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#define QUEUE PriorityQueue<EventListener<E>*>

#include "EventListener.h"
#include "EventPriority.h"
#include "PriorityQueue.h"

/**
 * A static class that holds pointers to EventListeners and calls their OnEvent() functions when an Event is called.
 */
class EventManager {
public:
    /**
     * Invokes the OnEvent() functions of all registered listeners for this event type.
     * @tparam E Event type (child class)
     * @param e Event instance
     */
    template <typename E>
    static void Call(E* e);

    template <typename E>
    static void RegisterListener(EventListener<E>* listener, EventPriority priority = DEFAULT);

    /**
     * Deletes all listeners of a target Event type and clears the listeners vec.
     * @tparam E Event type (child class)
     */
    template <typename E>
    static void DeleteAllListeners();

protected:
    template <typename E>
    static QUEUE listeners;
};


template <typename E>
QUEUE EventManager::listeners = QUEUE(EARLY); // EARLY because that's the highest value of the priority enum (i.e. the max)


template<typename E>
void EventManager::Call(E* e) {
    for (int i = 0; i < listeners<E>.GetLength(); i++) listeners<E>[i]->OnEvent(e);
}


template<typename E>
void EventManager::RegisterListener(EventListener<E>* listener, EventPriority priority) {
    listeners<E>.Insert(listener, priority);
}


template<typename E>
void EventManager::DeleteAllListeners() {
    for (EventListener<E> const* l : listeners<E>.GetValues()) { delete l; }
    listeners<E>.Clear();
}

#endif //EVENTMANAGER_H
