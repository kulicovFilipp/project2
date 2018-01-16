

#include "filipplib.h" //������ - 157- 26 �����; ������ - 158 - 16 ���; ������  - 177 - 26 �����.

struct Animal
    {
    int x_, y_, z_;
    int vx_, vy_;
    HDC hdc_;
    int width_, height_;
    int speedEX, speedEY;
    int speedAX, speedAY;
    int transparency_;
    int xImage_, yImage_;
    int widthOriginal_, hightOriginal_;
    int frame_;

    void control ();
    void physics (int dt);
    void control_reset (int clavisczschkhszcha, int new_vx, int new_vy);
    void draw ();
    void run (Animal creatures [], int size, int dt);
    };

//{ ���������

int lengh (Animal* circle1, Animal* circle2);

void health (double hearts);

void lenghh ();

void timecount (int timeStart, HDC desk);

void Function_which_is_measuring_the_distance_of_all_objects_and_than_sets_hearts
     (Animal creatures [], int size, double* hearts);

void set_radius (int radius, double damage, Animal* object1, Animal* object2, double* hearts);

void circleBlue ();

void bushruns (HDC desk, HDC altar, HDC hegdehog, HDC bat, HDC rat, HDC solider, HDC cat, HDC MagicAltar);

void portalappear ();

void moonruns ();

void hummenmowe ();

void hummenmowey ();

void hummenmowex ();

void kaktusmowe ();

void ground ();

void bush (int x, int y, double sizeX, double sizeY, double sizeBERRIES, int magic, int magic2, int airberry);

void moon (int x, int y, double sizeX, double sizeY);

void clouds (int x, int y, int size);

void stars ();

void ghost (int x, int y, int size, int skakalka, int dres, int head, int dres2);

void hummer (int x, int y, double sizeX, double sizeY, int prugina, int lengh);

void bloodrobenhood (int x, int y, double sizeX, double sizeY, int eyes, int mouth, int feather, int armL, int armR);

void hummen (int x, int y, int size, int hightsword, int flame, int arm2, int arm1, int leg2, int leg1, COLORREF color);

void wood ();

void desk ();

void tree (int x, int y, int leg, int leg2, int arm, int leaves, int rot);

void kaktus (int x, int y, int size, int spikes, int size2);

void yewtree ();

void portal ();

void circle ();

void Background ();

void hummenmove ();

int szX (double x);

int szY (double y);

int measure_distance (Animal* circle1, Animal* circle2);














//}

int main ()
    {

    txCreateWindow (GetSystemMetrics (SM_CXSCREEN) - 15, GetSystemMetrics (SM_CYSCREEN) - 55);


    HDC desk = txLoadImage ("�����2.BMP");

    HDC altar = txLoadImage ("������3.BMP");

    HDC hegdehog = txLoadImage ("��2.BMP");

    HDC bat = txLoadImage ("������� ��������.BMP");

    HDC rat = txLoadImage ("�����3.BMP");

    HDC solider = txLoadImage ("����������.BMP");

    HDC cat = txLoadImage ("���.BMP");

    HDC MagicAltar = txLoadImage ("��������.BMP");

    bushruns (desk, altar, hegdehog, bat, rat, solider, cat, MagicAltar);

    txDeleteDC (desk);

    hummenmove ();

    portalappear ();

    moonruns ();

    hummenmowe ();

    hummenmowey ();

    hummenmowex ();

    kaktusmowe ();

    ground (); // ���

    bush (65, 480, 1, 1, 1, 0, 0, 0);  // ����

    bush (450, 480, 1, 1, 1, 0, 0, 0);

    moon (202, 115, 1, 1);  // ����

    clouds (885, 150, 1); // ����

    clouds (835, 350, 1);

    stars (); // �����

    ghost (350, 205, 1, 138, 0, 0, 0); // �������



    hummer (600, 791, 1, 1, 0, 0); // �����

    bloodrobenhood (435, 760, 1, 1, 0, 0, 0, 0, 0); // �����

    wood (); // ���������

    hummen (840, 260 , 1, 30, 0, 0, 0, 0, 0, TX_RED); // �������

    tree (1050, 990, 0, 0, 0, 20, 0);

    kaktus (1020, 585, 1, 0, 0); // ������

    yewtree ();

    circle ();

    Background ();

    portal ();



    }
