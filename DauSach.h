#pragma once
#include "mylib.h"
#include "Ve_Hinh.h"
#include "Check_Nhap.h"
#include "GlobalVariable.h"
#include "Ngay_Thang.h"
#include "Mark.h"
#include <fstream>



//............................. danh muc sach................................
// info 1 cuon sach 
struct DanhMucSach{
	string maSach;
	uint ttSach ;
	string viTri;
};
typedef struct DanhMucSach DMS;
// node 1 cuon sach 
struct NodeDMS{
	DMS data;
	struct NodeDMS *pNext;
};
typedef struct NodeDMS NODE_DMS;
// list 1 mo sach thuoc dau sach 
struct ListDMS{
	int n ;//thay doi dung doc tu file va la quyen sach thu n trong dms
	NODE_DMS *pHead;
};
typedef struct ListDMS LIST_DMS;

//....................dau sach..................................
//info 1 dau sach 
struct dausach{
	string tensach;
	string ISBN;
	string tacgia;
	string theloai;
	uint sotrang;
	uint namSB;
	uint luotmuon = 0;
};
typedef struct dausach dauSach;
// node 1 dau sach 
struct DauSach{
	dauSach info;
	LIST_DMS dms;
};
typedef struct DauSach DAU_SACH;
typedef struct DauSach*  pDAU_SACH;
// list nhung dau sach 
struct ListDauSach{
	// n + 1 = so phan tu , n = chi so index.
	int n = -1;
	pDAU_SACH ListDS[MAX_DAUSACH];
};
typedef struct ListDauSach LIST_DAUSACH;
// tao ra kieu truct TopSach de tien xu ly in ra 10 sach co luoc muon nhieu nhat 
struct  TopSach{
	string tensach;
	int sosachmuon;
};

//............................................prototype Dau Sach..............................................
// save tat ca dau sach vao file 
void Save_DS(LIST_DAUSACH lDS);
// kiem tra list dau sach rong 
int Empty_DauSach(LIST_DAUSACH  l);

//kiem tra list dau sach day 100 
int Full_DauSach(LIST_DAUSACH  l);
// Them mot phan tu vao trong danh sach 
int Insert_DauSach(LIST_DAUSACH &l, pDAU_SACH &pDS);
// xoa mot phan tu khoi danh sach dau sach dua tren pos 
void Delete_DauSach(LIST_DAUSACH &l, int pos);
// kiem tra ISBN vua nhap co ton tai k?
bool SearchISBN_DS(LIST_DAUSACH lDS, string ISBN);

// tim phan tu dua tren ten sach, xem sach co trong list dau sach k 
LIST_DAUSACH SearchDSByTen(LIST_DAUSACH lDS, string tensach);
// kiem tra MASACH muontra co giong voi ISBN de lay ten ISBN 
bool checkMASACH(string MaSachMT, string MaSach);
// tim phan tu dua tren ma sach,xem sach co trong List DS k 
pDAU_SACH SearchMASACH_DS(LIST_DAUSACH lDS, string MASACH);
// doi cho 2 node trong mang 
void swap_DS(pDAU_SACH ds1, pDAU_SACH ds2);


// sort dsds theo the loai + ten 
void quickSort_DS(LIST_DAUSACH lDS,int l,int r);

// cap nhat voi isEdited = 1, them voi isEdited = 0 
void Update_DauSach(LIST_DAUSACH &lDS, pDAU_SACH &pDS, bool isEdited);
// tra ve vi tri dau sach duoc chon 
int ChooseItems_DS(LIST_DAUSACH &lDS, int &tttrang, int tongtrang);

void Xoa_OutDS_1line(int locate);

void Xoa_OutDS_29lines();

void Output_DS(dauSach ds);

void OutputDS_PerPage(LIST_DAUSACH &lDS, int index);

void Output_ListDStheoTT(LIST_DAUSACH lDS);

//..................quan ly menu dau sach.........................................
void Menu_DauSach(LIST_DAUSACH &lDS);

// ..........................prototype danh muc sach...........................................
// khoi tao danh muc sach 
void initList_DMS(LIST_DMS& l);

// kiem tra rong 
bool ListDMSIsEmpty(LIST_DMS l);

//khoi tao node dms dua tren data 
NODE_DMS* GetNode_DMS(DMS DATA);
//them vao dau danh sach 
void AddTailList_DMS(LIST_DMS &l, DMS data);

// xac dinh vi tri cua nut co gia tri ma sach bang keySearch trong danh sach lien ket 
int position(NODE_DMS *First, string keySearch);

// xac dinh con tro cua node thu i trong danh sach lien ket 
NODE_DMS * nodepointer(NODE_DMS *First, int i);

// xoa node dau danh sach lien ket dms
void Delete_first(NODE_DMS *&First);

// xoa node sau node p dms
void Delete_after(NODE_DMS *p);

// xoa 1 node bat ky trong danh sach lien ket dms
void Delete_batky(pDAU_SACH &pDS, string keySearch);
// xoa het list dms truoc khi xoa node dau sach 
void ClearAll_ListDMS(LIST_DMS &l);

// ham kiem tra sach co ai muon hay chua co thi tra ve true ko th� false 
bool Check_DMS(NODE_DMS* nDMS);

//tim kiem tuyen tinh dua tren masach 1 dau sach 
NODE_DMS*   Search_DMS1(pDAU_SACH pDS, string masach);
//tim kiem 1 quyen sach thuoc danh muc sach cua 1 dau sach dua tren vi tri 
NODE_DMS*  Search_DMS2(NODE_DMS* dms, int pos);
// sap xep DMS theo Masach
void quickSort_DMS(LIST_DAUSACH lDS,int l,int r);
int NhapSach(pDAU_SACH &pDS);

int SuaDanhMucSach(pDAU_SACH &pDS, NODE_DMS* dms);

void Xoa_OutDMS_1line(int locate);

void Xoa_OutDMS_29lines();
//tra ve ten dau sach vi tri pos 
string getTenSach(LIST_DAUSACH lDS,int pos);
// tra ve ma sach vitri pos cua dau sach co vi tri posDauSach 
string getMaNodeDMS(LIST_DAUSACH lDS,int posCuonSach, int posDauSach);

int ChooseItems(LIST_DAUSACH &lDS, int &tttrang, int tongtrang);

int ChooseItems1(pDAU_SACH &pDS, int &tttrang, int tongtrang);

void Output_DMS(DMS dms);

void OutputDMS_PerPage(pDAU_SACH pDS, int index);

void Output_ListDMS(pDAU_SACH &pDS);

void NhapDanhMucSach(pDAU_SACH &pDS);

