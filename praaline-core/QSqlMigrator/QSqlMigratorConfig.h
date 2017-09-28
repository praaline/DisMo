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
#ifndef QSQLMIGRATOR_CONFIG_H
#define QSQLMIGRATOR_CONFIG_H

#define QSQLMIGRATOR_VERSION "1.0.0"
#define QSQLMIGRATOR_LOG_PREFIX "[QSqlMigrator] "

#include <Qt>
#include <QtCore/qglobal.h>

//#if defined(_BUILDING_QSQLMIGRATOR_DLL)
//#  define QSQLMIGRATOR_DLL_EXPORT Q_DECL_EXPORT
//#else
//#  define QSQLMIGRATOR_DLL_EXPORT Q_DECL_IMPORT
//#endif
#define QSQLMIGRATOR_DLL_EXPORT

#ifndef Q_DECL_OVERRIDE
#   define Q_DECL_OVERRIDE
#endif
#if _MSC_VER >= 1700
#   define QSQL_OVERRIDE_D Q_DECL_OVERRIDE
#else
#   define QSQL_OVERRIDE_D
#endif

#ifndef Q_NULLPTR
#   define Q_NULLPTR 0
#endif

#endif // QSQLMIGRATOR_CONFIG_H
