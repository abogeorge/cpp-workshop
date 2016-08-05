#ifndef _AB_RECEIVER_HPP_
#define _AB_RECEIVER_HPP_

#ifndef  _AB_COMMON_HPP_
#include "AB/common.hpp"
#endif // ! _AB_COMMON_HPP_

WF_MSW_DISABLE(MSW_QT MSW_STL)
#ifndef QOBJECT_H
#include<QtCore/QObject>
#endif
WF_MSW_RESTORE()

class Receiver : public QObject 
{
  Q_OBJECT

    // TYPES

    // MEMBERS
private:
  int mValue;
  int mTimesCalled;
    // METHODS

private:
  Q_DISABLE_COPY(Receiver);

signals:
  void killApp();

public:
  inline explicit Receiver(int pValue = -3, QObject* parent = 0) :
    QObject(parent),
    mValue(pValue),
    mTimesCalled(0)
  {
  }

  public slots:
  void doWork();
  void doMoreWork(const QString&, bool);


};


#endif // !_AB_RECEIVER_HPP_
