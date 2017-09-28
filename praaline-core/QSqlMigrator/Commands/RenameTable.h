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
#ifndef COMMANDS_RENAMETABLE_H
#define COMMANDS_RENAMETABLE_H

#include "QSqlMigrator/Commands/BaseCommand.h"

#include <QString>

namespace QSqlMigrator {
namespace Commands {

/*!
 * \brief value object representing the command to rename a table
 */
class QSQLMIGRATOR_DLL_EXPORT RenameTable : public BaseCommand
{
public:
    explicit RenameTable(const QString &name, const QString &newName);
    ~RenameTable() QSQL_OVERRIDE_D {}

    static const QString &typeName();

    const QString &name() const;
    const QString &newName() const;

    CommandPtr reverse() const Q_DECL_OVERRIDE;

private:
    QString m_name;
    QString m_newName;
};

inline const QString &RenameTable::name() const
{
    return m_name;
}

inline const QString &RenameTable::newName() const
{
    return m_newName;
}

} // namespace Commands
} // namespace QSqlMigrator

#endif // COMMANDS_RENAMETABLE_H