//..................quan ly menu danh muc sach...................
void Menu_DMS(LIST_DAUSACH &lDS);

// tong so sach da duoc muon cua mot dau sach 
int TongSoSachDuocMuon(LIST_DMS dms);

// xu ly thao tac in ra 10 sach co luoc muon nhieu nhat 
void Sort_Top10(TopSach *top10, int q, int r);
// in ra danh sach 10 sach duoc muon nhieu nhat
void Top10Sach(LIST_DAUSACH lDS);


//..........................................define dau sach....................................................
int Empty_DauSach(LIST_DAUSACH  l){
	return l.n == -1;
}

int Full_DauSach(LIST_DAUSACH  l){
	return l.n == MAX_DAUSACH;
}

int Insert_DauSach(LIST_DAUSACH &l, pDAU_SACH &pDS){
	if (Full_DauSach(l))
		return 0;
	l.ListDS[++l.n] = pDS;
	return 1;
}


void Delete_DauSach(LIST_DAUSACH &l, int pos){
	if (pos > l.n  || Empty_DauSach(l))
		return;

	else
	{
		ClearAll_ListDMS(l.ListDS[pos]->dms);
		delete l.ListDS[pos];
		for (int temp = pos + 1; temp <= l.n; temp++)
		{
			l.ListDS[temp - 1] = l.ListDS[temp];
		}
	l.n--;
	}
	
}

//kiem tra ISBN vua nhap co ton tai k?
bool SearchISBN_DS(LIST_DAUSACH lDS, string ISBN){
	for (int i = 0; i <= lDS.n; i++){
		if (lDS.ListDS[i]->info.ISBN == ISBN)
			return true;
	}
	return false;
}

LIST_DAUSACH SearchDSByTen(LIST_DAUSACH lDS, string tensach){
	LIST_DAUSACH temp ;
	
	for (int i = 0; i <= lDS.n; i++){
		
		if (lDS.ListDS[i]->info.tensach.find(tensach) != -1){
			temp.n++;
			temp.ListDS[temp.n] = lDS.ListDS[i];
			}
		
	}
	return temp;
	
}

// kiem tra MASACH muontra co giong voi ISBN de lay ten ISBN 
bool checkMASACH(string MaSachMT, string MaSach){
    for(int i=0;i<4;i++)
        if(MaSachMT[i]!=MaSach[i]) return false;
    return true;
}

pDAU_SACH SearchMASACH_DS(LIST_DAUSACH lDS, string MASACH){
	pDAU_SACH temp = NULL;
	for (int i = 0; i <= lDS.n; i++){
		temp = lDS.ListDS[i];
		if (checkMASACH(temp->info.ISBN,MASACH))
			return temp;
	}
	return NULL;
}
// tim TenDS tu maDMS
string SearchTen_DSDuaTrenMaDMS(LIST_DAUSACH lDS, string MASACH){
	pDAU_SACH temp = NULL;
	for(int i=0;i<=lDS.n;i++){
		temp = lDS.ListDS[i];
		if (checkMASACH(temp->info.ISBN,MASACH))
			return temp->info.tensach;
	}
}

// doi thong tin giua 2 con tro 
void swap_DS(pDAU_SACH ds1, pDAU_SACH ds2){
	DAU_SACH temp = *ds1;
	*ds1 = *ds2;
	*ds2 = temp;
}

void quickSort_DS(LIST_DAUSACH lDS,int l,int r){
	pDAU_SACH key = lDS.ListDS[(l+r)/2];
	int i = l, j = r;
	do{
		while(lDS.ListDS[i]->info.theloai<key->info.theloai||
		(lDS.ListDS[i]->info.theloai==key->info.theloai&&lDS.ListDS[i]->info.tensach<key->info.tensach)) i++;
		while(lDS.ListDS[j]->info.theloai>key->info.theloai||
		(lDS.ListDS[j]->info.theloai==key->info.theloai&&lDS.ListDS[j]->info.tensach>key->info.tensach)) j--;
		if(i<=j){
			swap_DS(lDS.ListDS[i],lDS.ListDS[j]);
			i++;
			j--;
		}
	}while (i<=j);
	if(l<j) quickSort_DS(lDS,l,j);
	if(i<r) quickSort_DS(lDS,i,r);
}
// cap nhat voi isEdited = 1, them voi isEdited = 0 
void Update_DauSach(LIST_DAUSACH &lDS, pDAU_SACH &pDS, bool isEdited){
	dauSach info;
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();

	int nngang = (int)keyBangNhapDauSach[0].length();
	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 0;
	bool isSave = false;
	bool isEscape = false;

	// cac bien luu tru tam thoi
	string tensach = "";
	string ISBN = "";
	string tacgia = "";
	string theloai = "";
	uint sotrang = 0;
	uint namSB = 0;

	CreateBox(X_NOTIFY + 7, Y_NOTIFY, "NOTI:  ", 52);
	BangNhap(79, yDisplay, nngang, keyBangNhapDauSach, 14);
	BangGuides(79, yDisplay + 20, nngang, keyGuide2, 7);
    //neu true = chinh sua thong tin dau sach xuat thong tin cu ra bang
	if (isEdited) {
		// doc thong tin 
		tensach = pDS->info.tensach;
		ISBN = pDS->info.ISBN;
		tacgia = pDS->info.tacgia;
		theloai = pDS->info.theloai;
		sotrang = pDS->info.sotrang;
		namSB = pDS->info.namSB;

		gotoxy(80 + (nngang / 3), yDisplay + 3);
		cout << tensach;
		gotoxy(80 + (nngang / 3), yDisplay + 5);
		cout << ISBN;
		gotoxy(80 + (nngang / 3), yDisplay + 7);
		cout << tacgia;
		gotoxy(80 + (nngang / 3), yDisplay + 9);
		cout << theloai;
		gotoxy(80 + (nngang / 3), yDisplay + 11);
		cout << sotrang;
		gotoxy(80 + (nngang / 3), yDisplay + 13);
		cout << namSB;
	}
    // neu false nhap moi toan bo thong tin
	while (true) {
		switch (ordinal){
		case 0:
			gotoxy(80 + (nngang / 3), yDisplay + 3);
			NhapTenSach(tensach, ordinal, isSave, isEscape);
			break;
		case 1:
			gotoxy(80 + (nngang / 3), yDisplay + 5);
			NhapISBN(ISBN, ordinal, isSave, isEscape);
			break;
		case 2:
			gotoxy(80 + (nngang / 3), yDisplay + 7);
			NhapTenTacGia(tacgia, ordinal, isSave, isEscape);
			break;
		case 3:
			gotoxy(80 + (nngang / 3), yDisplay + 9);
			NhapTheLoaiSach(theloai, ordinal, isSave, isEscape);
			break;
		case 4:
			gotoxy(80 + (nngang / 3), yDisplay + 11);
			nhapSoTrang(sotrang, ordinal, isSave, isEscape);
			break;
		case 5:
			gotoxy(80 + (nngang / 3), yDisplay + 13);
			NhapNamXuatBan(namSB, ordinal, isSave, isEscape);
			break;
		}
		// check Save
		if (isSave){
			// cap nhat lai flag
			isSave = false;
			// check rong;
			if (tensach.length() == 0){
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue; // vong lai vong lap yeu cau nguoi dung nhap
			}
			else if (ISBN.length() == 0){
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}
			else if (tacgia.length() == 0){
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}
			else if (theloai.length() == 0){
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 3;
				continue;
			}
			else if (sotrang == 0){
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 4;
				continue;
			}
			else if (namSB == 0){
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!!";
				normalBGColor();
				ordinal = 5;
				continue;
			}
			//
			else if (namSB > (uint)LayNamHT()){
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "NAM XUAT BAN KHONG LON HON NAM HIEN TAI !!!";
				normalBGColor();
				ordinal = 5;
				continue;
			}
			//kiem tra ISBN da ton tai?
			if (SearchISBN_DS(lDS, ISBN)){
				if (pDS->info.ISBN != ISBN){
					gotoxy(X_NOTIFY + 15, Y_NOTIFY);
					SetColor(BLUE);
					cout << "ISBN VUA NHAP VAO TRUNG VOI ISBN DA CO  !!!";
					normalBGColor();
					// quay lai va dien vao truong du lieu do
					ordinal = 1;
					continue;
				}
			}
            //hoan thanh kiem tra tat ca thong tin
			// truyen thong tin vao info
			info.tensach = ChuanHoaString(tensach);
			info.ISBN = ChuanHoaString(ISBN);
			info.tacgia = ChuanHoaString(tacgia);
			info.theloai = ChuanHoaString(theloai);
			info.sotrang = sotrang;
			info.namSB = namSB;
			//neu cap nhat
			if (isEdited){
				pDS->info = info;
				normalBGColor();
				return;
			}
			else{ // neu them
				// gan NULL cho con tro dms trong DS
				initList_DMS(pDS->dms);
				pDS->info = info;
				int temp = Insert_DauSach(lDS, pDS);
				quickSort_DS(lDS,0,lDS.n);
				if (temp == 0) // them khong thanh cong
					// thong bao ra.
					for (int i = 0; i < 5; i++){
						SetColor(BLUE);
						gotoxy(X_NOTIFY + 15, Y_NOTIFY);
						Sleep(100);
						cout << "BO NHO DA DAY .KHONG THEM DAU SACH MOI VAO DUOC !";
					}
				else {
					// In dong thong bao them thanh cong
					for (int i = 0; i < 5; i++){
						SetColor(BLUE);
						gotoxy(X_NOTIFY + 15, Y_NOTIFY);
						Sleep(100);
						cout << "           SUCCESSFULLY !!! ";
					}
				}
				normalBGColor();
				return;
			}
		}
        // hoan thanh them vao cho nguoi dung nhap ecs
		if (isEscape)
			return;
	}
		ShowCur(false);
}

