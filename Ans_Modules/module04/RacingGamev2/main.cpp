#include <QApplication>
#include "mainwindow.h"
#include "modeselectdialog.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    ModeSelectDialog dialog;
    if (dialog.exec() == QDialog::Accepted) {
        MainWindow *w = new MainWindow(dialog.selectedMode(), dialog.selectedAISpeed());
        w->show();
        return a.exec();
    }

    return 0;
}
