/**
 * @file main.c
 * @author Iwan Ćulumović
 * @brief Main module.
 * 
 * @copyright Copyright (c) 2026
 * 
 */

/* ============================== INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "lvgl.h"

/* ============================== MACRO DEFINITIONS */

/* ============================== TYPE DEFINITIONS */

/* ============================== PRIVATE FUNCTION DECLARATIONS */
/** @brief Initializes LVGL GUI elements. */
static void _gui_init(void);

/** @brief LVGL task handler. */
static void _gui_task_handler(void);

/** @brief LVGL timer callback. */
static void _timer_cb(lv_timer_t *p_timer);

/* ============================== PRIVATE VARIABLES */
//! LVGL display object.
static lv_display_t *_gp_display = NULL;

//! LVGL label object.
static lv_obj_t *_gp_label = NULL;

//! LVGL timer object.
static lv_timer_t *_gp_timer = NULL;

/* ============================== PUBLIC VARIABLES */

/* ============================== PUBLIC FUNCTION DEFINITIONS */
void main(void)
{
    _gui_init();

    while (1)
    {
        _gui_task_handler();
    }
}

/* ============================== PRIVATE FUNCTION DEFINITIONS */
static void _gui_init(void)
{
    lv_result_t lv_res = LV_RESULT_INVALID;

    lv_init();

    /* Init Linux DRM display */
    _gp_display = lv_linux_drm_create();
    if (NULL == _gp_display)
    {
        fprintf(stderr, "Failed to create DRM display!\n");
        exit(1);
    }

    /* Set DRM device and automatic connector pick */
    lv_res = lv_linux_drm_set_file(_gp_display, DRM_DEVICE, -1);
    if (LV_RESULT_OK != lv_res)
    {
        fprintf(stderr, "DRM set file has failed (err %d)\n", lv_res);
        exit(1);
    }

    _gp_timer = lv_timer_create(_timer_cb, LVGL_TIMER_PERIOD_MS, NULL);
    lv_timer_ready(_gp_timer);

    /* Create a label with empty text. */
    _gp_label = lv_label_create(lv_scr_act());
    lv_label_set_text(_gp_label, "");
    lv_obj_align(_gp_label, LV_ALIGN_CENTER, 0, 0);
}

static void _gui_task_handler(void)
{
    lv_timer_handler();
    usleep(LVGL_TASK_HANDLING_PERIOD_US);
}

static void _timer_cb(lv_timer_t *p_timer)
{
    static int8_t _counter = 0;

    switch (_counter)
    {
        case 0:
        lv_label_set_text(_gp_label, "Hello!");
        break;

        case 1:
        lv_label_set_text(_gp_label, "I'm an app written ...");
        break;

        case 2:
        lv_label_set_text(_gp_label, "... using the LVGL library");
        break;
    
        default:
        break;
    }

    _counter++;
    if (3 == _counter) _counter = 0;
}

/* ============================== INTERRUPT FUNCTION DEFINITIONS */
