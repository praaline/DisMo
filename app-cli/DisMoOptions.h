#ifndef DISMOOPTIONS_H
#define DISMOOPTIONS_H

#include <QList>
#include <QString>
#include <QCommandLineParser>

enum CommandLineParseResult
{
    CommandLineOk,
    CommandLineError,
    CommandLineVersionRequested,
    CommandLineHelpRequested
};

enum DisMoInputFormat
{
    InputPraalineCorpus,
    InputPraatTextGrid
};

class DisMoOptions
{
public:
    DisMoOptions();

    // Choice of input format
    // ----------------------------------------------------------------------------------------------------
    DisMoInputFormat inputFormat;

    // Annotating a Praaline Corpus
    // ----------------------------------------------------------------------------------------------------
    QString filenameCorpusRepositoryDefinition;     // Corpus Repository Definition file
    QList<QString> communicationIDs;                // List of Communication IDs to annotate
    bool createDisMoAnnotationLevels;               // Create DisMo annotation levels?
    QString annotationLevelInput;                   // Annotation level to annotate (transcription)
    QString annotationLevelTokMin;                  // Annotation level name for tokens (minimal)
    QString annotationLevelTokMWU;                  // Annotation level name for tokens (multi-word units)
    QString annotationLevelPhones;                  // Annotation level for phones
    QString annotationAttributePrefix;              // Prefix to add to DisMo attributes
    QString annotationAttributeSuffix;              // Suffix to add to DisMo attributes

    // Annotating Praat TextGrids
    // ----------------------------------------------------------------------------------------------------
    QList<QString> textgridFilenames;               // List of TextGrid filenames to annotate
    bool textgridOverwriteAnnotations;              // Can DisMo overwrite existing annotations? (if false, abort if target tiers already exist)
    bool textgridAnnotateAllTiers;                  // Each tier contains an input transcription? (tier name is the speaker name)
    QString textgridTiernameInput;                  // otherwise: name of the tier to annotate (containing the input transcription)
    bool textgridOutputTokMin;                      // Include tok-min     tier in the output TextGrid?
    bool textgridOutputPOSMin;                      // Include pos-min     tier in the output TextGrid?
    bool textgridOutputDisfluency;                  // Include disfluency  tier in the output TextGrid?
    bool textgridOutputPOSMinExt;                   // Include pos-min-ext tier in the output TextGrid?
    bool textgridOutputLemmaMin;                    // Include lemma-min   tier in the output TextGrid?
    bool textgridOutputTokMWU;                      // Include tok-mwu     tier in the output TextGrid?
    bool textgridOutputPOSMWU;                      // Include pos-mwu     tier in the output TextGrid?
    bool textgridOutputDiscourse;                   // Include discourse   tier in the output TextGrid?
    bool textgridOutputPOSMWUExt;                   // Include pos-mwu-ext tier in the output TextGrid?
    bool textgridOutputLemmaMWU;                    // Include lemma-mwu   tier in the output TextGrid?
    QString textgridOutputTierNamePrefix;           // Prefix to add to DisMo tiers in the output TextGrid
    QString textgridOutputTierNameSuffix;           // Suffix to add to DisMo tiers in the output TextGrid

    // Outputs
    // ----------------------------------------------------------------------------------------------------
    bool outputAnnotatedTextgrid;                   // Should output an annotated TextGrid? Default true if input is a TextGrid
    QString outputAnnotatedTextgridPrefix;          // Optional prefix to add to the annotated TextGrid filename
    QString outputAnnotatedTextgridSuffix;          // Optional suffix to add to the annotated TextGrid filename
    bool outputTabSeparatedFileForEachInput;        // Should output a tab-separated file for each input?
    bool outputTabSeparatedFileForAllInputs;        // Should output a tab-separated file for all inputs?
    QString filenameTabSeparatedFileForAllInputs;   // ... if yes, its filename
    bool outputCONLLXFileForEachInput;              // Should output a CONLL-X file for each input?
    bool outputCONLLXFileForAllInputs;              // Should output a CONLL-X file for all inputs?
    QString filenameCONLLXFileForAllInputs;         // ... if yes, its filename

    // Tokeniser Options
    // ----------------------------------------------------------------------------------------------------
    bool alreadyTokenised;                          // Already tokenised?
    bool alreadyTokenisedOnlyTokMin;                // Already tokenised only to minimal tokens?
};

class DisMoCommandLineParseResult
{
public:
    CommandLineParseResult parseResult;
    QString errorMessage;
    DisMoOptions options;

    static DisMoCommandLineParseResult parseCommandLine(QCommandLineParser &parser);
};


#endif // DISMOOPTIONS_H
