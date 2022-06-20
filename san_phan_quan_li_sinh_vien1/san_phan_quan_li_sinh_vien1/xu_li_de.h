#pragma once
#include "load_file.h"
#include<vector>

// =============== MON HOC =============
istream& operator >>(istream &is, mon &x);
ostream& operator <<(ostream &os, mon x);
void Xuat_Danh_Sach_mh(danh_sach_mh ds_mh);

// =============== LOP =================
istream& operator >>(istream &is, lop &x);
ostream& operator <<(ostream &os, lop x);
void Xuat_Danh_Sach_lop(danh_sach_lop ds_lop);

// =============== SINH VIEN =================
int kt_trung_ma_lop(danh_sach_lop ds_lop, string a);
sv nhap_1_sinh_vien(sv &x, danh_sach_lop ds_lop, int i);
ostream& operator <<(ostream &os, sv x);
void xuat_ds_sv_1_lop(danh_sach_sv ds_sv);
void xuat_ds_sv(danh_sach_lop ds_lop);

// ================= DIEM ==============
int kt_trung_ma_sv_theo_lop(danh_sach_lop ds_lop, int chi_so_cua_lop_can_nhap, string _ma_sv);
istream& operator >>(istream &is, diem_tp &x);
ostream& operator <<(ostream &os, diem_tp x);
void xuat_ds_diem_1_lop(danh_sach_sv ds_sv);

// =============== XU Li NGOAI LE ===============
string VietHoa(string s);
void xuat_ds_sinh_vien_theo_nien_khoa(danh_sach_lop ds_lop);
void xuat_ds_sinh_vien_theo_thu_tu_alphabet_cua_1_lop(danh_sach_lop ds_lop, int chi_so_ma_lop);
void in_bang_diem_mon_hoc_cua_1_lop(danh_sach_sv ds_sv);
void in_bang_diem_moc_hoc_cua_1_sinh_vien(danh_sach_lop ds_lop, string _ma_sv);
void XoaKhoangTrangDauChuoi(string &c);
void XoaKhoangTrangCuoiChuoi(string &c);
void Can_Chu(string &c);
void Viet_Hoa_Chu_Cai_Dau(string &c);
void Viet_Thuong_Chu_Cai(string &c);
void ChuanHoaChuoi(string &c);
// =====================================
void menu();

