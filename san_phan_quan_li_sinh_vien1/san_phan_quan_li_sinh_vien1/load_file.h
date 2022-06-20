#pragma once
#include "ctdl.h"
// ========= SINH VIEN ===========
node_sv* khoi_tao_node_sv(sv x);
void them_sv(danh_sach_sv &ds_sv, sv x);
//========= DIEM ================
node_diem_tp *khoi_tao_node_diem(diem_tp x);
void them_diem(danh_sach_diem_tp &ds_diem, diem_tp x);
//===============================
void load_ds_mh(danh_sach_mh &ds_mh)
{
	ifstream FileIn;
	FileIn.open("ds_mh.txt", ios_base::in);
	// doc file
	while (!FileIn.eof())
	{
		mon x; // luu tam du lieu load tu file
		getline(FileIn, x.ma_mh, ',');
		getline(FileIn, x.ten_mh, ',');
		FileIn >> x.stclt;
		FileIn.ignore();
		FileIn >> x.stcth;
		FileIn.ignore();
		ds_mh.ds[ds_mh.sl++] = x;
	}
	FileIn.close();
}

void load_ds_lop(danh_sach_lop &ds_lop)
{
	ifstream FileIn;
	FileIn.open("ds_lop.txt", ios_base::in);
	// doc file
	while (!FileIn.eof())
	{
		lop x; // luu tam du lieu load tu file
		getline(FileIn, x.malop, ',');
		getline(FileIn, x.tenlop, ',');
		FileIn >> x.nien_khoa;
		FileIn.ignore();
		ds_lop.ds[ds_lop.sl++] = x;
	}
	FileIn.close();
}
void load_ds_sinh_vien(danh_sach_lop &ds_lop)
{
	ifstream FileIn;
	FileIn.open("ds_sv.txt", ios_base::in);
	// doc file
	for (int i = 0; i < ds_lop.sl; i++)
	{
		int n;
		FileIn >> n;
		FileIn.ignore(); // xuống dòng
		for (int j = 1; j <= n; j++)
		{
			sv a;
			getline(FileIn, a.masv, ',');
			getline(FileIn, a.ho, ',');
			getline(FileIn, a.ten, ',');
			getline(FileIn, a.phai, ',');
			getline(FileIn, a.sdt);
			them_sv(ds_lop.ds[i].ds_sv, a);
		}
	}
	FileIn.close();
}
void load_ds_diem(danh_sach_lop &ds_lop)
{
	ifstream FileIn;
	FileIn.open("ds_diem.txt", ios_base::in);
	// doc file
	for (int i = 0; i < ds_lop.sl; i++)
	{
		for (node_sv *k = ds_lop.ds[i].ds_sv.pHead; k != NULL; k = k->pNext)
		{
			int n_mon_file;
			FileIn >> n_mon_file;
			FileIn.ignore(); // xuống dòng trong file
			for (int i = 0; i < n_mon_file; i++)
			{
				diem_tp x;
				getline(FileIn, x.ma_mh, ',');
				FileIn >> x.lan;
				FileIn.ignore();
				FileIn >> x.diem;
				them_diem(k->data.ds_diem_tp, x);
				if (i != n_mon_file - 1)
				{
					FileIn.ignore();
				}
			}
		}
	}
	FileIn.close();
}