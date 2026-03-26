# AUTOSAR DEM – Minimal Implementation in C

A minimal, self-contained implementation of the **AUTOSAR Diagnostic Event Manager (DEM)** module written in C, built as a hands-on learning project to reinforce Classic AUTOSAR BSW concepts.

---

## Overview

The Diagnostic Event Manager (DEM) is a core AUTOSAR BSW module responsible for:
- Monitoring and storing diagnostic fault events
- Managing Diagnostic Trouble Codes (DTCs)
- Providing APIs to upper layers (DCM, application SWCs) for event reporting and DTC access

This project implements a simplified DEM stack with AUTOSAR-aligned APIs, platform types, and a simulated application SWC that triggers faults based on sensor input.

---

## Project Structure

```
dem_projects/
├── main.c                          # Entry point – operation selection menu
├── Makefile                        # Build configuration
├── Fault_Memory.txt                # Runtime fault log (generated on execution)
├── diagnostic_code/
│   ├── dem.h                       # DEM API declarations, types, DTC definitions
│   └── dem.c                       # DEM API implementations
├── application_code/
│   └── temperature_monitor.c       # SWC-style application triggering DTCs
└── platform_types/
    └── platform_types.h            # AUTOSAR-compliant platform type definitions
```

---

## Implemented APIs

| API | Description |
|-----|-------------|
| `Dem_SetEventStatus()` | Reports an event status (e.g., Test_Failed) and logs the DTC with timestamp |
| `Dem_GetDTCOfEvent()` | Returns the DTC associated with a given EventId in the specified format |
| `Dem_ClearDTC()` | Clears the fault memory log |
| `Dem_GetEventUdsStatus()`| Returns the Fault Memory information from the logs |

---

## Supported DTCs

| EventId | DTC | Fault Description |
|---------|-----|-------------------|
| `Over_temperature` (0) | `0x1100` | Temperature exceeded threshold |
| `Sensor_is_Open` (1) | `0x1200` | Sensor open circuit detected |

---

## Event Status Types

Modelled on `Dem_UdsStatusByteType` from the AUTOSAR SWS DEM specification:

- `Test_Failed`
- `Test_Failed_Operation_Cycle`
- `Pending_DTC`
- `Confirmed_DTC`
- `Test_Not_Completed_Since_Last_Clear`
- `Test_Failed_Since_Last_Clear`
- `Test_Not_Completed_This_Operation_Cycle`
- `Warning_Indicator_Request`

---

## How to Build and Run

### Prerequisites
- GCC (or any C compiler)
- Make

### Build
```bash
make
```

### Run
```bash
./dem_project
```

You will be prompted to choose an operation:
```
Enter which operation need to execute now
 1. Monitor temperature
 2. Clear fault Memory
```

**Option 1 – Temperature Monitor:**
Enter a temperature value. If the value is 0, a `Sensor_is_Open` DTC is triggered. If the value is above 29, an `Over_temperature` DTC is triggered. The fault is logged to `Fault_Memory.txt` with a timestamp.

**Option 2 – Clear Fault Memory:**
Clears the contents of `Fault_Memory.txt`.

---

## Sample Fault Memory Output

```
0 4352
0 4352
1 4608
1 4608
1 4608
0 4352
```

*(DTC values are decimal representations of 0x1200 and 0x1100 respectively)*

---

## Key Design Decisions

- **AUTOSAR-aligned naming**: API names, types, and enumerations follow the AUTOSAR SWS DEM specification to reflect real BSW conventions.
- **Platform type abstraction**: `platform_types.h` provides `uint8`, `uint16`, `uint32`, and `Std_ReturnType` — consistent with AUTOSAR Classic platform abstractions.
- **Separation of concerns**: Diagnostic logic (`diagnostic_code/`) is cleanly separated from application logic (`application_code/`), mirroring the BSW/SWC layered architecture.

---

## Limitations and Planned Improvements

This is an intentionally minimal implementation for learning purposes. Planned improvements:

- [ ] Fix `Dem_SetEventStatus` to update in-memory event status correctly
- [ ] Add `Dem_GetEventStatus` API
- [ ] Support multiple simultaneous fault events (event array instead of single struct)
- [ ] Add debounce counter logic
- [ ] Add operation cycle management (`Dem_SetOperationCycleState`)

---

## AUTOSAR Context

This project is inspired by the **AUTOSAR Classic BSW DEM module** as defined in:
- AUTOSAR SWS Diagnostic Event Manager (`AUTOSAR_SWS_DiagnosticEventManager.pdf`)
- ISO 14229-1 (UDS – Unified Dciagnostic Services)

> **Note:** This is a personal learning project and is not affiliated with or derived from any production AUTOSAR stack (e.g., Vector MICROSAR).

---

## Author

**Venkatesh Balasubramanian**  
Senior Embedded Software Engineer | Classic AUTOSAR BSW  
[LinkedIn](https://linkedin.com/in/venkatesh-balasubramanian-2060b91b6/)
