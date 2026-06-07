#include <stdint.h>

#define MMIO_BASE 0x3F000000UL
#define GPFSEL1 ((volatile uint32_t *)(MMIO_BASE + 0x200004))
#define GPSET0 ((volatile uint32_t *)(MMIO_BASE + 0x20001C))
#define GPCLR0 ((volatile uint32_t *)(MMIO_BASE + 0x200028))

static void delay_cycles(uint32_t cycles) {
  while (cycles--) {
    __asm__ volatile("nop");
  }
}

void kernel_main(void) {
  uint32_t reg = *GPFSEL1;
  reg &= ~(7u << 18); // GPIO16 function bits
  reg |= (1u << 18);  // GPIO16 as output
  *GPFSEL1 = reg;

  while (1) {
    *GPSET0 = (1u << 16);
    delay_cycles(500000);
    *GPCLR0 = (1u << 16);
    delay_cycles(500000);
  }
}
