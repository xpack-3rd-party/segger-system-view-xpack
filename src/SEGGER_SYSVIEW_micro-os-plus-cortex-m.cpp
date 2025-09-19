/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2016-2025 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
 */

#include "SEGGER_SYSVIEW.h"
#include <cmsis-plus/rtos/os.h>
#include "SEGGER_SYSVIEW_micro-os-plus.h"

// ----------------------------------------------------------------------------

static void
iterate_threads (os::rtos::thread* th = nullptr, unsigned int depth = 0);

// ----------------------------------------------------------------------------

#if 0
/*
 * This function is part of the link between FreeRTOS and SYSVIEW.
 * Called from SystemView when asked by the host, returns the
 * current system time in micro seconds.
 */
static U64
_cbGetTime (void)
{
  U64 Time;

  Time = os::rtos::hrclock.now();
  return Time;
}
#endif

/*
 * This function is part of the link between FreeRTOS and SYSVIEW.
 * Called from SystemView when asked by the host, it uses SYSVIEW
 * functions to send the entire task list to the host.
 */
static void
_cbSendResourcesLists (void)
{
  iterate_threads ();
}

static void
iterate_threads (os::rtos::thread* th, unsigned int depth)
{
#pragma GCC diagnostic push
#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#endif
  for (auto&& p : os::rtos::scheduler::children_threads (th))
#pragma GCC diagnostic pop
    {
      SYSVIEW_SendTaskInfo (&p);

      iterate_threads (&p, depth + 1);
    }
}

// Callbacks provided to SYSTEMVIEW by FreeRTOS
extern "C" const SEGGER_SYSVIEW_OS_API SYSVIEW_X_OS_TraceAPI = {
  nullptr, // _cbGetTime,
  _cbSendResourcesLists,
};

// ============================================================================

/*
 * Record task information.
 */
void
SYSVIEW_SendTaskInfo (os::rtos::thread* pThread)
{
  SEGGER_SYSVIEW_TASKINFO TaskInfo;

  memset (
      &TaskInfo, 0,
      sizeof (
          TaskInfo)); // Fill all elements with 0 to allow extending the
                      // structure in future version without breaking the code
  TaskInfo.TaskID = reinterpret_cast<U32> (pThread);
  TaskInfo.sName = pThread->name ();
  TaskInfo.Prio = pThread->priority ();
  TaskInfo.StackBase = reinterpret_cast<U32> (pThread->stack ().bottom ());
  TaskInfo.StackSize = pThread->stack ().size ();

  SEGGER_SYSVIEW_SendTaskInfo (&TaskInfo);
}

// ----------------------------------------------------------------------------
