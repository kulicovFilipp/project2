
/*                Episode X

               RETURN OF TXLIB

   War!  The Republic of Windows  is  under
   attack  of  modern  graphics  libraries.
   Programmers of the Galaxy  fight against
   SFML, SDL, OpenGL and DirectX.

   But the more pixels painted,  the lesser
   their Force.  Some  programmers think to
   switch to Pascal and Python.

   Being in utter despair,  princess Organa
   calls for anybody can help  the Graphics
   to get back its Force.

   A long time ago in a galaxy far, far away
   a small library called  TXLib  heard this
   call ...
*/

#include "TXLib.h"
#include <sys/stat.h>

int main()
    {
    txCreateWindow (GetSystemMetrics (SM_CXSCREEN) / 1.5, GetSystemMetrics (SM_CXSCREEN) / 3.0);
    txTextCursor (false);
    txBegin();

    if (access  (__FILE__ ".wav", 0) != 0) return txMessageBox ("ERROR: File \"" __FILE__ ".wav\" NOT found!"), 1;
    txPlaySound (__FILE__ ".wav");
    
    POINT  scr   = txGetExtent();
    double delay = txQueryPerformance() / (scr.x * scr.y) * 1E6 * 10;

    struct stat st = {};
    if (stat (__FILE__, &st) != 0) return txMessageBox ("ERROR: File \"" __FILE__ "\" NOT found!"), 1;
    char* text = new char [st.st_size + 1] {};
    
    FILE* f = fopen (__FILE__, "r");
    fread (text, st.st_size, 1, f);
    fclose (f);

    int n = 1;
    for (char* s = strchr (text, '\n'); s; s = strchr (s+1, '\n')) n++;

    const POINT font = { scr.x/45, scr.y/10 };

    HDC   sw = txCreateCompatibleDC (scr.x, scr.y * 2 + font.y * n);
    POINT sz = txGetExtent (sw);

    txSetColor (TX_LIGHTCYAN, 1, sw);
    txSelectFont ("Lucida Console", font.y, font.x, FW_BOLD, false, false, false, 0, sw);
    txDrawText (0, scr.y/1.5, sz.x, sz.y + scr.y, text, 0, sw);

    delete[] text;
    text = NULL;

    txSetFillColor (TX_BLACK);

    const int posY = ROUND (scr.y * 0.8);

    for (int i = 0; i <= sz.y - posY + scr.y && !GetAsyncKeyState (VK_ESCAPE); i++)
        {
        txLock();

        txClear();

        for (int y = 0; y <= posY; y++)
            {
            double t  = 1.0 * y / posY;

            int sizeX = ROUND (t * scr.x * 5/6 + scr.x/6);
            int destX = (scr.x - sizeX) / 2;

            int destY = ROUND (y + scr.y - posY);
            int srcY  = ROUND ((t+1 - 2 / pow (t+1, 3)) * scr.y + i - scr.y);

            int alpha = ROUND (t * 255);

            Win32::AlphaBlend (txDC(), destX, destY, sizeX, 3, sw, 0, srcY, sz.x, 7,
                               BLENDFUNCTION { AC_SRC_OVER, 0, (BYTE) alpha, 0 });
            }

        txUnlock();

        txSleep (delay);
        }

    txDeleteDC (sw);
    }
  