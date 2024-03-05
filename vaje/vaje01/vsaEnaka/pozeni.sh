#!/bin/bash

for i in {01..10}; do
	echo $i
	./a.out < test${i}.in > test${i}.res
	diff test${i}
