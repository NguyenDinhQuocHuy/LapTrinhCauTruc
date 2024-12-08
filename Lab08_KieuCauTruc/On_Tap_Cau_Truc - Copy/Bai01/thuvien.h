#define MAX 100
#define TAB '\t'

struct NgayThang
{
	unsigned short Ngay;
	unsigned short Thang;
	unsigned short Nam;
};

struct NhanVien
{
	unsigned int MaSo;
	char HoTen[MAX];
	char GioiTinh[MAX];
	char DiaChi[MAX];
	NgayThang NgaySinh;
	float HeSoLuong;
};

typedef NhanVien MangNV[MAX];

// Khai bao nguyen mau cac ham xu ly
void XuatTieuDe();
void XuatDongKeNgang();
void XuatMotNV(NhanVien nv);
void XuatDSNV(MangNV a, int n);
void NhapMotNV(NhanVien& nv);
void NhapDSNV(MangNV a, int n);
int KiemTraMaNV(MangNV a, int n, int maSo);
void ThemMotNV(MangNV a, int& n);
int TimTheoMaSo(MangNV a, int n, int maSo);
void CapNhatNV(NhanVien& nv);
int TimNVTheoNamSinh(MangNV a, int n, unsigned short namSinh);
void HoanVi(NhanVien& x, NhanVien& y);
void SapGiamTheoHeSoLuong(MangNV a, int n);

// Dinh nghia ham
void XuatTieuDe()
{
	cout << endl
		<< setiosflags(ios::left)
		<< setw(6)  << "Ma So"
		<< setw(25) << "Ho va Ten"
		<< setw(10) << "Gioi tinh"
		<< setw(25) << "Dia chi"
		<< setw(15) << "Ngay sinh"
		<< setw(11) << "He so luong"
		<< endl;
}

void XuatDongKeNgang()
{
	cout << endl
		<< setiosflags(ios::left)
		<< setw(6)  << "====="
		<< setw(25) << "========================"
		<< setw(10) << "========="
		<< setw(25) << "========================"
		<< setw(15) << "=============="
		<< setw(11) << "=========="
		<< endl;
}

void XuatMotNV(NhanVien nv)
{
	cout << endl
		<< setiosflags(ios::left)
		<< setw(6)  << nv.MaSo
		<< setw(25) << nv.HoTen
		<< setw(10) << nv.GioiTinh
		<< setw(25) << nv.DiaChi
		<< setw(2)  << nv.NgaySinh.Ngay << "/ "
		<< setw(2)  << nv.NgaySinh.Thang << "/ "
		<< setw(7)  << nv.NgaySinh.Nam
		<< setw(11) << nv.HeSoLuong
		<< endl;
}

void XuatDSNV(MangNV a, int n)
{
	XuatTieuDe();
	XuatDongKeNgang();
	for (int i = 0; i < n; i++)
	{
		XuatMotNV(a[i]);
	}
	XuatDongKeNgang();
	cout << endl;
}

void NhapMotNV(NhanVien& nv)
{
	cout << "Nhap ma so nhan vien: ";
	cin >> nv.MaSo;

	cout << "Nhap ho va ten: ";
	cin.ignore(1);
	gets_s(nv.HoTen);

	cout << endl << "Nhap gioi tinh: ";
	gets_s(nv.GioiTinh);
	
	cout << "Nhap dia chi: ";
	gets_s(nv.DiaChi);

	cout << "Nhap ngay sinh (Thu tu ngay thang nam): ";
	cin >> nv.NgaySinh.Ngay 
		>> nv.NgaySinh.Thang 
		>> nv.NgaySinh.Nam;

	cout << "Nhap he so luong: ";
	cin >> nv.HeSoLuong;
}

void NhapDSNV(MangNV a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl << "Nhan vien thu " << i + 1 << ": " << endl;
		NhapMotNV(a[i]);
	}
	cout << endl << "Da nhap xong !" << endl;
}

int KiemTraMaNV(MangNV a, int n, int maSo)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].MaSo == maSo)
			return 1;
		return 0;
	}
}

void ThemMotNV(MangNV a, int& n)
{
	NhanVien nv;
	NhapMotNV(nv);
	while (KiemTraMaNV(a, n, nv.MaSo))
	{
		cout << endl << "Ma so " << nv.MaSo << " da bi trung, nhap lai ma khac: ";
		cin >> nv.MaSo;
	}
	a[n] = nv; // Luu nhan vien moi vao cuoi mang
	n++; // Tang so luong nhan vien
}

int TimTheoMaSo(MangNV a, int n, int maSo)
{
	for (int i = 0; i < n; i++)
		if (a[i].MaSo == maSo)
			return i;
	return -1;
}

void CapNhatNV(NhanVien& nv)
{
	char traLoi;

	cout << endl << "Ban co muon doi ho ten (Y/N) ?";
	traLoi = _getch();
	if (traLoi == 'y' || traLoi == 'Y')
	{
		cout << endl << "Nhap ho va ten: ";
		cin.ignore(1);
		gets_s(nv.HoTen);
	}
	else cout << endl;

	cout << endl << "Ban co muon doi dia chi (Y/N) ?";
	traLoi = _getch();
	if (traLoi == 'y' || traLoi == 'Y')
	{
		cout << endl << "Nhap dia chi: ";
		cin.ignore(1);
		gets_s(nv.DiaChi);
	}
	else cout << endl;

	cout << endl << "Ban co muon doi ngay sinh (Y/N) ? ";
	traLoi = _getch();
	if (traLoi == 'y' || traLoi == 'Y')
	{
		cout << endl << "Nhap ngay sinh: ";
		cin.ignore();
		cin >> nv.NgaySinh.Ngay >> nv.NgaySinh.Thang >> nv.NgaySinh.Nam;
	}
	else cout << endl;

	cout << endl << "Ban co muon doi he so luong (Y/N) ?";
	traLoi = _getch();
	if (traLoi == 'y' || traLoi == 'Y')
	{
		cout << endl << "Nhap he so luong: ";
		cin >> nv.HeSoLuong;
	}
}

int TimNVTheoNamSinh(MangNV a, int n, unsigned short namSinh)
{
	int dem = 0;
	XuatTieuDe();
	XuatDongKeNgang();
	for (int i = 0; i < n; i++)
		if (a[i].NgaySinh.Nam == namSinh)
		{
			XuatMotNV(a[i]);
			dem++;
		}
	XuatDongKeNgang();
	return dem;
}

void HoanVi(NhanVien& x, NhanVien& y)
{
	NhanVien tam;
	tam = x;
	x = y;
	y = tam;
}

void SapGiamTheoHeSoLuong(MangNV a, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].HeSoLuong < a[j].HeSoLuong)
				HoanVi(a[i], a[j]);
}