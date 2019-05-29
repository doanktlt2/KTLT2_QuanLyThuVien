#pragma once
#include "BanDoc.h"
class GiaoVien :
	public BanDoc
{
protected:
	int  nMaPB;
	string sDiachi, sSodienthoai;
public:
	GiaoVien()
	{
		this->sSodienthoai = "";
		this->nMaPB = 0;
		this->sDiachi = "";
	}
	GiaoVien(string sMabandoc, string sTen, string sKhoa, string sDiachi, string sSdt,int nNgay,int nThang,int nNam) :BanDoc(sMabandoc, sTen, sKhoa,nNgay,nThang,nNam)
	{
		this->xNgayDK.nNgayHT = nNgay;
		this->xNgayDK.nThangHT = nThang;
		this->xNgayDK.nNamHT = nNam;
		this->sSodienthoai = sSdt;
		this->sDiachi = sDiachi;
		this->nMaPB = 1;
	}
	GiaoVien(string sMabandoc,string sTen,string sKhoa,string sDiachi,string sSdt):BanDoc(sMabandoc,sTen,sKhoa)
	{
		
		this->sSodienthoai = sSdt;
		this->sDiachi = sDiachi;
		this->nMaPB = 1;
	}
	 void outputBanDoc();
	 void readBanDoc(ifstream &file) ;
	 void writeBanDoc(ofstream &file) ;
	 ~GiaoVien() {};
};

