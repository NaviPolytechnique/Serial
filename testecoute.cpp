#include <iostream>
#include "Compteur.h"
#include "Runnable.h"
#include "Thread.h"
#include "Agent.h"
#include <vector>
#include<memory>
#include <unistd.h>
#include "Serial.h"
#include "Listener.h"
#include<string>


using namespace std;

int main()
{

            Serial Xbee("/dev/ttyUSB0", 9600);
            Xbee.startListening();
            while(true){
                std::string text = Xbee.listen();
            std::cout<< "on lit :" << std::endl;
            std::cout<< text << std::endl;
            }
	
	sleep(100000);

}
