#include <iostream>
#include <math.h>

using namespace std;

struct polinom
{
    int gr,coef;
    polinom *next;
};

void citesc_polinom(polinom* &p)
{
    cout<<"coeficient x^"<<p->gr;
    cin>>p->coef;
    p->next=NULL;
    polinom* temp=p;
    for(int i=temp->gr-1;i>=0;i--)
    {
        polinom* nou=new polinom;
        nou->gr=i;
        cout<<"coeficient x^"<<i;
        cin>>nou->coef;
        temp->next=nou;
        nou->next=NULL;
        temp=nou;
    }
}

void inmultesc_scalar(polinom * &p, int a)
{
    polinom* temp=p;
    while(temp!=NULL)
    {
        temp->coef*=a;
        temp=temp->next;
    }
}

int P(polinom *p, int x)
{
    int evaluare=0;
    polinom* temp=p;
    while(temp!=NULL)
    {
        evaluare=evaluare + temp->coef*pow(x,temp->gr);
        temp=temp->next;
    }
    return evaluare;
}

void afisez_polinom(polinom *p)
{
    polinom* temp=p;
    while(temp->next!=NULL)
    {
        if(temp->coef!=0)
            if(temp->coef>0) cout<<"+"<<temp->coef<<"X^"<<temp->gr;
            else cout<<temp->coef<<"X^"<<temp->gr;
        temp=temp->next;
    }
    if(temp->coef>0)
        cout<<"+"<<temp->coef<<endl;
    else cout<<temp->coef;
}

polinom suma_polinoame(polinom *p1, polinom *p2)
{
    polinom *temp1=p1;
    polinom *temp2=p2;
    polinom *p=new polinom;
    polinom *INCEPUT=p;
    if(p1->gr>p2->gr)
        {
        p->gr=p1->gr;
        p->coef=p1->coef;
        p->next=NULL;

        }
    if(p1->gr<p2->gr)
        {
        p->gr=p2->gr;
        p->coef=p2->coef;
        p->next=NULL;

        }

    cout<<"semn1"<<endl;





    while(temp1->gr>temp2->gr)
    {
        polinom* nou=new polinom;
        nou->gr=temp1->gr;
        nou->coef=temp1->coef;
        nou->next=NULL;
        p->next=nou;
        p=nou;

        temp1=temp1->next;
    }

    cout<<"semn2"<<endl;

    while(temp1->gr<temp2->gr)
    {
        polinom* nou=new polinom;
        nou->gr=temp2->gr;
        nou->coef=temp2->coef;
        nou->next=NULL;
        p->next=nou;
        p=nou;
        temp2=temp2->next;
    }

    cout<<"semn 3"<<endl;

    while(temp1!=NULL)
    {
        polinom* nou=new polinom;
        nou->gr=temp1->gr;
        nou->coef=temp1->coef+temp2->coef;
        nou->next=NULL;
        p->next=nou;
        p=p->next;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    cout<<"semn 4"<<endl;
    INCEPUT=INCEPUT->next;
    afisez_polinom(INCEPUT);

}

int main()
{

    polinom* N=new polinom;
    polinom* M=new polinom;
    cout<<"Gradele polinoamelor: ";
    cin>>N->gr>>M->gr;
    /*citesc_polinom(N);
    afisez_polinom(N);
    cout<<endl;
    int a;
    cout<<"scalar=";
    cin>>a;
    //inmultesc_scalar(N,a);
    afisez_polinom(N);
    cout<<endl<<"p(3)="<<P(N,4);
    cout<<endl<<endl;*/
    citesc_polinom(N);
    citesc_polinom(M);
    afisez_polinom(N);cout<<endl;
    afisez_polinom(M);cout<<endl;
    suma_polinoame(N,M);

    return 0;
}
