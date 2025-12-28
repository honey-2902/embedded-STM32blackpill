# embedded-STM32blackpill
STM32blackpill and Embedded C Program

1. Header Files
stm32f4xx.h provides access to STM32 registers.
stdio.h is used for formatted output.

2. Global Variable
adc_val stores the ADC conversion result, updated automatically by DMA.

3. Clock Enable
Enables clocks for GPIOA, DMA2, TIM2, ADC1, and USART1.

4. GPIO Configuration
PA0 is set as analog input for ADC.
PA9 is configured as USART1 TX using alternate function AF7.

5. UART Configuration
USART1 is initialized with a suitable baud rate.
Transmitter and USART are enabled.

6. DMA Configuration
DMA2 Stream0 transfers ADC data directly to memory.
Reduces CPU overhead.

7. ADC Configuration
ADC1 is enabled in continuous conversion mode with DMA support.

8. Timer Configuration
TIM2 generates periodic triggers for ADC conversions.

9. Main Loop
ADC value is formatted and transmitted via UART continuously.

Applications:
Sensor monitoring, embedded systems, IoT, and data logging.


Applications
This system is suitable for sensor data acquisition, embedded monitoring systems, IoT applications, automation projects, and real-time data logging.
