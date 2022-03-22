/*
 * CYANCORE LICENSE
 * Copyrights (C) 2019, Cyancore Team
 *
 * File Name		: project.c
 * Description		: This file consists of project srouces
 * Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
 * Organisation		: Cyancore Core-Team
 */

#include <stdio.h>
#include <status.h>
#include <terravisor/platform.h>
#include <terravisor/bootstrap.h>
#include <driver.h>
#include <driver/watchdog.h>
#include <hal/gpio.h>
#include <arch.h>

static gpio_port_t led_13;

void plug()
{
	bootstrap();
	driver_setup_all();
	gpio_pin_alloc(&led_13, PORTB, 5);
	gpio_pin_mode(&led_13, out);
	gpio_pin_clear(&led_13);

	extern void test();
	test();


	printf("Demo Program!\n");
	printf("< ! > Running Blinky ... [");
	return;
}

char progress[] = "-\\|/";

static int i = 0;
void play()
{
	wdog_guard(2, true, NULL);
	gpio_pin_toggle(&led_13);
	printf("%c]", progress[i]);
	wdog_hush();
	arch_wfi();
	printf("\b\b");
	return;
}

void temp()
{
	i++;
	i = i & 3;
}
