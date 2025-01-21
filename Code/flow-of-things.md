## Flow
- Initialise a variable array to store FFT results
Run a loop in cpp file to:
- Collect audio sample of a specific length
- Clear the variable array storing FFT results
- 
- Window + perform FFT 
- Use LUT
- Add magnitudes
- Scaling

### Determining the cores
- Core 0
- Core 1

> [!NOTE]
> Light up the lowest row by default, so height reduces to 15 

## Determination of the scaling factor:
$$\text{Factor} = \frac{\text{Max Height \(15\)}}{\text{Max FFT Magnitude}}$$

Two possibilities:
- Fixed Scaling

- Dynamic Scaling

## To be done:
- [ ] find the sampling frequency
- [ ] find how to calculate scaling factor

## Flow for input.cpp

- function to read analog values
- sampling rate should be atleast twice the highest frequency : Nyquist theorem
- perform FFT
- set brightness, color etc for LEDs based on FFT output
- 