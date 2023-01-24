#include "TXLib.h"






int main()
{
    int yplay = 500;
    int xplay = 25;



    HDC fon = txLoadImage ("fon1.bmp");
    HDC boll = txLoadImage ("boll.bmp");


    txCreateWindow (800, 600);
    txDisableAutoPause();

    while(!GetAsyncKeyState (VK_ESCAPE))
    {

        txBitBlt (txDC(), 0, 0, 800, 600, fon);

        txBitBlt (txDC(), xplay, yplay, 60, 33, boll);

        if(GetAsyncKeyState ('A'))
        {

            xplay -=3;
        }
        if(GetAsyncKeyState ('D'))
        {

            xplay +=3;


        }

        if(xplay > 5 or xplay > 119 and yplay < 544)
        {
           yplay +=3;

        }

        txSleep(1);

        if(xplay < 5 or xplay > 120 and yplay == 529)
        if(GetAsyncKeyState (VK_SPACE))
        {
            yplay -=5;


        }
    }

    txDeleteDC (fon);


    txTextCursor (false);
    return 0;
}
 /*
 if(y2 == 180)
        {
            y +=v;
        }

        if(y2 == 0)
        {
            y -=v;
        }

        if(y > 580)
        {
            y2 = 0;
            //v +=0.2;
        }

       if(y < 20)
        {
            y2 = 180;
            //v +=0.2;
        }


        if(x2 == 90)
        {
            x +=v;
        }

        if(x2 == 270)
        {
            x -=v;
        }

        if(x > 780)
        {
            x2 = 270;
            //v +=0.2;
        }

        if(x < 20)
        {
            x2 = 90;
           // v +=0.2;
        }
        txSleep(1);

        txSetFillColor(TX_BLACK);
        txRectangle(0,0,800,600);
  */
