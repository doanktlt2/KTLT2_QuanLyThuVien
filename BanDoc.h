#pragma once
#ifndef BanDoc_h
#define BanDoc_h
#include"Date.h"
class PhieuMuon;
class BanDoc
{
protected:
	string sMaBanDoc, sHoten, sKhoa;
	Date xNgayDK;
public:
	friend PhieuMuon;
	BanDoc()
	{
		this->sMaBanDoc = "";
		this->sHoten = "";
		this->sKhoa = "";
	}
	BanDoc(string sMabandoc)
	{
		this->sMaBanDoc = sMabandoc;
		this->sHoten = "";
		this->sKhoa = "";
	}
	BanDoc(string sMabanDoc, string sHoten, string sKhoa):xNgayDK()
	{
		this->sMaBanDoc = sMabanDoc;
		this->sHoten = sHoten;
		this->sKhoa = sKhoa;
	}
	BanDoc(string sMabanDoc, string sHoten, string sKhoa, int nNgay, int nThang, int nNam) :xNgayDK(nNgay, nThang, nNam)
	{
		this->sMaBanDoc = sMabanDoc;
		this->sHoten = sHoten;
		this->sKhoa = sHoten;
	}
	string getMaBD();
	string getHoten();
	string getKhoa();
	void setMaBD(string sMabandoc);
	void setHoten(string sHoten);
	void setKhoa(string sKhoa);
	void setBanDoc(string sMabandoc, string sHoten, string sKhoa);
	virtual void outputBanDoc() {};
	virtual void readBanDoc(ifstream &file) {};
	virtual void writeBanDoc(ofstream &file) {};
	virtual ~BanDoc() {};
};
#endif // !BanDoc_h
