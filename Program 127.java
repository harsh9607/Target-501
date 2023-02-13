import java.util.*; 
import java.io.*; 

class Subsets
{
	

	public static void main(String... args)
	{
		Character[] S = new Character[] { 'a','b','c' }; 
		for(int i= 0 ; i<Math.pow(2,S.length);i++)
		{   int I = i ; 
			char[] x = {'0','0','0'}; 	
			
			int j=2; 

				while(I>0)
				{
					int rem = I%2 ;
					if(rem==0 ) 
					{x[j] = '0'; j--; } 
					
					else{x[j] = '1'; j--;}

					I=I/2;
					if(I==1)
						{x[j] = '1'; break;  }
					 
				}
				for(int y=0 ; y<3; y++)
				{
					System.out.print(x[y]); 
				}
				System.out.println();
				
				for(int y = 0; y<3 ; y++ )
				{
					if(x[y]=='0')
					{
						System.out.print('_');
					}
					else
					{
						System.out.print(S[y]); 
					}
				}
				System.out.println();
			

			
		}

	}
} 
