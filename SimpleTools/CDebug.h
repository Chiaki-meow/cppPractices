//
// Created by Chiaki_meow on 2024/8/30.
//

#ifndef CPPPRACTICES_CDEBUG_H
#define CPPPRACTICES_CDEBUG_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <stdint.h>
#include "CMessageLogContext.h"

enum LogType {
    INFO,
    WARNING,
    ERROR,
    DEFAULT,
    DEBUG
};
class CDebug {
public:
    struct Stream {
        Stream(): ss(), space(true), context() {}
        Stream(std::string *s): ss(*s), space(true), context() {}

        std::ostringstream ss;
        bool space;
        CMessageLogContext context;
        LogType logType;
    } *stream;

    CDebug(): stream(new Stream()) {}
    inline CDebug(std::string *s): stream(new Stream(s)) {}
    ~CDebug();
    inline CDebug &operator<<(bool t) {stream->ss << (t ? "true" : "false"); return maybeSpace();}
    inline CDebug &operator<<(char t) {stream->ss << t; return maybeSpace();}
    inline CDebug &operator<<(signed short t) {stream->ss << t; return maybeSpace();}
    inline CDebug &operator<<(unsigned short t) {stream->ss << t; return maybeSpace();}
    inline CDebug &operator<<(std::string s) {stream->ss << s; return maybeSpace();}
    inline CDebug &operator<<(const char *c) {stream->ss << c; return maybeSpace();}
    inline CDebug &space() {stream->space = true; stream->ss << ' '; return *this;}
    inline CDebug &nospace() {stream->space = false; return *this;}
    inline CDebug &maybeSpace() {if(stream->space) stream->ss<<' '; return *this;}

    template<typename T>
    inline CDebug &operator<<(const std::vector<T> &vec) {
        stream->ss << '(';
        for(int i = 0; i < vec.size(); i++) {
            stream->ss << vec.at(i);
            if(i > 0) stream->ss << ", ";
        }
        stream->ss << ')';
        return maybeSpace();
    }
    void LogToConsole(LogType logType, const CMessageLogContext &context, std::string logBuffer);
private:
    static CDebug *_instance;
};


#endif //CPPPRACTICES_CDEBUG_H
