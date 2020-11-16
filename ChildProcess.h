#ifndef CHILDPROCESS_H
#define CHILDPROCESS_H

#include <QObject>
#include <QProcess>
#include <QDebug>

class ChildProcess : public QObject
{
    Q_OBJECT
public:
    explicit ChildProcess(QObject *parent = nullptr);

signals:

public slots:
    void StartProcess();
    void NotifyStarted();
    void NotifyStateChanged();

private:
    QProcess    *m_ChildProcess;
};

#endif // CHILDPROCESS_H
