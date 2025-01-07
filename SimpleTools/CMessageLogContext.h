//
// Created by Chiaki_meow on 2024/8/30.
// ref: https://blog.csdn.net/silangquan/article/details/50279911?spm=1001.2014.3001.5502
//

#ifndef CPPPRACTICES_CMESSAGELOGCONTEXT_H
#define CPPPRACTICES_CMESSAGELOGCONTEXT_H

#include <string>

class CMessageLogContext {
public:
    CMessageLogContext(): line(0), file(0), function(0) {}
    CMessageLogContext(int lineNumber, const char *fileName, const char *functionName)
    :line(lineNumber), file(fileName), function(functionName) {}
    int line;
    const char *file;
    const char *function;
    void copy(const CMessageLogContext &logContext) {
        this->line = logContext.line;
        this->file = logContext.file;
        this->function = logContext.function;
    }
private:
    friend class CMessageLogger;
    friend class CDebug;
};

#endif //CPPPRACTICES_CMESSAGELOGCONTEXT_H
