#include "main.h"
#include "Utility.h"
#include "LCD_Blio.h"
#include <stdio.h>

#ifndef PRATICA01_H
#define PRATICA01_H

void questao01(void){
	Utility_Init();
	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);

	while(1){
		GPIO_Write_Pin(GPIOA, PIN_6, LOW);
		Delay_ms(100);
		GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
		Delay_ms(100);
	}
}

void questao02(void){
	Utility_Init();

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);

	while(1){
		GPIO_Write_Pin(GPIOA, PIN_6, LOW);
		Delay_ms(100);
		GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
		Delay_ms(1900);
	}
}

void questao03(void){
	Utility_Init();

	GPIO_Clock_Enable(GPIOD);
	GPIO_Pin_Mode(GPIOD, PIN_0, OUTPUT);

	while(1){
		GPIO_Write_Pin(GPIOD, PIN_0, HIGH);
		Delay_ms(100);
		GPIO_Write_Pin(GPIOD, PIN_0, LOW);
		Delay_ms(400);
		GPIO_Write_Pin(GPIOD, PIN_0, HIGH);
		Delay_ms(100);
		GPIO_Write_Pin(GPIOD, PIN_0, LOW);
		Delay_ms(100);
		GPIO_Write_Pin(GPIOD, PIN_0, HIGH);
		Delay_ms(100);
		GPIO_Write_Pin(GPIOD, PIN_0, LOW);
		Delay_ms(400);
	}
}

void questao04(void){
	Utility_Init();

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_7, OUTPUT);

	uint16_t tempoLigado = 0;
	uint16_t subida = 0;

	while(1){
		if (tempoLigado == 10000)
			subida = 0;
		else if(tempoLigado == 0)
			subida = 1;
		GPIO_Write_Pin(GPIOA, PIN_6, LOW);
		GPIO_Write_Pin(GPIOA, PIN_7, HIGH);
		Delay_us(tempoLigado);
		GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
		GPIO_Write_Pin(GPIOA, PIN_7, LOW);
		Delay_us(10000 - tempoLigado);
		if (subida)
			tempoLigado += 50;
		else
			tempoLigado -= 50;
	}
}

void questao05(void)
{
	Utility_Init();

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_0, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_2, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_3, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_4, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_5, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_7, OUTPUT);
	//GPIOA->ODR = (GPIOA->ODR & 0xFFFFFF00) | cont;
	while(1){
		for (uint8_t i = 0; i  < 256; i++){
			GPIO_Write_Port(GPIOA, i);
			Delay_ms(150);
		}
	}
}

void questao06(void){
	Utility_Init();

	GPIO_Clock_Enable(GPIOD);
	for(int pinD = 0; pinD < 8; pinD++){
		GPIO_Pin_Mode(GPIOD, pinD, OUTPUT); // Ativa os pinos D0 ao D7
	}

	uint8_t contador = 0;
	uint8_t inverso = 0;

	while(1){
		GPIO_Write_Port(GPIOD, LOW); // Manda todos os leds para nível baixo

		GPIO_Write_Pin(GPIOD, contador, HIGH);
		if (inverso == 0)
			contador++;
		else
			contador--;
		if (contador == 7 || contador == 0)
			inverso = !inverso;

		Delay_ms(200);
	}
}

