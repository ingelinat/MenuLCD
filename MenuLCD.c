/*
   Menú para controlar LEDs
   
   2 pulsadores de control:
      A0 = Control de los menús
      A1 = Encender/Apagar LED
   
   Autor: Jaime Martínez.
   Fecha: 03/01/2019
*/

#include <16F876.h>

#use delay (clock = 4M)

#fuses XT, NOWDT

#include <lcd.c>

#use standard_io(A)
#use standard_io(C)

enum menu {LED_D1, LED_D2, LED_D3}; //LED_D1 = 0, LED_D2 = 1, LED_D3 = 2

void nav(int m)
{
   switch (m)
   {
      case LED_D1:
         lcd_gotoxy(1,1);
         printf(lcd_putc, "LED D1");
         if (input(PIN_A1)==1)
         {
            output_toggle (PIN_C2);
            delay_ms(300);
         }
         break;
         
      case LED_D2:
         lcd_gotoxy(1,1);
         printf(lcd_putc, "LED D2");
         if (input(PIN_A1) == 1)
         {
            output_toggle (PIN_C1);
            delay_ms(300);
         }
         break;
      
      case LED_D3:
         lcd_gotoxy(1,1);
         printf(lcd_putc, "LED D3");
         if (input(PIN_A1) == 1)
         {
            output_toggle (PIN_C0);
            delay_ms(300);
         }
         break;        
   }
}

void main ()
{
   lcd_init();

   int m = 0;
   
   while(1)
   {
      if (input(PIN_A0) == 1)
      {
         m++;
         delay_ms(300);
      }
      
      if(m > 2)
      {
         m = 0;
      }
      
      nav(m);
      
   }
}



