// obecny vzorec pro vypocet presnosti: 1/sqrt(n)
// presnost = 1% = 1/100 => n = 10000 pokusu
double MCIntegral() {
    unsigned pocetPokusu = 10000;
    double suma = 0.0;

    for (unsigned i=0; i<pocetPokusu; i++) {
        double x[N];
        // urceni souradnic nahodneho bodu x
        for (unsigned j=0; j<N; j++) {
            x[j] = Range[j].min + Random() * (Range[j].max - Range[j].min);
        }
        // pricteni hodnoty nahodneho bodu do celkove sumy
        suma += f(x, N);
    }

    double refPlocha = 1.0;
    // vypocet rozmeru prostoru ve kterem se generovaly body
    for (unsigned k=0; k<N; k++) {
        refPlocha *= Range[k].max - Range[k].min;
    }

    return refPlocha * (suma / pocetPokusu);
}
