#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

enum class MODE {
    STOP,
    FORWARD,
    BACK
};

class MD30C {
    public:
        MD30C(uint8_t dir_pin, uint8_t pwm_pin);
        void init();
        void rotation(MODE mode,uint8_t pwm = 0);
        void forward(uint_t pwm);
        void back(uint_t pwm);
        void stop();
    private:
        uint8_t dir_pin;
        uint8_t pwm_pin;
};