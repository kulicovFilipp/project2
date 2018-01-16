#include "filiplib.h"

void buildGrafics ();

void controlGrafics (double *controlK, double *controlB, double *controlC);

void deskK (double k);

void deskB (double b);

void deskC (double c);

void changes (double k, double b, double c);

void window2 ();





int main ()
    {



    txCreateWindow (1350, 700);
    buildGrafics ();

    }

void buildGrafics ()
    {
    double k = 1;
    double b = 1;
    double c = 1;

    txBegin();


    while (!GetAsyncKeyState ('Q'))
        {
        txSetFillColor (TX_BLACK);
        txClear();


        controlGrafics (&k, &b, &c);

        txdrawGrafics (-50, 50, big_arc, LIGHTGREEN, 0.1, 5, k, b, c);

        deskK (k);
        deskB (b);
        deskC (c);

        changes (k, b, c);

        txSleep ();

        }


    txEnd();
    }

void controlGrafics (double *controlK, double *controlB, double *controlC)
    {
    if (GetAsyncKeyState ('K'))
        {
        if (GetAsyncKeyState (VK_SHIFT))  (*controlK) -= 0.08;
        else                              (*controlK) += 0.08;
        if (GetAsyncKeyState (VK_CONTROL)) *controlK     = 1;
        }

    if (GetAsyncKeyState ('B'))
        {
        if (GetAsyncKeyState (VK_SHIFT))  (*controlB) -= 0.1;
        else                              (*controlB) += 0.1;
        if (GetAsyncKeyState (VK_CONTROL)) *controlB     = 1;

        }

    if (GetAsyncKeyState ('C'))
        {
        if (GetAsyncKeyState (VK_SHIFT))  (*controlC) -= 0.2;
        else                              (*controlC) += 0.2;
        if (GetAsyncKeyState (VK_CONTROL)) *controlC     = 1;
        }

    if (GetAsyncKeyState (VK_SPACE)) *controlK = 1, *controlB = 1, *controlC = 1;
    }

void deskB (double b)
    {
    char str [100] = "";
    int time = (b);

    sprintf (str, "%d", time);

    txSetColor (TX_WHITE);
    txSelectFont ("Arial", 35);
    txTextOut (65, 30, str);
    txTextOut (20, 30, "B = ");

    }

void deskK (double k)
    {
    char str [100] = "";
    int time = (k);

    sprintf (str, "%d", time);

    txSetColor (TX_WHITE);
    txSelectFont ("Arial", 35);
    txTextOut (65, 60, str);
    txTextOut (20, 60, "K = ");

    }

void deskC (double c)
    {
    char str [100] = "";
    int time = (c);

    sprintf (str, "%d", time);

    txSetColor (TX_WHITE);
    txSelectFont ("Arial", 35);
    txTextOut (65, 90, str);
    txTextOut (20, 90, "C = ");

    }

