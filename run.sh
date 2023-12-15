#!/bin/bash
clear 

make clean

# Compile
make

# Run the compiled file using QEMU (change this command as needed)
qemu-system-x86_64 freeunix-cli.iso
