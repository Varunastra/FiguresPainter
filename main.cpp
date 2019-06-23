//---------------------------------------------------------------------------

#include <vcl.h>
#include <Math.hpp>
#include <math.h>
#pragma hdrstop

#include "main.h"
#include "BaseFigure.h"
#include "Circle.h"
#include "Ellipses.h"
#include "BaseRect.h"
#include "Quadrate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
Circle Cir(200,200,50);
Ellipses Eli(200,200,150,100);
BaseRect Quad(200,200,40,40);
BaseRect Rec(200,200,40,60);
std::string s, st;
double * mas, * center, scale, angle;
bool sw = false;
//---------------------------------------------------------------------------
double* textparse(std::string s)
{
	s.append(", ");
	int startpos = 0; double* mas = new double[2]; int j = 0;
	for(int i = 0; i < s.length(); i++)
	{
	if(s[i] == ',' && s[i+1] == ' ')
	{
	mas[j] = StrToFloat(s.substr(startpos, i - startpos).c_str());
	j++;
	startpos = i + 1;
	}
	}
	return mas;
}

__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	switch(RadioGroup1->ItemIndex)
	{
		case 0:
		switch(ComboBox1->ItemIndex)
		{
		case 0: Edit1->Text=Cir.getCenter().c_str(); break;
		case 1: Edit1->Text=FloatToStr(Cir.getSquare()); break;
		case 2: Edit1->Text=FloatToStr(Cir.getPerimetr()); break;
		case 3:	scale = Cir.getScale(); Timer1->Enabled = true; break;
		case 4: Timer1->Enabled = true; break;
		case 5: Cir.draw(Image1->Canvas); break;
		case 6: break;
        case 11:s = AnsiString(Edit1->Text).c_str(); mas = textparse(s);
				Cir.set_R(mas[0]); Cir.draw(Image1->Canvas);
				break;
		}
		break;

		case 1:
		switch(ComboBox1->ItemIndex)
		{
		case 0: Edit1->Text=Eli.getCenter().c_str(); break;
		case 1: Edit1->Text=FloatToStr(Eli.getSquare()); break;
		case 2: Edit1->Text=FloatToStr(Eli.getPerimetr()); break;
		case 3: scale = Eli.getScale(); Timer1->Enabled=true; break;
		case 4: Timer1->Enabled=true; break;
		case 5: Eli.draw(Image1->Canvas);  break;
		case 6: angle = Eli.getAngle(); Timer1->Enabled = true; break;
		case 7: s = AnsiString(Edit1->Text).c_str(); mas = textparse(s);
				Eli.set_r(mas[0]); Eli.draw(Image1->Canvas);
				break;
		case 11:s = AnsiString(Edit1->Text).c_str(); mas = textparse(s);
				Eli.set_R(mas[0]); Eli.draw(Image1->Canvas);
				break;
		}
		break;

		case 2:
		switch(ComboBox1->ItemIndex)
		{
			case 0: Edit1->Text=Rec.getCenter().c_str(); break;
			case 1: Edit1->Text=FloatToStr(Rec.getSquare()); break;
			case 2: Edit1->Text=FloatToStr(Rec.getPerimetr()); break;
			case 3: scale = Rec.getScale(); Timer1->Enabled = true; break;
			case 4: Timer1->Enabled = true; break;
			case 5: Rec.draw(Image1->Canvas);  break;
			case 6: angle = Rec.getAngle(); Timer1->Enabled = true; break;
			case 8: s = AnsiString(Edit1->Text).c_str(); mas = textparse(s);
					Rec.setWidth(mas[0]); Rec.draw(Image1->Canvas);
					break;
			case 9: s = AnsiString(Edit1->Text).c_str(); mas = textparse(s);
					Rec.setHeight(mas[0]); Rec.draw(Image1->Canvas);
					break;
			case 10:s = AnsiString(Edit1->Text).c_str(); mas = textparse(s);
					Quad.setCoord(mas[0], mas[1], mas[2], mas[3], mas[4], mas[5], mas[6], mas[7]);
				    Quad.draw(Image1->Canvas);
					break;
		}
		break;

		case 3:
		switch(ComboBox1->ItemIndex)
		{
			case 0: Edit1->Text=Quad.getCenter().c_str(); break;
			case 1: Edit1->Text=FloatToStr(Quad.getSquare()); break;
			case 2: Edit1->Text=FloatToStr(Quad.getPerimetr()); break;
			case 3: scale = Quad.getScale(); Timer1->Enabled=true; break;
			case 4: Timer1->Enabled = true; break;
			case 5: Quad.draw(Image1->Canvas); break;
			case 6: angle = Quad.getAngle(); Timer1->Enabled = true; break;
			case 8: s = AnsiString(Edit1->Text).c_str(); mas = textparse(s);
					Quad.setWidth(mas[0]); Quad.draw(Image1->Canvas);
					break;
			case 10:s = AnsiString(Edit1->Text).c_str(); mas = textparse(s);
					Quad.setCoord(mas[0], mas[1], mas[2], mas[3], mas[4], mas[5], mas[6], mas[7]);
				    Quad.draw(Image1->Canvas);
					break;
		}
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ComboBox1Select(TObject *Sender)
{
	switch(ComboBox1->ItemIndex)
	{
		case 0: Label1->Caption="Center is (x, y):"; Edit1->Visible = true; break;
		case 1: Label1->Caption="Square is:"; Edit1->Visible = true; break;
		case 2: Label1->Caption="Perimetr is:"; Edit1->Visible = true; break;
		case 3: Label1->Caption="Enter the scale below"; Edit1->Visible = true; break;
		case 4: Label1->Caption="Enter coordinates(x, y)";	Edit1->Visible = true; break;
		case 5: Label1->Caption="Click Action to apply"; Edit1->Visible = false; break;
		case 6: Label1->Caption="Enter angle below(deg)"; Edit1->Visible = true; break;
		case 7: Label1->Caption="Enter r below"; Edit1->Visible = true; break;
		case 8: Label1->Caption="Enter width below"; Edit1->Visible = true; break;
		case 9: Label1->Caption="Enter height below"; Edit1->Visible = true; break;
		case 10: Label1->Caption="Enter (x1, y1, x2, y2, x3, y3, x4, y4)"; Edit1->Visible = true; break;
		case 11: Label1->Caption="Enter R below"; Edit1->Visible = true; break;
	}

}
//---------------------------------------------------------------------------
				   
void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
	switch (RadioGroup1->ItemIndex)
	{
		case 0:
		switch(ComboBox1->ItemIndex)
		{
			case 3:
					s = AnsiString(Edit1->Text).c_str();
					mas = textparse(s);
					if(scale <= mas[0])
					sw = true;
					if(scale <= mas[0] && sw == true)
					{
						Cir.setScale(scale);
						Cir.draw(Image1->Canvas);
						scale += 0.02;
					}
					else if(sw == false)
					{
						Cir.setScale(scale);
						Cir.draw(Image1->Canvas);
						scale -= 0.02;
					}
					else
					{
						Timer1->Enabled = false;
						sw = false;
					}
			break;
			case 4: s = AnsiString(Edit1->Text).c_str();
					mas = textparse(s);
					st = Cir.getCenter().c_str();
					center = textparse(st);
					if (center[0] <= mas[0] && center[1] <= mas[1])
					sw = true;
					if(center[0] <= mas[0] && sw == true && center[1] <= mas[1])
					{
						center[0] += 1;
						center[1] += 1;
						Cir.setCenter(center[0], center[1]);
						Cir.draw(Image1->Canvas);
					}
					else if (sw == false && center[0] >= mas[0] && center[1] >= mas[1])
					{
						center[0] -= 1;
						center[1] -= 1;
						Cir.setCenter(center[0], center[1]);
						Cir.draw(Image1->Canvas);
					}
					else
					{
						Timer1->Enabled = false;
						sw = false;
					}
			break;
		}
		break;

		case 1:
		switch(ComboBox1->ItemIndex)
		{
					case 3: 
					s = AnsiString(Edit1->Text).c_str();
					mas = textparse(s);
					if(scale <= mas[0])
					sw = true;
					if(scale <= mas[0] && sw == true)
					{
						Eli.setScale(scale);
						Eli.draw(Image1->Canvas);
						scale += 0.05;
					}
					else if(sw == false)
					{
						Eli.setScale(scale);
						Eli.draw(Image1->Canvas);
						scale -= 0.05;
					}
					else
					{
						Timer1->Enabled = false;
						sw = false;
					}
					break;

					case 4:
					s = AnsiString(Edit1->Text).c_str();
					mas = textparse(s);
					st = Eli.getCenter().c_str();
					center = textparse(st);
					if (center[0] <= mas[0] && center[1] <= mas[1])
					sw = true;
					if(center[0] <= mas[0] && sw == true && center[1] <= mas[1])
					{
						center[0] += 1;
						center[1] += 1;
						Eli.setCenter(center[0], center[1]);
						Eli.draw(Image1->Canvas);
					}
					else if (sw == false && center[0] >= mas[0] && center[1] >= mas[1])
					{
						center[0] -= 1;
						center[1] -= 1;
						Eli.setCenter(center[0], center[1]);
						Eli.draw(Image1->Canvas);
					}
					else
					{
						Timer1->Enabled = false;
						sw = false;
					}
					break;

					case 6: s = AnsiString(Edit1->Text).c_str();
					mas = textparse(s);
					if(angle <= mas[0])
					sw = true;
					if(angle <= mas[0] && sw == true)
					{
						Eli.rotation(angle);
						Eli.draw(Image1->Canvas);
						angle += 1;
					}
					else if(sw == false)
					{
						Eli.rotation(angle);
						Eli.draw(Image1->Canvas);
						angle -= 1;
					}
					else
					{
						Timer1->Enabled = false;
						sw = false;
					}
					break;
		}
		break;

		case 2:
		switch(ComboBox1->ItemIndex)
		{
			case 3: s = AnsiString(Edit1->Text).c_str();
					mas = textparse(s);
					if(scale <= mas[0])
					sw = true;
					if(scale <= mas[0] && sw == true)
					{
						Rec.setScale(scale);
						Rec.draw(Image1->Canvas);
						scale += 0.02;
					}
					else if(sw == false)
					{
						Rec.setScale(scale);
						Rec.draw(Image1->Canvas);
						scale -= 0.02;
					}
					else
					{
						Timer1->Enabled = false;
						sw = false;
					}
					break;
					case 4:
					s = AnsiString(Edit1->Text).c_str();
					mas = textparse(s);
					st = Rec.getCenter().c_str();
					center = textparse(st);
					if (center[0] <= mas[0] && center[1] <= mas[1])
					sw = true;
					if(center[0] <= mas[0] && sw == true && center[1] <= mas[1])
					{
						center[0] += 1;
						center[1] += 1;
						Rec.setCenter(center[0], center[1]);
						Rec.draw(Image1->Canvas);
					}
					else if (sw == false && center[0] >= mas[0] && center[1] >= mas[1])
					{
						center[0] -= 1;
						center[1] -= 1;
						Rec.setCenter(center[0], center[1]);
						Rec.draw(Image1->Canvas);
					}
					else
					{
						Timer1->Enabled = false;
						sw = false;
					}
			break;

			case 6: s = AnsiString(Edit1->Text).c_str();
					mas = textparse(s);
					if(angle <= mas[0])
					sw = true;
					if(angle <= mas[0] && sw == true)
					{
						Rec.rotation(angle);
						Rec.draw(Image1->Canvas);
						angle += 1;
					}
					else if(sw == false)
					{
						Rec.rotation(angle);
						Rec.draw(Image1->Canvas);
						angle -= 1;
					}
					else
					{
						Timer1->Enabled = false;
						sw = false;
					}
					break;
		}
		break;

		case 3:
		switch(ComboBox1->ItemIndex)
		{
					case 3:
					s = AnsiString(Edit1->Text).c_str();
					mas = textparse(s);
					if(scale <= mas[0])
					sw = true;
					if(scale <= mas[0] && sw == true)
					{
						Quad.setScale(scale);
						Quad.draw(Image1->Canvas);
						scale += 0.02;
					}
					else if(sw == false)
					{
						Quad.setScale(scale);
						Quad.draw(Image1->Canvas);
						scale -= 0.02;
					}
					else
					{
						Timer1->Enabled = false;
						sw = false;
					}
					break;
					case 4:
					s = AnsiString(Edit1->Text).c_str();
					mas = textparse(s);
					st = Quad.getCenter().c_str();
					center = textparse(st);
					if (center[0] <= mas[0] && center[1] <= mas[1])
					sw = true;
					if(center[0] <= mas[0] && sw == true && center[1] <= mas[1])
					{
						center[0] += 1;
						center[1] += 1;
						Quad.setCenter(center[0], center[1]);
						Quad.draw(Image1->Canvas);
					}
					else if (sw == false && center[0] >= mas[0] && center[1] >= mas[1])
					{
						center[0] -= 1;
						center[1] -= 1;
						Quad.setCenter(center[0], center[1]);
						Quad.draw(Image1->Canvas);
					}
					else
					{
						Timer1->Enabled = false;
						sw = false;
					}
			break;

			case 6: s = AnsiString(Edit1->Text).c_str();
					mas = textparse(s);
					if(angle <= mas[0])
					sw = true;
					if(angle <= mas[0] && sw == true)
					{
						Quad.rotation(angle);
						Quad.draw(Image1->Canvas);
						angle += 1;
					}
					else if(sw == false)
					{
						Quad.rotation(angle);
						Quad.draw(Image1->Canvas);
						angle -= 1;
					}
					else
					{
						Timer1->Enabled = false;
						sw = false;
					}
					break;

		}
		break;

		default: break;
	}
}
//---------------------------------------------------------------------------
