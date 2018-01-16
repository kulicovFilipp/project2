#include"filipplib.h"

//void cow ();

//void Rectangle(double x, double x2);

int main()
    {
    txCreateWindow (1350, 690);
    txSetFillColor (TX_WHITE);
    txRectangle    (0, 0, 1350, 690);
    txSetFillColor (TX_LIGHTMAGENTA);
    txRectangle    (100, 400, 950, 290);
    //cow ();
    }

/*void Rectangle(double x, double x2)
    {
    txSetFillColor (TX_LIGHTMAGENTA);
    txRectangle    (x, 400, x2, 290);
    }  */

/*void cow ()
    {
    int t = 1;
    while (t <= 1000)
        {
        txBegin ();
        txSetFillColor (TX_WHITE);
        if (t >= 700)
            {
            txSetFillColor (TX_BLACK);
            }
        txClear ();
        Rectangle (t/8 % 2 * 100, 900);

        txSleep (20);
        t++;

        }
    }*/


