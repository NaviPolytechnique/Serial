test : test.o Serial.o 
	g++ test.o Serial.o -o test

test.o : test.cpp Serial.cpp
	g++ -c -I serial_exception/ test.cpp -o test.o

Serial.o : Serial.cpp 
	g++ -c -I serial_exception/ Serial.cpp -o Serial.o


clean : 
	rm -rf *.o
