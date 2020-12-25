// ConsoleApplication3.cpp : main project file.

#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
using namespace std;
using namespace System;
int ingresapositivo()
{
	int n;
	do
	{
		cout << "ingresa # de filas o columas: "; cin >> n;
	} while (n < 0 || n>50); return n;
}
void ingresodatos(int *f, int *c, int **matriz)
{
	Random r;
	for (int i = 0; i < *f; i++)
		for (int j = 0; j < *c; j++)
			matriz[i][j] = r.Next(1, 4);

}
void salidadatos(int *f, int *c, int **matriz)
{
	for (int i = 0; i < *f; i++)
	{
		for (int j = 0; j < *c; j++)
			cout << matriz[i][j] << "\t";
		cout << endl;
	}
}
void mayorfrecuencia(int *f, int *c, int **matriz, int *contador)
{
	int contador1=0, contador2=0, contador3=0;
	for (int i = 0; i < *f; i++)
		for (int j = 0; j < *c; j++)
		{
			if (matriz[i][j] == 3)
				contador3++;
			if (matriz[i][j] == 2)
				contador2++;
			if (matriz[i][j] == 1)
				contador1++;
		}
	for (int i = 0; i < 3; i++)
	{
		contador[0] = contador1;
		contador[1] = contador2;
		contador[2] = contador3;
	}

	
}
void salidacontador(int*contador)
{
	cout << "frecuencia por cultivo" << endl;
	cout << "zana" << "\t" << "beren" << "\t" << "nabos" << endl;
	for (int i = 0; i < 3; i++)
		cout << contador[i] << "\t";
	cout << endl;
}
void mayorymenor(int*contador)
{
	int mayor = contador[0];
	int menor = contador[0];
	int cultivomasfre=1;
	int cultivomenosfre = 1;
	for (int i = 1; i < 3; i++)
		if (mayor < contador[i])
		{
			mayor = contador[i];
			cultivomasfre = i+1;
		}
	for (int i = 1; i < 3; i++)
		if (menor > contador[i])
		{
			menor = contador[i];
			cultivomenosfre = i + 1;
		}
	cout << "el cultivo de mayor frecuencia es: " << cultivomasfre << " cantidad: " << mayor << endl;
	cout << "el cultivo de menor frecuencia es: " << cultivomenosfre << " cantidad: " << menor << endl;
}
void guaridatopos(int *f, int *c, int **matriz)
{
	cout << "la guaridad de topos se encuentra: " << endl;
	
	for (int i = 1; i < *f-1; i++)
		for (int j = 1; j < *c-1; j++)
		
			if (matriz[i][j+1] == 2 && matriz[i][j-1] == 2 && matriz[i-1][j] == 3 && matriz[i+1][j] == 1)
			{
				cout << "la fila: " << i+1 << "columna: " << j+1 << endl;
			}
}
int main()
{
	int f = ingresapositivo();
	int c = ingresapositivo();
	int **matriz = new int*[f];
	for (int i = 0; i < f; i++)
		matriz[i] = new int[c];
	int *contador = new int[3];
	ingresodatos(&f, &c, matriz);
	salidadatos(&f, &c, matriz);
	mayorfrecuencia(&f, &c, matriz,contador);
	salidacontador(contador);
	mayorymenor(contador);
	guaridatopos(&f, &c, matriz);
	for (int i = 0; i < f; i++)
		delete[] matriz[i];
	delete[]matriz;
	delete[] contador;
	_getch();
}

