#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//     disconnect(ui->addButton, nullptr, nullptr, nullptr);  // 모든 연결 해제

//     connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
//     connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::on_removeButton_clicked);
//     connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);
 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    Contact c(
        ui->nameEdit->text(),     // name
        ui->phoneEdit->text(),   // phone
        ui->emailEdit->text()    // email
        );

    contactList.addContact(c);
    refreshList(contactList.getAllContacts());
}

void MainWindow::on_removeButton_clicked()
{
    int row = ui->listWidget->currentRow();
    if (row >= 0) {
        contactList.removeContact(row);
        refreshList(contactList.getAllContacts());
    }
}

void MainWindow::on_searchButton_clicked()
{
    QString keyword = ui->nameEdit->text(); // 이름 검색만
    QList<Contact> result = contactList.searchByName(keyword);
    refreshList(result);
}

void MainWindow::refreshList(const QList<Contact> &list)
{
    ui->listWidget->clear();
    for (const Contact &c : list) {
        ui->listWidget->addItem(c.getName() + " | " + c.getPhone() + " | " + c.getEmail());
    }
}
