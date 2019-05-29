#include "GiaoVien.h"
void GiaoVien::outputBanDoc() 
{
	cout << "\t\tMa Ban doc    : " << this->sMaBanDoc << endl;
	cout << "\t\tTen Ban doc   : " << this->sHoten << endl;
	cout << "\t\tKhoa          : " << this->sKhoa << endl;
	cout << "\t\tNgay dang ki  : " << setw(2) << setfill('0') << this->xNgayDK.nNgayHT << " - " <<
		setw(2) << setfill('0') << this->xNgayDK.nThangHT << " - " <<
		setw(2) << setfill('0') << this->xNgayDK.nNamHT << endl;
	cout << "\t\tDia chi       : " << this->sDiachi << endl;
	cout << "\t\tSo dien thoai : " << this->sSodienthoai << endl;
};
void GiaoVien::readBanDoc(ifstream &file) 
{

	rewind(stdin); getline(file, sMaBanDoc, '#');
	rewind(stdin); getline(file, sHoten, '#');
	rewind(stdin); getline(file, sKhoa, '#');
	file >> xNgayDK.nNgayHT;
	file.ignore(1);
	file >> xNgayDK.nThangHT;
	file.ignore(1);
	file >> xNgayDK.nNamHT;
	file.ignore(1);
	rewind(stdin); getline(file, sDiachi, '#');
	rewind(stdin); getline(file, sSodienthoai);

};
void GiaoVien::writeBanDoc(ofstream &file)
{
	file << this->nMaPB << "#" << this->sMaBanDoc << "#" << this->sHoten << "#" << this->sKhoa << "#" << this->xNgayDK.nNgayHT << "#"
		<< this->xNgayDK.nThangHT << "#" << this->xNgayDK.nNamHT << "#" << this->sDiachi << "#" << this->sSodienthoai << endl;
}