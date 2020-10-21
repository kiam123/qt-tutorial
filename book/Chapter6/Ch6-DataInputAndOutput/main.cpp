#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile data("D:/QtProjects/QtProject/qt-tutorial/book/Chapter6/Ch6-DataInputAndOutput/output.txt");
    if(data.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&data);
        out << "name\tscore" << "\n";
        out << "justin\t" << 95 << "\n";
        out << "momor\t" << 93 << "\n";
        out << "minnie\t" << 93 << "\n";

        data.flush();
        data.close();
    }


    QFile file("D:/QtProjects/QtProject/qt-tutorial/book/Chapter6/Ch6-DataInputAndOutput/output.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Cannot open file for reading:"
                     << qPrintable(file.errorString()) << "\n";

    while(!file.atEnd()) {
        QByteArray line = file.readLine();
        qDebug() << line;
    }
    file.flush();
    file.close();

    return a.exec();
}
