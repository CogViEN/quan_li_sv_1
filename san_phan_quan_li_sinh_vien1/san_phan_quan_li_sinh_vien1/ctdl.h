#pragma once
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
using namespace std;

// =======================
struct mon
{
	string ma_mh;
	string ten_mh;
	int stclt;
	int stcth;
};

struct danh_sach_mh
{
	mon ds[100];
	int sl = 0;
};
// =================== danh sach diem tp =============
struct diem_tp {
	string ma_mh;
	int lan;
	float diem;
};

struct node_diem_tp {
	diem_tp data;
	node_diem_tp *pNext;
};

struct danh_sach_diem_tp {
	node_diem_tp *pHead = NULL;
	node_diem_tp *pTail = NULL;
};
// =================== danh sach sinh vien ===========
struct sv
{
	string masv;
	string ho;
	string ten;
	string sdt;
	string phai;
	// danh sach diem	
	danh_sach_diem_tp ds_diem_tp;
};

struct node_sv {
	sv data;
	node_sv *pNext;
};

struct danh_sach_sv {
	node_sv *pHead = NULL;
	node_sv *pTail = NULL;
};
// ================ danh sach lop ===================
struct lop {
	string malop;
	string tenlop;
	int nien_khoa;
	// ds sinh vien
	danh_sach_sv ds_sv;
};

struct danh_sach_lop {
	lop ds[100];
	int sl = 0;
};

void test()
{
	
}