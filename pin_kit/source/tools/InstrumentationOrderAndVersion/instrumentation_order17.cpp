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
#include <assert.h>

#include <fstream>
#include <iostream>

#include "instrumentation_order_app.h"
#include "pin.H"

static ofstream outstream("instrumentation_order17.out");

void Emit(char const *message) { outstream << message << endl; }

static VOID Image(IMG img, VOID *v) {
  RTN rtn = RTN_FindByName(img, watch_rtn);

  if (!RTN_Valid(rtn)) {
    return;
  }
  printf("Image Instrumenting %s\n", watch_rtn);
  RTN_Open(rtn);
  INS ins = RTN_InsHeadOnly(rtn);
  ASSERTX(INS_Valid(ins));

  INS_InsertCall(ins, IPOINT_BEFORE, AFUNPTR(Emit), IARG_PTR,
                 "IMG instrumentation2", IARG_CALL_ORDER, CALL_ORDER_FIRST + 2,
                 IARG_END);
  RTN_InsertCall(rtn, IPOINT_BEFORE, AFUNPTR(Emit), IARG_PTR,
                 "IMG instrumentation1", IARG_CALL_ORDER, CALL_ORDER_FIRST + 2,
                 IARG_END);
  RTN_Close(rtn);
}

static VOID Fini(INT32 code, VOID *v) { outstream.close(); }

int main(int argc, char *argv[]) {
  PIN_InitSymbols();
  PIN_Init(argc, argv);

  IMG_AddInstrumentFunction(Image, 0);

  PIN_AddFiniFunction(Fini, 0);

  // Start the program, never returns
  PIN_StartProgram();

  return 0;
}
