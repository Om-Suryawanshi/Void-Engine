# Void Engine

Bare-Metal ESP32 3D Rasterizer

## Demo

![Void Engine Demo](images/demo.gif)

## Overview

Void Engine is a lightweight, bare-metal 3D rasterization engine built specifically for the ESP32 using the ESP-IDF framework. It features a custom fixed-point mathematics library and DMA-accelerated SPI display rendering to achieve 3D graphics on microcontrollers.

## Features

* **Custom Math Library**: Optimized fixed-point vector and matrix operations (`v_math`) tailored for microcontrollers.
* **Hardware-Accelerated Rendering**: Utilizes DMA over SPI to push full 128x160 frame buffers efficiently.
* **3D Pipeline**: Includes basic 3D primitive rendering (Cubes, Pyramids), flat shading with light intensity calculation, and depth-sorting.
* **Hardware Abstraction Layer (HAL)**: Modular `v_hal` handles the display, graphics drawing (lines, triangles, pixels), and input state.
* **Core Engine Loop**: Maintains a steady update tick and dynamic render pipeline supporting wireframe, solid, or both (`v_engine`).

## Hardware Setup

The engine is currently configured for a 128x160 SPI display and a 6-button input configuration.

**Display Pinout:**
* **MOSI:** GPIO 23
* **CLK:** GPIO 18
* **CS:** GPIO 5
* **DC:** GPIO 2
* **RST:** GPIO 4

**Input Buttons:**
* **A / B:** GPIO 14 / GPIO 13
* **UP / DOWN:** GPIO 25 / GPIO 27
* **LEFT / RIGHT:** GPIO 26 / GPIO 32