void questao07(void){
	Utility_Init();

	GPIO_Clock_Enable(GPIOD);

	for(int pinD = 0; pinD < 6; pinD++){
		GPIO_Pin_Mode(GPIOD, pinD, OUTPUT);
	}

	while(1){
		GPIO_Write_Pin(GPIOA, PIN_0, HIGH);
		GPIO_Write_Pin(GPIOA, PIN_1, LOW);
		GPIO_Write_Pin(GPIOA, PIN_2, LOW);
		GPIO_Write_Pin(GPIOA, PIN_3, LOW);
		GPIO_Write_Pin(GPIOA, PIN_4, LOW);
		GPIO_Write_Pin(GPIOA, PIN_5, HIGH);
		Delay_ms(3000);

		GPIO_Write_Pin(GPIOA, PIN_0, LOW);
		GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
		GPIO_Write_Pin(GPIOA, PIN_2, LOW);
		GPIO_Write_Pin(GPIOA, PIN_3, LOW);
		GPIO_Write_Pin(GPIOA, PIN_4, LOW);
		GPIO_Write_Pin(GPIOA, PIN_5, HIGH);
		Delay_ms(1000);

		GPIO_Write_Pin(GPIOA, PIN_0, LOW);
		GPIO_Write_Pin(GPIOA, PIN_1, LOW);
		GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
		GPIO_Write_Pin(GPIOA, PIN_3, HIGH);
		GPIO_Write_Pin(GPIOA, PIN_4, LOW);
		GPIO_Write_Pin(GPIOA, PIN_5, LOW);
		Delay_ms(3000);

		GPIO_Write_Pin(GPIOA, PIN_0, LOW);
		GPIO_Write_Pin(GPIOA, PIN_1, LOW);
		GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
		GPIO_Write_Pin(GPIOA, PIN_3, LOW);
		GPIO_Write_Pin(GPIOA, PIN_4, HIGH);
		GPIO_Write_Pin(GPIOA, PIN_5, LOW);
		Delay_ms(1000);
	}
}

void questao08(void){
	Utility_Init();
	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_0, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_2, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_3, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_4, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_5, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_7, OUTPUT);

	// Decodificação de display de 7 segmentos com uso de máscaras em matriz
	const uint8_t mask[16]={
		0b00111111, //0
		0b00000110, //1
		0b01011011, //2
		0b01001111, //3
		0b01100110, //4
		0b01101101, //5
		0b01111101, //6
		0b00000111, //7
		0b01111111, //8
		0b01101111, //9
		0b01110111, //A
		0b01111100, //B
		0b00111001, //C
		0b01011110, //D
		0b01111001, //E
		0b01110001}; //F

	while(1){

		for(uint8_t i = 0; i < 16; i++){
			GPIO_Write_Port(GPIOA, mask[i]);
			Delay_ms(500);
		}
		for(int8_t i = 15; i >= 0; i--){
			GPIO_Write_Port(GPIOA, mask[i]);
			Delay_ms(500);
		}
	}
}

void questao09(void){
	Utility_Init();
	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_0, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_2, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_3, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_4, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_5, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_7, OUTPUT);

	GPIO_Clock_Enable(GPIOD);
	GPIO_Pin_Mode(GPIOD, PIN_0, OUTPUT);
	GPIO_Pin_Mode(GPIOD, PIN_1, OUTPUT);

	// Decodificação de display de 7 segmentos com uso de máscaras em matriz
	const uint8_t mask[16]={
		0b00111111, //0
		0b00000110, //1
		0b01011011, //2
		0b01001111, //3
		0b01100110, //4
		0b01101101, //5
		0b01111101, //6
		0b00000111, //7
		0b01111111, //8
		0b01101111, //9
		0b01110111, //A
		0b01111100, //B
		0b00111001, //C
		0b01011110, //D
		0b01111001, //E
		0b01110001}; //F

	while(1){
		for(uint8_t i = 0; i < 16; i++){
			for (uint8_t j = 0; j < 16; j++){
				int32_t cont = 250000;
				while(cont > 0){
					GPIO_Write_Pin(GPIOD, PIN_1, HIGH);
					GPIO_Write_Pin(GPIOD, PIN_0, LOW);
					GPIO_Write_Port(GPIOA, mask[i]);
					Delay_us(1);
					cont--;
					GPIO_Write_Pin(GPIOD, PIN_1, LOW);
					GPIO_Write_Pin(GPIOD, PIN_0, HIGH);
					GPIO_Write_Port(GPIOA, mask[j]);
					Delay_us(1);
					cont--;
				}
			}
		}
		for(int8_t i = 15; i >= 0; i--){
			for (int8_t j = 15; j >= 0; j--){
				int32_t cont = 250000;
				while(cont > 0){
					GPIO_Write_Pin(GPIOD, PIN_1, HIGH);
					GPIO_Write_Pin(GPIOD, PIN_0, LOW);
					GPIO_Write_Port(GPIOA, mask[i]);
					Delay_us(1);
					cont--;
					GPIO_Write_Pin(GPIOD, PIN_1, LOW);
					GPIO_Write_Pin(GPIOD, PIN_0, HIGH);
					GPIO_Write_Port(GPIOA, mask[j]);
					Delay_us(1);
					cont--;
				}
			}
		}
	}
}

