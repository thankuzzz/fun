echo "Enter a number"
read n
a=0
b=1
echo "The fibinoci series is : "
echo $a
echo $b
for (( i=0; i<n; i++))
do
r=$((a+b))
echo $r
a=$b
b=$r
done
