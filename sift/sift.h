#ifndef __SIFT_H
#define __SIFT_H

// Sniper Instruction Trace File Format
//
// x86-64 only, little-endian

#include <cstddef>
#include <cstdint>

extern "C" {
#include "xed-interface.h"
}

namespace Sift {
const uint32_t MAX_DYNAMIC_ADDRESSES = 2;

typedef enum {
  MemInvalidLock = 0,
  MemNoLock,
  MemLock,
  MemUnlock,
} MemoryLockType;

typedef enum {
  MemInvalidOp = 0,
  MemRead,
  MemWrite,
} MemoryOpType;

typedef enum {
  RoutineEnter = 0,
  RoutineExit,
  RoutineAssert,
} RoutineOpType;
};  // namespace Sift

#endif  // __SIFT_H
