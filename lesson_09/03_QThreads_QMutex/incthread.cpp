#include "incthread.h"
#include "commondata.h"

IncThread::IncThread() {

}

IncThread::~IncThread() {

}

void IncThread::run() {

  for(int i = 0; i < 100000; ++i) {
#ifdef USE_MUTEX
    CommonData::mutex.lock();
#endif
    CommonData::data++;
#ifdef USE_MUTEX
    CommonData::mutex.unlock();
#endif
    //msleep(10); // 20 миллисекунд
  }

}

