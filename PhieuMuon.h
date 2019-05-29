#pragma once
#include"Sach.h"
#include"BanDoc.h"
#include"Date.h"
class BanDoc;
class Date;
class Sach;
class PhieuMuon
{
protected:
	Date xNgayMuon, xNgayTra;
	BanDoc xBanDoc;
	Sach xSach;
	static int nTongPM;
	int nMaPM;
	int nTrangThai;
public:
	friend BanDoc;
	friend Date;
	friend Sach;
	/*PhieuMuon()
	{
		this->nTongPM ++;
		this->nMaPM = nTongPM;
		this->nTrangThai = 1;
		this->xNgayTra = tinhNgaytra();
	}*/
	PhieuMuon(string sMaBD, string sMaSach) :xBanDoc(sMaBD), xSach(sMaSach)
	{
		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTrangThai = 1;
		this->xNgayTra = tinhNgaytra();
	}
	PhieuMuon(int nMaPM = 0, string sMaBD = "", string sMaSach = "",
		int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0,
		int nTrangThai = 0) : xBanDoc(sMaBD), xSach(sMaSach), xNgayMuon(a, b, c),
		xNgayTra(d, e, f)
	{

		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTrangThai = nTrangThai;
	}
	string getMaBanDoc()
	{
		return this->xBanDoc.sMaBanDoc;
	}
	string getMaSach()
	{
		return this->xSach.sMasach;
	}
	Date getNgayMuon()
	{
		return this->xNgayMuon;
	}
	Date getNgayTra()
	{
		return this->xNgayTra;

	}
	static int getTongPM()
	{
		return nTongPM;
	}
	int getMaPM()
	{
		return this->nMaPM;
	}
	int getTrangThai();
	void setTrangThai(int nTrangthai);
	void setSach(Sach s);
	void setBanDoc(BanDoc xBD);
	Date& tinhNgaytra();
	void readPM(ifstream &file);
	void writePM(ofstream &file);
	void xuatPM();
	~PhieuMuon() {};
};

