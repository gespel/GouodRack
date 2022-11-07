//
// Created by sten on 27.10.22.
//

#ifndef GOUODRACK_SYNTHS_H
#define GOUODRACK_SYNTHS_H
#include <math.h>


class Synth {

public:
    Synth(double freq, double sampleRate);
    virtual double getSample() = 0;
    virtual void setFrequency(double freq) = 0;

protected:
    double phase = 0.0;
    double sample = 0.0;
    double sampleRate = 0.0;
    double freq = 0.0;
};

class SineSynth : public Synth {
public:
    SineSynth(double freq, double sampleRate);
    double getSample();
    void setFrequency(double freq);
};

class SquareSynth : public Synth {
public:
    SquareSynth(double freq, double sampleRate);
    double getSample();
    void setFrequency(double freq);
};

#endif //GOUODRACK_SYNTHS_H
