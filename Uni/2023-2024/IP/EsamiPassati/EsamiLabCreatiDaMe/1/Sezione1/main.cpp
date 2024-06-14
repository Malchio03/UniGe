#include <iostream>
#include <vector>
#include "array.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare**
 */
string siOrNo(bool b){
  if(b) return "SI";
  else return "NO";
}
////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare**
 */

std::string printArray(int* arrayInteri, unsigned int size) {
    std::string out = "[";
    for (unsigned int i = 0; i < size; i++) {
        if (i > 0) out = out + ",";
        out = out + std::to_string(arrayInteri[i]);
    }
    out += "]";
    return out;
}
////////////////////////////////////////////////////////////////////////////
int main(){
    int ret=0;
    int nTest=0;
    cout << std::boolalpha;
    cout << "\n";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    cout << "\n***** TEST sommaArray(...) *****";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        int a[]={};
        unsigned int s=0;
        int res =  sommaArray(a,s);
        int corr=0;
        cout << "\nL'array dato e': " << printArray(a, s);
        cout << "\nLa funzione deve ritornare " << corr;
        cout << "\nLa funzione ritorna " << res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        int a[]={1, 2, 3};
        unsigned int s=3;
        int res =  sommaArray(a,s);
        int corr=6;
        cout << "\nL'array dato e': " << printArray(a, s);
        cout << "\nLa funzione deve ritornare " << corr;
        cout << "\nLa funzione ritorna " << res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        int a[]={-1, -2, -3};
        unsigned int s=3;
        int res =  sommaArray(a,s);
        int corr=-6;
        cout << "\nL'array dato e': " << printArray(a, s);
        cout << "\nLa funzione deve ritornare " << corr;
        cout << "\nLa funzione ritorna " << res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        int a[]={0, 0, 0};
        unsigned int s=3;
        int res =  sommaArray(a,s);
        int corr=0;
        cout << "\nL'array dato e': " << printArray(a, s);
        cout << "\nLa funzione deve ritornare " << corr;
        cout << "\nLa funzione ritorna " << res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        int a[]={5, -5, 10, -10};
        unsigned int s=4;
        int res =  sommaArray(a,s);
        int corr=0;
        cout << "\nL'array dato e': " << printArray(a, s);
        cout << "\nLa funzione deve ritornare " << corr;
        cout << "\nLa funzione ritorna " << res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        int a[]={100, 200, 300};
        unsigned int s=3;
        int res =  sommaArray(a,s);
        int corr=600;
        cout << "\nL'array dato e': " << printArray(a, s);
        cout << "\nLa funzione deve ritornare " << corr;
        cout << "\nLa funzione ritorna " << res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }

    cout << "\n";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    cout << "\n***** TEST trovaMax(...) *****";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        int a[]={};
        unsigned int s=0;
        int res =  trovaMax(a,s);
        int corr=INT_MIN;
        cout << "\nL'array dato e': " << printArray(a, s);
        cout << "\nLa funzione deve ritornare " << corr;
        cout << "\nLa funzione ritorna " << res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        int a[]={1, 2, 3};
        unsigned int s=3;
        int res =  trovaMax(a,s);
        int corr=3;
        cout << "\nL'array dato e': " << printArray(a, s);
        cout << "\nLa funzione deve ritornare " << corr;
        cout << "\nLa funzione ritorna " << res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        int a[]={80, 2, 900, 1};
        unsigned int s=4;
        int res =  trovaMax(a,s);
        int corr=900;
        cout << "\nL'array dato e': " << printArray(a, s);
        cout << "\nLa funzione deve ritornare " << corr;
        cout << "\nLa funzione ritorna " << res;
        bool ans=(res==corr);
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }

    cout << "\n";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    cout << "\n***** TEST filtraPari(...) *****";
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        int a[]={1, 2, 3, 4};
        unsigned int s=4;
        std::vector<int> res =  filtraPari(a,s);
        std::vector<int> corr;
        corr.push_back(2);
        corr.push_back(4);
        cout << "\nL'array dato e': " << printArray(a, s);
        cout << "\nLa funzione deve ritornare [" << corr[0] << "," << corr[1] << "]";
        cout << "\nLa funzione ritorna [" << res[0] << "," << res[1] << "]";
        bool ans=(res==corr);
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }
    {
        cout << "\n-----------------------------------------";
        cout << "\n    TEST " << ++nTest;
        cout << "\n-----------------------------------------";

        int a[]={1, 3, 5};
        unsigned int s=3;
        std::vector<int> res =  filtraPari(a,s);
        std::vector<int> corr;
        cout << "\nL'array dato e': " << printArray(a, s);
        cout << "\nLa funzione deve ritornare []";
        cout << "\nLa funzione ritorna [";
        for (size_t i = 0; i < res.size(); ++i) {
            if (i > 0) cout << ",";
            cout << res[i];
        }
        cout << "]";
        bool ans=(res==corr);
        cout << "\nIl test e' superato? =================================> "
             << siOrNo(ans) << endl;
        if(ans) ++ret;
    }
    

    cout << "\n";
    cout << "=======> NUMERO DI TEST SUPERATI: " << ret << "/" << nTest << endl;
    return ret;
}
