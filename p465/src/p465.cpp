#include <iostream>
using namespace std;

class Converter{
protected:
	double ratio;
	virtual double convert(double src)=0;
	virtual string getSourceString()=0;
	virtual string getDestString()=0;

public:
	Converter(double ratio) { this->ratio = ratio; }
	void run(){
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
		cout << getSourceString() << "을 입력하세요>> ";
		cin >> src;
		cout << "변환 결과 : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {

public:
	WonToDollar(double ratio):Converter(ratio){};

	double convert(double src){
		double num;
		num=src/this->ratio;
		return num;
	}
	string getSourceString(){
		string str="원";
		return str;
	}
	string getDestString(){
		string str="달러";
		return str;
	}
};

class KmToMile : public Converter{

public:

	KmToMile(double ratio):Converter(ratio){};

	double convert(double src){
		double num;
		num=src/this->ratio;
		return num;
	}
	string getSourceString(){
		string str="Km";
		return str;
	}
	string getDestString(){
		string str="Mile";
		return str;
	}
};

class LoopAdder{
	string name;
	int x,y,sum;
	void read();
	void write();
protected:
	LoopAdder(string name=""){
		this->name = name;
	}
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run();
};

void LoopAdder::read(){
	cout << name << ":" << endl;
	cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}

void LoopAdder::write(){
	cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl;
}

void LoopAdder::run(){
	read();
	sum = calculate();
	write();
}

class ForLoopAdder : public LoopAdder{
public:
	ForLoopAdder(string name):LoopAdder(name){};
	int calculate(){
		int _sum=0;
		for(int i=this->getX(); i<=this->getY(); i++){
			_sum+=i;
		}
		return _sum;
	}
};

class WhileLoopAdder : public LoopAdder{
public:
	WhileLoopAdder(string name) : LoopAdder(name){};
	int calculate(){
		int _sum=0;
		int i=this->getX();
		while(i<=this->getY()){
			_sum+=i;
			i++;
		}

		return _sum;
	}
};

class DoWhileLoopAdder : public LoopAdder{
public:
	DoWhileLoopAdder(string name) : LoopAdder(name){};
	int calculate(){
		int _sum=0;
		int i=this->getX();
		do{
			_sum+=i;
			i++;
		}while(i<=this->getY());

		return _sum;
	}
};


int main() {
	WonToDollar wd(1010);
	wd.run();

	KmToMile toMile(1.609344);
	toMile.run();

	ForLoopAdder forLoop("For Loop");
	forLoop.run();

	WhileLoopAdder whileLoop("while Loop");
	DoWhileLoopAdder doWhileLoop("Do while Loop");

	whileLoop.run();
	doWhileLoop.run();

	return 0;
}
