#pragma once
#include "BanDoc.h"
class SinhVien :
	public BanDoc
{
protected:
	string sKhoahoc;
	int nMaPB;
public:
	SinhVien()
	{
		this->sKhoahoc = "";
		this->nMaPB = 2;
	}
	SinhVien(string sMabandoc, string sTen, string sKhoa, string sKhoahoc, int nNgay, int nThang, int nNam):BanDoc(sMabandoc, sTen, sKhoa, nNgay, nThang, nNam)
	{
		this->sKhoahoc = sKhoahoc;
		this->nMaPB = 2;
	}
	SinhVien(string sMabandoc, string sTen, string sKhoa, string sKhoahoc) :BanDoc(sMabandoc, sTen, sKhoa)
	{

		this->sKhoahoc = sKhoahoc;
		this->nMaPB = 2;
	}
	void outputBanDoc();
	void readBanDoc(ifstream &file);
	void writeBanDoc(ofstream &file);
	~SinhVien() {};
};

