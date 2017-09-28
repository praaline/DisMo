#ifndef ANNOTATIONSTABLEMODEL_H
#define ANNOTATIONSTABLEMODEL_H

#include <QObject>
#include <QStandardItemModel>
#include "corpus/Corpus.h"

class AnnotationsTableModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit AnnotationsTableModel(QObject *parent = 0);
    void clear();
    void loadFromCorpus(Praaline::Core::Corpus *corpus);

private:
    void initialize();
};

#endif // ANNOTATIONSTABLEMODEL_H
