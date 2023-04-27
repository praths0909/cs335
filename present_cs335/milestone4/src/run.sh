#!/bin/sh

./parser --input $1
./conv <output.3ac>final.s
gcc final.s -no-pie
./a.out