test : test.o Serial.o 
	g++ test.o Serial.o -o test

test.o : Serial/test.cpp Serial/Serial.cpp
	g++ -c -I serial_exception/ Serial/test.cpp -o test.o

Serial.o : Serial/Serial.cpp 
	g++ -c -I serial_exception/ Serial/Serial.cpp -o Serial.o


clean : 
	rm -rf *.o
