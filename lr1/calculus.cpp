#include "calculus.h"
#include "armadillo"

#include <cmath>

using namespace arma;

calculus::calculus(float X1, float Y1, float R1, float X2, float Y2, float R2)
{
    x1 = X1;
    y1 = Y1;
    r1 = R1;
    x2 = X2;
    y2 = Y2;
    r2 = R2;
    float dx = x1 - x2;
    float dy = y1 - y2;
    float dxy = sqrt(pow(dx, 2) + pow(dy, 2));
    float R = (r1 + r2) / dxy;
//    угол между касательной и отрезком, соединяющим центры окружностей
    float theta = acos(R) * 180.0 / M_PI;
//    вычисление точек касания
    float x02 = x2 - r2 * cos((90 - theta) * M_PI / 180);
    float y02 = y2 + r2 * sin((90 - theta) * M_PI / 180);
    float x01 = x1 + r1 * cos((90 - theta) * M_PI / 180);
    float y01 = y1 - r1 * sin((90 - theta) * M_PI / 180);
    float dxy0 = sqrt(pow((x02 - x01), 2) + pow((y02 - y01), 2));
//    однородные координаты конца масштабированного единичного вектора
    mat tmp = {{(double)(x2 + (dx * dxy0 / dxy)), (double)(y2 + (dy * dxy0 / dxy)), 1}};
//    mat m0 = {{(double)x2, (double)y2, 1},
//              {(double)(x2 + (dx * dxy0 / dxy)), (double)(y2 + (dy * dxy0 / dxy)), 1}};
//    параллельный перенос точки в начало координат
    mat mltransfer = {{1, 0, 0},
                      {0, 1, 0},
                      {(double)(-x2), (double)(-y2), 1}};
//    поворот точки вокруг начала координат
    mat mrotation = {{(double)R, sqrt(1 - pow(R, 2)), 0},
                     {-sqrt(1 - pow(R, 2)), (double)R, 0},
                     {0, 0, 1}};
//    перенос к точке касания
    mat mrtransfer = {{1, 0, 0},
                      {0, 1, 0},
                      {(double)(x02 - x2), (double)(y02 - y2), 1}};
//    параллельный перенос точки на прежнее место
    mat mrtransfert = {{1, 0, 0},
                      {0, 1, 0},
                      {(double)x2, (double)y2, 1}};
    mat tmp2 = tmp * mltransfer * mrotation * mrtransfert;
//    координаты отрезка "повёрнутая точка - центр окружности 2"
    mat m0 = {{tmp2(0, 0), tmp2(0, 1), 1},
          {(double)x2, (double)y2, 1}};
    mat mres = m0 * mrtransfer;
    xt1 = mres(0, 0) / mres(0, 2);
    xt2 = mres(1, 0) / mres(1, 2);
    yt1 = mres(0, 1) / mres(0, 2);
    yt2 = mres(1, 1) / mres(1, 2);
//    xt1 = tmp2(0, 0);
//    xt2 = x2;
//    yt1 = tmp2(0, 1);
//    yt2 = y2;
//    xt1 = x01;
//    xt2 = x02;
//    yt1 = y01;
//    yt2 = y02;
}

