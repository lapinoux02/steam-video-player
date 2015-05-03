#include "joystickeventwatcher.h"

JoystickEventWatcher::JoystickEventWatcher(QJoystick& joysticks)
{
    this->watchedJoysticks = joysticks;

    dataTimer = new QTimer;
    connect(data_timer, SIGNAL(timeout()), this, SLOT(updateData()));
}

JoystickEventWatcher::~JoystickEventWatcher()
{

}

JoystickEventWatcher::addEventListener(QWindow newListener)
{

}

JoystickEventWatcher::removeEventListener(QWindow listenerToDelete)
{

}

JoystickEventWatcher::updateData()
{
    watchedJoysticks.getdata();


}

