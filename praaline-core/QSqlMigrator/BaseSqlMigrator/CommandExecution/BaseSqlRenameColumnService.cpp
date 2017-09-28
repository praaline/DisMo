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
#include "QSqlMigrator/BaseSqlMigrator/CommandExecution/BaseSqlRenameColumnService.h"

#include "QSqlMigrator/Helper/QuoteService.h"

#include "QSqlMigrator/Commands/RenameColumn.h"

#include "QSqlMigrator/Structure/Table.h"

#include <QDebug>
#include <QStringList>
#include <QScopedPointer>

using namespace QSqlMigrator::Structure;

namespace QSqlMigrator {
namespace CommandExecution {

BaseSqlRenameColumnService::BaseSqlRenameColumnService()
{
}

const QString &BaseSqlRenameColumnService::commandType() const
{
    return Commands::RenameColumn::typeName();
}

bool BaseSqlRenameColumnService::execute(const Commands::RenameColumn &renameColumn,
                                         const CommandExecutionContext &context)
{
    const QString alterQuery =
            QString("ALTER TABLE %1 RENAME COLUMN %2 TO %3")
            .arg(context.helperRepository().quoteService().quoteTableName(renameColumn.tableName()))
            .arg(context.helperRepository().quoteService().quoteColumnName(renameColumn.oldName()))
            .arg(context.helperRepository().quoteService().quoteColumnName(renameColumn.newName()));

    return CommandExecution::BaseCommandExecutionService::executeQuery(alterQuery, context);
}

bool BaseSqlRenameColumnService::execute(const Commands::ConstCommandPtr &command,
                                         CommandExecution::CommandExecutionContext &context) const
{
    QSharedPointer<const Commands::RenameColumn> renameColumn(command.staticCast<const Commands::RenameColumn>());
    Q_ASSERT(renameColumn);

    bool success = execute(*renameColumn, context);

    if (success && context.isUndoUsed()) {
        context.setUndoCommand(renameColumn->reverse());
    }
    return success;
}

bool BaseSqlRenameColumnService::isValid(const Commands::ConstCommandPtr &command,
                                         const CommandExecution::CommandExecutionContext &context) const
{
    QSharedPointer<const Commands::RenameColumn> renameColumn(command.staticCast<const Commands::RenameColumn>());

    //check if table exists
    if (!context.database().tables().contains(renameColumn->tableName())) {
        ::qWarning() << "table doesn't exist!";
        return false;
    }
    return true;
}

} // namespace CommandExecution
} // namespace QSqlMigrator

