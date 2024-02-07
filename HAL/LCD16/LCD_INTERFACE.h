/*
 * LCD_INTERFACE.h
 *
 * Created: 10/11/2022 04:33:11 م
 *  Author: hp
 */ 

#define  RS PIN11
#define  EN PIN8
#define D7 PIN12
#define D6 PIN13
#define D5 PIN14
#define D4 PIN15
typedef enum{
	arrow_cg=0,
	man_cg=8,
	man_with_arrow_cg=16,
	dead_man1_cg=24,
	dead_man2_cg=32
	}patterns_locatin_in_cg;
typedef enum{
	arrow_dd=0x00,
	man_dd=0x01,
	man_with_arrow_dd=0x02,
	dead_man1_dd=0x03,
	dead_man2_dd=0x04
}patterns_locatin_in_dd;
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#define  const_bit_DDRAM  128
#define  start_line2_DDRAM  64

extern u8 pattern1[];
void LCD_INIT(void);
void LCD_Pin_Init(void);
void LCD_WRITE_NUMBER(s32 num);
void LCD_WRITEchare(u8 char1);
void LCD_WRITE_string(u8*char1); 
void LCD_CLEAR(void);
void LCD_WRITE_BINARY1(u8 num);
void LCD_WRITE_BINARY2(u8 num);
void LCD_WRITE_hex(u8 num);
void LCD_SETCURSOR(u8 line,u8 cell);
void LCD_CLEAR_CELLS(u8 line,u8 cell,u8 num_of_cells);
void lcd_write_number_four_D(s32 num);
void LCD_shift_right(void);
void LCD_shift_lift(void);
void lcd_back_steps(u8 steps);
void lcd_forward_steps(u8 steps);
void LCD_START(s8 *str,u8 size,u8 line);
void LCD_START2(u8 size);
void LCD_move_string(s8*str,u8 size);
void lcd_game(void);
void creat_charater_in_cg(u8*pattern);
void LCD_write_fnumber(double num);
void LCD_SetCursor(u8 line , u8 cell);
#endif /* LCD_INTERFACE_H_ */
