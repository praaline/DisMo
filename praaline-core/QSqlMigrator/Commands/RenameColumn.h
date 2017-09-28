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
#ifndef COMMANDS_RENAMECOLUMN_H
#define COMMANDS_RENAMECOLUMN_H

#include "QSqlMigrator/Commands/BaseCommand.h"

#include <QString>

namespace QSqlMigrator {
namespace Commands {

/*!
 * \brief value object representing the command to rename a column of a table
 */
class QSQLMIGRATOR_DLL_EXPORT RenameColumn : public BaseCommand
{
public:
    explicit RenameColumn(const QString &oldName, const QString &newName, const QString &tableName);
    ~RenameColumn() QSQL_OVERRIDE_D {}

    static const QString &typeName();

    const QString &oldName() const;
    const QString &newName() const;
    const QString &tableName() const;

    CommandPtr reverse() const Q_DECL_OVERRIDE;

private:
    const QString m_oldName;
    const QString m_newName;
    const QString m_tableName;
};

inline const QString &RenameColumn::oldName() const
{
    return m_oldName;
}

inline const QString &RenameColumn::newName() const
{
    return m_newName;
}

inline const QString &RenameColumn::tableName() const
{
    return m_tableName;
}

} // namespace Commands
} // namespace QSqlMigrator

#endif // COMMANDS_RENAMECOLUMN_H
