#include "filiplib.h" // ������ 34

void menu (HDC MainImage, HDC Play_StartPage, HDC GrayPlay);

int main ()
    {
    txCreateWindow (GetSystemMetrics (SM_CXSCREEN) - 15, GetSystemMetrics (SM_CYSCREEN) - 55);

    HDC MainImage      = txLoadImage ("gc.BMP");

    HDC Play_StartPage = txLoadImage ("ButtonPlay2.BMP");

    HDC GrayPlay     = txLoadImage ("GrayPlayer");

    menu (MainImage, Play_StartPage, GrayPlay);
    }

void menu (HDC MainImage, HDC Play_StartPage, HDC GrayPlay)
    {
    txSetColor (RGB (0, 255, 255));
    txBitBlt (txDC(), 375, 9, 650, 675, MainImage, 0, 0);
    txSelectFont ("Tajamuka Script", 75);
    txTextOut (810, 277, "");
    txBitBlt (txDC(), 375, 9, 267, 86, Play_StartPage, 0, 0);

   // txBitBlt (txDC(), 450, 350, 43, 43, GrayPlay, 0, 0);



    }