void questao10(void){
	Utility_Init();
	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_4, OUTPUT);

	GPIO_Clock_Enable(GPIOD);
	GPIO_Pin_Mode(GPIOD, PIN_0, OUTPUT);
	GPIO_Pin_Mode(GPIOD, PIN_1, OUTPUT);
	GPIO_Pin_Mode(GPIOD, PIN_2, OUTPUT);
	GPIO_Pin_Mode(GPIOD, PIN_3, OUTPUT);
	GPIO_Pin_Mode(GPIOD, PIN_4, OUTPUT);
	GPIO_Pin_Mode(GPIOD, PIN_5, OUTPUT);

	LCD_Init(4, 20);

	LCD_Clear();
	LCD_Display_ON();

	char nome1[] = "The";
	char nome2[] = "Life";
	char nome3[] = "Snake";

	while(1){
		for(int i = 10; i >= 0; --i){
			LCD_Clear();
			LCD_Write_String(1, 1, nome1);
			LCD_Write_String(2, 1, nome2);
			LCD_Write_String(3, 1, nome3);
			Delay_ms(500);
			char buffer[3];
			sprintf(buffer, "%d", i);
			LCD_Write_String(4, 1, buffer);
			Delay_ms(1000);
		}
	}

}

void questao11(void){
	Utility_Init(); // Inicializa o sistema de clock do STM32. È preciso garantir seu funcionamento correto para garantir a temporização correta do delay.

	//Configura PA4 como saída.
	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_0, OUTPUT); // Sentido horário
	GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT); // Sentido anti-horário

	GPIO_Pin_Mode(GPIOA, PIN_4, OUTPUT); // PWM

	int tempo_ligado = 0;
	int valor = 200;
	int sentido = 0;

	GPIO_Write_Pin(GPIOA, PIN_0, HIGH);
	GPIO_Write_Pin(GPIOA, PIN_1, LOW);

	while(1){
		GPIO_Write_Pin(GPIOA, PIN_4, HIGH);
		Delay_us(tempo_ligado);
		GPIO_Write_Pin(GPIOA, PIN_4, LOW);
		Delay_us(20000-tempo_ligado);
		tempo_ligado = tempo_ligado + valor;

		if(tempo_ligado >= 20000){
			valor = -200;
			tempo_ligado = 20000;
		}
		if(tempo_ligado <= 0){
			valor = 200;
			tempo_ligado = 0;

			if(sentido == 0){
				GPIO_Write_Pin(GPIOA, PIN_0, LOW);
				GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
				sentido = 1;
			} else {
				GPIO_Write_Pin(GPIOA, PIN_0, HIGH);
				GPIO_Write_Pin(GPIOA, PIN_1, LOW);
				sentido = 0;
			}
		}
	}
}

void questao12(void){
	Utility_Init();
	 GPIO_Clock_Enable(GPIOA);

	 GPIO_Pin_Mode(GPIOA, PIN_0, OUTPUT); //INB1
	 GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT); //INB2
	 GPIO_Pin_Mode(GPIOA, PIN_2, OUTPUT); //INA1
	 GPIO_Pin_Mode(GPIOA, PIN_3, OUTPUT); //INA2

	 void gira_motor(int delay, int sentido, int rotacoes){ // sentido = 1 -> Horário, sentido = 0 -> Anti-horário

	  for(int a=0;a<(50*rotacoes);a++){
	   if(sentido == 1){
	    for(int i = 0;i<4;i++){
	     GPIO_Write_Port(GPIOA, (1 << i));
	     Delay_ms(delay);
	    }
	   }
	   else if(sentido == 0){

	    for(int i=0;i<4;i++){
	     GPIO_Write_Port(GPIOA, (8 >> i));
	     Delay_ms(delay);
	    }
	   }
	  }
	 }

	 while(1){
	  gira_motor(10, 1, 2);
	  gira_motor(10, 0, 1);
	 }
}

