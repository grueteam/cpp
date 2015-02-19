#include <QCoreApplication>
#include "incthread.h"
#include "decthread.h"
#include "commondata.h"
#include <QDebug>
#include <QThread>

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  for(int i = 0; i < 1000; ++i) {
    CommonData::data = 0;
    IncThread it;
    DecThread dt;
    it.start();
    dt.start();

    it.wait();
    dt.wait();

    qDebug() << CommonData::data;

    //QThread::currentThread()->sleep(1);
  }

  return 0; // a.exec();
}
