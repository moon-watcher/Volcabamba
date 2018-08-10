#ifndef _INC_MYTYPES_H_
#define _INC_MYTYPES_H_

typedef enum
{
    false,
    true = !false,
}
bool;

#define zero    FIX32(0)
#define nullptr ((void*)0)

#endif // _INC_MYTYPES_H_


