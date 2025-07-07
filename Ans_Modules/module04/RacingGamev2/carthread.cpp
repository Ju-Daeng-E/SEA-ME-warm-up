#include "carthread.h"
#include <QThread>

CarThread::CarThread(int start, int finish, int delayMs)
    : x(start), finish(finish), delay(delayMs) {}

void CarThread::run() {
    while (x < finish) {
        QThread::msleep(delay);
        x += 5;
        emit positionUpdated(x);
    }
    emit finished();
}
