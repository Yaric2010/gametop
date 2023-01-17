#include "TXLib.h"

void player(int x, int y)
{
    txSetFillColor(TX_YELLOW);
    txCircle(x, y, 10);

}

void spawn()
{
    /*txSetFillColor(TX_GREEN);
    txSetColor(TX_NULL);
    txRectangle(0,0, 1901,1025);

    txSetFillColor(RGB(128,128,128));
    txRectangle(0,300,1901,650);

    txSetFillColor(RGB(128,128,128));
    txRectangle(900,0,1250,1025);

    txLine(0,299, 900, 299);
    txLine(0,651, 900, 651);
    txLine(1250,299, 1900, 299);
    txLine(1250,650, 1900, 650);
    txLine(899,0, 899, 300);
    txLine(1250,0, 1250, 300);
    txLine(899,650, 899, 1025);
    txLine(1250,650, 1250, 1250);

    txSetFillColor(RGB(110,110,110));
    txRectangle(0,295, 900, 301);
    txRectangle(0,655, 900, 649);
    txRectangle(1250,295, 1900, 301);
    txRectangle(1250,655, 1900, 649);
    txRectangle(895,0, 901, 300);
    txRectangle(1249,0, 1255, 300);
    txRectangle(901,650, 895, 1025);
    txRectangle(1249,650, 1255, 1250);

    txSetColor(TX_BLACK);
    txSetFillColor(RGB(100,100,100));
    txRectangle(1,1,200,280);

    txRectangle(300,1,500,280);
    */



}

void mysort(int x)
{
    while(not(GetAsyncKeyState (VK_ESCAPE)))
    {
        txSetFillColor(TX_WHITE);
        txRectangle(300, 100, 1600, 300);

        if(x / 10000 == 1)
        {
            txSetFillColor(TX_RED);
            txCircle(400, 200, 60);
            txSetFillColor(TX_GREEN);
            txRectangle(398, 140, 410, 110);
        }

        if(x / 10000 == 2)
        {
            txSetFillColor(TX_BLACK);
            POINT star[3] = {{400,200},{425, 110},{450, 200}};
            txPolygon(star, 3);
            txSetFillColor(TX_BLACK);
            txRectangle(395, 290, 455, 200);
        }

        txSleep(1);





    }
}


void mysorka(int xplay, int yplay, int inventar)
{
    float x = 210;
    txSetFillColor(TX_GREY);
    txSetColor(TX_BLACK);
    txRectangle(200, 50, 210, 70);
    txSetFillColor(TX_BLACK);
    txRectangle(202, 52, 208, 68);
    txSetFillColor(TX_GREY);
    txRectangle(200, 50, x, 70);
    txRectangle(202, 54, x - 2, 59);
    txRectangle(202, 61, x - 2, 65);


    if(GetAsyncKeyState ('E') and yplay > 50 and  70 > yplay and xplay == 220 or xplay == 221)
    {
        while(x > 200)
        {
            txRectangle(200, 50, 210, 70);
            txSetFillColor(TX_BLACK);
            txRectangle(202, 52, 208, 68);
            txSetFillColor(TX_GREY);
            txRectangle(200, 50, x, 70);
            txSleep(10);
            x -=0.2;

        }

        mysort(inventar);

    }


}






int main()
{
    int yplay = 10;
    int xplay = 10;
    int mysor1 = random(10000, 30000);
    int s = 1;
    float V = 2;

    HDC  background = txLoadImage ("fon1.bmp");
    HDC  player = txLoadImage ("vp.bmp");
    HDC  playerl = txLoadImage ("vl.bmp");

    txCreateWindow (1900, 1024);
    txDisableAutoPause();

    while(!GetAsyncKeyState (VK_ESCAPE))
    {
        txBitBlt (txDC(), 0, 0, 1900, 1024, background);
        if(s == 1)
        {
            txTransparentBlt (txDC(), xplay, yplay, 50, 20, player, 0, 0, TX_WHITE);
        }
        else
        {
            txTransparentBlt (txDC(), xplay, yplay, 50, 20, playerl, 0, 0, TX_WHITE);
        }



        if(GetAsyncKeyState ('A'))
        {
            s = 2;
            if(xplay > 260 and yplay < 305 or yplay > 305)
            {
                if(xplay < 302 or xplay > 510 and yplay < 289 or yplay > 289)
                {
                    if(yplay > 75 or yplay < 55 or yplay < 55 and xplay < 220 or xplay > 220)
                    {
                        xplay -=V;
                    }
                }
            }
        }
        if(GetAsyncKeyState ('D'))
        {
            s = 1;
            if(xplay < 290 or xplay > 508 and yplay < 289 or yplay > 289)
            {
                xplay=xplay + V;
                xplay  += 1;
            }
        }

        if(GetAsyncKeyState ('W'))
        {
            if(xplay > 260 or xplay < 305 and yplay > 305)
            {
                if(xplay < 300 or xplay > 510 or xplay < 510 and yplay > 289)
                {
                    if(yplay > 80 or yplay < 50 and xplay < 220 or xplay > 220)
                    {
                        yplay -=V;
                    }
                }
            }

        }
        if(GetAsyncKeyState ('S'))
        {
            if(yplay > 75 or yplay < 40 and xplay < 220 or xplay > 220)
            {
                yplay=yplay + V;
                yplay  += 1;
            }
        }

        if(GetAsyncKeyState (VK_LSHIFT))
        {
            if(V < 3)
            {
                V += 0.001;
            }
        }
        else if(V >= 2)
        {
            V -= 0.005;
        }





        txSleep(1);




    }

    txDeleteDC (background);
    txDeleteDC (player);
    txDeleteDC (playerl);

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