string getTenSach(LIST_DAUSACH lDS,int pos, int trang){
	trang--;
	pos=pos+ 29*trang;
	if(pos>lDS.n){
		return "               ";
	}
    else{
    	return lDS.ListDS[pos]->info.tensach;
	}
}
// tra ve ma sach vitri pos cua dau sach co vi tri posDauSach 
string getMaNodeDMS(pDAU_SACH pDS,int posCuonSach, int trangc){
	trangc--;
	posCuonSach=posCuonSach+ 29*trangc;
	//string mk = "r";
	int a = pDS->dms.n;
	if(posCuonSach>=a){
		return "     ";
		//return mk;
	}else{
		return Search_DMS2(pDS->dms.pHead,posCuonSach)->data.maSach;
	}
	//return Search_DMS2(pDS->dms.pHead,posCuonSach)->data.maSach;
}

int ChooseItems_DS(LIST_DAUSACH &lDS, int &tttrang, int tongtrang)
{
	int pos = 0;
	int kb_hit;
	pos = 0;
	SetColor(BRIGHT_WHITE);
	SetBGColor(BLUE);
	string keySach = "";
	keySach=getTenSach(lDS, pos, tttrang);
	gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + pos);
	cout << keySach;
	normalBGColor();
	//SetColor(WHITE);

	while (true)
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit)
			{
			case KEY_UP:
				// xoa muc truoc
			 	keySach=getTenSach(lDS, pos, tttrang);
				gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + pos);
				cout << keySach;
				(pos > 0) ? pos-- : pos = 28;

				// to mau muc moi
				SetColor(BRIGHT_WHITE);
				SetBGColor(BLUE);
				keySach=getTenSach(lDS, pos, tttrang);
				gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + pos);
				cout << keySach;
				normalBGColor();
				break;

			case KEY_DOWN:
				// xoa muc truoc
				keySach=getTenSach(lDS, pos, tttrang);
				gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + pos);
				cout << keySach;
				(pos < 28) ? pos++ : pos = 0;

				// to mau muc moi
				SetColor(BRIGHT_WHITE);
				SetBGColor(BLUE);
				keySach=getTenSach(lDS, pos, tttrang);
				gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + pos);
				cout << keySach;
				normalBGColor();
				break;

			case PAGE_UP:
				if (tttrang > 1)
				{
					tttrang--;
				}
				else
				{
					tttrang = tongtrang;
				}
				Xoa_OutDS_29lines();
				OutputDS_PerPage(lDS, tttrang);
				pos = 0;
				SetColor(BRIGHT_WHITE);
				SetBGColor(BLUE);
				keySach=getTenSach(lDS, pos, tttrang);
				gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + pos);
				cout << keySach;
				normalBGColor();
				break;

			case PAGE_DOWN:
				if (tttrang <  tongtrang)
				{
					tttrang++;
				}
				else
				{
					tttrang = 1;
				}
				Xoa_OutDS_29lines();
				OutputDS_PerPage(lDS, tttrang);
				pos = 0;
				SetColor(BRIGHT_WHITE);
				SetBGColor(BLUE);
				keySach=getTenSach(lDS, pos, tttrang);
				gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + pos);
				cout << keySach;
				normalBGColor();
				break;

			case ENTER:
				return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1)* NUMBER_LINES;
				break;
			case ESC:
			return -1;

			}
		}
		ShowCur(false);
		SetColor(WHITE);
		gotoxy(33, 36);
		cout << "Trang " << tttrang << " / " << tongtrang;
		normalBGColor();
	}
}

