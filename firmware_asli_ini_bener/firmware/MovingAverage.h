#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H

#include <Arduino.h>

class MovingAverage {
private:
    float* window;
    size_t windowSize;
    size_t currentIndex;
    bool isFilled;
    float sum;

public:
    MovingAverage(size_t size);
    ~MovingAverage();
    float addValue(float value);
    float getAverage() const;
};

#endif
