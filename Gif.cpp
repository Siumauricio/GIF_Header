#include "Gif.h"
#include <fstream>
#include <iostream>

void Gif::CargarHeader (char*filename) {
	ifstream Archivo;
	Archivo.open (filename, ifstream::in | ifstream::binary);
	Archivo.seekg (0, ios_base::beg);
	Archivo.read ((char*)&Gif_Header, sizeof (GIF_Header));
	ImprimirHeader ();
	Archivo.close ();
}

void Gif::ImprimirHeader () {
	char* tipo = new char[sizeof (Gif_Header.Tipo)];
	tipo[3] = '\0';
	memcpy (tipo, &Gif_Header.Tipo, 3);

	char* Firma = new char[sizeof (Gif_Header.Firma)];
	Firma[3] = '\0';
	memcpy (Firma, &Gif_Header.Firma, 3);

	cout << "********************************************" << endl;
	cout << "Tamano Estructura: "<<sizeof(GIF_Header)<< endl;
	cout << "Tipo: " << tipo << endl;
	cout << "Firma: " << Firma << endl;
	cout << "Ancho: " << Gif_Header.Ancho << endl;
	cout << "Altura: " << Gif_Header.Altura << endl;
	cout << "Banderas: " << (int)Gif_Header.Banderas << endl;
	cout << "Fondo: " << (int)Gif_Header.Fondo << endl;
	cout << "Rango: " <<(int) Gif_Header.Rango << endl;
	cout << "********************************************" << endl;
}
