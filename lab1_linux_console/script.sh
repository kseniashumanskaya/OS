g++ -c -o number/number.o number/number.cpp
ar r number/number.a number/number.o
g++ -c -o vector/vector.o vector/vector.cpp -Inumber -Lnumber -lnumber
g++ -shared -o vector/libvector.so vector/vector.o
g++ -o main/main main/main.cpp -Lnumber -Lvector -lnumber -lvector -Inumber -Ivector
cd main
export LD_LIBRARY_PATH=../vector
./main
