#pragma once
#include <inttypes.h>
using namespace std;

struct GIF_Header {
	char  Tipo[3];
	char  Firma[3];               //Firma 89A O 87A
	uint16_t Ancho;               //  Ancho del GIF
	uint16_t  Altura;			  //Altura del GIF
	uint8_t   Banderas;           // Color Global de la paleta
	uint8_t   Fondo;              //  Color De Fondo 
	uint8_t  Rango;               //Relacion Del Aspecto de un pixel  //7atr
};

class Gif {
private:
	GIF_Header Gif_Header;
public:
	void CargarHeader (char*Archivo);
	void ImprimirHeader ();
};
