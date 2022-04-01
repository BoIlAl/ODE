#pragma once

#include "ontologyLexer.h"
#include "ontologyParser.h"
#include "ANTLRInputStream.h"
#include "ontologyBaseVisitor.h"
#include "compilerLogger.h"
#include <QString>
#include <QCoreApplication>
#include <QDir>
#include <QtCore>
#include <QFileInfo>

class ProjectCompiler {
private:
    const QString c_srcPath = "/src/";
    const QString c_jsonPath = "/data/";
    const QString c_filter = "*txt";
    const QString c_logPath = "/log/";

    QString projectPath_;

    void createMainJson(ontologyBaseVisitor& visitor);
public:
    ProjectCompiler(const QString& projectPath);
    void compile();
};