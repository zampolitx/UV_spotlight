#include <xc.h>
#include "UV_Spotlight_main.h"
#include <stdio.h>
#include <stdlib.h>
#include "LCD.h"




void main(void) {
    TRISA = 0b00000;
    TRISC = 0x00; //Initialization PORTC all in out
    TRISB = 0b11111101; //Initialization PORTB RB1 OUT;
    Lcd_Init();
    Lcd_Clear();
    while(1)
    {
        char b = "lskdjf";
        char rejim1[] = "lksdjf";
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String(b);
        sprintf(b, "REJIM: %s", rejim1);
        relay = 1;
        __delay_ms(1000);
        Lcd_Clear();
        relay = 0;
        __delay_ms(1000);
        
    }

    return;
}

/*
 
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "main.h" 
#include "lcd.h"
#include "hello.h"
int count2;
int count;
unsigned char eep;
bit start = 0;
int time;
bit rej = 0;
char rejim1[] = "rabota";
char rejim2[] = "nastroyka";

void sohranenie (unsigned char eep)
{
  EEPROM_WriteByte(1,eep);  
};

void mylcd(count, rej)
{
 Lcd_Clear();
 char s[20];
 char b[20];
 if (rej==0) //esli rejim rabota
 {
  Lcd_Set_Cursor(1,1);
  Lcd_Write_String(b);
  sprintf(b, "REJIM: %s", rejim1);
  Lcd_Set_Cursor(2,1);
  Lcd_Write_String(s);
  sprintf(s, "TIME: %d", count);    
 }
 else if (rej==1) //esli rejim nastroyka
 {
 Lcd_Set_Cursor(1,1);
 Lcd_Write_String(b);
 sprintf(b, "REJIM: %s", rejim2);
 Lcd_Set_Cursor(2,1);
 Lcd_Write_String(s);
 sprintf(s, "TIME: %d", eep); 
 }
__delay_ms(90);
};

//Programma obrabotki preryvaniy
void interrupt preryvanie (void)
{   __delay_ms(200);
    if (INTCONbits.RBIF) //Proverka na preryvanie RB7:RB4
    {
        INTCONbits.RBIF = 0; //Sbros flaga preryvaniya
        if ((buttom1 && buttom2) && rej==0) //Esli knopka RB4 & RB5 najata i rejim rabota
        {
            rej=1; //perevodim v rejim nastroyka
            while(buttom1) //ustranyaem drebezg
            {
                _delay(1);
            }
        }
        else if ((buttom1 && buttom2) && rej==1) //Esli knopka RB4 & RB5 najata i rejim nastroyka
        {
            //sohranenie(time);  //esli najali obe knopki v rejime nastroyka
            rej=0;           //perehodiim v rejim rabota
            while(buttom1)   //ustranyaem drebezg
            {
                _delay(1);
            }           
        }
        else if (buttom1 && rej==1 ) //Esli knopka RB4 najata v rejime nastroyka
        {
            eep=eep++;
            sohranenie(eep);  //esli najali obe knopki v rejime nastroyka
            while(buttom1)
            {
                _delay(1);
            }
        }
        else if (buttom2 && rej==1 ) //Esli knopka RB5 najata v rejime nastroyka
        {
            eep=eep--;
            sohranenie(eep);  //esli najali obe knopki v rejime nastroyka
            while(buttom2)
            {
                _delay(1);
            }
        }
        else if (buttom2 && rej==0 ) //Esli knopka RB5 najata v rejime rabota
        {
            start=!start;
            while(buttom2)
            {
                _delay(1);
            }
        }
    }
    else (_delay(1));
};


   

int main()
{
relay=1;                   //vyklychaem rele
eep = EEPROM_ReadByte(1);
TRISA = 0b00000;
TRISC = 0x00; //Initialization PORTC all in out
TRISB = 0b11111101; //Initialization PORTB RB1 OUT;
//Initializing interrupt
INTCONbits.RBIE = 1; //Razreshenie preryvanya RB7:RB4
INTCONbits.RBIF = 0; //Sbros flaga preryvaniya
INTCONbits.GIE = 1; //Razreshenie globalnyh preryvaniy
Lcd_Init();
Lcd_Clear();

hello();
while(1)
{
  time = EEPROM_ReadByte(1);
  count=time;
  relay=1;
  if(start)
    {
      while(count>0)
     {
      relay=0;
      count=count--;
      mylcd(count,rej);
      __delay_ms(1000);
      if(!start) break;
      
     }
     relay=1;
     start=0;
    }
   else relay=1;
 mylcd(count,rej);
}
return 0;
 
}
 */