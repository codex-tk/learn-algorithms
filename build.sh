#!/bin/sh
if [ ! -d "./output" ]; then
  mkdir output
fi

cd output
cmake ..
make -j 4

if [ $? -eq 0 ]; then
	cd ./srcs
	./alg-impl
fi
