#pragma once

#include <QString>
#include <QFile>
#include <QTextStream>

enum CompErrorType {
    CE_OK
};

enum CompErrorLevel {
    CEL_WARNING,
    CEL_ERROR,
    CEL_INFO
};

class CompilerLogger {
private:
    QFile* file_;
    QTextStream* textStream_ = nullptr;
    bool okFlag_ = true;
public:
    CompilerLogger(){}; 
    CompilerLogger(const QString& logFilePath);
    void log(CompErrorLevel level, CompErrorType rc);
    bool status();
    ~CompilerLogger();
};
