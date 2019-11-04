#include <iostream>
#include <string.h>

using namespace std;

struct nod
{
    float info;
    nod* next;
};


void afisare_lista(nod *prim)
{
    nod *p=prim;
    while(p!=NULL)
    {
        cout<<p->info<< " ";
        p=p->next;
        }
}

void adaug_final(nod* prim, int val)
{
    nod* nou=new nod;
    nou->info=val;
    nou->next=NULL;
    nod* p=prim;
    while(p->next!=NULL)
        p=p->next;
    p->next=nou;
}

void adaug_inceput(nod* &prim, int val)
{
    nod* nou=new nod;
    nou->info=val;
    nou->next=prim;
    prim=nou;
}

void adaug_poz(nod* &prim, int poz, int val)
{
    if(poz==1)
    {
        adaug_inceput(prim,val);
        return;
    }
    nod* p=prim;
    for(int i=1;i<poz;i++){
        p=p->next;
        if(p==NULL) {cout<<"Pozitie prea mare";
        return;}}


        nod* nou=new nod;
        nou->info=val;
        nou->next=p->next;
        p->next=nou;


}

int caut_valoare(nod* prim, int val)
{
    int i=1;
    nod* p=prim;
    while(p!=NULL)
    {
        if(p->info==val)
        {
            cout<<"Elementul se gaseste in lista";
            return i;

        }
        i++;
        p=p->next;
    }
    if(p==NULL) cout<<"Elementul nu se gaseste in lista";
    return -1;
}

void caut_poz(nod* prim, int poz)
{
    nod* p=prim;
    for(int i=1;i<=poz&&p!=NULL;i++)
        p=p->next;
    if(p==NULL) cout<<"pozitia nu exista";
    else cout<<"pozitia exista";
}

void sterg_val(nod* &prim, int val)
{
    nod* p=prim;
    if(p->info==val)
    {
        nod* temp=p;
        prim=prim->next;
        delete temp;
    }
    else
    {
        while(p!=NULL){
            if(p->next->info==val) break;
            p=p->next;}
        if(p==NULL)
        {
            cout<<"nu exista in lista";
            return;

        }
        else
        {
            nod* temp=p->next;
            p->next=temp->next;
            delete temp;
        }

    }
}

void sterg_lista(nod* &prim)
{
    if(prim->next!=NULL) sterg_lista(prim->next);
    prim=NULL;
    delete prim;
}

void creez_lista_ordonata(nod* &prim)
{
    int val;
    cout<<"Prima valoare:";
    cin>>val;
    prim->info=val;
    prim->next=NULL;
    cout<<"Pentru oprire cititi 10000"<<endl;
    cin>>val;
    while(val!=10000)
    {
        if(val<prim->info) adaug_inceput(prim,val);
        else
        {
            nod* p=prim;
            int i=2;
            while(p!=NULL)
            {
                if(p->info>=val) break;
                i++;
                p=p->next;
            }

            if(p==NULL) adaug_final(prim,val);
            else adaug_poz(prim,i,val);

        }
        cout<<"Introduceti alt nr"<<endl;
        cin>>val;
    }

    afisare_lista(prim);
}

void supl3(nod* prim)
{
    nod* p=prim;
    int nrpoz=0, nrneg=0;
    float medie=0;
    while(p!=NULL)
    {
        if(p->info>=0) nrpoz++;
        else
        {
            nrneg++;
            medie+=p->info;
        }
        p=p->next;
    }
    medie=(float)medie/nrneg;
    cout<<"Medie negative="<<medie<<endl;
    cout<<"Nr pozitive="<<nrpoz;
}

void supl4(nod* &prim)
{
    float medie;
    nod* p=prim;
    while(p->next!=NULL)
    {
        medie=(p->info+p->next->info)/2;
        nod* nou=new nod;
        nou->next=p->next;
        p->next=nou;
        nou->info=medie;
        p=p->next->next;
    }
    afisare_lista(prim);

}

