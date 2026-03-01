/**
 * @file main.h
 * @author Iwan Ćulumović
 * @brief See main.c file.
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef __MAIN_H__
#define __MAIN_H__

/* ============================== INCLUDES */

/* ============================== MACRO DEFINITIONS */
//! DRM device.
#define DRM_DEVICE                                  ("/dev/dri/card1")

//! LVGL task handling period.
#define LVGL_TASK_HANDLING_PERIOD_US                (5000)

//! LVGL timer callback period in milliseconds.
#define LVGL_TIMER_PERIOD_MS                        (500)

/* ============================== TYPE DEFINITIONS */

/* ============================== PUBLIC FUNCTION DECLARATIONS */

#endif
