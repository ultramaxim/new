param=$1;
name=$0
#echo "script: $name with: $param"
time ./main.img $param &
j=0;
pid=$!
while [ "`ps ax -o pid | grep $pid`" != "" ]; do
taskset -c -p $((j)) $pid
j=$((j^1));
done
time ./main.img $param
