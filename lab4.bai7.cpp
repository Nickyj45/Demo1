#include <bits/stdc++.h>
#define e endl
#define for(i,a,b) for(int i=(a); i<(b);i++)
using namespace std;
class hanghoa{
	protected :
	    int ma;
		char ten[30];
		float gia;
	public :
		hanghoa(int ma=0, char *ten="", float gia=0){
		    this ->ma=ma;
			strcpy(this ->ten,ten);
			this ->gia=gia;
		}
		~hanghoa(){
		}
		void nhap(){
			cout<<"Nhap ma :";
			cin>>ma;
			cout<<"Nhap ten :";
			fflush(stdin);
			cin.getline(ten,30);
			cout<<"Nhap gia : ";
			cin>>gia;
		}
		void in(){
			cout<<"\t"<<ma<<setw(12)<<ten<<setw(12)<<gia;
		}
		int getma(){
			return ma;
		}
		char *getten(){
			return ten;
		}
};
class MT : public hanghoa{
	protected :
		int tocdo;
		int sluong;
	public :
		MT(int tocdo=0, int sluong=0){
			this ->tocdo=tocdo;
			this ->sluong=sluong;
		}
		~MT(){
			
		}
		friend istream & operator >>(istream &i, MT &a){
			a.nhap();
			cout<<"Nhap toc do:";
			i>>a.tocdo;
			cout<<"Nhap so luong:";
			i>>a.sluong;
			return i;
		}
		int tien(){
			cout<< sluong * gia;
			return sluong * gia;
		}
		friend ostream & operator <<(ostream &o, MT &a){
			a.in();
			o<<setw(10)<<a.tocdo<<setw(12)<<a.sluong<<setw(12)<<a.tien();
			return o;
		}
		int gettocdo(){
			return tocdo;
		}
		
};
class MTXT : public MT{
	protected :
		float tluong;
	public :
		MTXT(float tluong=0){
			this ->tluong=tluong;
		}
		~MTXT(){
		}
		friend istream & operator >>(istream &i, MTXT &a){
			MT *temp= &a;
			i>> *temp;
			cout<<"Nhap trong luong:";
			i>>a.tluong;
			return i;
		}
		float phi_btri(){
			cout<< (5 / 100) * gia;
			return (5 / 100) * gia;
		}
		friend ostream & operator <<(ostream &o, MTXT &a){
			MT *temp = &a;
			o<<*temp;
			o<<setw(10)<<a.tluong<<setw(15)<<a.phi_btri()<<e;
			return o;
		}
		int gettluong(){
			return tluong;
		}
		void sua(){
			MT *temp=this;
			cout<<"Nhap thong tin may tinh:\n";
			cin>>*temp;
			cout<<"Nhap trong luong:";
			cin>>tluong;
		}
		void tieude(){
			cout<<"\t"<<"Ma  |"<<setw(10)<<"Ten  |"<<setw(10)<<"Gia       |"<<setw(12)<<"Toc do        |"<<setw(12)<<"So luong       |"<<setw(11)<<"Tien    |  "<<setw(10)<<"Trong luong  |"<<setw(11)<<"  Phi bao tri"<<e;
		}
};

