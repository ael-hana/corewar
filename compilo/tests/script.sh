#!/bin/sh

dir="tests"

for subdir in `ls $dir`
do
	if [ $subdir != "script.sh" ]
	then
		for file in `ls "$dir/$subdir/goods"`
		do
			echo "$dir/$subdir/goods/$file"
			if [ $1 ] && [ $1 = "-d" ]
			then
				valgrind --leak-check=full ./asm "$dir/$subdir/goods/$file"
			else
				./asm "$dir/$subdir/goods/$file" | tail -n 1
			fi
		done
		for file in `ls "$dir/$subdir/errors"`
		do
			echo "$dir/$subdir/errors/$file"
			if [ $1 ] && [ $1 = "-d" ]
			then
				valgrind --leak-check=full ./asm "$dir/$subdir/errors/$file"
			else
				./asm "$dir/$subdir/errors/$file" | tail -n 1
			fi
		done
	fi
done