void bushruns (HDC desk, HDC altar, HDC hegdehog, HDC bat, HDC rat, HDC solider, HDC /* cat */, HDC MagicAltar)
    {
   // Animal bush2        = {100,  100, 1, 0,  0, solider, 220, 220};
   // Animal blueCircle   = {600,  600, 1, 4,  6, hegdehog, 118, 82, 6, 8, 1, 3};
   // Animal redCircle    = {300,  900, 1, 5,  7, bat,      135, 101,6, 7, 2, 4};
   // Animal greenCircle  = {900,  300, 1, 12, 14, rat,     90,  53, 7, 9, 4, 6};
   // Animal someCircle  =  {700,  700, 1, 12, 14, rat,     90,  53, 8, 10, 4, 6};






    Animal creatures [] = { {szX (8), szY (8), 1, 0,  0, solider, 220, 220},
                            {szX (48), szY (48), 1, 4,  6, hegdehog, 118, 82, 6, 8, 1, 3},
                            {szX (24), szY (72), 1, 5,  7, bat,     135, 101, 6, 7, 2, 4},
                            {szX (72), szY (24), 1, 12, 14, rat,     90,  53, 7, 9, 4, 6},
                            {szX (56), szY (56), 1, 12, 14, rat,      90, 53, 8, 10, 4, 6} };
    double hearts = 8;
    int dt = 1;
    int timeStart = GetTickCount ();

    double amountOfGhostInAMouse = 1;


    txBegin ();


    while (!GetAsyncKeyState (VK_ESCAPE))
        {

        txClear ();
        txSetFillColor (TX_BLUE);

        txBitBlt (txDC(), 0, 0, 0, 0, altar, 0, 0);

        txAlphaBlend (txDC(), txGetExtentX()/2 - 300/2, txGetExtentY()/2 - 285/2, 300, 285, MagicAltar);

        txSetFillColor (TX_LIGHTBLUE);

        txSetFillColor (TX_RED);
        txSetColor (TX_BLACK);

            int i = 0;
            while (i < sizearr(creatures))
                {
                creatures [i].control_reset ('E', 6, 8);
                creatures [i].control_reset ('W', 0, 0);
                creatures [i].control_reset ('A', 2, 4);

                creatures [i].physics (dt);
                creatures [i].draw ();
                i++;
                }

        if (GetAsyncKeyState (VK_F4)) creatures [0].z_ -= 1;
        if (GetAsyncKeyState (VK_F3)) creatures [0].z_ += 1;    object ButtonList [] = { {900, 60 , 250, 60, RED,      BLUE},
                             {900, 160, 250, 60, BLUE,      RED},
                             {900, 260, 250, 60, GREEN,     RED},
                             {900, 360, 250, 60, YELLOW,   BLUE},
                             {900, 460, 250, 60, BROWN, MAGENTA};
        if (GetAsyncKeyState (VK_F1)) amountOfGhostInAMouse += 0.1;
        if (GetAsyncKeyState (VK_F2)) amountOfGhostInAMouse -= 0.1;
        if (amountOfGhostInAMouse > 1) amountOfGhostInAMouse = 1;
        if (amountOfGhostInAMouse < 0) amountOfGhostInAMouse = 0;

        txSetFillColor (TX_GREEN);
        txSetColor (TX_BLACK);

        int time = (GetTickCount () - time)/100;


        creatures [0].control ();
//{   ������� �����!
        //////////////////////////////////////////////////////////////    ////////////////      //////////////
/*        blueCircle.control_reset   ('E', 6, 8);                     //    ////////////////       //          //
        redCircle.control_reset    ('E', 6, 7);                     //    //                     //          //
        greenCircle.control_reset  ('E', 7, 9);                     //    //                     //          //
        yellowCircle.control_reset ('E', 5, 7);                     //    //                     //          //
        someCircle.control_reset   ('E', 8, 10);                    //    //                     //          //
        blueCircle.control_reset   ('W', 0, 0);                     //    //                     //          //
        redCircle.control_reset    ('W', 0, 0);                     //    //                     //////////////
        greenCircle.control_reset  ('W', 0, 0);                     //    //                     ////
        yellowCircle.control_reset ('W', 0, 0);                     //    //                     // //
        someCircle.control_reset   ('W', 0, 0);                     //    //                     //   //
        blueCircle.control_reset   ('A', 1, 3);                     //    //                     //    //
        redCircle.control_reset    ('A', 2, 4);                     //    //                     //      //
        greenCircle.control_reset  ('A', 4, 6);                     //    //                     //        //
        yellowCircle.control_reset ('A', 2, 4);                     //    //                     //         //
        someCircle.control_reset   ('A', 4, 6);                     //    ////////////////       //           //
 */       //////////////////////////////////////////////////////////////    ////////////////  //   //             //
//}
//{   ������!
//        bush2.physics (dt);                                         //
                                                                      //    ///////////    //
//        blueCircle.physics (dt);                                    //    //       //    //
//                                                                    //    //       //    //
//                                                                    //    //       //    ///////////
 //       greenCircle.physics (dt);                                   //    ///////////    //       //
                                                                      //    //             //       //
                                                                      //    //             //       //
                                                                      //    //             //       //
  //      someCircle.physics (dt);                                    //    //             //       //
                                                                      //    //             //       //
          //////////////////////////////////////////////////////////////    //             //       //   //
        //}
        health (hearts);

        if (hearts <= -1)
            {
            break;
            }

        Function_which_is_measuring_the_distance_of_all_objects_and_than_sets_hearts
            (creatures, sizearr (creatures), &hearts);



        timecount (timeStart, desk);                                                                                                              ///
//{   �������!
 //                                         /////////     //     /                                                      ///                //
 //                                            //         //   //                                                       ///                //
 //                                            //         //  /      //                    //                    //     ///                //
 //                                            //         ////       ///////    ////////    //                  //      ///                //
 //                                            //         //         //    //   //    //     //                //       ///                //
 //                                            //         ////       //    //   //    //      ///     ///     //         /                 //
 //                                            //         // ///     //    //   //    //       ///   ////   ///                            //
 //                                            //         //   //    //    //   //    //        /// //  //////          ///                //
 //                                         /////////     //    //   //    //   ////////         ////     ///           ///                //
 //                                                                                                                                        //
 //                                                                                                                                        //
 //          /////////                                                                                                                     //
 //          /////////  //             //   /////////                                         /////////                                    //
 //          //          //          //     /////////   //                                    /////////                    //              //
 //          //           //         //     //          //                                    //            ///////////  //////            //
 //          //           //        //      //          ////////                              //           //        //    //              //
 //          ////////      //      //       ////////    //     //   //     //                 //             ////////      //              //
 //          //            //     //        //          //          //     //                 //            ///   //       //              //
 //          //             //   //         //          //          //     //                 //           //  a  //       //              //
 //          ////////        // //          /////////   //          //     //    //           /////////    //    //        //              //
 //          ////////         //            /////////   //          /////////  //             /////////    //////////      /////           //
 //                                                                       ////                                     //                      //
 //                                                                      ////                                                              //
 //                                                                    //  //                                                              //
 //                                                                  //    //                                                              //
 //          ////////                                                //   //        //                                                     //
 //             //                                                    //////        //                                                     //
 //             //     //                                                           //                                                     //
 //             //     //                                           //              /////////   /////////   //    //  /////    ////////    //
 //             //     ///////       //    //     ///////  //   //  ///////         //     //   //     //   //    //  //       //    //    //
 //             //     //   //       //    //     //   //  //   //  //    /         //     //   //     //   //    //  ///      //    //    //
 //             //     //   //       //    //     //   //  //   //  //              //     //   //     //   //    //   ///     ///////     //
 //             //     //   //       //    //  // //   //  //   //  //              //     //   //     //   //    //     //    //          //
 //          ////////  //   //       //////////   ///////  ///////  //              //     //   /////////   ////////  /////    ///////     //
 //                                       ///                                                                                              //
 //                                     ////                                                                                               //
 //                                   //  //                                                                                               //
 //                                   //  //                                                                                               //
 //                                   //////                                                                                               //
//}


        txSleep (18);
        }

    }
//{   ������!

void hummenmove ()
    {
    int x = 100, y = 100, vx = 5, vy = 0;
    int dt = 1;
    while (GetAsyncKeyState (VK_ESCAPE))
        {
        txBegin ();
        txClear ();
        Background ();
        hummen (x, y , 1, 30, 0, 0, 0, 0, 0, TX_RED);


        x = x + vx*dt;
        y = y + vy*dt;


        if (x >= 1200)
            {
            vx = -vx;
            x = 1200;
            }

        if (x <= 0)
            {
            vx = -vx;
            x = 0;
            }

        if (y >= 960)
            {
            vy = -vy;
            y = 960;
            }

        if (y <= 0)
            {
            vy = -vy;
            y = 0;
            }

        if (GetAsyncKeyState (VK_LEFT)) vx--;
        if (GetAsyncKeyState (VK_RIGHT)) vx++;
        if (GetAsyncKeyState (VK_UP)) vy--;
        if (GetAsyncKeyState (VK_DOWN)) vy++;

        txSleep (4);

        }

    }


void portalappear ()
    {
    int t = 300;
    while (t <= 400)
        {
        txBegin ();
        txSetFillColor (TX_PINK);
        txClear ();
        Background ();
        moon (202, 115, 1, 1);
        bloodrobenhood (435, 760, 1, 1, 0, 0, 0 , 0, 0);
        txSetColor (TX_WHITE);
        txTextOut (t+3, 900, " *���-�� �� ������� ��������� ������*");
        bush (450, 480, 1, 1, 1, 0, 0, 0);
        portal ();
        t++;
        txSleep (10);

        }
    }


void moonruns ()
    {
    int t = 0;
    while (t <= 250)
        {
        txBegin ();
        txSetFillColor (TX_BLUE);
        txClear ();
        Background ();
        txSetColor (TX_RED);
        portal ();
        txSetColor (TX_WHITE);
        txTextOut (300, 900, "-��� ... ��� �? � ����� � ������� � ���������� �����");
        moon (202 + 2*t, 115 - t/2, 1, 1); // 115 - (int) round (t * 0.5)
        hummen (840, 260 , 1, 30, 0, t/10 % 2 * 10, t/10 % 2 * 10, t/10 % 2 * 20, t/10 % 2 * 30, TX_RED);
        bloodrobenhood (435, 760, 1, 1, t+100/2 %3, t+10 %2 * 10, t+20/5 , t/10 %2 * 25, t/10 %2 * 25);
        bush (450, 480, 1, 1, 1, t+40/2 %1, t+40/2 %1, 0);
        kaktus (1020, 585, 1, 0, 0);
        t++;
        txSleep (10);
        }
    }

void hummenmowe ()
    {
    int t = 0;
    while (t <= 100)
         {
         txBegin ();
         txSetFillColor (TX_BLUE);
         txClear ();
         Background ();
         txSetColor (TX_RED);
         portal ();
         txSetColor (TX_WHITE);
         txTextOut (300, 900, "-�� ����� , �� ���� ��������. � ��� ��� ��� �����? ");
         hummen (840 - 23/10*t, 260 , 1, 30, 0,t/3 %3 * 7, t/3 %3 *7, t/3 %4 *8, t/3 %4 *8, TX_RED);
         bloodrobenhood (435, 760, 1, 1, 0, 0, 0, t/10 %2 * 25, t/10 %2 * 25);
         kaktus (1020, 585, 1, 0, 0);
         t++;
         txSleep (25);
                        //  840 - v*100 = 610
         }
    }

void hummenmowey ()
    {
    int t = 260;
    while (t <= 500)
        {
        txBegin ();
        txSetFillColor (TX_PINK);
        txClear ();
        Background ();
        txSetColor (TX_RED);
        portal ();
        txSetColor (TX_WHITE);
        txTextOut (300, 900, "-����..., ��� �� ������ ������! ��� �� ������");
        bloodrobenhood (435, 760, 1, 1, 0, 0, 0, t/10 %2 * 25, t/10 %2 * 25);
        hummen (610 , t + 23/10, 1, 30, 0, 35, 35, 0, 0, TX_RED);
        kaktus (1020, 585, 1, 0, 0);
        t++;
        txSleep (15);

        }
    }

void hummenmowex ()
    {
    int t = 0;
    while (t <= 100)
        {
        txBegin ();
        txSetFillColor (TX_PINK);
        txClear ();
        Background ();
        txSetColor (TX_WHITE);
        txTextOut (300, 900, "-���������...");
        hummen (610 +23/10*t, 500 , 1, 30, 0, t/3 %3 *7, t/3 %3 *7, t/3 %4 *8, t/3 %4 *8, TX_RED);
        bloodrobenhood (435, 760, 1, 1, 0, 0, 0, t/10 %2 * 25, t/10 %2 * 25);
        kaktus (1020, 585, 1, 0, 0);
        t++;
        txSleep (25);

        }
    }

void kaktusmowe ()
    {
    int t = 950;
    while (t >=  500)
        {
        txBegin ();
        txSetFillColor (TX_PINK);
        txClear ();
        Background ();
        txSetColor (TX_WHITE);
        txTextOut (300, 900, "-!!!???                      -� �� ������ ������, �� �� ��");
        bloodrobenhood (435, 760, 1, 1, 0, 0, 0, t/10 %2 * 25, t/10 %2 * 25);
        kaktus (t , 585, 1, t/3 %4 *8, 45);
        hummen (945, 500 , 1, 30, 0, 0, 0, 0, 0, TX_RED);
        t--;
        txSleep (25);

        }
    }

//{ �����
void ground ()
    {
    txSetColor (TX_LIGHTGREEN);
    txSetFillColor (TX_BROWN);
    txRectangle (0, 840, 1200, 960);
    txSetFillColor (TX_LIGHTGREEN);
    txRectangle (0, 540, 1200, 840);
    txSetFillColor (TX_LIGHTBLUE);
    txRectangle (0, 0, 1200, 540);

    }

void bush (int x, int y, double sizeX, double sizeY, double sizeBERRIES, int magic, int magic2, int airberry)
    {
    txSetFillColor (TX_GREEN);
    txSetColor (TX_GREEN);
    txEllipse (x-60*sizeX, y+60*sizeY, x+60*sizeX, y-60*sizeY);
        txSetFillColor (TX_PINK);
        txSetColor (TX_GREEN);
        txCircle (x+(23+magic)*sizeX, y+(25+magic2)*sizeY, 10*sizeBERRIES);
        txCircle (x-(27+magic)*sizeX, y-(50+magic2)*sizeY, (12+airberry)*sizeBERRIES);
        txCircle (x+(3+magic)*sizeX, y-(25+magic2)*sizeY, 8*sizeBERRIES);
        txCircle (x+(50+magic)*sizeX, y-(35+magic2)*sizeY, 10*sizeBERRIES);
        txCircle (x-(36+magic)*sizeX, y+(20+magic2)*sizeY, 10*sizeBERRIES);
    txSetColor (TX_WHITE);
    txSelectFont ("COPYWRIGHT", 500);
    txTextOut (x-25, y-25, "������");
    }
void moon (int x, int y, double sizeX, double sizeY)
    {
    txSetFillColor (TX_YELLOW);
    txSetColor (TX_YELLOW);
    txPie (x-52*sizeX, y-65*sizeY, x+48*sizeX, y+65*sizeY, 100, 180);
    }

void clouds (int x, int y, int size)
    {
    txSetFillColor (TX_DARKGRAY);
    txSetColor (TX_DARKGRAY);
    txCircle (x-80*size, y-20*size, 90*size);
    txCircle (x-15*size, y-30*size, 70*size);
    txEllipse (x-80*size, y-5*size, x+230*size, y+110*size);
    }

void stars ()
    {
    txSetFillColor (TX_YELLOW);
    txSetColor (TX_YELLOW);
    txCircle (388, 55, 3);
    txCircle (1138, 110, 6);
    txCircle (777, 28, 3);
    txCircle (1055, 95, 4);
    txCircle (1000, 67, 3);
    }

void ghost (int x, int y, int size, int skakalka, int dres, int head, int dres2)
    {
    txSetFillColor (TX_BLACK);
    txSetColor (TX_BLACK, 2);
    txEllipse (x-(30-head)*size, y-105*size, x+(30+head)*size, y-45*size);
    txSetFillColor (TX_WHITE);
    txSetColor (TX_BLACK, 2);
    POINT ghost[8] = {{x-50*size, y-60*size}, {x-54*size, y-15*size}, {x-29*size, y-35*size}, {x-4*size, y-15*size}, {x+21*size, y-35*size}, {x+46*size, y-15*size}, {x+50*size, y-60*size}, {x-50*size, y-60*size}};
    txPolygon (ghost, 8);
    txRectangle (x-72*size, y-51*size, x-50*size, y-31*size);
    txRectangle (x+48*size, y-51*size, x+72*size, y-31*size);
    txCircle ((x+head), y-75*size, 20*size);
    POINT dress[4] = {{x-23*size, y-35*size}, {x-(38+dres)*size, y+(82+dres2)*size}, {x+(38-dres)*size, y+(82+dres2)*size}, {x+23*size, y-35*size}};
    txPolygon (dress, 4);
    txSetFillColor (TX_RED);
    txCircle (x-(7-head)*size, y-75*size, 5*size);
    txCircle (x+(7+head)*size, y-75*size, 5*size);
    txLine (x-15*size, y-25*size, x-24*size, y+55*size);
    txLine (x+19*size, y-1*size, x+23*size, y+12*size);
    txSetFillColor (TX_MAGENTA);
    txRectangle (x-100, y-45, x-65, y-37);
    txRectangle (x+65, y-45, x+100, y-37);
    txSetColor (TX_PINK, 2);
    txArc (x-100, y-(42-skakalka), x+100, y-(42+skakalka) , 0, 180);


    }

void hummer (int x, int y, double sizeX, double sizeY, int prugina, int lengh)
    {

        txSetColor     (TX_BLACK, 2);
        txSetFillColor (TX_ORANGE);    Win32::RoundRect (txDC(), x-(50+lengh)*sizeX, y-(99+prugina)*sizeY, x+(50+lengh)*sizeX, y-(49+prugina)*sizeY, 10, 10);
             txSelectFont ("Arial", 20, 0, FW_BOLD);
             txDrawText  (x-49*sizeX, y-(101+prugina)*sizeY, x+51*sizeX, y-(51+prugina)*sizeY, "HELLO");
             txDrawText  (x-49*sizeX, y-(86+prugina)*sizeY, x+51*sizeX, y-(36+prugina)*sizeY, "WORLD!");
        txSetFillColor (TX_ORANGE);
        txSetColor (TX_BLACK, 2);
        txRectangle (x-7*sizeX, y-(49+prugina)*sizeY, x+7*sizeX, y+51*sizeY);
        txRectangle (x-17*sizeX, y+51*sizeY, x+17*sizeX, y+117*sizeY);
     }

void bloodrobenhood (int x, int y, double sizeX, double sizeY, int eyes, int /*mouth*/, int feather, int armL, int armR)
    {
    txSetFillColor (TX_WHITE);
    txSetColor (TX_BLACK, 2);
    txEllipse (x-80*sizeX, y-22*sizeY, x+82*sizeX, y+47*sizeY);
    txSetFillColor (TX_RED);
    txPie (x-60*sizeX, y-55*sizeY, x+60*sizeX, y+90*sizeY, 0, 180);
    txSetFillColor (TX_WHITE);
    txCircle (x-(30-eyes), y-21, 12);
    txCircle (x+(30-eyes), y-22, 12);
    txPie (x+(30-eyes), y-10, x-(30-eyes), y+12, 180, 180);
    txSetFillColor (TX_BLACK);
    txCircle (x-(30-eyes), y-21, 6);
    txCircle (x+(30-eyes), y-21, 6);
    txSetFillColor (TX_BROWN);
    POINT hat[5] = {{x-46, y-47}, {x+46, y-47}, {x+52, y-57}, {x-52, y-57}, {x-46, y-47}};
    txPolygon (hat, 5);
    POINT hat2[3] = {{x-36, y-47}, {x+36, y-47}, {x, y-100}};
    txPolygon (hat2, 3);
    txSetColor (TX_BLACK, 2);
    txLine (x, y-80, x+(55-feather), y-110);
    txSetColor(TX_RED, 2);
    txLine (x+(27-feather), y-95, x+(60-feather), y-130);
    txLine (x+(27-feather), y-95, x+(65-feather), y-96);
    txLine (x+(40-feather), y-102, x+(65-feather), y-125);
    txLine (x+(40-feather), y-102, x+(70-feather), y-101);
    txLine (x+(55-feather), y-110, x+(70-feather), y-115);
    txSetFillColor (TX_RED);
    txSetColor (TX_BLACK, 2);
    POINT arm[3] = {{x-48, y-12}, {x-95, y-(20+armL)}, {x-95, y-(4+armL)}};
    txPolygon (arm, 3);
    POINT arm2[3] = {{x+48, y-12}, {x+95, y-(20+armR)}, {x+95, y-(4+armR)}};
    txPolygon (arm2, 3);


    }

void hummen (int x, int y, int size, int hightsword, int flame, int arm2, int arm1, int leg2, int leg1, COLORREF color )
    {
    txSetColor (TX_BLACK, 2);
    txLine (x, y+30*size, x-(2+leg1)*size, y+73*size);
    txLine (x, y+30*size, x+(2+leg2)*size, y+73*size);
    txLine (x, y-23*size, x, y+30*size);
    txLine (x-55*size, y-(15+arm1)*size, x, y-25*size);
    txLine (x, y-15*size, x+45*size, y-(25+arm2)*size);
    txSetFillColor (color);
    txCircle (x, y-45*size, 25*size);
        txSetFillColor (TX_WHITE);
        txCircle (x-14*size, y-42*size, 5*size);
        txCircle (x+5*size, y-41*size, 6*size);
        txSetFillColor (TX_BLACK);
        txPie (x-14*size, y-46*size, x+7*size, y-41*size, 0, 180);
        txSetColor (TX_WHITE);
        txSetFillColor (TX_WHITE);
        txPie (x-14*size, y-34*size, x+7*size, y-28*size, 0 , 180);
    txSetFillColor (TX_BROWN);
    txSetColor (TX_BLACK);
    POINT triangle[3] = {{x-60*size, y-25*size}, {x-45*size, y-25*size}, {x-53*size, y+18*size}};
    txPolygon (triangle, 3);
    txSetFillColor (TX_YELLOW);
    POINT fire[3] = {{x-60*size, y-25*size}, {x-45*size, y-25*size}, {x-53*size, y-(40+flame)*size}};
    txPolygon (fire, 3);
    txSetFillColor (TX_ORANGE);
    POINT fire2[3] = {{x-56*size, y-25*size}, {x-49*size, y-25*size}, {x-53*size, y-(35+flame)*size}};
    txPolygon (fire2, 3);
        txSetColor (TX_BLACK, 4);
        txLine (x+50*size, y-25*size, x+50*size,y);
        txSetFillColor (TX_BROWN);
        txRectangle (x+38*size, y-30*size, x+62*size, y-25*size);
        txSetFillColor (TX_WHITE);
        txSetColor (TX_WHITE);
        txRectangle (x+43*size, y-(65+hightsword)*size, x+56*size, y-30*size);
    POINT iron[3] = {{x+43*size, y-(65+hightsword)*size}, {x+56*size, y-(65+hightsword)*size}, {x+49*size, y-(90+hightsword)*size}};
    txPolygon (iron, 3);




    }

void wood ()
    {
    txSetColor  (TX_BROWN);
    txSetFillColor (TX_BROWN);
    txRectangle (650, 333, 1200, 400);
    txRectangle (870, 400, 935, 540);
    txRectangle (0, 333, 550, 400);
    txRectangle (220, 400, 285, 540);
    txSetColor (TX_BLACK, 2);
    txRectangle (555, 300, 565, 575);
    txRectangle (645, 300, 635, 575);
    txRectangle (550, 327, 650, 341);
    txRectangle (550, 381, 650, 395);
    txRectangle (550, 435, 650, 450);
    txRectangle (550, 490, 650, 505);
    txRectangle (550, 545, 650, 560);
    POINT torch[3] = {{892, 385}, {913, 385}, {902, 430}};
    txPolygon (torch, 3);
    txSetFillColor (TX_YELLOW);
    POINT fire[3] = {{892, 385}, {913, 385}, {902, 355}};
    txPolygon(fire, 3);
    txSetFillColor (TX_ORANGE);
    POINT fire2[3] {{897, 385}, {908, 385}, {902, 365}};
    txPolygon (fire2, 3);

    }

void desk ()
    {
    txSetFillColor (TX_BLACK);
    txSetColor (TX_BLACK, 3);
    txRectangle (10, 870, 1190, 950);
    txSetColor (TX_WHITE);

    }

void tree (int /*x*/, int /*y*/, int leg, int leg2, int arm, int leaves, int rot)
    {
    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_GREEN);
    txCircle (1050, 120, 70+leaves);
    txSetFillColor (TX_BROWN);
    txRectangle (1075+leg2, 265, 1100+leg2, 333);
    POINT leghigh2[4] ={{1100+leg2, 265}, {1075+leg2, 265}, {1050, 220}, {1075, 220}};
    txPolygon (leghigh2, 4);
    POINT leghigh1[4] = {{1050, 220}, {1025, 220}, {(1000+leg), 265}, {(1025+leg), 265}};
    txPolygon (leghigh1, 4);
    txRectangle (1025+leg, 265, 1000+leg, 333);
    txRectangle (1025, 220, 1075, 125);
    txRectangle (1075, 145+arm, 1150, 165+arm);
    POINT armhigh2[4] = {{1145, 165+arm}, {1145, 145+arm}, {1175, 110+arm}, {1195, 110+arm}};
    txPolygon (armhigh2, 4);
    POINT arm1[4] = {{1025, 130}, {1025, 150}, {970, 200}, {950, 200}};
    txPolygon (arm1, 4);
    txRectangle (950, 200, 970, 235);
    txRectangle (1025, 80, 1075, 125);
    txRectangle (1025, 67, 1031, 80);
    txRectangle (1069, 67, 1075, 80);
    txRectangle (1031, 74, 1035, 80);
    txRectangle (1065, 74, 1069, 80);
    txSetFillColor (TX_ORANGE);
    txPie (1025, 92, 1050, 112, 0, 90);
    txPie (1055, 112, 1080, 92, 90, 90);
    txPie (1030, 112, 1070, 130, 0, 180+rot);
    txSetFillColor (TX_PINK);
    txCircle (1050, 990, 7);

    }

