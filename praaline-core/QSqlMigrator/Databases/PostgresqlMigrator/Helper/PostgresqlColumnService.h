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
#ifndef HELPER_POSTGRESQLCOLUMNSERVICE_H
#define HELPER_POSTGRESQLCOLUMNSERVICE_H

#include "QSqlMigrator/Databases/PostgresqlMigrator/PostgresqlMigrator.h"

#include "QSqlMigrator/Structure/Column.h"
#include "QSqlMigrator/Structure/Index.h"

#include "QSqlMigrator/BaseSqlMigrator/Helper/BaseSqlColumnService.h"

#include <QString>
#include <QHash>

namespace QSqlMigrator {
namespace Helper {

class PostgresqlTypeMapperService;

class PostgresqlColumnService : public BaseSqlColumnService
{
public:
    PostgresqlColumnService(const PostgresqlTypeMapperService& postgresqlTypeMapperService);
    ~PostgresqlColumnService() QSQL_OVERRIDE_D {}

    QString buildColumnTypeSql(const Structure::Column &column) const Q_DECL_OVERRIDE;

    void buildColumnOptionsSql(const Structure::Column &column,
                               const StringOutputFunction &addOption) const Q_DECL_OVERRIDE;
};

} // namespace Helper
} // namespace QSqlMigrator

#endif // HELPER_BASESQLCOLUMNSERVICE_H
