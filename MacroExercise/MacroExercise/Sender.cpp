#include "Sender.hpp"

WF_MSW_DISABLE(MSW_STL)
#include <iostream>
WF_MSW_RESTORE()

WF_MSW_DISABLE(MSW_QT)
#include <QtCore/QThread>
WF_MSW_RESTORE()


void Sender::internalWorker()
{
  QString lStringData = QString::number(qrand());
  bool lBoolData = (static_cast<quint32>(qrand() % 2 == 0));
  std::cout << "Emiting from thread " << QThread::currentThreadId() << std::endl;
  emit dataReady(lStringData, lBoolData);
}


#include "Sender_moc.cpp"
