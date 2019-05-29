#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<iomanip>
#include<vector>
#include<Windows.h>
#include <iomanip>
#include<conio.h>
using namespace std;
class PhieuMuon;
class Sach;
class BanDoc;
class GiaoVien;
class SinhVien;
class Date
{
private:
	int nNgayHT, nThangHT, nNamHT;
public:
	friend PhieuMuon;
	friend GiaoVien;
	friend Sach;
	friend BanDoc;
	friend SinhVien;
	Date()
	{
		errno_t err;
		struct tm time_info;
		time_t time_create = time(NULL);
		localtime_s(&time_info, &time_create);
		char timebuf[26];
		nNgayHT = time_info.tm_mday;
		nThangHT = time_info.tm_mon+1;
		nNamHT = time_info.tm_year+1900;
	}
	Date(int nNgay, int nThang, int nNam)
	{
		this->nNgayHT = nNgay;
		this->nThangHT = nThang;
		this->nNamHT = nNam;
	}
	int getNgay();
	int getThang();
	int getNam();

	void setNgay(int nNgay);
	void setThang(int nThang);
	void setNam(int nNam);
	void setDate(int nNgay, int nThang, int nNam);
	~Date() {};
};