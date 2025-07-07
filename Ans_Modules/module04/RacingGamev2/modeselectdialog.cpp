#include "modeselectdialog.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

ModeSelectDialog::ModeSelectDialog(QWidget *parent)
    : QDialog(parent) {
    setWindowTitle("Select Game Mode");
    setFixedSize(300, 250);

    auto *layout = new QVBoxLayout(this);
    auto *pvpBtn = new QPushButton("Player 1 vs Player 2");
    auto *pveBtn = new QPushButton("Player 1 vs AI");

    layout->addWidget(pvpBtn);
    layout->addWidget(pveBtn);

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