void kaktus (int x, int y, int size, int spikes, int size2)
    {
    txSetFillColor (RGB (0, 200, 40));
    txSetColor (TX_BLACK, 3);
    txEllipse (x-(20-size2)*size, y-40*size, x+25*size, y+70*size);
    txEllipse (x-10*size, y-150*size, x+(20+size2)*size, y-20*size);
    txEllipse (x-4*size, y-200*size, x+(17+size2)*size, y-130*size);
    txEllipse (x-4*size, y-220*size, x+(17+size2)*size, y-190*size);
    txEllipse (x-(20-size2)*size, y-200*size, x+5*size, y-190*size);
    txEllipse (x+9*size, y-115*size, x+(45+size2)*size, y-130*size);
    txEllipse (x-(45-size2)*size, y-60*size, x+3*size, y-80*size);
    txEllipse (x+19*size, y+15*size, x+(45+size2)*size, y-1*size);
    txSetColor (RGB (210, 20, 20), 4);
    txLine (x+18*size, y-5*size, x+(29+spikes)*size, y-10*size);
    txLine (x+17*size, y-55*size, x+(27+spikes)*size, y-67*size);
    txLine (x+16*size, y-95*size, x+(24+spikes)*size, y-108*size);
    txLine (x+33*size, y-127*size, x+(43+spikes)*size, y-130*size);
    txLine (x+12*size, y-207*size, x+(26+spikes)*size, y-215*size);
    txLine (x-15*size, y-185*size, x+(3+spikes)*size, y-175*size);
    txLine (x-22*size, y-80*size, x-(27+spikes)*size, y-87*size);
    txLine (x-18*size, y-25*size, x-(13+spikes)*size, y-17*size);
    txLine (x-28*size, y+17*size, x-(19+spikes)*size, y+19*size);
    }

