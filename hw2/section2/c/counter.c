
#include <mega16.h>
#include <delay.h>

int temp;
int led7Number[10] = {0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 , 0b01101101 , 0b01111101 , 0b00000111 ,0b01111111 ,0b01101111};

int overflow0 =0;
int overflow1 =0;
int number7seg[4] = {0,0,0,0};
int i =3;
int endCounter=3;

interrupt [TIM0_OVF] void timer0_ovf_isr(void){

   ++overflow0;
    if(overflow0 ==2){
           temp = PORTC ^ 0b11111111;
           PORTC= temp ^ 0b11111111;
           PORTD = led7Number[number7seg[endCounter]];
           temp = temp >>1;
           if(temp ==0){
           temp = 8;
           }
           temp = temp ^ 0b11111111;
           PORTC = temp;
           temp = temp ^ 0b11111111;

              overflow0=0;
             endCounter--;
             if(endCounter == -1 ){
             endCounter = 3;
             }
    }


       TCNT0=0x00;

}

interrupt [TIM1_OVF] void timer1_ovf_isr(void){

    ++overflow1;
    if(overflow1 ==500){

         number7seg[3]++;

         while (i>=0){

            if( number7seg[i] ==10){

            number7seg[i-1]++;
            number7seg[i]=0;

            }
             i--;
         }


                   i=3;
             overflow1=0;

    }


        TCNT1H=0xFF;
        TCNT1L=0xF0;

}



void main(void){



DDRD=0b11111111;
PORTD=0b00000000;
DDRC=0b11111111;
PORTC=0b11101111;

TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);



TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0=0x00;
OCR0=0x00;

TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (1<<CS12) | (0<<CS11) | (1<<CS10);
TCNT1H=0xFF;
TCNT1L=0xF0;

MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);

#asm("sei")
while (1)
      {




      }
}
