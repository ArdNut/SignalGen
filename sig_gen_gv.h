//-------------------------------------------------------------------
// sig_gen_gv.h
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

#ifndef SIGGENGV_H
#define SIGGENGV_H

#include <LiquidCrystal.h>
#include <DDS.h>
#include "sig_gen.h"

// initialize the LCD and DDS objects and map digital pins
extern LiquidCrystal *lcd;
extern DDS *ddsdev;

// button input values (0 or 1)
extern int  fpls;
extern int  fmn;
extern int  rpls;
extern int  rmn;
extern int  mode;
extern int  sel;

extern int  last_fpls;
extern int  last_fmn;
extern int  last_rpls;
extern int  last_rmn;

extern int  mode_cnt;
extern bool new_mode;       // true if mode has changed
extern int  btncnt;         // used to detect button hold-down
extern bool btnhold;        // true if button is held down

extern int  dds_load_cnt;   // update cycle delay counter for DDS update

// output control settings
extern unsigned long fval;
extern unsigned int rval;

extern char gval;
extern char gpol;

extern char cval;
extern char cpol;

extern bool dogate;
extern bool docv;

extern bool gate_output;

extern bool set_cvzero;
extern bool reset_cvzero;

extern unsigned long cv_zero;
extern unsigned long cv_input;     // latest value from CV input

extern int currmode;        // control input mode

extern unsigned int cvinval;
extern unsigned int cvzero;
extern unsigned int fvalset;

#endif
