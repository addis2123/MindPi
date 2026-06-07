# MindPi

MindPi is a NEAT-inspired neural network implemented on Raspberry Pi 3B+ bare metal (64-bit mode).  
Its goal is to provide a live-trainable "mind" for robotic pets.

## Core input model

- A remote places input on the first 4 GPIO pins.
- Inputs represent:
  - positive reinforcement
  - negative reinforcement
  - punishment signals

## Memory and persistence model

- The network is organized for partial save/load from SD card files.
- Network sections are loaded into memory on demand so models can be larger than available RAM.
- Memory layout should be tuned to leverage:
  - registers
  - cache
  - RAM size limits

## Training modes

- A **dreaming state** supports background training on basic tasks such as:
  - walking
  - navigation
- Initial mind creation may require extended dream-time before user-led training begins.

## Performance roadmap

- Investigate using the onboard GPU to assist computation.
- Provide an optimizer that reorganizes saved network segments to improve load/unload behavior.
- Keep persisted network files compact, clean, and efficient over time.
