#pragma once

class AFigura 
{
protected:
	int posX, posY, despX, despY, color;
public:
	AFigura(int pPosX, int pPosY,int pDespX,int pDespY,int pColor);
	AFigura(void) {};
	~AFigura(void) {};
	virtual void set_posX(int pPosX) abstract;
	virtual void set_posY(int pPosY) abstract;
	virtual void Dibujar(System::Drawing::Graphics^g) abstract;
	virtual void Mover(System::Drawing::Graphics^g) abstract;
	virtual void Accion(System::Drawing::Graphics^g, System::Random ^rd) abstract;
	virtual int get_radio() abstract;
	virtual int get_posX() abstract;
	virtual int get_posY() abstract;
};

AFigura::AFigura(int pPosX, int pPosY, int pDespX, int pDespY, int pColor) {
	this->posX = pPosX;
	this->posY = pPosY;
	this->despX = pDespX;
	this->despY = pDespY;
	this->color = pColor;
};
