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

bool areEqual(const triTree& tr1,const triTree& tr2){
  if(tr1==nullptr && tr2==nullptr){
    return true;
  }else if(tr1==nullptr || tr2==nullptr ){
    return false;
  }else if(tr1->el!=tr2->el){
    return false;
  }else{
    return (areEqual(tr1->child1,tr2->child1) &&
            areEqual(tr1->child2,tr2->child2) &&
            areEqual(tr1->child3,tr2->child3));
  }
}
////////////////////////////////////////////////////////////////////////////
int main(){
  int ret=0;
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
  triTree btr=nullptr;
  triTree btr1=nullptr;
  triTree btr2=nullptr;
  triTree btr3=nullptr;
  triTree btr4=nullptr;
  triTree btr5=nullptr;
  triTree btr6=nullptr;
  triTree btr7=nullptr;
  triTree btr8=nullptr;
  triTree btr9=nullptr;
  triTree btr10=nullptr;
  triTree btr11=nullptr;
  triTree btr12=nullptr;
  triTree btr13=nullptr;
  triTree btr14=nullptr;
  triTree btr15=nullptr;
  triTree btr16=nullptr;
  triTree btr17=nullptr;
  triTree btr18=nullptr;
  triTree btr19=nullptr;
  triTree btr20=nullptr;
  triTree btr21=nullptr;
  triTree btr22=nullptr;
  triTree btr23=nullptr;
  triTree btr24=nullptr;
  triTree btr25=nullptr;

  cout << std::boolalpha;
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
  cout << "\n****   TEST  deleteAll(...)          *****";
  cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

  cout << "\n";
  cout << "\n!!!! ATTENZIONE: 33 TEST DA SUPERARE !!!!";
  int nTest = 1;

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": deleteAll(1,tr) ";
    cout << "\n-----------------------------------------";

    btr=nullptr;
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(1,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  tr=new triNode{1,nullptr,nullptr,nullptr};

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": deleteAll(1,tr) ";
    cout << "\n-----------------------------------------";

    btr=nullptr;
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(1,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  tr=new triNode{1,nullptr,nullptr,nullptr};

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": deleteAll(2,tr) ";
    cout << "\n-----------------------------------------";

    btr=new triNode{1,nullptr,nullptr,nullptr};
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(2,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  tr1=new triNode{1,nullptr,nullptr,nullptr};
  tr2=new triNode{3,nullptr,nullptr,nullptr};
  tr3=new triNode{2,nullptr,nullptr,nullptr};
  tr=new triNode{0,tr1,tr2,tr3};

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": deleteAll(0,tr) ";
    cout << "\n-----------------------------------------";

    
    btr=new triNode{3,nullptr,nullptr,nullptr};
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(0,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  tr1=new triNode{1,nullptr,nullptr,nullptr};
  tr2=new triNode{2,nullptr,nullptr,nullptr};
  tr3=new triNode{2,nullptr,nullptr,nullptr};
  tr=new triNode{0,tr1,tr2,tr3};

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": deleteAll(1,tr) ";
    cout << "\n-----------------------------------------";

    btr2=new triNode{2,nullptr,nullptr,nullptr};
    btr3=new triNode{2,nullptr,nullptr,nullptr};
    btr=new triNode{0,nullptr,btr2,btr3};
    
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(1,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  tr1=new triNode{1,nullptr,nullptr,nullptr};
  tr2=new triNode{2,nullptr,nullptr,nullptr};
  tr3=new triNode{2,nullptr,nullptr,nullptr};
  tr=new triNode{0,tr1,tr2,tr3};

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": deleteAll(2,tr) ";
    cout << "\n-----------------------------------------";

    btr1=new triNode{1,nullptr,nullptr,nullptr};
    btr=new triNode{0,btr1,nullptr,nullptr};
    
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(2,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  tr1=new triNode{1,nullptr,nullptr,nullptr};
  tr2=new triNode{2,nullptr,nullptr,nullptr};
  tr3=new triNode{2,nullptr,nullptr,nullptr};
  tr=new triNode{0,tr1,tr2,tr3};

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": deleteAll(3,tr) ";
    cout << "\n-----------------------------------------";

    btr1=new triNode{1,nullptr,nullptr,nullptr};
    btr2=new triNode{2,nullptr,nullptr,nullptr};
    btr3=new triNode{2,nullptr,nullptr,nullptr};
    btr=new triNode{0,btr1,btr2,btr3};
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(3,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(3,tr) ";
    cout << "\n-----------------------------------------";

   
    btr4=new triNode{5,nullptr,nullptr,nullptr};
    btr1=new triNode{5,nullptr,btr4,nullptr};
    btr=new triNode{5,nullptr,btr1,nullptr};
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(3,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(5,tr) ";
    cout << "\n-----------------------------------------";

    btr6=new triNode{3,nullptr,nullptr,nullptr};
    btr5=new triNode{3,nullptr,btr6,nullptr};
    btr3=new triNode{3,nullptr,btr5,nullptr};
    btr=new triNode{3,nullptr,tr3,nullptr};
        
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(5,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

  tr6=new triNode{3,nullptr,nullptr,nullptr};
  tr5=new triNode{3,nullptr,tr6,nullptr};
  tr4=new triNode{3,nullptr,tr5,nullptr};
  tr3=new triNode{3,nullptr,tr4,nullptr};
  tr2=new triNode{3,nullptr,tr3,nullptr};
  tr1=new triNode{3,nullptr,tr2,nullptr};
  tr=new triNode{3,nullptr,tr1,nullptr};

  {
    cout << "\n";
    cout << "\n-----------------------------------------";
    cout << "\n    TEST " << nTest << ": deleteAll(3,tr) ";
    cout << "\n-----------------------------------------";

    btr=nullptr;
        
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(3,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(0,tr) ";
    cout << "\n-----------------------------------------";

    btr6=new triNode{3,nullptr,nullptr,nullptr};
    btr5=new triNode{3,nullptr,btr6,nullptr};
    btr4=new triNode{5,nullptr,btr5,nullptr};
    btr3=new triNode{3,nullptr,btr4,nullptr};
    btr2=new triNode{3,nullptr,btr3,nullptr};
    btr1=new triNode{5,nullptr,btr2,nullptr};
    btr=new triNode{5,nullptr,btr1,nullptr};
        
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(0,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(3,tr) ";
    cout << "\n-----------------------------------------";

  
    btr4=new triNode{5,nullptr,nullptr,nullptr};
    btr1=new triNode{5,btr4,nullptr,nullptr};
    btr=new triNode{5,btr1,nullptr,nullptr};
        
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(3,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(5,tr) ";
    cout << "\n-----------------------------------------";

    btr=nullptr;
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(5,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(3,tr) ";
    cout << "\n-----------------------------------------";

    btr=new triNode{4,nullptr,nullptr,nullptr};;
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(3,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(1,tr) ";
    cout << "\n-----------------------------------------";

    btr6=new triNode{5,nullptr,nullptr,nullptr};
    btr5=new triNode{4,nullptr,nullptr,nullptr};
    btr3=new triNode{7,nullptr,nullptr,nullptr};
    btr2=new triNode{3,nullptr,btr5,btr6};
    btr=new triNode{3,nullptr,btr2,btr3};
     
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(1,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(2,tr) ";
    cout << "\n-----------------------------------------";

    btr6=new triNode{5,nullptr,nullptr,nullptr};
    btr5=new triNode{4,nullptr,nullptr,nullptr};
    btr3=new triNode{7,nullptr,nullptr,nullptr};
    btr2=new triNode{3,nullptr,btr5,btr6};
    btr1=new triNode{1,nullptr,nullptr,nullptr};
    btr=new triNode{3,btr1,btr2,btr3};
     
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(2,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(4,tr) ";
    cout << "\n-----------------------------------------";

    btr6=new triNode{5,nullptr,nullptr,nullptr};
    btr4=new triNode{2,nullptr,nullptr,nullptr};
    btr3=new triNode{7,nullptr,nullptr,nullptr};
    btr2=new triNode{3,nullptr,nullptr,btr6};
    btr1=new triNode{1,nullptr,nullptr,btr4};
    btr=new triNode{3,btr1,btr2,btr3};
     
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(4,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(5,tr) ";
    cout << "\n-----------------------------------------";

    btr5=new triNode{4,nullptr,nullptr,nullptr};
    btr4=new triNode{2,nullptr,nullptr,nullptr};
    btr3=new triNode{7,nullptr,nullptr,nullptr};
    btr2=new triNode{3,nullptr,btr5,nullptr};
    btr1=new triNode{1,nullptr,nullptr,btr4};
    btr=new triNode{3,btr1,btr2,btr3};
     
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(5,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(7,tr) ";
    cout << "\n-----------------------------------------";

    btr6=new triNode{5,nullptr,nullptr,nullptr};
    btr5=new triNode{4,nullptr,nullptr,nullptr};
    btr4=new triNode{2,nullptr,nullptr,nullptr};
    btr2=new triNode{3,nullptr,btr5,btr6};
    btr1=new triNode{1,nullptr,nullptr,btr4};
    btr=new triNode{3,btr1,btr2,nullptr};
     
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(7,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(6,tr) ";
    cout << "\n-----------------------------------------";

    btr6=new triNode{5,nullptr,nullptr,nullptr};
    btr5=new triNode{4,nullptr,nullptr,nullptr};
    btr4=new triNode{2,nullptr,nullptr,nullptr};
    btr3=new triNode{7,nullptr,nullptr,nullptr};
    btr2=new triNode{3,nullptr,btr5,btr6};
    btr1=new triNode{1,nullptr,nullptr,btr4};
    btr=new triNode{3,btr1,btr2,btr3};
     
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(6,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(1,tr) ";
    cout << "\n-----------------------------------------";

    btr9=new triNode{7,nullptr,nullptr,nullptr};
    btr8=new triNode{8,nullptr,nullptr,nullptr};
    btr7=new triNode{2,nullptr,btr9,nullptr};
    btr6=new triNode{6,nullptr,nullptr,nullptr};
    btr=new triNode{3,btr6,btr7,btr8};

    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(1,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(2,tr) ";
    cout << "\n-----------------------------------------";

    btr9=new triNode{7,nullptr,nullptr,nullptr};
    btr8=new triNode{8,nullptr,nullptr,nullptr};
    btr6=new triNode{6,nullptr,nullptr,nullptr};
    btr4=new triNode{5,nullptr,nullptr,nullptr};
    btr3=new triNode{4,nullptr,nullptr,nullptr};
    btr2=new triNode{3,btr6,btr9,btr8};
    btr=new triNode{1,btr4,btr2,btr3};

    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(2,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(3,tr) ";
    cout << "\n-----------------------------------------";

    btr9=new triNode{7,nullptr,nullptr,nullptr};
    btr7=new triNode{2,nullptr,btr9,nullptr};
    btr5=new triNode{6,nullptr,nullptr,nullptr};
    btr4=new triNode{5,nullptr,nullptr,nullptr};
    btr3=new triNode{4,nullptr,nullptr,nullptr};
    btr1=new triNode{2,btr4,nullptr,btr5};
    btr=new triNode{1,btr1,btr7,btr3};
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(3,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(4,tr) ";
    cout << "\n-----------------------------------------";

    btr9=new triNode{7,nullptr,nullptr,nullptr};
    btr8=new triNode{8,nullptr,nullptr,nullptr};
    btr7=new triNode{2,nullptr,btr9,nullptr};
    btr6=new triNode{6,nullptr,nullptr,nullptr};
    btr5=new triNode{6,nullptr,nullptr,nullptr};
    btr4=new triNode{5,nullptr,nullptr,nullptr};
    btr2=new triNode{3,btr6,btr7,btr8};
    btr1=new triNode{2,btr4,nullptr,btr5};
    btr=new triNode{1,btr1,btr2,nullptr};
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(4,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(5,tr) ";
    cout << "\n-----------------------------------------";

    btr9=new triNode{7,nullptr,nullptr,nullptr};
    btr8=new triNode{8,nullptr,nullptr,nullptr};
    btr7=new triNode{2,nullptr,btr9,nullptr};
    btr6=new triNode{6,nullptr,nullptr,nullptr};
    btr5=new triNode{6,nullptr,nullptr,nullptr};
    btr3=new triNode{4,nullptr,nullptr,nullptr};
    btr2=new triNode{3,btr6,btr7,btr8};
    btr1=new triNode{2,nullptr,nullptr,btr5};
    btr=new triNode{1,btr1,btr2,btr3};
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(5,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

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
    cout << "\n    TEST " << nTest << ": deleteAll(6,tr) ";
    cout << "\n-----------------------------------------";

    btr9=new triNode{7,nullptr,nullptr,nullptr};
    btr8=new triNode{8,nullptr,nullptr,nullptr};
    btr7=new triNode{2,nullptr,btr9,nullptr};
    btr4=new triNode{5,nullptr,nullptr,nullptr};
    btr3=new triNode{4,nullptr,nullptr,nullptr};
    btr2=new triNode{3,nullptr,btr7,btr8};
    btr1=new triNode{2,btr4,nullptr,nullptr};
    btr=new triNode{1,btr1,btr2,btr3};
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(6,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

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
    cout << "\n    TEST " << nTest << ": deleteAll(7,tr) ";
    cout << "\n-----------------------------------------";

    btr8=new triNode{8,nullptr,nullptr,nullptr};
    btr7=new triNode{2,nullptr,nullptr,nullptr};
    btr6=new triNode{6,nullptr,nullptr,nullptr};
    btr5=new triNode{6,nullptr,nullptr,nullptr};
    btr4=new triNode{5,nullptr,nullptr,nullptr};
    btr3=new triNode{4,nullptr,nullptr,nullptr};
    btr2=new triNode{3,btr6,btr7,btr8};
    btr1=new triNode{2,btr4,nullptr,btr5};
    btr=new triNode{1,btr1,btr2,btr3};
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(7,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  nTest++;

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
    cout << "\n    TEST " << nTest << ": deleteAll(8,tr) ";
    cout << "\n-----------------------------------------";

    btr9=new triNode{7,nullptr,nullptr,nullptr};
    btr7=new triNode{2,nullptr,btr9,nullptr};
    btr6=new triNode{6,nullptr,nullptr,nullptr};
    btr5=new triNode{6,nullptr,nullptr,nullptr};
    btr4=new triNode{5,nullptr,nullptr,nullptr};
    btr3=new triNode{4,nullptr,nullptr,nullptr};
    btr2=new triNode{3,btr6,btr7,nullptr};
    btr1=new triNode{2,btr4,nullptr,btr5};
    btr=new triNode{1,btr1,btr2,btr3};
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(8,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(1,tr) ";
    cout << "\n-----------------------------------------";

    btr25=new triNode{2,nullptr,nullptr,nullptr};
    btr24=new triNode{5,nullptr,nullptr,nullptr};
    btr23=new triNode{3,nullptr,nullptr,nullptr};
    btr22=new triNode{5,nullptr,nullptr,nullptr};
    btr21=new triNode{4,nullptr,nullptr,nullptr};
    btr20=new triNode{2,nullptr,nullptr,nullptr};
    btr19=new triNode{4,nullptr,nullptr,nullptr};
    btr18=new triNode{4,btr23,btr24,btr25};
    btr17=new triNode{2,nullptr,nullptr,nullptr};
    btr15=new triNode{5,nullptr,nullptr,nullptr};
    btr14=new triNode{4,nullptr,nullptr,nullptr};
    btr12=new triNode{3,nullptr,btr22,nullptr};
    btr11=new triNode{3,nullptr,btr21,nullptr};
    btr10=new triNode{3,nullptr,btr20,nullptr};
    btr9=new triNode{2,nullptr,nullptr,btr19};
    btr8=new triNode{5,nullptr,nullptr,nullptr};
    btr7=new triNode{3,nullptr,btr17,btr18};
    btr6=new triNode{3,nullptr,nullptr,nullptr};
    btr4=new triNode{4,nullptr,btr14,btr15};
    btr3=new triNode{3,btr10,btr11,btr12};
    btr2=new triNode{2,btr7,btr8,btr9};
    btr1=new triNode{2,btr4,nullptr,btr6};
    btr=new triNode{2,btr1,btr2,btr3};
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(1,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(2,tr) ";
    cout << "\n-----------------------------------------";

    btr=new triNode{5,nullptr,nullptr,nullptr};
  
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(2,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(3,tr) ";
    cout << "\n-----------------------------------------";

    btr19=new triNode{4,nullptr,nullptr,nullptr};
    btr16=new triNode{1,nullptr,nullptr,nullptr};
    btr15=new triNode{5,nullptr,nullptr,nullptr};
    btr14=new triNode{4,nullptr,nullptr,nullptr};
    btr13=new triNode{1,nullptr,nullptr,nullptr};
    btr9=new triNode{2,nullptr,nullptr,btr19};
    btr8=new triNode{5,nullptr,nullptr,nullptr};
    btr5=new triNode{1,nullptr,nullptr,nullptr};
    btr4=new triNode{4,btr13,btr14,btr15};
    btr2=new triNode{2,btr16,btr8,btr9};
    btr1=new triNode{2,btr4,btr5,nullptr};
    btr=new triNode{2,btr1,btr2,nullptr};
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(3,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(4,tr) ";
    cout << "\n-----------------------------------------";

    btr25=new triNode{2,nullptr,nullptr,nullptr};
    btr22=new triNode{5,nullptr,nullptr,nullptr};
    btr20=new triNode{2,nullptr,nullptr,nullptr};
    btr17=new triNode{2,nullptr,nullptr,nullptr};
    btr16=new triNode{1,nullptr,nullptr,nullptr};
    btr13=new triNode{1,nullptr,nullptr,nullptr};
    btr12=new triNode{3,nullptr,btr22,nullptr};
    btr11=new triNode{3,nullptr,nullptr,nullptr};
    btr10=new triNode{3,nullptr,btr20,nullptr};
    btr9=new triNode{2,nullptr,nullptr,nullptr};
    btr8=new triNode{5,nullptr,nullptr,nullptr};
    btr7=new triNode{3,btr16,btr17,btr25};
    btr6=new triNode{3,nullptr,nullptr,nullptr};
    btr5=new triNode{1,nullptr,nullptr,nullptr};
    btr4=new triNode{4,btr13,btr14,btr15};
    btr3=new triNode{3,btr10,btr11,btr12};
    btr2=new triNode{2,btr7,btr8,btr9};
    btr1=new triNode{2,btr13,btr5,btr6};
    btr=new triNode{2,btr1,btr2,btr3};
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(4,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
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
    cout << "\n    TEST " << nTest << ": deleteAll(5,tr) ";
    cout << "\n-----------------------------------------";

    btr25=new triNode{2,nullptr,nullptr,nullptr};
    btr23=new triNode{3,nullptr,nullptr,nullptr};
    btr21=new triNode{4,nullptr,nullptr,nullptr};
    btr20=new triNode{2,nullptr,nullptr,nullptr};
    btr19=new triNode{4,nullptr,nullptr,nullptr};
    btr18=new triNode{4,btr23,nullptr,btr25};
    btr17=new triNode{2,nullptr,nullptr,nullptr};
    btr16=new triNode{1,nullptr,nullptr,nullptr};
    btr14=new triNode{4,nullptr,nullptr,nullptr};
    btr13=new triNode{1,nullptr,nullptr,nullptr};
    btr12=new triNode{3,nullptr,nullptr,nullptr};
    btr11=new triNode{3,nullptr,btr21,nullptr};
    btr10=new triNode{3,nullptr,btr20,nullptr};
    btr9=new triNode{2,nullptr,nullptr,btr19};
    btr7=new triNode{3,btr16,btr17,btr18};
    btr6=new triNode{3,nullptr,nullptr,nullptr};
    btr5=new triNode{1,nullptr,nullptr,nullptr};
    btr4=new triNode{4,btr13,btr14,nullptr};
    btr3=new triNode{3,btr10,btr11,btr12};
    btr2=new triNode{2,btr7,nullptr,btr9};
    btr1=new triNode{2,btr4,btr5,btr6};
    btr=new triNode{2,btr1,btr2,btr3};
    
    cout << "\ncon tr uguale a:"<<endl;
    print(tr,"");
    deleteAll(5,tr);
    cout << "\nLa funzione cambia tr in "<<endl;
    print(tr,"");
    bool ans=areEqual(tr,btr);
    cout << "\nIl test e' superato? "
      "================================> "
         << siOrNo(ans)<<endl;
    if(ans) ++ret;
  }
  
  cout<<"\n";
  cout<<"=======> NUMERO DI TEST SUPERATI: "<<ret<<"/"<<nTest<<endl;
  return ret;
}
