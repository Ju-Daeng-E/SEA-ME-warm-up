#include "mainwindow.h"
#include <QMessageBox>
#include "modeselectdialog.h"

MainWindow::MainWindow(Mode selectedMode, AISpeed selectedSpeed, QWidget *parent)
    : QMainWindow(parent), mode(selectedMode), currentAISpeed(selectedSpeed) {
    setFixedSize(800, 400);
    setFocusPolicy(Qt::StrongFocus);

    background = new QLabel(this);
    background->setPixmap(QPixmap("images/race_track.jpg").scaled(size()));
    background->setGeometry(0, 0, width(), height());

    car1 = new QLabel(this);
    car1->setPixmap(QPixmap("images/car1.png").scaled(100, 50));
    car1->setGeometry(car1_x, 100, 100, 50);

    car2 = new QLabel(this);
    car2->setPixmap(QPixmap("images/car2.png").scaled(100, 50));
    car2->setGeometry(car2_x, 300, 100, 50);

    countdownLabel = new QLabel(this);
    countdownLabel->setStyleSheet("QLabel { color: white; font-size: 48px; background-color: rgba(0, 0, 0, 150); }");
    countdownLabel->setAlignment(Qt::AlignCenter);
    countdownLabel->setGeometry(0, height()/2 - 50, width(), 100);

    retryButton = new QPushButton("Retry", this);
    mainMenuButton = new QPushButton("Main Menu", this);
    retryButton->setGeometry(250, 150, 100, 40);
    mainMenuButton->setGeometry(450, 150, 100, 40);
    retryButton->hide();
    mainMenuButton->hide();
    connect(retryButton, &QPushButton::clicked, this, &MainWindow::retryGame);
    connect(mainMenuButton, &QPushButton::clicked, this, &MainWindow::returnToMainMenu);

    resetGameState();
}

MainWindow::~MainWindow() {}

void MainWindow::resetGameState() {
    car1_x = car2_x = 50;
    car1->move(car1_x, 100);
    car2->move(car2_x, 250);
    activeKeys.clear();
    retryButton->hide();
    mainMenuButton->hide();
    gameOver = false;
    gameStarted = false;
    countdownActive = true;

    QStringList countdownTexts = {"3", "2", "1", "START!"};
    int delay = 0;

    countdownLabel->show();

    for (int i = 0; i < countdownTexts.size(); ++i) {
        QTimer::singleShot(delay, this, [=]() {
            countdownLabel->setText(countdownTexts[i]);
            if (i == countdownTexts.size() - 1) {
                QTimer::singleShot(1000, this, [=]() {
                    countdownLabel->hide();
                    countdownActive = false;
                    gameStarted = true;
                    if (mode == Mode::PVE) startAIMode(currentAISpeed);
                });
            }
        });
        delay += 1000;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (event->isAutoRepeat() || gameOver || !gameStarted) return;

    if (event->key() == Qt::Key_Space) {
        car1_x += 5;
        car1->move(car1_x, 100);
    } else if (mode == Mode::PVP && (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)) {
        car2_x += 5;
        car2->move(car2_x, 250);
    }

    checkWin();
}

void MainWindow::checkWin() {
    if (gameOver) return;
    if (car1_x >= finishLine) {
        gameOver = true;
        if (aiTimer) aiTimer->stop();
        QMessageBox::information(this, "Game Over", "Player 1 wins!");
        showEndButtons();
    } else if (car2_x >= finishLine) {
        gameOver = true;
        if (aiTimer) aiTimer->stop();
        QMessageBox::information(this, "Game Over", "Player 2 wins!");
        showEndButtons();
    }
}

void MainWindow::startAIMode(AISpeed speed) {
    if (aiTimer) {
        aiTimer->stop();
        delete aiTimer;
    }
    aiTimer = new QTimer(this);
    connect(aiTimer, &QTimer::timeout, this, [=]() {
        if (gameOver || !gameStarted) return;
        car2_x += 5;
        car2->move(car2_x, 250);
        checkWin();
    });
    aiTimer->start(static_cast<int>(speed));
}

void MainWindow::showEndButtons() {
    retryButton->show();
    mainMenuButton->show();
}

void MainWindow::retryGame() {
    resetGameState();
}

void MainWindow::returnToMainMenu() {
    this->close();
    ModeSelectDialog dialog;
    if (dialog.exec() == QDialog::Accepted) {
        MainWindow *newGame = new MainWindow(dialog.selectedMode(), dialog.selectedAISpeed());
        newGame->show();
    }
}
