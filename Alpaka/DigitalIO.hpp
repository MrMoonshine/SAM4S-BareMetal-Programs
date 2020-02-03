#include "sam.h"

#define OUTPUT true
#define INPUT false
#define UP true
#define DOWN false

class DigitalOut{
    unsigned char pin;
    char reg;
    bool mode;
public:
    DigitalOut(char reg_i, unsigned char pin_i,bool mode_i);
    void operator=(unsigned int x);
    void operator!();
    int read();
};

/*class DigitalIn{
    unsigned char pin;
    char reg;
    bool mode;
public:
    DigitalIO(char reg_i, unsigned char pin_i,bool mode_i);
    void enablePull(bool dir);
    void disablePull(bool dir);
    void operator=(unsigned int x);
};*/
