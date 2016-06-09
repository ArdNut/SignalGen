//-------------------------------------------------------------------
// sig_gen_lcd.h
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

#ifndef SIGGENLCD_H
#define SIGGENLCD_H

void TitleDisp1();
void TitleDisp2();
void InitLCDFields();
void SetLCDVals();
void blinkCursor(int row, int col, bool mode);

#endif
