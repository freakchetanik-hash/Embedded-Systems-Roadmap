# Multi Pattern LED Controller

## Overview

This project demonstrates a modular embedded firmware architecture using a custom GPIO driver.

## Features

- GPIO Driver Abstraction
- Button Input
- LED Output
- Finite State Machine
- Multiple LED Patterns
- Morse Code SOS Pattern
- Modular Function Design

## Firmware Architecture

main()
    ↓
button_update()
    ↓
current_pattern
    ↓
switch()
    ↓
pattern functions
    ↓
GPIO Driver
    ↓
STM32 Registers
    ↓
Hardware

## Concepts Learned

- Register-level GPIO programming
- Driver abstraction
- State machines
- Guard clauses
- Modular programming
- Function parameterization
