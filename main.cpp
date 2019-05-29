/*	Đồ án KTLT2 :
	Project : Quản lý Thư viện

- Thành viên :
		Võ Minh Tiến ( Nhóm trưởng )
		Lê Hoài Thương
 */
#include"Sach.h"
#include"GiaoVien.h"
#include"SinhVien.h"
#include"Admin.h"
#include"PhieuMuon.h"
using namespace std;
int PhieuMuon::nTongPM = 0;
//
void textcolor(WORD color);
string chuanhoaPass(string mk);
bool kTraMaSach(vector<Sach> S, string sMasach);
bool kTraMaBandoc(vector<BanDoc*> xBd, string sMaBD);
bool kTraMaPM(vector<PhieuMuon> dsPM, int nX);
int kTra_Vtri_Sach_DeTra(vector<Sach> S, string sMasach);
// Vieen Thong bao
void Menu();
void timkiemTT();
void Quanly();
void quanLyPM();
void quanLySach();
void quanLyBD();
void Thongke();
//phieu muon
void docDSPM(vector<PhieuMuon> &dsPM);
void ghiDSPM(vector<PhieuMuon> dsPM);
void xuatDSPM(vector<PhieuMuon> dsPM);
void taoPM(vector<PhieuMuon> &dsPM, vector<Sach> &S, vector<BanDoc*> xBd);
void traSach(vector<PhieuMuon> &dsPM, vector<Sach>&S);
//Sach
void hienThiTTSach(vector<Sach> S);
void docDSsach(vector<Sach> &S);
void ghiDSsach(vector<Sach> S);
void CN_hienThiSachtheoTuade(vector<Sach>S);
void themSach(vector<Sach> &S);
void xoaSach(vector<Sach> &S);
// Ban doc
void readDSBD(vector<BanDoc*> &Bandoc);
void ghiDSBanDoc(vector<BanDoc*> Bandoc);
void xuatDSBanDoc(vector<BanDoc*> Bandoc);
void hienthiDSBanDoc_theoMaBD(vector<BanDoc*> Bd);
void themBanDoc(vector<BanDoc*> &xBd);
//Thong ke :
void Thongke_TongsoSach(vector<Sach> S);
void Thongke_TongsoSach_Muon(vector<Sach> S);
void Lietke_Sachdang_Muon(vector<Sach> S, vector<PhieuMuon> dsPM);
//Admin :
void docDSAD(vector<Admin> &Ad);
bool Login(vector<Admin> Ad);
//Chuc nang :
void CN_TimkiemTT(vector<Sach> S, vector<BanDoc*> xBd);
void CN_Quanly(vector<Sach> &S, vector<BanDoc*> &xBd, vector<PhieuMuon> &dsPM, vector<Admin> Ad);
void main()
{
	int nLuachon = 0;
	bool bFlag = 0;
	vector<BanDoc*> Bandoc;
	vector<Sach> S;
	vector<PhieuMuon> PM;
	vector<Admin> Ad;
	readDSBD(Bandoc);
	docDSsach(S);
	docDSPM(PM);
	docDSAD(Ad);
	do
	{
	cc: {Menu();
	dd: {	textcolor(9);
		cout << "\t\t\tNhap Lua chon : "; cin >> nLuachon; } }
		switch (nLuachon)
		{
		case 1:
		{
			hienThiTTSach(S);
			system("pause");
			system("cls");
			goto cc;
		}
		case 2:
		{
			CN_TimkiemTT(S, Bandoc);
			system("pause");
			system("cls");
			goto cc;

		}
		case 3:
		{
			if (Login(Ad)==1)
			{
				CN_Quanly(S, Bandoc, PM, Ad);
				system("pause");
				system("cls");
				goto cc;
			}
			else
			{
				textcolor(12);
				cout << "\t\tThong tin Tai khoan hoac Mat khau khong chinh xac. Vui long kiem tra lai!\n";
				system("pause");
				system("cls");
				goto cc;
			}
			
		}
		case 4:
		{
			break;
			bFlag = 1;
		}
		}
	} while (bFlag=0);


	system("pause");
}
// Chuc nang :
void CN_Quanly(vector<Sach> &S, vector<BanDoc*> &xBd, vector<PhieuMuon> &dsPM, vector<Admin> Ad)
{
	int nLuachon = 0;
	int nChonCNcon = 0;
	int nChonCNsach = 0;
	int nChonCNBD = 0;
	int nChonCNTK = 0;
	bool bFlag = 0;
	do
	{
	cc: {system("cls");
		Quanly();
		textcolor(83);
		cout << "\t\t\tNhap lua chon : "; cin >> nLuachon; }
		switch (nLuachon)
		{
		case 1:
		{
		dd: {system("cls");
			quanLyPM();
			textcolor(83);
			cout << "\t\t\tNhap lua chon : "; cin >> nChonCNcon; }
			if (nChonCNcon == 1)
			{
				taoPM(dsPM, S, xBd);
				system("pause");
				goto dd;
			}
			else if (nChonCNcon == 2)
			{
				traSach(dsPM, S);
				system("pause");
				goto dd;
			}
			else
			{
				break;
			}
		}
		case 2:
		{ee: {system("cls");
		quanLySach();
		textcolor(83);
		cout << "\t\t\tNhap lua chon : "; cin >> nChonCNsach; }
		if (nChonCNsach == 1)
		{
			themSach(S);
			system("pause");
			goto ee;
		}
		else if (nChonCNsach == 2)
		{
			xoaSach(S);
			system("pause");
			goto ee;
		}
		else
		{
			break;
		}
		}
		case 3:
		{
		ff: {system("cls");
			quanLyBD();
			textcolor(83);
			cout << "\t\t\tNhap lua chon : "; cin >> nChonCNBD; }
			if (nChonCNBD == 1)
			{
				themBanDoc(xBd);
				system("pause");
				goto ff;
			}
			else if (nChonCNBD == 2)
			{
				xuatDSBanDoc(xBd);
				system("pause");
				goto ff;
			}
			else
			{
				break;
			}
		}
		case 4:
		{
		gg:
			{system("cls");
			Thongke();
			textcolor(83);
			cout << "\t\t\tNhap lua chon : "; cin >> nChonCNTK; }
			if (nChonCNTK == 1)
			{
				Thongke_TongsoSach(S);
				system("pause");
				goto gg;
			}
			else if (nChonCNTK == 2)
			{
				Thongke_TongsoSach_Muon(S);
				system("pause");
				goto gg;
			}
			else if (nChonCNTK == 3)
			{
				Lietke_Sachdang_Muon(S, dsPM);
				system("pause");
				goto gg;
			}
			else
			{
				break;
			}
		}
		case 5:
		{
			break;
			bFlag = 1;
		}
		if (bFlag = 1)
		{
			break;
		}
		}
	} while (nLuachon>=1&&nLuachon<5);
}
void CN_TimkiemTT(vector<Sach> S, vector<BanDoc*> xBd)
{
	int nLuachon = 0;
	bool bFlag = 0;
	do
	{
	cc: {system("cls");
		timkiemTT();
		textcolor(83);
		cout << "\t\t\tNhap lua chon : "; cin >> nLuachon; }
		switch (nLuachon)
		{
		case 1:
		{
			CN_hienThiSachtheoTuade(S);
			system("pause");
			goto cc;
		}
		case 2:
		{
			hienthiDSBanDoc_theoMaBD(xBd);
			system("pause");
			goto cc;
		}
		case 3:
			break;
			bFlag = 1;
		}
		if (bFlag=1)
		{
			break;
		}
	} while (nLuachon>=1&&nLuachon<=3);

}
//Thong ke
void Thongke_TongsoSach(vector<Sach> S)
{
	textcolor(11);
	cout << "\t\t\tTong so Sach con lai trong thu vien : " << S.size() << endl;
}
void Thongke_TongsoSach_Muon(vector<Sach> S)
{
	int nCount = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhtrang()!=0)
		{
			nCount++;
		}
	}
	textcolor(11);
	cout << "\t\t\tTong so Sach dang duoc muon : " << nCount << endl;
}
void Lietke_Sachdang_Muon(vector<Sach> S, vector<PhieuMuon> dsPM)
{
	string sMaBD = "";
	bool bFlag = 0;
cc: {textcolor(11);
	cout << "\t\t\tNhap Ma BD : "; rewind(stdin); getline(cin, sMaBD); }
	for (int i = 0; i < dsPM.size(); i++)
	{
		if (dsPM[i].getMaBanDoc()==sMaBD&&dsPM[i].getTrangThai()==1)
		{
			bFlag = 1;
			for (int j = 0; j < S.size(); j++)
			{
				if (S[j].getMasach()==dsPM[i].getMaSach())
				{
					S[j].outputSach();
					cout << endl;
					cout << "\t-----------------------------------------------\n";
					
				}
			}
		}
	}
	if (bFlag==0)
	{
		system("cls");
		Thongke();
		textcolor(12);
		cout << "\t\tMa ban doc nay khong ton tai hoac chua muon Sach. Vui long nhap lai !\n";
		goto cc;
	}
}
//Admin
void docDSAD(vector<Admin> &Ad)
{
	int nN = 0;
	ifstream file;
	file.open("Admin.txt");
	file >> nN;
	file.ignore(1);
	for (int i = 0; i < nN; i++)
	{
		Admin ad;
		ad.docDSuser(file);
		Ad.push_back(ad);
	}
	file.close();
}
string chuanhoaPass(string mk)
{
	string sPass = "";
	char ch;
	int dem = 0;
	char pass[10];
	while ((ch = _getch()) != 13) {
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9')) {
			printf("*");
			pass[dem++] = ch;
			sPass.push_back(ch);


		}
		else
			if (ch == 8)
				if (dem > 0) {
					printf("\b \b");
					dem--;
				}
		if (ch == '\n')
		{
			break;
		}
	}
	pass[dem] = 0;
	return sPass;
}
bool Login(vector<Admin> Ad)
{
	string sUser, sPass, a;
	bool bFlag = 0;
	textcolor(10);
	cout << "\t\t\tNhap User     : "; rewind(stdin); getline(cin, sUser);
	textcolor(10);
	cout << "\t\t\tNhap Password : ";
	sPass = chuanhoaPass(a);
	for (int i = 0; i < Ad.size();i++)
	{
		if (Ad[i].getTaikhoan()!=sUser&&Ad[i].getMatkhau()!=sPass)
		{
			
			bFlag = 0;
		}
	}
	bFlag = 1;
	cout << endl;
	return bFlag;
}
// Phieu muon
void docDSPM(vector<PhieuMuon> &dsPM)
{
	int nN = 0;
	ifstream file;
	file.open("PhieuMuon.txt");
	file >> nN;
	file.ignore(1);
	if (file.is_open()==true)
	{
		cout << "ok";
	}
	for (int i = 0; i < nN; i++)
	{
		PhieuMuon pm;
		pm.readPM(file);
		dsPM.push_back(pm);
	}
	file.close();
}
void ghiDSPM(vector<PhieuMuon> dsPM)
{
	ofstream file;
	file.open("PhieuMuon.txt", ios::out);
	file << dsPM.size();
	file << endl;
	for (int i = 0; i < dsPM.size(); i++)
	{
		dsPM[i].writePM(file);
	}
	file.close();

}
void xuatDSPM(vector<PhieuMuon> dsPM)
{
	for (int i = 0; i < dsPM.size(); i++)
	{
		dsPM[i].xuatPM();
		cout << "\n\t\t-------------------------------------\n";
	}
}
void taoPM(vector<PhieuMuon> &dsPM, vector<Sach> &S, vector<BanDoc*> xBd)
{
	string sMaBD = "";
	string sMaSach = "";
	int nTTPM = 0;
	bool bFlag = 0;
	string sLuachon = "";
	do
	{
	cc: {	textcolor(11);
	cout << "\t\t\tNhap ma Ban doc : ";
		rewind(stdin);
		getline(cin, sMaBD); }
		if (sMaBD=="N")
		{
			break;
		}
		if (kTraMaBandoc(xBd, sMaBD) == true)
		{
			bFlag = 1;
			while (true)
			{
			aa: {textcolor(11);
				cout << "\t\t\tNhap ma Sach : ";
				rewind(stdin);
				getline(cin, sMaSach); }
				if (sMaSach=="N")
				{
					break;
				}
				if (kTraMaSach(S, sMaSach) == true)
				{
					textcolor(13);
					cout << "\t\t\tMuon sach thanh cong !\n";
					PhieuMuon pm(sMaBD, sMaSach);
					dsPM.push_back(pm);
					ghiDSPM(dsPM);
					break;
				}
				else
				{
					textcolor(12);					
					system("cls");
					quanLyPM();
					cout << "\t\tMa sach nay khong ton tai hoac dang duoc muon. Xin moi nhap lai hoac nhap (N) de thoat!\n";
					goto aa;
				}
			}
		}
		else
		{
			textcolor(12);		
			system("cls");
			quanLyPM();
			cout << "\t\t\tMa Ban doc nay khong ton tai. Xin moi nhap lai hoac nhap (N) de thoat!\n";
			goto cc;
		}
	} while (bFlag=0);
	for (int i = 0; i < S.size(); i++)
	{
		int nTongPM1 = dsPM.size();
		if (S[i].getMasach() == sMaSach)
		{
			S[i].setTinhtrangSach(nTongPM1);
			ghiDSsach(S);
		}
	}
}
void traSach(vector<PhieuMuon> &dsPM, vector<Sach>&S)
{
	
	int nMaPM = 0;
	bool bFlag = 0;
	do
	{
	cc: {	
		textcolor(11);
		cout << "\t\t\tNhap So phieu muon : "; cin >> nMaPM; }
		if (nMaPM == -1)
		{
			break;
		}
		for (int i = 0; i < dsPM.size(); i++)
		{
			if(dsPM[i].getMaPM()==nMaPM&&dsPM[i].getTrangThai()==1)
			{
				bFlag = 1;
				dsPM[i].setTrangThai(0);
				int nKq = kTra_Vtri_Sach_DeTra(S, dsPM[i].getMaSach());
				S[nKq].setTinhtrangSach(0);
				ghiDSPM(dsPM);
				ghiDSsach(S);
				textcolor(12);
				cout << "\t\tTra Sach thanh cong! \n";
				break;
			}
		}
		if (bFlag==0)
		{
			system("cls");
			quanLyPM();
			textcolor(12);
			cout << "\t\tSo Phieu muon khong ton tai. Xin vui long nhap lai hoac nhap (-1) de thoat !\n ";
			goto cc;
		}
	} while (bFlag==0);
}
// Ban Doc :
void themBanDoc(vector<BanDoc*> &xBd)
{
	int nPB = 0;
	string sMaBD="";
	string sTen = "";
	string sKhoa = " ";
	string sKhoahoc = " ";
	string sDiachi = "";
	string sSdt = "";
cc: {textcolor(11);
	cout << "\t\t\tNhap Ma BD can them : "; rewind(stdin); getline(cin, sMaBD); }
	for (int i = 0; i < xBd.size(); i++)
	{
		if (xBd[i]->getMaBD()==sMaBD)
		{
			system("cls");
			quanLyBD();
			textcolor(12);
			cout << "\t\tMa ban doc nay da ton tai. Vui long nhap lai !\n";
			goto cc;
		}
	}
	textcolor(11);
	cout << "\t\t\tNhap Ten BD         : "; rewind(stdin); getline(cin, sTen);
	cout << "\t\t\tNhap Khoa           : "; rewind(stdin); getline(cin, sKhoa);
	cout << "\t\t\tNhap ma phan biet   : "; cin >> nPB;
	if (nPB==1)
	{
		cout << "\t\t\tNhap dia chi        : "; rewind(stdin); getline(cin, sDiachi);
		cout << "\t\t\tNhap SDT            : "; rewind(stdin); getline(cin, sSdt);
		textcolor(12);
		cout << "\t\tThem ban doc thanh cong !\n";
		BanDoc *gv = new GiaoVien(sMaBD, sTen, sKhoa, sDiachi, sSdt);
		xBd.push_back(gv);
		ghiDSBanDoc(xBd);
	}
	else
	{
		cout << "\t\t\tNhap Khoa hoc   : "; rewind(stdin); getline(cin, sKhoahoc);
		BanDoc *sv = new SinhVien(sMaBD, sTen, sKhoa, sKhoahoc);
		xBd.push_back(sv);
		ghiDSBanDoc(xBd);
		textcolor(12);
		cout << "\t\tThem ban doc thanh cong !\n";
	}
}
void readDSBD(vector<BanDoc*> &Bandoc)
{
	int nNum = 0;
	int nMaPB = 0;
	ifstream fcin;
	fcin.open("BanDoc.txt", ios::in);
	fcin >> nNum;
	fcin.ignore(1);
	for (int i = 0; i < nNum; i++)
	{
		fcin >> nMaPB; fcin.ignore(1);
		if (nMaPB==1)
		{
			BanDoc *gv = new GiaoVien;
			gv->readBanDoc(fcin);
			Bandoc.push_back(gv);
		}
		else if (nMaPB==2)
		{
			BanDoc *sv = new SinhVien;
			sv->readBanDoc(fcin);
			Bandoc.push_back(sv);
		}
	}
	
	fcin.close();
}
void ghiDSBanDoc(vector<BanDoc*> Bandoc)
{
	ofstream fcout;
	int nMaPB = 0;
	fcout.open("BanDoc.txt", ios::out);
	fcout << Bandoc.size();
	fcout << endl;
	for (int i = 0; i < Bandoc.size(); i++)
	{
		Bandoc[i]->writeBanDoc(fcout);
	}
	fcout.close();
}
void xuatDSBanDoc(vector<BanDoc*> Bandoc)
{
	for (int i = 0; i < Bandoc.size(); i++)
	{
		Bandoc[i]->outputBanDoc();
		cout << endl;
	}
}
void hienthiDSBanDoc_theoMaBD(vector<BanDoc*> Bd)
{
	string sMaBD = "";
	bool bFlag = 0;
	textcolor(13);
	cout << "\t\t\tNhap Ma ban doc : ";
	rewind(stdin);
	getline(cin, sMaBD);
	textcolor(10);
	
	textcolor(43);
	for (int i = 0; i < Bd.size(); i++)
	{
		if (Bd[i]->getMaBD() == sMaBD)
		{
			cout << endl;
			bFlag = 1;
			Bd[i]->outputBanDoc();
		}
	}
	if (bFlag == 0)
	{
		textcolor(12);
		cout << "\t\tMa Ban doc vua nhap khong ton tai! \n";
	}
	cout << endl;
}
// Sach :
void docDSsach(vector<Sach> &S)
{
	int nN = 0;
	ifstream file;
	file.open("Sach.txt");
	file >> nN;
	file.ignore(1);
	for (int i = 0; i < nN; i++)
	{
		Sach s;
		s.readSach(file);
		S.push_back(s);
	}
	file.close();
}
void ghiDSsach(vector<Sach> S)
{
	ofstream file;
	file.open("Sach.txt", ios::out);
	file << S.size(); file << endl;
	for (int i = 0; i < S.size(); i++)
	{
		S[i].writeSach(file);
	}
}
void hienThiTTSach(vector<Sach> S)
{
	textcolor(11);
	for (int i = 0; i < S.size(); i++)
	{
		S[i].outputSach();
		cout << endl;
		cout << "\t-----------------------------------------------\n";
	}
}
void themSach(vector<Sach> &S)
{
	string sMasach = "";
	string sTensach = "";
	string sTacgia = "";
	string sNXB = "";
	float fGia = 0.0;
	int nSotrang = 0;
	int nNamPH = 0;
	
cc: {textcolor(11);
	cout << "\t\t\tNhap Ma sach can them : "; rewind(stdin); getline(cin, sMasach); }
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getMasach()==sMasach)
		{
			system("cls");
			quanLySach();
			textcolor(12);
			cout << "\t\tMa sach da ton tai. Vui long nhap lai !\n";
			goto cc;
		}
		else if (sMasach=="")
		{
			system("cls");
			textcolor(12);
			quanLySach();
			cout << "\t\tKhong duoc de trong !\n";
		}
	}
	textcolor(11);
	cout << "\t\t\tNhap tua de           : "; rewind(stdin); getline(cin, sTensach);
	cout << "\t\t\tNhap tac gia          : "; rewind(stdin); getline(cin, sTacgia);
	cout << "\t\t\tNhap NXB              : "; rewind(stdin); getline(cin, sNXB);
	cout << "\t\t\tNhap gia ban          : "; cin >> fGia;
	cout << "\t\t\tNhap so trang         : "; cin >> nSotrang;
	cout << "\t\t\tNhap nam PH           : "; cin >> nNamPH;
	Sach s(sMasach, sTensach, sTacgia, sNXB, fGia, nNamPH, nSotrang);
	S.push_back(s);
	ghiDSsach(S);
	textcolor(12);
	cout << "\t\tThem sach thanh cong !\n";
	
}
void xoaSach(vector<Sach> &S)
{
	
	string sMasach = "";
	bool bFlag = 0;
cc: {textcolor(11);
	cout << "\t\t\tNhap Ma sach can xoa : ";
	rewind(stdin); getline(cin, sMasach); }
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getMasach()==sMasach&&S[i].getTinhtrang()==0)
		{
			
			bFlag = 1;
			textcolor(12);
			cout << "\t\t\t\tXoa sach thanh cong!\n";
			S.erase(S.begin()+i);
			ghiDSsach(S);
		}
	}
	if (bFlag==0)
	{
		system("cls");
		quanLySach();
		textcolor(12);
		cout << "\t\t\tMa sach nay khong ton tai hoac dang duoc muon !\n";
		goto cc;
	}

}
// Hàm màu, mã hóa mật khẩu:
void textcolor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
// Chức năng khác :
void CN_hienThiSachtheoTuade(vector<Sach>S)
{
	string sTuade = "";
	bool bFlag = 0;
	textcolor(14);
	cout << "\t\t\tNhap Tua de sach : ";
	rewind(stdin);
	getline(cin, sTuade);
	textcolor(43);
	
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTieude() == sTuade)
		{
			cout << endl;
			bFlag = 1;
			S[i].outputSach();
			cout << endl;
			cout << "\t---------------------------------------\n";
		}
	}
	if (bFlag==0)
	{
		textcolor(12);
		cout << "\t\tTieu de Sach vua nhap khong ton tai! \n";
	}
	
}
bool kTraMaBandoc(vector<BanDoc*> xBd, string sMaBD)
{
	bool bFlag = false;
	for (int i = 0; i < xBd.size(); i++)
	{
		if (xBd[i]->getMaBD() == sMaBD)
		{
			return true;
		}
	}
	return false;
}
bool kTraMaSach(vector<Sach> S, string sMasach)
{
	bool bFlag = false;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getMasach() == sMasach&&S[i].getTinhtrang()==0)
		{
			return true;
		}
	}
	return false;
}
bool kTraMaPM(vector<PhieuMuon> dsPM,int nX)
{
	for (int i = 0; i < dsPM.size(); i++)
	{
		if (dsPM[i].getMaPM() == nX)
		{
			return i;
		}
	}
	return -1;
	
}
int kTra_Vtri_Sach_DeTra(vector<Sach> S,string sMasach)
{
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getMasach()==sMasach)
		{
			return i;
		}
	}
	return -1;
}
// Màn hình thông báo:
void Menu()
{
	textcolor(11);
	cout << "\t\t\t  * * * * * * * * * * * * * * * * * * * * *\n";
	cout << "\t\t\t  *                ";
	textcolor(10);
	cout << " MENU                 ";
	textcolor(11);
	cout << " *\n";
	cout << "\t\t\t  * * * * * * * * * * * * * * * * * * * * *\n";
	textcolor(12);
	cout << "\t\t\t\t1. Hien thi thong tin Sach\n";
	cout << "\t\t\t\t2. Tim kiem thong tin\n";
	cout << "\t\t\t\t3. Quan ly\n";
	cout << "\t\t\t\t4. Thoat\n";
	textcolor(10);
	cout << "\t\t___________________________________________________________________\n";
}
void timkiemTT()
{
	textcolor(11);
	cout << "\t\t\t  * * * * * * * * * * * * * * * * * * * * *\n";
	cout << "\t\t\t  *          ";
	textcolor(10);
	cout << " TIM KIEM THONG TIN          ";
	textcolor(11);
	cout << "*\n";
	cout << "\t\t\t  * * * * * * * * * * * * * * * * * * * * *\n";
	textcolor(12);
	cout << "\t\t\t\t1. Tim kiem thong tin Sach\n";
	cout << "\t\t\t\t2. Tim kiem thong tin Ban Doc\n";
	cout << "\t\t\t\t3. Quay ve Menu chinh\n";
	textcolor(10);
	cout << "\t\t___________________________________________________________________\n";
}
void Quanly()
{
	textcolor(11);
	cout << "\t\t\t  * * * * * * * * * * * * * * * * * * * * *\n";
	cout << "\t\t\t  *               ";
	textcolor(10);
	cout << " QUAN LY                ";
	textcolor(11);
	cout << "*\n";
	cout << "\t\t\t  * * * * * * * * * * * * * * * * * * * * *\n";
	textcolor(12);
	cout << "\t\t\t\t1. Quan ly Phieu Muon\n";
	cout << "\t\t\t\t2. Quan ly Sach\n";
	cout << "\t\t\t\t3. Quan ly Ban Doc\n";
	cout << "\t\t\t\t4. Thong ke\n";
	cout << "\t\t\t\t5. Quay ve Menu chinh\n";
	textcolor(10);
	cout << "\t\t___________________________________________________________________\n";
}
void quanLyPM()
{
	textcolor(14);
	cout << "\n\t\t\t___________________";
	textcolor(58);
	cout << "-[QUAN LY PHIEU MUON]-";

	textcolor(14);
	cout<<"___________________\n\n";
	textcolor(12);
	cout << "\t\t\t\t\t1. Tao Phieu Muon\n";
	cout << "\t\t\t\t\t2. Tra sach\n";
	cout << "\t\t\t\t\t3. Quay ve Menu chinh\n";
	textcolor(10);
	cout << "\t\t___________________________________________________________________\n";
}
void quanLySach()
{
	textcolor(14);
	cout << "\n\t\t\t___________________";
	textcolor(58);
	cout << "-[QUAN LY SACH]-";
	textcolor(14);
	cout << "___________________\n\n";
	textcolor(12);
	cout << "\t\t\t\t\t1. Them Sach\n";
	cout << "\t\t\t\t\t2. Xoa sach\n";
	cout << "\t\t\t\t\t3. Quay ve Menu chinh\n";
	textcolor(10);
	cout << "\t\t___________________________________________________________________\n";
}
void quanLyBD()
{
	textcolor(14);
	cout << "\n\t\t\t___________________";
	textcolor(58);
	cout << "-[QUAN LY BAN DOC]-";
	textcolor(14);
	cout << "___________________\n\n";
	textcolor(12);
	cout << "\t\t\t\t\t1. Them Ban doc\n";
	cout << "\t\t\t\t\t2. Xem danh sach Ban doc\n";
	cout << "\t\t\t\t\t3. Quay ve Menu chinh\n";
	textcolor(10);
	cout << "\t\t___________________________________________________________________\n";
}
void Thongke()
{
	textcolor(14);
	cout << "\n\t\t\t___________________________";
	textcolor(58);
	cout << "-[THONG KE]-";
	textcolor(14);
	cout << "___________________________\n\n";
	textcolor(12);
	cout << "\t\t\t\t1. Tong so luong Sach con lai trong Thu Vien\n";
	cout << "\t\t\t\t2. Tong so Sach da duoc muon\n";
	cout << "\t\t\t\t3. Liet ke cac Sach GV hoac SV dang muon\n";
	cout << "\t\t\t\t4. Quay ve Menu chinh\n";
	textcolor(10);
	cout << "\t\t\t___________________________________________________________________\n";
}