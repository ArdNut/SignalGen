//-------------------------------------------------------------------
// sig_gen_control.cpp
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

// Simple button debounce
bool debounce(int switchid)
{
    int swval = 0;

    if (swval = digitalRead(switchid)) {
        delay(DBDLY);
        if (swval != digitalRead(switchid)) {
            return false;
        }
        else {
            return true;
        }
    }

    return false;
}


void readControls()
{
    fpls = !debounce(SW_FPLS);
    if (last_fpls != fpls) {
        last_fpls = fpls;
        btncnt = 0;
    }
    else if (fpls) {
        btncnt++;
    }

    fmn = !debounce(SW_FMIN);
    if (last_fmn != fmn) {
        last_fmn = fmn;
        btncnt = 0;
    }
    else if (fmn) {
        btncnt++;
    }

    rpls = !debounce(SW_RPLS);
    if (last_rpls != rpls) {
        last_rpls = rpls;
        btncnt = 0;
    }
    else if (rpls) {
        btncnt++;
    }

    rmn  = !debounce(SW_RMIN);
    if (last_rmn != rmn) {
        last_rmn = rmn;
        btncnt = 0;
    }
    else if (rmn) {
        btncnt++;
    }

    mode = !debounce(SW_MODE);

    if (mode) {
        if (mode_cnt) {
            mode_cnt--;
            new_mode = false;
        }
        else {
            mode_cnt = 10;
            new_mode = true;
        }
    }
    else
        new_mode = false;

    sel = !debounce(SW_SLCT);

    if (btncnt >= HOLD_CNT) {
        btncnt = HOLD_CNT;
        btnhold = true;
    }
    else {
        btnhold = false;
    }
}


void getFreq()
{
    if (fpls) {
        if (btnhold) {
            if (fval >= FSTEP3) {
                fval += FSTEP3;
            }
            else if (fval >= FSTEP2) {
                fval += FSTEP2;
            }
            else if ((fval >= 10) && (fval < 100)) {
                fval += FSTEP1;
            }
            else {
                fval++;
            }
        }
        else {
            fval++;
        }
        // autoinrcrement the range value
        if (fval > (rval * RSTEP)) {
            rval++;
            if (rval > RMAX) {
                rval = RMAX;
            }
        }
    }
    else if (fmn) {
        if (btnhold) {
            if (fval >= FSTEP3) {
                fval -= FSTEP3;
            }
            if (fval >= FSTEP2) {
                fval -= FSTEP2;
            }
            if ((fval >= FSTEP1) && (fval < FSTEP2)) {
                fval -= FSTEP1;
            }
            else if (fval > 0) {
                fval--;
            }
        }
        else if (fval > 0) {
            fval--;
        }
        // autodecrement the range
        if (rval > 2) {
            if (fval < (rval * RSTEP)) {
                rval--;
            }
        }
    }
    else if (rpls) {
        rval++;
        if (rval > RMAX) {
            rval = RMAX;
        }
        fval = rval * RSTEP;
    }
    else if (rmn) {
        rval--;
        if (!rval) {
            fval = 0;
            rval = 1;
        }
        else {
            fval = rval * RSTEP;
        }
    }
}


void SetMode()
{
    if (new_mode) {
        if (currmode <= MODE_CV)  {
            currmode++;                 // step to next mode
            if (currmode > MODE_CV) {
                currmode = MODE_DISP;   // go back to 1st mode
            }
        }
        new_mode = false;               // reset mode change flag
    }
}
