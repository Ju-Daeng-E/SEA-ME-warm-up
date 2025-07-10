#include "modeselectdialog.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug> // for qDebug()

ModeSelectDialog::ModeSelectDialog(QWidget *parent)
    : QDialog(parent) {

    setWindowTitle("Select Game Mode");
    setFixedSize(600, 400);

    backgroundLabel = new QLabel(this);
    QPixmap introPixmap("images/Intro.png");
    if (introPixmap.isNull())
        qDebug() << "❌ Intro image not found at images/Intro.png";

    backgroundLabel->setPixmap(introPixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    backgroundLabel->setGeometry(0, 0, width(), height());
    backgroundLabel->lower();

    // 버튼 생성
    auto *pvpBtn = new QPushButton("Player 1 vs Player 2");
    auto *pveBtn = new QPushButton("Player 1 vs AI");

    pvpBtn->setStyleSheet("font-size: 16px; padding: 8px;");
    pveBtn->setStyleSheet("font-size: 16px; padding: 8px;");

    // 레이아웃 설정
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch();  // 위 공간 확보

    auto *bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(pvpBtn);
    bottomLayout->addWidget(pveBtn);
    bottomLayout->addStretch();  // 오른쪽 여백 밀어냄

    mainLayout->addLayout(bottomLayout);
    mainLayout->setContentsMargins(10, 10, 50, 50);  // 여백 설정
    setLayout(mainLayout);


    connect(pvpBtn, &QPushButton::clicked, this, [this]() {
        mode = Mode::PVP;
        accept();
    });
    connect(pveBtn, &QPushButton::clicked, this, [this]() {
        QDialog diffDialog(this);
        diffDialog.setWindowTitle("Select AI Difficulty");
        diffDialog.setFixedSize(300, 200);

        QVBoxLayout *layout = new QVBoxLayout(&diffDialog);
        QLabel *label = new QLabel("Select AI Difficulty:");
        QPushButton *easy = new QPushButton("Easy");
        QPushButton *normal = new QPushButton("Normal");
        QPushButton *hard = new QPushButton("Hard");

        layout->addWidget(label);
        layout->addWidget(easy);
        layout->addWidget(normal);
        layout->addWidget(hard);

        connect(easy, &QPushButton::clicked, &diffDialog, [this, &diffDialog]() {
            aiSpeed = AISpeed::EASY;
            mode = Mode::PVE;
            diffDialog.accept();
        });
        connect(normal, &QPushButton::clicked, &diffDialog, [this, &diffDialog]() {
            aiSpeed = AISpeed::NORMAL;
            mode = Mode::PVE;
            diffDialog.accept();
        });
        connect(hard, &QPushButton::clicked, &diffDialog, [this, &diffDialog]() {
            aiSpeed = AISpeed::HARD;
            mode = Mode::PVE;
            diffDialog.accept();
        });

        if (diffDialog.exec() == QDialog::Accepted)
            accept();
    });
}

Mode ModeSelectDialog::selectedMode() const {
    return mode;
}

AISpeed ModeSelectDialog::selectedAISpeed() const {
    return aiSpeed;
}
