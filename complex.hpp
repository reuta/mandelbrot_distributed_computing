#ifndef _complex_hpp_
#define _complex_hpp_
// Struct für eine Komplexe Zahl mit dem Reateil r und imaginärem Teil i
struct Complex {
	long double r, i;
	Complex(long double nr, long double ni);
	Complex();
};
// verschieden  Operatoren für Komplexe Zahlen 
Complex operator + (Complex a, Complex b);
Complex operator * (Complex a, Complex b);
Complex operator * (long double a, Complex b);
long double abs(Complex a);
#endif
