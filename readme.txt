================================================================================
              MEDICINE REMINDER SYSTEM USING LPC2148
================================================================================

PROJECT DESCRIPTION:
--------------------
This project implements a **Medicine Reminder System** on the **LPC2148 ARM7 
microcontroller**. It utilizes various embedded peripherals including:

- LCD Display (for displaying time, menu, and messages)
- RTC (Real Time Clock) for keeping track of time and date
- Keypad (for input and menu navigation)
- Buzzer (as an alert mechanism)
- GPIO Inputs (SW1, SW2) to interact with system modes and alerts

The system continuously checks the current time against a preset "medicine time."
When the RTC time matches the medicine time (within a 2-second window), the
buzzer sounds to alert the user. The alert continues until SW2 is pressed.

================================================================================
HARDWARE REQUIREMENTS:
----------------------

1. LPC2148 Development Board
2. 16x2 LCD
3. 4x4 Matrix Keypad
4. RTC (DS1307 or on-chip RTC of LPC2148)
5. Buzzer (connected to P1.24)
6. Push Button Switches:
   - SW1: Mode selection (RTC edit or Medicine time update)
   - SW2: Acknowledge medicine alert
7. Power Supply
8. Connecting Wires

================================================================================
PIN CONNECTIONS:
----------------

- LCD: Connected via data lines and control pins (check `lcd.h`)
- Keypad: Connected to GPIOs (see `keypad_defines.h`)
- RTC: Uses on-chip RTC features (`rtc.h`)
- SW1: Connected to P0.5
- SW2: Connected to P0.6
- Buzzer: Connected to P1.24

KEYPAD PIN MAPPING:
-------------------
The 4x4 matrix keypad is connected to P0.16 – P0.23 as follows:

  ROW0 -> P0.16
  ROW1 -> P0.17
  ROW2 -> P0.18
  ROW3 -> P0.19
  COL0 -> P0.20
  COL1 -> P0.21
  COL2 -> P0.22
  COL3 -> P0.23

See: `keypad_defines.h` for the exact macros.

================================================================================
SOFTWARE REQUIREMENTS:
----------------------

- Keil uVision (for code development and building)
- Flash Magic (for programming the LPC2148)
- Header files used:
  - lcd.h
  - rtc.h
  - keypad.h
  - delay.h
  - MACROS.h (for SETBIT, CLRBIT, etc.)
  - keypad_defines.h (for GPIO pin mappings of keypad)

================================================================================
HOW TO USE THE PROJECT:
-----------------------

1. **Initial Setup:**
   - Flash the compiled binary to the LPC2148 using Flash Magic.
   - Power on the board. LCD will show RTC date/time and current medicine time.

2. **Set Modes Using SW1:**
   - Press SW1 to enter menu:
     - Option 1: Edit RTC
     - Option 2: Update Medicine Time

3. **Edit RTC (Option 1):**
   - Use keypad to enter:
     - Hour, Minute, Second
     - Day, Date, Month, Year
   - Invalid entries will request re-entry.

4. **Set Medicine Time (Option 2):**
   - Press SW1 again to enter medicine time set mode.
   - Use keypad to set Hour, Minute, and Second.
   - Press Exit to return to main screen.

5. **Medicine Alert:**
   - When RTC time matches medicine time ±2 seconds:
     - LCD displays an alert
     - Buzzer sounds continuously
   - Press SW2 to stop the alert.

================================================================================
NOTES:
------

- Valid time ranges while setting:
  - Hour: 0–23
  - Minute: 0–59
  - Second: 0–59
  - Date: 1–31
  - Month: 1–12
  - Day of week: 0–6 (where 0 = Sunday)
- The buzzer toggles periodically while alert is active.
- Proper debouncing is assumed for SW1 and SW2.

================================================================================
AUTHORS / CONTRIBUTORS:
-----------------------

This project was implemented using modular code with separate header files for
each peripheral. Each module (`lcd.c`, `rtc.c`, `keypad.c`, etc.) should be
compiled along with the main `.c` file.

================================================================================
