#include "io.h" // Include necessary headers
#include "tty.h"
#include <stdint.h>

#define GPIO_BASE 0x3F200000 // GPIO base address for Raspberry Pi 2 (adjust for your model)
volatile uint32_t *gpio; // Pointer to access GPIO registers

void init_gpio() {
    gpio = (uint32_t *)GPIO_BASE; // Set gpio to the base address

    // Initialize GPIO pin 18 as an output (adjust the pin number as needed)
    *(gpio + 1) |= (1 << 18); // Set pin 18 as an output
}

void set_gpio(int pin, int value) {
    if (value)
        *(gpio + 7) = 1 << pin; // Set pin high
    else
        *(gpio + 10) = 1 << pin; // Set pin low
}

uint8_t inb(uint16_t port) {
    // Use GPIO access to read from a specific port (adjust as needed)
    uint8_t ret = *(volatile uint8_t *)(GPIO_BASE + port);
    return ret;
}

void outb(uint16_t port, uint8_t val) {
    // Use GPIO access to write to a specific port (adjust as needed)
    *(volatile uint8_t *)(GPIO_BASE + port) = val;
}

uint8_t scan(void)
{
    unsigned char brk;
    static uint8_t key = 0;
    uint8_t scan = inb(0x60);
    brk = scan & 0x80;
    scan = scan & 0x7f;
    if (brk)
	return key = 0;
    else if (scan != key)
	return key = scan;
    else
	return 0;
}

void move_cursor(int row, int col)
{
    unsigned short pos = (row * 80) + col;
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT, (unsigned char)(pos & 0xFF));
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT, (unsigned char)((pos >> 8) & 0xFF));
}

void printprompt(void)
{
    printf("\n> ");
    move_cursor(get_terminal_row(), get_terminal_col());
}

