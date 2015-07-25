#include <iostream>
#include "Serial.h"
#include "Runnable.h"
#include "Listener.h"

using namespace std;

Listener::Listener(const char* portname){
    serialport = new Serial(portname, 9600);
}

Listener::~Listener(){};

char* Listener::Listen(){
  return serialport->listen();
}


void* Listener::run(){
  serialport->startListening();
  while(true){
    char* h = Listen();
    std::cout<<"on lit"<<h<<std::endl;
  }
  
  
}