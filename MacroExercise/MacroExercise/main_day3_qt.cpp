#include "AB/common.hpp"

WF_MSW_DISABLE(MSW_STL)
#include <iostream>
WF_MSW_RESTORE()

WF_MSW_DISABLE(MSW_QT)
#include <QtCore/QVector>
#include <QtCore/QString>
#include <QtCore/QDebug>
#include <QtCore/QElapsedTimer>
WF_MSW_RESTORE()

#include "AB/logger.hpp"


int main()
{
  QElapsedTimer lElapsedTimer;
  lElapsedTimer.start();

  QVector<QString> lVector;
  lVector << "This element has value " + QString::number(5);

  qDebug() << lVector;

  std::cout << lElapsedTimer.nsecsElapsed() << std::endl;

}