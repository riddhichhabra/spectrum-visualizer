#include <"input.h">
#include <math>

// TO DO: Var declaration and initialization

// samplesCount
// bandsCount
// fftReal
// fftImag
// bandsMagnitude

// AUDIO_PIN
// SAMPLING_PERIOD_US

/* Function to initialize FFT output 
 * and LED output arrays to 0
 * and ensure no garbage values remain
 */

void analyser_begin()
{
    for (int i = 0; i < samplesCount; i++)
    {
        fftReal[i] = 0.0;
        fftImag[i] = 0.0;
    }
    for (int i = 0; i < bandsCount; i++)
    {
        bandsMagnitude[i] = 0.0;
    }
}

/* Function to start reading audio
 * data from the AUDIO_PIN and store
 * in fftReal array. Delay by sampling
 * period in microseconds and loop
 * for entire sample
 */

void start_sampling()
{
    for (int i = 0; i < samplesCount; i++)
    {
        fftReal[i] = analogRead(AUDIO_PIN);
        // fftImag[i] = 0.0;
        delayMicroseconds(SAMPLING_PERIOD_US);
    }
}


