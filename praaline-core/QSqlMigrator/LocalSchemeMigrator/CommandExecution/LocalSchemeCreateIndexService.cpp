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
#include "QSqlMigrator/LocalSchemeMigrator/CommandExecution/LocalSchemeCreateIndexService.h"

#include "QSqlMigrator/Commands/CreateIndex.h"
#include "QSqlMigrator/Commands/DropIndex.h"

#include <QDebug>

namespace QSqlMigrator {
namespace CommandExecution {

LocalSchemeCreateIndexService::LocalSchemeCreateIndexService()
{
}

const QString &LocalSchemeCreateIndexService::commandType() const
{
    return Commands::CreateIndex::typeName();
}

bool LocalSchemeCreateIndexService::execute(const Commands::ConstCommandPtr &command,
                                            CommandExecution::LocalSchemeCommandExecutionContext &context) const
{
    QSharedPointer<const Commands::CreateIndex> createIndex(command.staticCast<const Commands::CreateIndex>());

    context.localScheme()->createIndex(createIndex->index());

    return true;
}

bool LocalSchemeCreateIndexService::isValid(const Commands::ConstCommandPtr &command,
                                            const CommandExecution::LocalSchemeCommandExecutionContext &context) const
{
    Q_UNUSED(context);
    QSharedPointer<const Commands::CreateIndex> createIndex(command.staticCast<const Commands::CreateIndex>());

    if (createIndex->index().columns().size() < 1) {
        ::qWarning() << "at least one Column name must be specified to create an index!";
        return false;
    }
    return true;
}

} // namespace CommandExecution
} // namespace QSqlMigrator
