#ifndef DISMOANNOTATIONMODEL_H
#define DISMOANNOTATIONMODEL_H

#include <QStandardItemModel>
#include "dismo/TokenList.h"

enum DismoAnnotationColum {
    Filename, xMin, xMax,
    TokenMin, POSMin,
    TokenMWU, POSMWU,
    Discourse, Disfluency, Boundary,
    POSExt, Lemma,
    AmbiguityClass, Confidence, Method
};

class DismoAnnotationModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit DismoAnnotationModel(QObject *parent = 0);
    void clear();
    void loadTokenList(const DisMoAnnotator::TokenList &TL, const QString &file = QString());
    // void load(const QString &filename = QString());
private:
    void initialize();
};

#endif // DISMOANNOTATIONMODEL_H
