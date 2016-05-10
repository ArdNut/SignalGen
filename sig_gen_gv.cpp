// sig_gen_gv.cpp

#include "Arduino.h"
#include <LiquidCrystal.h>
#include <DDS.h>
#include "sig_gen.h"

// initialize the LCD and DDS objects and map digital pins
LiquidCrystal *lcd = new LiquidCrystal(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
DDS *ddsdev = new DDS(DDS_OSC, DDS_DATA, DDS_FQ_UP, DDS_W_CLK, DDS_RESET);

// alternate form
//LiquidCrystal lcdobj(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
//DDS ddsobj(DDS_OSC, DDS_DATA, DDS_FQ_UP, DDS_W_CLK, DDS_RESET);
//LiquidCrystal *lcd = &lcdobj;
//DDS *ddsdev = &ddsobj;

// button input values (0 or 1)
int  fpls      = 0;
int  fmn       = 0;
int  rpls      = 0;
int  rmn       = 0;
int  mode      = 0;
int  sel       = 0;

int  last_fpls = 0;
int  last_fmn  = 0;
int  last_rpls = 0;
int  last_rmn  = 0;

int  mode_cnt  = 2;          // mode cycle counter
bool new_mode  = false;      // true if mode has changed
int  btncnt    = 0;             // used to detect button hold-down
bool btnhold   = false;      // true if button is held down

int dds_load_cnt = 0;       // update cycle delay counter for DDS update

// output control settings
unsigned long fval = 1000;
unsigned int rval  = 1;

char gval = 'X';
char gpol = '+';

char cval = 'X';
char cpol = '0';

bool dogate = false;
bool docv = false;

bool gate_output = true;

bool set_cvzero = false;
bool reset_cvzero = false;

unsigned long cv_zero  = 512;
unsigned long cv_input = 0; // latest value from CV input

int currmode = MODE_DISP;   // init starting control input mode

// CV input
unsigned int cvinval;
unsigned int cvzero;
unsigned int fvalset;
