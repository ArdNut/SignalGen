// sig_gen_gate.cpp

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
    SetLCDVals();

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
