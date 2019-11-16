#include "stdafx.h"
#include "display.h"

const int Botao0 = 14;
const int Botao1 = 15;
const int led1 = 13;
const int led2 = 12;
const int led3 = 11;

int valor1, valor2;
int soma;
int MAX = 4;
int cont = 0;
int entrada1 = 0;
int entrada0 = 0;
int estado = 0;

void setup()
{

	pinMode(Botao0, INPUT_PULLUP);
	pinMode(Botao1, INPUT_PULLUP);

	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led3, OUTPUT);

	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);

	exibeDisplay(cont);
}

void exibeDisplay(cont)
{
	if (cont == 0)
	{

		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(5, LOW);
		digitalWrite(6, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, HIGH);
		digitalWrite(9, HIGH);
	}
	else if (cont == 1)
	{

		digitalWrite(2, HIGH);
		digitalWrite(3, HIGH);
		digitalWrite(4, LOW);
		digitalWrite(5, HIGH);
		digitalWrite(6, HIGH);
		digitalWrite(7, LOW);
		digitalWrite(8, HIGH);
		digitalWrite(9, HIGH);
	}
	else if (cont == 2)
	{

		digitalWrite(2, HIGH);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(5, LOW);
		digitalWrite(6, LOW);
		digitalWrite(7, HIGH);
		digitalWrite(8, LOW);
		digitalWrite(9, HIGH);
	}
	else if (cont == 3)
	{

		digitalWrite(2, HIGH);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(5, HIGH);
		digitalWrite(6, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
		digitalWrite(9, HIGH);
	}
	else if (cont == 4)
	{

		digitalWrite(2, LOW);
		digitalWrite(3, HIGH);
		digitalWrite(4, LOW);
		digitalWrite(5, HIGH);
		digitalWrite(6, HIGH);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
		digitalWrite(9, HIGH);
	}
	else if (cont == 5)
	{

		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, HIGH);
		digitalWrite(5, HIGH);
		digitalWrite(6, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
		digitalWrite(9, HIGH);
	}
	else if (cont == 6)
	{

		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, HIGH);
		digitalWrite(5, LOW);
		digitalWrite(6, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
		digitalWrite(9, HIGH);
	}
	else if (cont == 7)
	{

		digitalWrite(2, HIGH);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(5, HIGH);
		digitalWrite(6, HIGH);
		digitalWrite(7, LOW);
		digitalWrite(8, HIGH);
		digitalWrite(9, HIGH);
	}
	else if (cont == 8)
	{

		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
		digitalWrite(5, LOW);
		digitalWrite(6, LOW);
		digitalWrite(7, LOW);
		digitalWrite(8, LOW);
		digitalWrite(9, HIGH);
	}
}
int leitura(int botao)
{

	int estado = digitalRead(botao);
	if (estado == 1)
	{
		return LOW;
	}
	else
	{
		return HIGH;
	}
}

void loop()
{
	exibeDisplay(cont);

	if (leitura(Botao1) == LOW && entrada1 == 0)
	{
		delay(20);
		cont++;
		if (cont == MAX)
			cont = 0;
		entrada1 = 1;
	}
	if (leitura(Botao1) == HIGH && entrada1 == 1)
	{
		entrada1 = 0;
	}

	if (leitura(Botao0) == LOW && entrada0 == 0)
	{
		delay(20);
		if (estado == 0)
		{
			valor1 = cont;
			cont = 0;
			estado = 1;
		}
		else if (estado == 1)
		{
			valor2 = cont;
			soma = valor1 + valor2;
			cont = soma;

			exibeDisplay(cont);

			if (soma == 0)
			{
				digitalWrite(led1, LOW);
				digitalWrite(led2, LOW);
				digitalWrite(led3, LOW);
			}
			else if (soma == 1)
			{
				digitalWrite(led1, LOW);
				digitalWrite(led2, LOW);
				digitalWrite(led3, HIGH);
			}
			else if (soma == 2)
			{
				digitalWrite(led1, LOW);
				digitalWrite(led2, HIGH);
				digitalWrite(led3, LOW);
			}
			else if (soma == 3)
			{
				digitalWrite(led1, LOW);
				digitalWrite(led2, HIGH);
				digitalWrite(led3, HIGH);
			}
			else if (soma == 4)
			{
				digitalWrite(led1, HIGH);
				digitalWrite(led2, LOW);
				digitalWrite(led3, LOW);
			}
			else if (soma == 5)
			{
				digitalWrite(led1, HIGH);
				digitalWrite(led2, LOW);
				digitalWrite(led3, HIGH);
			}
			else if (soma == 6)
			{
				digitalWrite(led1, HIGH);
				digitalWrite(led2, HIGH);
				digitalWrite(led3, LOW);
			}
			else if (soma == 7)
			{
				digitalWrite(led1, HIGH);
				digitalWrite(led2, HIGH);
				digitalWrite(led3, HIGH);
			}
			else if (soma == 8)
			{
				digitalWrite(led1, HIGH);
				digitalWrite(led2, HIGH);
				digitalWrite(led3, HIGH);
			}

			estado = 2;
		}
		else if (estado == 2)
		{

			valor1 = 0;
			valor2 = 0;
			cont = 0;
			soma = 0;

			exibeDisplay(cont);

			digitalWrite(led1, LOW);
			digitalWrite(led2, LOW);
			digitalWrite(led3, LOW);
			estado = 0;
		}
		entrada0 = 1;
	}
	if (leitura(Botao0) == HIGH && entrada0 == 1)
	{
		entrada0 = 0;
	}
}

]