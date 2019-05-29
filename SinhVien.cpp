#include "SinhVien.h"
void SinhVien::outputBanDoc()
{
	cout << "\t\tMa Ban doc    : " << this->sMaBanDoc << endl;
	cout << "\t\tTen Ban doc   : " << this->sHoten << endl;
	cout << "\t\tKhoa          : " << this->sKhoa << endl;
	cout << "\t\tNgay dang ki  : " << setw(2) << setfill('0') << this->xNgayDK.nNgayHT << " - " <<
		setw(2) << setfill('0') << this->xNgayDK.nThangHT << " - " <<
		setw(2) << setfill('0') << this->xNgayDK.nNamHT << endl;
	cout << "\t\tKhoa hoc      : " << this->sKhoahoc << endl;
	
}
void SinhVien::readBanDoc(ifstream &file)
{
	
	rewind(stdin); getline(file, this->sMaBanDoc, '#');
	rewind(stdin); getline(file, this->sHoten, '#');
	rewind(stdin); getline(file, this->sKhoa, '#');
	file >> this->xNgayDK.nNgayHT;
	file.ignore(1);
	file >> this->xNgayDK.nThangHT;
	file.ignore(1);
	file >> this->xNgayDK.nNamHT;
	file.ignore(1);
	rewind(stdin); getline(file, this->sKhoahoc);
	
}
void SinhVien::writeBanDoc(ofstream &file)
{
	file << this->nMaPB << "#" << this->sMaBanDoc << "#" << this->sHoten << "#" << this->sKhoa << "#" << this->xNgayDK.nNgayHT << "#"
		<< this->xNgayDK.nThangHT << "#" << this->xNgayDK.nNamHT << "#" << this->sKhoahoc << endl;
}
