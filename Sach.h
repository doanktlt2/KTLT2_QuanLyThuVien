#pragma once
#include"Date.h"
class PhieuMuon;
class Sach
{
private:
	string sMasach, sTuade, sTacgia, sNXB;
	float fGiasach;
	int nNamPH, nSotrang, nTinhtrangSach;
	Date xNgaynhapkho;

public:
	friend PhieuMuon;
	Sach()
	{
		this->sMasach = "";
		this->sTuade = "";
		this->sTacgia = "";
		this->sNXB = "";
		this->fGiasach = 0.0;
		this->nNamPH = 0;
		this->nSotrang = 0;
		this->nTinhtrangSach = 0;
	}
	Sach(string sMasach) :xNgaynhapkho()
	{
		this->sMasach = sMasach;
		this->sTuade = "";
		this->sTacgia = "";
		this->sNXB = "";
		this->fGiasach = 0.0;
		this->nNamPH = 0;
		this->nSotrang = 0;
		this->nTinhtrangSach = 0;
	}
	Sach(string sMasach, string sTieude, string sTacgia, string sNXB, float fGia, int nNamPH, int nSotrang, int ntinhtrang, int nNgay, int nThang, int nNam) :xNgaynhapkho(nNgay, nThang, nNam)
	{
		this->sMasach = sMasach;
		this->sTuade = sTieude;
		this->sTacgia = sTacgia;
		this->sNXB = sNXB;
		this->fGiasach = fGia;
		this->nNamPH = nNamPH;
		this->nSotrang = nSotrang;
		this->nTinhtrangSach = ntinhtrang;
	}
	Sach(string sMasach, string sTieude, string sTacgia, string sNXB, float fGia, int nNamPH, int nSotrang) :xNgaynhapkho()
	{
		this->sMasach = sMasach;
		this->sTuade = sTieude;
		this->sTacgia = sTacgia;
		this->sNXB = sNXB;
		this->fGiasach = fGia;
		this->nNamPH = nNamPH;
		this->nSotrang = nSotrang;
		this->nTinhtrangSach = 0;
	}
	string getMasach();
	string getTieude();
	string getTacgia();
	string getNXB();
	float getGiaban();
	int getNamPH();
	int getSotrang();
	Date getNgayNhapKho();
	int getTinhtrang();
	// Cac ham set:
	void setTinhtrangSach(int nTinhtrang);
	friend ostream& operator<<(ofstream&os, Sach&s);
	void outputSach();
	void writeSach(ofstream &file);
	void readSach(ifstream &file);

	~Sach() {};
};

