/*
 * LCD.c
 *
 * Created: 10/11/2022 04:32:43 م
 *  Author: hp
 */ 


#include "BIT_MATHS.h"
#include "STD_TYPES.h"
#include "STM32F103xx.h"
#include "GPIO.interface.h"
#include "SysTick_interface.h"
#include "LCD_INTERFACE.h"
#include "LCD_CFG.h"


#if mode==_8_bit

static void LCD_write_instruction(u8 inst){
	DIO_writepin(RS,low);
	DIO_WritePort(LCD_PORT,inst);
	DIO_writepin(EN,high);
	_delay_ms((1));
	DIO_writepin(EN,low);
	_delay_ms((1));
}

static void LCD_writeDATA(u32 DATA){
	DIO_writepin(RS,high);
	DIO_WritePort(LCD_PORT,DATA);
	DIO_writepin(EN,high);
	_delay_ms((1));
	DIO_writepin(EN,low);
	_delay_ms((1));
}
void LCD_INIT(){
	_delay_ms(50);
	LCD_write_instruction(0x38);//screen on 8 bit mode
	
	LCD_write_instruction(0x0c);//cursor off 0x0e,0x0f
	
	LCD_write_instruction(0x01);//clear screen
	
	_delay_ms((1));
	LCD_write_instruction(0x06);
  LCD_write_instruction(64+arrow);
  for(u8 i=0;i<8;i++){
	  LCD_writeDATA(arrow_pattern[i]);
  }
 LCD_write_instruction(64+man);
 for(u8 i=0;i<8;i++){
	 LCD_writeDATA(man_pattern[i]);
 }
 LCD_write_instruction(64+man_with_arrow);
 for(u8 i=0;i<8;i++){
	 LCD_writeDATA(man_with_arrow_pattern[i]);
 }
 LCD_write_instruction(64+dead_man1);
 for(u8 i=0;i<8;i++){
	 LCD_writeDATA(dead_man_pattern1[i]);
 }
 LCD_write_instruction(64+dead_man2);
 for(u8 i=0;i<8;i++){
	 LCD_writeDATA(dead_man_pattern2[i]);
 }
 LCD_write_instruction(128);
}
#elif mode ==_4_bit





static void LCD_write_instruction(u8 inst){


	Gpio_u8_SetPinvalue(PORTA,RS,PIN_LOW);

	Gpio_u8_SetPinvalue(PORTB,D7,READ_BIT(inst,7));
	Gpio_u8_SetPinvalue(PORTB,D6,READ_BIT(inst,6));
	Gpio_u8_SetPinvalue(PORTB,D5,READ_BIT(inst,5));
	Gpio_u8_SetPinvalue(PORTB,D4,READ_BIT(inst,4));

	Gpio_u8_SetPinvalue(PORTA,EN,PIN_HIGH);
	SysTick_delay_ms(1);
	Gpio_u8_SetPinvalue(PORTA,EN,PIN_LOW);
	SysTick_delay_ms(1);
	    Gpio_u8_SetPinvalue(PORTB,D7,READ_BIT(inst,3));
		Gpio_u8_SetPinvalue(PORTB,D6,READ_BIT(inst,2));
		Gpio_u8_SetPinvalue(PORTB,D5,READ_BIT(inst,1));
		Gpio_u8_SetPinvalue(PORTB,D4,READ_BIT(inst,0));

		Gpio_u8_SetPinvalue(PORTA,EN,PIN_HIGH);
			SysTick_delay_ms(1);
			Gpio_u8_SetPinvalue(PORTA,EN,PIN_LOW);
			SysTick_delay_ms(1);
}

static void LCD_writeDATA(u32 DATA){
	Gpio_u8_SetPinvalue(PORTA,RS,PIN_HIGH);

	Gpio_u8_SetPinvalue(PORTB,D7,READ_BIT(DATA,7));
	Gpio_u8_SetPinvalue(PORTB,D6,READ_BIT(DATA,6));
	Gpio_u8_SetPinvalue(PORTB,D5,READ_BIT(DATA,5));
	Gpio_u8_SetPinvalue(PORTB,D4,READ_BIT(DATA,4));

	Gpio_u8_SetPinvalue(PORTA,EN,PIN_HIGH);
		SysTick_delay_ms(1);
		Gpio_u8_SetPinvalue(PORTA,EN,PIN_LOW);
		SysTick_delay_ms(1);
		 Gpio_u8_SetPinvalue(PORTB,D7,READ_BIT(DATA,3));
		Gpio_u8_SetPinvalue(PORTB,D6,READ_BIT(DATA,2));
		Gpio_u8_SetPinvalue(PORTB,D5,READ_BIT(DATA,1));
		Gpio_u8_SetPinvalue(PORTB,D4,READ_BIT(DATA,0));
		Gpio_u8_SetPinvalue(PORTA,EN,PIN_HIGH);
					SysTick_delay_ms(1);
					Gpio_u8_SetPinvalue(PORTA,EN,PIN_LOW);
					SysTick_delay_ms(1);
	
}

