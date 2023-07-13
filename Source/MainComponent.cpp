#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (800, 600);

    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        setAudioChannels (2, 2);
    }
}

MainComponent::~MainComponent()
{
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    wtL->generateRandomWavetable();
    wtR->generateRandomWavetable();
    st2->setMax(2);
    st->setMin(2);
    st->setMax(8);
    st2->setMin(2);
    st2->setMax(8);
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    auto* outBufferL = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
    auto* outBufferR = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);
    
    /*this->wyld++;
    if(this->wyld > 10) {
        this->wyld = 0;
        wtL->generateRandomWavetable();
        wtR->generateRandomWavetable();
    }*/
    
    for (int sample = 0; sample < bufferToFill.numSamples; sample++) {
        auto s = st->getSample();
        auto s2 = st2->getSample();
        st->setFrequency(s2 * 0.8);
        //wtL->setFrequency(s*110);
        //wtR->setFrequency(s*110);
        //auto s2 = x2->getSample()*0.3;
        //x->setFrequency(220.0);
        //x->setFrequency(std::abs(y->getSample()*220));
        //x2->setFrequency(std::abs(z->getSample()*220));
        //x2->setFrequency((y->getSample())*220);
        xL->setFrequency(s*110);
        xR->setFrequency(s*55);
        //wtR->setFrequency(s*55);
        
        outBufferL[sample] = xL->getSample();
        outBufferR[sample] = xR->getSample();
        //outBufferR[sample] = s;
        //outBufferL[sample] = (s + s2)/2;
        //outBufferR[sample] = (s + s2)/2;
    }
}

void MainComponent::releaseResources()
{
    
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

}

void MainComponent::resized()
{

}
