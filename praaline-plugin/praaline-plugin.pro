# DisMo
# A multi-level annotator (part-of-speech tagging, chunking, disfluency detection) for spoken language transcriptions based on Conditional Random Fields (CRF)
# (c) George Christodoulides 2012-2017

# Plug-in for Praaline

! include( ../common.pri ) {
    error( Could not find the common.pri file! )
}

CONFIG += staticlib qt thread warn_on stl rtti exceptions c++11

TARGET = plugin_dismo


