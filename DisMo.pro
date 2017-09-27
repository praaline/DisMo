# DisMo
# A multi-level annotator (part-of-speech tagging, chunking, disfluency detection) for spoken language transcriptions based on Conditional Random Fields (CRF)
# (c) George Christodoulides 2012-2017

TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += crfpp praalinelib dismo \
           praaline-plugin app-gui app-cli app-trainer \
           distrib


