import java.util.*;
class x
{
    public static void main(String args[])
    {
        int t;
        Scanner s=new Scanner(System.in);
        t=s.nextInt();
        String st=s.nextLine();
        while(t>0)
        {
            st=s.nextLine();
            st=s.nextLine();
            if(st.contains("D")||st.contains("0")||st.contains("J"))
            System.out.println("YES");
            else
            System.out.println("NO");
            t--;
        }
    }
}