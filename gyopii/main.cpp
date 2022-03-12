#include <iostream>

using namespace std;
#include <iostream>

using namespace std;

struct elem
{

    int inf;
    elem* elo, *kov;

};

elem *fej, *veg;

void letrehoz(elem* &fej, elem* &veg)
{

    fej= new elem;
    cin>>fej->inf;
    fej->kov=0;
    fej->elo=0;
    veg=fej;

}
void hozzaad(elem* &veg)
{

    elem* akt= new elem;
    cin>>akt->inf;
    akt->kov=0;
    veg->kov=akt;
    akt->elo=veg;
    veg=akt;

}


void paratlan(elem *&feje)
{
    elem *p=feje, *r;
    while(p->kov!=0)
    {
        if(p->inf%2==1)
        {
            if(p==veg)
            {
                elem* akt= new elem;
                akt->inf=p->inf;
                akt->kov=0;
                akt->elo=veg;
                veg->kov=akt;
                veg=akt;
            }
            else
            {
                elem *akt=new elem;
                akt->inf=p->inf;
                akt->kov=p->kov;
                akt->elo=p;
                p->kov->elo=akt;
                p->kov=akt;

            }
            p=p->kov->kov;
        }
        else
        p=p->kov;
    }
}
void bejaras(elem* fej)
{

    elem* p=fej;
    while(p)
    {
        cout<<p->inf<<" ";
        p=p->kov;
    }
}
int main()
{
    int n;
    cin>>n;
    letrehoz(fej,veg);
    for(int i=1; i<n; i++)
        hozzaad(veg);
    bejaras(fej);
    cout<<endl;
    paratlan(fej);
    bejaras(fej);
    return 0;
}