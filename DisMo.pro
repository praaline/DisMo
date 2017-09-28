# DisMo
# A multi-level annotator (part-of-speech tagging, chunking, disfluency detection) for spoken language transcriptions based on Conditional Random Fields (CRF)
# (c) George Christodoulides 2012-2017

TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += crfpp praaline-core dismo \
           app-gui app-cli app-trainer # \
           # praaline-plugin

