if [ "$2" = ""  ]
then 
  g++ $1.cpp -o out.exe -std=c++17 -g -Wall -Ibits
fi
./out < input.txt
# bash -c "time ./out < input.txt"