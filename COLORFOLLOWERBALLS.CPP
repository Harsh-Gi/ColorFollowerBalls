#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#include <stdlib.h>
inline float rotX(float x, float y, float ang)
{
    return ((x * cos(ang)) - (y * sin(ang)));
}
inline float rotY(float x, float y, float ang)
{
    return ((x * sin(ang)) + (y * cos(ang)));
}
inline int box()
{
    line(215, getmaxy(), 215, 100);
    line(425, getmaxy(), 425, 100);
    line(215, 150, 295, 199);
    line(425, 150, 345, 199);
    line(215, 275, 255, 300);
    line(425, 275, 385, 300);
    line(215, getmaxy(), 424, getmaxy());
    line(320, 200, 335, 215);
    line(335, 215, 320, 230);
    line(320, 230, 305, 215);
    line(305, 215, 320, 200);
    line(270, 240, 275, 245);
    line(275, 245, 270, 250);
    line(270, 250, 265, 245);
    line(265, 245, 270, 240);
    line(370, 240, 375, 245);
    line(375, 245, 370, 250);
    line(370, 250, 365, 245);
    line(365, 245, 370, 240);
    line(265, 350, 270, 355);
    line(270, 355, 265, 360);
    line(265, 360, 260, 355);
    line(260, 355, 265, 350);
    line(320, 350, 325, 355);
    line(325, 355, 320, 360);
    line(320, 360, 315, 355);
    line(315, 355, 320, 350);
    line(375, 350, 380, 355);
    line(380, 355, 375, 360);
    line(375, 360, 370, 355);
    line(370, 355, 375, 350);
    return 0;
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setbkcolor(7);
    setcolor(8);
    int mCol[4] = {14, 10, 11, 12};
    int i = 0, j = 0, k, n = 0, m = 0, l = 0;
    float gap = 1;
    float **x = new float *[5];
    float **y = new float *[5];
    for (i = 1; i <= 4; i++)
    {
        x[i] = new float[21];
        y[i] = new float[21];
    }
    // Balls Fall Straight
    do
    {
        cleardevice();
        box();
        line(268, getmaxy(), 268, 419);
        line(320, getmaxy(), 320, 419);
        line(371, getmaxy(), 371, 419);
        line(320, 285, 330, 295);
        line(330, 295, 320, 305);
        line(320, 305, 310, 295);
        line(310, 295, 320, 285);
        for (i = 1; i <= 4; i++)
        {
            for (j = 1; j <= 20; j++)
            {
                x[i][j] = 225 + n;
                y[i][j] = -5 + m + l;
                if (j >= 5 && j <= 16)
                {
                    setfillstyle(1, mCol[j % 4]);
                    circle(x[i][j], y[i][j], 5);
                    floodfill(x[i][j], y[i][j], 8);
                }
                n = n + 10;
            }
            m = m + 10;
            n = 0;
        }
        l = l + 2;
        m = 0;
        delay(30);
    } while (y[i - 1][j - 1] < 148);
    float stepl, stepr, xincl, yincl, xincr, yincr, dxl, dyl, dxr, dyr;
    float x1l = 215.0, y1l = 100.0, x2l = 295.0, y2l = 150.0;
    dxl = abs(x2l - x1l);
    dyl = abs(y2l - y1l);
    if (dxl > dyl)
    {
        stepl = dxl;
    }
    else
    {
        stepl = dyl;
    }
    xincl = (x2l - x1l) / stepl;
    yincl = (y2l - y1l) / stepl;
    float xl = x1l, yl = y1l;
    float x1r = 425.0, y1r = 100.0, x2r = 345.0, y2r = 150.0;
    dxr = abs(x2r - x1r);
    dyr = abs(y2r - y1r);
    if (dxr > dyr)
    {
        stepr = dxr;
    }
    else
    {
        stepr = dyr;
    }
    cout << stepr << endl;
    xincr = (x2r - x1r) / stepr;
    yincr = (y2r - y1r) / stepr;
    float xr = x1r, yr = y1r;
    float baril = 215.0, barir = 425.0;
    // Balls Fall in Basin
    for (k = 1; k <= 24; k++)
    {
        cleardevice();
        box();
        line(268, getmaxy(), 268, 419);
        line(320, getmaxy(), 320, 419);
        line(371, getmaxy(), 371, 419);
        line(320, 285, 330, 295);
        line(330, 295, 320, 305);
        line(320, 305, 310, 295);
        line(310, 295, 320, 285);
        xr = x1r;
        yr = y1r;
        xl = x1l, yl = y1l;
        putpixel(xl, yl, 8);
        putpixel(xr, yr, 8);
        while (xl <= baril + 3.5 && xr >= barir - 3.5)
        {
            xl = xl + xincl;
            yl = yl + yincl;
            xr = xr + xincr;
            yr = yr + yincr;
            putpixel(xl, yl, 8);
            putpixel(xr, yr, 8);
        }
        baril = baril + 3.5;
        barir = barir - 3.5;
        for (j = 5; j <= 16; j++)
        {
            for (i = 1; i <= 4; i++)
            {
                if (j >= gap && j < 11)
                {
                    y[i][j] = y[i][j] + 2;
                    y[i][21 - j] = y[i][21 - j] + 2;
                }
                setfillstyle(1, mCol[j % 4]);
                circle(x[i][j], y[i][j], 5);
                floodfill(x[i][j], y[i][j], 8);
            }
        }
        delay(40);
        gap = gap + 0.33;
    }
    // Balls Fall Bellow Basin
    gap = 4;
    float xdl = xl, ydl = yl, xdr = xr, ydr = yr, bStopL = 0.0, bStopR = 0.0;
    for (k = 1; k <= 20; k++)
    {
        cleardevice();
        box();
        line(268, getmaxy(), 268, 419);
        line(320, getmaxy(), 320, 419);
        line(371, getmaxy(), 371, 419);
        line(320, 285, 330, 295);
        line(330, 295, 320, 305);
        line(320, 305, 310, 295);
        line(310, 295, 320, 285);
        ydl = ydl + 2.2;
        ydr = ydr + 2.2;
        line(x1l, y1l, xl, yl);
        line(x1r, y1r, xr, yr);
        line(xl, yl, xdl, ydl);
        line(xr, yr, xdr, ydr);
        for (j = 5; j <= 16; j++)
        {
            for (i = 1; i <= 4; i++)
            {
                if (i >= gap && (j == 9 || j == 10))
                {
                    x[i][j] = x[i][j] - 2;
                    x[i][21 - j] = x[i][21 - j] + 2;
                }
                if (j == 9 || j == 10)
                {
                    y[i][j] = y[i][j] + 2;
                    y[i][21 - j] = y[i][21 - j] + 2;
                }
                setfillstyle(1, mCol[j % 4]);
                circle(x[i][j], y[i][j], 5);
                circle(x[i][21 - j], y[i][21 - j], 5);
                floodfill(x[i][j], y[i][j], 8);
            }
        }
        gap = gap - 0.2;
        delay(40);
    }
    // Balls Fall In Part1
    int cno = 0;
    int *cval = new int[81];
    for (i = 1; i < 81; i++)
    {
        cval[i] = 0;
    }
    float spl = 0.0, spr = 0.0;
    int extra = 0, liBar = 0, bBar = 0;
    for (k = 1; k < 79; k++)
    {
        cleardevice();
        box();
        line(268, getmaxy(), 268, 419);
        line(320, getmaxy(), 320, 419);
        line(371, getmaxy(), 371, 419);
        line(320, 285, 330, 295);
        line(330, 295, 320, 305);
        line(320, 305, 310, 295);
        line(310, 295, 320, 285);
        cno = 0;
        if (bBar < 25)
        {
            bBar = bBar + 5;
        }
        line(x1l, y1l, xl, yl);
        line(x1r, y1r, xr, yr);
        line(xl, yl, xdl, ydl);
        line(xr, yr, xdr, ydr);
        line(320, 199, 320 - bBar, 199);
        line(320, 199, 320 + bBar, 199);
        if (liBar <= 15)
        {
            liBar = liBar + 1;
        }
        line(255, 300, 255, 300 - liBar);
        line(385, 300, 385, 300 - liBar);
        for (i = 1; i <= 4; i++)
        {
            for (j = 5; j <= 16; j++)
            {
                cno = cno + 1;
                if ((x[i][j] >= 220 && x[i][j] <= 255 && y[i][j] <= 295 && y[i][j] >= 278) || (x[i][j] >= 388 && x[i][j] <= 420 && y[i][j] <= 295 && y[i][j] >= 278))
                {
                    if (x[i][j] >= 220 && x[i][j] <= 255)
                    {
                        if ((i == 2 && j == 9) || (i == 1 && j == 9))
                        {
                            extra = extra + 1;
                        }
                        else
                        {
                            if (x[i][j] < 249 - spl)
                            {
                                x[i][j] = x[i][j] + 2;
                            }
                            if (y[i][j] < 290 - (spl / 2))
                            {
                                y[i][j] = y[i][j] + 2;
                            }
                        }
                    }
                    else if (x[i][j] >= 391 && x[i][j] <= 420)
                    {
                        if ((i == 2 && j == 12) || (i == 1 && j == 12))
                        {
                            extra = extra + 1;
                        }
                        else
                        {
                            if (x[i][j] > 391 + spr)
                            {
                                x[i][j] = x[i][j] - 2;
                            }
                            if (y[i][j] < 290 - (spr / 2))
                            {
                                y[i][j] = y[i][j] + 2;
                            }
                        }
                    }
                    if (x[i][j] == 249 - spl && y[i][j] == 291 - (spl / 2))
                    {
                        spl = spl + 10;
                    }
                    if (x[i][j] == 391 + spr && y[i][j] == 291 - (spr / 2))
                    {
                        spr = spr + 10;
                    }
                }
                else
                {
                    if (i == 1 && (j == 9 || j == 12))
                    {
                        if (y[i][j] <= 272)
                        {
                            if (y[i][j] >= 237)
                            {
                                if (j == 9)
                                {
                                    x[i][j] = x[i][j] - 2.3;
                                    y[i][j] = y[i][j] + 2;
                                }
                                else
                                {
                                    x[i][j] = x[i][j] + 2.3;
                                    y[i][j] = y[i][j] + 2;
                                }
                            }
                            else
                            {
                                if (j == 9)
                                {
                                    x[i][j] = x[i][j] - 2;
                                    y[i][j] = y[i][j] + 2;
                                }
                                else
                                {
                                    x[i][j] = x[i][j] + 2;
                                    y[i][j] = y[i][j] + 2;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (((x[i][j] > 220 && x[i][j] < 314) || (x[i][j] < 420 && x[i][j] > 326)) && cval[cno] != 1)
                        {
                            if (j == 9 || j == 10)
                            {
                                if (y[i][j] >= 237)
                                {
                                    if (i % 2 == 0)
                                    {
                                        if (j == 9)
                                        {
                                            x[i][j] = x[i][j] - 3;
                                            y[i][j] = y[i][j] + 2;
                                        }
                                        else
                                        {
                                            x[i][j] = x[i][j] + 3.1;
                                            y[i][j] = y[i][j] + 3;
                                        }
                                    }
                                    else
                                    {
                                        if (j == 9)
                                        {
                                            x[i][j] = x[i][j] - 2;
                                            y[i][j] = y[i][j] + 3;
                                        }
                                        else
                                        {
                                            x[i][j] = x[i][j] + 3.1;
                                            y[i][j] = y[i][j] + 3;
                                        }
                                    }
                                }
                                else
                                {
                                    x[i][j] = x[i][j] - 2;
                                    y[i][j] = y[i][j] + 2;
                                }
                            }
                            else if (j == 11 || j == 12)
                            {
                                if (y[i][j] >= 237)
                                {
                                    if (i % 2 == 0)
                                    {
                                        if (j == 12)
                                        {
                                            x[i][j] = x[i][j] + 3;
                                            y[i][j] = y[i][j] + 2;
                                        }
                                        else
                                        {
                                            x[i][j] = x[i][j] - 3;
                                            y[i][j] = y[i][j] + 3;
                                        }
                                    }
                                    else
                                    {
                                        if (j == 12)
                                        {
                                            x[i][j] = x[i][j] + 2;
                                            y[i][j] = y[i][j] + 3;
                                        }
                                        else
                                        {
                                            x[i][j] = x[i][j] - 3;
                                            y[i][j] = y[i][j] + 3;
                                        }
                                    }
                                }
                                else
                                {
                                    x[i][j] = x[i][j] + 2;
                                    y[i][j] = y[i][j] + 2;
                                }
                            }
                        }
                        else
                        {
                            if (x[i][j] < 260)
                            {
                                cval[cno] = 1;
                                x[i][j] = x[i][j] + 2;
                                y[i][j] = y[i][j] + 2;
                            }
                            else if (x[i][j] > 260 && x[i][j] < 320)
                            {
                                cval[cno] = 1;
                                if (y[i][j] < 350)
                                {
                                    x[i][j] = x[i][j] - 2.05;
                                    y[i][j] = y[i][j] + 4;
                                }
                                else
                                {
                                    if (y[i][j] < 427)
                                    {
                                        x[i][j] = x[i][j] + 2;
                                        y[i][j] = y[i][j] + 4;
                                    }
                                    else
                                    {
                                        if (y[i][j] < getmaxy() - 9)
                                        {
                                            x[i][j] = x[i][j] - 0.5;
                                            y[i][j] = y[i][j] + 4.1;
                                        }
                                        if (y[i][j] >= 473 && x[i][j] > 275 + bStopL)
                                        {
                                            x[i][j] = x[i][j] - 2;
                                            if (x[i][j] == 274.5 + bStopL)
                                            {
                                                bStopL = bStopL + 10;
                                            }
                                        }
                                    }
                                }
                            }
                            else if (x[i][j] > 320 && x[i][j] < 370)
                            {
                                cval[cno] = 1;
                                if (y[i][j] < 350)
                                {
                                    x[i][j] = x[i][j] + 2;
                                    y[i][j] = y[i][j] + 4;
                                }
                                else
                                {
                                    if (y[i][j] < 427)
                                    {
                                        x[i][j] = x[i][j] - 2;
                                        y[i][j] = y[i][j] + 4;
                                    }
                                    else
                                    {
                                        if (y[i][j] < getmaxy() - 9)
                                        {
                                            x[i][j] = x[i][j] + 0.5;
                                            y[i][j] = y[i][j] + 4.1;
                                        }
                                        if (y[i][j] >= 473 && x[i][j] < 365 - bStopR)
                                        {
                                            x[i][j] = x[i][j] + 2;
                                            if (x[i][j] == 365.5 - bStopR)
                                            {
                                                bStopR = bStopR + 10;
                                            }
                                        }
                                    }
                                }
                            }
                            else if (x[i][j] > 370)
                            {
                                cval[cno] = 1;
                                x[i][j] = x[i][j] - 2;
                                y[i][j] = y[i][j] + 2;
                            }
                        }
                    }
                }
                setfillstyle(1, mCol[j % 4]);
                circle(x[i][j], y[i][j], 5);
                floodfill(x[i][j], y[i][j], 8);
            }
        }
        cno = 0;
        delay(40);
    }
    // Balls Fall In Part2
    bStopL = 0;
    bStopR = 0;
    for (k = 1; k <= 70; k++)
    {
        cleardevice();
        box();
        line(268, getmaxy(), 268, 419);
        line(320, getmaxy(), 320, 419);
        line(371, getmaxy(), 371, 419);
        line(320, 285, 330, 295);
        line(330, 295, 320, 305);
        line(320, 305, 310, 295);
        line(310, 295, 320, 285);
        line(x1l, y1l, xl, yl);
        line(x1r, y1r, xr, yr);
        line(xl, yl, xdl, ydl);
        line(xr, yr, xdr, ydr);
        line(320, 199, 295, 199);
        line(320, 199, 345, 199);
        if (liBar >= 2)
        {
            liBar = liBar - 2;
        }
        line(255, 300, 255, 300 - liBar);
        line(385, 300, 385, 300 - liBar);
        if (bStopR == 10)
        {
            bStopR = 11;
        }
        if (bStopL == 10)
        {
            bStopL = 11;
        }
        for (i = 1; i <= 4; i++)
        {
            for (j = 5; j <= 16; j++)
            {
                if (liBar <= 0)
                {
                    if (j == 9)
                    {
                        if (y[i][j] < 300)
                        {
                            x[i][j] = x[i][j] + 3;
                            y[i][j] = y[i][j] + 2;
                            x[i][21 - j] = x[i][21 - j] - 3;
                            y[i][21 - j] = y[i][21 - j] + 2;
                        }
                        else
                        {
                            if (y[i][j] < 348)
                            {
                                x[i][j] = x[i][j] + 3;
                                y[i][j] = y[i][j] + 3;
                                x[i][21 - j] = x[i][21 - j] - 3;
                                y[i][21 - j] = y[i][21 - j] + 3;
                            }
                            else
                            {
                                if (y[i][j] < 450)
                                {
                                    x[i][j] = x[i][j] - 3.5;
                                    y[i][j] = y[i][j] + 4;
                                    x[i][21 - j] = x[i][21 - j] + 3.5;
                                    y[i][21 - j] = y[i][21 - j] + 4;
                                    if (y[i][j] >= 450)
                                    {
                                        x[i][j] = 220;
                                        x[i][21 - j] = 420;
                                    }
                                }
                                else
                                {
                                    if (y[i][j] < getmaxy() - 7)
                                    {
                                        x[i][j] = x[i][j] + 1;
                                        y[i][j] = y[i][j] + 4;
                                    }
                                    else
                                    {
                                        if (x[i][j] < 260 && y[i][j] == 473)
                                        {
                                            if (bStopL == 0 || bStopL == 10 || bStopL == 11)
                                            {
                                                x[i][j] = x[i][j] + 4.5;
                                            }
                                            if (x[i][j] >= 260)
                                            {
                                                bStopL = 10;
                                            }
                                            if (bStopL == 11)
                                            {
                                                x[3][j] = 262;
                                                bStopL = 1;
                                            }
                                            if (bStopL == 1 && i == 4)
                                            {
                                                x[i][j] = 252;
                                                x[2][j] = x[2][j] + 3;
                                                x[1][j] = x[1][j] + 3;
                                                bStopL = 2;
                                            }
                                            if (bStopL == 2 && i == 2)
                                            {
                                                x[i][j] = 242;
                                                x[1][j] = x[1][j] + 3;
                                                bStopL = 3;
                                            }
                                            if (bStopL == 3 && i == 1)
                                            {
                                                x[i][j] = 232;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else if (j == 12)
                    {
                        if (y[i][j] >= 450)
                        {
                            if (y[i][j] < getmaxy() - 7)
                            {
                                x[i][j] = x[i][j] - 1;
                                y[i][j] = y[i][j] + 4;
                            }
                            else
                            {
                                if (x[i][j] > 381 && y[i][j] == 473)
                                {
                                    if (bStopR == 0 || bStopR == 10 || bStopR == 11)
                                    {
                                        x[i][j] = x[i][j] - 4.5;
                                    }
                                    if (x[i][j] <= 381)
                                    {
                                        bStopR = 10;
                                    }
                                    if (bStopR == 11)
                                    {
                                        x[3][j] = 377;
                                        bStopR = 1;
                                    }
                                    if (bStopR == 1 && i == 4)
                                    {
                                        x[i][j] = 387;
                                        x[2][j] = x[2][j] - 3;
                                        x[1][j] = x[1][j] - 3;
                                        bStopR = 2;
                                    }
                                    if (bStopR == 2 && i == 2)
                                    {
                                        x[i][j] = 397;
                                        x[1][j] = x[1][j] - 3;
                                        bStopR = 3;
                                    }
                                    if (bStopR == 3 && i == 1)
                                    {
                                        x[i][j] = 407;
                                    }
                                }
                            }
                        }
                    }
                }
                setfillstyle(1, mCol[j % 4]);
                circle(x[i][j], y[i][j], 5);
                floodfill(x[i][j], y[i][j], 8);
            }
        }
        delay(50);
    }
    // Second
    gap = 1;
    for (k = 1; k <= 23; k++)
    {
        cleardevice();
        box();
        line(268, getmaxy(), 268, 419);
        line(320, getmaxy(), 320, 419);
        line(371, getmaxy(), 371, 419);
        line(320, 285, 330, 295);
        line(330, 295, 320, 305);
        line(320, 305, 310, 295);
        line(310, 295, 320, 285);
        line(x1l, y1l, xl, yl);
        line(x1r, y1r, xr, yr);
        if (ydl > yl)
        {
            ydl = ydl - 4;
        }
        if (ydr > yr)
        {
            ydr = ydr - 4;
        }
        line(xl, yl, xdl, ydl);
        line(xr, yr, xdr, ydr);
        if (x[1][8] > 313)
        {
            if (bBar >= 5)
            {
                bBar = bBar - 5;
            }
        }
        line(320, 199, 320 - bBar, 199);
        line(320, 199, 320 + bBar, 199);
        for (j = 5; j <= 16; j++)
        {
            for (i = 1; i <= 4; i++)
            {
                if (ydr <= yr)
                {
                    if (j < 9)
                    {
                        if ((y[1][j] < 163 || y[4][j] < 192) && x[i][8] < 315)
                        {
                            y[i][j] = y[i][j] + 1.5;
                            y[i][21 - j] = y[i][21 - j] + 1.5;
                        }
                        if (x[i][8] < 315)
                        {
                            x[i][j] = x[i][j] + 2.5;
                            x[i][21 - j] = x[i][21 - j] - 2.5;
                        }
                    }
                }
                setfillstyle(1, mCol[j % 4]);
                circle(x[i][j], y[i][j], 5);
                floodfill(x[i][j], y[i][j], 8);
            }
        }
        delay(100);
        gap = gap + 0.33;
    }
    // Balls Fall Bellow Basin
    float xinc1 = 0.8, yinc1 = -1, xinc2 = 0.67, yinc2 = -1, x1 = 320, y1 = 285, x2 = 330, y2 = 295, x3 = 320, y3 = 285, x4 = 310, y4 = 295;
    gap = 4;
    float cross = 0.0;
    xdl = xl, ydl = yl, xdr = xr, ydr = yr, bStopL = 0.0, bStopR = 0.0;
    for (k = 1; k <= 22; k++)
    {
        cleardevice();
        box();
        line(268, getmaxy(), 268, 419);
        line(320, getmaxy(), 320, 419);
        line(371, getmaxy(), 371, 419);
        line(320, 285, 330, 295);
        line(330, 295, 320, 305);
        line(320, 305, 310, 295);
        line(310, 295, 320, 285);
        line(320, 285, x1, y1);
        line(330, 295, x2, y2);
        line(320, 285, x3, y3);
        line(310, 295, x4, y4);
        if (y2 > 260)
        {
            if (y2 > 263)
            {
                x1 = x1 + (2 * xinc1);
                y1 = y1 + (2 * yinc1);
                x3 = x3 - (2 * xinc1);
                y3 = y3 + (2 * yinc1);
            }
            x2 = x2 + (2 * xinc2);
            y2 = y2 + (2 * yinc2);
            x4 = x4 - (2 * xinc2);
            y4 = y4 + (2 * yinc2);
        }
        if (ydl < 197)
        {
            ydl = ydl + 2.2;
            ydr = ydr + 2.2;
        }
        line(x1l, y1l, xl, yl);
        line(x1r, y1r, xr, yr);
        line(xl, yl, xdl, ydl);
        line(xr, yr, xdr, ydr);
        for (j = 5; j <= 16; j++)
        {
            for (i = 1; i <= 4; i++)
            {
                if (i >= gap && (j == 7 || j == 8))
                {
                    if (y[i][j] >= 197)
                    {
                        x[i][j] = x[i][j] - 2;
                        x[i][21 - j] = x[i][21 - j] + 2;
                    }
                }
                if (j == 7 || j == 8)
                {
                    y[i][j] = y[i][j] + 2;
                    y[i][21 - j] = y[i][21 - j] + 2;
                }
                setfillstyle(1, mCol[j % 4]);
                circle(x[i][j], y[i][j], 5);
                circle(x[i][21 - j], y[i][21 - j], 5);
                floodfill(x[i][j], y[i][j], 8);
            }
        }
        gap = gap - 0.2;
        delay(40);
    }
    // Balls Fall In Part1
    cno = 0;
    for (i = 1; i < 81; i++)
    {
        cval[i] = 0;
    }
    spl = 0.0, spr = 0.0;
    extra = 0, liBar = 0, bBar = 0;
    for (k = 1; k < 35; k++)
    {
        cleardevice();
        box();
        line(268, getmaxy(), 268, 419);
        line(320, getmaxy(), 320, 419);
        line(371, getmaxy(), 371, 419);
        line(320, 285, 330, 295);
        line(330, 295, 320, 305);
        line(320, 305, 310, 295);
        line(310, 295, 320, 285);
        cno = 0;
        line(320, 285, x1, y1);
        line(330, 295, x2, y2);
        line(320, 285, x3, y3);
        line(310, 295, x4, y4);
        if (bBar < 25)
        {
            bBar = bBar + 5;
        }
        line(x1l, y1l, xl, yl);
        line(x1r, y1r, xr, yr);
        line(xl, yl, xdl, ydl);
        line(xr, yr, xdr, ydr);
        line(320, 199, 320 - bBar, 199);
        line(320, 199, 320 + bBar, 199);
        if (liBar <= 15)
        {
            liBar = liBar + 1;
        }
        line(255, 300, 255, 300 - liBar);
        line(385, 300, 385, 300 - liBar);
        for (i = 1; i <= 4; i++)
        {
            for (j = 5; j <= 16; j++)
            {
                cno = cno + 1;
                if (j == 7 || j == 14)
                {
                    if ((x[i][j] >= 220 && x[i][j] <= 255 && y[i][j] <= 295 && y[i][j] >= 278) || (x[i][j] >= 388 && x[i][j] <= 420 && y[i][j] <= 295 && y[i][j] >= 278))
                    {
                        if (x[i][j] >= 220 && x[i][j] <= 255)
                        {
                            if ((i == 2 && j == 7) || (i == 1 && j == 7))
                            {
                                extra = extra + 1;
                            }
                            else
                            {
                                if (x[i][j] < 249 - spl)
                                {
                                    x[i][j] = x[i][j] + 2;
                                }
                                if (y[i][j] < 290 - (spl / 2))
                                {
                                    y[i][j] = y[i][j] + 2;
                                }
                            }
                        }
                        else if (x[i][j] >= 391 && x[i][j] <= 420)
                        {
                            if ((i == 2 && j == 14) || (i == 1 && j == 14))
                            {
                                extra = extra + 1;
                            }
                            else
                            {
                                if (x[i][j] > 391 + spr)
                                {
                                    x[i][j] = x[i][j] - 2;
                                }
                                if (y[i][j] < 290 - (spr / 2))
                                {
                                    y[i][j] = y[i][j] + 2;
                                }
                            }
                        }
                        if (x[i][j] == 249 - spl && y[i][j] == 291 - (spl / 2))
                        {
                            spl = spl + 10;
                        }
                        if (x[i][j] == 391 + spr && y[i][j] == 291 - (spr / 2))
                        {
                            spr = spr + 10;
                        }
                    }
                    else
                    {
                        if (i == 1 && (j == 7 || j == 14))
                        {
                            if (y[i][j] <= 272)
                            {
                                if (y[i][j] >= 237)
                                {
                                    if (j == 7)
                                    {
                                        x[i][j] = x[i][j] - 2.3;
                                        y[i][j] = y[i][j] + 2;
                                    }
                                    else
                                    {
                                        x[i][j] = x[i][j] + 2.3;
                                        y[i][j] = y[i][j] + 2;
                                    }
                                }
                                else
                                {
                                    if (j == 7)
                                    {
                                        x[i][j] = x[i][j] - 2;
                                        y[i][j] = y[i][j] + 2;
                                    }
                                    else
                                    {
                                        x[i][j] = x[i][j] + 2;
                                        y[i][j] = y[i][j] + 2;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (((x[i][j] > 220 && x[i][j] < 314) || (x[i][j] < 420 && x[i][j] > 326)) && cval[cno] != 1)
                            {
                                if (j == 7 || j == 8)
                                {
                                    if (y[i][j] >= 237)
                                    {
                                        if (i % 2 == 0)
                                        {
                                            if (j == 7)
                                            {
                                                x[i][j] = x[i][j] - 3;
                                                y[i][j] = y[i][j] + 2;
                                            }
                                            else
                                            {
                                                x[i][j] = x[i][j] + 3;
                                                y[i][j] = y[i][j] + 3;
                                            }
                                        }
                                        else
                                        {
                                            if (j == 7)
                                            {
                                                x[i][j] = x[i][j] - 2;
                                                y[i][j] = y[i][j] + 3;
                                            }
                                            else
                                            {
                                                x[i][j] = x[i][j] + 3;
                                                y[i][j] = y[i][j] + 3;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        x[i][j] = x[i][j] - 2;
                                        y[i][j] = y[i][j] + 2;
                                    }
                                }
                                else if (j == 13 || j == 14)
                                {
                                    if (y[i][j] >= 237)
                                    {
                                        if (i % 2 == 0)
                                        {
                                            if (j == 14)
                                            {
                                                x[i][j] = x[i][j] + 3;
                                                y[i][j] = y[i][j] + 2;
                                            }
                                            else
                                            {
                                                x[i][j] = x[i][j] - 3;
                                                y[i][j] = y[i][j] + 3;
                                            }
                                        }
                                        else
                                        {
                                            if (j == 14)
                                            {
                                                x[i][j] = x[i][j] + 2;
                                                y[i][j] = y[i][j] + 3;
                                            }
                                            else
                                            {
                                                x[i][j] = x[i][j] - 3;
                                                y[i][j] = y[i][j] + 3;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        x[i][j] = x[i][j] + 2;
                                        y[i][j] = y[i][j] + 2;
                                    }
                                }
                            }
                            else
                            {
                                if (x[i][j] < 260)
                                {
                                    cval[cno] = 1;
                                    x[i][j] = x[i][j] + 2;
                                    y[i][j] = y[i][j] + 2;
                                }
                                else if (x[i][j] > 260 && x[i][j] < 320)
                                {
                                    cval[cno] = 1;
                                    if (y[i][j] < 350)
                                    {
                                        x[i][j] = x[i][j] - 2;
                                        y[i][j] = y[i][j] + 4;
                                    }
                                    else
                                    {
                                        if (y[i][j] < 427)
                                        {
                                            x[i][j] = x[i][j] + 2;
                                            y[i][j] = y[i][j] + 4;
                                        }
                                        else
                                        {
                                            if (y[i][j] < getmaxy() - 9)
                                            {
                                                x[i][j] = x[i][j] - 0.5;
                                                y[i][j] = y[i][j] + 4.1;
                                            }
                                            if (y[i][j] >= 473 && x[i][j] > 275 + bStopL)
                                            {
                                                x[i][j] = x[i][j] - 2;
                                                if (x[i][j] == 274.5 + bStopL)
                                                {
                                                    bStopL = bStopL + 10;
                                                }
                                            }
                                        }
                                    }
                                }
                                else if (x[i][j] > 320 && x[i][j] < 370)
                                {
                                    cval[cno] = 1;
                                    if (y[i][j] < 350)
                                    {
                                        x[i][j] = x[i][j] + 2;
                                        y[i][j] = y[i][j] + 4;
                                    }
                                    else
                                    {
                                        if (y[i][j] < 427)
                                        {
                                            x[i][j] = x[i][j] - 2;
                                            y[i][j] = y[i][j] + 4;
                                        }
                                        else
                                        {
                                            if (y[i][j] < getmaxy() - 9)
                                            {
                                                x[i][j] = x[i][j] + 0.5;
                                                y[i][j] = y[i][j] + 4.1;
                                            }
                                            if (y[i][j] >= 473 && x[i][j] < 365 - bStopR)
                                            {
                                                x[i][j] = x[i][j] + 2;
                                                if (x[i][j] == 365.5 - bStopR)
                                                {
                                                    bStopR = bStopR + 10;
                                                }
                                            }
                                        }
                                    }
                                }
                                else if (x[i][j] > 370)
                                {
                                    cval[cno] = 1;
                                    x[i][j] = x[i][j] - 2;
                                    y[i][j] = y[i][j] + 2;
                                }
                            }
                        }
                    }
                }
                else if (j == 8 || j == 13)
                {
                    if (j == 8)
                    {
                        if (y[i][j] < 285)
                        {
                            if (y[i][j] >= 237)
                            {
                                if (y[i][j] < 285 - cross)
                                {
                                    x[i][j] = x[i][j] + 2;
                                    y[i][j] = y[i][j] + 2.7;
                                    if (y[i][j] >= 284 - cross)
                                    {
                                        cross = cross + 8;
                                    }
                                }
                            }
                            else
                            {
                                x[i][j] = x[i][j] - 2;
                                y[i][j] = y[i][j] + 2;
                            }
                        }
                    }
                    else
                    {
                        if (y[i][j] < 285)
                        {
                            if (y[i][j] >= 237)
                            {
                                if (y[i][j] < 285 - cross + 8)
                                {
                                    x[i][j] = x[i][j] - 2;
                                    y[i][j] = y[i][j] + 2.7;
                                }
                            }
                            else
                            {
                                x[i][j] = x[i][j] + 2;
                                y[i][j] = y[i][j] + 2;
                            }
                        }
                    }
                }
                setfillstyle(1, mCol[j % 4]);
                circle(x[i][j], y[i][j], 5);
                floodfill(x[i][j], y[i][j], 8);
            }
        }
        cno = 0;
        delay(50);
    }
    // xCR is for left & xCL is for right
    float xincC = -1, yincC = -0.75, xCL = 354, xCR = 286, yCL = 259, yCR = 259;
    for (i = 0; i <= 8; i++)
    {
        putpixel(xCL, yCL, 8);
        putpixel(xCR, yCR, 8);
        xCL = xCL + xincC;
        yCL = yCL + yincC;
        xCR = xCR - xincC;
        yCR = yCR + yincC;
        delay(50);
    }
    // Rotate
    xCL = xCL - xincC;
    yCL = yCL - yincC;
    xCR = xCR + xincC;
    yCR = yCR - yincC;
    float x1s = 320.0, y1s = 285.0, x2s = 330.0, y2s = 295.0, x3s = 320.0, y3s = 285.0, x4s = 310.0, y4s = 295.0;
    float xCLs = 354.0, yCLs = 259.0, xCRs = 286.0, yCRs = 259.0;
    float liBarXL1 = 255, liBarYL1 = 300, liBarXL2 = 255, liBarYL2 = 300 - liBar;
    float liBarXR1 = 385, liBarYR1 = 300, liBarXR2 = 385, liBarYR2 = 300 - liBar;
    float bBarXL1 = 320, bBarYL1 = 199, bBarXL2 = 320 - bBar, bBarYL2 = 199;
    float bBarXR1 = 320, bBarYR1 = 199, bBarXR2 = 320 + bBar, bBarYR2 = 199;
    float xS1 = 320.0, yS1 = 285.0, xS2 = 330.0, yS2 = 295.0, xS3 = 320.0, yS3 = 305.0, xS4 = 310.0, yS4 = 295.0;
    float rotCX = 320.0, rotCY = 295.0, xSet = 0.0, ySet = 0.0;
    float ang = 0.0;
    float rotBallX[5][3], rotBallY[5][3];
    int ij = 0, ji = 0;
    for (i = 1; i <= 4; i++)
    {
        ij = ij + 1;
        ji = 0;
        for (j = 8; j <= 13; j++)
        {
            if (j == 8 || j == 13)
            {
                ji = ji + 1;
                rotBallX[ij][ji] = x[i][j];
                rotBallY[ij][ji] = y[i][j];
            }
        }
    }
    for (k = 1; k <= 18; k++)
    {
        cleardevice();
        box();
        line(268, getmaxy(), 268, 419);
        line(320, getmaxy(), 320, 419);
        line(371, getmaxy(), 371, 419);
        if (k < 18)
        {
            ang = ang + (M_PI / 18);
        }
        else
        {
            ang = M_PI;
        }
        xSet = rotX(rotCX, rotCY, ang) - rotCX;
        ySet = rotY(rotCX, rotCY, ang) - rotCY;
        line(rotX(xS1, yS1, ang) - xSet, rotY(xS1, yS1, ang) - ySet, rotX(xS2, yS2, ang) - xSet, rotY(xS2, yS2, ang) - ySet);
        line(rotX(xS2, yS2, ang) - xSet, rotY(xS2, yS2, ang) - ySet, rotX(xS3, yS3, ang) - xSet, rotY(xS3, yS3, ang) - ySet);
        line(rotX(xS3, yS3, ang) - xSet, rotY(xS3, yS3, ang) - ySet, rotX(xS4, yS4, ang) - xSet, rotY(xS4, yS4, ang) - ySet);
        line(rotX(xS4, yS4, ang) - xSet, rotY(xS4, yS4, ang) - ySet, rotX(xS1, yS1, ang) - xSet, rotY(xS1, yS1, ang) - ySet);
        line(rotX(x1s, y1s, ang) - xSet, rotY(x1s, y1s, ang) - ySet, rotX(x1, y1, ang) - xSet, rotY(x1, y1, ang) - ySet);
        line(rotX(x2s, y2s, ang) - xSet, rotY(x2s, y2s, ang) - ySet, rotX(x2, y2, ang) - xSet, rotY(x2, y2, ang) - ySet);
        line(rotX(x3s, y3s, ang) - xSet, rotY(x3s, y3s, ang) - ySet, rotX(x3, y3, ang) - xSet, rotY(x3, y3, ang) - ySet);
        line(rotX(x4s, y4s, ang) - xSet, rotY(x4s, y4s, ang) - ySet, rotX(x4, y4, ang) - xSet, rotY(x4, y4, ang) - ySet);
        line(rotX(xCLs, yCLs, ang) - xSet, rotY(xCLs, yCLs, ang) - ySet, rotX(xCL, yCL, ang) - xSet, rotY(xCL, yCL, ang) - ySet);
        line(rotX(xCRs, yCRs, ang) - xSet, rotY(xCRs, yCRs, ang) - ySet, rotX(xCR, yCR, ang) - xSet, rotY(xCR, yCR, ang) - ySet);
        line(x1l, y1l, xl, yl);
        line(x1r, y1r, xr, yr);
        line(xl, yl, xdl, ydl);
        line(xr, yr, xdr, ydr);
        line(bBarXL1, bBarYL1, bBarXL2, bBarYL2);
        line(bBarXR1, bBarYR1, bBarXR2, bBarYR2);
        line(liBarXL1, liBarYL1, liBarXL2, liBarYL2);
        line(liBarXR1, liBarYR1, liBarXR2, liBarYR2);
        ij = 0;
        ji = 0;
        for (i = 1; i <= 4; i++)
        {
            ij = ij + 1;
            ji = 0;
            for (j = 5; j <= 16; j++)
            {
                if (j == 8 || j == 13)
                {
                    ji = ji + 1;
                    x[i][j] = rotX(rotBallX[ij][ji], rotBallY[ij][ji], ang) - xSet;
                    y[i][j] = rotY(rotBallX[ij][ji], rotBallY[ij][ji], ang) - ySet;
                }
                setfillstyle(1, mCol[j % 4]);
                circle(x[i][j], y[i][j], 5);
                floodfill(x[i][j], y[i][j], 8);
            }
        }
        delay(70);
    }
    // After rotation
    xS1 = rotX(xS1, yS1, ang) - xSet;
    yS1 = rotY(xS1, yS1, ang) - ySet;
    xS2 = rotX(xS2, yS2, ang) - xSet;
    yS2 = rotY(xS2, yS2, ang) - ySet;
    xS3 = rotX(xS3, yS3, ang) - xSet;
    yS3 = rotY(xS3, yS3, ang) - ySet;
    xS4 = rotX(xS4, yS4, ang) - xSet;
    yS4 = rotY(xS4, yS4, ang) - ySet;
    x1s = rotX(x1s, y1s, ang) - xSet;
    y1s = rotY(x1s, y1s, ang) - ySet;
    x2s = rotX(x2s, y2s, ang) - xSet;
    y2s = rotY(x2s, y2s, ang) - ySet;
    x3s = rotX(x3s, y3s, ang) - xSet;
    y3s = rotY(x3s, y3s, ang) - ySet;
    x4s = rotX(x4s, y4s, ang) - xSet;
    y4s = rotY(x4s, y4s, ang) - ySet;
    x1 = rotX(x1, y1, ang) - xSet;
    y1 = rotY(x1, y1, ang) - ySet;
    x2 = rotX(x2, y2, ang) - xSet;
    y2 = rotY(x2, y2, ang) - ySet;
    x3 = rotX(x3, y3, ang) - xSet;
    y3 = rotY(x3, y3, ang) - ySet;
    x4 = rotX(x4, y4, ang) - xSet;
    y4 = rotY(x4, y4, ang) - ySet;
    xCLs = rotX(xCLs, yCLs, ang) - xSet;
    yCLs = rotY(xCLs, yCLs, ang) - ySet;
    xCRs = rotX(xCRs, yCRs, ang) - xSet;
    yCRs = rotY(xCRs, yCRs, ang) - ySet;
    xCL = rotX(xCL, yCL, ang) - xSet;
    yCL = rotY(xCL, yCL, ang) - ySet;
    xCR = rotX(xCR, yCR, ang) - xSet;
    yCR = rotY(xCR, yCR, ang) - ySet;
    if (abs(xCR - xCRs) >= abs(yCR - yCRs))
    {
        xincC = (xCR - xCRs) / abs(xCR - xCRs);
        yincC = (yCR - yCRs) / abs(xCR - xCRs);
    }
    else
    {
        xincC = (xCR - xCRs) / abs(yCR - yCRs);
        yincC = (yCR - yCRs) / abs(yCR - yCRs);
    }
    if (abs(x1 - x1s) >= abs(y1 - y1s))
    {
        xinc1 = (x1 - x1s) / abs(x1 - x1s);
        yinc1 = (y1 - y1s) / abs(x1 - x1s);
    }
    else
    {
        xinc1 = (x1 - x1s) / abs(y1 - y1s);
        yinc1 = (y1 - y1s) / abs(y1 - y1s);
    }
    if (abs(x2 - x2s) >= abs(y2 - y2s))
    {
        xinc2 = (x2 - x2s) / abs(x2 - x2s);
        yinc2 = (y2 - y2s) / abs(x2 - x2s);
    }
    else
    {
        xinc2 = (x2 - x2s) / abs(y2 - y2s);
        yinc2 = (y2 - y2s) / abs(y2 - y2s);
    }
    int pLineV = 0, pLineH = 0, cOpen = 0, blSet = 0;
    cno = 0;
    for (i = 1; i < 81; i++)
    {
        cval[i] = 0;
    }
    for (k = 1; k <= 77; k++)
    {
        cleardevice();
        box();
        cno = 0;
        if (blSet <= 25)
        {
            blSet = blSet + 1;
        }
        line(226, getmaxy(), 226, getmaxy() - blSet);
        line(413, getmaxy(), 413, getmaxy() - blSet);
        if (y[4][8] > 352)
        {
            if ((x1s - x1) > 0)
            {
                x1 = x1 - xinc1;
                y1 = y1 - yinc1;
                x3 = x3 + xinc1;
                y3 = y3 - yinc1;
            }
            if ((x2s - x2) > 0)
            {
                x2 = x2 - xinc2;
                y2 = y2 - yinc2;
                x4 = x4 + xinc2;
                y4 = y4 - yinc2;
                line(x2s, y2s, x2, y2);
                line(x4s, y4s, x4, y4);
            }
        }
        if ((x1s - x1) > 0)
        {
            line(x1s, y1s, x1, y1);
            line(x3s, y3s, x3, y3);
        }
        if ((x2s - x2) > 0)
        {
            line(x2s, y2s, x2, y2);
            line(x4s, y4s, x4, y4);
        }
        if (419 + pLineV <= getmaxy() - 14)
        {
            pLineV = pLineV + 2;
        }
        if (268 + pLineH < 320)
        {
            pLineH = pLineH + 2;
        }
        line(268, getmaxy(), 268, 419 + pLineV + 1);
        line(320, getmaxy(), 320, 419);
        line(371, getmaxy(), 371, 419 + pLineV + 1);
        line(268, 468, 268 + pLineH, 468);
        line(371, 468, 371 - pLineH, 468);
        line(xS1, yS1, xS2, yS2);
        line(xS2, yS2, xS3, yS3);
        line(xS3, yS3, xS4, yS4);
        line(xS4, yS4, xS1, yS1);
        if (xCR - xCRs >= 0)
        {
            cOpen = 1;
        }
        if (xCR - xCRs < 0)
        {
            xCL = xCL + xincC;
            yCL = yCL - yincC;
            xCR = xCR - xincC;
            yCR = yCR - yincC;
            line(xCLs, yCLs, xCL, yCL);
            line(xCRs, yCRs, xCR, yCR);
        }
        line(x1l, y1l, xl, yl);
        line(x1r, y1r, xr, yr);
        line(xl, yl, xdl, ydl);
        line(xr, yr, xdr, ydr);
        line(bBarXL1, bBarYL1, bBarXL2, bBarYL2);
        line(bBarXR1, bBarYR1, bBarXR2, bBarYR2);
        line(liBarXL1, liBarYL1, liBarXL2, liBarYL2);
        line(liBarXR1, liBarYR1, liBarXR2, liBarYR2);
        ij = 0;
        ji = 0;
        for (i = 1; i <= 4; i++)
        {
            ij = ij + 1;
            ji = 0;
            for (j = 5; j <= 16; j++)
            {
                cno = cno + 1;
                if (cOpen == 1)
                {
                    if (j == 8 || j == 13)
                    {
                        if (j == 8)
                        {
                            if (y[i][j] >= 352)
                            {
                                cval[cno] = 1;
                            }
                            if (cval[cno] == 1)
                            {
                                if (y[i][j] < 410)
                                {
                                    x[i][j] = x[i][j] - 2;
                                    y[i][j] = y[i][j] + 3;
                                }
                                else
                                {
                                    if (y[i][j] < getmaxy() - 18)
                                    {
                                        x[i][j] = x[i][j] + 2;
                                        y[i][j] = y[i][j] + 2.5;
                                    }
                                    else
                                    {
                                        if (x[i][j] < 420)
                                        {
                                            x[i][j] = x[i][j] + 2.5;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                x[i][j] = x[i][j] + 1.5;
                                y[i][j] = y[i][j] + 2;
                            }
                        }
                        else
                        {
                            if (y[i][j] >= 352)
                            {
                                cval[cno] = 1;
                            }
                            if (cval[cno] == 1)
                            {
                                if (y[i][j] < 410)
                                {
                                    x[i][j] = x[i][j] + 2;
                                    y[i][j] = y[i][j] + 3;
                                }
                                else
                                {
                                    if (y[i][j] < getmaxy() - 18)
                                    {
                                        x[i][j] = x[i][j] - 2;
                                        y[i][j] = y[i][j] + 2.5;
                                    }
                                    else
                                    {
                                        if (x[i][j] > 220)
                                        {
                                            x[i][j] = x[i][j] - 2.5;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                x[i][j] = x[i][j] - 1.5;
                                y[i][j] = y[i][j] + 2;
                            }
                        }
                    }
                }
                setfillstyle(1, mCol[j % 4]);
                circle(x[i][j], y[i][j], 5);
                floodfill(x[i][j], y[i][j], 8);
            }
        }
        cno = 0;
        delay(50);
    }
    ang = 0.0;
    int pLineVC = 0, bFlag = 0, bFlag1 = 0, liBar1 = liBar;
    for (k = 1; k <= 140; k++)
    {
        cleardevice();
        box();
        if (k < 18)
        {
            ang = ang - (M_PI / 18);
            xSet = rotX(rotCX, rotCY, ang) - rotCX;
            ySet = rotY(rotCX, rotCY, ang) - rotCY;
            line(rotX(xS1, yS1, ang) - xSet, rotY(xS1, yS1, ang) - ySet, rotX(xS2, yS2, ang) - xSet, rotY(xS2, yS2, ang) - ySet);
            line(rotX(xS2, yS2, ang) - xSet, rotY(xS2, yS2, ang) - ySet, rotX(xS3, yS3, ang) - xSet, rotY(xS3, yS3, ang) - ySet);
            line(rotX(xS3, yS3, ang) - xSet, rotY(xS3, yS3, ang) - ySet, rotX(xS4, yS4, ang) - xSet, rotY(xS4, yS4, ang) - ySet);
            line(rotX(xS4, yS4, ang) - xSet, rotY(xS4, yS4, ang) - ySet, rotX(xS1, yS1, ang) - xSet, rotY(xS1, yS1, ang) - ySet);
        }
        else
        {
            ang = -M_PI;
            xS1 = 320.0, yS1 = 285.0, xS2 = 330.0, yS2 = 295.0, xS3 = 320.0, yS3 = 305.0, xS4 = 310.0, yS4 = 295.0;
            line(xS1, yS1, xS2, yS2);
            line(xS2, yS2, xS3, yS3);
            line(xS3, yS3, xS4, yS4);
            line(xS4, yS4, xS1, yS1);
        }
        line(226, getmaxy(), 226, getmaxy() - blSet);
        line(413, getmaxy(), 413, getmaxy() - blSet);
        if (pLineV > 0)
        {
            pLineV = pLineV - 2;
        }
        if (419 + pLineVC <= getmaxy() - 14)
        {
            pLineVC = pLineVC + 2;
        }
        line(268, getmaxy(), 268, 419 + pLineV);
        line(320, getmaxy(), 320, 419 + pLineVC + 1);
        line(371, getmaxy(), 371, 419 + pLineV);
        line(268, 468, 268 + pLineH, 468);
        line(371, 468, 371 - pLineH, 468);
        line(x1l, y1l, xl, yl);
        line(x1r, y1r, xr, yr);
        line(xl, yl, xdl, ydl);
        line(xr, yr, xdr, ydr);
        line(bBarXL1, bBarYL1, bBarXL2, bBarYL2);
        line(bBarXR1, bBarYR1, bBarXR2, bBarYR2);
        if (bFlag == 1)
        {
            if (liBar1 >= 2)
            {
                liBar1 = liBar1 - 2;
            }
        }
        if (liBar >= 2)
        {
            liBar = liBar - 2;
        }
        line(liBarXL1, liBarYL1, liBarXL2, 300 - liBar1);
        line(liBarXR1, liBarYR1, liBarXR2, 300 - liBar);
        if (bFlag == 1)
        {
            x[3][14] = 274;
            x[4][14] = 284;
            x[2][14] = 294;
            x[1][14] = 304;
        }
        if (bFlag1 == 1)
        {
            x[3][7] = 365;
            x[4][7] = 355;
            x[2][7] = 345;
            x[1][7] = 335;
        }
        for (i = 1; i <= 4; i++)
        {
            for (j = 5; j <= 16; j++)
            {
                if (liBar1 <= 0)
                {
                    if (j == 7)
                    {
                        if (y[i][j] < 300)
                        {
                            x[i][j] = x[i][j] + 3;
                            y[i][j] = y[i][j] + 2;
                        }
                        else
                        {
                            if (y[i][j] < 348)
                            {
                                x[i][j] = x[i][j] + 3;
                                y[i][j] = y[i][j] + 3;
                            }
                            else
                            {
                                if (y[i][j] < 417)
                                {
                                    x[i][j] = x[i][j] - 2.2;
                                    y[i][j] = y[i][j] + 4;
                                    if (y[i][j] >= 417)
                                    {
                                        x[i][j] = 274;
                                    }
                                }
                                else
                                {
                                    if (y[i][j] < 461)
                                    {
                                        x[i][j] = x[i][j] + 4;
                                        y[i][j] = y[i][j] + 4;
                                        if (y[i][j] >= 461)
                                        {
                                            y[i][j] = 462;
                                        }
                                    }
                                    else
                                    {
                                        if (x[3][j] < 363)
                                        {
                                            x[i][j] = x[i][j] + 3.5;
                                            if (x[i][j] >= 363)
                                            {
                                                bFlag1 = 1;
                                                x[4][j] = x[4][j] + 3;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (liBar <= 0)
                {
                    if (j == 14)
                    {
                        if (y[i][j] < 300)
                        {
                            x[i][j] = x[i][j] - 3;
                            y[i][j] = y[i][j] + 2;
                        }
                        else
                        {
                            if (y[i][j] < 348)
                            {
                                x[i][j] = x[i][j] - 3;
                                y[i][j] = y[i][j] + 3;
                            }
                            else
                            {
                                if (y[i][j] < 417)
                                {
                                    x[i][j] = x[i][j] + 2.2;
                                    y[i][j] = y[i][j] + 4;
                                    if (y[i][j] >= 417)
                                    {
                                        x[i][j] = 365;
                                    }
                                }
                                else
                                {
                                    if (y[i][j] < 461)
                                    {
                                        x[i][j] = x[i][j] - 4;
                                        y[i][j] = y[i][j] + 4;
                                        if (y[i][j] >= 461)
                                        {
                                            y[i][j] = 462;
                                        }
                                    }
                                    else
                                    {
                                        if (x[3][j] > 277)
                                        {
                                            x[i][j] = x[i][j] - 3.5;
                                            if (x[i][j] <= 277)
                                            {
                                                bFlag = 1;
                                                x[4][j] = x[4][j] - 3;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                setfillstyle(1, mCol[j % 4]);
                circle(x[i][j], y[i][j], 5);
                floodfill(x[i][j], y[i][j], 8);
            }
        }
        delay(50);
    }
    // Third
    gap = 1;
    int blSet1 = 0;
    for (k = 1; k <= 23; k++)
    {
        cleardevice();
        box();
        line(xS1, yS1, xS2, yS2);
        line(xS2, yS2, xS3, yS3);
        line(xS3, yS3, xS4, yS4);
        line(xS4, yS4, xS1, yS1);
        line(x1l, y1l, xl, yl);
        line(x1r, y1r, xr, yr);
        if (ydl > yl)
        {
            ydl = ydl - 4;
        }
        if (ydr > yr)
        {
            ydr = ydr - 4;
        }
        line(xl, yl, xdl, ydl);
        line(xr, yr, xdr, ydr);
        if (x[1][6] > 313)
        {
            if (bBar >= 5)
            {
                bBar = bBar - 5;
            }
        }
        line(320, 199, 320 - bBar, 199);
        line(320, 199, 320 + bBar, 199);
        if (pLineVC > 0)
        {
            pLineVC = pLineVC - 2;
        }
        if (pLineH > 1)
        {
            pLineH = pLineH - 3;
        }
        line(268, getmaxy(), 268, 419 + pLineV);
        line(320, getmaxy(), 320, 419 + pLineVC);
        line(371, getmaxy(), 371, 419 + pLineV);
        line(268, 468, 268 + pLineH, 468);
        line(371, 468, 371 - pLineH, 468);
        if (blSet1 <= 25)
        {
            blSet1 = blSet1 + 2;
        }
        line(310, getmaxy(), 310, getmaxy() - blSet1);
        line(329, getmaxy(), 329, getmaxy() - blSet1);
        line(226, getmaxy(), 226, getmaxy() - blSet);
        line(413, getmaxy(), 413, getmaxy() - blSet);
        for (j = 5; j <= 16; j++)
        {
            for (i = 1; i <= 4; i++)
            {
                if (ydr <= yr)
                {
                    if (j < 7)
                    {
                        if ((y[1][j] < 163 || y[4][j] < 192) && x[i][6] < 315)
                        {
                            y[i][j] = y[i][j] + 1.5;
                            y[i][21 - j] = y[i][21 - j] + 1.5;
                        }
                        if (x[i][6] < 315)
                        {
                            x[i][j] = x[i][j] + 2.5;
                            x[i][21 - j] = x[i][21 - j] - 2.5;
                        }
                    }
                }
                setfillstyle(1, mCol[j % 4]);
                circle(x[i][j], y[i][j], 5);
                floodfill(x[i][j], y[i][j], 8);
            }
        }
        delay(100);
        gap = gap + 0.33;
    }
    gap = 4;
    xdl = xl, ydl = yl, xdr = xr, ydr = yr, bStopL = 0.0, bStopR = 0.0;
    for (k = 1; k <= 22; k++)
    {
        cleardevice();
        box();
        line(268, getmaxy(), 268, 419);
        line(320, getmaxy(), 320, 419);
        line(371, getmaxy(), 371, 419);
        line(xS1, yS1, xS2, yS2);
        line(xS2, yS2, xS3, yS3);
        line(xS3, yS3, xS4, yS4);
        line(xS4, yS4, xS1, yS1);
        line(310, getmaxy(), 310, getmaxy() - blSet1);
        line(329, getmaxy(), 329, getmaxy() - blSet1);
        line(226, getmaxy(), 226, getmaxy() - blSet);
        line(413, getmaxy(), 413, getmaxy() - blSet);
        if (ydl < 197)
        {
            ydl = ydl + 2.2;
            ydr = ydr + 2.2;
        }
        line(x1l, y1l, xl, yl);
        line(x1r, y1r, xr, yr);
        line(xl, yl, xdl, ydl);
        line(xr, yr, xdr, ydr);
        for (j = 5; j <= 16; j++)
        {
            for (i = 1; i <= 4; i++)
            {
                if (i >= gap && (j == 5 || j == 6))
                {
                    if (y[i][j] >= 197)
                    {
                        x[i][j] = x[i][j] - 2;
                        x[i][21 - j] = x[i][21 - j] + 2;
                    }
                }
                if (j == 5 || j == 6)
                {
                    y[i][j] = y[i][j] + 2;
                    y[i][21 - j] = y[i][21 - j] + 2;
                }
                setfillstyle(1, mCol[j % 4]);
                circle(x[i][j], y[i][j], 5);
                circle(x[i][21 - j], y[i][21 - j], 5);
                floodfill(x[i][j], y[i][j], 8);
            }
        }
        gap = gap - 0.2;
        delay(40);
    }
    cno = 0;
    for (i = 1; i < 81; i++)
    {
        cval[i] = 0;
    }
    spl = 0.0, spr = 0.0;
    extra = 0, liBar = 0, bBar = 0, bFlag = 0, bFlag1 = 0;
    for (k = 1; k < 80; k++)
    {
        cleardevice();
        box();
        line(268, getmaxy(), 268, 419);
        line(320, getmaxy(), 320, 419);
        line(371, getmaxy(), 371, 419);
        line(xS1, yS1, xS2, yS2);
        line(xS2, yS2, xS3, yS3);
        line(xS3, yS3, xS4, yS4);
        line(xS4, yS4, xS1, yS1);
        line(310, getmaxy(), 310, getmaxy() - blSet1);
        line(329, getmaxy(), 329, getmaxy() - blSet1);
        line(226, getmaxy(), 226, getmaxy() - blSet);
        line(413, getmaxy(), 413, getmaxy() - blSet);
        cno = 0;
        if (bBar < 25)
        {
            bBar = bBar + 5;
        }
        line(x1l, y1l, xl, yl);
        line(x1r, y1r, xr, yr);
        line(xl, yl, xdl, ydl);
        line(xr, yr, xdr, ydr);
        line(320, 199, 320 - bBar, 199);
        line(320, 199, 320 + bBar, 199);
        if (liBar <= 15)
        {
            liBar = liBar + 1;
        }
        line(255, 300, 255, 300 - liBar);
        line(385, 300, 385, 300 - liBar);
        for (i = 1; i <= 4; i++)
        {
            for (j = 5; j <= 16; j++)
            {
                cno = cno + 1;
                if ((x[i][j] >= 220 && x[i][j] <= 255 && y[i][j] <= 295 && y[i][j] >= 278) || (x[i][j] >= 388 && x[i][j] <= 420 && y[i][j] <= 295 && y[i][j] >= 278))
                {
                    if (x[i][j] >= 220 && x[i][j] <= 255)
                    {
                        if ((i == 2 && j == 5) || (i == 1 && j == 5))
                        {
                            extra = extra + 1;
                        }
                        else
                        {
                            if (x[i][j] < 249 - spl)
                            {
                                x[i][j] = x[i][j] + 2;
                            }
                            if (y[i][j] < 290 - (spl / 2))
                            {
                                y[i][j] = y[i][j] + 2;
                            }
                        }
                    }
                    else if (x[i][j] >= 391 && x[i][j] <= 420)
                    {
                        if ((i == 2 && j == 16) || (i == 1 && j == 16))
                        {
                            extra = extra + 1;
                        }
                        else
                        {
                            if (x[i][j] > 391 + spr)
                            {
                                x[i][j] = x[i][j] - 2;
                            }
                            if (y[i][j] < 290 - (spr / 2))
                            {
                                y[i][j] = y[i][j] + 2;
                            }
                        }
                    }
                    if (x[i][j] == 249 - spl && y[i][j] == 291 - (spl / 2))
                    {
                        spl = spl + 10;
                    }
                    if (x[i][j] == 391 + spr && y[i][j] == 291 - (spr / 2))
                    {
                        spr = spr + 10;
                    }
                }
                else
                {
                    if (i == 1 && (j == 5 || j == 16))
                    {
                        if (y[i][j] <= 272)
                        {
                            if (y[i][j] >= 237)
                            {
                                if (j == 5)
                                {
                                    x[i][j] = x[i][j] - 2.3;
                                    y[i][j] = y[i][j] + 2;
                                }
                                else
                                {
                                    x[i][j] = x[i][j] + 2.3;
                                    y[i][j] = y[i][j] + 2;
                                }
                            }
                            else
                            {
                                if (j == 5)
                                {
                                    x[i][j] = x[i][j] - 2;
                                    y[i][j] = y[i][j] + 2;
                                }
                                else
                                {
                                    x[i][j] = x[i][j] + 2;
                                    y[i][j] = y[i][j] + 2;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (((x[i][j] > 220 && x[i][j] < 314) || (x[i][j] < 420 && x[i][j] > 326)) && cval[cno] != 1)
                        {
                            if (j == 5 || j == 6)
                            {
                                if (y[i][j] >= 237)
                                {
                                    if (i % 2 == 0)
                                    {
                                        if (j == 5)
                                        {
                                            x[i][j] = x[i][j] - 3;
                                            y[i][j] = y[i][j] + 2;
                                        }
                                        else
                                        {
                                            x[i][j] = x[i][j] + 3.1;
                                            y[i][j] = y[i][j] + 3;
                                        }
                                    }
                                    else
                                    {
                                        if (j == 5)
                                        {
                                            x[i][j] = x[i][j] - 2;
                                            y[i][j] = y[i][j] + 3;
                                        }
                                        else
                                        {
                                            x[i][j] = x[i][j] + 3.1;
                                            y[i][j] = y[i][j] + 3;
                                        }
                                    }
                                }
                                else
                                {
                                    x[i][j] = x[i][j] - 2;
                                    y[i][j] = y[i][j] + 2;
                                }
                            }
                            else if (j == 15 || j == 16)
                            {
                                if (y[i][j] >= 237)
                                {
                                    if (i % 2 == 0)
                                    {
                                        if (j == 16)
                                        {
                                            x[i][j] = x[i][j] + 3;
                                            y[i][j] = y[i][j] + 2;
                                        }
                                        else
                                        {
                                            x[i][j] = x[i][j] - 3;
                                            y[i][j] = y[i][j] + 3;
                                        }
                                    }
                                    else
                                    {
                                        if (j == 16)
                                        {
                                            x[i][j] = x[i][j] + 2;
                                            y[i][j] = y[i][j] + 3;
                                        }
                                        else
                                        {
                                            x[i][j] = x[i][j] - 3;
                                            y[i][j] = y[i][j] + 3;
                                        }
                                    }
                                }
                                else
                                {
                                    x[i][j] = x[i][j] + 2;
                                    y[i][j] = y[i][j] + 2;
                                }
                            }
                        }
                        else
                        {
                            if (x[i][j] < 260)
                            {
                                cval[cno] = 1;
                                x[i][j] = x[i][j] + 2;
                                y[i][j] = y[i][j] + 2;
                            }
                            else if (x[i][j] > 260 && x[i][j] < 320)
                            {
                                cval[cno] = 1;
                                if (y[i][j] < 350)
                                {
                                    x[i][j] = x[i][j] - 2.05;
                                    y[i][j] = y[i][j] + 4;
                                }
                                else
                                {
                                    if (y[i][j] < 427)
                                    {
                                        x[i][j] = x[i][j] + 2;
                                        y[i][j] = y[i][j] + 4;
                                    }
                                    else
                                    {
                                        if (y[i][j] < 451)
                                        {
                                            x[i][j] = x[i][j] - 1.6;
                                            y[i][j] = y[i][j] + 4;
                                            if (y[i][j] >= 451)
                                            {
                                                y[i][j] = 451;
                                            }
                                        }
                                        else
                                        {
                                            if (bFlag == 0)
                                            {
                                                if (x[4][j] > 275)
                                                {
                                                    x[i][j] = x[i][j] - 2;
                                                }
                                                else
                                                {
                                                    if (x[4][j] > 275)
                                                    {
                                                        x[i][j] = x[i][j] - 1;
                                                        if (x[4][j] <= 274)
                                                        {
                                                            x[4][j] = 274;
                                                            x[3][j] = 284;
                                                            x[2][j] = 294;
                                                            x[1][j] = 304;
                                                            bFlag = 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (x[i][j] > 320 && x[i][j] < 370)
                            {
                                cval[cno] = 1;
                                if (y[i][j] < 350)
                                {
                                    x[i][j] = x[i][j] + 2;
                                    y[i][j] = y[i][j] + 4;
                                }
                                else
                                {
                                    if (y[i][j] < 427)
                                    {
                                        x[i][j] = x[i][j] - 2;
                                        y[i][j] = y[i][j] + 4;
                                    }
                                    else
                                    {
                                        if (y[i][j] < 451)
                                        {
                                            x[i][j] = x[i][j] + 1.5;
                                            y[i][j] = y[i][j] + 4;
                                            if (y[i][j] >= 451)
                                            {
                                                y[i][j] = 451;
                                            }
                                        }
                                        else
                                        {
                                            if (bFlag1 == 0 && i != 1)
                                            {
                                                if (x[4][j] < 362)
                                                {
                                                    x[i][j] = x[i][j] + 2;
                                                }
                                                else
                                                {
                                                    if (x[4][j] < 365)
                                                    {
                                                        x[i][j] = x[i][j] + 2;
                                                        x[4][j] = 365;
                                                        x[3][j] = 355;
                                                        x[2][j] = 345;
                                                        x[1][j] = 335;
                                                        bFlag1 = 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (x[i][j] > 370)
                            {
                                cval[cno] = 1;
                                x[i][j] = x[i][j] - 2;
                                y[i][j] = y[i][j] + 2;
                            }
                        }
                    }
                }
                setfillstyle(1, mCol[j % 4]);
                circle(x[i][j], y[i][j], 5);
                floodfill(x[i][j], y[i][j], 8);
            }
        }
        cno = 0;
        delay(40);
    }
    bStopL = 0;
    bStopR = 0;
    for (k = 1; k <= 75; k++)
    {
        cleardevice();
        if (k <= 75)
            box();
        line(268, getmaxy(), 268, 419);
        line(320, getmaxy(), 320, 419);
        line(371, getmaxy(), 371, 419);
        line(226, getmaxy(), 226, getmaxy() - blSet);
        line(413, getmaxy(), 413, getmaxy() - blSet);
        line(310, getmaxy(), 310, getmaxy() - blSet1);
        line(329, getmaxy(), 329, getmaxy() - blSet1);
        line(xS1, yS1, xS2, yS2);
        line(xS2, yS2, xS3, yS3);
        line(xS3, yS3, xS4, yS4);
        line(xS4, yS4, xS1, yS1);
        line(x1l, y1l, xl, yl);
        line(x1r, y1r, xr, yr);
        line(xl, yl, xdl, ydl);
        line(xr, yr, xdr, ydr);
        line(320, 199, 295, 199);
        line(320, 199, 345, 199);
        if (liBar >= 2)
        {
            liBar = liBar - 2;
        }
        line(255, 300, 255, 300 - liBar);
        line(385, 300, 385, 300 - liBar);
        if (bStopR == 10)
        {
            bStopR = 11;
        }
        if (bStopL == 10)
        {
            bStopL = 11;
        }
        for (i = 1; i <= 4; i++)
        {
            for (j = 5; j <= 16; j++)
            {
                if (liBar <= 0)
                {
                    if (j == 5)
                    {
                        if (y[i][j] < 300)
                        {
                            x[i][j] = x[i][j] + 3;
                            y[i][j] = y[i][j] + 2;
                            x[i][21 - j] = x[i][21 - j] - 3;
                            y[i][21 - j] = y[i][21 - j] + 2;
                        }
                        else
                        {
                            if (y[i][j] < 348)
                            {
                                x[i][j] = x[i][j] + 3;
                                y[i][j] = y[i][j] + 3;
                                x[i][21 - j] = x[i][21 - j] - 3;
                                y[i][21 - j] = y[i][21 - j] + 3;
                            }
                            else
                            {
                                if (y[i][j] < 427)
                                {
                                    x[i][j] = x[i][j] - 3.5;
                                    y[i][j] = y[i][j] + 3;
                                    x[i][21 - j] = x[i][21 - j] + 3.5;
                                    y[i][21 - j] = y[i][21 - j] + 3;
                                    if (y[i][j] >= 427)
                                    {
                                        y[i][j] = 427;
                                        x[i][j] = 220;
                                        y[i][21 - j] = 427;
                                        x[i][21 - j] = 420;
                                    }
                                }
                                else
                                {
                                    if (y[i][j] < 451)
                                    {
                                        x[i][j] = x[i][j] + 2;
                                        y[i][j] = y[i][j] + 4;
                                        if (y[i][j] >= 451)
                                        {
                                            y[i][j] = 451;
                                            x[i][j] = 232;
                                        }
                                    }
                                    else
                                    {
                                        if (x[i][j] < 260)
                                        {
                                            if (bStopL == 0 || bStopL == 10 || bStopL == 11)
                                            {
                                                x[i][j] = x[i][j] + 4.5;
                                            }
                                            if (x[i][j] >= 260)
                                            {
                                                bStopL = 10;
                                            }
                                            if (bStopL == 11)
                                            {
                                                x[3][j] = 262;
                                                bStopL = 1;
                                            }
                                            if (bStopL == 1 && i == 4)
                                            {
                                                x[i][j] = 252;
                                                x[2][j] = x[2][j] + 3;
                                                x[1][j] = x[1][j] + 3;
                                                bStopL = 2;
                                            }
                                            if (bStopL == 2 && i == 2)
                                            {
                                                x[i][j] = 242;
                                                x[1][j] = x[1][j] + 3;
                                                bStopL = 3;
                                            }
                                            if (bStopL == 3 && i == 1)
                                            {
                                                x[i][j] = 232;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else if (j == 16)
                    {
                        if (y[i][j] < 451 && y[i][j] >= 427)
                        {
                            x[i][j] = x[i][j] - 2;
                            y[i][j] = y[i][j] + 4;
                            if (y[i][j] >= 451)
                            {
                                y[i][j] = 451;
                                x[i][j] = 407;
                            }
                        }
                        else if (y[i][j] >= 451)
                        {
                            if (x[i][j] > 381)
                            {
                                if (bStopR == 0 || bStopR == 10 || bStopR == 11)
                                {
                                    x[i][j] = x[i][j] - 4.5;
                                }
                                if (x[i][j] <= 381)
                                {
                                    bStopR = 10;
                                }
                                if (bStopR == 11)
                                {
                                    x[3][j] = 377;
                                    bStopR = 1;
                                }
                                if (bStopR == 1 && i == 4)
                                {
                                    x[i][j] = 387;
                                    x[2][j] = x[2][j] - 3;
                                    x[1][j] = x[1][j] - 3;
                                    bStopR = 2;
                                }
                                if (bStopR == 2 && i == 2)
                                {
                                    x[i][j] = 397;
                                    x[1][j] = x[1][j] - 3;
                                    bStopR = 3;
                                }
                                if (bStopR == 3 && i == 1)
                                {
                                    x[i][j] = 407;
                                }
                            }
                        }
                    }
                }
                setfillstyle(1, mCol[j % 4]);
                circle(x[i][j], y[i][j], 5);
                floodfill(x[i][j], y[i][j], 8);
            }
        }
        if (k == 75)
        {
            delay(1500);
        }
        delay(50);
    }
    setcolor(RED);
    settextstyle(0, 0, 3);
    outtextxy(110, 70, "Level Completed :)");
    getch();
    closegraph();
    return 0;
}