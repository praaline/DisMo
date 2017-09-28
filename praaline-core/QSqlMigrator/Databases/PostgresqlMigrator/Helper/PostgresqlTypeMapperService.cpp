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
#include "PostgresqlTypeMapperService.h"

#include "QSqlMigrator/MigrationTracker/MigrationTrackerService.h"

#include "QSqlMigrator/Structure/Column.h"

#include <QDebug>

namespace QSqlMigrator {
namespace Helper {

PostgresqlTypeMapperService::PostgresqlTypeMapperService()
{
    using namespace Structure;

    m_typeMap.insert(SqlType::Char,      "CHARACTER(%1)");
    m_typeMap.insert(SqlType::VarChar,   "CHARACTER VARYING(%1)");
    m_typeMap.insert(SqlType::Integer,   "INTEGER");
    m_typeMap.insert(SqlType::Time,      "TIME WITHOUT TIME ZONE");
    m_typeMap.insert(SqlType::Timestamp, "TIMESTAMP WITHOUT TIME ZONE");
    m_typeMap.insert(SqlType::Binary,    "BYTEA");
    m_typeMap.insert(SqlType::Decimal,   "NUMERIC(%1,%2)");
}

QString PostgresqlTypeMapperService::map(const Structure::SqlType &type) const
{
    using namespace Structure;

    switch (type.base())
    {
    case SqlType::Integer:
        return m_typeMap[SqlType::Integer];

    default:
        return BaseSqlTypeMapperService::map(type);
    }
}

} // namespace Helper
} // namespace QSqlMigrator
