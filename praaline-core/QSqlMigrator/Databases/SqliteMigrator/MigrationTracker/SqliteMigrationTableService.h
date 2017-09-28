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
#ifndef MIGRATIONTRACKER_SQLITEMIGRATIONTABLESERVICE_H
#define MIGRATIONTRACKER_SQLITEMIGRATIONTABLESERVICE_H

#include "QSqlMigrator/BaseSqlMigrator/MigrationTracker/BaseMigrationTableService.h"
#include "QSqlMigrator/Databases/SqliteMigrator/SqliteMigrator.h"

namespace QSqlMigrator {
namespace MigrationTracker {

class SqliteMigrationTableService : public MigrationTracker::BaseMigrationTableService
{
public:
    SqliteMigrationTableService();
    ~SqliteMigrationTableService() QSQL_OVERRIDE_D {}

    bool canRevertStrucuturalChangesUsingTransactions() const Q_DECL_OVERRIDE;
};

} // namespace MigrationTracker
} // namespace QSqlMigrator

#endif // MIGRATIONTRACKER_SQLITEMIGRATIONTABLESERVICE_H
