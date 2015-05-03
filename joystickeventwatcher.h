#ifndef JOYSTICKEVENTWATCHER_H
#define JOYSTICKEVENTWATCHER_H

#include <QWindow>
#include "qjoystick/qjoystick.h"

enum JoystickKey
{
    LeftStick_Up = 0x02000000,
    LeftStick_Down,
    LeftStick_Left,
    LeftStick_Right,
    LeftStick_Click,
    RightStick_Up,
    RightStick_Down,
    RightStick_Left,
    RightStick_Right,
    RightStick_Click,
    Button_A,
    Button_B,
    Button_X,
    Button_Y,
    Button_Left,
    Button_Righ,
    Dpad_Up,
    Dpad_Down,
    Dpad_Left,
    Dpad_Right,
    Trigger_Left,
    Trigger_Right
};

class JoystickEventWatcher
{
public:
    JoystickEventWatcher(QJoystick& joysticks);
    ~JoystickEventWatcher();

    void addEventListener(QWindow newListener);
    QWindow removeEventListener(QWindow listenerToDelete);

protected:
    QJoystick watchedJoysticks;

    void updateData();
};

#endif // JOYSTICKEVENTWATCHER_H
