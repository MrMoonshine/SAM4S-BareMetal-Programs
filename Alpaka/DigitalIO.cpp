#include "sam.h"
#include "DigitalIO.hpp"

DigitalOut::DigitalOut(char reg_i, unsigned char pin_i,bool mode_i){
    pin = pin_i;
    mode = mode_i;
    reg = reg_i;

    if(reg == 'A' || reg == 'a'){
        REG_PIOA_PER |= (1 << pin);   
        REG_PIOA_OER |= (1 << pin); 
    }
    else if(reg == 'B' || reg == 'b'){
        REG_PIOB_PER |= (1 << pin);
        REG_PIOB_OER |= (1 << pin);  
    }
    else if(reg == 'C' || reg == 'c'){
        REG_PIOC_PER |= (1 << pin);
        REG_PIOC_OER |= (1 << pin); 
    }
    else if(reg == 'D' || reg == 'd'){
        REG_PIOD_PER |= (1 << pin);
        REG_PIOD_OER |= (1 << pin); 
    }
    else
    return EXIT_FAILURE;
}
void DigitalOut::operator=(unsigned int x){
    if(x & 1 == 1){
        REG_PIOC_SODR |= (1 << pin); 
    }else{
        REG_PIOC_CODR |= (1 << pin)
    }
}

void DigitalOut::operator!(){
    if(read() == 0){
        REG_PIOC_SODR |= (1 << pin); 
    }else{
        REG_PIOC_CODR |= (1 << pin)
    }
}

int DigitalOut::read(){
    if(reg == 'A' || reg == 'a')
    return REG_PIOA_ODSR;
    else if(reg == 'B' || reg == 'b')
    return REG_PIOB_ODSR;
    else if(reg == 'C' || reg == 'c')
    return REG_PIOC_ODSR;
    else if(reg == 'D' || reg == 'd')
    return REG_PIOD_ODSR;
}

/*void DigitalOut::enablePull(bool dir){
    ;
}
void DigitalOut::disablePull(bool dir){
    ;
}*/