void menu()
{
	// setting
	danh_sach_lop ds_lop;
	danh_sach_mh ds_mh;
	// ----- load file -------
	load_ds_mh(ds_mh);
	load_ds_lop(ds_lop);
	load_ds_sinh_vien(ds_lop);
	load_ds_diem(ds_lop);
	// ------ play ------
	while (66)
	{
		system("cls");
		cout << "1. Nhap mon hoc" << endl;
		cout << "2. Xuat danh sach mon hoc" << endl;
		cout << "3. Nhap lop" << endl;
		cout << "4. Xuat danh sach lop" << endl;
		cout << "5. Nhap sinh vien theo ma lop" << endl;
		cout << "6.  Xuat danh sach sinh vien theo ma lop" << endl;
		cout << "7. Nhap diem sinh vien theo ma lop va ma sinh vien" << endl;
		cout << "8.  Xuat danh sach diem sinh vien theo ma lop" << endl;
		cout << "9.  Xuat danh sach  sinh vien theo nien khoa" << endl;
		cout << "10.  Xuat danh sach sinh vien theo bang chu cai tang dan theo lop" << endl;
		cout << "11.  In bang diem mon hoc cua mot lop" << endl;
		cout << "12.  In bang diem mon hoc cua mot sinh vien" << endl;
		cout << "0. Thoat" << endl;
		int lc;
		cout << "Nhap lua chon: "; cin >> lc;
		if (lc == 0)
		{
			break;
		}
		else if (lc == 1)
		{
			int sl_temp = 0;
			cout << "Nhap so luong mon can nhap: "; cin >> sl_temp;
			for (int i = 0; i < sl_temp; i++)
			{
				cin.ignore();
				cout << "\t\t =========== Nhap mon " << i + 1 << "===========" << endl;
				mon x; // luu tam du lieu nguoi dung
				cin >> x; // nap chong toan tu
				ds_mh.ds[ds_mh.sl++] = x;
			}
		}
		else if (lc == 2)
		{
			Xuat_Danh_Sach_mh(ds_mh);
			system("pause");
		}
		else if (lc == 3)
		{
			int sl_temp = 0;
			cout << "Nhap so luong lop can nhap: "; cin >> sl_temp;
			for (int i = 0; i < sl_temp; i++)
			{
				cin.ignore();
				cout << "\t\t =========== Nhap lop " << i + 1 << "===========" << endl;
				lop x; // luu tam du lieu nguoi dung
				cin >> x; // nap chong toan tu
				ds_lop.ds[ds_lop.sl++] = x;
			}
		}
		else if (lc == 4)
		{
			Xuat_Danh_Sach_lop(ds_lop);
			system("pause");
		}
		else if (lc == 5)
		{
			cin.ignore();
			string a; // luu ma lop can nhap ds sinh vien
			cout << "Nhap ma lop can them sinh vien: "; getline(cin, a);
			int i = kt_trung_ma_lop(ds_lop, a);
			if (i == -1)
			{
				cout << "Ma lop khong ton tai " << endl;
				system("pause");
			}
			else // trung ma lop
			{
				system("cls");
				int sl_temp;
				cout << "Nhap so luong sinh vien cam them: ";
				cin >> sl_temp;
				cin.ignore(); // chi xoa cho sinh vien dau tien
				for (int j = 1; j <= sl_temp; j++)
				{
					cout << "\t\t------ Nhap sv " << j << "------" << endl;
					// them sinh vien cho lop thu i : ds_lop.ds[i]
					sv x; // luu tam du lieu cua mot sinh vien
					nhap_1_sinh_vien(x, ds_lop, i);
					them_sv(ds_lop.ds[i].ds_sv, x);
				}
			}
		}
		else if (lc == 6)
		{
					cout << "\t\t Xuat Danh Sach Sinh Vien Toan Truong" << endl;
					xuat_ds_sv(ds_lop);
					system("pause");
			/*cin.ignore();
			string a;
			cout << "Nhap ten lop muon xuat danh sach: ";
			getline(cin, a);
			int i = kt_trung_ma_lop(ds_lop, a);
			if (i == -1)
			{
				cout << "\tKhong ton tai ma lop " << a;
			}
			else
			{
				xuat_ds_sv_1_lop(ds_lop.ds[i].ds_sv);
			}
			system("pause");*/
		}
		else if (lc == 7)
		{
			cin.ignore();
			string _ma_lop;
			cout << "Nhap ma lop muon nhap diem: ";
			getline(cin, _ma_lop);
			int i = kt_trung_ma_lop(ds_lop, _ma_lop); // giữ chỉ số của lớp đã nhập từ bàn phím
			if (i == -1)
			{
				cout << "Khong ton tai ma lop " << VietHoa(_ma_lop);
				system("pause");
			}
			else
			{
				string _ma_sv;
				cout << "Nhap ma sinh vien muon nhap diem: ";
				getline(cin, _ma_sv);
				int j = kt_trung_ma_sv_theo_lop(ds_lop, i, _ma_sv); // giữ chỉ số của sinh viên thứ j của lớp thứ i
				if (j == -1)
				{
					cout << "Khong ton tai ma sinh vien " << VietHoa(_ma_sv) << " trong lop " << VietHoa(_ma_lop);
					system("pause");
				}
				else
				{				
					int n_mon;
					cout << "Nhap so luong mon can nhap diem cho sinh vien: ";
					cin >> n_mon;					
					int index = 1;
					for (node_sv *k = ds_lop.ds[i].ds_sv.pHead; k != NULL; k = k->pNext)
					{
						if (index == j)
						{
							for (int g = 0; g < n_mon; g++)
							{
								cout << "\t ======= Lan nhap thu " << g + 1 << endl;
								cin.ignore();
								diem_tp x;
								cin >> x;
								them_diem(k->data.ds_diem_tp, x);
							}
							break;
						}
						index++;
					}
				}
			}
		}
		else if (lc == 8)
		{
			cin.ignore();
			string a;
			cout << "Nhap ten lop muon xuat danh sach:  ";
			getline(cin, a);
			int i = kt_trung_ma_lop(ds_lop, a);
			if (i == -1)
			{
				cout << "\tKhong ton tai ma lop " << VietHoa(a);
			}
			else
			{
				cout << "\t\t======== Danh Sach Diem Lop " << VietHoa(a) << " ========" << endl;
				xuat_ds_diem_1_lop(ds_lop.ds[i].ds_sv);
			}
			system("pause");
		}
		else if (lc == 9)
		{
			xuat_ds_sinh_vien_theo_nien_khoa(ds_lop);
			system("pause");
		}
		else if (lc == 10)
		{
			cin.ignore();
			string _ma_lop;
			cout << "Nhap ma lop muon xuat: ";
			getline(cin, _ma_lop);
			int i = kt_trung_ma_lop(ds_lop, _ma_lop); // giữ chỉ số của lớp đã nhập từ bàn phím
			if (i == -1)
			{
				cout << "Khong ton tai ma lop " << VietHoa(_ma_lop);
				system("pause");
			}
			else
			{
				xuat_ds_sinh_vien_theo_thu_tu_alphabet_cua_1_lop(ds_lop, i);
				system("pause");
			}
		}
		else if (lc == 11)
		{
			cin.ignore();
			string _ma_lop;
			cout << "Nhap ma lop muon xuat: ";
			getline(cin, _ma_lop);
			int i = kt_trung_ma_lop(ds_lop, _ma_lop); // giữ chỉ số của lớp đã nhập từ bàn phím
			if (i == -1)
			{
				cout << "Khong ton tai ma lop " << VietHoa(_ma_lop);
				system("pause");
			}
			else
			{
				in_bang_diem_mon_hoc_cua_1_lop(ds_lop.ds[i].ds_sv);
				system("pause");
			}
		}
		else if (lc == 12)
		{
			cin.ignore();
			string _ma_sv;
			cout << "Nhap ma sinh vien muon nhap diem: ";
			getline(cin, _ma_sv);
			in_bang_diem_moc_hoc_cua_1_sinh_vien(ds_lop, _ma_sv);
			system("pause");
		}
	}
}
// ============== MON ================
istream& operator >>(istream &is, mon &x)
{
	cout << "Nhap ma mon hoc: ";
	getline(is, x.ma_mh);
	cout << "Nhap ten mon: ";
	getline(is, x.ten_mh);
	cout << "Nhap so tin chi li thuyet: ";
	is >> x.stclt;
	cout << "Nhap so tin chi thuc hanh: ";
	is >> x.stcth;
	return is;
}
ostream& operator <<(ostream &os, mon x)
{
	cout << "Ma mon: " << x.ma_mh << endl;
	cout << "Ten mon: " << x.ten_mh << endl;
	cout << "So tin chi li thuyet: " << x.stclt << endl;
	cout << "So tin chi thuc hanh: " << x.stcth << endl;
	return os;
}
void Xuat_Danh_Sach_mh(danh_sach_mh ds_mh)
{
	cout << "\t\t ========== Xuat Danh Sach Mon Hoc ==========" << endl;
	for (int i = 0; i < ds_mh.sl; i++)
	{
		cout << "\t\t ------ Mon: " << i + 1 << "-----" << endl;
		cout << ds_mh.ds[i];
	}
}
// =============== LOP ===============
istream& operator >>(istream &is, lop &x)
{
	cout << "Nhap ma lop: ";
	getline(is, x.malop);
	cout << "Nhap ten lop: ";
	getline(is, x.tenlop);
	cout << "Nhap nien khoa: ";
	is >> x.nien_khoa;
	return is;
}
ostream& operator <<(ostream &os, lop x)
{
	cout << "Ma Lop: " << x.malop << endl;
	cout << "Ten Lop: " << x.tenlop << endl;
	cout << "Nien Khoa: " << x.nien_khoa << endl;
	return os;
}
void Xuat_Danh_Sach_lop(danh_sach_lop ds_lop)
{
	cout << "\t\t ========== Xuat Danh Sach Lop ==========" << endl;
	for (int i = 0; i < ds_lop.sl; i++)
	{
		cout << "\t\t ------ Lop: " << ds_lop.ds[i].tenlop << "-----" << endl;
		cout << ds_lop.ds[i];
	}
}
// ========================== Nhap sv ==========================
int kt_trung_ma_lop(danh_sach_lop ds_lop, string a)
{
	for (int i = 0; i < ds_lop.sl; i++)
	{
		if (_stricmp(ds_lop.ds[i].malop.c_str(), a.c_str()) == 0)
		{
			return i; // tra ve vi tri thu i cua lop do	
		}
	}
	return -1; // khong ton tai
}
// ==== Nhap 1 sinh vien
sv nhap_1_sinh_vien(sv &x,danh_sach_lop ds_lop,int i)
{
	do
	{
		cout << "Nhap ma sinh vien: ";
		getline(cin, x.masv);
		if (kt_trung_ma_sv_theo_lop(ds_lop,i,x.masv) != -1)
		{
			cout << "\nDa ton tai ma sinh vien. Vui long nhap lai" << endl;
		}
	}while (kt_trung_ma_sv_theo_lop(ds_lop, i, x.masv) != -1);
	cout << "Nhap ho: ";
	getline(cin, x.ho);
	ChuanHoaChuoi(x.ho);
	cout << "Nhap ten: ";
	getline(cin, x.ten);
	ChuanHoaChuoi(x.ten);
	cout << "Nhap phai: ";
	getline(cin, x.phai);
	cout << "Nhap sdt: ";
	getline(cin, x.sdt);
	return x;
}
node_sv* khoi_tao_node_sv(sv x)
{
	node_sv *p = new node_sv;
	p->pNext = NULL;
	p->data = x;
	return p;
}
void them_sv(danh_sach_sv &ds_sv, sv x)
{
	node_sv *p = khoi_tao_node_sv(x);
	if (ds_sv.pHead == NULL) // danh sach rong
	{
		ds_sv.pHead = ds_sv.pTail = p;
	}
	else
	{
		ds_sv.pTail->pNext = p; // lien ket
		ds_sv.pTail = p; // cap nhat lai ptail
	}
}
// ------------- xuat ds sinh vien ----------
ostream& operator <<(ostream &os, sv x)
{
	cout << "Ma sinh vien: " << x.masv << endl;
	cout << "Ho Ten: " << x.ho << " " << x.ten << endl;
	cout << "Phai: " << x.phai << endl;
	cout << "SDT: " << x.sdt << endl;
	return os;
}
void xuat_ds_sv_1_lop(danh_sach_sv ds_sv)
{
	cout << "\t\t============= Xuat Danh Sach Sinh Vien ===========" << endl;
	for (node_sv *k = ds_sv.pHead; k != NULL; k = k->pNext)
	{
		cout << "\t\t\t\t------- Ma Sinh vien: " << k->data.masv << "------" << endl;
		cout << k->data << endl;
	}
}
void xuat_ds_sv(danh_sach_lop ds_lop)
{
	for (int i = 0; i < ds_lop.sl; i++)
	{
		cout << "\t\t======= Dach sach sinh vien lop: " << ds_lop.ds[i].tenlop << " ========" << endl;
		for (node_sv *k = ds_lop.ds[i].ds_sv.pHead; k != NULL; k = k->pNext)
		{
			cout << "\t\t\t\tMa Sinh vien: " << k->data.masv << endl;
			cout << k->data << endl;
		}
	}
}

