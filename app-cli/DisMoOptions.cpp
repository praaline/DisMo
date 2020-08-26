#include "DisMoOptions.h"

DisMoOptions::DisMoOptions()
{
    // Choice of input format
    // ----------------------------------------------------------------------------------------------------
    inputFormat = DisMoInputFormat::InputPraalineCorpus;

    // Annotating a Praaline Corpus
    // ----------------------------------------------------------------------------------------------------
    createDisMoAnnotationLevels = true;             // Create DisMo annotation levels?
    annotationLevelInput = "transcription";         // Annotation level to annotate
    annotationLevelTokMin = "tok_min";              // Annotation level name for tokens (minimal)
    annotationLevelTokMWU = "tok_mwu";              // Annotation level name for tokens (multi-word units)
    annotationLevelPhones = "phone";                // Annotation level for phones
    annotationAttributePrefix = QString();          // Prefix to add to DisMo attributes
    annotationAttributeSuffix = QString();          // Suffix to add to DisMo attributes

    // Annotating Praat TextGrids
    // ----------------------------------------------------------------------------------------------------
    textgridOverwriteAnnotations = true;            // Can DisMo overwrite existing annotations? (if false, abort if target tiers already exist)
    textgridAnnotateAllTiers = true;                // Each tier contains an input transcription? (tier name is the speaker name)
    textgridTiernameInput = QString();              // otherwise: name of the tier to annotate (containing the input transcription)
    textgridOutputTokMin = true;                    // Include tok-min     tier in the output TextGrid?
    textgridOutputPOSMin = true;                    // Include pos-min     tier in the output TextGrid?
    textgridOutputDisfluency = true;                // Include disfluency  tier in the output TextGrid?
    textgridOutputPOSMinExt = false;                // Include pos-min-ext tier in the output TextGrid?
    textgridOutputLemmaMin = false;                 // Include lemma-min   tier in the output TextGrid?
    textgridOutputTokMWU = true;                    // Include tok-mwu     tier in the output TextGrid?
    textgridOutputPOSMWU = true;                    // Include pos-mwu     tier in the output TextGrid?
    textgridOutputDiscourse = false;                // Include discourse   tier in the output TextGrid?
    textgridOutputPOSMWUExt = false;                // Include pos-mwu-ext tier in the output TextGrid?
    textgridOutputLemmaMWU = false;                 // Include lemma-mwu   tier in the output TextGrid?
    textgridOutputTierNamePrefix = QString();       // Prefix to add to DisMo tiers in the output TextGrid
    textgridOutputTierNameSuffix = QString();       // Suffix to add to DisMo tiers in the output TextGrid

    // Outputs
    // ----------------------------------------------------------------------------------------------------
    outputAnnotatedTextgrid = false;                // Should output an annotated TextGrid?
    outputAnnotatedTextgridPrefix = QString();      // Optional prefix to add to the annotated TextGrid filename
    outputAnnotatedTextgridSuffix = QString();      // Optional suffix to add to the annotated TextGrid filename
    outputTabSeparatedFileForEachInput = false;     // Should output a tab-separated file for each input?
    outputTabSeparatedFileForAllInputs = false;     // Should output a tab-separated file for all inputs?
    filenameTabSeparatedFileForAllInputs = "dismo_out.txt";     // ... if yes, its filename
    outputCONLLXFileForEachInput = false;           // Should output a CONLL-X file for each input?
    outputCONLLXFileForAllInputs = false;           // Should output a CONLL-X file for all inputs?
    filenameCONLLXFileForAllInputs = "dismo_out_connlx.txt";    // ... if yes, its filename

    // Tokeniser Options
    // ----------------------------------------------------------------------------------------------------
    alreadyTokenised = false;                       // Already tokenised?
    alreadyTokenisedOnlyTokMin = false;             // Already tokenised only to minimal tokens?
}

