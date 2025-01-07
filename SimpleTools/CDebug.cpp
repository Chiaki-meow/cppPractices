//
// Created by Chiaki_meow on 2024/8/30.
//

#include "CDebug.h"

CDebug::~CDebug() {
    LogToConsole(stream->logType, stream->context, stream->ss.str());
    delete stream;
}

void CDebug::LogToConsole(LogType logType, const CMessageLogContext &context, std::string logBuffer) {
    std::string logString;
    switch (logType) {
        case ERROR:
            logString.append("ERROR!");
            break;
        case INFO:
            break;
        case WARNING:
            logString.append("WARNING!");
            break;
        case DEBUG:
            logString.append("[DEBUG]:");
            break;
        default:
            break;
    }
    logString.append(logBuffer);
    logString.append("......");
    logString.append(context.file);
    logString.append(" ");
    logString.append(context.function);
    logString.append("()");

    std::cout<<logString<<" line: "<<context.line<<" "<<std::endl;

}