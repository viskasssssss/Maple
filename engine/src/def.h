// -- core engine defines header

#pragma once

// unsigned int
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// signed int
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// floating point
typedef float f32;
typedef double f64;

// boolean
typedef int b32;
typedef char b8;

// define static assertions
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// ensure all types are of the correct size
STATIC_ASSERT(sizeof(u8) == 1, "expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(u16) == 2, "expected u16 to be 2 bytes.");
STATIC_ASSERT(sizeof(u32) == 4, "expected u32 to be 4 bytes.");
STATIC_ASSERT(sizeof(u64) == 8, "expected u64 to be 8 bytes.");

STATIC_ASSERT(sizeof(i8) == 1, "expected i8 to be 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "expected i16 to be 2 bytes.");
STATIC_ASSERT(sizeof(i32) == 4, "expected i32 to be 4 bytes.");
STATIC_ASSERT(sizeof(i64) == 8, "expected i64 to be 8 bytes.");

STATIC_ASSERT(sizeof(f32) == 4, "expected f32 to be 4 bytes.");
STATIC_ASSERT(sizeof(f64) == 8, "expected f64 to be 8 bytes.");

#define TRUE 1
#define FALSE 0

// platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) 
#define MPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required on Windows"
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
// linux os
#define MPLATFORM_LINUX 1
#if defined(__ANDROID__)
#define MPLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
// catch anything not caught by the above
#define MPLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
// posix
#define MPLATFORM_POSIX 1
#elif __APPLE__
// apple platforms
#define MPLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
// iOS simulator
#define MPLATFORM_IOS 1
#define MPLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define MPLATFORM_IOS 1
// iOS device
#elif TARGET_OS_MAC
// other kinds of Mac OS
#else
#error "unknown Apple platform"
#endif
#else
#error "unknown platform!"
#endif

#ifdef MEXPORT
// exports
#ifdef _MSC_VER
#define MAPI __declspec(dllexport)
#else
#define MAPI __attribute__((visibility("default")))
#endif
#else
// imports
#ifdef _MSC_VER
#define MAPI __declspec(dllimport)
#else
#define MAPI
#endif
#endif