#include "filipplib.h"

struct Button
    {
    int x, y;
    int lengh, hight;
    COLORREF setColor, fillColor;
    const char* text;
    COLORREF setTextColor;
    int number;
    int hotKey;
    double (*grafic) (double x, const double kF []/*, int n*/);
    char yFormula [125];

    void drawButton ();




    };

void buildGrafics (HDC desk, HDC book, HDC voprosImage);

int  controlGrafics (double kF []/*, int n*/);

void deskKF (const double kF [], int n);

void DrawButtons       (Button object [], int size);

int  CheckButtons      (Button object[], int size  /*, int n*/);

int  CheckMouseButtons (Button object[], int size /*, int n*/);


int fIn (double xMin, double x, double xMax, double yMin, double y, double yMax);

void formula (double kF [], char yFormula[]);


void Lines ();

void signingOfTheAxes ();

void InformationDesk ();











int main ()
    {
    HDC desk   = txLoadImage ("�����3.BMP");
    HDC book   = txLoadImage ("�����2.BMP");
    HDC voprosImage = txLoadImage ("vopros.BMP");


    txTextCursor (false);
    txCreateWindow (1300, 700);
    buildGrafics (desk, book, voprosImage);
    }

void buildGrafics (HDC desk, HDC book, HDC voprosImage)
    {                   // x     y  lengh hight   setColor         fillColor       text          setTextColor  number      grafic
    Button object [] = { {975, 110, 300,  60,  CountourColor,    ButtonColor,  "�������� �������",TextColor   ,  0, '3', liner      , "y = %.1f + x * %.1f"},
                         {975, 210, 300,  60,  CountourColor,    ButtonColor,  "��������",        TextColor   ,  1, '4', parabola   , "y = %.1f  + %.1f * x + %.1f * x^2"},
                         {975, 310, 300,  60,  CountourColor,    ButtonColor,  "����������",      TextColor   ,  2, '5', radio_waves, "y = %1.f + %1.f*x + %1.f * sin (x) / tan (x) * x * x / 10* (x / 2 + x - (x/2))"},
                         {975, 410, 300,  60,  CountourColor,    ButtonColor,  "������� ����!!",  TextColor   ,  3, '6', big_arc    , "y = %1.f + x*x/100 / %1.f * %1.f"},
                         {975, 510, 300,  60,  CountourColor,    ButtonColor,  "�����",           TextColor   ,  4, '7', sinus      , "y = %1.f + sin (x * %1.f) * %1.f"} };

    int size = sizeof (object) / sizeof (object [0]);

    int oldMousePressed  = 0;
    int mousePressed = 0;

    int drawButtons = 0;
    int vopros = 0;

    const int n = 3;
    double kF [n] = {0, 1, 0};

    txBegin();

    int numberOfGrafic = 0;

    while (!GetAsyncKeyState ('Q'))
        {
        int button = CheckButtons   (object, size/*, n*/);
        controlGrafics (kF/*, n*/);

        if (button != -1)
            {
            numberOfGrafic = button;
            }

        txSetFillColor (TX_BLACK);
        txClear();

        alphaBlend (0, 0, LenghDesk, HightDesk, desk, 0, 0, (txGetExtentX (desk)), (txGetExtentY (desk)), 1, 2);

        Lines();

        const COLORREF veryGray = RGB (15, 15, 15);
        txSetFillColor (veryGray);

        txSetColor (veryGray);

        txTransparentBlt (txDC(), 1240,  45, 55, 47, book);
        txTransparentBlt (txDC(), 1170,  45, 50, 50, voprosImage);

        formula (kF, object[numberOfGrafic].yFormula);

        txdrawGrafics (-50, 50, object [numberOfGrafic].grafic, WHITE, 0.1, 5, kF/*, n*/);
        signingOfTheAxes ();

        double x = txMousePos().x, y = txMousePos().y;

        oldMousePressed = mousePressed;
        mousePressed = txMouseButtons() & 1;


        if (!oldMousePressed && mousePressed)
            {
            if (fIn (1240, x, 1295, 45, y, 92))
                {
                drawButtons = !drawButtons;
                }

            if (fIn (1170, x, 1220, 45, y, 90))
                {
                vopros = !vopros;
                }
            }


        if (drawButtons)
            {
            DrawButtons (object, size);
            }

        if (vopros)
            {
            InformationDesk ();
            }

        txSleep ();
        }

    txEnd();
    }


