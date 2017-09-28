/****************************************************************************
**
** Copyright (C) 2013, HicknHack Software
** All rights reserved.
** Contact: http://www.hicknhack-software.com/contact
**
** This file is part of the QSqlMigrator
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL3 included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
****************************************************************************/
#include "BaseMigrationTableService.h"

#include "QSqlMigrator/Helper/QuoteService.h"

#include "QSqlMigrator/MigrationExecution/MigrationExecutionContext.h"

#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

namespace QSqlMigrator {
namespace MigrationTracker {

bool BaseMigrationTableService::canRevertStrucuturalChangesUsingTransactions() const
{
    return false;
}

bool BaseMigrationTableService::wasMigrationExecuted(const QString &migrationName,
                                                     const CommandExecution::CommandExecutionContext &context) const
{
    return this->migrationList(context).contains(migrationName);
}

QStringList BaseMigrationTableService::migrationList(const CommandExecution::CommandExecutionContext &context) const
{
    const QString versionTableName = context.migrationConfig().migrationVersionTableName;
    QSqlQuery sqlQuery = context.database().exec(
                QString("SELECT version FROM %1")
                .arg(context.helperRepository().quoteService().quoteTableName(versionTableName)));

    QStringList migrationList;
    if (sqlQuery.lastError().isValid()) {
        ::qDebug() << Q_FUNC_INFO << sqlQuery.lastError().text();
    } else {
        while (sqlQuery.next()) {
            migrationList << sqlQuery.value(0).toString();
        }
    }
    return migrationList;
}

bool BaseMigrationTableService::addMigration(const QString &migrationName,
                                             const CommandExecution::CommandExecutionContext &context) const
{
    const QString versionTableName = context.migrationConfig().migrationVersionTableName;
    const QString query =
            QString("INSERT INTO %1 (version) VALUES (%2)")
            .arg(context.helperRepository().quoteService().quoteTableName(versionTableName))
            .arg(context.helperRepository().quoteService().quoteString(migrationName));

    ::qDebug() << "adding entry to version table. complete query looks like:";
    ::qDebug() << query;
    QSqlQuery sqlQuery = context.database().exec(query);
    if (sqlQuery.lastError().isValid()) {
        ::qDebug() << Q_FUNC_INFO << sqlQuery.lastError().text();
        return false;
    }
    return true;
}

bool BaseMigrationTableService::removeMigration(const QString &migrationName,
                                                const CommandExecution::CommandExecutionContext &context) const
{
    const QString versionTableName = context.migrationConfig().migrationVersionTableName;
    const QString query =
            QString("DELETE FROM %1 WHERE version = %2")
            .arg(context.helperRepository().quoteService().quoteTableName(versionTableName))
            .arg(context.helperRepository().quoteService().quoteString(migrationName));
    ::qDebug() << "removing entry to version table. complete query looks like:";
    ::qDebug() << query;
    QSqlQuery sqlQuery = context.database().exec(query);
    if (sqlQuery.lastError().isValid()) {
        ::qDebug() << Q_FUNC_INFO << sqlQuery.lastError().text();
        return false;
    }
    return true;
}

bool BaseMigrationTableService::prepare(const MigrationExecution::MigrationExecutionContext &context) const
{
    QStringList tables = context.database().tables(QSql::AllTables);
    QString versionTableName = context.migrationConfig().migrationVersionTableName;
    if(!tables.contains(versionTableName)) {
        const QString query =
                QString("CREATE TABLE %1 (version VARCHAR(255) NOT NULL, PRIMARY KEY (version))")
                .arg(context.helperRepository().quoteService().quoteTableName(versionTableName));
        ::qDebug() << "creating migrationVersion table! query looks like:";
        ::qDebug() << query;
        QSqlQuery sqlQuery = context.database().exec(query);
        if (sqlQuery.lastError().isValid())
        {
            ::qDebug() << Q_FUNC_INFO << sqlQuery.lastError().text();
            return false;
        }
    }
    return true;
}

} // namespace MigrationTracker
} // namespace QSqlMigrator