void questao13(void)
{
	Utility_Init();

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_7, OUTPUT);

	GPIO_Clock_Enable(GPIOE);
	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);
	GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);
	GPIO_Pin_Mode(GPIOE, PIN_4, INPUT);
	GPIO_Resistor_Enable(GPIOE, PIN_4, PULL_UP);

	while(1){
		if (!GPIO_Read_Pin(GPIOE, PIN_4)) {
		  GPIO_Write_Pin(GPIOA, PIN_6, LOW);
		}
		else {
		  GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
		}
		if (!GPIO_Read_Pin(GPIOE, PIN_3)) {
		  GPIO_Write_Pin(GPIOA, PIN_7, LOW);
		}
		else {
		  GPIO_Write_Pin(GPIOA, PIN_7, HIGH);
		}
	}
}

void questao14(void)
{
	Utility_Init();

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);

	GPIO_Clock_Enable(GPIOE);
	GPIO_Pin_Mode(GPIOE, PIN_4, INPUT);
	GPIO_Resistor_Enable(GPIOE, PIN_4, PULL_UP);

	while(1){
		if (!GPIO_Read_Pin(GPIOE, PIN_4)){
			Delay_ms(250);
			GPIO_Toggle_Pin(GPIOA, PIN_6);
		}
	}
}

void questao15(void){
	Utility_Init();

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);

	GPIO_Clock_Enable(GPIOE);
	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT); // Ativando Botão K1
	GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);
	GPIO_Pin_Mode(GPIOE, PIN_4, INPUT); // Ativando Botão K0
	GPIO_Resistor_Enable(GPIOE, PIN_4, PULL_UP);

	while(1){
		while(!GPIO_Read_Pin(GPIOE, PIN_4)){
			while(!GPIO_Read_Pin(GPIOE, PIN_3) && !GPIO_Read_Pin(GPIOE, PIN_4)){
				GPIO_Write_Pin(GPIOA, PIN_6, LOW);
			}
			GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
		}
		while(!GPIO_Read_Pin(GPIOE, PIN_3));
		GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
	}
}

void questao16(void)
{
	Utility_Init();

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);

	GPIO_Clock_Enable(GPIOE);
	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);
	GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);
	GPIO_Pin_Mode(GPIOE, PIN_4, INPUT);
	GPIO_Resistor_Enable(GPIOE, PIN_4, PULL_UP);

	while(1){
		uint32_t cont = 0;

		while(!GPIO_Read_Pin(GPIOE, PIN_4)){
			if (cont <= 1000){
				cont++;
				Delay_ms(1);
			}
			while(!GPIO_Read_Pin(GPIOE, PIN_3) && cont <= 1000 && !GPIO_Read_Pin(GPIOE, PIN_4)){
				GPIO_Write_Pin(GPIOA, PIN_6, LOW);
			}
			GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
		}
		while(!GPIO_Read_Pin(GPIOE, PIN_3));
		GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
	}
}

