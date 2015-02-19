#ifndef COMMONDATA_H
#define COMMONDATA_H

#include <QMutex>

//#define USE_MUTEX

class CommonData {
 public:
  static int data;
  static QMutex mutex;
};


#endif // COMMONDATA_H
