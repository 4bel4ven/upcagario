#pragma once
#include "figura.h"
#define radio_minimo_med 10
class ACirculoAleatorio:public AFigura
{
private:
	int r;
public:
	ACirculoAleatorio(int pPosX, int pPosY, int pDespX, int pDespY, int pColor,int pR);
	~ACirculoAleatorio(void) {};
	void set_posX(int pPosX) {};
	void set_posY(int pPosY) {};
	void Dibujar(System::Drawing::Graphics^ g);
	void Mover(System::Drawing::Graphics^ g);
	void Accion(System::Drawing::Graphics^g, System::Random^rd);
	int get_radio() { return r; };
	int get_posX() { return posX; };
	int get_posY() { return posY; };
};

ACirculoAleatorio::ACirculoAleatorio(int pPosx, int pPosy, int pDespX, int pDespY, int pColor, int pR) :AFigura(pPosx, pPosy, pDespX, pDespY, pColor) {
	this->r = pR;
};

void ACirculoAleatorio::Dibujar(System::Drawing::Graphics ^g)
{
	System::Drawing::Color col = System::Drawing::ColorTranslator::FromWin32(color);
	System::Drawing::SolidBrush^ miBrocha = gcnew System::Drawing::SolidBrush(col);

	g->FillEllipse(miBrocha, posX - r, posY - r, 2 * r, 2 * r);

};

void ACirculoAleatorio::Mover(System::Drawing::Graphics ^g)
{

	//control de velocidad
	if (despX < 0) {
		if (r > radio_minimo_med && r <= radio_minimo_med+5) {
			despX = -20;
		}
		else if (r > radio_minimo_med+5 && r <= radio_minimo_med+10) {
			despX = -18;
		}
		else if (r > radio_minimo_med+10 && r <= radio_minimo_med+15) {
			despX = -16;
		}
		else if (r > radio_minimo_med +15 && r <= radio_minimo_med+20) {
			despX = -14;
		}
		else if (r > radio_minimo_med +20 && r <= radio_minimo_med+25) {
			despX = -12;
		}
		else if (r > radio_minimo_med+25 && r <= radio_minimo_med+30) {
			despX = -10;
		}
		else if (r > radio_minimo_med+30 && r <= radio_minimo_med+35) {
			despX = -8;
		}
		else if (r > radio_minimo_med+35 && r <= radio_minimo_med+40) {
			despX =  -6;
		}
		else if (r > radio_minimo_med+40 && r <= radio_minimo_med+70) {
			despX =  -4;
		};
	}
	else {
		if (r > radio_minimo_med && r <= radio_minimo_med + 5) {
			despX = 20;
		}
		else if (r > radio_minimo_med + 5 && r <= radio_minimo_med + 10) {
			despX = 18;
		}
		else if (r > radio_minimo_med + 10 && r <= radio_minimo_med + 15) {
			despX = 16;
		}
		else if (r > radio_minimo_med + 15 && r <= radio_minimo_med + 20) {
			despX = 14;
		}
		else if (r > radio_minimo_med + 20 && r <= radio_minimo_med + 25) {
			despX = 12;
		}
		else if (r > radio_minimo_med + 25 && r <= radio_minimo_med + 30) {
			despX = 10;
		}
		else if (r > radio_minimo_med + 30 && r <= radio_minimo_med + 35) {
			despX = 8;
		}
		else if (r > radio_minimo_med + 35 && r <= radio_minimo_med + 40) {
			despX = 6;
		}
		else if (r > radio_minimo_med + 40 && r <= radio_minimo_med + 70) {
			despX = 4;
		};
	};

	if (despY < 0) {
		if (r > radio_minimo_med && r <= radio_minimo_med+5) {
			despY = -20;
		}
		else if (r > radio_minimo_med+5 && r <= radio_minimo_med+10) {
			despY = -18;
		}
		else if (r > radio_minimo_med+10 && r <= radio_minimo_med+15) {
			despY = -16;
		}
		else if (r > radio_minimo_med+15 && r <= radio_minimo_med+20) {
			despY = -14;
		}
		else if (r > radio_minimo_med+20 && r <= radio_minimo_med+25) {
			despY = -12;
		}
		else if (r > radio_minimo_med+25 && r <= radio_minimo_med+30) {
			despY = -10;
		}
		else if (r > radio_minimo_med+30 && r <= radio_minimo_med+35) {
			despY = -8;
		}
		else if (r > radio_minimo_med+35 && r <= radio_minimo_med+40) {
			despY = -6;
		}
		else if (r > radio_minimo_med+40 && r <= radio_minimo_med+70) {
			despY = -4;
		};
	}
	else {
		if (r > radio_minimo_med && r <= radio_minimo_med + 5) {
			despY = 20;
		}
		else if (r > radio_minimo_med + 5 && r <= radio_minimo_med + 10) {
			despY = 18;
		}
		else if (r > radio_minimo_med + 10 && r <= radio_minimo_med + 15) {
			despY = 16;
		}
		else if (r > radio_minimo_med + 15 && r <= radio_minimo_med + 20) {
			despY = 14;
		}
		else if (r > radio_minimo_med + 20 && r <= radio_minimo_med + 25) {
			despY = 12;
		}
		else if (r > radio_minimo_med + 25 && r <= radio_minimo_med + 30) {
			despY = 10;
		}
		else if (r > radio_minimo_med + 30 && r <= radio_minimo_med + 35) {
			despY = 8;
		}
		else if (r > radio_minimo_med + 35 && r <= radio_minimo_med + 40) {
			despY = 6;
		}
		else if (r > radio_minimo_med + 40 && r <= radio_minimo_med + 70) {
			despY = 4;
		};
	};

	//rebota si llega a un extremo
	if (((posX - r) < 0) || ((posX + r) > g->VisibleClipBounds.Width ))
		despX *= -1;

	if (((posY - r) < 0) || ((posY + r) > g->VisibleClipBounds.Height ))
		despY *= -1;

	posX += despX;
	posY += despY;
};
void ACirculoAleatorio::Accion(System::Drawing::Graphics ^g, System::Random^rd)
{
	this->color = System::Drawing::ColorTranslator::ToWin32 ( System::Drawing::Color::FromArgb(rd->Next(255), rd->Next(255), rd->Next(255)) );
};
