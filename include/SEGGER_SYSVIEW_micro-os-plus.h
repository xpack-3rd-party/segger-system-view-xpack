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

#ifndef SYSVIEW_MICRO_OS_PLUS_H_
#define SYSVIEW_MICRO_OS_PLUS_H_

/*
 * API functions
 */
#ifdef __cplusplus
extern "C" {

void SYSVIEW_SendTaskInfo (os::rtos::thread* pThread);

}
#endif

#endif // SYSVIEW_MICRO_OS_PLUS_H_
