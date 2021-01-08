#include <reg51.h>

float numb; 
char digit; 
char xdata mas[8]; 
char m = 1;
char mm;
int i = 0;

void Int00(void) interrupt 0  {  
	char x = P3;  
	switch (x)   { 
		case 0x13: digit = '0'; break; 
    case 0x77: digit = '1'; break;
    case 0x73: digit = '2'; break;
    case 0x71: digit = '3'; break;
    case 0x70: digit = '4'; break;
    case 0x37: digit = '5'; break;
    case 0x33: digit = '6'; break;
    case 0x31: digit = '7'; break;
    case 0x30: digit = '8'; break;
    case 0x17: digit = '9'; break;
		case 0x11: digit = ',' ; break;
		case 0x10: digit = 'e'; break;
			  default: digit = 0xff;		
	}
	if(digit == ',') {
		mm = m; 
		mas[i++] = digit;  
    digit = 0xff;
	} 
	if(digit == 'e') {  
		digit = 0xff ; 
		numb /= mm;  
	} 
	if (digit != 0xff) { 
		mas[i++] = digit; 
		m *= 10;
    numb = numb * 10 + (digit & 0x0f);     
  }

	while(EX0 != 1);
	return;

}

main () {   
	EX0 = 1; 
	IT0 = 1; 
	EA = 1;
	while (1); 
}
