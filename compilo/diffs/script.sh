#!/bin/sh

dir="diffs"

rm -f *.cor
cp ../champions/*.s $dir
./asm $dir/*.s > /dev/null
rm -f $dir/*.s

for file in `ls $dir`
do
	if [ $file != "script.sh" ]
	then
		diff $dir/$file ../champions/$file
	fi
done
