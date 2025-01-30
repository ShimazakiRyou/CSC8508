//
// Contributors: Alfie
//

#ifndef CANCELLABLEEVENT_H
#define CANCELLABLEEVENT_H
#include "Event.h"

class CancellableEvent : public Event
{
public:
    void SetCancelled(bool const cancelled) { this->cancelled = cancelled; }

    [[nodiscard]]
    bool IsCancelled() const { return cancelled; }

protected:
    bool cancelled = false;
};

#endif //CANCELLABLEEVENT_H
