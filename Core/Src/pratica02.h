#ifndef PRATICA_02_H
#define PRATICA_02_H

#include "Utility.h"
#include <stdio.h>
#include <math.h>
#include "audio.h"

// INTERRUPÇÕES

// Interrupção questão 9 e 10
void EXTI0_IRQHandler(){
	printf("\nINTERRUPÇÃO EXTERNA EM PB0\n");
	EXTI_Clear_Pending(EXTI0);
}

// Interrupção questão 9 e 10
void EXTI1_IRQHandler(){
	printf("INTERRUPÇÃO EXTERNA EM PB1\n");
	EXTI_Clear_Pending(EXTI1);
}

// Interrupção questão 10
void EXTI4_IRQHandler(){
	TIM3->CNT = 0;
	TIM3->SR &= ~TIM_SR_UIF;
	TIM3->CR1 |= TIM_CR1_CEN; // Habilita a contagem
	GPIO_Write_Pin(GPIOA, PIN_6, LOW);
	printf("\nINTERRRUPÇÃO EXTERNA EM K0\n");
	EXTI_Clear_Pending(EXTI3);
}

// Interrupção questão 10
void EXTI3_IRQHandler(){
	if(!(TIM4->CR1 & TIM_CR1_CEN))
	{
		TIM4->SR &= ~TIM_SR_UIF;
		TIM4->CNT = 0;
		TIM4->SR &= ~TIM_SR_UIF; // Garante flag limpa
		TIM4->CR1 |= TIM_CR1_CEN; // hABILITA CONTAGEM
		GPIO_Write_Pin(GPIOA, PIN_7, LOW);
		printf("\nINTERRRUPÇÃO EXTERNA EM K1\n");
		EXTI_Clear_Pending(EXTI4);
	}
}

void questao01(){
	Utility_Init();
	USART1_Init();

	DAC_Init(DAC_CHANNEL1);

	while(1){


		for (uint16_t valor = 0; valor <= 4095; ++valor){
			DAC_SetValue(DAC_CHANNEL1, valor, DAC_RES_12BITS);
			Delay_us(500);
		}

		for (uint16_t valor2 = 4095; valor2 > 0; --valor2){
			DAC_SetValue(DAC_CHANNEL1, valor2, DAC_RES_12BITS);
			Delay_us(500);
		}

	}
	return 0;
}

