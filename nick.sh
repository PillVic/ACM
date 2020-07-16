#!/bin/bash

#comparing the output different between answer and the program

while true; do
    ./data > input
    cat input | ./answer > answer.out
    cat input | ./main > main.out
    diff answer.out main.out
    if [ $? -ne 0 ] ; then 
	break
    else
	echo "AC"
    fi
done

echo "answer:"
cat answer.out
echo "main:"
cat main.out
