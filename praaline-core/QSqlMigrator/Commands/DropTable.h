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
#ifndef COMMANDS_DROPTABLE_H
#define COMMANDS_DROPTABLE_H

#include "QSqlMigrator/Commands/BaseCommand.h"
#include "QSqlMigrator/Structure/Table.h"

namespace QSqlMigrator {
namespace Commands {

/*!
 * \brief value object representing the command to drop a table
 */
class QSQLMIGRATOR_DLL_EXPORT DropTable : public BaseCommand
{
public:
    explicit DropTable(const QString &name);
    explicit DropTable(const Structure::Table &table);
    ~DropTable() QSQL_OVERRIDE_D {}

    static const QString &typeName();

    const Structure::Table &table() const;
    const QString &tableName() const;

    CommandPtr reverse() const Q_DECL_OVERRIDE;

private:
    Structure::Table m_table;
};

inline const Structure::Table &DropTable::table() const
{
    return m_table;
}

inline const QString &DropTable::tableName() const
{
    return m_table.name();
}

} // namespace Commands
} // namespace QSqlMigrator

#endif // COMMANDS_DROPTABLE_H
