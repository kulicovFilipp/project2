#include "TXLib.h"

//{ прототипы
void txdrawGrafics  (double start, double finish, double (*func) (double x, double k, double b, double c),
                      COLORREF colour(), double increase, double radius,    double k, double b, double c);

double parabola (double x, double kF [], int n);

double liner    (double x, double kF [], int n);

double parabola_3 (double x, double kF [], int n);

double parabola_4 (double x, double k, double b, double c);

double arc (double x, double k, double b, double c);

double big_arc (double x, double k, double b, double c);

double some_sin (double x, double k, double b, double c);

double more_parabols (double x, double k, double b, double c);

double big_sin (double x, double k, double b, double c);

double scliff (double x, double k, double b, double c);

double rope (double x, double k, double b, double c);

double waves (double x, double k, double b, double c);

double big_waves (double x, double k, double b, double c);

double radio_waves (double x, double k, double b, double c);

double forest (double x, double k, double b, double c);

double small_forest (double x, double k, double b, double c);

double rainforest (double x, double k, double b, double c);

double big_rainforest (double x, double k, double b, double c);






COLORREF GREEN ();

COLORREF LIGHTGREEN ();

COLORREF BLUE ();

COLORREF LIGHTBLUE ();

COLORREF RED ();

COLORREF LIGHTRED ();

COLORREF CYAN ();

COLORREF LIGHTCYAN ();

COLORREF MAGENTA ();

COLORREF LIGHTMAGENTA ();

COLORREF PINK ();

COLORREF YELLOW ();

COLORREF ORANGE ();

COLORREF BROWN ();

COLORREF WHITE ();

COLORREF BLUE ();

COLORREF DARKGREY ();

COLORREF LIGHTGREY ();

COLORREF GREY ();

COLORREF MULTICOLOUR ();
//}

//{  alphaBlend
void alphaBlend (double x, double y, double width, double height,
                 HDC image, double xImage, double yImage, double widthOriginal, double heightOriginal, double alpha);

void alphaBlend (double x, double y, double width, double height,
                 HDC image, double xImage, double yImage, double widthOriginal, double heightOriginal, double alpha)
    {

    BLENDFUNCTION blend = { AC_SRC_OVER, 0, (BYTE) ROUND (alpha * 255), AC_SRC_ALPHA};

    txGDI (Win32::AlphaBlend (txDC(), ROUND (x), ROUND (y), ROUND (width), ROUND (height),
           image, ROUND (xImage),  ROUND (yImage),  ROUND (widthOriginal), ROUND (heightOriginal), blend), txDC());


    }
//}

//{  Функции
void txdrawGrafics (double start, double finish, double (*func) (double x, double k, double b, double c),
                     COLORREF colour(),    double increase, double radius, double k, double b, double c)
    {
    double x = start;
    while (x <= finish)
        {
        double y = func (x, k, b, c);
        txSetColour (TX_BLACK);
        txSetFillColour (colour());
        txCircle (x * 20 + txGetExtentX()/2, y * 20 + txGetExtentY()/2, radius);
        x += increase;
        }
    }


//{ функции графиков

double parabola (double x, double k, double b, double c)
    {
    return k * x*x + b*x + c  ;
    }


double parabola_3 (double x, double k, double b, double c)
    {
    return k * x*x*x + b*x + c;
    }



//=============================================================================================================================

double liner (double x, double k, double b, double c)
    {
    return k * x + b*x + c;
    }

//=======================================================================================================================================

/*double parabola_3 (double x, double k, double b, double c)
    {
    return k * x*x*x + b*x + c;
    }*/

//====================================================================================================================================================

double parabola_4 (double x, double k, double b, double c)
    {
    return k * x*x*x*x + b*x + c;
    }

//---------------------------------------------------------------------------------------------------------------------

double arc (double x, double k, double b, double c)
    {
    return k * x*x/10 + b*x + c;
    }

//------------------------------------------------------------------------------------------------------------------------------------

double big_arc (double x, double k, double b, double c)
    {
    return k * x*x/100 + b*x + c;
    }

