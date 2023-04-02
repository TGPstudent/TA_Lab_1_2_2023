//TA_Lab_1_2_2023.c Робота з файлами. Функція додавання тексту в файл.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

//Функція дозапису тексту в файл

	void AddTo(char *NF, char *Str)
	{
	FILE *Inp;
	Inp = fopen(NF, "at+");
	fprintf (Inp, "\n %s", Str);
	fclose(Inp);
	}

int main(void)
{
	//Встановив кодування, підключення Укр. мови
	system("chcp 1251");
	setlocale(LC_CTYPE, "ukr");
	system("cls");

	int N = 100;
	char *NamFil = (char*)calloc(N, sizeof(char*));
	printf("\n Введіть Назву файлу та шлях до нього: ");
	gets(NamFil);
	N = strlen(NamFil) + 1;
	NamFil = (char*)realloc(NamFil, N * sizeof(char*));

	N = 255;
	char *Str = (char*)calloc(N, sizeof(char*));
	printf("\n Введіть текст: ");
	gets(Str);
	N = strlen(Str) + 1;
	Str = (char*)realloc(Str, N * sizeof(char*));
	
	//Відкриття файлу для діалогу з користувачем
	FILE *F;
	F = fopen(NamFil, "rt");
	if (F==0) 
	printf("\n Файл: %s не існує і буде створено для запису заданої Вами фрази.\n", NamFil);
	else
	{
	printf("\n Файл : %s відкрито і він містить наступний текст:\n ", NamFil);
	char buffer[255];
	do
	{
		fgets(buffer, 255, F);
		puts(buffer);
	} 
	while (!feof(F));
	fclose(F);
	}
			AddTo(NamFil, Str);
	
		printf("\n До файлу: %s додано заданий Вами текст, а саме: ", NamFil);
		puts(Str);
		
	getchar();
	free(Str);
	free(NamFil);
	
	return 0;
}
