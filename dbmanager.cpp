#include "dbmanager.h"

// The constructor
DBManager::DBManager(const QString& path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);
    if (!IsGood())
        QMessageBox::warning(new QWidget(), "Connection Failed", "SQLite connection failed. Your data will not save locally");

    // TODO: Finish implementation
}

// Returns whether the database has been opened or not
bool DBManager::IsGood() const
{
    return m_db.isOpen();
}