/*void multic ()
    {
    txBegin ();
    int t = 1;
    while (t <= 37)
        {
        txdrawGrafics (-50, 50, liner, CYAN, 0.05, 5, t,   1, 1);
        txdrawGrafics (-50, 50, liner, CYAN, 0.05, 5, t+4, 1, 1);
        txdrawGrafics (-50, 50, liner, CYAN, 0.05, 5, t+7, 1, 1);

        txSleep (48);


        txSetFillColor (TX_BLACK);
        //txClear();
        t++;
        }

    txdrawGrafics (-50, 50, liner, CYAN, 0.03, 5, 37, 1, 1);
    txdrawGrafics (-50, 50, liner, CYAN, 0.05, 5, 41, 1, 1);
    txdrawGrafics (-50, 50, liner, CYAN, 0.05, 5, 44, 1, 1);

    txEnd();

    txBegin ();
    t = 1;
    while (t <= 80)
        {
        txdrawGrafics (-50, 50, liner, CYAN, 0.03, 5, 37, 1, 1);
        txdrawGrafics (-50, 50, liner, CYAN, 0.05, 5, 41, 1, 1);
        txdrawGrafics (-50, 50, liner, CYAN, 0.05, 5, 44, 1, 1);

        txdrawGrafics (-50, 50, liner, LIGHTCYAN, 0.3, 5,  t-35 , 1, 1);
        txdrawGrafics (-50, 50, liner, LIGHTCYAN, 0.3, 5, -t+35 , 1, 1);

        txSleep (30);



        txSetFillColor (TX_BLACK);
        //txClear();
        t++;
        }

    txEnd();


    }

void multic2 ()

    txBegin ();
    int t = 1;
    while (t <= -50)
        {

        txdrawGrafics (-50, 50, liner, LIGHTCYAN, 0.3, 5,  t+10 , 1, 1);
        txdrawGrafics (-50, 50, liner, LIGHTCYAN, 0.3, 5, -t+80 , 1, 1);

        txSleep (30);


        txSetFillColor (TX_BLACK);
        txClear();
        t--;
        }

        txEnd();

    }

void multic3 ()
    {
    txBegin ();
    int t = 1;
    while (t <= 40)
        */

/* txdraw_Grafics (-50, 50, &Sin, LIGHTMAGENTA, 0.3, 5, -t , 1, 1);
        txdraw_Grafics (-50, 50, &Cos, LIGHTCYAN,    0.3, 5,  t , 1, 1);
        txdraw_Grafics (-50, 50, &Sin, ORANGE,       0.3, 5,  1 , t, 1);
        txdraw_Grafics (-50, 50, &Cos, LIGHTGREEN,   0.3, 5,  1 , -t, 1);

        txSleep (80);


        txSetFillColor (TX_BLACK);
        txClear();

        }


        txEnd();
        }


                                                                          */
/*void controlGrafics (double *controlK, double *controlB, double *controlC)
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
    }*/

int  controlGrafics (double kF []/*, int n*/)
    {
    int difference = 0;

        if (GetAsyncKeyState('0'))
            {
            if (GetAsyncKeyState (VK_SHIFT))  (kF [0]) -= 0.08;
            else                              (kF [0]) += 0.08;
            if (GetAsyncKeyState (VK_CONTROL)) kF [0]      = 1;

            difference++;
            }

        if (GetAsyncKeyState ('1'))
            {
            if (GetAsyncKeyState (VK_SHIFT))  (kF [1]) -= 0.1;
            else                              (kF [1]) += 0.1;
            if (GetAsyncKeyState (VK_CONTROL)) kF [1]     = 1;

            difference++;
            }

        if (GetAsyncKeyState ('2'))
            {
            if (GetAsyncKeyState (VK_SHIFT))  (kF [2]) -= 0.2;
            else                              (kF [2]) += 0.2;
            if (GetAsyncKeyState (VK_CONTROL)) kF [2]     = 1;

            difference++;
            }




        if (GetAsyncKeyState (VK_SPACE)) kF [0] = 0, kF [1] = 0, kF [2] = 1, difference++;

        return difference;
    }




