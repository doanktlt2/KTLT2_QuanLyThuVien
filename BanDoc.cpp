#include "BanDoc.h"
string BanDoc::getMaBD()
{
	return this->sMaBanDoc;
}
string BanDoc::getHoten()
{
	return this->sHoten;
}
string BanDoc::getKhoa()
{
	return this->sKhoa;
}
void BanDoc::setMaBD(string sMabandoc)
{
	this->sMaBanDoc = sMabandoc;
}
void BanDoc::setHoten(string sHoten)
{
	this->sHoten = sHoten;
}
void BanDoc::setKhoa(string sKhoa)
{
	this->sKhoa = sKhoa;
}
void BanDoc::setBanDoc(string sMabandoc, string sHoten, string sKhoa)
{
	this->sMaBanDoc = sMabandoc;
	this->sHoten = sHoten; 
	this->sKhoa = sKhoa;
}
