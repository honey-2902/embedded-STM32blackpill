#include "stm32f4xx.h"
#include <stdio.h>

uint16_t adc_val = 0; 

int main(void) {
    
    //Clock enable 
    RCC->AHB1ENR |= 0x400001;     
    RCC->APB1ENR |= 0x01;         
    RCC->APB2ENR |= 0x110;        

    //GPIO setup
    GPIOA->MODER |= 0x03;        
    GPIOA->MODER |= 0x80000;      
    GPIOA->AFR[1] |= 0x70;        

    //UART setup
    USART1->BRR = 0x8A;           
    USART1->CR1 = 0x2008;         

    // DMA setup 
    DMA2_Stream0->PAR = (uint32_t)&(ADC1->DR);
    DMA2_Stream0->M0AR = (uint32_t)&adc_val;
    DMA2_Stream0->NDTR = 1;
    DMA2_Stream0->CR = 0x02000401; 

    //ADC setup
    ADC1->CR2 = 0xB0000101;       

    //TIMER setup 
    TIM2->PSC = 16000 - 1;        
    TIM2->ARR = 10 - 1;          
    TIM2->CR2 = 0x20;             
    TIM2->CR1 = 0x01;            

    char msg[20];
    while(1) {
        sprintf(msg, "ADC: %d\r", adc_val);
        for(int i=0; msg[i] != '\0'; i++) {
            while(!(USART1->SR & 0x80));
            USART1->DR = msg[i];
        }
        for(int i=0; i<100000; i++); 
    }
}