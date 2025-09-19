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

// ----------------------------------------------------------------------------

extern const SEGGER_SYSVIEW_OS_API SYSVIEW_X_OS_TraceAPI;

// Defines, configurable
// Frequency of the timestamp. Must match SEGGER_SYSVIEW_GET_TIMESTAMP in
// SEGGER_SYSVIEW_Conf.h
#define SYSVIEW_TIMESTAMP_FREQ (configCPU_CLOCK_HZ)

// System Frequency. SystemcoreClock is used in most CMSIS compatible projects.
#define SYSVIEW_CPU_FREQ configCPU_CLOCK_HZ

// The lowest RAM address used for IDs (pointers)
#define SYSVIEW_RAM_BASE (0x10000000)

// Sends SystemView description strings.
static void
_cbSendSystemDesc (void)
{
  SEGGER_SYSVIEW_SendSysDesc ("N=Test Application"); // Application name
  SEGGER_SYSVIEW_SendSysDesc ("O=µOS++"); // Operating system
  SEGGER_SYSVIEW_SendSysDesc ("D=STM32F411RE"); // Target device
  SEGGER_SYSVIEW_SendSysDesc ("C=Cortex-M4"); // Target core
  SEGGER_SYSVIEW_SendSysDesc ("I#15=SysTick"); // Interrupt #<InterruptID>
}

// Global functions
void
SEGGER_SYSVIEW_Conf (void)
{
  SEGGER_SYSVIEW_Init (
      SYSVIEW_TIMESTAMP_FREQ, // Frequency of the timestamp
      SYSVIEW_CPU_FREQ, // Frequency of the system
      &SYSVIEW_X_OS_TraceAPI, // OS-specific SEGGER_SYSVIEW_OS_API
      _cbSendSystemDesc); // Callback for application-specific description

  // Sets the RAM base address, which is subtracted from IDs in order to save
  // bandwidth.
  SEGGER_SYSVIEW_SetRAMBase (SYSVIEW_RAM_BASE);
}

// ----------------------------------------------------------------------------
