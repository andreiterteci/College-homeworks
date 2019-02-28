#include <iostream>
#include "carte.h"
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include "lista.h"

using namespace std;

int main()
{
    carte c1;
    Vector <carte> l1(1);
    int x,y,z;
    carte a(1,2008,"The Hunger Games","Suzanne Collins",40);
    carte b(2,1997,"Harry Potter and the Sorcerer's stone","J.K. Rowling",50);
    carte c(3,2000,"Harry Potter and the Goblet of Fire","J.K. Rowling",56);
    carte d(4,1998,"Harry Potter and the Chamber of Secrets","J.K. Rowling",36);
    carte e(5,2016,"Harry Potter and the Cursed Child","J.K. Rowling",44);
    carte f(6,2005,"Harry Potter and the Half-Blood Prince","J.K. Rowling",56);
    carte g(7,2003,"Harry Potter and the Order of the Phoenix","J.K. Rowling",19);
    carte h(8,1999,"Harry Potter and the Pisoner of Azkaban","J.K. Rowling",36);
    carte i(9,2007,"Harry Potter and the Deathly Hallows","J.K. Rowling",51);
    carte j(10,1955,"The Lord of The Rings","J.R.R. Tolkien",135);
    carte k(11,1937,"The Hobbit","J.R.R. Tolkien",37);
    carte l(12,2006,"The Da Vinci Code","Robert Langdon",47);
    carte m(13,2012,"Divergent","Veronica Roth",34);
    carte n(14,2004,"The Great Gatsby","F. Scott Fitzgerald",61);
    carte o(15,2006,"The Lovely Bones","Alice Sebold",31);
    l1.add(a);
    l1.add(b);
    l1.add(c);
    l1.add(d);
    l1.add(e);
    l1.add(f);
    l1.add(g);
    l1.add(h);
    l1.add(i);
    l1.add(j);
    l1.add(k);
    l1.add(l);
    l1.add(m);
    l1.add(n);
    l1.add(o);
    system("cls");
    cout<<"*************************************************************************";
    cout<<"\n\t\t\t\tBUN VENIT!\n";
    cout<<"*************************************************************************";
    cout<<"\n\t1.Adaugati o noua carte in stoc";
    cout<<"\n\t2.Stergeti o carte din stoc";
    cout<<"\n\t3.Modificati datele unei carti";
    cout<<"\n\t4.Cautare carte";
    cout<<"\n\t5.Afisarea cartilor disponibile";
    cout<<"\n\t0.Iesire";
    cout<<"\nIntroduceti optiunea(0-5): ";
    cin>>x;
    while(x < 0 || x > 5)
    {
        cout<<"Optiunea aleasa nu exista!"<<endl<<"Introduceti o noua optiune: ";
        cin>>x;
    }
    while(x)
    {
        switch(x)
        {
        case 1:
        {
            system("cls");
            cout<<"Introduceti datele:"<<endl;
            cin>>c1;
            l1.add(c1);
            cout<<"\tCartea a fost adaugata cu succes!";
            cout<<"\n\tApasati orice tasta pentru a continua!";
            getch();
            break;
        }
        case 2:
        {
            system("cls");
            if(l1.getNr() == 1)
            {
                cout<<"Lista de carti esti goala!";
                cout<<"\n\tApasati orice tasta pentru a continua!";
                getch();
                break;
            }
            cout<<"Introduceti id-ul cartii pe care doriti sa o stergeti: ";
            cin>>z;
            while (z < 0 || z > l1.getNr()-1)
            {
                cout<<"ID-ul este invalid!";
                cout<<endl;
                cout<<"Introduceti un nou id: ";
                cin>>z;
            }
            l1.stergere(z);
            cout<<"\tCartea a fost stearsa cu succes!";
            cout<<"\n\tApasati orice tasta pentru a continua!";
            getch();
            break;
        }
        case 3:
            {
            system("cls");
            if(l1.getNr() == 1)
            {
                cout<<"Lista de carti esti goala!";
                cout<<"\n\tApasati orice tasta pentru a continua!";
                getch();
                break;
            }
            cout<<"Introduceti id-ul cartii pe care doriti sa o modificati: ";
            cin>>z;
            while (z < 0 || z > l1.getNr()-1)
            {
                cout<<"ID-ul este invalid!";
                cout<<endl;
                cout<<"Introduceti un nou id: ";
                cin>>z;
            }
            l1.modificare(z);
            cout<<"\tCartea a fost modificata cu succes";
            cout<<"\n\tApasati orice tasta pentru a continua!";
            getch();
            break;
            }
        case 4:
        {
            system("cls");
            if(l1.getNr() == 1)
            {
                cout<<"Lista este goala!";
                cout<<"\n\tApasati orice tasta pentru a continua!";
            getch();
                break;
            }
            cout<<"Introduceti id-ul cartii: ";
            cin>>z;
            while (z < 1 || z > l1.getNr()-1)
            {
                cout<<"Cartea nu exista!";
                cout<<endl;
                cout<<"Introduceti un nou id: ";
                cin>>z;
            }
            l1.afisare_carte(z);
            cout<<"\n\tApasati orice tasta pentru a continua!";
            getch();
            break;
        }
        case 5:
        {
            system("cls");
            l1.display();
            cout<<"\n\tApasati orice tasta pentru a continua!";
            getch();
            break;
        }
        }
        system("cls");
        cout<<"\n\t1.Adaugati o noua carte in stoc";
        cout<<"\n\t2.Stergeti o carte din stoc";
        cout<<"\n\t3.Modificati datele unei carti";
        cout<<"\n\t4.Cautare carte";
        cout<<"\n\t5.Afisarea cartilor disponibile";
        cout<<"\n\t0.Iesire";
        cout<<"\nIntroduceti optiunea(0-5): ";
        cin>>x;
        while(x < 0 || x > 5)
        {
            cout<<"Optiunea aleasa nu exista!"<<endl<<"Introduceti o noua optiune: ";
            cin>>x;
        }
    }
    return 0;
}
