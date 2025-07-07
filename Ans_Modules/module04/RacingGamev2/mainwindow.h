#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QKeyEvent>
#include <QSet>
#include <QTimer>
#include "modeselectdialog.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(Mode selectedMode, AISpeed selectedSpeed, QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    QLabel *background;
    QLabel *car1;
    QLabel *car2;
    QLabel *countdownLabel;
    QPushButton *retryButton;
    QPushButton *mainMenuButton;

    int car1_x = 50;
    int car2_x = 50;
    const int finishLine = 700;

    Mode mode;
    AISpeed currentAISpeed;
    QSet<int> activeKeys;
    QTimer *aiTimer;

    bool gameOver = false;
    bool gameStarted = false;
    bool countdownActive = false;

    void checkWin();
    void resetGameState();
    void showEndButtons();
    void retryGame();
    void returnToMainMenu();
    void startAIMode(AISpeed speed);
};

#endif // MAINWINDOW_H
