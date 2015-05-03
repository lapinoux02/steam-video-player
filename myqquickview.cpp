#include "myqquickview.h"

MyQQuickView::MyQQuickView(QString s) : QQuickView() {
    DIR* rep = opendir(s.toStdString().c_str());
    struct dirent* readFile = NULL;

    while ((readFile = readdir(rep)) != NULL)
        files.append(s + "/" + QString(readFile->d_name));

    files.erase(files.begin(), files.begin()+2);

    currentFile = files.begin();

    closedir(rep);
}

MyQQuickView::MyQQuickView(QString s){

}

MyQQuickView::~MyQQuickView() {}

virtual bool MyQQuickView::event(QEvent* e){
    return QQuickView::event(e);
}

virtual void MyQQuickView::keyPressEvent(QKeyEvent *event) {

    switch (event->key()) {
        case Qt::Key_Left :
            currentFile == files.begin() ? currentFile = files.end()-1 : currentFile--;
            rootObject()->setProperty("source1", *currentFile);
            break;
        case Qt::Key_Right :
            currentFile == files.end()-1 ? currentFile = files.begin() : currentFile++;
            rootObject()->setProperty("source1", *currentFile);
            break;
        case JoystickKey::Button_A :
            cout << "Bouton A" << endl;
            break;
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

void MyQQuickView::setInitialFileName() {
    rootObject()->setProperty("source1", *currentFile);
}