void Xoa_OutDS_1line(int locate)
{
	gotoxy(xDisplayDS[0] + 1, yDisplay + 3 + locate);
	cout << setw(27) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[1] + 1, yDisplay + 3 + locate);
	cout << setw(4) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[2] + 1, yDisplay + 3 + locate);
	cout << setw(18) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[3] + 1, yDisplay + 3 + locate);
	cout << setw(11) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[4] + 1, yDisplay + 3 + locate);
	cout << setw(6) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[5] + 1, yDisplay + 3 + locate);
	cout << setw(4) << setfill(' ') << ' ';
}

void Xoa_OutDS_29lines()
{
	for (int i = 0; i <NUMBER_LINES; i++)
		Xoa_OutDS_1line(i);
}

void Output_DS(dauSach ds)
{
	ShowCur(false);
	Xoa_OutDS_1line(locate);
	gotoxy(xDisplayDS[0] + 3, yDisplay + 3 + locate);
	cout << ds.tensach;
	gotoxy(xDisplayDS[1] + 1, yDisplay + 3 + locate);
	cout << ds.ISBN;
	gotoxy(xDisplayDS[2] + 1, yDisplay + 3 + locate);
	cout << ds.tacgia;
	gotoxy(xDisplayDS[3] + 1, yDisplay + 3 + locate);
	cout << ds.theloai;

	gotoxy(xDisplayDS[4] + 1, yDisplay + 3 + locate);
	cout << ds.sotrang;
	gotoxy(xDisplayDS[5] + 1, yDisplay + 3 + locate);
	cout << ds.namSB;
	locate++;
}

void OutputDS_PerPage(LIST_DAUSACH &lDS, int index)
{
	Xoa_OutDS_29lines();
	SetColor(WHITE);
	locate = 0;
	index--;
	if (lDS.n == -1)
		return;
	for (int i =  NUMBER_LINES * index;  i < NUMBER_LINES*( 1 + index)  && i <=  lDS.n ; i++)
	{
		Output_DS(lDS.ListDS[i]->info);
	}
}

void ShowInfoDS(pDAU_SACH pDS){

	gotoxy(93, 8);
	cout << "THONG TIN TRA CUU DUOC !";
	gotoxy(82, 11);
	cout << "TEN SACH: " << pDS->info.tensach;
	gotoxy(82, 13);
	cout << "TAC GIA: " << pDS->info.tacgia;
	gotoxy(82, 15);
	cout << "THE LOAI: " << pDS->info.theloai;
	gotoxy(82, 17);
	cout << "NAM XUAT BAN: " << pDS->info.namSB;
	gotoxy(82, 19);					
	cout << "ISBN: " << pDS->info.ISBN;
	gotoxy(82 ,21);
	cout << "TONG SO SACH CUA DAU SACH: " << pDS->dms.n;
	gotoxy(82, 23);
	cout << "SO SACH CON TRONG THU VIEN:  " << pDS->dms.n - TongSoSachDuocMuon(pDS->dms);
	gotoxy(82, 25);
	cout << "CAC MA SACH CON CO TRONG THU VIEN: ";

						// thuc hien in ma sach ra theo dung format.
	int i = 0, j = 0, count = 0;
	for (NODE_DMS* p = pDS->dms.pHead; p != NULL; p = p->pNext)
	{
			gotoxy(82 + i, 26 + j);
			if (p->data.ttSach == 0)
			{
				cout << p->data.maSach;
				i += 10;
				count++;
				if (count == 5)
				{
					j++;
					i = 0;
					count = 0;
				}
			}
	}
	_getch();
	XoaMotVung(82, 1, 35, 50);

			
}


