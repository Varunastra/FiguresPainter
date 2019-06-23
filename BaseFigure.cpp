//---------------------------------------------------------------------------

#pragma hdrstop

#include "BaseFigure.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

AnsiString BaseFigure::getCenter()
{
	AnsiString s = FloatToStr(x)+", "+FloatToStr(y);
	return(s);
}

void BaseFigure::setCenter(double x_move, double y_move)
{
	x = x_move;
	y = y_move;
}

void BaseFigure::clear(TCanvas *Canvas)
{
	Canvas->Brush->Color=clWhite;
	Canvas->FillRect(Canvas->ClipRect);
}

double BaseFigure::getScale()
{
    return scale;
}

double BaseFigure::getAngle()
{
	return orientation;
}