void changes (double k, double b, double c)
    {
     RECT area = { 1200, 50, 1300, 80 };
     txTextOut (1200, 50, "parabola");


    if (In (txMousePos(), area)) // парабола
        {
        if (txMouseButtons() & 1)
            {
            if (GetAsyncKeyState ('1')) // жёлтая и оранжевая парабола
                {
                if (GetAsyncKeyState (VK_SHIFT))
                    {
                    double k = 1;
                    double b = 1;
                    double c = 1;

                    txBegin();


                    while (!GetAsyncKeyState ('Q'))
                        {
                        txSetFillColor (TX_BLACK);
                        txClear();


                        controlGrafics (&k, &b, &c);

                        txdrawGrafics (-50, 50, parabola, ORANGE, 0.1, 5, k, b, c);


                        deskK (k);
                        deskB (b);
                        deskC (c);

                        changes (k, b, c);

                        txSleep ();

                        }


                    txEnd();
                    }

                else
                    {
                    double k = 1;
                    double b = 1;
                    double c = 1;

                    txBegin();


                    while (!GetAsyncKeyState ('Q'))
                        {
                        txSetFillColor (TX_BLACK);
                        txClear();


                        controlGrafics (&k, &b, &c);

                        txdrawGrafics (-50, 50, parabola, YELLOW, 0.1, 5, k, b, c);


                        deskK (k);
                        deskB (b);
                        deskC (c);

                        changes (k, b, c);

                        txSleep ();

                        }


                    txEnd();
                    }
            }
            if (GetAsyncKeyState ('2')) // светло-красная  и красная парабола
                {
                if (GetAsyncKeyState (VK_SHIFT)) // светло-красная парабола
                    {
                    double k = 1;
                    double b = 1;
                    double c = 1;

                    txBegin();


                    while (!GetAsyncKeyState ('Q'))
                        {
                        txSetFillColor (TX_BLACK);
                        txClear();


                        controlGrafics (&k, &b, &c);

                        txdrawGrafics (-50, 50, parabola, LIGHTRED, 0.1, 5, k, b, c);


                        deskK (k);
                        deskB (b);
                        deskC (c);

                        changes (k, b, c);

                        txSleep ();

                        }


                    txEnd();
                    }

                else                             // красная парабола
                    {
                    double k = 1;
                    double b = 1;
                    double c = 1;

                    txBegin();


                    while (!GetAsyncKeyState ('Q'))
                        {
                        txSetFillColor (TX_BLACK);
                        txClear();


                        controlGrafics (&k, &b, &c);

                        txdrawGrafics (-50, 50, parabola, RED, 0.1, 5, k, b, c);


                        deskK (k);
                        deskB (b);
                        deskC (c);

                        changes (k, b, c);

                        txSleep ();

                        }


                    txEnd();
                    }

                    }

            if (GetAsyncKeyState ('3')) // зелёная и светло-зелёная парабола
                {
                if (GetAsyncKeyState (VK_SHIFT)) // светло-зелёная парабола
                    {
                    double k = 1;
                    double b = 1;
                    double c = 1;

                    txBegin();


                    while (!GetAsyncKeyState ('Q'))
                        {
                        txSetFillColor (TX_BLACK);
                        txClear();


                        controlGrafics (&k, &b, &c);

                        txdrawGrafics (-50, 50, parabola, LIGHTGREEN, 0.1, 5, k, b, c);


                        deskK (k);
                        deskB (b);
                        deskC (c);

                        changes (k, b, c);

                        txSleep ();

                        }


                    txEnd();
                    }

                else                             // зелёная парабола
                    {
                    double k = 1;
                    double b = 1;
                    double c = 1;

                    txBegin();


                    while (!GetAsyncKeyState ('Q'))
                        {
                        txSetFillColor (TX_BLACK);
                        txClear();


                        controlGrafics (&k, &b, &c);

                        txdrawGrafics (-50, 50, parabola, GREEN, 0.1, 5, k, b, c);


                        deskK (k);
                        deskB (b);
                        deskC (c);

                        changes (k, b, c);

                        txSleep ();

                        }


                    txEnd();
                    }

                    }

            if (GetAsyncKeyState ('4')) // синяя и голубая парабола
                    {
                if (GetAsyncKeyState (VK_SHIFT)) // голубая парабола
                    {
                    double k = 1;
                    double b = 1;
                    double c = 1;

                    txBegin();


                    while (!GetAsyncKeyState ('Q'))
                        {
                        txSetFillColor (TX_BLACK);
                        txClear();


                        controlGrafics (&k, &b, &c);

                        txdrawGrafics (-50, 50, parabola, LIGHTBLUE, 0.1, 5, k, b, c);


                        deskK (k);
                        deskB (b);
                        deskC (c);

                        changes (k, b, c);

                        txSleep ();

                        }


                    txEnd();
                    }

                else                             // синяя парабола
                    {
                    double k = 1;
                    double b = 1;
                    double c = 1;

                    txBegin();


                    while (!GetAsyncKeyState ('Q'))
                        {
                        txSetFillColor (TX_BLACK);
                        txClear();


                        controlGrafics (&k, &b, &c);

                        txdrawGrafics (-50, 50, parabola, BLUE, 0.1, 5, k, b, c);


                        deskK (k);
                        deskB (b);
                        deskC (c);

                        changes (k, b, c);

                        txSleep ();

                        }


                    txEnd();
                    }

                    }
            }


        }

    }








