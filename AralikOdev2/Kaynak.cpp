/***********************************************************************************************************************************************************
																	SAKARYA �N�VERS�TES�
														   B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
															   B�LG�SAYAR M�HEND�SL��� B�L�M�
																 PROGRAMLAMAYA G�R�� DERS�
															 �DEV NUMARASI.....:2.�DEV
															 ��RENC� ADI.......:H�SEY�N AKBAL
															 ��RENC� NUMARASI..:G211210069
															 DERS GRUBU........:2.��RET�M C GRUBU
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

	void bilgiC�kart()
	{
		if (sanal < 0)//Karma��k say�n�n sanal k�sm�na pozitif de�er girildi�inde + operat�r� gelicek.
			cout << "Sayinin degeri : " << getGercel() << getSanal() << "i" << endl;
		else
			cout << "Sayinin degeri : " << getGercel() << "+" << getSanal() << "i" << endl;
	}

	void kutupsalGosterim()
	{
		cout << "\nSayinin kutupsal gosterimi : ";//Bu fonksiyonla say�n�n a��s� ve kutupsal de�eri ��kacak.
		cout << sqrt(pow(getGercel(), 2) + pow(getSanal(), 2)) << " ";
		cout << radyantDerece(atan(getSanal() / getGercel())) << endl;
	}

	KarmasikSayi operator + (const KarmasikSayi& karmasikSayi2)//��aret�i yard�m�yla ilk sayi ve ikinci sayiyi toplanarak sonuca e�itlenir ve sonuc d�nd�r�l�r.
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
		sonuc.gercel = (this->gercel * karmasikSayi2.gercel) - (this->sanal * karmasikSayi2.sanal);//Karma��k sayinin sanal kisimlari �arp�ld���nda -1 verece�i i�in �arp�lan sanal k�sma - de�er verdim.
		sonuc.sanal = (this->gercel * karmasikSayi2.sanal) + (this->sanal * karmasikSayi2.gercel);
		return sonuc;
	}
	KarmasikSayi operator / (const KarmasikSayi& karmasikSayi2)
	{
		KarmasikSayi sonuc;//Paydan�n eslenik carpimi sonucunda cikan gercel sayiyi hesaplay�p payin sanal ve reel kismina boldum.
		float payda = (karmasikSayi2.gercel * karmasikSayi2.gercel) + (karmasikSayi2.sanal * karmasikSayi2.sanal);
		sonuc.gercel = (this->gercel * karmasikSayi2.gercel + this->sanal * karmasikSayi2.sanal) / payda;//Sayinin e�leni�i ters i�aret olaca�� i�in �arpmada kulland���m - burda da ters i�arete d�n���yor.
		sonuc.sanal = (-this->gercel * karmasikSayi2.sanal + this->sanal * karmasikSayi2.gercel) / payda;
		return sonuc;
	}

	KarmasikSayi operator += (KarmasikSayi karmasikSayi2)//�lk sayiyi i�aret�i yard�m�yla al�p ilk sayiya ikinci sayiyi ekleyip ilk sayiyi d�nd�rd�ren fonksiyon.
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

	KarmasikSayi operator *= (KarmasikSayi karmasikSayi2)//�ki sayi belirleyip sayilar�n de�erlerini hesaplayip i�aret�i yard�m�yla sonucu bulup i�aret�iyi d�nd�ren fonksiyon.
	{
		float gercelSayi, sanalSayi;
		gercelSayi = (this->gercel * karmasikSayi2.gercel) - (this->sanal * karmasikSayi2.sanal);
		sanalSayi = (this->gercel * karmasikSayi2.sanal) + (this->sanal * karmasikSayi2.gercel);
		this->gercel = gercelSayi;
		this->sanal = sanalSayi;
		return *this;
	}

	KarmasikSayi operator /= (KarmasikSayi karmasikSayi2)//�lk sayiyi paydadaki karma��k sayinin e�leni�iyle �arp�p paydadaki ger�el sayiya b�l�p d�nd�ren fonksiyon.
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


	do//Kullan�c� e se�ene�ini se�ti�i halde i�lemleri ayn� say�larla yapmaya devam edebilecek.
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


		if (menuSecenek == 1) //Her secenek icin kullan�c� deger girdi�inde o men�n�n i�lemleri ger�ekle�icek.
		{
			karmasikSayi1 += karmasikSayi2;
			karmasikSayi1.bilgiC�kart();
		}

		else if (menuSecenek == 2)
		{
			cikarma.bilgiC�kart();
		}

		else if (menuSecenek == 3)
		{
			carpma.bilgiC�kart();
		}

		else if (menuSecenek == 4)
		{
			karmasikSayi1 /= karmasikSayi2;
			karmasikSayi1.bilgiC�kart();
		}
		else if (menuSecenek == 5)
		{
			cout << "Sayilarin sirasiyla kutupsal gosterimi  " << endl;
			karmasikSayi1.kutupsalGosterim();
			karmasikSayi2.kutupsalGosterim();
		}
		else if (menuSecenek > 5 || menuSecenek < 1)//Kullan�c� 1,2,3,4,5 de�erleri girmedi�i s�rece i�leme devam etmek istedi�i s�rece ge�erli bir sayi girene kadar bu yazilar c�kar.
		{
			cout << "Gecerli bir sayi giriniz " << endl;
		}


		cout << "Isleme devam etmek istiyor musunuz (E/H) " << endl;
		cin >> menuDevam;
	} while (toupper(menuDevam) == 'E');//Kucuk ve buyuk harf kar���kl���n� ortadan kald�rmak i�in kulland�m.
}