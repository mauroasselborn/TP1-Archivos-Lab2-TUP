#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

#include <windows.h>


void centrarTexto(string, SHORT);
void imprimirFechaActual ( void );


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
	imprimirFechaActual();
	colorTexto(15);
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

/** OBTENER FECHA ACTUAL **/
void imprimirFechaActual ( void )
{
    int day, month, year;
    struct tm *tiempo;

    time_t fecha_sistema;
    time ( &fecha_sistema );
    tiempo = localtime ( &fecha_sistema );

    year = tiempo->tm_year + 1900;
    month = tiempo->tm_mon + 1;
    day = tiempo->tm_mday;

    gotoxy ( 80, 18 );
    ( month < 10 ) ? cout << "Fecha: " << day << "/" << "0" << month << "/" << year : cout << "Fecha: " << day << "/" << month << "/" << year;
    gotoxy ( 0, 3 );
}

#endif // UTILIDADES_H_INCLUDED
