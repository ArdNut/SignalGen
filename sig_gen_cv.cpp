//-------------------------------------------------------------------
// sig_gen_cv.cpp
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

void SetCV()
{
    if (fpls) {
        cval = ' ';
        docv = true;
    }
    else if (fmn) {
        cval = 'X';
        docv = false;
    }
    else if (rpls) {
        if (docv) {
            set_cvzero = true;
        }
    }
    else if (rmn) {
        if (docv) {
            reset_cvzero = true;
        }
    }

    if (sel) {
        currmode = MODE_DISP;
    }
}


void ShowCV()
{
    SetLCDVals();

    if (currmode == MODE_CV) {
        blinkCursor(LCD_CCLN,LCD_CROW,true);
    }
    else {
        blinkCursor(LCD_CCLN,LCD_CROW,false);
    }
}


unsigned long RunCV()
{
    fvalset = fval;

    if (docv) {
        cvinval = analogRead(IN_CV);

        if (set_cvzero) {
            set_cvzero = false;
            cvzero = cvinval;
        }

        if (reset_cvzero) {
            reset_cvzero = false;
            cvzero = DEF_CVZERO;
        }

        if (cvinval > cvzero) {
            cpol = '+';
            fvalset = fval + (fval * (cvinval/CV_DIV));
        }
        else if (cvinval < cvzero) {
            cpol = '-';
            fvalset = fval - (fval * (cvinval/CV_DIV));
        }
        else {
            cpol = '0';
        }
    }

    return fvalset;
}
