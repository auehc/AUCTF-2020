#include <stdlib.h>

int func_1();
int func_2();
int func_3(const int x, const int y);

int main()
{
    const int x = func_1();
    const int y = func_2();

    const int z = func_3(x, y);
}

int func_1()
{
    unsigned char i = 25;

    for (int j = 0; j < 10; j++)
    {
        i += (j + 10) * 25;
    }
    int x = (int)i;
    return x;
}

int func_2()
{
    // do a whole lot of garabage
    // red flag simply returns a constant declared earlier
    int i = 207;
    return i;
}

int func_3(const int x, const int y)
{
    if (x < 65)
    {
        return 24;
    }
    if (y > 211)
    {
        return 20;
    }
    if (x && !y)
    {
        return 120;
    }
    if (!x && y)
    {
        return 220;
    }

    int i = x | y;
    int j = x & y;
    int k = x ^ y;

    int out = 0;
    for (int l = 0; l < k; l++)
    {
        out += i + (j - l);
    }

    return out;
}
