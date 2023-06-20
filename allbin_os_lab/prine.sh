echo "Enter a Number"
read a
flag=0
i=2
while [ $i -le `expr $a / 2` ]
do
if [ ` expr $a % $i ` -eq 0 ]
then
flag=1
fi
i=`expr $i + 1`
done
if [ $a -eq 1 ]
then
	echo "Number is not Prime"
else
	if [ `expr $flag` -eq 0 ]
	then 
		echo "Number is Prime"
	else 
		echo "Number is not Prime"
	fi
fi
