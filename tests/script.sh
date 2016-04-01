#!/bin/sh

dir="tests"

rm -f $dir/**/*.cor

for subdir in `ls $dir`
do
	if [ $subdir != "script.sh" ]
	then
		for file in `ls "$dir/$subdir/goods"`
		do
			echo "$dir/$subdir/goods/$file"
			if [ $1 ] && [ $1 = "-d" ]
			then
				~/.brew/Cellar/valgrind/3.11.0/bin/valgrind --leak-check=full ./asm "$dir/$subdir/goods/$file"
			else
				./asm "$dir/$subdir/goods/$file" | tail -n 1
				./asm -a "$dir/$subdir/goods/$file" > /dev/null
			fi
		done
		for file in `ls "$dir/$subdir/errors"`
		do
			echo "$dir/$subdir/errors/$file"
			if [ $1 ] && [ $1 = "-d" ]
			then
				~/.brew/Cellar/valgrind/3.11.0/bin/valgrind --leak-check=full ./asm "$dir/$subdir/errors/$file"
			else
				./asm "$dir/$subdir/errors/$file" | tail -n 1
				./asm -a "$dir/$subdir/errors/$file" > /dev/null
			fi
		done

	fi
done
