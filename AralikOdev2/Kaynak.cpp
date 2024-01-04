/***********************************************************************************************************************************************************
																	SAKARYA ÜNÝVERSÝTESÝ
														   BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
															   BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
																 PROGRAMLAMAYA GÝRÝÞ DERSÝ
															 ÖDEV NUMARASI.....:2.ÖDEV
															 ÖÐRENCÝ ADI.......:HÜSEYÝN AKBAL
															 ÖÐRENCÝ NUMARASI..:G211210069
															 DERS GRUBU........:2.ÖÐRETÝM C GRUBU
***********************************************************************************************************************************************************/
#include <iostream>
#include <math.h>

using namespace std;
int menuSecenek;
char menuDevam;
const double pi = 3.14159265;

class KarmasikSayi {
private:
	float sanal, gercel;

	float radyantDerece(float x)
	{
		return x * 180 / pi;
	}
public:
	KarmasikSayi()
	{
		gercel = 0;
		sanal = 0;
		cout << "Yapici fonk calisti ..." << endl;
	}
	KarmasikSayi(float g, float s)
	{
		gercel = g;
		sanal = s;
		cout << "Iki parametreli yapici fonk calisti ..." << endl;
	}
	~KarmasikSayi()
	{
		cout << "Yikici fonk calisti ..." << endl;
	}
	void setGercel(float gercel)
	{
		this->gercel = gercel;
	}
	float getGercel()const
	{
		return gercel;
	}
	void setSanal(float sanal)
	{
		this->sanal = sanal;
	}
	float getSanal()const
	{
		return sanal;
	}

	void bilgiGir()
	{
		float _gercel, _sanal;
		cout << "Sayinin gercel kismini giriniz : ";
		cin >> _gercel;
		setGercel(_gercel);

		cout << "Sayinin sanal kismini giriniz : ";
		cin >> _sanal;
		setSanal(_sanal);
	}

	void bilgiCýkart()
	{
		if (sanal < 0)//Karmaþýk sayýnýn sanal kýsmýna pozitif deðer girildiðinde + operatörü gelicek.
			cout << "Sayinin degeri : " << getGercel() << getSanal() << "i" << endl;
		else
			cout << "Sayinin degeri : " << getGercel() << "+" << getSanal() << "i" << endl;
	}

	void kutupsalGosterim()
	{
		cout << "\nSayinin kutupsal gosterimi : ";//Bu fonksiyonla sayýnýn açýsý ve kutupsal deðeri çýkacak.
		cout << sqrt(pow(getGercel(), 2) + pow(getSanal(), 2)) << " ";
		cout << radyantDerece(atan(getSanal() / getGercel())) << endl;
	}

	KarmasikSayi operator + (const KarmasikSayi& karmasikSayi2)//Ýþaretçi yardýmýyla ilk sayi ve ikinci sayiyi toplanarak sonuca eþitlenir ve sonuc döndürülür.
	{
		KarmasikSayi sonuc;
		sonuc.gercel = this->gercel + karmasikSayi2.gercel;
		sonuc.sanal = this->sanal + karmasikSayi2.sanal;
		return sonuc;
	}
	KarmasikSayi operator - (const KarmasikSayi& karmasikSayi2)
	{
		KarmasikSayi sonuc;
		sonuc.gercel = this->gercel - karmasikSayi2.gercel;
		sonuc.sanal = this->sanal - karmasikSayi2.sanal;
		return sonuc;
	}
	KarmasikSayi operator * (const KarmasikSayi& karmasikSayi2)
	{
		KarmasikSayi sonuc;//Carpma isleminin dagilma ozelligini kullandim.
		sonuc.gercel = (this->gercel * karmasikSayi2.gercel) - (this->sanal * karmasikSayi2.sanal);//Karmaþýk sayinin sanal kisimlari çarpýldýðýnda -1 vereceði için çarpýlan sanal kýsma - deðer verdim.
		sonuc.sanal = (this->gercel * karmasikSayi2.sanal) + (this->sanal * karmasikSayi2.gercel);
		return sonuc;
	}
	KarmasikSayi operator / (const KarmasikSayi& karmasikSayi2)
	{
		KarmasikSayi sonuc;//Paydanýn eslenik carpimi sonucunda cikan gercel sayiyi hesaplayýp payin sanal ve reel kismina boldum.
		float payda = (karmasikSayi2.gercel * karmasikSayi2.gercel) + (karmasikSayi2.sanal * karmasikSayi2.sanal);
		sonuc.gercel = (this->gercel * karmasikSayi2.gercel + this->sanal * karmasikSayi2.sanal) / payda;//Sayinin eþleniði ters iþaret olacaðý için çarpmada kullandýðým - burda da ters iþarete dönüþüyor.
		sonuc.sanal = (-this->gercel * karmasikSayi2.sanal + this->sanal * karmasikSayi2.gercel) / payda;
		return sonuc;
	}