void circle ()
    {
    txSetFillColor (TX_LIGHTBLUE);
    txCircle (1, 1, 55);
    }

void Background ()
    {

    ground (); // ���

    bush (65, 480, 1, 1, 1, 0, 0, 0);  // ����

    clouds (885, 150, 1); // ����

    clouds (835, 350, 1);

    stars (); // �����

    desk();

    hummer (600, 791, 1, 1, 0, 0); // �����

    wood (); // ���������

    yewtree ();

    tree (1050, 990, 0, 0, 0, 20, 0);

    ghost (350, 205, 1, 138, 0, 0, 0);

    circle ();






    }

void yewtree ()
    {
    txSetFillColor (TX_BROWN);
    txRectangle (970, 120, 1030, 333);
    txSetFillColor (TX_GREEN);
    txCircle (1000, 160, 65);


    }

void portal ()
    {
    txSetFillColor (TX_MAGENTA);
    txPie (800, 180, 870, 333 , 0, 0);

    }

//}
//}
//{   VOIDS !
void Animal::control ()
    {
    if (GetAsyncKeyState (VK_LEFT))  vx_--;
    if (GetAsyncKeyState (VK_RIGHT)) vx_++;
    if (GetAsyncKeyState (VK_UP))    vy_--;
    if (GetAsyncKeyState (VK_DOWN))  vy_++;
    if (GetAsyncKeyState ('Q'))
        {
        vx_ = 0;
        vy_ = 0;
        }
    }

