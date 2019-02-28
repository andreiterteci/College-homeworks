package javaapplication1;

import java.util.*;

public class JavaApplication1 
{
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
  
        int m, n, x=0;
        int nr[];
        nr = new int[32];
        
        System.out.println("Introduceti numarul de numere: ");
        
        n = in.nextInt();
        
        System.out.println("Introduceti numerele:\n");
        
        for (int i = 0; i < n; i++) 
        {
            m = in.nextInt();
            
            while(m!=0)
            {
                if ((m&1)==1) nr[x]=1;
            else 
                nr[x]=0;
            x++;
            m=m>>1;
            }
        }
        for(int i=31; i>=0; i--)
            System.out.print(nr[i]);
        System.out.println("\n");
    }

}
