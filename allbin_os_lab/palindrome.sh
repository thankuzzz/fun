echo "Enter a Number: "
read n
temp=$n
s=0
num=0
while [ $n -gt 0 ]
do
s=$((n%10))
num=$((num*10+s))
n=$((n/10))
done
echo "Reverse is $((num))"
if (( $temp == $num ))
then
echo "Number is Palindrome"
else
echo "Number is Not  Palindrome"
fi