void Animal::physics (int dt)
    {
    x_ = x_ + vx_ * dt;
    y_ = y_ + vy_ * dt;

    if  (x_ >= txGetExtentX())
        {
        vx_ = -vx_;
        x_ = txGetExtentX();
        }
    if  (y_ >= txGetExtentY())
        {
        vy_ = -vy_;
        y_ = txGetExtentY();
        }
    if (x_ <= 0)
        {
        vx_ = -vx_;
        x_ = 0;
        }
    if (y_ <= 0)
        {
        vy_ = -vy_;
        y_ = 0;
        }
    }



int measure_distance (Animal* circle1, Animal* circle2)
    {
    int distance = sqrt (((*circle2).x_ - (*circle1).x_) * ((*circle2).x_ - (*circle1).x_) +
                         ((*circle2).y_ - (*circle1).y_) * ((*circle2).y_ - (*circle1).y_));
    return distance;

    }

void health (double hearts)
    {
    txSelectFont ("SYMBOL", 75);

    int nHearts = 0;
    while (nHearts <= hearts)
        {
        txSetColor (TX_RED);
        txTextOut (txGetExtentX() - txGetExtentX()/1.8 + 40 * nHearts, txGetExtentY() - txGetExtentY()/1.7, "�");
        nHearts++;
        }




    }

