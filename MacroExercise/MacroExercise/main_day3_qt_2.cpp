#include "AB/common.hpp"

WF_MSW_DISABLE(MSW_STL)
#include <iostream>
WF_MSW_RESTORE()

#include "Sender.hpp"
#include "Receiver.hpp"

WF_MSW_DISABLE(MSW_QT)
#include <QtCore/QVector>
#include <QtCore/QString>
#include <QtCore/QDebug>
#include <QtCore/QElapsedTimer>
#include <QtCore/QTimer>
#include <QtCore/QCoreApplication>
//#include <QtGui/QApplication>

#include <QtCore/QThread>

WF_MSW_RESTORE()

int main(int argc, char** argv)
{
  /* 1 */
  //QCoreApplication app(argc, argv);
  //
  //Receiver lReceiver(42);

  //QTimer lTimer;

  //QObject::connect(&lTimer, SIGNAL(timeout()), &lReceiver, SLOT(doWork()));

  //QObject::connect(&lReceiver, SIGNAL(killApp()), &app, SLOT(quit()));

  ////lTimer.setInterval(1000);
  //lTimer.start(1000);

  ////QTimer::singleShot(1000, &lReceiver, SLOT(doWork()));
  ////QTimer::singleShot(7000, &app, SLOT(quit()));

  //int result = app.exec();
  //return result;

  /* 2 */
  //QCoreApplication app(argc, argv);

  //Sender lSender;
  //Receiver lReceiver(42);

  //QObject::connect(&lSender, SIGNAL(dataReady(const QString&, bool)), &lReceiver, SLOT(doMoreWork(const QString&, bool)));
  //
  //int result = app.exec();
  //return result;

  /* 3 */
  QCoreApplication app(argc, argv);

  Sender lSender;
  Receiver lReceiver(42);

  QThread lThread;
  lSender.moveToThread(&lThread);
  lThread.start();

  QObject::connect(&lSender, SIGNAL(dataReady(const QString&, bool)), &lReceiver, SLOT(doMoreWork(const QString&, bool)));

  int result = app.exec();
  return result;

}