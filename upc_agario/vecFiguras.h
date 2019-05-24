#pragma once

#include "figura.h"
#include "circuloAleatorio.h"
#include "virus.h"
#include "jugador.h"
#include "windows.h"

#define val_min_radio 25
#define val_max_radio 75
#define radio_virus 15

class AVecFiguras {

private:
	AFigura** arrFigura;
	int cant;
	bool opcion;
public:
	AVecFiguras(void) {
		this->cant = 0;
		this->opcion = true;
		this->arrFigura = new AFigura*[cant];
	};
	~AVecFiguras(void) {};
	void AgregarFigura(System::Drawing::Graphics^g, bool opcion);
	void EliminarFigura(System::Drawing::Graphics^g, int valor);
	void MoverFiguras(System::Drawing::Graphics^g);
};

void AVecFiguras::AgregarFigura(System::Drawing::Graphics^ g, bool opcion) 
{
	AFigura ** VectorTemporalFiguras = new AFigura* [cant+ 1];
	AFigura* nuevaFigura;

	System::Random ^ rd = gcnew System::Random();

	for (int i = 0; i < cant; i++) 
		VectorTemporalFiguras[i] = arrFigura[i];
	

	System::Drawing::Color color = System::Drawing::Color::FromArgb(rd->Next(255), rd->Next(255), rd->Next(255));
	System::Drawing::Color color_virus = System::Drawing::Color::FromArgb(107, 190, 91);
	
	if (opcion) {
		nuevaFigura = new ACirculoAleatorio( rd->Next(80, g->VisibleClipBounds.Width /2),
			rd->Next(80, g->VisibleClipBounds.Height/2),
			1, 1,
			System::Drawing::ColorTranslator::ToWin32(color), rd->Next(val_min_radio, val_max_radio));
	
	}else {
	
		nuevaFigura = new AVirus (rd->Next(200, 1000),
			rd->Next(100, 600),
			0, 0,
			System::Drawing::ColorTranslator::ToWin32(color_virus), radio_virus);
	}
	VectorTemporalFiguras[cant] = nuevaFigura;
	cant+=1;

	if (arrFigura != NULL)
		delete[] arrFigura;

	arrFigura = VectorTemporalFiguras;
};

void AVecFiguras::EliminarFigura(System::Drawing::Graphics^g,int valor) {
	AFigura **AVecFig = new AFigura*[cant- 1];
	for (int i = 0; i < valor; i++)
		AVecFig[i] = arrFigura[i];
	for (int i = valor + 1; i < cant; i++)
		AVecFig[i - 1] = arrFigura[i];
	cant-= 1;
	arrFigura = AVecFig;
};
void AVecFiguras::MoverFiguras(System::Drawing::Graphics^g) 
{
	for (int i = 0; i < cant; i++) {
		arrFigura[i]->Mover(g);
		arrFigura[i]->Dibujar(g);
	}
};
