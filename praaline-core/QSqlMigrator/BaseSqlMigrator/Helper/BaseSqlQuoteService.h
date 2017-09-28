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
#ifndef HELPER_BASESQLQUOTESERVICE_H
#define HELPER_BASESQLQUOTESERVICE_H

#include "QSqlMigrator/QSqlMigratorConfig.h"

#include "QSqlMigrator/Helper/QuoteService.h"

#include <QString>

namespace QSqlMigrator {
namespace Helper {

class QSQLMIGRATOR_DLL_EXPORT BaseSqlQuoteService : public QuoteService
{
public:
    BaseSqlQuoteService();
    ~BaseSqlQuoteService() QSQL_OVERRIDE_D {}

    QString quoteTableName(const QString &tableName) const Q_DECL_OVERRIDE;
    QString quoteColumnName(const QString &columnName) const Q_DECL_OVERRIDE;
    QString quoteString(const QString &string) const Q_DECL_OVERRIDE;
};

} // namespace Helper
} // namespace QSqlMigrator

#endif // HELPER_BASESQLQUOTESERVICE_H
