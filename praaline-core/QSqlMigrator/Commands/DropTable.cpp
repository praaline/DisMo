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
#include "DropTable.h"

#include "QSqlMigrator/Commands/CreateTable.h"

#include <QDebug>

namespace QSqlMigrator {
namespace Commands {

DropTable::DropTable(const QString &name) :
    BaseCommand(DropTable::typeName()),
    m_table(Structure::Table(name, Structure::ColumnList()))
{
    if(name.isEmpty()) {
        ::qWarning() << QSQLMIGRATOR_LOG_PREFIX << DropTable::typeName() << "command with empty name!";
    }
}

DropTable::DropTable(const Structure::Table &table) :
    BaseCommand(DropTable::typeName()),
    m_table(table)
{
    if (!m_table.isValid()) {
        ::qWarning() << QSQLMIGRATOR_LOG_PREFIX << DropTable::typeName() << "command with invalid table!";
    }
}

const QString &DropTable::typeName()
{
    static QString typeName("DropTable");
    return typeName;
}

CommandPtr DropTable::reverse() const
{
    if (!m_table.isValid())
        return CommandPtr();
    return CommandPtr(new CreateTable(table()));
}

} // namespace Commands
} // namespace QSqlMigrator

