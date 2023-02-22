#ifndef BASE_H

/* depends on:
 * stdio.h, stdint.h */

/* types */
typedef int8_t   int8;
typedef int16_t  int16;
typedef int32_t  int32;
typedef int64_t  int64;
typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef float    real32;
typedef double   real64;
typedef int8     bool8;
typedef int16    bool16;
typedef int32    bool32;
typedef int64    bool64;

/* macros */
#define internal static
#define global_variable static
#define local_persist static

#define true 1
#define false 0

#ifndef MEM_DEFAULT_ALIGNMENT
#define MEM_DEFAULT_ALIGNMENT (2*sizeof(void *))
#endif

#define Stmnt(S)	do{S}while(0)
#define ArrayLength(a)  (sizeof(a)/sizeof(*(a)))
#define Min(a,b)        (((a)<(b))?(a):(b))
#define Max(a,b)        (((a)>(b))?(a):(b))
#define Clamp(a,x,b)    (((x)<(a))?(a):((b)<(x))?(b):(x))
#define ClampBot(a,b)   (Max((a),(b)))
#define ClampTop(a,b)   (Min((a),(b)))
#define Abs(a)          (((a)<0)?(-(a)):(a))
#define OffsetOf(t, e)  ((size_t)&(((t *)0)->e))
#define Kilobytes(v)	((v)*1024LL)
#define Megabytes(v)	(Kilobytes(v)*1024LL)
#define Gigabytes(v)	(Megabytes(v)*1024LL)
#define Terabytes(v)	(Gigabytes(v)*1024LL)

#define AssertBreak() (*(int *)0 = 0)
#if ENABLE_ASSERT
#define Assert(c) Stmnt(\
                        if (!(c)){\
                          fprintf(stderr, "[ASSERTION FAILED]: %s %d, ",__FILE__, __LINE__);\
                          fprintf(stderr, "`"#c"`\n");\
                          AssertBreak();\
                        }\
                    )
#else
#define Assert(c)
#endif

#if ENABLE_DEBUGLOG
#define DebugLog(format, ...)       printf(format"\n"ANSII_ESC_RESET_ALL,\
					   ##__VA_ARGS__);
#define DebugLogError(format, ...)  Stmnt(\
                                        fprintf(stderr, "%s %d: ",__FILE__, __LINE__);\
                                        fprintf(stderr, format,##__VA_ARGS__);\
                                        fprintf(stderr, "\n");\
                                        fprintf(stderr, ANSII_ESC_RESET_ALL);\
                                          )
#define DebugLogInt(a)              printf(#a" = %ld\n", (int64)a)
#define DebugLogUint(a)             printf(#a" = %lu\n", (uint64)a)
#define DebugLogReal(a)             printf(#a" = %f\n", (real64)a)
#define DebugLogChar(s)             printf(#s" = %c\n", (char)s)
#define DebugLogString(s)           printf(#s" = %s\n", (char *)s)
#define DebugLogBool(b)             printf(#b" = %s\n", (b)?"true":"false")
#define DebugLogPtr(p)              printf(#p" = %p\n", p)
#define DebugLogLine(p)             printf("────────────────────────────────\n")
#else
#define DebugLog(format, ...)
#define DebugLogError(format, ...)
#define DebugLogInt(a)
#define DebugLogUint(a)
#define DebugLogReal(a)
#define DebugLogChar(s)
#define DebugLogString(s)
#define DebugLogBool(b)
#define DebugLogPtr(p)
#define DebugLogLine(p)
#endif

#define BASE_H
#endif
