#pragma once
class AJugador
{
private:
	int posX, posY, despX, despY, color, r;
	char *imagen;
public:
	AJugador(int pPosX, int pPosY, int pDespX, int pDespY, int pColor, int pR);
	AJugador(void) {};
	void Dibujar(System::Drawing::Graphics^g);
	void Mover(System::Drawing::Graphics^g, bool a,bool b);
	int get_radio() { return r; };
	int get_posX() { return posX; };
	int get_posY() { return posY; };
};
AJugador::AJugador(int pPosX, int pPosY, int pDespX, int pDespY, int pColor, int pR) {
	this->posX = pPosX;
	this->posY = pPosY;
	this->despX = pDespX;
	this->despY = pDespY;
	this->color = pColor;
	this->r = pR;
}
void AJugador::Dibujar(System::Drawing::Graphics^g) 
{
	System::Drawing::Color col = System::Drawing::ColorTranslator::FromWin32(color);
	System::Drawing::SolidBrush^ miBrocha = gcnew System::Drawing::SolidBrush(col);
	
	g->FillEllipse(miBrocha, posX - r, posY - r, 2 * r, 2 * r);
};
void AJugador::Mover(System::Drawing::Graphics^g, bool a, bool b) {
	int val;
	if (r <= 30 && r>10) val = 20;
	else if (r <= 50 && r>30) val = 15;
	else if (r <= 70 && r>50) val = 10;
	else if (r <= 90 && r>70) val = 6;


	if (a == false && b == false) {			//a = 0 y b = 0  MUEVE ARRIBA
		if ((posY - r) >= 0) {
			despY = -val;
			posY += despY;
	}
	}
	else if (a == false && b == true) {		//a = 0 y b = 1 MUEVE ABAJO 
		if ((posY + r) <= g->VisibleClipBounds.Height) {
			despY = val;
			posY += despY;
		}
	}
	else if (a==true && b==false) {			//a = 1 y b = 0 MUEVE DERECHA
		if ((posX + r) <= g->VisibleClipBounds.Width) {
			despX = val;
			posX += despX;
		}
	}
	else {									//a = 1 y b = 1 MUEVE IZQUIERDA
		if ((posX - r) >= 0) {
			despX = -val;
			posX += despX;
		}
	};
};