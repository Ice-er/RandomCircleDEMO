#include "pch.h"
#include "RandData.h"


void RandData::randomShape()
{
    // TODO: �ڴ˴����ʵ�ִ���.
}


COLORREF RandData::GetColor()
{
    // TODO: �ڴ˴����ʵ�ִ���.
    int nRed, nGreen, nBlue;
    nRed = rand() % 255;
    nGreen = rand() % 255;
    nBlue = rand() % 255;
    return RGB(nRed, nGreen, nBlue);

    //return 0;
}


CPoint RandData::GetPosition()
{
    // TODO: �ڴ˴����ʵ�ִ���.
    int nx, ny;
    nx = rand() % MAXX;
    ny = rand() % MAXY;
    CPoint positionValue;
    positionValue.x = nx;
    positionValue.y = ny;
    return positionValue;

   // return 0;
}


int RandData::GetShapeSize()
{
    // TODO: �ڴ˴����ʵ�ִ���.
    int nShapeSize;
    nShapeSize = MIN + rand() % (MAX - MIN);
    return nShapeSize;

   // return 0;
}


void RandData::GetShapeType()
{
    // TODO: �ڴ˴����ʵ�ִ���.
}

RandData::RandData()
{
    srand(time(NULL));
    MAX = 200;
    MIN = 0;
    MAXX = 500;
    MAXY = 500;

}

void RandData::SetPositionRange(int nX, int nY)
{
    // TODO: �ڴ˴����ʵ�ִ���.

    if (nX > 0 && nY > 0)
    {
        MAXX = nX;
        MAXY = nY;
    }
    else
    {
        MAXX = 1000;
        MAXY = 1000;

    }
}


int RandData::SetShapeRange(int min, int max)
{
    // TODO: �ڴ˴����ʵ�ִ���.

    if (max > 10)
    {
        MAX = max;
        MIN = 0;
    }
    else
    {
        MAX = 300;
        MIN = 0;
    }
    return 0;
    return 0;
}


/*int RandData::MIN()
{
    // TODO: �ڴ˴����ʵ�ִ���.
    return 0;
}*/
