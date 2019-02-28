package tema.pkg2;

import java.util.*;

public class Ex2 {
    
    public static void main(String args[])
    { 
        Scanner in = new Scanner(System.in);
        
        int n, v[];
        
        System.out.println("Introduceti numarul de elemente ale vectorului\n");
        n = in.nextInt();
        
        System.out.println("Introduceti elementele vectorului\n");
        v = new int[n];
        
        int max = 0;
        
        for(int i =0; i < n; i++)
        {
            v[i] = in.nextInt();
            if(v[i]>max) max = v[i];
        }
        
        int aparitii[];
        aparitii = new int[max+1];
        
        for(int i = 0; i <= max;i++)
            aparitii[i]=0;
        
        for(int i = 0; i < n; i++)
            aparitii[v[i]]++;
        
        System.out.println("Introduceti suma\n");
        
        int x;
        x = in.nextInt();
        
        for(int i = 0; i < n; i++)
            if(aparitii[x-v[i]]>=1)
                System.out.println(aparitii[x-v[i]]+"+"+v[i]+"="+x);
    }
}

    

