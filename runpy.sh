if [ "$2" = ""  ]
then 
  g++ $1.cpp -o out.exe -std=c++14 -g -Wall
fi
python36 input.py | bash -c "time ./out"
