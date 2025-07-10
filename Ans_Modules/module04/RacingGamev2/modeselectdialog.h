#ifndef MODESELECTDIALOG_H
#define MODESELECTDIALOG_H

#include <QDialog>
#include <QLabel>
enum class Mode { NONE, PVP, PVE };
enum class AISpeed { EASY = 150, NORMAL = 100, HARD = 50 };

class ModeSelectDialog : public QDialog {
    Q_OBJECT
    QLabel *backgroundLabel = nullptr;

public:
    ModeSelectDialog(QWidget *parent = nullptr);
    Mode selectedMode() const;
    AISpeed selectedAISpeed() const;

private:
    Mode mode = Mode::NONE;
    AISpeed aiSpeed = AISpeed::NORMAL;
};

#endif // MODESELECTDIALOG_H