	KarmasikSayi operator += (KarmasikSayi karmasikSayi2)//Ýlk sayiyi iþaretçi yardýmýyla alýp ilk sayiya ikinci sayiyi ekleyip ilk sayiyi döndürdüren fonksiyon.
	{

		this->gercel += karmasikSayi2.gercel;
		this->sanal += karmasikSayi2.sanal;

		return *this;
	}

	KarmasikSayi operator -= (KarmasikSayi karmasikSayi2)
	{

		this->gercel -= karmasikSayi2.gercel;
		this->sanal -= karmasikSayi2.sanal;

		return *this;
	}

	KarmasikSayi operator *= (KarmasikSayi karmasikSayi2)//Ýki sayi belirleyip sayilarýn deðerlerini hesaplayip iþaretçi yardýmýyla sonucu bulup iþaretçiyi döndüren fonksiyon.
	{
		float gercelSayi, sanalSayi;
		gercelSayi = (this->gercel * karmasikSayi2.gercel) - (this->sanal * karmasikSayi2.sanal);
		sanalSayi = (this->gercel * karmasikSayi2.sanal) + (this->sanal * karmasikSayi2.gercel);
		this->gercel = gercelSayi;
		this->sanal = sanalSayi;
		return *this;
	}

	KarmasikSayi operator /= (KarmasikSayi karmasikSayi2)//Ýlk sayiyi paydadaki karmaþýk sayinin eþleniðiyle çarpýp paydadaki gerçel sayiya bölüp döndüren fonksiyon.
	{
		float payda = (karmasikSayi2.gercel * karmasikSayi2.gercel) + (karmasikSayi2.sanal * karmasikSayi2.sanal);
		float gercelSayi, sanalSayi;
		gercelSayi = (this->gercel * karmasikSayi2.gercel + this->sanal * karmasikSayi2.sanal) / payda;
		sanalSayi = (-this->gercel * karmasikSayi2.sanal + this->sanal * karmasikSayi2.gercel) / payda;
		this->gercel = gercelSayi;
		this->sanal = sanalSayi;
		return *this;
	}


};



int main()
{
	cout << "                                      " << "Karmasik Sayi Ile 5 Islem " << endl;
	KarmasikSayi karmasikSayi1;
	karmasikSayi1.bilgiGir();
	KarmasikSayi karmasikSayi2;
	karmasikSayi2.bilgiGir();
	KarmasikSayi toplam = karmasikSayi1 + karmasikSayi2;
	KarmasikSayi cikarma = karmasikSayi1 - karmasikSayi2;
	KarmasikSayi carpma = karmasikSayi1 * karmasikSayi2;
	KarmasikSayi bolme = karmasikSayi1 / karmasikSayi2;


	do//Kullanýcý e seçeneðini seçtiði halde iþlemleri ayný sayýlarla yapmaya devam edebilecek.
	{
		system("Pause");
		system("CLS");

		cout << "Lutfen hangi islemi yapmak istediginizi seciniz (1,2,3,4,5)" << endl;
		cout << "Menu1 => Toplama islemi " << endl;
		cout << "Menu2 => Cikarma islemi " << endl;
		cout << "Menu3 => Carpma islemi " << endl;
		cout << "Menu4 => Bolme islemi " << endl;
		cout << "Menu5 => Kutupsal gosterim " << endl;
		cin >> menuSecenek;

		system("CLS");


		if (menuSecenek == 1) //Her secenek icin kullanýcý deger girdiðinde o menünün iþlemleri gerçekleþicek.
		{
			karmasikSayi1 += karmasikSayi2;
			karmasikSayi1.bilgiCýkart();
		}

		else if (menuSecenek == 2)
		{
			cikarma.bilgiCýkart();
		}

		else if (menuSecenek == 3)
		{
			carpma.bilgiCýkart();
		}

		else if (menuSecenek == 4)
		{
			karmasikSayi1 /= karmasikSayi2;
			karmasikSayi1.bilgiCýkart();
		}
		else if (menuSecenek == 5)
		{
			cout << "Sayilarin sirasiyla kutupsal gosterimi  " << endl;
			karmasikSayi1.kutupsalGosterim();
			karmasikSayi2.kutupsalGosterim();
		}
		else if (menuSecenek > 5 || menuSecenek < 1)//Kullanýcý 1,2,3,4,5 deðerleri girmediði sürece iþleme devam etmek istediði sürece geçerli bir sayi girene kadar bu yazilar cýkar.
		{
			cout << "Gecerli bir sayi giriniz " << endl;
		}


		cout << "Isleme devam etmek istiyor musunuz (E/H) " << endl;
		cin >> menuDevam;
	} while (toupper(menuDevam) == 'E');//Kucuk ve buyuk harf karýþýklýðýný ortadan kaldýrmak için kullandým.
}