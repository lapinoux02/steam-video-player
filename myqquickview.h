#ifndef MYQQUICKVIEW_H
#define MYQQUICKVIEW_H

#include <dirent.h>
#include <QQuickView>

class MyQQuickView : public QQuickView
{
public:
    MyQQuickView(QString s) {
        DIR* rep = opendir(s.toStdString().c_str());
        struct dirent* readFile = NULL;

        while ((readFile = readdir(rep)) != NULL) {
            QString string (readFile->d_name);
            if (string.contains(QRegExp("\\.mp4$"))) // Change regexp to add more file types
                files.append(s + "/" + string);
        }

        currentFile = files.begin();

        closedir(rep);
    }

    virtual ~MyQQuickView() {}

    virtual bool event(QEvent* e) {
        return QQuickView::event(e);
    }

    void setInitialFileName(){
        rootObject()->setProperty("source1", *currentFile);
    }

protected:
    QList<QString> files;
    QList<QString>::iterator currentFile;

    virtual void keyPressEvent(QKeyEvent *event){

        switch (event->key()) {
            case Qt::Key_Left :
                currentFile == files.begin() ? currentFile = files.end()-1 : currentFile--;
                rootObject()->setProperty("source1", *currentFile);
                break;
            case Qt::Key_Right :
                currentFile == files.end()-1 ? currentFile = files.begin() : currentFile++;
                rootObject()->setProperty("source1", *currentFile);
                break;
            /*case JoystickKey::Button_A :
                cout << "Bouton A" << endl;
                break;*/
            case Qt::Key_Enter :
            case Qt::Key_Return :
                rootObject()->findChild<QObject *>(QString("sceneSelectionPanel"))->setProperty("sceneSource", "VideoFullScreen.qml");
                break;
            case Qt::Key_Backspace:
            case Qt::Key_Escape:
                rootObject()->findChild<QObject *>(QString("sceneSelectionPanel"))->setProperty("sceneSource", "");
                break;

        }
    }
};


#endif // MYQQUICKVIEW_H
