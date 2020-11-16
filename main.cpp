#include <QCoreApplication>
#include <QDebug>
#include "ChildProcess.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "I am Master application" << endl;

    ChildProcess    *obj = new ChildProcess();
    obj->StartProcess();

    return a.exec();
}
