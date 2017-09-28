#include "LocalSchemeComparisonService.h"

#include "QSqlMigrator/LocalSchemeMigrator/LocalSchemeComparisonContext.h"

#include "QSqlMigrator/Helper/ColumnService.h"
#include "QSqlMigrator/Helper/SqlStructureService.h"
#include "QSqlMigrator/Helper/TypeMapperService.h"

#include "QSqlMigrator/Structure/Table.h"

#include <QDebug>
#include <QStringList>

namespace QSqlMigrator {
namespace LocalSchemeMigrator {

LocalSchemeComparisonService::LocalSchemeComparisonService()
{
}

bool LocalSchemeComparisonService::compareLocalSchemeWithDatabase(const LocalSchemeComparisonContext &context) const
{
    bool success = true;

    foreach (const Structure::Table &table, context.localScheme()->tables().values()) {
        Structure::Table realTable = context.helperRepository().sqlStructureService().getTableDefinition(table.name(), context.database());
        if (realTable.columns().length() != table.columns().length()) {
            qWarning() << QSQLMIGRATOR_LOG_PREFIX << "columns count doesn't match";
            success = false;
        }
        for (int i=0; i<table.columns().length(); i++) {
            const Structure::Column &realColumn = realTable.columns().at(i);
            const Structure::Column &column = table.columns().at(i);

            if (realColumn.name() != column.name()) {
                qWarning() << QSQLMIGRATOR_LOG_PREFIX << "table" << table.name()
                           << "column" << column.name() << "is not named" << realColumn.name();
                success = false;
            }
            if (realColumn.hasDefaultValue() != column.hasDefaultValue()) {
                if (column.hasDefaultValue())
                    qWarning() << QSQLMIGRATOR_LOG_PREFIX << "table" << table.name()
                               << "column" << column.name() << "has a default value of" << column.defaultValue();
                else
                    qWarning() << QSQLMIGRATOR_LOG_PREFIX << "table" << table.name()
                               << "column" << column.name() << "has not a default value of" << realColumn.defaultValue();
                success = false;
            } else if (realColumn.defaultValue() != column.defaultValue() ){
                qWarning() << QSQLMIGRATOR_LOG_PREFIX << "table" << table.name()
                           << "column" << column.name() << "has a default value of" << column.defaultValue() << ", while real column has one of" << realColumn.defaultValue();
                success = false;
            }
            {
                QString sqlTypeString = context.helperRepository().typeMapperService().map(column.type());
                if(0 != QString::compare(sqlTypeString, realColumn.type().string(), Qt::CaseInsensitive)) {
                    qWarning() << QSQLMIGRATOR_LOG_PREFIX << "table" << table.name()
                               << "column" << column.name() << "is of type" << sqlTypeString << ", while real column is of type" << realColumn.type().string();
                    success = false;
                }
            }
            if (realColumn.isAutoIncremented() != column.isAutoIncremented()) {
                qWarning() << QSQLMIGRATOR_LOG_PREFIX << "table" << table.name()
                           << "column" << column.name() << "has auto increment set to" << column.isAutoIncremented() << ", while real column has it set to" << realColumn.isAutoIncremented();
                success = false;
            }
            if (realColumn.isNullable() != column.isNullable()) {
                qWarning() << QSQLMIGRATOR_LOG_PREFIX << "table" << table.name()
                           << "column" << column.name() << "has nullability set to" << column.isNullable() << ", while real column has it set to" << realColumn.isNullable();
                success = false;
            }
            if (realColumn.isPrimary() != column.isPrimary()) {
                qWarning() << QSQLMIGRATOR_LOG_PREFIX << "table" << table.name()
                           << "column" << column.name() << "has primary set to" << column.isPrimary() << ", while real column has it set to" << realColumn.isPrimary();
                success = false;
            }
            if (realColumn.isUnique() != column.isUnique()) {
                qWarning() << QSQLMIGRATOR_LOG_PREFIX << "table" << table.name()
                           << "column" << column.name() << "has uniqueness set to" << column.isUnique() << ", while real column has it set to" << realColumn.isUnique();
                success = false;
            }
        }
    }
    foreach (const Structure::Index &index, context.localScheme()->indices()) {
        Structure::Index realIndex = context.helperRepository().sqlStructureService().getIndexDefinition(index.name(), index.tableName(), context.database());
        if (index.columns() != realIndex.columns()) {
            qWarning() << QSQLMIGRATOR_LOG_PREFIX << "table" << index.tableName()
                       << "index" << index.name() << "have different columns";
            qWarning() << QSQLMIGRATOR_LOG_PREFIX << "table" << index.tableName()
                       << "local scheme index:" << context.helperRepository().columnService().generateIndexColumnsDefinitionSql(index.columns());
            qWarning() << QSQLMIGRATOR_LOG_PREFIX << "table" << index.tableName()
                       << "real index:" << context.helperRepository().columnService().generateIndexColumnsDefinitionSql(realIndex.columns());
            success = false;
        }
    }

    return success;
}

} // namespace LocalSchemeMigrator
} // namespace QSqlMigrator
