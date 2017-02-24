#!/bin/bash

: '
function quit {
	echo ES
	exit
}
function hello {
	echo HELLO!
}
hello
echo foo
quit
'

:'
for i in {0..100..10}
do 
	echo $i
done
'

:'
for((no=1;no<=100;no++))
{
	if(($no%5==0))
	then
	   echo -n "$no is divisible by 5"
	fi
}
'

####  wrong way ####
read no
for(( i = 0; i < $no; i++ ))
{
	for(( j = 0; j < ($no - $i - 1); j++ ))
	{
		echo -n " "	
	}
	for(( k = $j; k < $no; k++ ))
	{
		echo -n "*"	
	}
	echo ""
}


#for i in {1..5}
#do
#  for j in {1}



