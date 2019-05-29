#include "PhieuMuon.h"
void PhieuMuon::readPM(ifstream &file)
{
	file >> this->nMaPM; file.ignore(1);
	rewind(stdin);
	getline(file, this->xBanDoc.sMaBanDoc, ',');
	rewind(stdin);
	getline(file, this->xSach.sMasach, ',');
	file >> this->xNgayMuon.nNgayHT; file.ignore(1);
	file >> this->xNgayMuon.nThangHT; file.ignore(1);
	file >> this->xNgayMuon.nNamHT; file.ignore(1);
	file >> this->xNgayTra.nNgayHT; file.ignore(1);
	file >> this->xNgayTra.nThangHT; file.ignore(1);
	file >> this->xNgayTra.nNamHT; file.ignore(1);
	file >> this->nTrangThai; file.ignore(1);
}
void PhieuMuon::writePM(ofstream &file)
{
	file << this->nMaPM << "," <<
		this->xBanDoc.sMaBanDoc << "," <<
		this->xSach.sMasach << "," <<
		xNgayMuon.nNgayHT << "," <<
		xNgayMuon.nThangHT << "," <<
		xNgayMuon.nNamHT << "," <<
		xNgayTra.nNgayHT << "," <<
		xNgayTra.nThangHT << "," <<
		xNgayTra.nNamHT << "," <<
		this->nTrangThai << endl;
}
void PhieuMuon::xuatPM()
{
	cout << "\t\t<So PM>      : " << this->nMaPM << endl;
	cout << "\t\t<Ma Ban doc> : " << this->xBanDoc.sMaBanDoc << endl;
	cout << "\t\t<Ma Sach>    : " << this->xSach.sMasach << endl;
	cout << "\t\t<Ngay Muon>  : " <<
		setw(2) << setfill('0') << this->xNgayMuon.nNgayHT << " - " <<
		setw(2) << setfill('0') << this->xNgayMuon.nThangHT << " - " <<
		setw(2) << setfill('0') << this->xNgayMuon.nNamHT << endl;
	cout << "\t\t<Ngay Tra>   : " <<
		setw(2) << setfill('0') << this->xNgayTra.nNgayHT << " - " <<
		setw(2) << setfill('0') << this->xNgayTra.nThangHT << " - " <<
		setw(2) << setfill('0') << this->xNgayTra.nNamHT << endl;
	cout << "\t\t<Tinh trang> : " << this->nTrangThai << endl;
}
Date& PhieuMuon::tinhNgaytra()
{
	int nNgay = xNgayMuon.nNgayHT + 7;
	switch (xNgayMuon.nThangHT)
	{
	case 1 :case 3:case 5:case 7:case 8:case 10:case 12: // Co 31 ngay
	{
		
		if (nNgay>31)
		{
			xNgayTra.nNgayHT = nNgay - 31;
			xNgayTra.nThangHT++;
		}
		break;
	}
	case 4:case 6:case 9:case 11: // Có 30 ngày
	{
		
		if (nNgay > 30)
		{
			xNgayTra.nNgayHT = nNgay - 30;
			xNgayTra.nThangHT++;
		}
		break;
	}
	default:
		if (xNgayMuon.nNamHT%400==0|| xNgayMuon.nNamHT%4==0&& xNgayMuon.nNamHT%100!=0)
		{
			
			if (nNgay > 28)
			{
				xNgayTra.nNgayHT = nNgay - 28;
				xNgayTra.nThangHT++;
			}
			break;
		}

		else
		{
			
			if (nNgay> 29)
			{
				xNgayTra.nNgayHT = nNgay - 29;
				xNgayTra.nThangHT++;
			}
		}
		break;
	}
	return xNgayTra;
}
int PhieuMuon::getTrangThai()
{
	return this->nTrangThai;
}
void PhieuMuon::setTrangThai(int nTrangthai)
{
	this->nTrangThai = nTrangthai;
}
void PhieuMuon::setSach(Sach s)
{
	this->xSach = s;
}
void PhieuMuon::setBanDoc(BanDoc xBD)
{
	this->xBanDoc = xBD;
}