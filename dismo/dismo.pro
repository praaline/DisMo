# DisMo
# A multi-level annotator (part-of-speech tagging, chunking, disfluency detection) for spoken language transcriptions based on Conditional Random Fields (CRF)
# (c) George Christodoulides 2012-2017

# Main annotator source code

! include( ../common.pri ) {
    error( Could not find the common.pri file! )
}

CONFIG += staticlib qt thread warn_on stl rtti exceptions c++11
QT += sql
QT -= gui

INCLUDEPATH += . .. ../praaline-core
DEPENDPATH += . .. ../praaline-core

TARGET = dismo

DISTFILES += \
    ../README.md \
    ../LICENSE \
    ../.travis.yml \
    ../appveyor.yml

HEADERS += \
    BoundaryDetector.h \
    CRFAnnotator.h \
    CRFFeatureSet.h \
    DictionaryEntry.h \
    DictionaryFST.h \
    DictionaryQuery.h \
    DictionarySQL.h \
    DiscourseTagger.h \
    DisfluencyDetector.h \
    DisMoAnnotator.h \
    DisMoEvaluator.h \
    DisMoTrainer.h \
    POSTagger.h \
    PostProcessor.h \
    PreProcessor.h \
    Token.h \
    Tokenizer.h \
    TokenList.h \
    TokenUnit.h \
    serialisers/DisMoSerialiserSQL.h \
    serialisers/DisMoSerialiserTiers.h

SOURCES += \
    BoundaryDetector.cpp \
    CRFAnnotator.cpp \
    CRFFeatureSet.cpp \
    DictionaryFST.cpp \
    DictionarySQL.cpp \
    DiscourseTagger.cpp \
    DisfluencyDetector.cpp \
    DisMoAnnotator.cpp \
    DisMoEvaluator.cpp \
    DisMoTrainer.cpp \
    POSTagger.cpp \
    PostProcessor.cpp \
    PreProcessor.cpp \
    Token.cpp \
    Tokenizer.cpp \
    TokenList.cpp \
    TokenUnit.cpp \
    serialisers/DisMoSerialiserSQL.cpp \
    serialisers/DisMoSerialiserTiers.cpp