// Amostra de senoide para questão 02
void questao02(){
	Utility_Init();
	DAC_Init(DAC_CHANNEL2);
	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_5, ANALOG);
	// Amostra de sinal de onda de uma senoide
	uint16_t samples[500] = {
	    1985, 2000, 2016, 2031, 2047, 2062, 2078, 2093, 2109, 2124,
	    2140, 2155, 2171, 2186, 2202, 2217, 2232, 2247, 2263, 2278,
	    2293, 2308, 2323, 2338, 2353, 2368, 2382, 2397, 2412, 2426,
	    2441, 2455, 2470, 2484, 2498, 2512, 2527, 2540, 2554, 2568,
	    2582, 2595, 2609, 2622, 2636, 2649, 2662, 2675, 2688, 2701,
	    2713, 2726, 2738, 2751, 2763, 2775, 2787, 2799, 2810, 2822,
	    2833, 2845, 2856, 2867, 2878, 2888, 2899, 2909, 2920, 2930,
	    2940, 2950, 2959, 2969, 2978, 2988, 2997, 3006, 3014, 3023,
	    3031, 3040, 3048, 3056, 3064, 3071, 3079, 3086, 3093, 3100,
	    3106, 3113, 3119, 3126, 3132, 3137, 3143, 3149, 3154, 3159,
	    3164, 3169, 3173, 3177, 3182, 3186, 3189, 3193, 3196, 3200,
	    3203, 3205, 3208, 3210, 3213, 3215, 3217, 3218, 3220, 3221,
	    3222, 3223, 3224, 3224, 3224, 3225, 3224, 3224, 3224, 3223,
	    3222, 3221, 3220, 3218, 3217, 3215, 3213, 3210, 3208, 3205,
	    3203, 3200, 3196, 3193, 3189, 3186, 3182, 3177, 3173, 3169,
	    3164, 3159, 3154, 3149, 3143, 3137, 3132, 3126, 3119, 3113,
	    3106, 3100, 3093, 3086, 3079, 3071, 3064, 3056, 3048, 3040,
	    3031, 3023, 3014, 3006, 2997, 2988, 2978, 2969, 2959, 2950,
	    2940, 2930, 2920, 2909, 2899, 2888, 2878, 2867, 2856, 2845,
	    2833, 2822, 2810, 2799, 2787, 2775, 2763, 2751, 2738, 2726,
	    2713, 2701, 2688, 2675, 2662, 2649, 2636, 2622, 2609, 2595,
	    2582, 2568, 2554, 2540, 2527, 2512, 2498, 2484, 2470, 2455,
	    2441, 2426, 2412, 2397, 2382, 2368, 2353, 2338, 2323, 2308,
	    2293, 2278, 2263, 2247, 2232, 2217, 2202, 2186, 2171, 2155,
	    2140, 2124, 2109, 2093, 2078, 2062, 2047, 2031, 2016, 2000,
	    1985, 1969, 1953, 1938, 1922, 1907, 1891, 1876, 1860, 1845,
	    1829, 1814, 1798, 1783, 1767, 1752, 1737, 1722, 1706, 1691,
	    1676, 1661, 1646, 1631, 1616, 1601, 1587, 1572, 1557, 1543,
	    1528, 1514, 1499, 1485, 1471, 1457, 1442, 1429, 1415, 1401,
	    1387, 1374, 1360, 1347, 1333, 1320, 1307, 1294, 1281, 1268,
	    1256, 1243, 1231, 1218, 1206, 1194, 1182, 1170, 1159, 1147,
	    1136, 1124, 1113, 1102, 1091, 1081, 1070, 1060, 1049, 1039,
	    1029, 1019, 1010, 1000, 991, 981, 972, 963, 955, 946,
	    938, 929, 921, 913, 905, 898, 890, 883, 876, 869,
	    863, 856, 850, 843, 837, 832, 826, 820, 815, 810,
	    805, 800, 796, 792, 787, 783, 780, 776, 773, 769,
	    766, 764, 761, 759, 756, 754, 752, 751, 749, 748,
	    747, 746, 745, 745, 745, 745, 745, 745, 745, 746,
	    747, 748, 749, 751, 752, 754, 756, 759, 761, 764,
	    766, 769, 773, 776, 780, 783, 787, 792, 796, 800,
	    805, 810, 815, 820, 826, 832, 837, 843, 850, 856,
	    863, 869, 876, 883, 890, 898, 905, 913, 921, 929,
	    938, 946, 955, 963, 972, 981, 991, 1000, 1010, 1019,
	    1029, 1039, 1049, 1060, 1070, 1081, 1091, 1102, 1113, 1124,
	    1136, 1147, 1159, 1170, 1182, 1194, 1206, 1218, 1231, 1243,
	    1256, 1268, 1281, 1294, 1307, 1320, 1333, 1347, 1360, 1374,
	    1387, 1401, 1415, 1429, 1442, 1457, 1471, 1485, 1499, 1514,
	    1528, 1543, 1557, 1572, 1587, 1601, 1616, 1631, 1646, 1661,
	    1676, 1691, 1706, 1722, 1737, 1752, 1767, 1783, 1798, 1814,
	    1829, 1845, 1860, 1876, 1891, 1907, 1922, 1938, 1953, 1969,
	};
	while(1){

		for (uint16_t i = 0; i < 500; ++i){
			DAC_SetValue(DAC_CHANNEL2, samples[i], DAC_RES_12BITS);
			Delay_us(20);
		}
	}
	return 0;
}

void questao03(){

//	void ADC_IRQHandler(){
//
//		// Printa a saída padrão
//		printf("Saida da Regiao Monitorada\n");
//		// Limpando a flag da indicação de interrupção
//		ADC1->SR &= ~ADC_SR_AWD;
//
//	}
	Utility_Init();
	USART1_Init();

	// Iniciando ADC1 com canal simples
	ADC_Init(ADC1, SINGLE_CHANNEL, ADC_RES_12BITS);
	// Definindo o canal IN0
	ADC_SingleChannel(ADC1, ADC_IN0);

	// Definindo limiares superior e inferior
	ADC1->LTR = 993;
	ADC1->HTR = 2109;

	// Habilita o WD em canal simples, seleciona o canal montiorado
	ADC1->CR1 |= ADC_CR1_AWDSGL;
	ADC1->CR1 &= ~ADC_CR1_AWDCH;

	// Habilita o WD e coloca uma interrupção toda vez q o bit sinalizador for setado
	ADC1->CR1 |= ADC_CR1_AWDEN;
	ADC1->CR1 |= ADC_CR1_AWDIE;

	// Habilita a interrupção no controlador NVIC
	NVIC_EnableIRQ(ADC_IRQn);

	while(1){
		uint16_t leitura = ADC_GetSingleConversion(ADC1);
		float voltage = 3.3 * (float) leitura/4095;
		printf("Voltage = %.2f\n\n", voltage); // imprime o valor
		Delay_ms(500);
	}
	return 0;
}

