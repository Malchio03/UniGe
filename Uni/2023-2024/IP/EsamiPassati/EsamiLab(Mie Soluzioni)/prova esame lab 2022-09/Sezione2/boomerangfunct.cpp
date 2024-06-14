#include <cmath>
#include "boomerang.h"

// funzione ausiliare
float distanza(const punto& p1, const punto& p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}


int contaBoomerang(const std::vector<punto>& punti) {
    int count = 0;
    
    for (size_t i = 0; i < punti.size() - 2; ++i) {
        const punto& p1 = punti[i];
        const punto& p2 = punti[i+1];
        const punto& p3 = punti[i+2];
        
        float d1 = distanza(p1, p2);
        float d2 = distanza(p3, p2);
        
        if (equals(d1, d2)) {
            ++count;
        }
    }
    
    return count;
}


bool equals(float a, float b) {
    const float eps = 1e-5;
    return std::fabs(a - b) < eps;
}

