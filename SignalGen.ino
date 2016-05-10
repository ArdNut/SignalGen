#include <LiquidCrystal.h>
#include <DDS.h>

#include "sig_gen.h"
#include "sig_gen_gv.h"
#include "sig_gen_lcd.h"
#include "sig_gen_control.h"
#include "sig_gen_gate.h"
#include "sig_gen_cv.h"

void setup() {
    lcd->begin(16, 2);  // Set the dimensions of the LCD

    TitleDisp1();

    pinMode(SW_FPLS, INPUT);
    pinMode(SW_FMIN, INPUT);
    pinMode(SW_RPLS, INPUT);
    pinMode(SW_RMIN, INPUT);
    pinMode(SW_MODE, INPUT);
    pinMode(SW_SLCT, INPUT);

    TitleDisp2();

    InitLCDFields();
}


void loop() {
    // read switch states
    readControls();

    // handle control modes
    SetMode();
    switch(currmode) {
        case MODE_DISP:
            getFreq();
            SetLCDVals();
            ShowGate();
            ShowCV();
            break;
        case MODE_GATE:
            SetGate();
            ShowGate();
            break;
        case MODE_CV:
            SetCV();
            ShowCV();
            break;
    }

    // check for active CV input
    fval = RunCV();

    // set dds output frequency
    dds_load_cnt++;
    if (dds_load_cnt >= DDS_LOAD_GO) {
        dds_load_cnt = 0;

        if (RunGate()) {
            ddsdev->setFrequency(fval);
        }
        else {
            ddsdev->setFrequency(0);
        }
    }

    delay(MAIN_DLY);
}




