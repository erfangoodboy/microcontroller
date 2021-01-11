#include <mega16.h>
#include <alcd.h>


int timerOverflowCounter;
int xLenght;
int yLenght;
int characterPosition;

char characters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
      timerOverflowCounter++;
      if (characterPosition < 26 ) {
        if(timerOverflowCounter == 500 ){

          lcd_putchar(characters[characterPosition]);
          characterPosition += 1;
          //incress x position
          xLenght=xLenght+1;
          
          //check need to change line 
          if(characterPosition==20){
            xLenght=0;
            yLenght=1;
          }

          lcd_gotoxy(xLenght,yLenght);
          timerOverflowCounter=0;
       }
      }else{
        TCCR0=0x00;
        TIMSK=0x00;
      }
      
      TCNT0=0x00;
}


void main(void)
{

    DDRC=0x00;
    PORTC=0x00; 
    
    xLenght=0;
    yLenght=0;
    timerOverflowCounter=0;
    characterPosition=0;   
    
    TCCR0=0x01;
    TCNT0=0x00;
    OCR0=0x00;
    TIMSK=0x01; 
    
    lcd_init(20);
    #asm("sei")

    while (1)
    {
    }


}
