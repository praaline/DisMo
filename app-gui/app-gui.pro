# DisMo
# A multi-level annotator (part-of-speech tagging, chunking, disfluency detection)
# for spoken language transcriptions based on Conditional Random Fields (CRF)
# (c) George Christodoulides 2012-2020

# Stand-alone application with GUI

! include( ../common.pri ) {
    error( Could not find the common.pri file! )
}

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dismo-gui
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += . .. ../praaline-core
DEPENDPATH += . .. ../praaline-core

# Build folder organisation
CONFIG( debug, debug|release ) {
    # debug
    COMPONENTSPATH = build/debug
} else {
    # release
    COMPONENTSPATH = build/release
}

# Library linking
LIBS +=  \
        -L../dismo/$${COMPONENTSPATH} -ldismo \
        -L../praaline-core/$${COMPONENTSPATH} -lpraaline-core$${PRAALINE_LIB_POSTFIX} \
        $$LIBS
PRE_TARGETDEPS += \
        ../dismo/$${COMPONENTSPATH}/libdismo.a \
        ../praaline-core/$${COMPONENTSPATH}/libpraaline-core$${PRAALINE_LIB_POSTFIX}.$${LIB_SUFFIX}


# Source code files
SOURCES += \
    main.cpp \
    models/AnnotationsTableModel.cpp \
    models/CheckableProxyModel.cpp \
    models/DelayedExecutionTimer.cpp \
    models/DisMoAnnotationModel.cpp \
    MainWindow.cpp

HEADERS += \
    models/AnnotationsTableModel.h \
    models/CheckableProxyModel.h \
    models/DelayedExecutionTimer.h \
    models/DisMoAnnotationModel.h \
    MainWindow.h

FORMS += \
    MainWindow.ui

RESOURCES += \
    app-gui-resources.qrc

