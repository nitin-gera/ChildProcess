#include "ChildProcess.h"

ChildProcess::ChildProcess(QObject *parent) : QObject(parent)
{
    m_ChildProcess = new QProcess(this);
}

void ChildProcess::StartProcess()
{
    QString program = "/home/Experiments/ChildApplication/ChildApplication";

    m_ChildProcess->start(program);

    qDebug() << m_ChildProcess->pid() << endl;

    connect(m_ChildProcess, SIGNAL(started()), SLOT(NotifyStarted()));
    connect(m_ChildProcess, SIGNAL(stateChanged(QProcess::ProcessState)), SLOT(NotifyStateChanged()));
}

void ChildProcess::NotifyStarted()
{
    qDebug() << Q_FUNC_INFO << endl;

    QString data = "I am sending data";

//    m_ChildProcess->open(QIODevice::WriteOnly);
    qDebug() << "Bytes written = " << m_ChildProcess->write(data.toLocal8Bit());
    m_ChildProcess->closeWriteChannel();
}

void ChildProcess::NotifyStateChanged()
{
    qDebug() << Q_FUNC_INFO << m_ChildProcess->state() << endl;
}