void lenghh ()
    {
    txSetFillColor (TX_BLACK);
    txRectangle (0, 0, 1900, 1100);
    txSetColor (TX_WHITE);
    txSelectFont ("COPYWRIGHT", 500);
    txTextOut (300, 420, "YOU DIE");
    }

void timecount (int timeStart, HDC desk)
    {
    txTransparentBlt (txDC(), txGetExtentX() - txGetExtentX()/4.5, txGetExtentY() - txGetExtentY()/4.5, 260, 110, desk, 0, 0, RGB (255, 0, 120));
    char str [5] = "";
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
    txTextOut ( txGetExtentX() - txGetExtentX()/5, txGetExtentY() - txGetExtentY()/5, str);



    }

void Animal::control_reset (int clavisczschkhszcha, int new_vx, int new_vy)
    {
    if (GetAsyncKeyState (clavisczschkhszcha))
        {
        vx_ = new_vx;
        vy_ = new_vy;
        }

    }

void Function_which_is_measuring_the_distance_of_all_objects_and_than_sets_hearts
    (Animal creatures [], int size, double* hearts)
    {
    int i = 1;
    while (i < size)
        {
        //creatures [i].set_radius (130, 1.0/8);
        set_radius (140, 1.0/8, &creatures[0], &creatures[i],   hearts);

        i++;
        }


    }

