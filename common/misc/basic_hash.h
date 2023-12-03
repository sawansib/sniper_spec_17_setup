#ifndef BASIC_HASH_H
#define BASIC_HASH_H

#include <assert.h>

#include <iostream>
#include <unordered_map>
#include <utility>

#include "fixed_types.h"

// #define DEBUG_BASIC_HASH

class BasicHash {
 protected:
  typedef std::unordered_map<UInt64, UInt64> Bucket;
  Bucket *array;
  UInt64 size;

 public:
  BasicHash(UInt64 size);
  ~BasicHash();

  std::pair<bool, UInt64> find(UInt64 key);
  bool insert(UInt64 key, UInt64 value);
};

#endif