/*void deskKF (const double kF [], int n)
    {
    txSelectFont ("Comic Sans MS", 45);

    for (int i = 0; i < n; i++)
        {


        char str [100] = "";
        sprintf (str, "kF [%d] = " "%+.3lf", i, kF [i]);

        txSetColor (TX_WHITE);
        txTextOut (LeftOfTheGrafic + 15, TopOfTheGrafic + 15 + i * 35, str);
        }


    char str [100] = "";

    int i = n-1;
    while (i >= 0)
        {
        double kf = kF [i];
        if (fabs (kf) <= 0.01) kf = 0;

        #pragma GCC diagnostic ignored "-Wfloat-equal"

             if (kf ==  0)       sprintf (str, " ");



        else if (kf ==  1)
                {
                     if (i == 0)  sprintf (str, "+1");
                else if (i == 1)  sprintf (str, "+x");
                else if (i >= 2)  sprintf (str, "+x^%d", i);
                }

        else if (kf == -1)
                {
                     if (i == 0)  sprintf (str, "-1");
                else if (i == 1)  sprintf (str, "-x");
                else if (i >= 2)  sprintf (str, "-x^%d", i);
                }


        else if (kf < -1)
                {
                     if (i == 0)  sprintf (str, "%+lg",        kf);
                else if (i == 1)  sprintf (str, "%+lg * x",    kf);
                else if (i >= 2)  sprintf (str, "%+lg * x^%d", kf, i);
                }

        else if (kf > 1)
                {
                     if (i == 0)  sprintf (str, "%+lg",        kf);
                else if (i == 1)  sprintf (str, "%+lg * x",    kf);
                else if (i >= 2)  sprintf (str, "%lg * x^%d", kf, i);
                }

        else if (kf > 0)
                {
                if (kF [i] < 1)
                    {
                         if (i == 0)  sprintf (str, "%+lg",        kf);
                    else if (i == 1)  sprintf (str, "%+lg * x",    kf);
                    else if (i >= 2)  sprintf (str, "%+lg * x^%d", kf, i);
                    }
                }

        else if (kf < 0)
                {
                if (kF [i] > -1)
                    {
                         if (i == 0)  sprintf (str, "%+lg",        kf);
                    else if (i == 1)  sprintf (str, "%+lg * x",    kf);
                    else if (i >= 2)  sprintf (str, "%+lg * x^%d", kf, i);
                    }
                }

        #pragma GCC diagnostic warning "-Winline"




        txTextOut (LeftOfTheGrafic + 215 - i * 100, TopOfTheGrafic + 130, str);
        i--;
        }

    }
      */

      //
      //          i == 0       i == 1       i >= 2
      //KF <  -1   "%+lg"    "%+lg * x"   "%+lg * x^%d" *
      //kF == -1    "-1"         "-x"        "-x^%d"    *
      //kF == 0     ""           ""             ""      *
      //kF == 1     "+1"         "+x"        "+x^%d"    *
      //kF >= 2    "%+lg"     "%+lg * x"   "%+lg * x^%d"
      ///////////////////////////////////////////////////

void formula (double kF [], char yFormula[])
    {
    txSetColor (TX_YELLOW);
    txSelectFont ("Comic Sans MS", 40);
    char str [100] = "";
    sprintf (str, yFormula, kF [0], kF [1], kF [2]);
    txTextOut (LeftOfTheGrafic + 15, TopOfTheGrafic + 15, str);

    }

void Button::drawButton ()
    {

    txSetColor     (ShadowColor);
    txSetFillColor (ShadowColor);
    Win32::RoundRect(txDC(), x + 5, y + 5, x + lengh + 5, y + hight + 5, hight/5, hight/5);

    txSetColor     (setColor);
    txSetFillColor (fillColor);
    Win32::RoundRect(txDC(), x,     y,     x + lengh,     y + hight,     hight/5, hight/5);

    txSelectFont ("Comic Sans MS", 40);
    txSetColor (setTextColor);
    txDrawText (x, y, x + lengh, y + hight, text);
    txSelectFont ("Comic Sans MS", 25);
    }

void DrawButtons (Button object [], int size)
    {
    int i = 0;
    while (i < size)
        {
        object [i].drawButton ();
        i++;
        }
    }

int  CheckMouseButtons (Button object[], int size/*, int n*/)
    {
    if (!txMouseButtons() & 1) return -1;

    int i = 0;
    while (i < size)
        {
       // printf ("i = %d", i);

        double xMin = object [i].x, xMax = object [i].x + object [i].lengh;
        double yMin = object [i].y, yMax = object [i].y + object [i].hight;
        double x = txMousePos().x, y = txMousePos().y;

        if (fIn (xMin, x, xMax, yMin, y, yMax))
            {
            return i;
            //txdrawGrafics (-50, 50, object [i].grafic, LIGHTGREEN, 0.1, 5, kF, n);
            }
        i++;
        }
    return -1;

    }

int  CheckButtons (Button object[], int size/*, int n*/)
    {
    int i = 0;
    while (i < size)
        {
        if (GetAsyncKeyState (object [i].hotKey) ||
           (fIn (object [i].x, txMouseX(), object [i].x + object [i].lengh,
                 object [i].y, txMouseY(), object [i].y + object [i].hight) && (txMouseButtons() & 1)))
            {
            return i;
            }
        i++;
        }

    return -1;

    }

