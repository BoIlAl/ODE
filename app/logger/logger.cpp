#include "logger.h"

QString CE_StringConv::CET_ToStr(const CompErrorType& cet) const {
    switch(cet) {
        case (CE_NODEF): {
            return "No definition of ";
        }
        case (CE_REDEF): {
            return "Redefinition of ";
        }
        case (CE_NO_MATCH_FILES): {
            return "No matching files in ";
        }
        case (CE_CANT_OPEN): {
            return "Cant open ";
        }
        default: {
            return "";
        }
    }
}

QString CE_StringConv::CEL_ToStr(const CompErrorLevel& cel) const {
    switch(cel) {
        case (CEL_WARNING): {
            return "Warning: ";
        }
        case (CEL_ERROR): {
            return "Error: ";
        }
        case (CEL_INFO): {
            return "Info: ";
        }
        default: {
            return "?";
        }
    }
}

void Logger::setLogFilePath(const QString& logFilePath) {
    if (file_.isOpen()) {
        file_.close();
    }

    file_.setFileName(logFilePath + c_logFileName);
    if (file_.open(QIODevice::WriteOnly | QIODevice::Text))  { 
        textStream_.setDevice(&file_);
    } 
}

void Logger::log(const CompErrorLevel& level, const CompErrorType& rc, const QString& message) {
    textStream_ << strConv_.CEL_ToStr(level) << strConv_.CET_ToStr(rc) << message << "\n";

    if (level == CEL_ERROR) {
        okFlag_ = false;
    }
}

bool Logger::status() const {
    return okFlag_;
}

void Logger::resetStatus() {
    okFlag_ = true;
}

Logger::~Logger(){
    if (file_.isOpen()) {
        file_.close();
    }
}