void Output_ListDStheoTT(LIST_DAUSACH lDS)
{
normalBGColor();
	clrscr();
	gotoxy(35, 1);
	cout << "   HIEN THI CAC DAU SACH    ";

	// nDS la so DS hien co trong danh sach tuyen tinh
	int nDS = lDS.n + 1;
	int choose, check;
	LIST_DAUSACH temp;

	gotoxy(3, yHotkey);
	SetColor(WHITE);
	cout << "HotKey:  F9 - TIM THONG TIN SACH, PgUP, PgDn";
	normalBGColor();

	// thu tu trang
	int tttrang, tongtrang;
	tttrang = 1;
	

label1:
	tongtrang = (nDS / NUMBER_LINES) + 1;
	XoaMotVung(79, yDisplay, 30, 53);
	DisplayDS(keyDisplayDS, 6, xDisplayDS);
	quickSort_DS(lDS,0,lDS.n);
	OutputDS_PerPage(lDS, tttrang);

	int kb_hit;
	do
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit)
			{
			case PAGE_UP:
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				OutputDS_PerPage(lDS, tttrang);
				break;

			case PAGE_DOWN:
				(tttrang <  tongtrang) ? tttrang++ : tttrang = 1;
				OutputDS_PerPage(lDS, tttrang);
				break;
			case KEY_F9:
				VeHinhBangNhap(82, 3,50, "         HAY NHAP VAO TEN SACH CAN TRA CUU");
				gotoxy(92, 5);
				check = NhapTenSachTimKiem(tensach);
				// kiem tra dieu kien tra ve .....
				if (check == -1)
				{
					gotoxy(92, 10);
					cout << "BAN VUA HUY TAC VU TRA CUU !!!";
					_getch();
					return;
				}
				else if (check == 1)
				{
					temp = SearchDSByTen(lDS, tensach);
					if (temp.n == -1)
					{
						gotoxy(86, 10);
						cout << "TEN SACH VUA NHAP KHONG CO TRONG THU VIEN !!!";
						_getch();
						XoaMotVung(82, 1, 35, 50);
						goto label1;
					}
					else{
						tongtrang = (temp.n / NUMBER_LINES) +1;
						tttrang  =1;
					label2:	
					
						
						
						XoaMotVung(79, yDisplay, 30, 53);
						DisplayDS(keyDisplayDS, 6, xDisplayDS);
						gotoxy(86, 10);
						
						OutputDS_PerPage(temp, tttrang);
						choose = ChooseItems_DS(temp, tttrang, tongtrang);
						if(choose==-1) goto label1;
						if (choose > temp.n) goto label1;
						
						ShowInfoDS(temp.ListDS[choose]);
						goto label2;
						
					}
				}
			
			case ESC:
				return ;
			}
		}
		ShowCur(false);
		
		gotoxy(33, 36);
		cout << "Trang " << tttrang << " / " << tongtrang;
		tensach = "";//xoa thong tin vua nhap
		
	} while (true);
}


	void Menu_DauSach(LIST_DAUSACH &lDS)
{
	normalBGColor();
	clrscr();
	gotoxy(35, 1);
	cout << "   CAP NHAT DAU SACH    ";	

	// nDS la so DS hien co trong danh sach tuyen tinh
	
	int choose;
	pDAU_SACH pDS;

	gotoxy(3, yHotkey);
	SetColor(WHITE);
	cout << "HotKey:  ESC - Thoat, F2 - Them, F3 - Sua, F4 - Xoa, F10 - Luu, PgUP, PgDn";
	normalBGColor();

	// thu tu trang
	int tttrang, tongtrang;
	tttrang = 1;
	

label1:
	int nDS = lDS.n + 1;
	gotoxy(80,20);
	tongtrang = ((nDS - 1) / NUMBER_LINES) + 1;
	XoaMotVung(79, yDisplay, 30, 53);
	DisplayDS(keyDisplayDS, 6, xDisplayDS);
	quickSort_DS(lDS,0,lDS.n);
	OutputDS_PerPage(lDS, tttrang);

	int kb_hit;
	do
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit)
			{
			case PAGE_UP:
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				OutputDS_PerPage(lDS, tttrang);
				break;

			case PAGE_DOWN:
				(tttrang <  tongtrang) ? tttrang++ : tttrang = 1;
				OutputDS_PerPage(lDS, tttrang);
				break;

			case KEY_F2:
				pDS = new DAU_SACH;
				if (pDS == NULL)
					goto label1;
				Update_DauSach(lDS, pDS, false);
				
				goto label1 ;

			case  KEY_F3:
				choose = ChooseItems_DS(lDS, tttrang, tongtrang);
				if(choose==-1) goto label1;
				if (choose > lDS.n)
					goto label1;
				Update_DauSach(lDS, lDS.ListDS[choose], true);
				goto label1;

			case KEY_F4:
				choose = ChooseItems_DS(lDS, tttrang, tongtrang);
				if(choose==-1) goto label1;
				if (choose > lDS.n)
					goto label1;

				// neu co nguoi muon thi se khong duoc phep xoa .
				if (Check_DMS(lDS.ListDS[choose]->dms.pHead))
				{
					gotoxy(79,20);
					cout << " Dau Sach da co Doc Gia muon nen khong duoc phep xoa !";
					_getch();
					gotoxy(79, 20);
					cout << "                                                      ";

					goto label1;
				}

				else
				
				{
				
				gotoxy(92,20);
				cout<<"BAN CHAC CHAN?";
				int kb_hit1 = _getch();
				if (kb_hit1 == ENTER)
				{
					Delete_DauSach(lDS, choose);
				}
				}
				goto label1;

				// thoat
			case ESC:
				return ;
			}
		}
		ShowCur(false);
		gotoxy(33, 36);
		cout << "Trang " << tttrang << " / " << tongtrang;

	} while (true);
}

//.......................................define danh muc sach....................................
// khoi tao dms 
void initList_DMS(LIST_DMS& l){
	l.n = 0;
	l.pHead = NULL;
}

// kiem tra rong 
bool ListDMSIsEmpty(LIST_DMS l){
	return l.pHead == NULL;
}


//void AddTailList_DMS(LIST_DMS &l, DMS data){
//	// tao Node
////	NODE_DMS *p = GetNode_DMS(data);
//NODE_DMS *p = new NODE_DMS;
//p->data = data; p->pNext = NULL;
//	if (l.pHead == NULL) {
//		l.pHead = l.pTail = p;
//	}
//	else{
//		l.pTail->pNext = p;
//		
//	}
//	l.pTail = p;
//	l.n++;
//}
void Insert_Last(LIST_DMS &l, DMS data)
{
   NODE_DMS *p = new NODE_DMS;
   p->data = data; p->pNext = NULL;
	if (l.pHead == NULL) l.pHead = p;
	else {
	NODE_DMS *Last = l.pHead;
	for ( Last; Last->pNext != NULL ; Last = Last->pNext);
	Last ->pNext = p;
}
l.n++;
}
int position(NODE_DMS *First, string keySearch){
	int vitri;
	NODE_DMS * q;
	q = First;
	vitri = 1;
	
	while (q != NULL && q->data.maSach != keySearch){
		q = q->pNext;
		vitri++;
	}
	if (q == NULL)
		return -1;
	return(vitri);
}

NODE_DMS *nodepointer(NODE_DMS *First, int i){
	NODE_DMS * p;
	int vitri = 1;
	p = First;
	while (p != NULL && vitri < i){
		p = p->pNext;
		vitri++;
	}
	return(p);
}


void Delete_first(NODE_DMS *&First){
	NODE_DMS *p;
	if (First == NULL)
		return;
	else{
		p = First;    // nut can xoa la nut dau
		First = First->pNext;
		delete p;
	}
}

void Delete_after(NODE_DMS *p){
	NODE_DMS * q;
	q = p-> pNext;  // q chi nut can xoa
	p->pNext = q-> pNext;
	delete q;
}


void Delete_batky(pDAU_SACH &pDS, string keySearch){
	int pos;
	pos = position(pDS->dms.pHead, keySearch);
	// truong hop xoa dau
	if (pos == 1){
		Delete_first(pDS->dms.pHead );
		pDS->dms.n--;
		
	}
	else{  //p chi toi nut truoc nut can xoa
		NODE_DMS  *p = nodepointer(pDS->dms.pHead , pos - 1);
		Delete_after(p);

		
		pDS->dms.n--;
		
	}
}

