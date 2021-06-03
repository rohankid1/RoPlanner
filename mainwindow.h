#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define UNUSED(x) (void)x

#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidget>
#include <QFileInfo>
#include <QDate>
#include <QDateTimeEdit>

#include "dbmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddButton_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
