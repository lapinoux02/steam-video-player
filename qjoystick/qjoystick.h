#ifndef QJOYSTICK_H
#define QJOYSTICK_H

#include <QObject>
#include <QString>

#include "SDL/SDL.h"


class QJoystick : public QObject
{
    Q_OBJECT
public:
    typedef struct
    {
        bool buttonA : 1;
        bool buttonB : 1;
        bool buttonX : 1;
        bool buttonY : 1;

    } joystickState;

    QJoystick();
    ~QJoystick();
    int availableJoysticks();
    int currentJoystick();
    QString joystickName(int id);
    int joystickNumAxes(int id);
    int joystickNumButtons(int id);
    void getdata();

public slots:
    void setJoystick(int jsNumber);

signals:

private:
    SDL_Joystick* m_joystick;
};

#endif // QJOYSTICK_H