void ClearAll_ListDMS(LIST_DMS &l){
	NODE_DMS * p;
	while (l.pHead != NULL){
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
//	l.pTail = NULL;
}
// check sach da co nguoi muon chua
bool Check_DMS(NODE_DMS* nDMS){
	for (NODE_DMS* p = nDMS; p != NULL; p = p->pNext){
		// sach da co nguoi muon.
		if (p->data.ttSach == 1)
			return true;
	}
	return false;
}
// tim kiem sach dua tren masach
NODE_DMS* Search_DMS1(pDAU_SACH pDS, string masach){
	NODE_DMS* p;
	p = pDS->dms.pHead;
	while (p != NULL && p->data.maSach != masach)
		p = p->pNext;
	return (p);
}
//tim kiem 1 quyen sach thuoc danh muc sach cua 1 dau sach dua tren vi tri 
NODE_DMS* Search_DMS2(NODE_DMS* dms, int pos){
	int count = -1;

	for (NODE_DMS* temp = dms; temp != NULL; temp = temp->pNext){
		count++;
		if (pos == count)
			return temp;
	}
	return NULL;
}

int NhapSach(pDAU_SACH &pDS, string &viTri){
	DMS info;
	// hien con tro nhap
	ShowCur(true);
	normalBGColor();
	int nngang = (int)keyBangNhapDanhMucSach[0].length();
	CreateBox(40, Y_NOTIFY + 2, "NOTIFICATIONS:  ", 66);
	BangNhap(38, yDisplay + 2, nngang, keyBangNhapDanhMucSach, 8);
	BangGuides(38, yDisplay + 22, nngang, keyGuide3, 4);

	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 1;
	bool isSave = false;
	bool isEscape = false;

	// cac bien luu tru tam thoi
	// ma sach = isbn + stt;   aaaa1..aaaa2....aaaa3....aaaa4
	// toString(++pDS->dms.n)  chuyen kieu int thanh kieu nguyen.
	int stt = pDS->dms.n;
//	int stt = 0;
	string maSach = pDS->info.ISBN + to_string(++stt);

	// neu maSach co trung thi tang ma sach len.
	while (Search_DMS1(pDS, maSach) != NULL){
		stt++;
		
		maSach = pDS->info.ISBN + to_string(stt);
	}
	
	uint ttSach = 3;
	

	gotoxy(40 + (nngang / 3), yDisplay + 5);
	cout << maSach;
	gotoxy(62, 11);
		cout << viTri;
	while (true)
	{
		switch (ordinal)
		{
		case 1:

			NhapTrangThaiSach(ttSach, ordinal, isSave, isEscape, 40 + (nngang / 3), yDisplay + 7);
			break;
		case 2:

			NhapViTri(viTri, ordinal, isSave, isEscape, 40 + (nngang / 3), yDisplay + 9);
			break;
		}

		// check Save
		if (isSave)
		{
			// cap nhat lai flag
			isSave = false;

			// check rong;
			if (ttSach == 3)
			{
				gotoxy(55, Y_NOTIFY + 2);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}

			if (viTri.length() == 0)
			{
				gotoxy(55, Y_NOTIFY + 2);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}

			// import data vao info
			info.maSach = maSach;
			info.ttSach = ttSach;
			info.viTri = viTri;

//			AddTailList_DMS(pDS->dms, info);
			Insert_Last(pDS->dms,info);
			return 0;
		}
		if (isEscape)
		{
			return -1;
		}
	}
}
void NhapDanhMucSach(pDAU_SACH &pDS)
{
	clrscr();
	//system("color 3E");
	normalBGColor();
	int check1 = 0 ;
	int i = 0;
	gotoxy(39, 2);
	cout << "BAN DANG NHAP THONG TIN VAO DANH MUC SACH CUA DAU SACH : " << pDS->info.tensach;
	/*gotoxy(60, 16);
	cout << "SO SACH DA NHAP: " << sosach << endl;*/
	gotoxy(51, 17);
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	gotoxy(52, 31);
	cout << " HotKey:   F10 - Luu ,  ESC - Thoat ";

	string viTri = "";
	while (check1!=-1)
	{
		// nhap dms sach
		
		check1 = NhapSach(pDS, viTri);


		XoaMotVung(38, yDisplay + 2, 10, (int)keyBangNhapDanhMucSach[0].length());
//		gotoxy(62, 11);
//		cout << viTri;
		gotoxy(60, 18);
		cout << "SO SACH DA NHAP : " << i + 1;
		i++;
	}
	
	Output_ListDMS(pDS);
}
int SuaDanhMucSach(pDAU_SACH &pDS, NODE_DMS* dms){
	DMS info;
	// kiem tra dieu kien.
	if (dms->data.ttSach == 1)
		return 2;

	// hien con tro nhap
	ShowCur(true);
	normalBGColor();

	int nngang = (int)keyBangNhapDanhMucSach[0].length();

	CreateBox(67, Y_NOTIFY + 2, "NOTIFICATIONS:  ", 66);
	BangNhap(65, yDisplay + 6, nngang, keyBangNhapDanhMucSach, 8);
	BangGuides(65, yDisplay + 22, nngang, keyGuide3, 4);

	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 1;
	bool isSave = false;
	bool isEscape = false;

	string maSach = dms->data.maSach;

	uint ttSach = dms->data.ttSach ;
	string viTri = dms->data.viTri;

	gotoxy(67 + (nngang / 3), yDisplay + 9);
	cout << maSach;

	gotoxy(89, yDisplay + 11);
	if (ttSach == 0)
		cout << ttSach << ":   CHO MUON DUOC  ";
	else if (ttSach == 1)
		cout << ttSach << ":   DA DUOC MUON   ";
	else if (ttSach == 2)
		cout << ttSach << ":   DA THANH LY    ";

	gotoxy(89, yDisplay + 13);
	cout << viTri;
	while (true)
	{
		switch (ordinal)
		{
		case 1:

			NhapTrangThaiSach(ttSach, ordinal, isSave, isEscape, 89,  yDisplay + 11);
			break;
		case 2:

			NhapViTri(viTri, ordinal, isSave, isEscape, 89, yDisplay + 13);
			break;
		}

		// check Save
		if (isSave)
		{
			// cap nhat lai flag
			isSave = false;

			// check rong;
			if (ttSach == 3)
			{
				gotoxy(67, Y_NOTIFY + 2);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}

			if (viTri.length() == 0)
			{
				gotoxy(67, Y_NOTIFY + 2);
				SetColor(BLUE);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				normalBGColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}

			// import data vao info
			info.maSach = maSach;
			info.ttSach = ttSach;
			info.viTri = viTri;

			dms->data = info;
			return 1;
		}
		if (isEscape)
		{
			return -1;
		}
	}

}

void Xoa_OutDMS_1line(int locate)
{
	gotoxy(xDisplayDMS[0] + 1, yDisplay + 3 + locate);
	cout << setw(11) << setfill(' ') << ' ';
	gotoxy(xDisplayDMS[1] + 1, yDisplay + 3 + locate);
	cout << setw(13) << setfill(' ') << ' ';
	gotoxy(xDisplayDMS[2] + 1, yDisplay + 3 + locate);
	cout << setw(34) << setfill(' ') << ' ';
}

void Xoa_OutDMS_29lines()
{
	for (int i = 0; i <NUMBER_LINES; i++)
	{
		Xoa_OutDMS_1line(i);
	}
}

int ChooseItems1(pDAU_SACH &pDS, int &tttrang, int tongtrang)
{
	int pos = 0;
	int kb_hit;
	pos = 0;
	SetColor(BRIGHT_WHITE);
	SetBGColor(BLUE);
	string keyMaSach = "";
	keyMaSach=getMaNodeDMS(pDS, pos, tttrang);
	gotoxy(xDisplayDS[0] + 4, yDisplay + 3 + pos);
	cout << keyMaSach;
	normalBGColor();

	while (true)
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit)
			{
			case KEY_UP:
				// xoa muc truoc
				keyMaSach=getMaNodeDMS(pDS, pos, tttrang);
				gotoxy(xDisplayDS[0] + 4, yDisplay + 3 + pos);
				cout << keyMaSach;
				(pos > 0) ? pos-- : pos = 28;

				// to mau muc moi
				SetColor(BRIGHT_WHITE);
				SetBGColor(BLUE);
				keyMaSach=getMaNodeDMS(pDS, pos, tttrang);
				gotoxy(xDisplayDS[0] + 4, yDisplay + 3 + pos);
				cout << keyMaSach;
				normalBGColor();
				break;

			case KEY_DOWN:

				// xoa muc truoc
				keyMaSach=getMaNodeDMS(pDS, pos, tttrang);
				gotoxy(xDisplayDS[0] + 4, yDisplay + 3 + pos);
				cout << keyMaSach;
				(pos < 28) ? pos++ : pos = 0;

				// to mau muc moi
				SetColor(BRIGHT_WHITE);
				SetBGColor(BLUE);
				keyMaSach=getMaNodeDMS(pDS, pos, tttrang);
				gotoxy(xDisplayDS[0] + 4, yDisplay + 3 + pos);
				cout << keyMaSach;
				normalBGColor();
				break;

			case PAGE_UP:
				if (tttrang > 1)
				{
					tttrang--;
				}
				else
				{
					tttrang = tongtrang;
				}
				Xoa_OutDMS_29lines();
				OutputDMS_PerPage(pDS, tttrang);

				pos = 0;
				SetColor(BRIGHT_WHITE);
				SetBGColor(BLUE);
				keyMaSach=getMaNodeDMS(pDS, pos, tttrang);
				gotoxy(xDisplayDS[0] + 4, yDisplay + 3 + pos);
				cout << keyMaSach;
				normalBGColor();
				break;

			case PAGE_DOWN:
				if (tttrang <  tongtrang)
				{
					tttrang++;
				}
				else
				{
					tttrang = 1;
				}
				Xoa_OutDMS_29lines();
				OutputDMS_PerPage(pDS, tttrang);
				pos = 0;
				SetColor(BRIGHT_WHITE);
				SetBGColor(BLUE);
				keyMaSach=getMaNodeDMS(pDS, pos, tttrang);
				gotoxy(xDisplayDS[0] + 4, yDisplay + 3 + pos);
				cout << keyMaSach;
				normalBGColor();
				break;

			case ENTER:
				keyMaSach=getMaNodeDMS(pDS, pos, tttrang);
				/*gotoxy(xDisplayDS[0] + 4, yDisplay + 3 + pos);
				cout << keyMaSach;*/
				//normalBGColor();
				return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1)* NUMBER_LINES;
				

			case ESC:
				return -1;
				//normalBGColor();
			}
		}
		//normalBGColor();
		ShowCur(false);
		gotoxy(33, 36);
		cout << "Trang " << tttrang << " / " << tongtrang;
	}
}

