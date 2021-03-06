// [AsmJit]
// Complete x86/x64 JIT and Remote Assembler for C++.
//
// [License]
// Zlib - See LICENSE.md file in the package.

#pragma once

#include "../build.h"
#ifndef ASMJIT_DISABLE_COMPILER

// [Dependencies - AsmJit]
#include "../x86/x86compiler.h"
#include "../x86/x86context_p.h"
#include "../x86/x86cpuinfo.h"
#include "../x86/x86inst.h"

// [Api-Begin]
#include "../apibegin.h"

namespace asmjit {

// ============================================================================
// [asmjit::X86Scheduler]
// ============================================================================

//! \internal
//!
//! X86 scheduler.
struct X86Scheduler {
  // --------------------------------------------------------------------------
  // [Construction / Destruction]
  // --------------------------------------------------------------------------

  X86Scheduler(X86Compiler* compiler, const X86CpuInfo* cpuInfo);
  ~X86Scheduler();

  // --------------------------------------------------------------------------
  // [Run]
  // --------------------------------------------------------------------------

  Error run(Node* start, Node* stop);

  // --------------------------------------------------------------------------
  // [Members]
  // --------------------------------------------------------------------------

  //! Attached compiler.
  X86Compiler* _compiler;
  //! CPU information used for scheduling.
  const X86CpuInfo* _cpuInfo;
};

} // asmjit namespace

// [Api-End]
#include "../apiend.h"

#endif // !ASMJIT_DISABLE_COMPILER
