#include <p18f4520.h>

#define pan   LATCbits.LATC0
#define tilt  LATCbits.LATC7 
#define pan_sobe PORTCbits.RC1
#define pan_desce PORTCbits.RC2
#define tilt_sobe PORTCbits.RC3
#define tilt_desce PORTCbits.RC4

int angulopan = 20;
int angulotilt = 20; 

void delay_grau(void) {
    unsigned char i;
    for (i=0;i<2;i++) {}
    i=0;
    i=0;
    i=0;
    i=0;
    i=0;
    i=0;
}

void delay_ms(int ms)
{
	unsigned int i;
	for (;ms>0;ms--)
	{
	for (i=0;i<529;i++) {}		//tempo de loop = 1ms
	}
}

void s_pan (int angulopan) {
    unsigned char ajuste = angulopan/11;
    pan = 1;
    delay_ms(1);
    
    
    for (;angulopan>0;angulopan--){
    delay_grau();
    }
    for(;ajuste>0;ajuste--){}
    pan = 0;
}

void s_tilt (int angulotilt) {
    unsigned char ajuste = angulotilt/11;
    tilt = 1;
    delay_ms(1);
    for (;angulotilt>0;angulotilt--){
    delay_grau();
    }
    for(;ajuste>0;ajuste--){}
    tilt = 0;
}

void checar_pan (void){
    if (pan_sobe == 1){
    angulopan++;
    }
    if (pan_desce == 1){
    angulopan--;
    }
    while (pan_sobe==1 || pan_desce==1){}
}

void checar_tilt (void){
    if (tilt_sobe == 1){
    angulotilt++;
    }
    if (tilt_desce == 1){
    angulotilt--;
    }
    while (tilt_sobe==1 || tilt_desce==1){}
}
void main (void) {
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 1;
    TRISCbits.TRISC2 = 1;
    TRISCbits.TRISC3 = 1; 
    TRISCbits.TRISC4 = 1; 
    TRISCbits.TRISC7 = 0;
    
    while(1) {
        s_pan(angulopan);
        s_tilt(angulotilt);
        delay_ms(20);
        checar_tilt();
        checar_pan();
    }
}