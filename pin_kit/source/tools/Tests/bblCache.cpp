/*BEGIN_LEGAL
Intel Open Source License

Copyright (c) 2002-2014 Intel Corporation. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.  Redistributions
in binary form must reproduce the above copyright notice, this list of
conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.  Neither the name of
the Intel Corporation nor the names of its contributors may be used to
endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE INTEL OR
ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
END_LEGAL */
/*
  @ORIGINAL_AUTHOR: Daniel Lemel
 */

/*! @file
 *  Check correctness of code-cache's address and size interfaces.
 */

#include "pin_tests_util.H"

BOOL test = true;

VOID FirstInCC(TRACE trace, VOID *v) {
  if (!test) return;
  test = false;

  BBL bbl = TRACE_BblHead(trace);
  while (!BBL_Valid(bbl)) bbl = BBL_Next(bbl);

  UINT32 ins_total = 0;
  INS ins = BBL_InsHead(bbl);
  TEST(INS_CodeCacheAddress(ins) == BBL_CodeCacheAddress(bbl),
       "BBL_CodeCacheAddress failed");

  for (; INS_Valid(ins); ins = INS_Next(ins)) {
    ins_total += INS_CodeCacheSize(ins);
  }
  TEST(ins_total == BBL_CodeCacheSize(bbl), "BBL_CodeCacheSize failed");
}

int main(INT32 argc, CHAR **argv) {
  PIN_Init(argc, argv);

  CODECACHE_AddTraceInsertedFunction(FirstInCC, 0);

  // Never returns
  PIN_StartProgram();

  return 0;
}
