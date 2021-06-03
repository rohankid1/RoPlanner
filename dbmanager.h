#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QtSql>
#include <QMessageBox>

class DBManager
{
public:
    DBManager(const QString& path);
    bool IsGood() const;

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
