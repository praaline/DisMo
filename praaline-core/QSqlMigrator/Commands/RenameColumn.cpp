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
#include "RenameColumn.h"

#include <QDebug>

namespace QSqlMigrator {
namespace Commands {

RenameColumn::RenameColumn(const QString &name, const QString &newName, const QString &tableName) :
    BaseCommand(RenameColumn::typeName()),
    m_oldName(name),
    m_newName(newName),
    m_tableName(tableName)
{
    if(name.isEmpty()) {
        ::qWarning() << QSQLMIGRATOR_LOG_PREFIX << RenameColumn::typeName()
                     << "command with empty name!";
    }

    if(newName.isEmpty()) {
        ::qWarning() << QSQLMIGRATOR_LOG_PREFIX << RenameColumn::typeName()
                     << "command" << name << "with empty newName!";
    }

    if(tableName.isEmpty()) {
        ::qWarning() << QSQLMIGRATOR_LOG_PREFIX << RenameColumn::typeName()
                     << "command" << name << "with empty tableName!";
    }
}

const QString &RenameColumn::typeName()
{
    static QString typeName("RenameColumn");
    return typeName;
}

CommandPtr RenameColumn::reverse() const
{
    return CommandPtr(new RenameColumn(newName(), oldName(), tableName()));
}

} // namespace Commands
} // namespace QSqlMigrator