// Timer questão 04
void TIM2_IRQHandler(){
	if (TIM2->SR & TIM_SR_UIF) {
		TIM2->SR &= ~TIM_SR_UIF; // limpa flag
		static int audio_index = 0;
		if(audio_index < audio_data_len){
			DAC_SetValue(DAC_CHANNEL1, audio_data[audio_index++], DAC_RES_8BITS);
		}
		else {
			audio_index = 0;
		}
	}
}

void questao04(){
	Utility_Init();
	DAC_Init(DAC_CHANNEL1);

	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC = 83;            // prescaler = 1
	TIM2->ARR = 20;         // para 48kHz (84MHz/1750 ≈ 48kHz)
	TIM2->DIER |= TIM_DIER_UIE; // habilita interrupção update
	TIM2->CR1 |= TIM_CR1_CEN;   // inicia timer

	NVIC_EnableIRQ(TIM2_IRQn);

	while(1){

	}
}

void questao05(){
	Utility_Init();
	USART1_Init();

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_2, ALTERNATE);
	GPIO_Alternate_Function(GPIOA, PIN_2, AF2);

	GPIO_Pin_Mode(GPIOA, PIN_0, ALTERNATE);
	GPIO_Alternate_Function(GPIOA, PIN_0, AF2);

	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN; // Liga o clock do timer 5
	TIM5->PSC = 83;
	TIM5->ARR = 19999;
	TIM5->CCMR2 |= 0b110 << 4;			// Seleciona o PWM no modo 1 (compare)
	TIM5->CCMR1 |= 0b110 << 4;

	TIM5->CCMR2 |= TIM_CCMR2_OC3PE;		// Evita glitchs
	TIM5->CCMR1 |= TIM_CCMR1_OC1PE;		// Evita glitchs

	TIM5->CCER |= TIM_CCER_CC3E;		// Habilita saída do canal 3
	TIM5->CCER |= TIM_CCER_CC1E;		// Habilita saída do canal 1

	TIM5->EGR |= TIM_EGR_UG;
	TIM5->CR1 &= ~TIM_CR1_DIR;
	TIM5->CR1 |= TIM_CR1_CEN;

	// -----------------------------------------------------------------------
	GPIO_Pin_Mode(GPIOA, PIN_3, ANALOG);
	GPIO_Pin_Mode(GPIOA, PIN_4, ANALOG);

	ADC_Init(ADC1, MULTI_CHANNEL, ADC_RES_12BITS);
	uint8_t canais[2] = {ADC_IN3, ADC_IN4};
	ADC_MultiChannel(ADC1, 2, canais);

	while(1){
		uint16_t leituras[2];
		ADC_GetMultiConversions(ADC1, 2, leituras);

		uint16_t leiturax = leituras[0];
		uint16_t leituray = leituras[1];

		TIM5->CCR3 = (leiturax * 2000) / 4095 + 500;
		TIM5->CCR1 = (leituray * 2000) / 4095 + 500;
	}
}