// ===================== DIEM ===================
int kt_trung_ma_sv_theo_lop(danh_sach_lop ds_lop, int chi_so_cua_lop_can_nhap,string _ma_sv)
{
	int i = 1; // luu du chi so cua sinh vien do
	for (node_sv *k = ds_lop.ds[chi_so_cua_lop_can_nhap].ds_sv.pHead; k != NULL; k = k->pNext)
	{
		if (_stricmp(k->data.masv.c_str(), _ma_sv.c_str()) == 0)
		{
			return i;
		}
		i++;
	}
	return -1;
}
// nhap diem cho 1 sinh vien
istream& operator >>(istream &is, diem_tp &x)
{
	cout << "Nhap ma mon hoc: ";
	getline(is, x.ma_mh);
	cout << "Nhap lan thi: ";
	is >> x.lan;
	cout << "Nhap diem: ";
	is >> x.diem;
	return is;
}
node_diem_tp *khoi_tao_node_diem(diem_tp x)
{
	node_diem_tp *p = new node_diem_tp;
	p->data = x;
	p->pNext = NULL;
	return p;
}
void them_diem(danh_sach_diem_tp &ds_diem, diem_tp x)
{
	node_diem_tp *p = khoi_tao_node_diem(x);
	// neu danh sach diem rong
	if (ds_diem.pHead == NULL)
	{
		ds_diem.pHead = ds_diem.pTail = p;
	}
	else
	{
		ds_diem.pTail->pNext = p;
		ds_diem.pTail = p;
	}
}
ostream& operator <<(ostream &os, diem_tp x)
{
	cout << "Ma mon hoc: " << x.ma_mh << endl;
	cout << "Lan thi: " << x.lan  << endl;
	cout << "Diem: " << x.diem << endl;
	return os;
}
void xuat_ds_diem_1_lop(danh_sach_sv ds_sv)
{
	for (node_sv *k = ds_sv.pHead; k != NULL; k = k->pNext)
	{
		cout << "\t---- Ma sinh vien:  " << k->data.masv << endl;
		if (k->data.ds_diem_tp.pHead == NULL)
		{
			cout << "Chua nhap diem" << endl;
		}
		for (node_diem_tp *h = k->data.ds_diem_tp.pHead; h != NULL; h = h->pNext)
		{
			cout << h->data << endl;
		}
	}
}

