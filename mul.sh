multiplication_table() {
  local number=$1
  echo "multiplication_table for $number"
  for i in {1..10}
  do 
    result=$((number * i))
    echo "$number x $i = $result"
  done
}

multiplication_table $1
