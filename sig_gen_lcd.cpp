//-------------------------------------------------------------------
// sig_gen_lcd.cpp
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
#include <LiquidCrystal.h>
#include "sig_gen.h"
#include "sig_gen_gv.h"


void TitleDisp1()
{
    // display start-up text and init the I/O pins
    lcd->setCursor(0, 0);
    lcd->print("DDS Signal Gen");
    delay(500);
    lcd->setCursor(0, 1);
    lcd->print("Initializing...");
    delay(1000);
}


void TitleDisp2()
{
    lcd->setCursor(0, 1);
    lcd->print("Ready          ");
    delay(2000);
    lcd->clear();
}


// First time LCD field initialization
void InitLCDFields()
{
    // Set up the LCD fields
    lcd->clear();

    lcd->setCursor(LCD_FSYM, LCD_FROW);
    lcd->print("F:");
    lcd->setCursor(LCD_RSYM, LCD_RROW);
    lcd->print("R:");
    lcd->setCursor(LCD_GSYM, LCD_GROW);
    lcd->print("G:");
    lcd->setCursor(LCD_CSYM, LCD_CROW);
    lcd->print("C:");
}


// Re-write values to LCD
void SetLCDVals()
{
    // print current freq value
    lcd->setCursor(LCD_FCOL, LCD_FROW);
    lcd->print("        ");
    lcd->setCursor(LCD_FCOL, LCD_FROW);
    lcd->print(fval);

    // print current range value
    lcd->setCursor(LCD_RCOL, LCD_RROW);
    lcd->print(rval);

    // update gate field and value
    lcd->setCursor(LCD_GSYM, LCD_GROW);
    lcd->print("G:");
    lcd->setCursor(LCD_GCOL, LCD_GROW);
    lcd->print(gval);
    if (dogate) {
        lcd->setCursor(LCD_GCOL, LCD_GROW);
        lcd->print(gpol);
    }

    // update CV field and value
    lcd->setCursor(LCD_CSYM, LCD_CROW);
    lcd->print("C:");
    lcd->setCursor(LCD_CCOL, LCD_CROW);
    lcd->print(cval);
    if (docv) {
        lcd->setCursor(LCD_CCOL, LCD_CROW);
        lcd->print(cpol);
    }
}


void blinkCursor(int row, int col, bool mode)
{
    if (mode) {
        lcd->setCursor(row, col);
        lcd->cursor();
        lcd->blink();
    }
    else {
        lcd->noBlink();
        lcd->noCursor();
    }
}
