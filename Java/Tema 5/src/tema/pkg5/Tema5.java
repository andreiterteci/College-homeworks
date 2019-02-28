package tema.pkg5;
import java.util.*;

abstract class AngajatUtm
{
    String nume;
    double salariu_baza;
    String universitate = "UTM";
    public AngajatUtm()
    {
        setNume("");
        setSalariu(0);
    }
    public AngajatUtm(String nume, Double salariu_baza, String universitate)
    {
        setNume(nume);
        setSalariu(salariu_baza);
        setUniversitate(universitate);
    }
    public void setNume(String nume)
    {
        this.nume = nume;
    }
    public void setSalariu(double salariu)
    {
        this.salariu_baza = salariu;
    }
    public void setUniversitate(String universitate)
    {
        this.universitate = universitate;
    }
    public String getNume()
    {
        return this.nume;
    }
    public double getSalariu()
    {
        return this.salariu_baza;
    }
    public String getUniversitate()
    {
        return this.universitate;
    }
    public String toString()
    {
         return "Nume: " +getNume()+ "\nSalariul de baza: " +getSalariu()+ "\nUniversitate: " +getUniversitate();
    }
    public boolean eguals(Object ob){
       if(ob == null) return false;
       if(this == ob) return true;
       if(this.getClass() != ob.getClass()) return false;
       
       AngajatUtm a = (AngajatUtm) ob;
       if(this.salariu_baza == a.salariu_baza)
           return true;
       if(this.nume == a.nume) 
           return true;
       return false;
   }
    abstract double salariu();
}

class CadruDidactic extends AngajatUtm
{
    String curs;
    int tarif_lunar;
    int numar_ore;
    public CadruDidactic()
    {
        super();
        setCurs("");
        setTarif(0);
        setNumarOre(0);
    }
    public CadruDidactic(String nume, double salariu_baza, String universitate, String curs, int tarif_lunar, int numar_ore)
    {
        super(nume, salariu_baza, universitate);
        setCurs(curs);
        setTarif(tarif_lunar);
        setNumarOre(numar_ore);
    }
    public void setCurs(String curs)
    {
        this.curs = curs;
    }
    public void setTarif(int tarif_lunar)
    {
        this.tarif_lunar = tarif_lunar;
    }
    public void setNumarOre(int numar_ore)
    {
        this.numar_ore = numar_ore;
    }
    public String getCurs()
    {
        return this.curs;
    }
    public int getTarif()
    {
        return this.tarif_lunar;
    }
    public int getNumarOre()
    {
        return this.numar_ore;
    }
    public String toString()
    {
        return "Nume: " +getNume()+ "\nUniversitate: " +getUniversitate() +"\nCurs: "+ getCurs() + "\nNumarul de ore: " + getNumarOre()+ "\nSalariul: " +salariu(); 
    }
    public boolean eguals(Object ob){
       if(ob == null) return false;
       if(this == ob) return true;
       if(this.getClass() != ob.getClass()) return false;
       
       CadruDidactic a = (CadruDidactic) ob;
       if(this.salariu_baza == a.salariu_baza)
           return true;
       if(this.nume == a.nume) 
           return true;
       if(this.curs == a.curs) 
           return true;
       if(this.tarif_lunar == a.tarif_lunar) 
           return true;
       if(this.numar_ore == a.numar_ore) 
           return true;
       return false;
   }
    double salariu()
    {
        return getNumarOre()*getTarif() + super.getSalariu();
    }
}

class Tsa extends AngajatUtm
{
    String functie;
    int spor;
    Tsa(String nume, double salariu_baza, String universitate, String functie, int spor)
    {
        super(nume, salariu_baza, universitate);
        setFunctie(functie);
        setSpor(spor);
    }
    public void setFunctie(String functie)
    {
        this.functie = functie;
    }
    public void setSpor(int spor)
    {
        this.spor = spor;
    }
    
    String getFunctie()
    {
        return this.functie;
    }
    
    int getSpor()
    {
       return this.spor;         
    }
    public String toString()
    {
        return "Nume: " +getNume()+ "\nUniversitate: " +getUniversitate() +"\nFunctie: "+ getFunctie() + "\nSalariul: " +salariu(); 
    }

    public boolean eguals (Object ob)
    {
        if(ob == null) 
            return false;
        if(this == ob) 
            return true;
        if(this.getClass() != ob.getClass()) 
            return false;
       
        Tsa a = (Tsa) ob;
        if(this.spor == a.spor)
           return true;
        if(this.functie == a.functie)
            return true;
       return false;
    }

    double salariu()
    {
        return (getSalariu() + getSalariu()*0.15);
    }

}
public class Tema5 
{
    
 
    public static void main(String[] args)
    {
        AngajatUtm []angajati = new AngajatUtm[5];
        
        angajati[0] = new CadruDidactic("Marius", 1700, "UNIBUC", "Java", 130, 7);
        angajati[1] = new CadruDidactic("Andrei", 1900, "ASE", "Economie", 160, 6);
        angajati[2] = new Tsa("Alexandru", 1200, "UNIBUC", "Paznic", 4);
        angajati[3] = new CadruDidactic("Gabriel", 1500, "ASE", "Probabilitate", 110, 2);
        angajati[4] = new Tsa("Andreea", 2000, "POLITEHNICA", "Secretara", 9);
        for(int i=0; i<5; i++)
            System.out.println(angajati[i].toString());
    }
    
}