// Timers questão 06
void TIM4_IRQHandler(){
	if (TIM4->SR & TIM_SR_UIF) {
		TIM4->SR &= ~TIM_SR_UIF;

		static int pwm_ativo = 0;

		if (pwm_ativo) {
			TIM5->CCER &= ~TIM_CCER_CC3E;  // Desliga canal de PWM
		} else {
			TIM5->CCER |= TIM_CCER_CC3E;   // Liga canal de PWM
		}
		pwm_ativo = !pwm_ativo;
	}
}
// Timer questão 06
void ADC_IRQHandler(){
	if (ADC1->SR & ADC_SR_EOC){

		static unsigned int cont = 0;
		static float value = 0;

		uint16_t TS_CAL1 = *((uint16_t*) 0x1FFF7A2C);
		uint16_t TS_CAL2 = *((uint16_t*) 0x1FFF7A2E);

		value += 80.0f * ((float)ADC1->DR - TS_CAL1) / (TS_CAL2 - TS_CAL1) + 30;
		cont++;
		// Coleta 50 amostras
		if (cont == 50) {
		    printf("Temperatura: %.2f\n\n", value/50.0f);

		    if (value/50.0f <= 50){
		    	printf("Dentro da Faixa de Operacao!\n");
		    	GPIO_Write_Pin(GPIOA, PIN_6, HIGH);  // Desliga LED de atenção
				GPIO_Write_Pin(GPIOA, PIN_7, HIGH);  // Desliga LED de superaquecimento

				TIM4->CR1 &= ~TIM_CR1_CEN;        // Para alternância
				TIM5->CCER &= ~TIM_CCER_CC3E;     // Garante buzzer desligado

		    } else if (value/50.0f > 50 && value/50.0f <= 60){
		    	printf("Dentro da Faixa de Atencao\n");
		        GPIO_Write_Pin(GPIOA, PIN_6, LOW);   // Liga LED de atenção
		        GPIO_Write_Pin(GPIOA, PIN_7, HIGH);  // Desliga superaquecimento

		        TIM4->CR1 &= ~TIM_CR1_CEN;        // Para alternância
		        TIM5->CCER &= ~TIM_CCER_CC3E;     // Garante buzzer desligado

		    } else{
		    	printf("Dentro da Faixa de Superaquecimento\n");
		        GPIO_Write_Pin(GPIOA, PIN_6, LOW);  // Desliga LED de atenção
		        GPIO_Write_Pin(GPIOA, PIN_7, LOW);   // Liga superaquecimento
		    	TIM5->CCER |= TIM_CCER_CC3E; // Alternativamente eu poderia usar TIM5->CCER &= ~TIM_CCER_CC3E
		    	TIM4->CR1 |= TIM_CR1_CEN;
		    	TIM5->CR1 |= TIM_CR1_CEN;
		    }
		    cont = 0;
		    value = 0;
		}
	}
}

void questao06(){
	Utility_Init();
	USART1_Init();

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT);
	GPIO_Pin_Mode(GPIOA, PIN_7, OUTPUT);
	GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
	GPIO_Write_Pin(GPIOA, PIN_7, HIGH);

	// Configurações Base para o ADC
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	ADC->CCR |= 0b01 << 16;
	ADC1->SQR1 &= ~(0xF << 20);
	ADC1->SQR3 |= 16;
	ADC1->SMPR1 |= (7 << 18);
	ADC->CCR |= ADC_CCR_TSVREFE;
	ADC1->CR2 |= ADC_CR2_ADON;

	// Configurações para o Timer 3
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;			// Liga o Clock do Timer 3
	TIM3->CR1 &= ~TIM_CR1_DIR;					// Define contagem crescente
	TIM3->PSC = 8399;							// Prescaler para pulsos (incrementos) a cada 5us (TIM3 = 84MHz)
	TIM3->ARR = 199;							// Estouros a cada 20 ms

	// Configuração do TIMER para Interrupções
	TIM3->CR2 = 0b010 << 4;						// Configuração no modo MESTRE (TRGO em Updates)
	TIM3->CR1 |= TIM_CR1_URS;					// Ativação do bit para gatilho TRGO (Overflow);
	TIM3->EGR = TIM_EGR_UG; 					// Update Event para escrever o valor do prescaler imediatamente

	// Configuração do ADC para Interrupções
	ADC1->CR2 |= 0b1000 << 24; 					// Seleciona a saída (TIM3 TRGO) como fonte de gatilhos
	ADC1->CR2 |= 0b01 << 28;					// Habilita o disparo na borda de subida
	ADC1->CR1 |= ADC_CR1_EOCIE;					// Habilita a interrupção de EOC
	NVIC_EnableIRQ(ADC_IRQn); 					// Habilita a Interrupção do NVIC

	TIM3->CR1 |= TIM_CR1_CEN;					// Habilita o Timer

	// Timer para o Buzzer (Delay)
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	TIM5->PSC = 83;
	TIM5->ARR = 1999;
	GPIO_Pin_Mode(GPIOA, PIN_2, ALTERNATE);
	GPIO_Alternate_Function(GPIOA, PIN_2, AF2);
	TIM5->CCMR2 |= 0b110 << 4;
	TIM5->CCMR2 |= TIM_CCMR2_OC3PE;
	TIM5->CCER |= TIM_CCER_CC3E;
	TIM5->EGR |= TIM_EGR_UG;
	TIM5->CR1 &= ~TIM_CR1_DIR;
	TIM5->CCR3 = 1000;

	// Configurar do Timer 4
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	TIM4->PSC = 8399;
	TIM4->ARR = 2500;
	TIM4->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM4_IRQn);

	while(1){}
}

