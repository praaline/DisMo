#include <QString>
#include <QStringList>
#include <QStandardItemModel>

#include "dismo/Token.h"
#include "dismo/TokenUnit.h"
#include "dismo/TokenList.h"
using namespace DisMoAnnotator;

#include "DisMoAnnotationModel.h"

DismoAnnotationModel::DismoAnnotationModel(QObject *parent)
    : QStandardItemModel(parent)
{
    initialize();
}

void DismoAnnotationModel::initialize()
{
    setHorizontalHeaderLabels(QStringList()
        << tr("file") << tr("xmin") << tr("xmax")
        << tr("tok-min") << tr("pos-min") << tr("tok-mwu") << tr("pos-mwu")
        << tr("discourse") << tr("disfluency") << tr("boundary")
        << tr("pos-ext") << tr("lemma")
        << tr("ambiguity-class") << tr("confidence") << tr("method")
    );
    this->horizontalHeaderItem(0)->setToolTip("Corpus item (file) annotated");
    this->horizontalHeaderItem(1)->setToolTip("Time interval - start");
    this->horizontalHeaderItem(2)->setToolTip("Time interval - end");
    this->horizontalHeaderItem(3)->setToolTip("Minimal token unit");
    this->horizontalHeaderItem(4)->setToolTip("POS tag of Minimal token unit");
    this->horizontalHeaderItem(5)->setToolTip("Multi-word token unit");
    this->horizontalHeaderItem(6)->setToolTip("POS tag of Multi-word token unit");
    this->horizontalHeaderItem(7)->setToolTip("Disourse annotation: markers, connectors, etc.");
    this->horizontalHeaderItem(8)->setToolTip("Disfluency annotation: hesitations, corrections, etc.");
    this->horizontalHeaderItem(9)->setToolTip("Boundary (minimal, mimimal left, maximal) - BETA");
    this->horizontalHeaderItem(10)->setToolTip("Inflection information for minimal token");
    this->horizontalHeaderItem(11)->setToolTip("Lemma of minimal token");
    this->horizontalHeaderItem(12)->setToolTip("POS tags in the dictionary for this token");
    this->horizontalHeaderItem(13)->setToolTip("Confidence measure");
    this->horizontalHeaderItem(14)->setToolTip("Method that led DisMo choose this POS tag");
}

void DismoAnnotationModel::clear()
{
    QStandardItemModel::clear();
    initialize();
}

void DismoAnnotationModel::loadTokenList(const TokenList &TL, const QString &file)
{
    QList<QStandardItem *> line;
    foreach(Token *tok, TL) {
        foreach(TokenUnit *tu, tok->getTokenUnits()) {
            line << new QStandardItem(file);                                        // file
            line << new QStandardItem(QString::number(tu->tMin().toDouble(), 'f', 3)); // xMin
            line << new QStandardItem(QString::number(tu->tMax().toDouble(), 'f', 3)); // xMax
            line << new QStandardItem(tu->text());                                  // tok-min
            line << new QStandardItem(tu->getTagPOS());                             // pos-min
            if (tok->isMWU()) {
                line << new QStandardItem(tok->text());                             // tok-mwu
                line << new QStandardItem(tok->getTagPOS());                        // pos-mwu
            }
            else {
                line << new QStandardItem("") << new QStandardItem("");
            }
            line << new QStandardItem(tok->getTagDiscourse());                      // discourse
            line << new QStandardItem(tu->getTagDisfluency());                      // disfluence
            line << new QStandardItem(tok->getTagFrontier());                       // boundary
            line << new QStandardItem(tu->getTagPOSext());                          // pos-min-ext
            line << new QStandardItem(tu->getLemma());                              // lemma
            line << new QStandardItem(tu->getAmbiguityClass());                     // ambiguity class
            line << new QStandardItem(QString::number(
                tu->getConfidencePOS()));                                           // pos-min confidence
            line << new QStandardItem(tu->getMatchTypePOS());                       // pos-min match type
            appendRow(line);
            line.clear();
        }
    }
}
