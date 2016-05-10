// sig_gen.h

#ifndef SIGGEN_H
#define SIGGEN_H

// Control PB inputs
#define SW_FPLS     8
#define SW_FMIN     9
#define SW_RPLS     10
#define SW_RMIN     11
#define SW_MODE     A1
#define SW_SLCT     A0
#define HOLD_CNT    10      // button hold-down count

// Gate and CV inputs
#define IN_GATE     A2
#define IN_CV       A3

// LCD module pin name
#define LCD_D4      2
#define LCD_D5      3
#define LCD_D6      4
#define LCD_D7      5
#define LCD_RS      6
#define LCD_E       7

// DDS module pin names and clock freq
#define DDS_FQ_UP   0
#define DDS_W_CLK   1
#define DDS_RESET   12
#define DDS_DATA    13
#define DDS_OSC     125000000LL

// Control input modes
#define MODE_DISP   0
#define MODE_GATE   1
#define MODE_CV     2

// control input parameters
#define DBDLY       10     // ms
#define FSTEP1      10
#define FSTEP2      100
#define FSTEP3      1000
#define RSTEP       10000
#define FMAX        40000000
#define RMAX        4000

// main loop delay and DDS update timing
#define MAIN_DLY    200     // ms
#define DDS_LOAD_GO 3       // F update internal = DDS_LOAD_GO * MAIN_DLY

// LCD position values
#define LCD_FSYM    0
#define LCD_FCOL    2
#define LCD_FROW    0

#define LCD_RSYM    0
#define LCD_RCOL    2
#define LCD_RROW    1

#define LCD_GCOL    15
#define LCD_GROW    0
#define LCD_GCLN    14
#define LCD_GSYM    13

#define LCD_CCOL    15
#define LCD_CROW    1
#define LCD_CCLN    14
#define LCD_CSYM    13

// Gate min value
#define GATE_PVAL   768
#define GATE_NVAL   256

// CV values
#define DEF_CVZERO  512
#define CV_DIV      1000

#endif
