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

}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    auto* outBufferL = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
    auto* outBufferR = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);
    
    for (int sample = 0; sample < bufferToFill.numSamples; sample++) {
        auto s = x->getSample()*0.3;

        
        x->setFrequency(y->getSample()*220);
        //x2->setFrequency((y->getSample())*220);
        
        
        
        
        
        outBufferL[sample] = s;
        outBufferR[sample] = s;
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