void questao17(void){
	Utility_Init();
	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_3, OUTPUT); // PWM

	GPIO_Clock_Enable(GPIOE);
	GPIO_Pin_Mode(GPIOE, PIN_4, INPUT); // botão 01 - K0
	GPIO_Resistor_Enable(GPIOE, PIN_4, PULL_UP);
	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT); // botão 02 - K1
	GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);

	uint32_t pulsoMin = 500;
	uint32_t pulsoMax = 2500;
	uint32_t pulso = 500;

	while(1){
		Delay_ms(20);
		if(!GPIO_Read_Pin(GPIOE, PIN_4)){
			GPIO_Write_Pin(GPIOA, PIN_3, HIGH);
			Delay_us(pulso);
			GPIO_Write_Pin(GPIOA, PIN_3, LOW);
			if (pulso < pulsoMax)
				//pulso++;
				pulso = pulso + 10;
		}
		else if(!GPIO_Read_Pin(GPIOE, PIN_3)){
			GPIO_Write_Pin(GPIOA, PIN_3, HIGH);
			Delay_us(pulso);
			GPIO_Write_Pin(GPIOA, PIN_3, LOW);
			if (pulso > pulsoMin)
				//pulso--;
				pulso = pulso - 10;
		}
		else {
			GPIO_Write_Pin(GPIOA, PIN_3, HIGH);
			Delay_us(pulso);
			GPIO_Write_Pin(GPIOA, PIN_3, LOW);
		}
		//Delay_ms(10);
	}
}

void questao18(void){
	Utility_Init();
	GPIO_Clock_Enable(GPIOA);
	for (int8_t pinA = 0; pinA < 8; pinA++){
		GPIO_Pin_Mode(GPIOA, pinA, OUTPUT);
	}

	GPIO_Clock_Enable(GPIOD);
	for(int8_t pinD = 0; pinD < 8; pinD++){
		if (pinD < 4){
			GPIO_Pin_Mode(GPIOD, pinD, OUTPUT);
			GPIO_Output_Type(GPIOD, pinD, OPEN_DRAIN);
			GPIO_Resistor_Enable(GPIOD, pinD, PULL_UP);
		}
		else {
			GPIO_Pin_Mode(GPIOD, pinD, INPUT);
			GPIO_Resistor_Enable(GPIOD, pinD, PULL_UP);
		}
	}
	// Decodificação de display de 7 segmentos com uso de máscaras em matriz
	const uint8_t teclado_matricial[4][4]={
			{
					0b00000110, //1
					0b01011011, //2
					0b01001111, //3
					0b01110111 //A
			},
			{
					0b01100110, //4
					0b01101101, //5
					0b01111101, //6
					0b01111100 //B
			},
			{
					0b00000111, //7
					0b01111111, //8
					0b01101111, //9
					0b00111001 //C
			},
			{
					0b01110001, // * = F
					0b00111111, //0
					0b01111001, // # = E
					0b01011110 //D
			}
	};

	while(1){
		//Delay_ms(300);
		for(int8_t linha = 0; linha < 4; linha++){
			GPIO_Write_Pin(GPIOD, linha, LOW);
			for(int8_t coluna = 4; coluna < 8; coluna++){
				while(!GPIO_Read_Pin(GPIOD, coluna)){
					GPIO_Write_Port(GPIOA, teclado_matricial[linha][coluna - 4]);
					Delay_us(700);
				}
			}
			Delay_ms(200);
			GPIO_Write_Pin(GPIOD, linha, HIGH);
			GPIO_Write_Port(GPIOA, LOW);
		}
	}
}

void questao19(void){
	Utility_Init();
	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_0, OUTPUT); // buzzer
	GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT); // trig
	GPIO_Pin_Mode(GPIOA, PIN_2, INPUT); // echo

	while(1)
	{
		Delay_ms(10);
		GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
		Delay_us(10);
		GPIO_Write_Pin(GPIOA, PIN_1, LOW);

		uint32_t cont = 30000;

		while(!GPIO_Read_Pin(GPIOA, PIN_2) && cont > 0)
		{
			Delay_us(1);
			cont--;
		}

		uint32_t tempo = 0;
		if (cont > 0){
			while(GPIO_Read_Pin(GPIOA, PIN_2)){
				Delay_us(1);
				tempo++;
			}

			uint32_t distancia = tempo/58;

			if (distancia >= 50){
				GPIO_Write_Pin(GPIOA, PIN_0, LOW);
			}
			else if(distancia < 50 && distancia >= 30){
				GPIO_Write_Pin(GPIOA, PIN_0, HIGH);
				Delay_ms(300);
				GPIO_Write_Pin(GPIOA, PIN_0, LOW);
				Delay_ms(1000);
			}
			else if (distancia < 30 && distancia >= 10){
				GPIO_Write_Pin(GPIOA, PIN_0, HIGH);
				Delay_ms(300);
				GPIO_Write_Pin(GPIOA, PIN_0, LOW);
				Delay_ms(500);
			}
			else if (distancia < 10){
				GPIO_Write_Pin(GPIOA, PIN_0, HIGH);
			}
		}
	}
}

