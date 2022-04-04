#pragma once

#include <QString>
#include <QFile>
#include <QTextStream>

enum CompErrorType {
    CE_NODEF,
    CE_REDEF,
    CE_NO_MATCH_FILES,
    CE_CANT_OPEN,

    CE_OK,
};

enum CompErrorLevel {
    CEL_WARNING,
    CEL_ERROR,
    CEL_INFO
};

class CE_StringConv {
public:
    QString CET_ToStr(const CompErrorType&) const;
    QString CEL_ToStr(const CompErrorLevel&) const;
};

class Logger {
private:
    const QString c_logFileName = "/log.txt";
    CE_StringConv strConv_;

    QFile file_;
    QTextStream textStream_;

    bool okFlag_ = true;
public:
    Logger(){};
    void setLogFilePath(const QString& logFilePath);

    void log(const CompErrorLevel& level, const CompErrorType& rc, const QString& message);
    bool status() const;
    void resetStatus();

    ~Logger();
};
