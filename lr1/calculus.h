#ifndef CALCULUS_H
#define CALCULUS_H

class calculus
{
public:
    float x1, y1, r1, x2, y2, r2, x01, x02, y01, y02;
    calculus(float, float, float, float, float, float);
    float pointsOfTangency();
};

#endif // CALCULUS_H
