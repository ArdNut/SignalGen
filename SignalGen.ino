//-------------------------------------------------------------------
// SignalGen.ino
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

#include <LiquidCrystal.h>
#include <DDS.h>

#include "sig_gen.h"
#include "sig_gen_gv.h"
#include "sig_gen_lcd.h"
#include "sig_gen_control.h"
#include "sig_gen_gate.h"
#include "sig_gen_cv.h"


void setup() {
    lcd->begin(16, 2);          // Set the dimensions of the LCD

    TitleDisp1();               // 1st half of title display

    pinMode(SW_FPLS, INPUT);    // Control button inputs
    pinMode(SW_FMIN, INPUT);
    pinMode(SW_RPLS, INPUT);
    pinMode(SW_RMIN, INPUT);
    pinMode(SW_MODE, INPUT);
    pinMode(SW_SLCT, INPUT);

    TitleDisp2();               // 2nd half

    InitLCDFields();            // init data fields
}


void loop() {
    // read switch states
    readControls();

    // handle control modes
    SetMode();
    switch(currmode) {
        case MODE_DISP:
            getFreq();          // scan for buttons
            ShowGate();         // display current control gate status
            ShowCV();           // display current CV status
            break;
        case MODE_GATE:
            SetGate();          // check buttons for gate mode
            ShowGate();         // display current control gate status
            break;
        case MODE_CV:
            SetCV();            // check buttons for CV mode
            ShowCV();           // display current CV status
            break;
    }

    // check for active CV input and get freq
    fval = RunCV();

    // set dds output frequency
    dds_load_cnt++;
    if (dds_load_cnt >= DDS_LOAD_GO) {
        dds_load_cnt = 0;

        // enable or disable based on control gate
        if (RunGate()) {
            ddsdev->setFrequency(fval);
        }
        else {
            ddsdev->setFrequency(0);
        }
    }

    delay(MAIN_DLY);
}




