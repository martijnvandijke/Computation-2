
echo $1
mv $1 $1.old
sed -e "s/\015//g" $1.old > $1
