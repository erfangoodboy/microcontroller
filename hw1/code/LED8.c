#include <mega16.h>
#include <delay.h>

// Declare your global variables here
#define LED0 PORTB.0
#define LED1 PORTB.1
#define LED2 PORTB.2
#define LED3 PORTB.3
#define LED4 PORTB.4
#define LED5 PORTB.5
#define LED6 PORTB.6
#define LED7 PORTB.7

#define turn_on 1
#define turn_off 0

void main(void)
{
    DDRA = 0x00;   
    PINA = 0x00;  
    DDRB = 0xff;  
    PORTB = 0x00;
    #asm("sei")

    while (1) {  
            if(PINA.0==1)    
            {  
                LED0 = turn_on;
                delay_ms(50);
                LED0 = turn_off;
                
                LED1 = turn_on;
                delay_ms(50);
                LED1 = turn_off;    
                
                LED2 = turn_on;
                delay_ms(50);
                LED2 = turn_off;         
                
                LED3 = turn_on;
                delay_ms(50);
                LED3 = turn_off;     
                
                LED4 = turn_on;
                delay_ms(50);
                LED4 = turn_off;     
                
                LED5 = turn_on;
                delay_ms(50);
                LED5 = turn_off;       
                
                LED6 = turn_on;
                delay_ms(50);
                LED6 = turn_off;        
                
                LED7 = turn_on;
                delay_ms(50);
                LED7 = turn_off;      
                
                LED6 = turn_on;
                delay_ms(50);
                LED6 = turn_off; 
                        
                LED5 = turn_on;
                delay_ms(50);
                LED5 = turn_off; 
                
                LED4 = turn_on;
                delay_ms(50);
                LED4 = turn_off;  
                
                LED3 = turn_on;
                delay_ms(50);
                LED3 = turn_off;    
                
                LED2 = turn_on;
                delay_ms(50);
                LED2 = turn_off; 
                
                LED1 = turn_on;
                delay_ms(50);
                LED1 = turn_off;
                
                LED0 = turn_on;
                delay_ms(50);
                LED0 = turn_off;
            } else {
                PORTB = 00000000;
            }
    }
}