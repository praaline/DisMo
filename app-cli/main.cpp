#include <QString>
#include <QList>
#include <QCoreApplication>
#include <QCommandLineParser>
#include "DisMoOptions.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("DisMo");
    QCoreApplication::setApplicationVersion("2020.08.1");

    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::translate("DisMo", "DisMo Linguistic Annotator."));
    DisMoCommandLineParseResult result = DisMoCommandLineParseResult::parseCommandLine(parser);
    switch (result.parseResult) {
       case CommandLineOk:
           break;
       case CommandLineError:
           fputs(qPrintable(result.errorMessage), stderr);
           fputs("\n\n", stderr);
           fputs(qPrintable(parser.helpText()), stderr);
           return 1;
       case CommandLineVersionRequested:
           printf("%s %s\n", qPrintable(QCoreApplication::applicationName()),
                  qPrintable(QCoreApplication::applicationVersion()));
           return 0;
       case CommandLineHelpRequested:
           parser.showHelp();
           Q_UNREACHABLE();
    }


    return a.exec();
}
