#pragma once
#include "vecFiguras.h"
#include "jugador.h"
#define cantAleatorios 4
#define cantVirus 3
namespace upcagario {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for juego
	/// </summary>
	public ref class juego : public System::Windows::Forms::Form
	{
	public:
		juego(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~juego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;

	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &juego::timer1_Tick);
			// 
			// juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1584, 711);
			this->KeyPreview = true;
			this->Name = L"juego";
			this->Text = L"juego";
			this->Load += gcnew System::EventHandler(this, &juego::juego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &juego::juego_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		AVecFiguras* oVecFiguras;
		AVecFiguras* oVecVirus;
		System::Random^rd;
		AJugador *jugador;
	

	private: System::Void juego_Load(System::Object^  sender, System::EventArgs^  e) {
		oVecFiguras = new AVecFiguras();
		oVecVirus = new AVecFiguras();

		/********************SE CREAN LOS ALEATORIOS********************/
		for (int i = 0 ; i < cantAleatorios; i++)
		oVecFiguras->AgregarFigura (this->CreateGraphics(),true);
		/****************SE CREAN VIRUS*********************/
		for (int i = 0; i < cantVirus; i++)
		oVecVirus->AgregarFigura (this->CreateGraphics(),false);
		/***********************SE INICIA EL JUGADOR****************/
		
		jugador = new AJugador(100, 100, 1, 1, 1, 30);
		
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	
		Graphics^g = this->CreateGraphics();
		if (g->VisibleClipBounds.Width > 0 && g->VisibleClipBounds.Height > 0)
		{
			System::Drawing::Bitmap ^image = gcnew System::Drawing::Bitmap(
				g->VisibleClipBounds.Width,
				g->VisibleClipBounds.Height);

			System::Drawing::Graphics ^ImageCanvas = System::Drawing::Graphics::FromImage(image);
			ImageCanvas->Clear(System::Drawing::Color::White);

			oVecFiguras->MoverFiguras(ImageCanvas);
			oVecVirus->MoverFiguras(ImageCanvas);

			jugador->Dibujar(ImageCanvas);

			g->DrawImage(image, 0, 0);

			delete ImageCanvas;
			delete image;
		}
		delete g;
	}
	
	private: System::Void juego_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		
		if (e->KeyCode == System::Windows::Forms::Keys::Space)
		{

		}
		else if (e->KeyCode == System::Windows::Forms::Keys::Up)
		{
			jugador->Mover(this->CreateGraphics(), 0, 0);
		}
		else if(e->KeyCode == System::Windows::Forms::Keys::Down)
		{
			jugador->Mover(this->CreateGraphics(), 0, 1);
		}
		else if (e->KeyCode == System::Windows::Forms::Keys::Right)
		{
			jugador->Mover(this->CreateGraphics(), 1, 0);
		}
		else if (e->KeyCode == System::Windows::Forms::Keys::Left)
		{
			jugador->Mover(this->CreateGraphics(), 1, 1);
		};
	};
};
}
