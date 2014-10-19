import java.io.*;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author gtm
 */
public class NewClass {
    
    public static void main(String a[]) throws IOException {
        BufferedReader d=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(d.readLine());
        while(t-->0) {
            
            int arr[]=new int[102];
            int hash[]=new int[26];
            String x;
            x=d.readLine();
            x=x.toLowerCase();
            int n=x.length();
            int i;
            for(i=0;i<26;i++)  
                hash[i]=0;
            
            for(i=0;i<n;i++) {
                hash[(x.charAt(i)-'a')]++;
            }
            
            
            
            int flag=0;
            int count=0;
            if(n<5)
                System.out.println("-1");
            else {
                for(i=0;i<26;i++) {
                    char ch=(char)(i+'a');
                    if(hash[i]>0){
                        if(ch=='l' || ch=='i' || ch=='u' || ch=='x'){
                            count=count+hash[i]-1;
                        }
                        else if(ch!='n') {
                            count=count+hash[i];
                        }
                    }
                }
                System.out.println(count);
            }
        }
    }
    
}
