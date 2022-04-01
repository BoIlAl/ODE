#include "compilerLogger.h"

CompilerLogger::CompilerLogger(const QString& logFilePath) {
    file_ = new QFile(logFilePath);
    if (file_->open(QIODevice::WriteOnly | QIODevice::Text))  { 
        textStream_ = new QTextStream(file_);
    } 
}

void CompilerLogger::log(CompErrorLevel level, CompErrorType rc) {
    if (level = CEL_ERROR) {
        okFlag_ = false;
    }
    switch (rc) {
     
    }
}

bool CompilerLogger::status() {
    return okFlag_;
}

CompilerLogger::~CompilerLogger() {
    if (textStream_ != nullptr) {
        delete textStream_;
        file_->close();
    }
    //delete file_;
}