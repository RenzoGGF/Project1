#pragma once
#include <msclr/marshal_cppstd.h>
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ImgGrafo
	/// </summary>
	public ref class ImgGrafo : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ loadBitmap() {
			// Usa __FILE__ directamente para obtener la ruta
			std::string filePath = __FILE__;
			size_t lastSlash = filePath.find_last_of("\\");

			// Obtiene la ruta del directorio
			std::string dirPath = (lastSlash != std::string::npos) ? filePath.substr(0, lastSlash) : filePath;

			// Crear la ruta completa del archivo de imagen
			std::string imagePath = dirPath + "\\grafo.png";

			// Convertir std::string a System::String^
			msclr::interop::marshal_context context;
			String^ managedPath = context.marshal_as<String^>(imagePath);

			// Crear el objeto Bitmap
			Bitmap^ bm = gcnew Bitmap(managedPath);

			// Retornar el Bitmap creado
			return bm;
		}

	public:
		ImgGrafo(void)
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
		~ImgGrafo()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	protected:

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			Bitmap^ bm =loadBitmap();
			this->pictureBox1->Image = bm;
			this->pictureBox1->Location = System::Drawing::Point(22, 25);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1001, 768);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			
			// 
			// ImgGrafo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1035, 884);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"ImgGrafo";
			this->Text = L"ImgGrafo";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
	
#pragma endregion
		
	
	
	};
}
