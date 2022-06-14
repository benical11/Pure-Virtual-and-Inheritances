#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;
int localToplam2D = 0;
int localToplam3D = 0;
double pi = 3.14;

class Sekil
{
	protected:
		string isim;
		int r1,l1,b1;
		
    public:
    
	//Pure Virtual Func
    virtual int getAlan() = 0;
    
    virtual string getIsim() = 0;    
    
    
};

//////////////////////////////// ------Sekil2D------- //////////////////////////////

class Sekil2D : public Sekil
{
    public: 
    
    //Pure Virtual Func
    virtual int getCevre() = 0;
    virtual int getKoseSayisi() = 0;
    
};

////////////////////////////// Sekil2D Alt Sýnýflarý ///////////////////////////////////////

		//Daire//
class Daire : public Sekil2D
{
    public:
    
    
    Daire(string isim1, int r){
    	isim = isim1;
    	r1 = r;
	}
    
    
    string getIsim(){
    	return isim;
	}
	
    int getAlan(){
    
       return (pi * pow(r1,2));
    }
    
    int getCevre(){
    	
    		return pi * r1;
    		
    }
    
    int getKoseSayisi(){
    	
    	return 0;
    }
};

		//Ucgen//
class Ucgen : public Sekil2D
{
    public:
    	Ucgen(string isim1, int r, int l, int b){
    	isim = isim1;
    	r1 = r;
    	l1 = l;
    	b1 = b;
	}
	
    string getIsim(){
    	
    	return isim;
	}
	
    int getAlan(){
       return (r1*l1)/2;
    }
    
    int getCevre(){
    	
    		return r1+l1+b1;
    		
    }
    
    int getKoseSayisi(){
    	int c = 3;
    	return c;
    }
};

		//Elips//
class Ellipse : public Sekil2D
{
    public:
    	
    	Ellipse(string isim1, int r, int l){
    	isim = isim1;
    	r1 = r;
    	l1 = l;
	}
	
    string getIsim(){
    	 
    	return isim;
	}
	
    int getAlan( ){
       return pi * (r1*l1);
    }
    
    int getCevre( ){
    	
    		return (2*pi) * sqrt(0.5*(pow(r1,2)+pow(l1,2)));
    		
    }
    
    int getKoseSayisi( ){
    	
    	return 0;
    }
};

		//Dikdortgen//
class Dikdortgen : public Sekil2D
{
    public:
    	
    	Dikdortgen(string isim1, int r, int l){
    	isim = isim1;
    	r1 = r;
    	l1 = l;
	}
	
    string getIsim( ){
    	 
    	return isim;
	}
	
    int getAlan( ){
    
       return r1*l1;
    }
    
    int getCevre( ){
    	
    		return 2*(r1+l1);
    		
    }
    
    int getKoseSayisi( ){
    	int c=4;
    	return c;
    }
};

//////////////////////////////// ------Sekil3D------- //////////////////////////////

class Sekil3D : public Sekil
{
    public:
    virtual int getHacim() = 0;
    virtual int getYuzSayisi() = 0;
};


		//Kure//

class Kure : public Sekil3D
{
    public:
    	
    	Kure(string isim1, int r){
    	isim = isim1;
    	r1 = r;
	}
	
    string getIsim( ){
    	 
    	return isim;
	}
	
    int getAlan( ){
    
       return (4*pi)*pow(r1,2);
    }
    
    int getHacim( ){
    	
    		return (4/3)*(pi*pow(r1,3));
    		
    }
    
    int getYuzSayisi( ){
    	int c = 1;
    	return c;
    }
};

		//Silindir//
class Silindir : public Sekil3D
{
    public:
    	
    	Silindir(string isim1, int r, int l){
    	isim = isim1;
    	r1 = r;
    	l1 = l;
	}
	
    string getIsim( ){
    	 
    	return isim;
	}
	
    int getAlan( ){
    
       return 2*pi*r1*(r1+l1);
    }
    