void questao20(void){
	Utility_Init();
	GPIO_Clock_Enable(GPIOA); // Leds
	for(uint8_t pinA = 0; pinA < 4; pinA++){
		GPIO_Pin_Mode(GPIOA, pinA, OUTPUT);
	}
	GPIO_Clock_Enable(GPIOD); // Botões
	for(uint8_t pinD = 0; pinD < 3; pinD++){
		GPIO_Pin_Mode(GPIOD, pinD, INPUT);
	}
	GPIO_Clock_Enable(GPIOE);
	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT);
	GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);

	uint32_t sequencia[32];
	uint16_t faseAtual = 0;

	while(1){
		sequencia[faseAtual] = Random_Number() % 4;
		faseAtual++;
		Delay_ms(300);
		for(uint16_t i = 0; i < faseAtual; i++){
			switch(sequencia[i]){
			case 0:
				GPIO_Write_Pin(GPIOA, PIN_0, HIGH);
				break;
			case 1:
				GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
				break;
			case 2:
				GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
				break;
			case 3:
				GPIO_Write_Pin(GPIOA, PIN_3, HIGH);
				break;
			}

			Delay_ms(1000);
			GPIO_Write_Port(GPIOA, LOW); // Manda todos os leds para nivel baixo
			Delay_ms(300);
		}

		GPIO_Write_Port(GPIOA, LOW);

		int8_t roundCompleto = 0;
		uint32_t posicaoSequencia = 0;

		while(roundCompleto == 0){
			GPIO_Write_Port(GPIOA, LOW);
			while(1){
				if (GPIO_Read_Pin(GPIOD, PIN_0)){
					GPIO_Write_Pin(GPIOA, PIN_0, HIGH);
					if (sequencia[posicaoSequencia] == 0){
						posicaoSequencia++;
						if(posicaoSequencia == faseAtual)
							roundCompleto = 1;
						Delay_ms(250);
						break;
					}
					else {
						roundCompleto = -1;
						break;
					}
				}
				else if(GPIO_Read_Pin(GPIOD, PIN_1)){
					GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
					if (sequencia[posicaoSequencia] == 1){
						posicaoSequencia++;
						if(posicaoSequencia == faseAtual)
							roundCompleto = 1;
						Delay_ms(250);
						break;
					}
					else {
						roundCompleto = -1;
						break;
					}

				}
				else if(GPIO_Read_Pin(GPIOD, PIN_2)){
					GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
					if (sequencia[posicaoSequencia] == 2){
						posicaoSequencia++;
						if(posicaoSequencia == faseAtual)
							roundCompleto = 1;
						Delay_ms(250);
						break;
					}
					else {
						roundCompleto = -1;
						break;
					}
				}
				else if(!GPIO_Read_Pin(GPIOE, PIN_3)){
					GPIO_Write_Pin(GPIOA, PIN_3, HIGH);
					if (sequencia[posicaoSequencia] == 3){
						posicaoSequencia++;
						if(posicaoSequencia == faseAtual)
							roundCompleto = 1;
						Delay_ms(250);
						break;
					}
					else {
						roundCompleto = -1;
						break;
					}
				}
			}
		}
		Delay_ms(300);
		GPIO_Write_Port(GPIOA, LOW);
		if (roundCompleto == -1){
			for(int8_t i = 0; i < 4; i++){
				GPIO_Write_Pin(GPIOA, i, HIGH);
				Delay_ms(200);
			}
			faseAtual = 0;
		}
		Delay_ms(1000);
	}
}

#endif
