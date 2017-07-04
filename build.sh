#!/bin/sh
if [ ! -d "./output" ]; then
  mkdir output
fi

cd output
cmake ..
make -j 4