void Output_DMS(DMS dms)
{
	Xoa_OutDMS_1line(locate);
	gotoxy(xDisplayDMS[0] + 3, yDisplay + 3 + locate);
	cout << dms.maSach;
	gotoxy(xDisplayDMS[1] + 1, yDisplay + 3 + locate);
	if (dms.ttSach == 0)
	{
		cout << "Cho Muon Duoc";
	}
	else if (dms.ttSach == 1)
	{
		cout << "Da Cho Muon";
	}
	else if (dms.ttSach == 2)
	{
		cout << "Da Thanh Ly";
	}
	gotoxy(xDisplayDMS[2] + 10, yDisplay + 3 + locate);
	cout << dms.viTri;
	locate++;
}

void OutputDMS_PerPage(pDAU_SACH pDS, int index)
{
	Xoa_OutDMS_29lines();
	locate = 0;
	if (pDS->dms.pHead == NULL)
		return;
	index--;
	index *= NUMBER_LINES;
	int count = 0;
	NODE_DMS * temp = NULL;
	// lay node dms tai vi tri index
	for ( temp = pDS->dms.pHead ; temp != NULL  && count < index ; temp = temp->pNext)
	{
		count++;
	}
	// xuat tu tu list ra 1 page toi da 29 node dms bat dau = temp vua lay o tren
	for (int i = 0; i < NUMBER_LINES && temp != NULL; i++)
	{
		Output_DMS(temp->data);
		temp = temp->pNext;
	}
	return;
}

