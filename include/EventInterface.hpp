/*
 * Event interface used for event management.
 */

#ifndef EVENTINTERFACE_HPP
#define EVENTINTERFACE_HPP

#include "EventType.hpp"
#include <SFML/Window.hpp>

class EventInterface {
public:
    virtual const EventType& getEventType(void) const = 0;
    const float getDeltaTime(void) const { return deltaTime; }
private:
private:
    EventType type;
    float deltaTime;
protected:
    void setDeltaTime(float deltaTime) {this->deltaTime = deltaTime; }
};

#endif
