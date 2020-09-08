
#ifndef lcd4bit_h
#define lcd4bit_h 1

#define Hi 1
#define Lo 0

#ifndef TRUE
	#define TRUE 1
#endif

#ifndef FALSE
	#define FALSE 0
#endif

#define RIGHT 0
#define LEFT  1

void init_lcd(void);
void write_high_lcd(unsigned char Val);
void gotoxy_lcd(unsigned char col,unsigned char line);
void putc_lcd(unsigned char byte);
void print_lcd(char String[]);
void delay_lcd(void);
void write_lcd(unsigned char Val);
void write_low_lcd(unsigned char Val);
void write_command_lcd(char cmd);
void scroll_lcd(char enable, char dir);
//void clear_lcd();
void write_nibble_lcd(unsigned char Val);

#endif

