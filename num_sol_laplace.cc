#include <iostream>
#include <vector>

// Rekursionsformel als Funktion definieren
std::vector<double> recursion(std::vector<double> u){
	std::vector<double> v(13);
	for(int i = 1; i <= 11; ++i){
		v[i] = (u[i+1]+u[i-1])/2;
	};
	v[0] = 2; //unteren Randpunkt festhalten
	v[12] = 8; //oberen Randpunkt festhalten
	return v;
}

int main(){
	// einen Vektor für die diskreten x-Koordinaten konstruieren
	std::vector<double> x(13);
	double lower_limit = 0; // untere Intervallgrenze
	double upper_limit = 3;	//obere Intervallgrenze
	double interval_length = upper_limit - lower_limit; //Intervalllänge
	x[0]=lower_limit;
	x[12]=upper_limit;
	double delta_x = interval_length / 12; //x-Diskretisierung
	for(int i = 0; i <= 12; ++i){
		x[i] = i * delta_x;
	}

	//einen Vektor für u(x) konstruieren
	std::vector<double> u(13);
	u[lower_limit] = 2; //Randbedingungen
	u[upper_limit] = 8; //Randbedingungen

	//counter zählt die Rekursionen, initialisieren
	int counter = 0;
	// Rekursionsformel 250-mal anwenden
	while(counter < 250){		
		std::vector<double> v(13); // Hilfsvektor v initialisieren
		v = recursion(u); //Rekursionsformel auf u anwenden
		u = v; // u durch das Ergebnis überschreiben, um von neuem zu starten
		++counter; // Zähler um eins erhöhen
	}	

	//Ergebnis ausgeben als (x,u(x))
	std::cout << "250 Iterationen, (x,u(x))\n";
	for(int i = 0; i <= 12; ++i){
		std::cout << "( " << x[i] << " , " << u[i] <<" )\t";
	}
	std::cout << "\n";
}