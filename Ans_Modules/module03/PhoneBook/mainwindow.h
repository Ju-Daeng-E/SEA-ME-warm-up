// mainwindow.h
#include <QMainWindow>
#include "contactlist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
    ContactList contactList;

    void refreshList(const QList<Contact>& list);
};
