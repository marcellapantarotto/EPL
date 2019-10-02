#include <bits/stdc++.h>
 
using namespace std;

//Base class
class Exp{
    public:
        // pure virtual function providing interface framework.
        virtual int eval() = 0;
        virtual void print() = 0; 
       
};

// Derived classes
class Lit: virtual public Exp{
    public:
        int value;
        Lit(){}
        Lit(int v){
            this->value = v; 
        }
        void setValue(int v){
            this->value = v;
        }
        void print(){
            cout << value << " ";
        }
        int eval(){
            return value;
        }
};

class Add: virtual public Exp{
    public:
        Exp *left, *right;
        Add(Exp *l, Exp *r){
            left = l;
            right = r;
        }
        void print(){
            // cout << left.eval() << " + " << right.eval() << endl;
            cout << "( ";  left->print();
            cout << "+ ";
            right->print(); cout << ") ";
        }
        int eval(){ 
            // return (this->left.eval() + this->right.eval());
            return (left->eval() + right->eval()); 
        }
};

class Neg: virtual public Exp{
    public:
        Exp *exp;
        Neg(Exp *e){
            exp = e;
        }
        void print(){
            cout << "(-" << exp->eval() << ") ";
        } 
        int eval(){ 
            return (exp->eval() * -1); 
      }
};

int main(void) {
    Lit *ltree = new Lit(3); 
    Add *atree = new Add(ltree, ltree); 
    Neg *ntree = new Neg(ltree);

    Exp *latree = new Add(ltree, atree);
    // Exp *lntree = new Neg(ltree, ntree);

    cout << "Literal: ";
    ltree->print(); 
    cout << "-> "<< ltree->eval() << endl;
    
    cout << "Add: ";
    atree->print();
    cout << "= " << atree->eval() << endl;
   
    cout << "Negative: ";
    ntree->print();
    cout << "-> " << ntree->eval() << endl; 

    cout << "Literal and Add: ";
    latree->print();
    cout << "\n"; 

    // cout << "Literal and Negative: ";
    // lntree->print();
    // cout << "\n"; 

    delete ltree;
    delete atree;
    delete ntree;
    delete latree;
    // delete lntree;
    return 0;
}