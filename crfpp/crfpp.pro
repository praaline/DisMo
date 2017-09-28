# DisMo
# A multi-level annotator (part-of-speech tagging, chunking, disfluency detection) for spoken language transcriptions based on Conditional Random Fields (CRF)
# (c) George Christodoulides 2012-2017

# CRF++ Library

! include( ../common.pri ) {
    error( Could not find the common.pri file! )
}

CONFIG += staticlib qt thread warn_on stl rtti exceptions c++11

TARGET = crfpp

INCLUDEPATH += . ..
DEPENDPATH += . ..

unix {
    DEFINES += HAVE_CRFPP_CONFIG_H
}

HEADERS += \
    common.h \
    config.h \
    crfpp.h \
    darts.h \
    encoder.h \
    feature_cache.h \
    feature_index.h \
    freelist.h \
    lbfgs.h \
    mmap.h \
    node.h \
    param.h \
    path.h \
    scoped_ptr.h \
    stream_wrapper.h \
    tagger.h \
    thread.h \
    timer.h \
    winmain.h

SOURCES += \
    encoder.cpp \
    feature.cpp \
    feature_cache.cpp \
    feature_index.cpp \
    lbfgs.cpp \
    libcrfpp.cpp \
    node.cpp \
    param.cpp \
    path.cpp \
    tagger.cpp
