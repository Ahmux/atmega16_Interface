/*
 * keypad_interface.c
 *Interfacing AVR atmega16 with 4x3  keypad and seven segment display
 *
 * Created: 10/1/2017 6:04:22 PM
 * Author : Ahmux
 */ 

#include <avr/io.h>
#include <util/delay.h>
char keys(){
	DDRC = 0x00;
	PORTC = 0xff;
	DDRD = 0xff;
	PORTD = 0b11111111;
	DDRA = 0xff;
	char keys_arr[4][3] ={
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'},
		{'*','0','#'}};

	while (1){
		for (int i=0; i<4; i++){
			PORTD &= ~(1<<i);
			switch (PINC){
				case 0xFE:		//if PC0 =0
				switch (PORTD){
					case 0b11111110:
					return keys_arr[0][0];
					break;
					case 0b11111101:
					return keys_arr[1][0];
					break;
					case 0b11111011:
					return keys_arr[2][0];
					break;
					case 0b11110111:
					return keys_arr[3][0];
					break;
					}
				break;
				case 0xFD:		//if PC1 = 0
				switch(PORTD){
					case 0b11111110:
					return keys_arr[0][1];
					break;
					case 0b11111101:
					return keys_arr[1][1];
					break;
					case 0b11111011:
					return keys_arr[2][1];
					break;
					case 0b11110111:
					return keys_arr[3][1];
					break;
					}	
				break;
				case 0b11111011:		//PC2=0
				switch(PORTD){
					case 0b11111110:
					return keys_arr[0][2];
					break;
					case 0b11111101:
					return keys_arr[1][2];
					break;
					case 0b11111011:
					return keys_arr[2][2];
					break;
					case 0b11110111:
					return keys_arr[3][2];
					break;
				}
				break;
				}
			
			PORTD |= (1<<i);
			}
		}
	
}


void seven_segment(char n){
	switch (n){
		case '1':
		PORTA = 0x01; break;
		case '2':
		PORTA = 0x02; break;
		case '3':
		PORTA = 0x03; break;
		case '4':
		PORTA = 0x04; break;
		case '5':
		PORTA = 0x05; break;
		case '6':
		PORTA = 0x06; break;
		case '7':
		PORTA = 0x07; break;
		case '8':
		PORTA = 0x08; break;
		case '9':
		PORTA = 0x09; break;
		case '0':
		PORTA = 0x00; break;
		case '*':
		PORTA = 0x0A; break;
		case '#':
		PORTA = 0x0B; break;
	}		
}

void main(void)
{
	while(1){
		seven_segment(keys());
	}	
}

