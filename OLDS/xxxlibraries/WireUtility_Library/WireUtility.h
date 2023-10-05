#include "Arduino.h"
/** This file content function to help to debug wire interface on component.

*/

/** dump a 8 bit address data memory map from addreg up to (addreg+size)
*/
 void dump(HardwareSerial &MySerial,TwoWire &ScanWire, int adddev,int addreg, int size);
 
/** read a 8 bit address data(addreg)
*/
int readRegister(TwoWire &ScanWire,int adddev,int addreg);
/** read a 16 bit address data(addreg)
*/
int readMem2(TwoWire &ScanWire,int adddev,int addreg);
/** read a 24 bit address data(addreg)
*/
int readMem3(TwoWire &ScanWire,int adddev,int addreg);

/** scan a 7 bit device address. and stop after 1st find, use scanNext to get next.
*/
int scan(HardwareSerial &MySerial,TwoWire &ScanWire);
/** scan next 7 bit device address.
if a 10bit device is found it can scanNext10bits
*/
int scanNext(HardwareSerial &MySerial,TwoWire &ScanWire);
/** scan next 10 bit device address.
*/
int scanNext10bits(HardwareSerial &MySerial,TwoWire &ScanWire);