// Questão 07
#define ESQUERDA -1
#define PARADO    0
#define DIREITA   1
#define TRANSICAO 2
#define LIM_DEADZONE 50
#define INA1 PIN_7
#define INB1 PIN_6

double posicaoMotor = 0;
int estado = PARADO;
int proximaDirecao = PARADO;

void questao07() {
    Utility_Init();
    USART1_Init();

    GPIO_Clock_Enable(GPIOA);
    GPIO_Pin_Mode(GPIOA, INA1, OUTPUT);
    GPIO_Pin_Mode(GPIOA, INB1, OUTPUT);

    GPIO_Pin_Mode(GPIOA, PIN_2, ALTERNATE); // Sinal PWM
    GPIO_Alternate_Function(GPIOA, PIN_2, AF2);

    ADC_Init(ADC1, SINGLE_CHANNEL, ADC_RES_12BITS);
    ADC_SingleChannel(ADC1, ADC_IN0);  // PA0

    // Timer para PWM no canal 3 (PA2)
    RCC->APB1ENR |= RCC_APB1ENR_TIM5EN; //liga o clock do Timer5
	TIM5->CR1 &= ~TIM_CR1_DIR; //contador crescente
	TIM5->ARR = 99; //auto reload=99
	TIM5->PSC = 419; //prescaler para pulsos a cada 5uS
	TIM5->CCMR2 |= 0b110 << 4; //seleciona PWM modo 1
	TIM5->CCMR2 |= TIM_CCMR2_OC3PE; //habilita o pré-carregamento de CCR3
	TIM5->CCER |= TIM_CCER_CC3E; //habilita a saída
	TIM5->EGR = TIM_EGR_UG; //update event para escrever PSC e ARR
	TIM5->CR1 |= TIM_CR1_CEN; //habilita o timer

    // Timer para chamadas periódicas (100ms)
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; // Ativa Clock Timer 3
	TIM3->CR1 &= ~(TIM_CR1_DIR); // Direção Crescente
	TIM3->PSC = 8399;  // 84MHz / (8399 + 1) = 10kHz
	TIM3->ARR = 999;    // 10kHz / (999 + 1) = 10Hz → 100ms
	// 3. Gera um evento de atualização para carregar os registros
	TIM3->EGR = TIM_EGR_UG;
	// 4. Habilita interrupção de atualização (quando contador reinicia)
	TIM3->DIER |= TIM_DIER_UIE;
	// 5. Habilita a interrupção no NVIC
	NVIC_EnableIRQ(TIM3_IRQn);
	// 6. Inicia o Timer
	TIM3->CR1 |= TIM_CR1_CEN;

    while (1) {
        // Loop principal vazio (uso de interrupções)
    }
}
// Timer da questão 07
void TIM3_IRQHandler() {
    TIM3->SR &= ~TIM_SR_UIF;

    uint16_t leitura = ADC_GetSingleConversion(ADC1);  // Retorna valor entre 0 e 4095 do Joystick
    int16_t centro = 2048;
    int16_t desvio = leitura - centro;

    double alvoMotor = 0;
    double max_pwm = 100.0;
    double ganho_pwm = max_pwm / 2048.0;

    // Direção desejada
    int direcaoDesejada = PARADO;
    if (desvio > LIM_DEADZONE)
        direcaoDesejada = DIREITA;
    else if (desvio < -LIM_DEADZONE)
        direcaoDesejada = ESQUERDA;

    // Suavização dinâmica
    double ganhoSuavizacao = 0.1;
    if (estado == TRANSICAO)
        ganhoSuavizacao = 0.4; // Desacelera mais rápido na transição

    // ---------- Controle de transição ----------
    if (estado == TRANSICAO) {
        if (posicaoMotor <= 10.0) { // Mudança de direção mais cedo
            estado = proximaDirecao;
            if (estado == DIREITA) {
                GPIO_Write_Pin(GPIOA, INA1, LOW);
                GPIO_Write_Pin(GPIOA, INB1, HIGH);
            } else if (estado == ESQUERDA) {
                GPIO_Write_Pin(GPIOA, INA1, HIGH);
                GPIO_Write_Pin(GPIOA, INB1, LOW);
            }
        }
        alvoMotor = 0;  // Desacelera
    }
    else if (direcaoDesejada != estado && direcaoDesejada != PARADO && estado != PARADO) {
        estado = TRANSICAO;
        proximaDirecao = direcaoDesejada;
        alvoMotor = 0;
    }
    else {
        if (direcaoDesejada == DIREITA) {
            estado = DIREITA;
            GPIO_Write_Pin(GPIOA, INA1, LOW);
            GPIO_Write_Pin(GPIOA, INB1, HIGH);
            alvoMotor = desvio * ganho_pwm;
        } else if (direcaoDesejada == ESQUERDA) {
            estado = ESQUERDA;
            GPIO_Write_Pin(GPIOA, INA1, HIGH);
            GPIO_Write_Pin(GPIOA, INB1, LOW);
            alvoMotor = -desvio * ganho_pwm;
        } else {
            alvoMotor = 0;
            if (posicaoMotor <= 1.0) {
                estado = PARADO;
                GPIO_Write_Pin(GPIOA, INA1, LOW);
                GPIO_Write_Pin(GPIOA, INB1, LOW);
            }
        }
    }

    // Aplicar suavização
    posicaoMotor += (alvoMotor - posicaoMotor) * ganhoSuavizacao;
    if (posicaoMotor > 100) posicaoMotor = 100;
    if (posicaoMotor < 0) posicaoMotor = 0;

    TIM5->CCR3 = posicaoMotor;
}

