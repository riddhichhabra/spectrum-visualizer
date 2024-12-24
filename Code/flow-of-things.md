Run a loop in cpp file to:
- Window + perform FFT 
- Use LUT
- Add magnitudes
- Scaling

[!NOTE]
Light up the lowest row by default, so height reduces to 15 

Determination of the scaling factor:\
$$Factor = \frac{\text{Max Height \(15\)}}{\text{Max FFT Magnitude}}$$

Two possibilities:
- Fixed Scaling

- Dynamic Scaling