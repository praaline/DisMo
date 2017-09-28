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
#ifndef HELPER_FIREBIRSQLSTRUCTURESERVICE_H
#define HELPER_FIREBIRSQLSTRUCTURESERVICE_H

#include "QSqlMigrator/Helper/SqlStructureService.h"

#include "QSqlMigrator/CommandExecution/CommandExecutionContext.h"

namespace QSqlMigrator {

namespace Structure {
class Table;
class Index;
}

namespace Helper {

class FirebirdSqlStructureService : public SqlStructureService
{
public:
    FirebirdSqlStructureService();
    ~FirebirdSqlStructureService() QSQL_OVERRIDE_D {}

    Structure::Table getTableDefinition(const QString &tableName,
                                        QSqlDatabase database) const Q_DECL_OVERRIDE;

    Structure::Index getIndexDefinition(const QString &indexName,
                                        const QString &tableName,
                                        QSqlDatabase database) const Q_DECL_OVERRIDE;
};

} // namespace Helper

} // namespace QSqlMigrator

#endif // HELPER_FIREBIRSQLSTRUCTURESERVICE_H
