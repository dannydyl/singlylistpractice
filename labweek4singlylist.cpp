#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

class Infos{
	public:
		Infos(const string &townN, const string &countryN, int populationN);
		Infos();
		//constructor and default
		string getTown() const;
		string getCountry() const;
		int getPopulation() const;
		
	private:
		string townname, countryname;
		int population;
		

		
};

class Operator{
	public:
		Operator(int Maxinformation = 10);
		~Operator();
		void addInfos(const Infos& n);
		void remove (int i);
		void displayoddandeven(const Infos n);
		
	private:
		int MaxInfo;
		int NumInfo;
		Infos* informations;
};

void Operator::displayoddandeven(Infos n){
	for(int i=0;i<MaxInfo;i++){
		if(i % 2 == 0){
			cout << informations[i].getTown() << endl;
			cout << informations[i].getCountry() << endl;
			cout << informations[i].getPopulation() << endl;
		}
	}
	
	cout << endl << endl;
	
	for(int i=0;i<MaxInfo;i++){
		if(i % 2 == 1){
			cout << informations[i].getTown() << endl;
			cout << informations[i].getCountry() << endl;
			cout << informations[i].getPopulation() << endl;
		}
	}
}

string Infos::getTown() const{
	return townname;
}

string Infos::getCountry() const{
	return countryname;
}

int Infos::getPopulation() const{
	return population;
}

Infos::Infos(const string &townN, const string &countryN, int populationN){
	townname = townN;
	countryname = countryN;
	population = populationN;
}

Infos::Infos(){
	
}

Operator::Operator(int Maxinformation){
	MaxInfo = Maxinformation;
	NumInfo = 0;
	informations = new Infos[Maxinformation];
}

Operator::~Operator(){
	delete[] informations;
}

void Operator::addInfos(const Infos &n){
	
	if(NumInfo == MaxInfo){
		return;
	}
	informations[NumInfo] = n;
	

	
}

void Operator::remove(int i){
	if(i<0 || i >= MaxInfo){
		cout << "Index is out of bounds" << endl;
		return;
	}
	
	Infos e = informations[i];
	
	for(int j=i+1;j<NumInfo;j++){
		informations[j-1] = informations[j];
	}
	
	NumInfo--;
	
}

int main() {
	string tname, cname;
	int pnum;
	Infos n(tname, cname, pnum); // declare variable
	Operator myinfo(5);
	int i=0;
	while(i!=5){
		cout << "Town name: ";
		cin >> tname;
		cout << "Country name: ";
		cin >> cname;
		cout << "Population: ";
		cin >> pnum;
		
		
		myinfo.addInfos(n);
		
		
		i++;
	}
	
	myinfo.displayoddandeven(n);
	
	
}