// static
DisMoCommandLineParseResult DisMoCommandLineParseResult::parseCommandLine(QCommandLineParser &parser)
{
    DisMoCommandLineParseResult result;
    parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);

    // Set options
    const QCommandLineOption listCommunicationIDsOption("communications",
                "A list of the Communication IDs to annotate in a Praaline corpus.", "listCommunicationIDs");
    parser.addOption(listCommunicationIDsOption);
    const QCommandLineOption createDisMoAnnotationLevelsOption("create-dismo-annotation-levels",
                "Create DisMo annotation levels?", "createDisMoAnnotationLevels", "yes");
    parser.addOption(createDisMoAnnotationLevelsOption);
    const QCommandLineOption annotationLevelInputOption("annotation-level-input",
                "Annotation level to annotate (transcription)", "annotationLevelInput", "transcription");
    parser.addOption(annotationLevelInputOption);
    const QCommandLineOption annotationLevelTokMinOption("annotation-level-tok-min",
                "Annotation level name for tokens (minimal)", "annotationLevelTokMin", "tok_min");
    parser.addOption(annotationLevelTokMinOption);
    const QCommandLineOption annotationLevelTokMWUOption("annotation-level-tok-mwu",
                "Annotation level name for tokens (multi-word units)", "annotationLevelTokMWU", "tok_mwu");
    parser.addOption(annotationLevelTokMWUOption);
    const QCommandLineOption annotationLevelPhonesOption("annotation-level-phones",
                "Annotation level name for phones (optional)", "annotationLevelPhones", "phone");
    parser.addOption(annotationLevelPhonesOption);
    const QCommandLineOption annotationAttributePrefixOption("annotation-attribute-prefix",
                "Prefix to add to DisMo attributes", "annotationAttributePrefix");
    parser.addOption(annotationAttributePrefixOption);
    const QCommandLineOption annotationAttributeSuffixOption("annotation-attribute-suffix",
                "Suffix to add to DisMo attributes", "annotationAttributeSuffix");
    parser.addOption(annotationAttributeSuffixOption);



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
    bool outputAnnotatedTextgrid;                   // Should output an annotated TextGrid? Default true if input is a TextGrid
    QString outputAnnotatedTextgridPrefix;          // Optional prefix to add to the annotated TextGrid filename
    QString outputAnnotatedTextgridSuffix;          // Optional suffix to add to the annotated TextGrid filename
    bool outputTabSeparatedFileForEachInput;        // Should output a tab-separated file for each input?
    bool outputTabSeparatedFileForAllInputs;        // Should output a tab-separated file for all inputs?
    QString filenameTabSeparatedFileForAllInputs;   // ... if yes, its filename
    bool outputCONLLXFileForEachInput;              // Should output a CONLL-X file for each input?
    bool outputCONLLXFileForAllInputs;              // Should output a CONLL-X file for all inputs?
    QString filenameCONLLXFileForAllInputs;         // ... if yes, its filename
    bool alreadyTokenised;                          // Already tokenised?
    bool alreadyTokenisedOnlyTokMin;                // Already tokenised only to minimal tokens?



    // Set positional arguments, help and version
    parser.addPositionalArgument("input", "Input filename: .PraalineCorpus or .TextGrid");
    const QCommandLineOption helpOption = parser.addHelpOption();
    const QCommandLineOption versionOption = parser.addVersionOption();

    // Try parsing the command line -- exit with an error if unsuccesful
    if (!parser.parse(QCoreApplication::arguments())) {
        result.parseResult = CommandLineParseResult::CommandLineError;
        result.errorMessage = parser.errorText();
        return result;
    }
    // Version requested
    if (parser.isSet(versionOption)) {
        result.parseResult = CommandLineParseResult::CommandLineVersionRequested;
        return result;
    }
    // Help requested
    if (parser.isSet(helpOption)) {
        result.parseResult = CommandLineParseResult::CommandLineHelpRequested;
        return result;
    }

    // Validate options


    return result;
}

