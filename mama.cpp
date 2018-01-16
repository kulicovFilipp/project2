#include "filipplib.h"

void menu (HDC text);

int main()
    {
    HDC text = txLoadImage ("text.BMP");

    txTextCursor (false);
    txCreateWindow (1300, 700);
    menu (text);
    }

void menu (HDC text)
    {

    txSetColor     (RGB (255, 255, 0));
    txSetFillColor (RGB (84, 84, 84));
    txSelectFont   ("Comic Sans MS", 90);
    txRectangle    (300, 250, 1000, 350);
    txTextOut      (375, 255, "Select character");

    txTransparentBlt (txDC(), 450,  100, 409, 164, text);
    }