void LCD_INIT(){
	SysTick_delay_ms(50);
	LCD_write_instruction(0x02);
	LCD_write_instruction(0x28);//screen on 8 bit mode
	LCD_write_instruction(0x0c);//cursor off 0x0e,0x0f
	LCD_write_instruction(0x01);//clear screen
	SysTick_delay_ms(1);
	LCD_write_instruction(0x06);
	
	/*
	 LCD_write_instruction(64+arrow_cg);
	 for(u8 i=0;i<8;i++){
		 LCD_writeDATA(arrow_pattern[i]);
	 }
	 _delay_ms((1));
	 LCD_write_instruction(64+man_cg);
	 for(u8 i=0;i<8;i++){
		 LCD_writeDATA(man_pattern[i]);
	 }
	 _delay_ms((1));
	 LCD_write_instruction(64+man_with_arrow_cg);
	 for(u8 i=0;i<8;i++){
		 LCD_writeDATA(man_with_arrow_pattern[i]);
	 }
	 _delay_ms((1));
	 LCD_write_instruction(64+dead_man1_cg);
	 for(u8 i=0;i<8;i++){
		 LCD_writeDATA(dead_man_pattern1[i]);
	 }
	 _delay_ms((1));
	  LCD_write_instruction(64+dead_man2_cg);
	  for(u8 i=0;i<8;i++){
		  LCD_writeDATA(dead_man_pattern2[i]);
	  }
	   for(u8 i=0;i<8;i++){
		   LCD_writeDATA(cassette_pattern[i]);
	   }
	 _delay_ms((1));
	 LCD_write_instruction(128);
	 */
}

#endif

static void LCD_write_negative_num(s32 num,u8*str){
	num*=-1;u8 i=0;
	while(num){
		str[i]=(num%10)+'0';
		num/=10;
		i++;
	}
	LCD_writeDATA('-');
	for(;i>0;i--){
		LCD_writeDATA(str[i-1]);
	}
}
static void LCD_write_pos_num(s32 num,u8*str){
	u8 i=0;
	while(num){
		str[i]=(num%10)+'0';
		num/=10;
		i++;
	}
	for(;i>0;i--){
		LCD_writeDATA(str[i-1]);
	}
}

           void LCD_WRITEchare(u8 char1)
		   {
            	LCD_writeDATA(char1);
           }
		   
		   
           void LCD_CLEAR(void)
		   {
			   
	LCD_write_instruction(0x01);//clear screen
		_delay_ms((1));
	
          }
		  
void LCD_WRITE_NUMBER(s32 num){
	if(num==0){
		LCD_writeDATA('0');
		
	}else
	{
	char str[16];
	if(num<0){
		LCD_write_negative_num(num,str);
	}else{
	LCD_write_pos_num(num,str);	
	}
	}
}

   void LCD_WRITE_string(u8*char1){
	for(u16 i=0;char1[i];i++){
		LCD_WRITEchare(char1[i]);
	}
  }
  
void LCD_WRITE_BINARY1(u8 num){
	u8 arr[8]={0},i=0;
	while(num){
		arr[i]=num%2;
		num/=2;
		i++;
	}
	for(i=8;i>0;i--){
		LCD_WRITEchare((arr[i-1]+'0'));
	}
}

void LCD_WRITE_BINARY2(u8 num){
	u8 i=8;
	while(i--){
		LCD_WRITEchare(((num>>i)&(1))+'0');
	}
}

