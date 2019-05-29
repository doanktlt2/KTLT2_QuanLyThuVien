#include "Date.h"
int Date::getNgay()
{
	return this->nThangHT;
}
int Date::getThang()
{
	return this->nThangHT;
}
int Date::getNam()
{
	return this->nNamHT;
}

void Date::setNgay(int nNgay)
{
	this->nNgayHT = nNgay;
}
void Date::setThang(int nThang)
{
	this->nThangHT = nThang;
}
void Date::setNam(int nNam)
{
	this->nNamHT = nNam;
}
void Date::setDate(int nNgay, int nThang, int nNam)
{
	this->nNgayHT = nNgay;
	this->nThangHT = nThang;
	this->nNamHT = nNam;
}