void questao08(){
	Utility_Init();
	USART1_Init();

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_1, ALTERNATE);
	GPIO_Alternate_Function(GPIOA, PIN_1, AF2);

	// TIM5
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	TIM5->CR1 &= ~TIM_CR1_DIR; //Contagem crescente
	TIM5->PSC = 8399; // Prescaler de 10 kHz
	TIM5->ARR = 9999; // Período de 1 segundo (1 Hz)
	TIM5->CCR2 = 5000; // Duty Cicle 50%
	TIM5->CCMR1 |= 0b110 << 12; // Seleciona PWM modo 1
	TIM5->CCMR1 |= TIM_CCMR1_OC2PE; // Habilita o pré carregamento do registrador CCR2
	TIM5->CCER |= TIM_CCER_CC2E; // Habilita saída
	TIM5->EGR = TIM_EGR_UG; // update event para escrever o valor do presca
	TIM5->CR1 |= TIM_CR1_CEN; // Habilita o timer

	while(1)
	{
	}
}

void questao09(){
	Utility_Init();
	USART1_Init();

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_1, ALTERNATE);
	GPIO_Alternate_Function(GPIOA, PIN_1, AF2);

	GPIO_Clock_Enable(GPIOB);
	GPIO_Pin_Mode(GPIOB, PIN_0, INPUT);
	GPIO_Pin_Mode(GPIOB, PIN_1, INPUT);

	// TIM5 gerando sinal PWM para PA1
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	TIM5->CR1 &= ~TIM_CR1_DIR; //Contagem crescente
	TIM5->PSC = 8399; // Prescaler de 10 kHz
	TIM5->ARR = 9999; // Período de 1 segundo (1 Hz)
	TIM5->CCR2 = 5000; // Duty Cicle 50%
	TIM5->CCMR1 |= 0b110 << 12; // Seleciona PWM modo 1
	TIM5->CCMR1 |= TIM_CCMR1_OC2PE; // Habilita o pré carregamento do registrador CCR2
	TIM5->CCER |= TIM_CCER_CC2E; // Habilita saída
	TIM5->EGR = TIM_EGR_UG; // update event para escrever o valor do presca
	TIM5->CR1 |= TIM_CR1_CEN; // Habilita o timer

	// Interrupções externas
	EXTI_Config(EXTI0, GPIOB, RISING_EDGE);
	NVIC_EnableIRQ(EXTI0_IRQn);
	EXTI_Config(EXTI1, GPIOB, RISING_EDGE);
	NVIC_EnableIRQ(EXTI1_IRQn);

	NVIC_SetPriority(EXTI0_IRQn, 0);
	NVIC_SetPriority(EXTI1_IRQn, 0);

	while(1){

	}
}

