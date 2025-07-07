#ifndef CARTHREAD_H
#define CARTHREAD_H

#include <QObject>

class CarThread : public QObject {
    Q_OBJECT

public:
    CarThread(int start, int finish, int delayMs = 100);

private:
    int delay;

public slots:
    void run();

signals:
    void positionUpdated(int);
    void finished();

private:
    int x;
    int finish;
};

#endif // CARTHREAD_H
