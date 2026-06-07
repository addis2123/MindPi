.section ".text.boot"
.global _start

_start:
    ldr x0, =__bss_start
    ldr x1, =__bss_end

zero_bss:
    cmp x0, x1
    b.hs boot_main
    str xzr, [x0], #8
    b zero_bss

boot_main:
    bl kernel_main

hang:
    wfe
    b hang
