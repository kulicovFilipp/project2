#include "TXLib.h"

void alphaBlend (double x, double y, double width, double height,
                 HDC image, double xImage, double yImage, double widthOriginal, double heightOriginal, double alpha);

void alphaBlend (double x, double y, double width, double height,
                 HDC image, double xImage, double yImage, double widthOriginal, double heightOriginal, double alpha)
    {

    BLENDFUNCTION blend = { AC_SRC_OVER, 0, (BYTE) ROUND (alpha * 255), AC_SRC_ALPHA};

    txGDI (Win32::AlphaBlend (txDC(), ROUND (x), ROUND (y), ROUND (width), ROUND (height),
           image, ROUND (xImage),  ROUND (yImage),  ROUND (widthOriginal), ROUND (heightOriginal), blend), txDC());


    }


