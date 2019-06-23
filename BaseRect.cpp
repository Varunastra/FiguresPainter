//---------------------------------------------------------------------------

#pragma hdrstop

#include "BaseRect.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void BaseRect::draw(TCanvas *Canvas)
{
	x1_save = (x1 - x) * cos(orientation) - (y1 - y) * sin(orientation) + x;
	y1_save = (x1 - x) * sin(orientation) + (y1 - y) * cos(orientation) + y;
	x2_save = (x2 - x) * cos(orientation) - (y2 - y) * sin(orientation) + x;
	y2_save = (x2 - x) * sin(orientation) + (y2 - y) * cos(orientation) + y;
	x3_save = (x3 - x) * cos(orientation) - (y3 - y) * sin(orientation) + x;
	y3_save = (x3 - x) * sin(orientation) + (y3 - y) * cos(orientation) + y;
	x4_save = (x4 - x) * cos(orientation) - (y4 - y) * sin(orientation) + x;
	y4_save = (x4 - x) * sin(orientation) + (y4 - y) * cos(orientation) + y;
	TPoint points[4];
	points[0] = Point(x1_save, y1_save);
	points[1] = Point(x2_save, y2_save);
	points[2] = Point(x3_save, y3_save);
	points[3] = Point(x4_save, y4_save);
	clear(Canvas);
	Canvas->Polygon(points, 3);
}

double BaseRect::getSquare()
{
	return scaled_width * scaled_height;
}

double BaseRect::getPerimetr()
{
	return (scaled_width + scaled_height) * 2;
}

void BaseRect::setScale(double sc)
{
	scale = sc;
	scaled_width = width * scale;
	scaled_height = height * scale;
	calculations();
}

void BaseRect::calculations()
{
	x1 = x - scaled_width / 2;
	y1 = y - scaled_height / 2;
	x2 = x + scaled_width / 2;
	y2 = y - scaled_height / 2;
	x3 = x + scaled_width / 2;
	y3 = y + scaled_height / 2;
	x4 = x - scaled_width / 2;
	y4 = y + scaled_height / 2;
}

void BaseRect::rotation(double angle)
{
	angle = angle * M_PI / 180;
	orientation = angle;
	setScale(scale);
}

void BaseRect::setCenter(double x_move, double y_move)
{
	x = x_move;
	y = y_move;
    setScale(scale);
}

void BaseRect::setHeight(double h)
{
	height = h;
	setScale(scale);
}

void BaseRect::setWidth(double w)
{
	width = w;
	setScale(scale);
}

void BaseRect::setCoord(double xc1, double yc1, double xc2, double yc2, double xc3, double yc3, double xc4, double yc4)
{
	x1_save = xc1;
	y1_save = yc1;
	x2_save = xc2;
	y2_save = yc2;
	x3_save = xc3;
	y3_save = yc3;
	x4_save = xc4;
	y4_save = yc4;
}
