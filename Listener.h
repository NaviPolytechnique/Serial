#ifndef LISTENER_HEADER_H
#define LISTENER_HEADER_H

#include<iostream>
#include"Serial.h"
#include "Runnable.h"




class Listener : public Runnable{
  
public : 
  Listener(const char* portname);
  ~Listener();
  char* Listen();
  void* run();
  
private : 
  Serial* serialport;
  
};

#endif