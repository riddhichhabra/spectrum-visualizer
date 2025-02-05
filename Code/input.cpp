#include <"input.h">
#include <math>

// TO DO: Var declaration and initialization

// samplesCount
// bandsCount
// fftReal
// fftImag
// bandsMagnitude
// minNoise
// heightModifyingConst

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

void sampling()
{
    for (int i = 0; i < samplesCount; i++)
    {
        fftReal[i] = analogRead(AUDIO_PIN);
        delayMicroseconds(SAMPLING_PERIOD_US);
    }
}

/* Function description
 *
 *
 */
void load_samples()
{
    for (int i = 0; i < samplesCount; i++){

    }
}

void calculate_bars_height()
{
    // FFT.removeDC();
    // FFT.windowing();
    // FFT.perform();
    // FFT.C2M(); i.e. convert to magnitudes

    for (int i = 0; i < bandsCount; i++){
        bandsMagnitude[i] = 0.0;
    }

    for (int i=0; i < usableSamplesCount; i++){
        if(fftReal[i] > minNoise){
            bandsMagnitude[bands[i]] += fftReal;
        }
    }
    
    for (int i = 0; i < bandsCount; i++){
        bandsMagnitude[i] *= heightModifyingConst;
    }


}


void IRAM_ATTR on_timer_sample() {
  portENTER_CRITICAL_ISR(&sampling_timerMux);
  adc_readings_counter++;
  readings_buffer[reading_buffer_index++] = analogRead(A6);
  if(reading_buffer_index >= READING_BUFFER_SIZE)
    reading_buffer_index = 0;
  portEXIT_CRITICAL_ISR(&sampling_timerMux);
}

