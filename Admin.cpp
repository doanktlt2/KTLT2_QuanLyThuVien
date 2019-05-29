#include "Admin.h"
string Admin::getTaikhoan()
{
	return this->sTaikhoan;
}
string Admin::getMatkhau()
{
	return this->sMatkhau;
}
void Admin::docDSuser(ifstream &file)
{
	rewind(stdin); getline(file, this->sTaikhoan, '#');
	rewind(stdin); getline(file, this->sMatkhau);
	file.ignore(1);
}

