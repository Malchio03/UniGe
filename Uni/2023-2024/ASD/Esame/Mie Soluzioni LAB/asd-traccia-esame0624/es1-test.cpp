#include <iostream>
#include "trinary-tree.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////
/* funzione utilizzata per test **non modificare**
 */
string siOrNo(bool b){
  if(b) return "SI"; 
  else return "NO";
}

void print(const triTree&tr,string prefix){
  if(tr!=nullptr){
    cout<<prefix<<tr->el<<endl;
    if(tr->child1!=nullptr ||tr->child2!=nullptr ||tr->child3!=nullptr){   
      print(tr->child1,prefix+"*");
      print(tr->child2,prefix+"*");
      print(tr->child3,prefix+"*");
    }
  }else{
    cout<<prefix<<"nullptr"<<endl;
  }
  
}
////////////////////////////////////////////////////////////////////////////



int main(){
  int ret=0;
  unsigned int ires=0;
  unsigned int ireq=0;
  triTree tr=nullptr;
  triTree tr1=nullptr;
  triTree tr2=nullptr;
  triTree tr3=nullptr;
  triTree tr4=nullptr;
  triTree tr5=nullptr;
  triTree tr6=nullptr;
  triTree tr7=nullptr;
  triTree tr8=nullptr;
  triTree tr9=nullptr;
  triTree tr10=nullptr;
  triTree tr11=nullptr;
  triTree tr12=nullptr;
  triTree tr13=nullptr;
  triTree tr14=nullptr;
  triTree tr15=nullptr;
  triTree tr16=nullptr;
  triTree tr17=nullptr;
  triTree tr18=nullptr;
  triTree tr19=nullptr;
  triTree tr20=nullptr;
  triTree tr21=nullptr;
  triTree tr22=nullptr;
  triTree tr23=nullptr;
  triTree tr24=nullptr;
  triTree tr25=nullptr;
  
  
  cout << std::boolalpha;
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
  cout << "\n****   TEST  nbOccurrence(...)          *****";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

  cout << "\n";
  cout << "\n!!!! ATTENZIONE: 32 TEST DA SUPERARE !!!!";
  int nTest = 1;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(1,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=0; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(1,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(1,tr) ";
    cout << "\n-----------------------------------------";

    tr=new triNode{1,nullptr,nullptr,nullptr};
    
    ireq=1; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(1,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(2,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=0; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(2,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(1,tr) ";
    cout << "\n-----------------------------------------";

    tr1=new triNode{1,nullptr,nullptr,nullptr};
    tr2=new triNode{2,nullptr,nullptr,nullptr};
    tr3=new triNode{2,nullptr,nullptr,nullptr};
    tr=new triNode{0,tr1,tr2,tr3};
    
    ireq=1; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(1,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(2,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=2; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(2,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(3,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=0; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(3,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  tr6=new triNode{3,nullptr,nullptr,nullptr};
  tr5=new triNode{3,nullptr,tr6,nullptr};
  tr4=new triNode{5,nullptr,tr5,nullptr};
  tr3=new triNode{3,nullptr,tr4,nullptr};
  tr2=new triNode{3,nullptr,tr3,nullptr};
  tr1=new triNode{5,nullptr,tr2,nullptr};
  tr=new triNode{5,nullptr,tr1,nullptr};

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(4,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=0; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(4,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(3,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=4; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(3,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(5,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=3; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(5,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  tr6=new triNode{3,nullptr,nullptr,nullptr};
  tr5=new triNode{3,tr6,nullptr,nullptr};
  tr4=new triNode{5,tr5,nullptr,nullptr};
  tr3=new triNode{3,tr4,nullptr,nullptr};
  tr2=new triNode{3,tr3,nullptr,nullptr};
  tr1=new triNode{5,tr2,nullptr,nullptr};
  tr=new triNode{5,tr1,nullptr,nullptr};

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(4,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=0; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(4,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(3,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=4; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(3,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(5,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=3; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(5,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  //tr3 dal testo
  tr6=new triNode{5,nullptr,nullptr,nullptr};
  tr5=new triNode{4,nullptr,nullptr,nullptr};
  tr4=new triNode{2,nullptr,nullptr,nullptr};
  tr3=new triNode{7,nullptr,nullptr,nullptr};
  tr2=new triNode{3,nullptr,tr5,tr6};
  tr1=new triNode{1,nullptr,nullptr,tr4};
  tr=new triNode{3,tr1,tr2,tr3};

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(1,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=1; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(1,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(2,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=1; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(2,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(3,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=2; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(3,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(4,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=1; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(4,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(5,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=1; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(5,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(7,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=1; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(7,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  //tr4 dal testo
  tr9=new triNode{7,nullptr,nullptr,nullptr};
  tr8=new triNode{8,nullptr,nullptr,nullptr};
  tr7=new triNode{2,nullptr,tr9,nullptr};
  tr6=new triNode{6,nullptr,nullptr,nullptr};
  tr5=new triNode{6,nullptr,nullptr,nullptr};
  tr4=new triNode{5,nullptr,nullptr,nullptr};
  tr3=new triNode{4,nullptr,nullptr,nullptr};
  tr2=new triNode{3,tr6,tr7,tr8};
  tr1=new triNode{2,tr4,nullptr,tr5};
  tr=new triNode{1,tr1,tr2,tr3};

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(1,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=1; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(1,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(2,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=2; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(2,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(3,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=1; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(3,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(4,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=1; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(4,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(5,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=1; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(5,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(6,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=2; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(6,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(7,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=1; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(7,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(8,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=1; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(8,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(9,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=0; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(9,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  tr25=new triNode{2,nullptr,nullptr,nullptr};
  tr24=new triNode{5,nullptr,nullptr,nullptr};
  tr23=new triNode{3,nullptr,nullptr,nullptr};
  tr22=new triNode{5,nullptr,nullptr,nullptr};
  tr21=new triNode{4,nullptr,nullptr,nullptr};
  tr20=new triNode{2,nullptr,nullptr,nullptr};
  tr19=new triNode{4,nullptr,nullptr,nullptr};
  tr18=new triNode{4,tr23,tr24,tr25};
  tr17=new triNode{2,nullptr,nullptr,nullptr};
  tr16=new triNode{1,nullptr,nullptr,nullptr};
  tr15=new triNode{5,nullptr,nullptr,nullptr};
  tr14=new triNode{4,nullptr,nullptr,nullptr};
  tr13=new triNode{1,nullptr,nullptr,nullptr};
  tr12=new triNode{3,nullptr,tr22,nullptr};
  tr11=new triNode{3,nullptr,tr21,nullptr};
  tr10=new triNode{3,nullptr,tr20,nullptr};
  tr9=new triNode{2,nullptr,nullptr,tr19};
  tr8=new triNode{5,nullptr,nullptr,nullptr};
  tr7=new triNode{3,tr16,tr17,tr18};
  tr6=new triNode{3,nullptr,nullptr,nullptr};
  tr5=new triNode{1,nullptr,nullptr,nullptr};
  tr4=new triNode{4,tr13,tr14,tr15};
  tr3=new triNode{3,tr10,tr11,tr12};
  tr2=new triNode{2,tr7,tr8,tr9};
  tr1=new triNode{2,tr4,tr5,tr6};
  tr=new triNode{2,tr1,tr2,tr3};

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(1,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=3; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(1,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(2,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=7; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(2,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

   {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(3,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=7; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(3,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

   {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(4,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=5; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(4,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

   {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": nbOccurrence(5,tr) ";
    cout << "\n-----------------------------------------";
    
    ireq=4; 
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    ires =  nbOccurrence(5,tr);
    cout << "\nLa funzione ritorna "<<ires;
    bool ans=(ires==ireq);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  
  cout<<"\n";
  cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
  return ret;
}
