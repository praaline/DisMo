# DisMo
# A multi-level annotator (part-of-speech tagging, chunking, disfluency detection) for spoken language transcriptions based on Conditional Random Fields (CRF)
# (c) George Christodoulides 2012-2017

# GUI application for training DisMo models

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dismo-trainer
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        MainWindow.cpp

HEADERS += \
        MainWindow.h

FORMS += \
        MainWindow.ui



