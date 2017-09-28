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
#ifndef COMMANDEXECUTION_COMMANDEXECUTIONCONTEXT_H
#define COMMANDEXECUTION_COMMANDEXECUTIONCONTEXT_H

#include "QSqlMigrator/Commands/BaseCommand.h"
#include "QSqlMigrator/MigrationExecution/MigrationExecutionConfig.h"
#include "QSqlMigrator/Helper/HelperRepository.h"
#include "QSqlMigrator/QSqlMigratorConfig.h"

#include <QSqlDatabase>

namespace QSqlMigrator {
namespace CommandExecution {

class QSQLMIGRATOR_DLL_EXPORT CommandExecutionContext
{
public:
    CommandExecutionContext(const QSqlDatabase database,
                            const MigrationExecution::MigrationExecutionConfig &migrationConfig,
                            const Helper::HelperRepository &helperRepository);

    QSqlDatabase database() const;

    //TODO: undo-logic in own class
    //! \return true, when undo command will be used
    bool isUndoUsed() const;
    Commands::CommandPtr currentUndoCommand() const;
    const MigrationExecution::MigrationExecutionConfig &migrationConfig() const;
    const Helper::HelperRepository &helperRepository() const;

    void setIsUndoUsed(bool isUndoUsed);
    void setUndoCommand(Commands::CommandPtr command);
    void resetUndoCommand();

private:
    QSqlDatabase m_database;
    const MigrationExecution::MigrationExecutionConfig m_migrationConfig;
    const Helper::HelperRepository m_helperRepository;

    bool m_isUndoUsed;
    Commands::CommandPtr m_currentUndoCommand;
};

} // namespace CommandExecution
} // namespace QSqlMigrator

#endif // COMMANDEXECUTION_COMMANDEXECUTIONCONTEXT_H
