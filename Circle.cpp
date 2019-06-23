//---------------------------------------------------------------------------

#pragma hdrstop
#include "Circle.h"
#include "vcl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void Circle::draw(TCanvas *Canvas)
{
	clear(Canvas);
	Canvas->Ellipse(x-draw_R, y-draw_R, x+draw_R, y+draw_R);
}

double Circle::getPerimetr()
{
	return 2*M_PI*draw_R;
}

double Circle::getSquare()
{
	return M_PI*powl(draw_R,2);
}

void Circle::setScale(double sc)
{
	scale = sc;
	draw_R = R * scale;
}

void Circle::set_R(double radius)
{
    draw_R = radius;
}
