#pragma once

#include "ontologyLexer.h"
#include "ontologyParser.h"
#include "ANTLRInputStream.h"
#include "ontologyBaseVisitor.h"
#include "logger.h"
#include <QString>
#include <QCoreApplication>
#include <QDir>
#include <QtCore>
#include <QFileInfo>

class ProjectCompiler {
private:
    const QString c_srcPath = "/src/";
    const QString c_jsonPath = "/.gldata/";
    const QString c_filter = "*txt";
    const QString c_logPath = "/log/";
    const QString c_format = ".json";

    QString projectPath_;
    Logger logger_;

    void createMainJson();
    void createPackageFiles();

    void redefCheck(std::vector<std::pair<QString, int>> names);
    void nodefCheck(std::vector<std::pair<QString, int>> names, std::vector<QString> uNames);
    QJsonArray getObjArr(std::vector<std::pair<QString, int>> info, std::vector<QString> packages) const;
public:
    void setProjPath(const QString& projectPath);

    void compile();
};