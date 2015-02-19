#include "decthread.h"
#include "commondata.h"

DecThread::DecThread() {

}

DecThread::~DecThread() {

}

void DecThread::run() {

  for(int i = 0; i < 100000; ++i) {
#ifdef USE_MUTEX
    CommonData::mutex.lock();
#endif
    CommonData::data--;
#ifdef USE_MUTEX
    CommonData::mutex.unlock();
#endif

    //msleep(20); // 20 миллисекунд
  }

}
