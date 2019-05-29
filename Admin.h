#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Admin
{
protected:
	string sTaikhoan, sMatkhau;
public:
	Admin()
	{
		sTaikhoan = "";
		sMatkhau = "";
	}
	Admin(string sTk, string sMk)
	{
		this->sTaikhoan = sTk;
		this->sMatkhau = sMatkhau;
	}
	string getTaikhoan();
	string getMatkhau();
	void docDSuser(ifstream &file);
	~Admin() {};
};

