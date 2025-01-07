//
// Created by Chiaki_meow on 2024/8/30.
//

#ifndef CPPPRACTICES_CMESSAGELOGGER_H
#define CPPPRACTICES_CMESSAGELOGGER_H

#define cDebug CMessageLogger(__LINE__, __FILE__, __FUNCTION__).debug
#define qInfo CMessageLogger(__LINE__, __FILE__, __FUNCTION__).info
#define qWarning CMessageLogger(__LINE__, __FILE__, __FUNCTION__).warning
#define qCritical CMessageLogger(__LINE__, __FILE__, __FUNCTION__).critical
#define qFatal CMessageLogger(__LINE__, __FILE__, __FUNCTION__).fatal

#include "CDebug.h"
#include "CMessageLogContext.h"

class CMessageLogger {
public:
    CMessageLogger(): context() {}
    CMessageLogger(int lineNumber, const char *fileName, const char *functionName):context(lineNumber, fileName, functionName) {}
    CDebug debug() const;
    CDebug info() const;
    CDebug warning() const;
    CDebug critical() const;
private:
    CMessageLogContext context;
};

#endif //CPPPRACTICES_CMESSAGELOGGER_H
