#ifndef __DYNAMIC_INSTRUCTION_H
#define __DYNAMIC_INSTRUCTION_H

#include "allocator.h"
#include "hit_where.h"
#include "operand.h"
#include "subsecond_time.h"

class Core;
class Instruction;

class DynamicInstruction {
 private:
  // Private constructor: alloc() should be used
  DynamicInstruction(Instruction *ins, IntPtr _eip) {
    instruction = ins;
    eip = _eip;
    branch_info.is_branch = false;
    branch_info.is_call = false;
    branch_info.is_ret = false;
    branch_info.is_jump = false;
    branch_info.is_direct = false;
    branch_info.taken = false;
    branch_info.target = 0;
    num_memory = 0;
    is_xchg = false;
  }

 public:
  struct BranchInfo {
    bool is_branch;
    bool is_call;
    bool is_ret;
    bool is_jump;
    bool is_direct;
    bool taken;
    IntPtr target;
  };
  struct MemoryInfo {
    bool executed;  // For CMOV: true if executed
    Operand::Direction dir;
    IntPtr addr;
    UInt32 size;
    UInt32 num_misses;
    SubsecondTime latency;
    HitWhere::where_t hit_where;
  };
  static const UInt8 MAX_MEMORY = 2;

  Instruction *instruction;
  IntPtr eip;  // Can be physical address, so different from
               // instruction->getAddress() which is always virtual
  BranchInfo branch_info;
  UInt8 num_memory;
  MemoryInfo memory_info[MAX_MEMORY];
  bool is_xchg;
  int reg_value;

  static Allocator *createAllocator();

  ~DynamicInstruction();

  static DynamicInstruction *alloc(Allocator *alloc, Instruction *ins,
                                   IntPtr eip) {
    void *ptr = alloc->alloc(sizeof(DynamicInstruction));
    DynamicInstruction *i = new (ptr) DynamicInstruction(ins, eip);
    return i;
  }
  static void operator delete(void *ptr) { Allocator::dealloc(ptr); }

  SubsecondTime getCost(Core *core);

  bool isBranch() const { return branch_info.is_branch; }
  bool isCall() const { return branch_info.is_call; }
  bool isRet() const { return branch_info.is_ret; }
  bool isJump() const { return branch_info.is_jump; }
  bool isDirect() const { return branch_info.is_direct; }
  bool isMemory() const { return num_memory > 0; }

  void addMemory(bool e, SubsecondTime l, IntPtr a, UInt32 s,
                 Operand::Direction dir, UInt32 num_misses,
                 HitWhere::where_t hit_where) {
    LOG_ASSERT_ERROR(num_memory < MAX_MEMORY,
                     "Got more than MAX_MEMORY(%d) memory operands",
                     MAX_MEMORY);
    memory_info[num_memory].dir = dir;
    memory_info[num_memory].executed = e;
    memory_info[num_memory].latency = l;
    memory_info[num_memory].addr = a;
    memory_info[num_memory].size = s;
    memory_info[num_memory].num_misses = num_misses;
    memory_info[num_memory].hit_where = hit_where;
    num_memory++;
  }

  void addBranch(bool taken, IntPtr target) {
    branch_info.is_branch = true;
    branch_info.is_direct = true;
    branch_info.taken = taken;
    branch_info.target = target;
  }

  void addCallDirect(IntPtr target) {
    branch_info.is_call = true;
    branch_info.is_direct = true;
    branch_info.taken = true;
    branch_info.target = target;
  }

  void addCallIndirect(IntPtr target) {
    branch_info.is_call = true;
    branch_info.is_direct = false;
    branch_info.taken = true;
    branch_info.target = target;
  }

  void addRetIndirect(IntPtr target) {
    branch_info.is_ret = true;
    branch_info.is_direct = false;
    branch_info.taken = true;
    branch_info.target = target;
  }

  void addJumpDirect(IntPtr target) {
    branch_info.is_jump = true;
    branch_info.is_direct = true;
    branch_info.taken = true;
    branch_info.target = target;
  }

  void addJumpIndirect(IntPtr target) {
    branch_info.is_jump = true;
    branch_info.is_direct = false;
    branch_info.taken = true;
    branch_info.target = target;
  }

  void setXchgRegValue(int value) {
    is_xchg = true;
    reg_value = value;
  }

  SubsecondTime getBranchCost(Core *core, bool *p_is_mispredict = NULL);
  void accessMemory(Core *core);
};

#endif  // __DYNAMIC_INSTRUCTION_H
