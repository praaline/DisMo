#include <QString>
#include <QStringList>
#include <QStandardItemModel>

#include "corpus/Corpus.h"
#include "corpus/CorpusObject.h"
#include "corpus/CorpusCommunication.h"
#include "corpus/CorpusAnnotation.h"
using namespace Praaline::Core;

#include "AnnotationsTableModel.h"

AnnotationsTableModel::AnnotationsTableModel(QObject *parent)
    : QStandardItemModel(parent)
{
    initialize();
}

void AnnotationsTableModel::initialize()
{
    setHorizontalHeaderLabels(QStringList()
        << tr("Annotation ID") << tr("Type") << tr("Communication ID")
        << tr("Tier to annotate")
    );
}

void AnnotationsTableModel::clear()
{
    QStandardItemModel::clear();
    initialize();
}

void AnnotationsTableModel::loadFromCorpus(Corpus *corpus)
{
    QList<QStandardItem *> tableRecord;
    foreach (CorpusCommunication *com, corpus->communications()) {
        QString comName = com->ID();
        foreach (CorpusAnnotation *annot, com->annotations()) {
            QString type;
            if (annot->filename().endsWith("textgrid", Qt::CaseInsensitive))
                type = "TextGrid";
            else if (annot->filename().endsWith("txt", Qt::CaseInsensitive))
                type = "Table File";
            else
                continue;
            tableRecord << new QStandardItem(annot->ID());
            tableRecord << new QStandardItem(type);
            tableRecord << new QStandardItem(comName);
            tableRecord << new QStandardItem(annot->property("DismoTier").toString());
            // Add record to table and continue
            appendRow(tableRecord);
            tableRecord.clear();
        }
    }
}