void set_radius (int radius, double damage, Animal* object1, Animal* object2, double* hearts)
    {
    int lengH = measure_distance (object1, object2);

    if (lengH <= radius)
        {
        lenghh ();
        *hearts -= damage;
        }
    }

void Animal::draw ()
    {


    alphaBlend (x_ + (x_ - txGetExtentX()/2) * txGetExtentY (hdc_) / 5000, y_ + y_ * txGetExtentY (hdc_) / 5000, width_, height_,
                hdc_,  frame_/2%2 * txGetExtentX (hdc_) / 2, txGetExtentY (hdc_) / 2, width_, height_, 0.6 );

    alphaBlend (x_, y_, width_, height_, hdc_, frame_/2%2 * txGetExtentX (hdc_) / 2, 0, width_, height_, 1);


    frame_++;
    }

void Animal::run (Animal creatures [], int size, int dt)
    {
    int i = 0;
    while (i < size)
        {
        creatures [i].control_reset ('E', speedEX, speedEX);
        creatures [i].control_reset ('W', 0, 0);
        creatures [i].control_reset ('A', speedAX, speedAX);

        creatures [i].physics (dt);
        creatures [i].draw ();
        i++;
        }
    }

int szX (double x)
    {
    return x * txGetExtentX()/100;
    }

int szY (double y)
    {
    return y * txGetExtentY()/100;
    }






