//---------------------------------------------------------------------------------------------------------------------------------

double some_sin (double x, double k, double b, double c)
    {
    return k * sin (x) * sin (x) * cos (x) + b*x + c;
    }

//------------------------------------------------------------------------------------------------------------------------------------

double more_parabols (double x, double k, double b, double c)
    {
    return k * sin (x) / sin (x) / cos (x) + b*x + c;
    }

//---------------------------------------------------------------------------------------------------------------------------

double big_sin (double x, double k, double b, double c)
    {
    return k * sin (x) / tan (x) + b*x + c;
    }

//-----------------------------------------------------------------------------------------------------------------------

double scliff (double x, double k, double b, double c)
    {
    return k * sin (x) / tan (x) + x * x / 10 + b*x + c;
    }

//----------------------------------------------------------------------------------------------------------------------------

double rope (double x, double k, double b, double c)
    {
    return k * sin (x) / tan (x) + x * x / 100 + b*x + c;
    }

//-----------------------------------------------------------------------------------------------------------------------------------

double waves (double x, double k, double b, double c)
    {
    return k * sin (x) / tan (x) * x * x / 70 + b*x + c;
    }

//----------------------------------------------------------------------------------------------------------------------------

double big_waves (double x, double k, double b, double c)
    {
    return k * sin (x) / tan (x) * x * x / 10 + b*x + c;
    }

//------------------------------------------------------------------------------------------------------------------------------

double radio_waves (double x, double k, double b, double c)
    {
    return k * sin (x) / tan (x) * x * x / 10* (x / 2 + x - (x/2)) + b*x + c;
    }

//-------------------------------------------------------------------------------------------------------------------------

double forest (double x, double k, double b, double c)
    {
    return k * x*x * tan (x) * sin (x) * cos (x)/10 + b*x+ c;
    }

//---------------------------------------------------------------------------------------------------------------------------------

double small_forest (double x, double k, double b, double c)
    {
    return k * x*x * tan (x) * sin (x) * cos (x)/100 + b*x + c;
    }

//-------------------------------------------------------------------------------------------------------------------------------

double rainforest (double x, double k, double b, double c)
    {
    return k * x*x * tan (x) * sin (x) * cos (x) * 100 + b*x + c;
    }

//----------------------------------------------------------------------------------------------------------------------

double big_rainforest (double x, double k, double b, double c)
    {
    return k * x*x * tan (x) * sin (x) * cos (x) + x/x + b*x + c;
    }




//}

//{ функции цветов

COLORREF GREEN ()
    {
    return TX_GREEN;
    }

COLORREF LIGHTGREEN ()
    {
    return TX_LIGHTGREEN;
    }

COLORREF YELLOW ()
    {
    return TX_YELLOW;
    }

COLORREF ORANGE ()
    {
    return TX_ORANGE;
    }

COLORREF RED ()
    {
    return TX_RED;
    }

COLORREF LIGHTRED ()
    {
    return TX_LIGHTRED;
    }

COLORREF BLUE ()
    {
    return TX_BLUE;
    }

COLORREF LIGHTBLUE ()
    {
    return TX_LIGHTBLUE;
    }

COLORREF PINK ()
    {
    return TX_PINK;
    }

COLORREF WHITE ()
    {
    return TX_WHITE;
    }

COLORREF BLACK ()
    {
    return TX_BLACK;
    }

COLORREF BROWN ()
    {
    return TX_BROWN;
    }

COLORREF LIGHTGREY ()
    {
    return TX_LIGHTGREEN;
    }

COLORREF DARKGREY ()
    {
    return TX_DARKGREY;
    }

COLORREF MAGENTA ()
    {
    return TX_MAGENTA;
    }

COLORREF LIGHTCYAN  ()
    {
    return TX_LIGHTCYAN;
    }

COLORREF LIGHTMAGENTA ()
    {
    return TX_LIGHTMAGENTA;
    }

COLORREF CYAN ()
    {
    return TX_CYAN;
    }

COLORREF MULTICOLOUR ()
    {
        return rand() * rand()/64;
    }





