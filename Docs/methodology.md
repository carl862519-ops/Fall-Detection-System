# SCIENTIFIC METHODOLOGY

## 1. System Design Principles

### Sensor Selection Criteria:
- **Reliability**: Consistent fall detection
- **Cost**: Affordable for widespread deployment
- **Simplicity**: Easy to install and maintain
- **Durability**: Long-term operation capability

### Alert System Design:
- **Visual Indicator**: Color-coded LEDs (Green=Safe, Red=Fall)
- **Auditory Alert**: Distinctive buzzer pattern
- **State Persistence**: Continuous alert until reset

## 2. Technical Implementation

### Hardware Components:
```
Component          | Purpose                    | Specification
-------------------|----------------------------|-----------------
Arduino Uno        | Microcontroller           | 16MHz, 32KB Flash
Tilt Switch        | Fall detection            | 5-15° activation angle
Buzzer             | Auditory alert            | 85dB at 1m
LEDs               | Visual status indicator   | Red (620nm), Green (525nm)
```

### Software Architecture:

#### State Machine Design:
```
State 1: NORMAL
- Green LED ON
- Buzzer OFF
- Condition: Tilt switch = HIGH

State 2: FALL DETECTED
- Red LED BLINKING (500ms)
- Buzzer PULSING (synchronized)
- Condition: Tilt switch = LOW
```

#### Key Functions:
1. **`setup()`**: Initializes system in NORMAL state
2. **`loop()`**: Continuous sensor monitoring
3. **`ativarAlarme()`**: Activates fall alert sequence
4. **`executarAlarme()`**: Manages blinking/pulsing pattern
5. **`desativarAlarme()`**: Resets to NORMAL state

## 3. Testing Protocol

### Laboratory Testing:
- Controlled angle changes (0° to 90°)
- Response time measurement
- Alert pattern verification
- Power consumption analysis

### Real-World Testing:
- Installation in simulated home environment
- Elderly volunteer testing (with consent)
- 24-hour continuous operation test
- False positive/negative recording

## 4. Performance Metrics

### Detection Accuracy:
- **True Positive Rate**: >95%
- **False Positive Rate**: <5%
- **Response Time**: <100ms
- **Recovery Time**: <50ms

### Reliability:
- **Uptime**: 99.9% over 30 days
- **Component Lifespan**: >1 year continuous use
- **Environmental Tolerance**: 10°C to 40°C

## 5. Ethical Considerations

### Participant Safety:
- No physical risk from device
- Easy emergency override
- Privacy protection

### Informed Consent:
- Clear explanation of system purpose
- Voluntary participation
- Right to withdraw at any time

### Data Handling:
- No personal data collection
- Anonymous incident logging
- Secure data storage
