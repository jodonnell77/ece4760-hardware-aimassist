/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "tusb.h"
#include "bsp/board.h"
#include "pico/stdlib.h"
void hid_task(void);


#define LED_PIN 25

int main() {
    stdio_init_all();
    tusb_init();
        
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        hid_task();
        tud_task();
        gpio_put(LED_PIN, 1);
        printf("Hello, world!\n");
        sleep_ms(1000);
        gpio_put(LED_PIN, 0);
        sleep_ms(1000);
    }
    return 0;
}

void hid_task(void) {
    if (tud_hid_ready())
    {
        tud_hid_n_report(0x00, 0x01, 0xff, sizeof(0xff));
    }
}
