//-------------------------------------------------------------------
// sig_gen_gate.cpp
//
// Created for "Arduino: A Technical Reference", 2016, J. M. Hughes
// Chapter 11
//
// Copyight 2015-2016 John M. Hughes
// O'Reilly appreciates, but does not require, attribution. An attribution
// usually includes the title, author, publisher, and ISBN. For example:
// "Arduino: A Technical Reference, by John M. Hughes. Copyright 2016 O’Reilly
// Media, Inc., ISBN: 978-1-491-92176-0".
//
// If you feel your use of code examples falls outside fair use or the
// permission given above, feel free to contact permissions@oreilly.com.
//-------------------------------------------------------------------

#include "Arduino.h"
#include "sig_gen.h"
#include "sig_gen_gv.h"
#include "sig_gen_lcd.h"

void SetGate()
{
    if (fpls) {
        gval = ' ';
        dogate = true;
    }
    else if (fmn) {
        gval = 'X';
        dogate = false;
    }
    else if (rpls) {
        gpol = '+';
    }
    else if (rmn) {
        gpol = '-';
    }

    if (sel) {
        currmode = MODE_DISP;
    }
}


void ShowGate()
{
    SetLCDVals();       // update display

    if (currmode == MODE_GATE) {
        blinkCursor(LCD_GCLN,LCD_GROW,true);
    }
    else {
        blinkCursor(LCD_GCLN,LCD_GROW,false);
    }
}


bool RunGate()
{
    unsigned int gate_val = 0;

    if (dogate) {
        gate_val = analogRead(IN_GATE);

        if (gpol == '+') {
            if (gate_val > GATE_PVAL)
                return true;
            else
                return false;
        }
        else {
            if (gate_val < GATE_NVAL)
                return true;
            else
                return false;
        }
    }
    else
        return true;
}
