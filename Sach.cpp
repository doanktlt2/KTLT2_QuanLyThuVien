#include "Sach.h"
ostream& operator<<(ofstream&os, Sach&s)
{
	os << s.sMasach << "," << s.sTuade << "," << s.sTacgia << "," << s.sNXB << "," <<
		s.fGiasach << "," << s.nNamPH << "," << s.xNgaynhapkho.getNgay() << "," << s.xNgaynhapkho.getThang() << "," <<
		s.xNgaynhapkho.getNam() << "," << s.nTinhtrangSach;
	return os;
}
void Sach::outputSach()
{
	
	cout << "\t\tMa sach       : " << sMasach << endl;
	cout << "\t\tTua de        : " << sTuade << endl;
	cout << "\t\tTac gia       : " << sTacgia << endl;
	cout << "\t\tNha xuat ban  :" << sNXB << endl;
	cout << "\t\tGia ban       : " << fGiasach << endl;
	cout << "\t\tSo trang      : " << nSotrang << endl;
	cout << "\t\tNam Phat hanh : " << nNamPH;
}
void Sach::writeSach(ofstream &file)
{
	file << this->sMasach << "," << this->sTuade << "," 
		<< this->sTacgia << "," << this->sNXB << ","
		<< this->fGiasach << "," <<this->nSotrang<<","
		<< this->nNamPH << "," << this->xNgaynhapkho.nNgayHT << "-" <<
		this->xNgaynhapkho.nThangHT << "-" <<
		this->xNgaynhapkho.nNamHT << "," <<
		this->nTinhtrangSach << endl;
}
void Sach::readSach(ifstream &file)
{
	rewind(stdin); getline(file, sMasach, ',');
	rewind(stdin); getline(file, sTuade, ',');
	rewind(stdin); getline(file, sTacgia, ',');
	rewind(stdin); getline(file, sNXB, ',');
	file >> fGiasach; file.ignore(1);
	file >> nSotrang; file.ignore(1);
	file >> nNamPH; file.ignore(1);
	file >> xNgaynhapkho.nNgayHT; file.ignore(1);
	file >> xNgaynhapkho.nThangHT; file.ignore(1);
	file >> xNgaynhapkho.nNamHT; file.ignore(1);
	file >> nTinhtrangSach; file.ignore(1);
}
string Sach::getMasach()
{
	return this->sMasach;
}
string Sach::getTieude()
{
	return this->sTuade;
}
string Sach::getTacgia()
{
	return this->sTacgia;
}
string Sach::getNXB()
{
	return this->sNXB;
}
float Sach::getGiaban()
{
	return this->fGiasach;
}
int Sach::getNamPH()
{
	return this->nNamPH;
}
int Sach::getSotrang()
{
	return this->nSotrang;
}
Date Sach::getNgayNhapKho()
{
	return this->xNgaynhapkho;
}
int Sach::getTinhtrang()
{
	return this->nTinhtrangSach;
}
// Cac ham set:
void Sach::setTinhtrangSach(int nTinhtrang)
{
	this->nTinhtrangSach = nTinhtrang;
}