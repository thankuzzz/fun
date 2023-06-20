echo "read a number"
read n
echo "To find the factorial"
fact=1
for (( i=2; i<=n; i++ )) 
do
	fact=$((fact*i))
done
echo "factorial of $n = $fact"
