#include "Nintendo.h"
/* This code uses the Nicohood Library
 * This code also uses the USB Host Shield Library 2.0 by Felis/Lauszus
 * I used Simple Controllers/Froq's SmashBox code as a basis to develop this. They also aided me previously! so thank you.
 * Without the three mentioned above, I wouldn't have been able to do this. So Thanks!
 *This Code written/modified by That's So Mo
 *This code is open source and its free to share, improve on, modify or anything you like!
*/

#include <XBOXRECV.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
XBOXRECV Xbox(&Usb);
//This makes the controller bidirection data line on pin number 8
CGamecubeConsole GamecubeConsole1(8);      //Defines a "Gamecube Console" sending data to the console on pin 8
Gamecube_Data_t d = defaultGamecubeData;   //Structure for data to be sent to console

//This is needed but you don't need a controller on pin 7
CGamecubeController GamecubeController1(7);


void setup()
{
  //This is establishing the pin assignments up there to input pins


  //This is needed to run the code.
  GamecubeController1.read();
   Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nXbox Wireless Receiver Library Started"));
}


void loop()
{
  Usb.Task();
  if (Xbox.XboxReceiverConnected) {
    for (uint8_t i = 0; i < 4; i++) {
      if (Xbox.Xbox360Connected[i]) {
        Xbox.setLedOn(LED1, i);
      
  //This resets and establishes all the values after the controller sends them to the console and helps with initial "zeroing"
  int pinA = 0;
  int pinB = 0;
  int pinX = 0;
  int pinY = 0;
  int pinZ = 0;
  int pinSTART = 0;
  int pinR = 0;
  int pinL = 0;
  int pinLEFT = 0;
  int pinRIGHT = 0;
  int pinUP = 0;
  int pinDOWN = 0;
  int pinCLEFT = 0;
  int pinCRIGHT = 0;
  int pinCUP = 0;
  int pinCDOWN = 0;
  int pinxAxisC = 128;
  int pinyAxisC = 128;
  int pinxAxis = 128;
  int xmod = 0;
  int pinyAxis = 128;
  int rightOne = 0;
  int leftOne = 0;
  int downOne = 0;

  

        if (Xbox.getButtonPress(B, i)){
            pinB = 1;
            }
            
        if (Xbox.getButtonClick(XBOX, i)){ // This combination allows you to restart the GameCube - only useful if your using swiss to load games...etc.
            pinB = 1;
            pinR = 1;
            pinZ = 1;
            pinDOWN = 1;
            }            
 
        if (Xbox.getButtonPress(A, i)){
            pinA = 1;}

        if (Xbox.getButtonPress(X, i)){
            pinX = 1;}
 
        if (Xbox.getButtonPress(Y, i)){
            pinY = 1;}

        if (Xbox.getButtonPress(UP, i)){
            pinUP = 1;
            }
 
        if (Xbox.getButtonPress(DOWN, i)){
            pinDOWN = 1;
            }

        if (Xbox.getButtonPress(LEFT, i)){
            pinLEFT = 1;
            }
 
        if (Xbox.getButtonPress(RIGHT, i)){
            pinRIGHT = 1;        
            }            

        if (Xbox.getButtonPress(R2, i)){
            pinZ = 1;}
            
        if (Xbox.getButtonPress(R1, i)){
            pinR = 1;}

        if (Xbox.getButtonPress(L1, i)){
            pinL = 1;}                          
        
        if (Xbox.getButtonPress(START, i)){
            pinSTART = 1;}
            
        if (Xbox.getAnalogHat(LeftHatX, i) > 10000) { //When the left stick X axis of the Xbox controller is greater than 10000 (stick is tilted to the right) = GC Left stick - X-axis right.
          pinxAxis = 128+86;}
        
        if (Xbox.getAnalogHat(LeftHatX, i) < -10000) { //Basically, doing the code this way means that it removes the acturate positioning of the joysticks and implements just a simple up down left right position.
          pinxAxis = 128-86;}
        
        if (Xbox.getAnalogHat(LeftHatY, i) > 10000) {
          pinyAxis = 128+86;}
        
        if (Xbox.getAnalogHat(LeftHatY, i) < -10000) {
          pinyAxis = 128-86;}              

        if (Xbox.getAnalogHat(RightHatX, i) > 10000) {
          pinxAxisC = 128+86;}
        
        if (Xbox.getAnalogHat(RightHatX, i) < -10000) {
          pinxAxisC = 128-86;}
        
        if (Xbox.getAnalogHat(RightHatY, i) > 10000) {
          pinyAxisC = 128+86;}
        
        if (Xbox.getAnalogHat(RightHatY, i) < -10000) {
          pinyAxisC = 128-86;}  

  //reports data'
  d.report.a = pinA;
  d.report.b = pinB;
  d.report.x = pinX;
  d.report.y = pinY;
  d.report.z = pinZ;
  d.report.start = pinSTART;
  d.report.r = pinR;
  d.report.l = pinL;
  d.report.dup = pinUP;
  d.report.dright = pinRIGHT;
  d.report.ddown = pinDOWN;
  d.report.dleft = pinLEFT;  
  d.report.xAxis = pinxAxis;
  d.report.yAxis = pinyAxis;
  d.report.cxAxis = pinxAxisC;
  d.report.cyAxis = pinyAxisC;
  //sends the complied data to console when console polls for the input
  GamecubeConsole1.write(d);
  }
    }
  }
}
