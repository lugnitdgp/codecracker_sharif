import java.util.Scanner;
class debayanlinux {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = Integer.parseInt(sc.nextLine());
		while(t-->0) {
			String s;
			s = sc.nextLine();
			s = s.toLowerCase();
			int n = s.length();
			int res = 0;
			if(n < 5) res = -1;
			else {
				if(s.charAt(0) !='l') res++;
				if(s.charAt(1)!='i') res++;
				if(s.charAt(n-1) !='x') res++;
				if(s.charAt(n-2) !='u') res++;
				for(int i=2; i<n-2; i++) {
					if(s.charAt(i) != 'n') res++;
				}
			}
			System.out.println(res);
		}
	}
}