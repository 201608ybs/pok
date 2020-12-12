#!/bin/bash

make clean
make all
make run > debug.log
sleep 10
sudo killall -s9 qemu-system-i386