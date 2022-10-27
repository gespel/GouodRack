//
// Created by sten on 27.10.22.
//

#ifndef GOUODRACK_SYNTHS_H
#define GOUODRACK_SYNTHS_H
#include <math.h>


class Synth {
public:
    Synth(float freq, float sampleRate);
    virtual float getSample() = 0;
    virtual void setFrequency(float freq) = 0;

protected:
    float phase = 0.0;
    float sample = 0.0;
    float sampleRate = 0.0;
    float freq = 0.0;
};

class SineSynth : public Synth {
public:
    SineSynth(float freq, float sampleRate);
    float getSample();
    void setFrequency(float freq);
};

#endif //GOUODRACK_SYNTHS_H
