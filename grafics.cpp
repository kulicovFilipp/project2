#include "filipplib.h"

void DrawGrafics (int start, int finish, double increase, COLORREF (*colour)(),
                  double (*func) (double x, double k, double b, double c), double k, double b, double c);


double parabola (double x, double k, double b, double c);

double liner (double x, double k, double b, double c);

double cubicParabola (double x, double k, double b, double c);

double parabola_4 (double x, double k, double b, double c);

double Sin (double x, double k, double b, double c);

double Cos (double x, double k, double b, double c);


COLORREF LIGHTBLUE();

COLORREF LIGHTGREEN();

COLORREF LIGHTRED();

COLORREF YELLOW();

COLORREF ORANGE();

int moveGrafic ();

int moveGrafic2 ();

int moveGrafic3 ();

int main ()
    {
    txCreateWindow (GetSystemMetrics (SM_CXSCREEN) - 15, GetSystemMetrics (SM_CYSCREEN) - 55);

    DrawGrafics (-50, 50, 0.01, [] () {return TX_LIGHTGREEN;}, &parabola, 1, 12, 0);

    DrawGrafics (-50, 50, 0.01, [] () {return TX_LIGHTRED;}, &parabola, 1, 4, 0);


    DrawGrafics (-50, 50, 0.01, LIGHTBLUE, &liner, 1, 2 , 0);

    DrawGrafics (-50, 50, 0.01, YELLOW, &liner, 1, 16, 0);

    DrawGrafics (-50, 50, 0.01, ORANGE, &cubicParabola, 7, 0, 0);

    DrawGrafics (-50, 50, 0.01, LIGHTGREEN, &parabola_4, 1, 0, 0);

    DrawGrafics (-50, 50, 0.1, LIGHTRED, &Sin, 1, 0, 0);

    DrawGrafics (-50, 50, 0.1 , YELLOW, &Cos, 1, 0, 0);

    moveGrafic ();

    moveGrafic2 ();

    moveGrafic3 ();

    txdrawGrafics (-50, 50, liner, LIGHTGREEN, 0.1, 2);

    DrawGrafics (-50, 50, 0.1 ,  YELLOW,     &Sin,      2, 0, 0);
    DrawGrafics (-50, 50, 0.1 ,  ORANGE,     &Sin,      3, 0, 0);
    DrawGrafics (-50, 50, 0.1 ,  LIGHTRED,   &Sin,      4, 0, 0);
    DrawGrafics (-50, 50, 0.01 , YELLOW,     &parabola, 2, 0, 0);
    DrawGrafics (-50, 50, 0.01 , ORANGE,     &parabola, 3, 0, 0);
    DrawGrafics (-50, 50, 0.01 , LIGHTRED,   &parabola, 4, 0, 0);

    DrawGrafics (-50, 50, 0.01 , ORANGE,
        [] (double x, double k, double b, double c)
            {
            if (fabs (tan (x)) <= 0.001) {return 1600.0;}
            else                          return 1/tan (x);
            },
        1, 0, 0);

        //drawGrafics (-50, 100, 0.01, [] () {return TX_ORANGE;}, &cubicParabola, 1, 0, 0);

        DrawGrafics (-50, 100, 0.01, [] () {return TX_GREEN;}, &parabola_4, 1, 0, 0);

        txSetFillColor (TX_BLACK);
        txRectangle (0, 0, 1400, 1000);
        txdrawGrafics (-50, 50, radio_waves, GREEN, 0.001, 4);



    //drawGrafics (-50, 50, 0.1, [] () {return TX_LIGHTGREEN;}, [] (double x) {return x*x*x;});


    }

int moveGrafic ()
    {
    txBegin ();

    for (int t = 0; t <= 20; t++)
        {
        DrawGrafics (-50, 50, 0.1, LIGHTGREEN, &parabola, t, 0, 0);
        DrawGrafics (-50, 50, 0.1, LIGHTGREEN, &parabola, 1, t, 0);
        DrawGrafics (-50, 50, 0.1, LIGHTGREEN, &parabola, 1, 0, t);

        DrawGrafics (-50, 50, 0.1, YELLOW,     &liner,    t, 0, 0);
        DrawGrafics (-50, 50, 0.1, YELLOW,     &liner,    1, t, 0);
        DrawGrafics (-50, 50, 0.1, YELLOW,     &liner,    1, 0, t);


        txSleep (30);


        txSetFillColor (TX_BLACK);
        txClear();

        }

    txEnd();
    }

int moveGrafic2 ()
    {
    txBegin ();

    for (int t = 0; t <= 20; t++)
        {
        DrawGrafics (-50, 50, 0.1, LIGHTRED, &Cos, 1, 0, t);
        DrawGrafics (-50, 50, 0.1, LIGHTBLUE, &Sin, 1, 0, t);
        DrawGrafics (-50, 50, 0.1, LIGHTRED, &Cos, 1, t, 0);
        DrawGrafics (-50, 50, 0.1, LIGHTBLUE, &Sin, 1, t, 0);
        DrawGrafics (-50, 50, 0.1, LIGHTRED, &Cos, t, 0, 0);
        DrawGrafics (-50, 50, 0.1, LIGHTBLUE, &Sin, t, 0, 0);


        txSleep (20);


        txSetFillColor (TX_BLACK);
        txClear();

        }

    txEnd();
    }

int moveGrafic3 ()
    {
    txBegin ();

    for (int t = 0; t <= 20; t++)
        {
        DrawGrafics (-50, 50, 0.05, ORANGE, &cubicParabola, 1, 0, t);
        DrawGrafics (-50, 50, 0.05, LIGHTGREEN, &parabola_4, 1, 0, t);
        DrawGrafics (-50, 50, 0.05, ORANGE, &cubicParabola, 1, t, 0);
        DrawGrafics (-50, 50, 0.05, LIGHTGREEN, &parabola_4, 1, t, 0);

        txSleep (15);


        txSetFillColor (TX_BLACK);
        txClear();

        }

    txEnd();
    }



void DrawGrafics (int start, int finish, double increase, COLORREF (*colour)(),
                  double (*func) (double x, double k, double b, double c), double k, double b, double c)
    {
    double x = start;
    while (x <= finish)
        {
        double y = func (x, k, b, c);
        txSetColour (TX_NULL);
        txSetFillColour (colour());
        txCircle (x*20 + txGetExtentX()/2, -y*20 + txGetExtentY()/2, 2);
        x += increase;
        }
    }

double parabola (double x, double k, double b, double c)
    {
    return x*x*k + b - c;
    }

double liner (double x, double k, double b, double c)
    {
    return k * x + b - c;
    }

double cubicParabola (double x, double k, double b, double c)
    {
    return x*x*x*k + b - c;
    }

double parabola_4 (double x, double k, double b, double c)
    {
    return x*x*x*x*k + b - c;
    }

double Sin (double x, double k, double b, double c)
    {
    //return sin (x) * k + b - c;
     return x*x * tan (x) * sin (x) * cos (x) /4 -x * k + b - c;
    }


double Cos (double x, double k, double b, double c)
    {
    return cos (x) * k + b - c;
    }



COLORREF colour()
    {
    return rand()*rand()/64;
    }

