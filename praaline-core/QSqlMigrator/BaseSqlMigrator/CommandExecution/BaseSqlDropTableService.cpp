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
#include "QSqlMigrator/BaseSqlMigrator/CommandExecution/BaseSqlDropTableService.h"

#include "QSqlMigrator/Helper/SqlStructureService.h"
#include "QSqlMigrator/Helper/QuoteService.h"

#include "QSqlMigrator/Commands/DropTable.h"
#include "QSqlMigrator/Commands/CreateTable.h"

#include <QDebug>
#include <QStringList>

namespace QSqlMigrator {
namespace CommandExecution {

BaseSqlDropTableService::BaseSqlDropTableService()
{
}

const QString &BaseSqlDropTableService::commandType() const
{
    return Commands::DropTable::typeName();
}

bool BaseSqlDropTableService::execute(const Commands::DropTable &dropTable, const CommandExecutionContext &context)
{
    const QString dropQuery =
            QString("DROP TABLE %1")
            .arg(context.helperRepository().quoteService().quoteTableName(dropTable.tableName()));

    return CommandExecution::BaseCommandExecutionService::executeQuery(dropQuery, context);
}

bool BaseSqlDropTableService::execute(const Commands::ConstCommandPtr &command,
                                      CommandExecution::CommandExecutionContext &context) const
{
    QSharedPointer<const Commands::DropTable> dropTable(command.staticCast<const Commands::DropTable>());
    Q_ASSERT(dropTable);

    const Structure::Table originalTable( context.helperRepository().sqlStructureService().getTableDefinition(dropTable->tableName(),
                                                                                                              context.database()) );

    bool success = execute(*dropTable, context);

    if (success) {
        context.setUndoCommand(Commands::CommandPtr(new Commands::CreateTable(originalTable)));
    }
    return success;
}

bool BaseSqlDropTableService::isValid(const Commands::ConstCommandPtr &command,
                                      const CommandExecution::CommandExecutionContext &context) const
{
    QSharedPointer<const Commands::DropTable> dropTable(command.staticCast<const Commands::DropTable>());

    //check if tableName is empty
    if (dropTable->tableName().isEmpty()) {
        ::qWarning() << "need to specify a table name!";
        return false;
    }

    //check if table exists
    if (!context.database().tables().contains(dropTable->tableName())) {
        ::qWarning() << "table doesn't exist!";
        return false;
    }

    return true;
}

} // namespace CommandExecution
} // namespace QSqlMigrator
