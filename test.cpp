//
//  test.cpp
//  serial_port
//
/*
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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
