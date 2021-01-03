#ifndef __OS_H__
#define __OS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"
#include "os/OSAlloc.h"
#include "os/OSFont.h"

typedef int64 OSTime;

struct OSCalendarTime
{
    int32 sec; // Current second. 0 - 61
    int32 min; // Current minute. 0 - 59
    int32 hour; // Current hour. 0 - 23
    int32 mday; // Day of month. 0 - 31
    int32 mon; // Current month. 0 - 11
    int32 year; // Current year.
    int32 wday; // Days since Sunday. 0 - 6
    int32 yday; // Days since January 1. 0 - 365
    int32 msec; // Current millisecond. 0 - 999
    int32 usec; // Current microsecond. 0 - 999
};

OSTime OSGetTime();
void OSTicksToCalendarTime(OSTime ticks, OSCalendarTime* td);
void OSPanic (const char* file, int32 line, const char* msg, ...);

#ifdef __cplusplus
}
#endif

#endif