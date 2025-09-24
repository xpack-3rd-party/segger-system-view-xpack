# An xpm/npm package with the SEGGER RTT library

This project offers a convenient method for integrating the
[SEGGER SystemView](https://github.com/SEGGERMicro//SystemView) library
into the xpm/npm ecosystem, enabling installation as a package dependency.

The open-source project is hosted on GitHub at
[xpack-3rd-party/segger-system-view-xpack](https://github.com/xpack-3rd-party/segger-system-view-xpack).

In addition to the original SEGGER project, this fork provides
a `package.json` with npm/xpm metadata and a `CMakeLists.txt` for
seamless CMake integration.

The current version is based on **v3.60e**, dated **5 August 2025**.

Changes:

- copy `Global.h` from `Config` to `include`, to have it in the usual include path

## How to use

### Install

The easiest method to install the library into a project is via `xpm`:

```sh
xpm install github:xpack-3rd-party/segger-system-view-xpack#v3.60.5-1
```

The SEGGER SystemView library also requires SEGGER RTT:

```sh
xpm install github:xpack-3rd-party/segger-rtt-xpack#v8.56.1-2
```

### Template files

In the `templates` folder there are two header files and one source file;
copy them into the project, and possibly update them.

### CMake

If the project uses CMake, include the `CMakeLists.txt` and the
`segger::system-view` to the build.

### Other builders

Otherwise manually add the include folders and the source files mentioned in
the `CMakeLists.txt` to the build configuration.

### Macros

To enable instrumentation, pass the following to the compiler:

- `OS_INCLUDE_INSTRUMENTATION`

To enable various more specific functionality, add any of the following
to the application configuration file (`os-app-config.h`):

```c
#define OS_ENABLE_INSTRUMENTATION_SCHEDULER
#define OS_ENABLE_INSTRUMENTATION_THREAD
#define OS_ENABLE_INSTRUMENTATION_MUTEX
#define OS_ENABLE_INSTRUMENTATION_SEMAPHORE
#define OS_ENABLE_INSTRUMENTATION_MESSAGE_QUEUE
#define OS_ENABLE_INSTRUMENTATION_MEMORY_POOL
#define OS_ENABLE_INSTRUMENTATION_EVENT_FLAGS
#define OS_ENABLE_INSTRUMENTATION_CLOCK
#define OS_ENABLE_INSTRUMENTATION_CONDITION_VARIABLE
#define OS_ENABLE_INSTRUMENTATION_TIMER
#define OS_ENABLE_INSTRUMENTATION_POSIX_IO

#define OS_INCLUDE_INSTRUMENTATION_EXTRA_VALUES
```

- `OS_DISABLE_INSTRUMENTATION_AUTOSTART`

### SystemView

For Cortex-M targets, SystemView must be configured to use SWD. The default
speed (4 MHz) should be fine for regular applications.

The tracing session usually runs in tandem with a debugger (like Ozone), that
must be configured to the same 4 MHz speed.

Flash the binary to the target and place a breakpoint at `_start()`.

While execution is halted at this point, start recording on SystemView.

Resume execution in the debugger possibly placing breakpoints in the places
of interest. The SystemView timeline window will be updated live with the
new events received from the target.

## Know limitations

- currently only Cortex-M devices are supported
- support for Cortex-M0/M0+ is planned to be added in a later release

---

The original README content is provided below.

---

SystemView
==========

SEGGER SystemView target sources, configurations, and RTOS patches.

https://www.segger.com/systemview
https://wiki.segger.com/SystemView

## Included files

  * `SYSVIEW/`
    * `SEGGER_SYSVIEW.c`               - Main module for SystemView.
    * `SEGGER_SYSVIEW.h`               - Main header for SystemView.
    * `SEGGER_SYSVIEW_ConfDefaults.h`  - Default SystemView configuration.
    * `SEGGER_SYSVIEW_Int.h`           - Internal header for SystemView.
  * `SEGGER/`
    * `SEGGER.h`                       - Common header for SEGGER modules.
  * `Config/`
    * `Global.h`                       - Global configuration for SEGGER modules.
    * `SEGGER_SYSVIEW_Conf.h`          - SystemView configuration file.
  * `Sample/`
    * `COMM/`
      * `IP/`                          - Examples for SystemView IP Recorder implementation.
      * `UART/`                        - Examples for SystemView UART Recorder implementation.
      * `SEGGER_SYSVIEW_REC.*`         - Implementation of Recorder state machine.
    * `embOS/`
      * `SEGGER_SYSVIEW_embOS.*`       - SystemView RTOS Interface for embOS.
      * `SEGGER_SYSVIEW_embOS_Ultra.*` - SystemView RTOS Interface for embOS-Ultra.
      * `Config/`                      - Example SystemView Target Configuration with embOS.
    * `FreeRTOSV8/`
      * `SEGGER_SYSVIEW_FreeRTOS.*`    - SystemView RTOS Interface for FreeRTOS V8.
      * `Config/`                      - Example SystemView Target Configuration with FreeRTOS V8.
      * `Patch/`
        * `FreeRTOSV8.2.3_Core.patch`  - Patch for SystemView instrumentation of FreeRTOS V8.2.3.
    * `FreeRTOSV9/`
      * `SEGGER_SYSVIEW_FreeRTOS.*`    - SystemView RTOS Interface for FreeRTOS V9.
      * `Config/`                      - Example SystemView Target Configuration with FreeRTOS V9.
      * `Patch/`
        * `FreeRTOSV9_Core.patch`      - Patch for SystemView instrumentation of FreeRTOS V9.
    * `FreeRTOSV10/`
      * `SEGGER_SYSVIEW_FreeRTOS.*`    - SystemView RTOS Interface for FreeRTOS V10.
      * `Config/`                      - Example SystemView Target Configuration with FreeRTOS V10.
      * `Patch/`
        * `FreeRTOSV10_Core.patch`     - Patch for SystemView instrumentation of FreeRTOS V10.
        * `FreeRTOSV10_Amazon_Core.patch`  - Patch for SystemView instrumentation of Amazon FreeRTOS V10.
    * `FreeRTOSV10.4/`
      * `SEGGER_SYSVIEW_FreeRTOS.*`    - SystemView RTOS Interface for FreeRTOS V10.4.
      * `Config/`                      - Example SystemView Target Configuration with FreeRTOS V10.4.
      * `Patch/`
        * `FreeRTOS_10_4_3.patch`      - Patch for SystemView instrumentation of FreeRTOS V10.4.
    * `FreeRTOSV11/`
      * `SEGGER_SYSVIEW_FreeRTOS.*`    - SystemView RTOS Interface for FreeRTOS V11.
      * `Config/`                      - Example SystemView Target Configuration with FreeRTOS V11.
    * `MicriumOSKernel/`
      * `SEGGER_SYSVIEW_MicriumOSKernel.c` - SystemView RTOS Interface for Micrium OS.
      * `os_trace_events.h`            - SystemView RTOS Interface header for Micrium OS.
      * `Config/`                      - Example SystemView Target Configuration with Micrium OS.
    * `NuttX`
      * `SEGGER_SYSVIEW_NuttX.*`       - SystemView RTOS Interface for NuttX.
      * `Config/`                      - Example SystemView Target Configuration with NuttX.
      * `Patch/`
        * `nuttx-8.2.diff`             - Patch for SystemView instrumentation of NuttX.
    * `NoOS/`
      * `Config/`                      - Example SystemView Target Configuration with no RTOS.
    * `ThreadX`
      * `SEGGER_SYSVIEW_ThreadX.*`     - SystemView RTOS Interface for ThreadX.
      * `Config/`                      - Example SystemView Target Configuration with ThreadX.
    * `uCOS-II/`
      * `SEGGER_SYSVIEW_uCOSII.c`      - SystemView RTOS Interface for uC/OS-II.
      * `os_trace_events.h`            - SystemView RTOS Interface header for uC/OS-II.
      * `Config/`                      - Example SystemView Target Configuration with uC/OS-II.
    * `uCOS-III/`
      * `SEGGER_SYSVIEW_uCOSIII.c`     - SystemView RTOS Interface for uC/OS-III.
      * `os_trace_events.h`            - SystemView RTOS Interface header for uC/OS-III.
      * `Config/`                      - Example SystemView Target Configuration with uC/OS-III.

## Getting Started

Clone the SystemView repository (this one, SEGGERMicro/SystemView) and the RTT repository (SEGGERMicro/RTT) into your project.

Add include paths to:
 * `SystemView/Config`
 * `SystemView/SEGGER`
 * `SystemView/SYSVIEW`
 * `RTT/Config`
 * `RTT/RTT`

Add the sources to your project:
 * Core SystemView Sources:
   * `SystemView/SYSVIEW/*.c`
 * Core RTT Sources:
   * `RTT/RTT/*.c`
   * `RTT/RTT/*.s`
 * SystemView RTOS Interface:
   * e.g. `SystemView/Sample/embOS/SEGGER_SYSVIEW_embOS.c/.h`
 * SystemView Target Configuration:
   * e.g. `SystemView/Sample/embOS/Config/Cortex-M0/*.c`

Update `SystemView/Config/SEGGER_SYSVIEW_Conf.h` and `RTT/Config/SEGGER_RTT_Conf.h`
to match the target system.

*(Alternatively: Do not include `SystemView/Config` and `RTT/Config` and place a copy of `*_Conf.h` in the project.)*

