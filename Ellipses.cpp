//---------------------------------------------------------------------------

#pragma hdrstop

#include "Ellipses.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Ellipses::draw(TCanvas *Canvas){
	clear(Canvas);
	double angle = 0;
	double range = draw_R;
	do
	{
	double x_n = (draw_R/2) * sin(angle) + x;
	double y_n = (draw_r/2) * cos(angle) + y;
	double x_rot = (x_n - x) * cos(orientation) - (y_n - y) * sin(orientation) + x;
	double y_rot = (x_n - x) * sin(orientation) + (y_n - y) * cos(orientation) + y;
	Canvas->Pixels[x_rot][y_rot] = clBlack;
	angle+=0.05;
	}
	while(angle<=range);
}

double Ellipses::getPerimetr()
{
	return M_PI*(draw_r+draw_R);
}

double Ellipses::getSquare()
{
	return M_PI*draw_R*draw_r;
}

void Ellipses::setScale(double sc)
{
	scale = sc;
	draw_R = R * scale;
	draw_r = r * scale;
}

void Ellipses::rotation(double angle)
{
	orientation = M_PI * angle / 180;
}

void Ellipses::set_r(double radius)
{
	draw_r = radius;
}
