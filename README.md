Lab_ArduinoNFC_VendingMachine
=============================

Code for the Mega 2560 in the vending machine at Familab.org

Written by David Sikes, any code usage from other sources is cited in the blog entry for this project on Familab.org

Compiled on 1.5.2

Modules:
    
    Credit_Card_Emulator - Main file. Contains CC strings and the associated NFC tag UIDs
   
    BitWritingHandler - Code to send data to coil as well as how to write certain chars
   
    CardStringInterpreter - Calculates LRC then writes card string passed + LRC on the end
   
    LRC_Calc - Does the actual LRC calculation then passes back a string of bits for the LRC char
   
    Notes - Misc info about pin setup and track 2 info
   
    readSerial - If a serial string comes in, passes that string back. (Does not return. Look at Credit_Card_Emulator for example on how to use.)