void supl5()
{
    nod* l1=new nod;
    nod* l2=new nod;
    cout<<"citesc lista 1 pana la -1"<<endl;
    cin>>l1->info;
    l1->next=NULL;
    int val;
    cin>>val;
    while(val!=-1)
    {
        adaug_final(l1,val);
        cin>>val;
    }
    afisare_lista(l1);
    cout<<"citesc lista 2 pana la -1"<<endl;
    cin>>l2->info;
    cin>>val;
    while(val!=-1)
    {
        adaug_final(l2,val);
        cin>>val;
    }
    afisare_lista(l2);
    int suma, rest=0;
    nod* l3=new nod;
    suma=l1->info+l2->info;
    if(suma>=10)
    {
        suma=suma%10;
        rest=1;
    }
    nod * temp=l3;
    l3->info=suma;
    l3->next=NULL;
    l1=l1->next;
    l2=l2->next;
    while(l1!=NULL && l2!=NULL)
    {
        suma=l1->info+l2->info+rest;
        rest=0;
        if(suma>=10)
        {
            suma=suma%10;
            rest=1;
        }
        nod* nou=new nod;
        nou->info=suma;
        nou->next=NULL;
        l3->next=nou;
        l1=l1->next;
        l2=l2->next;
        l3=l3->next;

    }
    while(l1!=NULL)
    {
        nod* nou=new nod;
        nou->info=l1->info+rest;
        nou->next=NULL;
        rest=0;
        l3->next=nou;
        l1=l1->next;
        l3=l3->next;

    }
    while(l2!=NULL)
    {
        nod* nou=new nod;
        nou->info=l2->info+rest;
        nou->next=NULL;
        rest=0;
        l3->next=nou;
        l2=l2->next;
        l3=l3->next;
    }
    if(rest==1)
    {
        nod* nou=new nod;
        nou->info=1;
        nou->next=NULL;
        l3->next=nou;
    }
    l3=temp;
    cout<<endl;
    afisare_lista(l3);
}

void meniu()
{
    nod* prim=new nod;
    cout<<"capul listei=";
    cin>>prim->info;
    prim->next=NULL;
    char optiune;
    int elem,poz;
    cout<<"OPTIUNI: "<<endl;
    cout<<"A: afisez lista"<<endl;
    cout<<"B: adaug la inceput"<<endl;
    cout<<"C: adaug la final"<<endl;
    cout<<"D: adaug pe o pozitie"<<endl;
    cout<<"E: caut element dupa valoare"<<endl;
    cout<<"F: caut element dupa pozitie"<<endl;
    cout<<"G: sterg element dupa valoare"<<endl;
    cout<<"I: sterg intreaga lista"<<endl;
    cout<<"X: inchid programul"<<endl;
    cin>>optiune;
    optiune=tolower(optiune);
    while(optiune!='x'){
        switch (optiune)
       {
        case 'a':
            afisare_lista(prim);break;
        case 'b':
            cout<<"Element de adaugat=";
            cin>>elem;
            adaug_inceput(prim,elem);
            break;
        case 'c':
            cout<<"Element de adaugat=";
            cin>>elem;
            adaug_final(prim,elem);
            break;
        case 'd':
            cout<<"Element de adaugat=";
            cin>>elem;
            cout<<"pozitie de adaugat=";
            cin>>poz;
            adaug_poz(prim,poz,elem);
            break;
        case 'e':
            cout<<"Elementul cautat=";
            cin>>elem;
            caut_valoare(prim,elem);
            break;
        case 'f':
            cout<<"Pozitia cautata=";
            cin>>elem;
            caut_poz(prim,elem);
            break;
        case 'g':
            cout<<"Elementul de sters=";
            cin>>elem;
            sterg_val(prim,elem);
            break;
        case 'i':
            sterg_lista(prim);
            break;


       }
       if(optiune=='i') return;


    cout<<endl<<"OPTIUNI: "<<endl;
    cout<<"A: afisez lista"<<endl;
    cout<<"B: adaug la inceput"<<endl;
    cout<<"C: adaug la final"<<endl;
    cout<<"D: adaug pe o pozitie"<<endl;
    cout<<"E: caut element dupa valoare"<<endl;
    cout<<"F: caut element dupa pozitie"<<endl;
    cout<<"G: sterg element dupa valoare"<<endl;
    cout<<"H: sterg element dupa pozitie"<<endl;
    cout<<"I: sterg intreaga lista"<<endl;
    cout<<"X: inchid programul"<<endl;

    cin>>optiune;
    optiune=tolower(optiune);
    cout<<endl;
    }



}

int main()
{


    //meniu();
    nod * ord=new nod;
//    creez_lista_ordonata(ord);
    nod* prim=new nod;
    prim->info=3;
    prim->next=NULL;
    adaug_final(prim,4);
    adaug_final(prim,5);
    adaug_final(prim,6);
    adaug_final(prim,7);
    adaug_final(prim,-2);
    adaug_final(prim,-4);
    afisare_lista(prim);
    supl3(prim);
    cout<<endl;
    supl4(prim);








}
