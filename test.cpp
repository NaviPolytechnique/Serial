//
//  test.cpp
//  serial_port
//
//  Created by Louis Faury on 09/06/2015.
//  Copyright (c) 2015 Louis Faury. All rights reserved.
// 
// /!\ Test class for a mBed with appropriate code 
//


#include <iostream>
#include "Serial.h"
#include "serial_exception.hpp"
#include <ctime>


using namespace std;

const char* IU_port_name = "/dev/tty.usbmodem1422";
int ret;

int main(int argc, const char * argv[]) {
    
    // Reading from port routine
    
    /* char buffer[128];
    string line;

    
    try {
        Serial InertialUnit(IU_port_name,9600);
        sleep(1);
        for (int i=0; i<100 ; i++){
            InertialUnit.readLine(buffer);
            //ret = InertialUnit.readChar(&buffer);
            cout << buffer << endl;
            sleep(0.1);
        }
        InertialUnit.Close();
    } catch(exception const& e){
        cerr << "ERR : "<< IU_port_name << " : " << e.what() << " ! " << endl;
    }*/
    
    
    
    // Writing on port routine
    
    try{
        Serial InertialUnit(IU_port_name,9600);
        cout << InertialUnit.getPortName() << endl;
        sleep(1);
        for (int i=0; i<100; ++i)
        {
            int ret = InertialUnit.writeString("a\n");
            if (ret==1) cout << "Writting succeeded" << endl;
            else cout << "Error while writing" << endl;
            sleep(1);
        }
    }
    catch (exception const& e){
        cout << "ERR : " << IU_port_name << " : " << e.what() << " ! " << endl;
    }
    return 0;
}
