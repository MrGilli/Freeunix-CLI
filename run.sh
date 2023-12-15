#!/bin/bash

make clean

# Compile
make

# Run the compiled file using QEMU (change this command as needed)
qemu-system-arm -M raspi2 -kernel kemieBSD
