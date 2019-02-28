
package tema.pkg2;

import java.util.*;

public class ex1 
{
   
    public static void main(String[] args)
    {
        
        Scanner in = new Scanner(System.in);
        int n, m, p, q;
        
        System.out.println("Introduceti numarul de linii si numarul de coloane pentru prima matrice\n");
        n = in.nextInt();
        m = in.nextInt();
        
        int a[][];
        a = new int[n][m];
        
        System.out.println("Introduceti elementele primei matrice\n");
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                a[i][j] = in.nextInt();
        
        System.out.println("Introduceti numarul de linii si numarul de coloane pentru a doua matrice\n");
        
        p = in.nextInt();
        q = in.nextInt();
        
        if(m != p) System.out.println("Cele 2 matrice nu pot fi inmultite!\n");
        
        else
        {
        int b[][];
        
        b = new int[p][q];
        
        System.out.println("Introduceti elementele celei de-a doua matrice\n");
        
        for(int i = 0; i < p; i++)
            for(int j = 0; j < q; j++)
                b[i][j] = in.nextInt();
        
        int produs[][];
        int i, j, k, suma = 0;
        
        produs = new int[n][q];
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < q; j++)
            {
                for(k = 0; k < p; k++)
                    suma +=  a[i][k] * b[k][j];
            }
            produs[i][j] = suma;
            suma = 0;
        }
        
            System.out.println("Matricea rezultata\n");
            
            for(i = 0; i < n; i++)
            {
                for(j = 0 ;j < q; j++)
                    System.out.println(produs[i][j]+"\t");
                System.out.print("\n");
            }       
        
        }
    }
}
