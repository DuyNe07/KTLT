#include <iostream>
#include <math.h>

using namespace std;

struct toado
{
    int x;
    int y;
};

toado doiXungQuaTungDo(toado A)
{
    A.y = -A.y;
    return A;
}

toado doiXungQuaHoanhDo(toado A)
{
    A.x = -A.x;
    return A;
}

toado doiXungQuaToaDo(toado A)
{
    A.x = -A.x;
    A.y = -A.y;
    return A;
}

toado tongHaiDiem(toado A, toado B)
{
    toado C = {A.x + B.x, A.y + B.y};
    return C;
}

toado hieuHaiDiem(toado A, toado B)
{
    toado C = {A.x - B.x, A.y - B.y};
    return C;
}

toado tichHaiDiem(toado A, toado B)
{
    toado C = {A.x * B.x, A.y * B.y};
    return C;
}

float khoangCachHaiDiem(toado A, toado B)
{
    float ketqua = sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2));
    return ketqua;
}