void Output_ListDMS(pDAU_SACH &pDS)
{
	// thu tu trang
	clrscr();
	int check1;
	int check2;
	int check3;
	int tttrang, tongtrang;
	
	tttrang = 1;
	
	NODE_DMS* temp = NULL, *temp1 = NULL;
	

	label:
	if (pDS->dms.n == 0)
	{
		NhapDanhMucSach(pDS);
	}
	gotoxy(8, 1);
	cout << " BANG DANH MUC SACH CUA DAU SACH : " << pDS->info.tensach;
	tongtrang = ((pDS->dms.n -1 ) / NUMBER_LINES) + 1;
	DisplayDMS(keyDisplayDMS, 3, xDisplayDMS);
//	selectionsort_DMS(pDS->dms);
	OutputDMS_PerPage(pDS, tttrang);
	string keySearch = "";
	
	int kb_hit;
	do
	{
		XoaMotVung(65,2,  30, 67);
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit)
			{
			case PAGE_UP:
				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				OutputDMS_PerPage(pDS, tttrang);
				break;

			case PAGE_DOWN:
				(tttrang <  tongtrang) ? tttrang++ : tttrang = 1;
				OutputDMS_PerPage(pDS, tttrang);
				break;
			case  KEY_F2:
				
				NhapDanhMucSach(pDS);
				goto label;
			case  KEY_F3:
				VeHinhBangNhap(82, 3, 38, " HAY NHAP VAO MA SACH CAN HIEU CHINH");
				gotoxy(96, 5);
				check1 = NhapMaSach(keySearch);

				// kiem tra dieu kien tra ve .....
				if (check1 == -1)
				{
					gotoxy(84, Y_NOTIFY + 12);
					cout << "BAN VUA HUY TAC VU HIEU CHINH !!!";
					_getch();
				}
				else if (check1 == 1)
				{
					temp = Search_DMS1(pDS, keySearch);
					if (temp == NULL)
					{
						gotoxy(77, Y_NOTIFY + 12);
						cout << "BAN VUA NHAP MA SACH " << "'" << keySearch << "'" << " KHONG CO TRONG DU LIEU";
						_getch();
					}
					else
					{
						check3 = SuaDanhMucSach(pDS, temp);

						// kiem tra cac truong hop.
						if (check3 == 1)
						{
							gotoxy(73, Y_NOTIFY + 12);
							cout << "BAN VUA HIEU CHINH THONG TIN SACH CO MA SACH LA: " << keySearch;
							_getch();
						}
						else if (check3 == 2)
						{
							gotoxy(73, Y_NOTIFY + 12);
							cout << "Sach da co Doc Gia muon nen khong duoc phep hieu chinh !";
							_getch();
							gotoxy(73, Y_NOTIFY + 12);
							cout << "                                                        ";
						}
						else
						{
							gotoxy(82, Y_NOTIFY + 12);
							cout << "BAN VUA HUY TAC VU HIEU CHINH !!!";
							_getch();
						}
					}
				}

				goto label;

			case KEY_F4:
				VeHinhBangNhap(82, 3, 35,  "     HAY NHAP VAO MA SACH DE XOA   ");
				gotoxy(96, 5);
				check1 = NhapMaSach(keySearch);

				// kiem tra dieu kien tra ve .....
				if (check1 == -1)
				{
					gotoxy(88, 10);
					cout << "BAN VUA HUY TAC VU XOA !!!";
					_getch();
				}
				else if (check1 == 1)
				{
					temp1 = Search_DMS1(pDS, keySearch);
					
					// da co doc gia muon.
					if (temp1 == NULL)
						{
							gotoxy(75, 10);
							cout << "BAN VUA NHAP MA SACH " << "'" << keySearch << "'" << " KHONG CO TRONG DU LIEU";
							_getch();
						}
					else if (temp1->data.ttSach == 1)
					{
						gotoxy(78, 20);
						cout << "Sach da co Doc Gia muon nen khong duoc phep xoa !";
						_getch();
						gotoxy(78, 20);
						cout << "                                                      ";
					}
					else
					{
						gotoxy(92,10);
						cout<<"BAN CHAC CHAN?";
						int kb_hit1 = _getch();
						if (kb_hit1 == ENTER){
							Delete_batky(pDS, keySearch);
						}

					}
				}
				goto label;

			case ESC:
				return;
			}
		}
		ShowCur(false);
		gotoxy(3, 35);
		cout << "HotKey: F2 - Them sach  F3 - Hieu chinh  F4 - Xoa  ESC - Thoat";
		gotoxy(54, 36);
		cout << "Trang " << tttrang << " / " << tongtrang;

	} while (true);
}



void Menu_DMS(LIST_DAUSACH &lDS){
	//system("color 3E");
	normalBGColor();
	int choose;
	int nDS = lDS.n + 1;
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
	int temp = 1;

	do
	{
		clrscr();

		// hien thi bang chua thong tin dau sach
		DisplayDS(keyDisplayDS, 6, xDisplayDS);
		OutputDS_PerPage(lDS, tttrang);

		gotoxy(23, 1);
		//SetBGColor(GREEN);
		cout << "CHON DAU SACH DE CAP NHAT DANH MUC SACH";
		normalBGColor();

		// chon dau sach muon nhap sach vao
		choose = ChooseItems_DS(lDS, tttrang, tongtrang);

		// check cac truong hop ...
		if (choose == -1)
		{
			return ;
		}
		else if (choose > lDS.n)
		{
			gotoxy( 2 , yDisplay + 3 + choose % NUMBER_LINES);
			cout << setw(27) << setfill(' ') << ' ';
			continue;
		}

			// bat dau nhap thong tin sach
//			NhapDanhMucSach(lDS.ListDS[choose]);
			Output_ListDMS(lDS.ListDS[choose]);
	
	} while (true);
}
// tong so sach da duoc muon cua mot dau sach 
int TongSoSachDuocMuon(LIST_DMS dms){
	int dem = 0;
	NODE_DMS *temp = NULL;
	for (temp = dms.pHead; temp != NULL; temp = temp->pNext){
		//  tinh ca sach da muon va da muon nhung lam mat.
		if (temp->data.ttSach == 1   ||  temp->data.ttSach == 2)
			dem++;
	}
	return dem;
}
// sort 10 sach co luot muon nhieu nhat 
void Sort_Top10(TopSach *top10, int l, int r)
{
	TopSach temp;
	int i = l;
	int j = r;
	int x = top10[(l + r) / 2].sosachmuon;

	do{ 
		while (top10[i].sosachmuon > x)
			i++; 
		while (top10[j].sosachmuon < x)
			j--; 

		if (i <= j) {
			temp = top10[i];
			top10[i] = top10[j];
			top10[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (l<j) 	
		Sort_Top10(top10, l, j);
	if (i < r)   
		Sort_Top10(top10, i, r);
}
// in ra danh sach 10 sach duoc muon nhieu nhat
void Top10Sach(LIST_DAUSACH lDS)
{
	//system("color 3E");
	normalBGColor();
	clrscr();
	int count = 0;
	TopSach *top10 = new TopSach[lDS.n + 1];

	// nhap thong tin vao mang.
	for (int i = 0; i <= lDS.n; i++)
	{
		top10[i].tensach = lDS.ListDS[i]->info.tensach;
		top10[i].sosachmuon = lDS.ListDS[i]->info.luotmuon;
	}

	Sort_Top10(top10, 0, lDS.n);
	// in thong tin ra  console
	gotoxy(50, 2);
	//SetBGColor(GREEN);
	cout << "TOP 10 DAU SACH CO SO LUOC MUON NHIEU NHAT ";
	normalBGColor();
	int j = 0;
	while (top10[j].sosachmuon != 0 && j < 10   ||  top10[j].sosachmuon == top10[j + 1].sosachmuon  && top10[j].sosachmuon != 0)
	{
		SetColor(WHITE);
		gotoxy(xDisplayTop10[1] + 3, yDisplayTop10 + 2 + j);
		cout << top10[j].tensach;
		gotoxy(xDisplayTop10[2] + 16, yDisplayTop10 + 2 + j);
		cout << top10[j].sosachmuon;
		gotoxy(xDisplayTop10[0] + 7, yDisplayTop10 + 2 + j);
		j++;
		cout << j;

	}

	DisplayTop10(keyDisplayTop10, 3, xDisplayTop10, j + 2);
	_getch();
	// xoa vung nho....
	delete[] top10;
}

