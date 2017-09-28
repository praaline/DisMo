# DisMo
# A multi-level annotator (part-of-speech tagging, chunking, disfluency detection) for spoken language transcriptions based on Conditional Random Fields (CRF)
# (c) George Christodoulides 2012-2017

# Command-line Interface

QT += core
QT -= gui

CONFIG += c++11

TARGET = dismo
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp

