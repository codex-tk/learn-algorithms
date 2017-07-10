#!/bin/sh
if [ ! -d "./output" ]; then
  mkdir output
fi

cd output
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
make -j 4

if [ $? -eq 0 ]; then
	cd ./srcs
	./alg-impl
fi
