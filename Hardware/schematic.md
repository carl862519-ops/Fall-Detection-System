# CIRCUIT SCHEMATIC

## Arduino Pin Connections

### Inputs:
1. **Tilt Switch** → Pin 2
   ```
   VCC → Tilt Switch → 10kΩ Resistor → GND
                    → Pin 2 (Arduino)
   ```

### Outputs:
2. **Buzzer** → Pin 8
   ```
   Pin 8 → Buzzer (+) → Buzzer (-) → GND
   ```

3. **Red LED** → Pin 5
   ```
   Pin 5 → 220Ω Resistor → Red LED → GND
   ```

4. **Green LED** → Pin 6
   ```
   Pin 6 → 220Ω Resistor → Green LED → GND
   ```

## Circuit Explanation

### Tilt Switch Operation:
- **Normal Position** (vertical): Switch CLOSED → HIGH signal to Arduino
- **Fall Position** (horizontal): Switch OPEN → LOW signal to Arduino

### Alert System:
- **Green LED**: Continuously ON during normal state
- **Red LED**: Blinks (500ms interval) during fall state
- **Buzzer**: Sounds (800Hz) synchronized with red LED blink

## Power Requirements
- Powered via USB (5V, <200mA)
- Suitable for battery operation
- Low power consumption for 24/7 monitoring
