#ifndef _AB_SENDER_HPP_
#define _AB_SENDER_HPP_

#ifndef  _AB_COMMON_HPP_
#include "AB/common.hpp"
#endif // ! _AB_COMMON_HPP_

WF_MSW_DISABLE(MSW_QT MSW_STL)
#ifndef QOBJECT_H
#include<QtCore/QObject>
#endif

#ifndef QTIMER_H
#include<QtCore/QTimer>
#endif
WF_MSW_RESTORE()

class Sender : public QObject 
{
  Q_OBJECT

    // TYPES

    // MEMBERS
private:
  QTimer mTimer;

    // METHODS

private:
  Q_DISABLE_COPY(Sender);

  private slots:
  void internalWorker();

signals:
  void dataReady(const QString&, bool);

public:
  inline explicit Sender(QObject* parent = 0) :
    QObject(parent),
    mTimer(this)
  {
    mTimer.setParent(this);
    QObject::connect(&mTimer, SIGNAL(timeout()), this, SLOT(internalWorker()));
    mTimer.start(800);
  }

};


#endif // !_AB_SENDER_HPP_
