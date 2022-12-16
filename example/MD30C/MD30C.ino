#include <MD30C.h>

MD30C Moter = MD30C(13,11);

void setup() {
    MD30C.init();
}

void loop() {
    MD30C.forward(255);
    delay(1000);
    MD30C.back(128);
    delay(1000);
    MD30C.rotation(FORWARD,64);
    delay(1000);
    MD30C.stop();
    delay(1000);

}