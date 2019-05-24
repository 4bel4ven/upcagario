#pragma once
#include "figura.h"
class AVirus:public AFigura 
{
private:
	int r;
public:
	AVirus(int pPosX, int pPosY, int pDespX, int pDespY, int pColor, int pR);
	AVirus(void) {};
	~AVirus(void) {};

	void set_posX(int pPosX);
	void set_posY(int pPosY);

	void Dibujar(System::Drawing::Graphics^g);
	void Mover(System::Drawing::Graphics^ g);
	void Accion(System::Drawing::Graphics^g, System::Random^rd) {};
	int get_radio() { return r; };
	int get_posX() { return posX; };
	int get_posY() { return posY; };

};
void AVirus::set_posX(int pPosX)
	{
		this->posX = pPosX;
	};

void AVirus::set_posY(int pPosY)
	{
		this->posY = pPosY;
	};

AVirus::AVirus(int pPosX, int pPosY, int pDespX, int pDespY, int pColor, int pR):AFigura(pPosX,pPosY,pDespX,pDespY,pColor)
{
	this->r = pR;
};

void AVirus::Dibujar(System::Drawing::Graphics^g) 
{
	System::Drawing::Color col = System::Drawing::Color::FromArgb(107, 190, 91);
	System::Drawing::SolidBrush^ miBrocha = gcnew System::Drawing::SolidBrush(col);
	g->FillEllipse(miBrocha, posX - r, posY - r, 2 * r, 2 * r);
	
};
void AVirus::Mover(System::Drawing::Graphics^ g) 
{
};
