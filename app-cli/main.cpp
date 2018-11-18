#include <QString>
#include <QList>
#include <QCoreApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("DisMo");
    QCoreApplication::setApplicationVersion("2018.11.1");

    QCommandLineParser parser;
    parser.setApplicationDescription("DisMo Multi-Level Linguistic Annotator");
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addPositionalArgument("input", QCoreApplication::translate("main", "Input file to annotate."));



    return a.exec();
}
