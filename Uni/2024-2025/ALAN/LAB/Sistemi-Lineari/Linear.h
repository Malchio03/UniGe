#ifndef LINEAR_H
#define LINEAR_H

#include <vector>

double normaInfinito(const std::vector<std::vector<double>>& matrice);
unsigned long long coeffBinomiale(int n, int k);
std::vector<std::vector<double>> generaMatricePascal(int n);
std::vector<std::vector<double>> generaMatriceTridiagonale(int size);
std::vector<double> risolviSistema(const std::vector<std::vector<double>>& A, const std::vector<double>& b);
std::vector<double> generaTermineNoto(const std::vector<std::vector<double>>& A);
bool eliminazioneGaussiana(std::vector<std::vector<double>>& A, std::vector<double>& b);
double normaInfinitoVettore(const std::vector<double>& b);
std::vector<double> aggiungiPerturbazione(const std::vector<double>& b);

#endif 
