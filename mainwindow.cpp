#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("RoPlanner");
//    DBManager db("storage.db");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddButton_clicked()
{
    auto taskname = ui->TaskNameEdit_2;
    auto taskdesc = ui->plainTextEdit_2;
    auto table = ui->tabWidget->widget(1)->findChild<QTableWidget*>();
    auto date = ui->Task->findChild<QDateTimeEdit*>();

    bool is_empty = taskname->text().replace(" ", "").isEmpty();
    bool is_empty2 = taskdesc->toPlainText().replace(" ", "").isEmpty();

    int row = table->rowCount();
    int year = date->date().year();
//    int month = date->date().month();
//    int day = date->date().day();

    if (is_empty || is_empty2)
    {
        QMessageBox::warning(this, "Empty", "All fields must not be empty");
        return;
    }

    if (year < QDate::currentDate().year())
    {
        QMessageBox::warning(this, "Date Error", "The date must be the current date or later dates");
        return;
    }

   table->setRowCount(row + 1);
   table->setItem(row, 0, new QTableWidgetItem(taskname->text()));
   table->setItem(row, 1, new QTableWidgetItem(date->dateTime().toString()));
   table->setItem(row, 2, new QTableWidgetItem(taskdesc->toPlainText()));

   taskname->setText("");
   taskdesc->setPlainText("");

    QMessageBox::information(this, "Task Added", "Task successfully added!");
}

// Removes the row that was double clicked on (with a confirmation to prevent accidental deletions!)
void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    // to remove 'unused' warning
    UNUSED(column);

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Task Deletion Confirmation", "Are you sure you want to delete this task?");

    if (reply == QMessageBox::Yes)
        ui->tableWidget->removeRow(row);
}


void MainWindow::on_tableWidget_cellClicked(int row, int column)
{

}
