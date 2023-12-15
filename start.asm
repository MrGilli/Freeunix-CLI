.section .text
    .align 2
    .global _start

    .equ    MAGIC, 0x1BADB002
    .equ    FLAGS, 0x00

_start:
    cpsid   i               @ Disable IRQs (Disable Interrupts)
    ldr     sp, =stack      @ Set stack pointer

    bl      kernel_early    @ Call kernel_early function (if defined)
    
    bl      main            @ Call main function (if defined)

loop:
    b       loop            @ Infinite loop after main

.section .bss
    .align 2
stack:
    .space  8192            @ Define stack space

.end