void questao10(){
	Utility_Init();
	USART1_Init();

	GPIO_Clock_Enable(GPIOA);
	GPIO_Pin_Mode(GPIOA, PIN_1, ALTERNATE);
	GPIO_Alternate_Function(GPIOA, PIN_1, AF2);
	GPIO_Pin_Mode(GPIOA, PIN_6, OUTPUT); // D2
	GPIO_Pin_Mode(GPIOA, PIN_7, OUTPUT); // D3
	GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
	GPIO_Write_Pin(GPIOA, PIN_7, HIGH);

	GPIO_Clock_Enable(GPIOB);
	GPIO_Pin_Mode(GPIOB, PIN_0, INPUT);
	GPIO_Pin_Mode(GPIOB, PIN_1, INPUT);

	GPIO_Clock_Enable(GPIOE);
	GPIO_Pin_Mode(GPIOE, PIN_4, INPUT); // K0
	GPIO_Resistor_Enable(GPIOE, PIN_4, PULL_UP);
	GPIO_Pin_Mode(GPIOE, PIN_3, INPUT); // K1
	GPIO_Resistor_Enable(GPIOE, PIN_3, PULL_UP);

	// TIM5 gerando sinal PWM para PA1
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	TIM5->CR1 &= ~TIM_CR1_DIR; //Contagem crescente
	TIM5->PSC = 8399; // Prescaler de 10 kHz
	TIM5->ARR = 9999; // Período de 1 segundo (1 Hz)
	TIM5->CCR2 = 5000; // Duty Cicle 50%
	TIM5->CCMR1 |= 0b110 << 12; // Seleciona PWM modo 1
	TIM5->CCMR1 |= TIM_CCMR1_OC2PE; // Habilita o pré carregamento do registrador CCR2
	TIM5->CCER |= TIM_CCER_CC2E; // Habilita saída
	TIM5->EGR = TIM_EGR_UG; // update event para escrever o valor do prescaler
	TIM5->CR1 |= TIM_CR1_CEN; // Habilita o timer

	// Configurando interrupções externas
	EXTI_Config(EXTI0, GPIOB, RISING_EDGE);
	NVIC_EnableIRQ(EXTI0_IRQn);
	EXTI_Config(EXTI1, GPIOB, RISING_EDGE);
	NVIC_EnableIRQ(EXTI1_IRQn);

	NVIC_SetPriority(EXTI0_IRQn, 0);
	NVIC_SetPriority(EXTI1_IRQn, 0);

	// Configurando Timer TIM3
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; // Liga clock TIM3
	TIM3->PSC = 41999; // PS = 500 us
	TIM3->ARR = 3999;
	TIM3->EGR |= TIM_EGR_UG;  // update para escrever o valor do prescaler
	TIM3->CR1 |= TIM_CR1_OPM;
	TIM3->CR1 &= ~TIM_CR1_DIR; // contagem crescente
	// TIM4
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; // Liga clock TIM3
	TIM4->PSC = 41999;
	TIM4->ARR = 7999;
	TIM4->EGR |= TIM_EGR_UG;  // update para escrever o valor do prescaler
	TIM4->CR1 |= TIM_CR1_OPM;
	TIM4->CR1 &= ~TIM_CR1_DIR; // contagem crescente

	// Configurando interrupções externas
	EXTI_Config(EXTI3, GPIOE, RISING_EDGE);
	NVIC_EnableIRQ(EXTI3_IRQn);
	EXTI_Config(EXTI4, GPIOE, RISING_EDGE);
	NVIC_EnableIRQ(EXTI4_IRQn);

	while(1){
		if (TIM3->SR & TIM_SR_UIF) {
			TIM3->SR &= ~TIM_SR_UIF;
			// Ação após 2 segundos
			GPIO_Write_Pin(GPIOA, PIN_6, HIGH);
		}
		if (TIM4->SR & TIM_SR_UIF) {
			TIM4->SR &= ~TIM_SR_UIF;
			// Ação após 4 segundos
			GPIO_Write_Pin(GPIOA, PIN_7, HIGH);
		}
	}
}

#endif
