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
#ifndef HELPER_BASESQLTYPEMAPPERSERVICE_H
#define HELPER_BASESQLTYPEMAPPERSERVICE_H

#include "QSqlMigrator/QSqlMigratorConfig.h"

#include "QSqlMigrator/Helper/TypeMapperService.h"

#include "QSqlMigrator/Structure/SqlType.h"

#include <QString>

namespace QSqlMigrator {
namespace Helper {

/*!
 * \brief standard sql type mapping implementation
 */
class QSQLMIGRATOR_DLL_EXPORT BaseSqlTypeMapperService : public TypeMapperService
{
public:
    BaseSqlTypeMapperService();
    ~BaseSqlTypeMapperService() QSQL_OVERRIDE_D {}

    QString map(const Structure::SqlType &type) const Q_DECL_OVERRIDE;

protected:
    QHash<Structure::SqlType::Base, QString> m_typeMap;
};

} // namespace Helper
} // namespace QSqlMigrator

#endif // HELPER_BASESQLTYPEMAPPERSERVICE_H
