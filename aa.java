import java.io.*;
class EH{
	public static void main(String [] args){
		int temp=0;
		int s,a,b;
		a=5;
		if(a==0){
				throw new ArithmeticException("Input is wrong");
			}
		try{
			b=3;
			s=a/b;	
			System.out.println(s);	
		}catch(Exception e){
			temp=1;
			System.out.println("Division by zero is not piossible");
			
		}finally{
			if(temp==1){
				System.out.println("\nOUTPUT NOT FOUND\n");
			}
			else{
				System.out.println("\nOUTPUT FOUND\n");
			}
			
		}
	}
}