// =============== XU Li NGOAI LE ===============
string VietHoa(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 97 && s[i] <= 122)
		{
			s[i] -= 32;
		}
	}
	return s;
}
// xuất danh sách sinh viên theo niên khoá
void xuat_ds_sinh_vien_theo_nien_khoa(danh_sach_lop ds_lop)
{
	vector<int> mang_nien_khoa;
	int sl_nien_khoa = 0;
	// copy niên khoá
	for (int i = 0; i < ds_lop.sl; i++)
	{
		mang_nien_khoa.push_back(ds_lop.ds[i].nien_khoa);
		sl_nien_khoa++;
	}
	// lọc dữ liệu để lấy ra niên khoá không trùng nhau
	for (int i = 0; i < sl_nien_khoa - 1; i++)
	{
		for (int j = i + 1; j < sl_nien_khoa; j++)
		{
			if (mang_nien_khoa[i] == mang_nien_khoa[j])
			{
				mang_nien_khoa.erase(mang_nien_khoa.begin() + j);
				sl_nien_khoa--;
			}
		}
	}
	for (int i = 0; i < sl_nien_khoa; i++)
	{
		cout << "\t\t +++++++++++++++ Danh Sach Sinh Vien Nien Khoa " << mang_nien_khoa[i] << " +++++++++++++++" << endl;
		for (int j = 0; j < ds_lop.sl; j++)
		{
			if (ds_lop.ds[j].nien_khoa == mang_nien_khoa[i])
			{
				xuat_ds_sv_1_lop(ds_lop.ds[j].ds_sv);
				cout << endl;
			}
		}
	}
}
//in dssv của 1 lớp theo thứ tự alphabet tăng dần của tên + họ
void xuat_ds_sinh_vien_theo_thu_tu_alphabet_cua_1_lop(danh_sach_lop ds_lop, int chi_so_ma_lop)
{
	// sắp xếp danh sách theo tên
	for (node_sv *k = ds_lop.ds[chi_so_ma_lop].ds_sv.pHead; k != NULL; k = k->pNext)
	{
		for (node_sv *h = k->pNext; h != NULL; h = h->pNext)
		{
			if (_stricmp(k->data.ten.c_str(), h->data.ten.c_str()) > 0)
			{
				swap(k->data, h->data);
			}
		}
	}
	// in danh sách
	xuat_ds_sv_1_lop(ds_lop.ds[chi_so_ma_lop].ds_sv);
}
// In bảng điểm môn học của 1 lớp theo 1 lần thi
void in_bang_diem_mon_hoc_cua_1_lop(danh_sach_sv ds_sv)
{
	cout << "\t\tBang Diem Mon Hoc Cua 1 Lop" << endl;
	for (node_sv *k = ds_sv.pHead; k != NULL; k = k->pNext)
	{
		for (node_diem_tp *h = k->data.ds_diem_tp.pHead; h != NULL; h = h->pNext)
		{
			if (h->data.lan == 1)
			{
				cout << h->data;
				cout << endl;
			}
		}
	}
}
// -> Phiếu điểm in bảng điểm môn học của 1 sinh viên có mã bất kỳ
void in_bang_diem_moc_hoc_cua_1_sinh_vien(danh_sach_lop ds_lop, string _ma_sv)
{
	for (int i = 0; i < ds_lop.sl; i++)
	{
		for (node_sv *k = ds_lop.ds[i].ds_sv.pHead; k != NULL; k = k->pNext)
		{
			if (_stricmp(k->data.masv.c_str(), _ma_sv.c_str()) == 0)
			{
				cout << "\t\t ================ BANG DIEM ================" << endl;
				cout << "\t\t Ma Sinh Vien " << VietHoa(_ma_sv) << endl;
				for (node_diem_tp *h = k->data.ds_diem_tp.pHead; h != NULL; h = h->pNext)
				{
					cout << h->data << endl;
				}
				return;
			}
		}
	}
	cout << "\tKhong ton tai ma sinh vien " << VietHoa(_ma_sv);
}
void XoaKhoangTrangDauChuoi(string &c)
{
	int len = c.length();
	for (int i = 0; i < len; i++)
	{
		if (c[i] == ' ')
		{
			c.erase(c.begin() + i);
			i--;
		}
		else
		{
			break;
		}
	}
}
// xoa khoang trang cuoi chuoi
void XoaKhoangTrangCuoiChuoi(string &c)
{
	int len = c.length();
	while (c[c.length() - 1] == ' ')
	{
		c.erase(c.begin() + c.length() - 1);
	}
}
// xoa khoang trang giua cac tu <=> moi tu chi cach nhau 1 khoang trang
void Can_Chu(string &c)
{
	int len = c.length();
	int demKhoangTrang = 0;
	for (int i = 0; i < len; i++)
	{
		if (c[i] == ' ')
		{
			demKhoangTrang++;
			if (demKhoangTrang > 1)
			{
				c.erase(c.begin() + i);
				i--;
			}
		}
		else
		{
			demKhoangTrang = 0;
		}
	}
}
// viet hoa ki tu dau moi chu
void Viet_Hoa_Chu_Cai_Dau(string &c)
{
	int len = c.length();
	for (int i = 0; i < len; i++)
	{
		if (i == 0 && (c[i] >= 97 && c[i] <= 122))
		{
			c[i] -= 32;
		}
		else if (c[i] == ' ' && (c[i] >= 97 && c[i] <= 122))
		{
			c[i] -= 32;
		}
	}
}
void Viet_Thuong_Chu_Cai(string &c)
{
	int dem = 0;
	for (int i = 1; i < c.length(); i++)
	{
		if (dem == 0 && (c[i] >= 65 && c[i] <= 90))
		{
			c[i] += 32;
		}
		else if (c[i] == ' ' && dem == 0)
		{
			dem = 1;
		}
		if (c[i] == ' ' && (c[i + 1] >= 65 && c[i + 1] <= 90) && dem == 1)
		{
			for (int j = i + 2; j < c.length(); j++)
			{
				if (c[j] >= 65 && c[j] <= 90)
				{
					c[j] += 32;
				}
				else if (c[j] == ' ')
				{
					i = j - 1;
					break;
				}
			}
		}
	}
}
// ham xu li tong
void ChuanHoaChuoi(string &c)
{
	XoaKhoangTrangDauChuoi(c);
	XoaKhoangTrangCuoiChuoi(c);
	Can_Chu(c);
	Viet_Hoa_Chu_Cai_Dau(c);
	Viet_Thuong_Chu_Cai(c);
}