void LCD_WRITE_hex(u8 num){
	u8 arr[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	struct temp{
		u8 nu1:4;
		u8 nu2:4;
		};
		struct temp s1;
	s1.nu2=num;
	s1.nu1=num>>4;
	
		LCD_WRITEchare(arr[(s1.nu1)]);
        LCD_WRITEchare(arr[(s1.nu2)]);
	}
	
	void LCD_SETCURSOR(u8 line,u8 cell){
		cell--;
		if(line==1)
		{
           LCD_write_instruction(const_bit_DDRAM|cell);
		}
		else
		{
			
			LCD_write_instruction(const_bit_DDRAM|start_line2_DDRAM|cell);
		}
		
	}
	
	void LCD_SetCursor(u8 line , u8 cell) {

		if(line==0) {

			LCD_write_instruction(0x80+cell) ;


		}
		else if (line==1)	{


			LCD_write_instruction((0x80+0x40)+cell) ;

		}
	}


	void LCD_CLEAR_CELLS(u8 line,u8 cell,u8 num_of_cells){
		LCD_SETCURSOR(line,cell);
		for(u8 i=0;i<num_of_cells;i++)
		{
			LCD_WRITEchare(' ');
	    }
			LCD_SETCURSOR(line,cell);
	}
	
	void lcd_write_number_four_D(s32 num){
		u8 str[4]={'0','0','0','0'};
	   if(num>0){
		   u8 i=4;
		   while(i){
			   str[i-1]=(num%10)+'0';
			   num/=10;
			   i--;
		   }
		   
		   for(i=0;i<4;i++){
			   LCD_writeDATA(str[i]);
		   }
	   }else{
		   num=num*-1;
		   LCD_WRITEchare('-');
		    u8 i=3;
		    while(i){
			    str[i-1]=(num%10)+'0';
			    num/=10;
			    i--;
		    }
		    
		    for(i=0;i<3;i++){
			    LCD_writeDATA(str[i]);
		    }
	   }
	}
	
	void LCD_shift_right(){
		LCD_write_instruction(28);
	}
	void LCD_shift_lift(){
		
			LCD_write_instruction(24);
		
		
	}
	void lcd_back_steps(u8 steps)
	{
		for (u8 i=0;i<steps;i++)
		
		{
			LCD_shift_lift();
		}
	}
		void lcd_forward_steps(u8 steps)
		{
			for (u8 i=0;i<steps;i++)
			
			{
				LCD_shift_right();
			}
		}
		
	void LCD_START(s8 *str,u8 size,u8 line){
		
		for(u8 i=size;i>0;i--){
			LCD_SETCURSOR(line,1);
			for(u8 k=0;k<size-(i-1);k++){
				LCD_WRITEchare(str[(i-1)+(k)]);
			}
			_delay_ms(100);
			
			
		}
	}

	void LCD_move_string(s8*str,u8 size){
		
		LCD_START(str,size,1);
		for(u8 i=0;i<16;i++){
			LCD_shift_right();
			_delay_ms(300);
		}
		
		LCD_CLEAR();
		
		
		LCD_START(str,size,2);
		for(u8 i=0;i<16;i++){
			LCD_shift_right();
			_delay_ms(300);
		}
		LCD_CLEAR();
	}
	
 void lcd_game(){
	 LCD_CLEAR();
	 LCD_SETCURSOR(1,1);
	 LCD_writeDATA(man_dd);
	  LCD_SETCURSOR(1,16);
	  LCD_writeDATA(man_dd);
	for(u8 i=1;i<16;i++){
		if(i==15){
			LCD_SETCURSOR(1,1+i);
			LCD_writeDATA(man_with_arrow_dd);
			_delay_ms(300);
			LCD_SETCURSOR(1,i);
			LCD_writeDATA(dead_man1_dd);
			LCD_SETCURSOR(1,i+1);
			LCD_writeDATA(dead_man2_dd);
			_delay_ms(300);
		}
		LCD_SETCURSOR(1,1+i);
		LCD_writeDATA(arrow_dd);
		_delay_ms(200);
		LCD_SETCURSOR(1,1+i);
		LCD_writeDATA(' ');
		
	}
	
	}
	void LCD_write_fnumber(double num){
		
		s32 lift_point=num;
		double right_point=num-lift_point;
		s32 temp=right_point;
		while((right_point-temp)!=0){
			right_point*=10;
			temp=right_point;
		}
		LCD_WRITE_NUMBER(lift_point);
		LCD_WRITEchare('.');
		LCD_WRITE_NUMBER(right_point);
	}

