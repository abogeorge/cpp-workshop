#include "Receiver.hpp"

WF_MSW_DISABLE(MSW_STL)
#include <iostream>
WF_MSW_RESTORE()

WF_MSW_DISABLE(MSW_QT)
#include <QtCore/QThread>
WF_MSW_RESTORE()

void Receiver::doWork()
{
  std::cout << mValue << std::endl;
  ++mTimesCalled;
  if (mTimesCalled == 7)
  {
    emit killApp();
  }
}

void Receiver::doMoreWork(const QString& pString, bool pBool)
{

  std::cout << "Emiting from thread " << QThread::currentThreadId() << std::endl;

  std::cout << "String \"" << pString.toUtf8().constData() << "\", bool " << std::boolalpha << pBool << std::endl;
  ++mTimesCalled;
  if (mTimesCalled == 7)
  {
    emit killApp();
  }
}


#include "Receiver_moc.cpp"