void nhap_ds(MTXT a[], int &n){
	cout<<"Nhap so may:";
	cin>>n;
	for(i,0,n){
		cout<<"Nhap may thu:"<<i+1<<e;
		cin>>a[i];
	}
}
void in_ds(MTXT a[], int &n){
	cout<<"Danh sach may tinh ------------------------------------\n";
	for(i,0,n){
		a[i].tieude();
		cout<<a[i];
	}
}
void tim(MTXT a[], int &n){
	int tk;
	cout<<"Nhap ma so:";
	cin>>tk;
	bool kt=false;
	for(i,0,n){
		if(a[i].getma()==tk){
			a[i].tieude();
			cout<<a[i];
			kt =true;
		}
		if(!kt){
			cout<<"Khong co may nao co so giong nhau!!!!!!!!!!!!!!\n";
		}
	}
}
void lietke(MTXT a[], int &n){
	cout<<"Danh sach may tinh co ten giong nhau la-------------------\n";
	bool kt =false;
	for(i,0,n-1){
		for(j,i+1,n){
			if(strcmp(a[i].getten(),a[j].getten())==0){
				a[i].tieude();
				cout<<a[i];
				a[j].tieude();
				cout<<a[j];
				kt=true;
			}
			if(!kt){
				cout<<"Khong co may nao cung ten!!!!!!!!!!!!!!!!!\n";
			}
		}
	}
}
int tong_phi(MTXT a[], int &n){
	int sum=0;
	for(i,0,n){
		sum= sum + a[i].phi_btri();
	}
	cout<<"Tong phi bao tri cac may la:"<<sum<<e;
}
void timtocdo(MTXT a[], int &n){
    int min=a[0].gettocdo();
    
	for(i,0,n){
		if(a[0].gettocdo() > a[i].gettocdo()){
			min =a[i].gettocdo();
			
	}
		cout<<"May tinh co toc do nho nhat la:\n";
		      a[min].tieude();
			cout<<a[min]<<e;
		
	}
	}
void xoa(MTXT a[], int &n){
	bool kt=false;
	
	for(i,0,n){
		if(a[i].getma()=='1'){
			kt =true;
			break;
			
		}
		if(kt){
			for(i,0,n){
				a[i]=a[i+1];
				i--;
				n--;
			}
			in_ds(a,n);
		}
		else {
			cout<<"Khong co ma giong vay!!!!!!!!\n";
		}
}
}
void sx(MTXT a[], int &n){
	for(i,0,n-1){
		for(j,i+1,n){
			if(a[i].getma() > a[j].getma()){
				swap(a[i],a[j]);
			}
		}
	}
	cout<<"Danh sach sau sap xep la:--------------------\n";
	for(i,0,n){
	    a[i].tieude();
		cout<<a[i]<<e;
	}
}
void chen(MTXT a[], int k, int &n){
	MTXT mtnew;
	mtnew.sua();
	for(i,k,n){
		a[i]=a[i-1];
	}
	a[k].tieude();
	a[k] = mtnew;
	n++;
}
int main(){
	const int max =100;
	MTXT a[max];
    int n;
	MTXT b;
	int chon;
	do {
		cout<<"-----------------------MENU----------------------\n";
		cout<<"1. Nhap danh sach may tinh.\n";
		cout<<"2. Hien thi danh sach ma tinh.\n";
		cout<<"3. Tim thong tin may tinh theo ma.\n";
		cout<<"4. Liet ke may tinh theo ten.\n";
		cout<<"5. Tong phi bao tri cua may tinh.\n";
		cout<<"6. Tim may tinh co toc do nho nhat.\n";
		cout<<"7. Sua thong tin 1 may tinh.\n";
		cout<<"8. Xoa thong tin 1 may tinh.\n";
		cout<<"9. Chen them 1 may tinh tai vi tri k.\n";
		cout<<"10. Sap xep tang dan  theo ma may.\n";
		cout<<"0. Thoat chuong trinh.\n";
		cout<<"----------------------------------------------------\n";
		cout<<"Nhap lua chon:";
		cin>>chon;
	    
		switch (chon){
		case 1 :
			
			nhap_ds(a,n);
			break;
		case 2 :
			in_ds(a,n);
			break;
		case 3 :
			tim(a,n);
			break;
		case 4 :
			lietke(a,n);
			break;
		case 5 :
			tong_phi(a,n);
			break;
		case 6 :
			timtocdo(a,n);
			break;
		case 7 :
			
			
			b.sua();
			break;
		case 8 :
			xoa(a,n);
			break;
		case 9 :
			int k;
			cout<<"Nhap vi tri:";
			cin>>k;
			chen(a,k,n);
			break;
		case 10 :
			sx(a,n);
			break;
		case 0 :
			cout<<"Het chuong trinh!!!!!!!!!!\n";
			break;
		default :
			cout<<"Nhap k hop le, moi nhap lai:\n";
	}
	} while(chon !=0);

	return 0;
}