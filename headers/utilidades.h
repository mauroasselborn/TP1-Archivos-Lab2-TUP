#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

#include <windows.h>


void centrarTexto(string, SHORT);


void colorTexto(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void borrarPantalla(void)
{
	system("cls");
}

void pause(void)
{

	system("pause > nul");
}

void entradaIncorrecta(void)
{
	cout << endl << endl;
	colorTexto(12);
	centrarTexto("Entrada Incorrecta",15);
	centrarTexto("Precione ENTER",16);
	pause();

}

void tituloTP(void)
{
	system("title TP Archivos - *LABORATORIO 2* - Mauro y Juan Asselborn");

}

void encabezado(string titulo)
{
	colorTexto(14);
	cout << (char)32;
	for (int i = 0; i < 98; i++) cout << (char)205;
	centrarTexto(titulo, 1);
	cout << (char)32;
	for (int j = 0; j < 98; j++) cout << (char)205;
	cout << endl;
}

/** POSICIONAMIENTO DEL CURSOR **/
int gotoxy(SHORT X, SHORT Y)
{
	COORD coord;
	HANDLE h_stdout;

	coord.X = X;
	coord.Y = Y;

	if ((h_stdout = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE) return 0;
	if (SetConsoleCursorPosition(h_stdout, coord) == 0) return 0;
	return 0;
}

void centrarTexto(string texto, SHORT y)
{
	int size_texto = texto.size();
	gotoxy(50 - size_texto / 2, y);
	cout << texto << endl;
}

void ocultarCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}


#endif // UTILIDADES_H_INCLUDED
