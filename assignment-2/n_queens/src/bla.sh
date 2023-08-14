#! /bin/bash

javac filename.java
for parameter1 in 1 2 4 6 8 10 12 14 16
do
	for parameter2 in 14 16
	do
		java filename parameter1 parameter2
	done
done