#include <addr_7seg.h>

#define PIN 6
#define NUMDISPLAYS 6

Addr_7seg displays7seg(PIN, NUMDISPLAYS);

void setup()
{

    for (int i = 0; i < 10; i++)
    {
        displays7seg.setBrightness(i, 10 * (i + 1));
        displays7seg.setDisplay(i, i);
    }
}

void loop()
{

    delay(1000);

    for (int i = 0; i < 10; i++)
    {
        displays7seg.setDisplay(0, i);
        bool point = displays7seg.getPoint(0);
        displays7seg.setPoint(0, !point);
        delay(1000);
    }
}