int fIn (double xMin, double x, double xMax,
         double yMin, double y, double yMax)
    {
    return (xMin <= x && x <= xMax) &&
           (yMin <= y && y <= yMax);
    }

/*int in (struct button button, )
    {
    return (button.x <= point.x && point.x <= button.x + button.lengh) &&
           (button.y <= point.y && point.y <= button.y + button.hight);
    }*/

/*int book ()
    {
    if (!txMouseButtons() & 1) return -1;

    double x = txMousePos().x, y = txMousePos().y;

    if (fIn (1240, x, 1295, 45, y, 92))
            {

            if (book2 = 0)
                {
                return 1;
                }
            }


    }*/


void Lines ()
    {


    txSetColor (TX_RED, 2);
    txLine (Xcentre+1, TopOfTheGrafic + 7, Xcentre+1, BottomOfTheGrafic - 7);
    txLine (LeftOfTheGrafic + 10, Ycentre+1, RightOfTheGrafic - 10, Ycentre+1);
    txLine (Xcentre-10, TopOfTheGrafic+20, Xcentre+1, TopOfTheGrafic+7);
    txLine (Xcentre+11, TopOfTheGrafic+20, Xcentre+1, TopOfTheGrafic+7);
    txLine (RightOfTheGrafic-23, Ycentre+11, RightOfTheGrafic-10, Ycentre+1);
    txLine (RightOfTheGrafic-23, Ycentre-11, RightOfTheGrafic-10, Ycentre+1);

    txTextOut (txGetExtentX()/2 - 25, TopOfTheGrafic + 13,   "Y");
    txTextOut (RightOfTheGrafic - 25, txGetExtentY()/2 + 15, "X");

    Pen();
    int Xnum = LeftOfTheGrafic;
    while (Xnum < RightOfTheGrafic-20)
        {
        Xnum += 20;
        txLine (Xnum, TopOfTheGrafic, Xnum, BottomOfTheGrafic);

        }

    int Ynum = TopOfTheGrafic-10;
    while (Ynum < BottomOfTheGrafic-20)
        {
        Ynum += 20;
        txLine (LeftOfTheGrafic, Ynum, RightOfTheGrafic, Ynum);

        }
    }

void signingOfTheAxes ()
    {
    txSetColor (TX_RED);
    txSelectFont ("Comic Sans MS", 25);
    txSetTextAlign (TA_RIGHT);

    int i = 1;
    int y = Ycentre-90;
    while (y >= TopOfTheGrafic - 40)
        {
        char str [20]= "";
        sprintf (str, "%d", i);
        txTextOut (Xcentre-10, TopOfTheGrafic  + y, str);
        i++;
        y -= 2*Step;
        }

    int i2 = 1;
    int y2 = Ycentre-10;
    while (y2 <= BottomOfTheGrafic - 80)
        {
        char str [20]= "";
        sprintf (str, "-%d", i2);
        txTextOut (Xcentre-10, TopOfTheGrafic  + y2, str);
        i2++;
        y2 += 2*Step;
        }

    txSetTextAlign (TA_CENTER);

    int i3 = -1;
    int x = Xcentre-90;
    while (x >= LeftOfTheGrafic - 60)
        {
        char str [20]= "";
        sprintf (str, "%d", i3);
        txTextOut (LeftOfTheGrafic + x+5, Ycentre+5, str);
        i3--;
        x -= 2*Step;
        }

    int i4 = 1;
    int x2 = Xcentre-5;
    while (x2 <= RightOfTheGrafic - 60)
        {
        char str [20]= "";
        sprintf (str, "%d", i4);
        txTextOut (LeftOfTheGrafic + x2+5, Ycentre+5, str);
        i4++;
        x2 += 2*Step;
        }

    txSetTextAlign (TA_TOP + TA_RIGHT);
    txTextOut (Xcentre-7, Ycentre+4, "0");
    txSetTextAlign (TA_LEFT);

    }

void InformationDesk ()
    {
    txSetColor     (CountourColor);
    txSetFillColor (ButtonColor);
    Win32::RoundRect(txDC(), 30, 570, 825, 670, 15, 15);


    txSetColor     (TX_WHITE);
    txTextOut (50, 580, "����� �������, ��������� � ���������� ���� - ������ ����� � ������ ������� ����.");
    txTextOut (50, 600, "���������� k - ������ 2, ���������� - Shift + 2");
    txTextOut (50, 620, "���������� b - ������ 1, ���������� - Shift +  1");
    txTextOut (50, 640, "���������� c - ������ 0, ���������� - Shift + 0");
    }























