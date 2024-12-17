#include "MovingAverage.h"

// Constructor
MovingAverage::MovingAverage(size_t size) : windowSize(size), currentIndex(0), isFilled(false), sum(0) {
    window = new float[windowSize](); 
}

// Destructor
MovingAverage::~MovingAverage() {
    delete[] window; 
}

// Add a new value to the moving average
float MovingAverage::addValue(float value) {
    if (isFilled) {
        sum -= window[currentIndex];
    }

    window[currentIndex] = value;
    sum += value;

    currentIndex = (currentIndex + 1) % windowSize;

    if (currentIndex == 0) {
        isFilled = true;
    }

    return getAverage();
}

// Get the current moving average
float MovingAverage::getAverage() const {
    size_t count = isFilled ? windowSize : currentIndex; 
    return count > 0 ? sum / count : 0;
}