    int getHacim( ){
    	
    		return pi*pow(r1,2)*l1;
    		
    }
    
    int getYuzSayisi( ){
    	int c = 3;
    	return c;
    }
};

		//Kup//
class Kup : public Sekil3D
{
    public:
    	
    	Kup(string isim1, int r){
    	isim = isim1;
    	r1 = r;
	}
	
    string getIsim( ){
    	 
    	return isim;
	}
	
    int getAlan( ){
    
       return 6*pow(r1,2);
    }
    
    int getHacim( ){
    	
    		return pow(r1,3);
    		
    }
    
    int getYuzSayisi( ){
    	int c = 6;
    	return c;
    }
};




int getToplamHacim(Sekil *sekilPtr[], int N){
	
	
		for(int i = 0; i < N ; i++){
			localToplam3D += sekilPtr[i]->getAlan();
		}
		
		
	
	
	
	return localToplam3D;
	
	
}





int getToplamAlan(Sekil *sekilPtr[], int N){
	
	
		for(int i = 0; i < N ; i++){
			localToplam2D += sekilPtr[i]->getAlan();
		}
		
		
	
	
	
	return localToplam2D;
	
	
}


int main(){
	Sekil *sekilPtr[4];
	Sekil2D *sekPtr2;
	Sekil3D *sekPtr3;
	
	Daire der0("daire0",10);
	sekPtr2 = &der0;
		
	cout<<sekPtr2->getIsim()<<" "<<sekPtr2->getAlan()<<" "<<sekPtr2->getCevre()<<" "<<sekPtr2->getKoseSayisi()<<endl;
	
	Dikdortgen der1("dikdortgen0",12,30);
	sekPtr2 = &der1;
	
	cout<<sekPtr2->getIsim()<<" "<<sekPtr2->getAlan()<<" "<<sekPtr2->getCevre()<<" "<<sekPtr2->getKoseSayisi()<<endl;
	
	Ellipse der2("elips0",10,20);
	sekPtr2 = &der2;
	
	cout<<sekPtr2->getIsim()<<" "<<sekPtr2->getAlan()<<" "<<sekPtr2->getCevre()<<" "<<sekPtr2->getKoseSayisi()<<endl;
	
	Ucgen der3("ucgen0",12,30,25);
	sekPtr2 = &der3;
	
	cout<<sekPtr2->getIsim()<<" "<<sekPtr2->getAlan()<<" "<<sekPtr2->getCevre()<<" "<<sekPtr2->getKoseSayisi()<<endl;
	
	sekilPtr[0] = &der0;
	sekilPtr[1] = &der1;
	sekilPtr[2] = &der2;
	sekilPtr[3] = &der3;
	
	
		cout<<"Toplam Alan:"<<getToplamAlan(sekilPtr,4)<<endl<<"/////////////////////////////////////"<<endl;
	
	Kure der4("kure0", 10);
	sekPtr3 = &der4;
		
	cout<<sekPtr3->getIsim()<<" "<<sekPtr3->getAlan()<<" "<<sekPtr3->getHacim()<<" "<<sekPtr3->getYuzSayisi()<<endl;
	
	Kup der5("kup0", 10);
	sekPtr3 = &der5;
	
	cout<<sekPtr3->getIsim()<<" "<<sekPtr3->getAlan()<<" "<<sekPtr3->getHacim()<<" "<<sekPtr3->getYuzSayisi()<<endl;
	
	Silindir der6("silindir0", 10, 20);
	sekPtr3 = &der6;
	
	cout<<sekPtr3->getIsim()<<" "<<sekPtr3->getAlan()<<" "<<sekPtr3->getHacim()<<" "<<sekPtr3->getYuzSayisi()<<endl;
	
	
	sekilPtr[0] = &der4;
	sekilPtr[1] = &der5;
	sekilPtr[2] = &der6;
	
	
	cout<<"Toplam Hacim:"<<getToplamHacim(sekilPtr,3);
	
	
	
		

	
	
	return 0;
}




