w='y'
while [ $w == "y" ]
do
echo "Enter the first number : "
read a
echo "enter the second number : "
read b
echo "Enter the option "
echo "1,ADDITION  2,SUBSTRATION  3,MULTIPLICATION  4,DIVISION"
read opt
case $opt in
	1)result=$((a+b));;
	2)result=$((a-b));;
	3)result=$((a*b));;
	4)result=$((a/b));;
	*)echo "invaild option"
	  exit;;
esac
echo "result is $result"
echo "Do you want to con.. (y/n)"
read w
if (($w != "y"))
then 
exit
fi
done

