#include "filiplib.h" // рекорд 34
//txMouseButtons ; txMouseX; MK_LEFT;

const int Type_circle = 1,
          Type_cube   = 2;


struct Object
    {
    int x, y, z;
    int vx, vy;
    HDC hdc;
    int width, height;

    int type;


    void drawCircle();
    void drawCube ();
    void physicsCube (int dt);
    void physicsCircle (int dt);
    void control ();
    void run (Object geometry [], int size, int dt);
    void circleParamiter (int dt);
    void paramiter (int dt);



    };

//{ прототипы

void game (HDC cube, HDC circle, HDC shadow);

int szX (double x);

int szY (double y);

void timecount (int timeStart);

void health (double hearts);

int measure_distance (Object* circle1, Object* circle2);

void bite_function (Object geometry [], int size, double* hearts);

void set_damage (int radius, double damage, Object* object1, Object* object2, double* hearts);

void start ();
//}

int main ()
    {

    txCreateWindow (GetSystemMetrics (SM_CXSCREEN) - 15, GetSystemMetrics (SM_CYSCREEN) - 55);

    HDC cube = txLoadImage ("куб.BMP");

    HDC circle = txLoadImage ("круг.BMP");

    HDC shadow = txLoadImage ("ничего.BMP");



    start ();
    game (cube, circle, shadow);

    txDeleteDC (cube);
    txDeleteDC (circle);
    txDeleteDC (shadow);

    }

void game (HDC cube, HDC circle, HDC shadow)
    {

    int dt = 1;

    Object geometry [] = { {szX (50), szY (50), 1, 1,  2, circle, 81, 76, Type_circle},
                           {szX (8),  szY (8),  1, 12, 7, cube,   70, 70, Type_cube},
                           {szX (92), szY (92), 1, 8,  9, cube,   70, 70, Type_cube},
                           {szX (92), szY (8),  1, 8,  9, cube,   70, 70, Type_cube},
                           {szX (8),  szY (92), 1, 8,  9, cube,   70, 70, Type_cube} };





    double hearts = 3;
    int timeStart = GetTickCount ();

    txBegin ();

    while (!GetAsyncKeyState (VK_ESCAPE))
        {

        txClear ();
        txSetFillColor (TX_BLACK);

       // txBitBlt (txDC(), 0, 0, 0, 0, shadow, 0, 0);

        int i = 0;
        while (i < sizearr(geometry))
            {
            if (geometry [i].type == Type_circle)
                {
                geometry [i].physicsCircle (dt);
                geometry [i].drawCircle ();
                }
            if (geometry [i].type == Type_cube)
                {
                geometry [i].physicsCube (dt);
                geometry [i].drawCube ();
                }
          //geometry [i].physics (dt);
          //  geometry [i].draw ();
            i++;
            }





        bite_function (geometry, sizearr (geometry), &hearts);

        timecount (timeStart);

        health (hearts);

        if (hearts <= -1)
            {
            printf ("break\n");
            break;
            }

        geometry [0].control ();

        txSleep (18);

        }
    }

void Object::drawCircle ()
    {
    alphaBlend (x, y, width, height, hdc, 0, 0, width, height, 1);
    //alphaBlend (x, y, 50, 57, hdc, 0, 0, 50, 57, 1);
    //txAlphaBlend (txDC(), x, y, width, height, hdc, 0, 0);
    }

void Object::drawCube ()
    {
    alphaBlend (x, y, width, height, hdc, 0, 0, width, height, 1);
    }

int szX (double x)
    {
    return x * txGetExtentX()/100;
    }

int szY (double y)
    {
    return y * txGetExtentY()/100;
    }

void Object::physicsCube (int dt)
    {
    x = x + vx * dt;
    y = y + vy * dt;

    if  (x >= txGetExtentX())
        {
        vx = -vx;
        x = txGetExtentX();
        }
    if  (y >= txGetExtentY())
        {
        vy = -vy;
        y = txGetExtentY();
        }
    if (x <= 0)
        {
        vx = -vx;
        x = 0;
        }
    if (y <= 0)
        {
        vy = -vy;
        y = 0;
        }
    }

void Object::physicsCircle (int dt)
    {
    x = x + vx * dt;
    y = y + vy * dt;

    if  (x >= txGetExtentX())
        {
        x = 10;
        }
    if  (y >= txGetExtentY())
        {
        vy = -vy;
        y = txGetExtentY();
        }
    if (x <= 0)
        {
        x = txGetExtentX();
        }
    if (y <= 0)
        {
        vy = -vy;
        y = 0;
        }

    }

void timecount (int timeStart)
    {

    char str [100] = "";
    int time = (GetTickCount () - timeStart)/1000;

    if (time <= 60)
        {
        sprintf (str, "  %d:%d", time/60, time%60);
        }

    if (time >= 60)
        {
        sprintf (str, "  %d:%d", time/60, time%60);

        }

    txSetColor (TX_WHITE);
    txSelectFont ("Arial", 70);
    txTextOut (szX (4), szY (7), str);
    }

void health (double hearts)
    {
    txSelectFont ("SYMBOL", 75);

    int nHearts = 0;
    while (nHearts <= hearts)
        {
        txSetColor (TX_RED);
        txTextOut (szX (7) + 40 * nHearts, szY (95), "©");
        nHearts++;
        }
    }

void Object::control ()
    {
    if (GetAsyncKeyState (VK_LEFT))  vx--;
    if (GetAsyncKeyState (VK_RIGHT)) vx++;
    if (GetAsyncKeyState (VK_UP))    vy--;
    if (GetAsyncKeyState (VK_DOWN))  vy++;
    if (GetAsyncKeyState ('Q'))
        {
        vx = 0;
        vy = 0;
        }

/*void spear ()
    {
    double x1 = x;
    double y1 = y;
    double x2 = x + 150;
    double y2 = y;
    int t = 1;
    if (GetAsyncKeyState ('W'))
        {
        while (t <= 300)
            {
            txSetColor (TX_WHITE);
            txLine (x1 + t, y1 + t, x2 + t, y2 + t);
            t++;
            }
        }

    }*/

    }

int measure_distance (Object* circle1, Object* circle2)
    {
    int distance = sqrt (((*circle2).x - (*circle1).x) * ((*circle2).x - (*circle1).x) +
                         ((*circle2).y - (*circle1).y) * ((*circle2).y - (*circle1).y));
    return distance;
    }

void bite_function (Object geometry [], int size, double* hearts)
    {
    int i = 1;
    while (i < size)
        {
        set_damage (113, 1.0/3, &geometry[0], &geometry[i],   hearts);

        i++;
        }


    }

void set_damage (int radius, double damage, Object* object1, Object* object2, double* hearts)
    {
    int lengH = measure_distance (object1, object2);

    if (lengH <= radius)
        {
        *hearts -= damage;
        }
    }


void start ()
    {
    txSetFillColor (TX_BLACK);
    txRectangle (0, 0, 1500, 1500);

    txSetColor (TX_CYAN);
    txSelectFont ("Tajamuka Script", 70);
    txTextOut (500, 250, "I am there");

    txSetFillColor (TX_GRAY);
    txRectangle (400, 400, 700, 500);
    }




