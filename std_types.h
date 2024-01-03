
#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

typedef unsigned char           uint8 ;
typedef unsigned short          uint16;
typedef unsigned long           uint32;
typedef unsigned long long      uint64;

typedef signed char             sint8 ;
typedef signed short            sint16;
typedef signed long             sint32;
typedef signed long long        sint64;


typedef float                   float32;
typedef double                  float64;

#define ZERO_INIT               0
#define ONE_INIT                1

typedef enum
{
    E_OK,
    E_NOT_OK,
}std_return;


#endif