//
// Created by Chiaki_meow on 2024/8/30.
//
#include "CMessageLogger.h"

CDebug CMessageLogger::debug() const {
    std::string debug = "debug";
    CDebug dbg = CDebug(&debug);
    CMessageLogContext &ctxt = dbg.stream->context;
    ctxt.copy(this->context);
    dbg.stream->logType = DEBUG;
    return dbg;
}

CDebug CMessageLogger::info() const {
    CDebug dbg = CDebug();
    CMessageLogContext &ctxt = dbg.stream->context;
    ctxt.copy(this->context);
    dbg.stream->logType = INFO;
    return dbg;
}

CDebug CMessageLogger::warning() const {
    CDebug dbg = CDebug();
    CMessageLogContext &ctxt = dbg.stream->context;
    ctxt.copy(this->context);
    dbg.stream->logType = WARNING;
    return dbg;
}

CDebug CMessageLogger::critical() const {
    CDebug dbg = CDebug();
    CMessageLogContext &ctxt = dbg.stream->context;
    ctxt.copy(this->context);
    dbg.stream->logType = ERROR;
    return dbg;
}