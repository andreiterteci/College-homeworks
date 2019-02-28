#include <iostream>

using namespace std;

struct arbore
{
    int val;
    arbore *st,*dr;
};

void insert(arbore* &radacina, int x)
{
    if(radacina==NULL)
    {
        radacina = new arbore;
        radacina->val=x;
        radacina->st = radacina->dr=NULL;
    }
    else if(x <= radacina->val)
        insert(radacina->st,x);
    else insert(radacina->dr,x);
}

bool search(arbore* radacina,int x)
{
    if(radacina==NULL) return false;
    else if(x==radacina->val) return true;
    else if(x<radacina->val)
        return search(radacina->st,x);
    else return search(radacina->dr,x);
}

void findMax(arbore* radacina)
{
    arbore *a = radacina;
    if(a==NULL)
    {
        cout<<"Arbore nul!";
        return;
    }
    if(a->dr==NULL)
        cout<<a->val;
    else findMax(a->dr);
}

arbore* findMin(arbore* radacina)
{
    while(radacina->st!=NULL) radacina=radacina->st;
    return radacina;
}

void sterge(arbore* &radacina, int x)
{
    if(radacina==NULL) return;
    else if(x<radacina->val) sterge(radacina->st,x);
    else if(x>radacina->val) sterge(radacina->dr,x);
    else
        {
            //nicio frunza
            if(radacina->st==NULL && radacina->dr==NULL)
            {
                delete radacina;
                radacina=NULL;
            }
            //o singura frunza
            else if(radacina->st==NULL)
            {
                arbore *a=radacina;
                radacina=radacina->dr;
                delete a;
            }
            else if(radacina->dr==NULL)
            {
                arbore *a=radacina;
                radacina=radacina->st;
                delete a;
            }
            else
            {
                arbore *a = findMin(radacina->dr);
                radacina->val = a->val;
                sterge(radacina->dr, a->val);
            }
        }
}

void inorder(arbore* radacina)
{
    if(radacina==NULL) return;
    inorder(radacina->st);
    cout<<radacina->val<<" ";
    inorder(radacina->dr);
}

int main()
{

    arbore *radacina=NULL;
    insert(radacina,3);
    insert(radacina,10);
    insert(radacina,5);
    insert(radacina,8);
    insert(radacina,6);
    insert(radacina,11);
    cout<<search(radacina,11)<<endl;
    findMax(radacina);
    sterge(radacina,5);
    cout<<endl;
    inorder(radacina);
    return 0;
}
