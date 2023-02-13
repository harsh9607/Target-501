// Print all Subsets possible 
// Subarray 
import java.util.* ;  

class Subarray{
	

	public static void main(String... args)
	{	

		System.out.println("Hi");

		Character[] Set = new Character[]{'a','b','c'};
		// print all subsets
		for(int i = 0 ; i<Set.length ; i++)
		{
			for(int j=i ; j<Set.length;j++)
			{
				for(int k = i ; k<=j ; k++)
				{
					System.out.print(Set[k]);
				}
				System.out.println();
			}
		} 	
	}
}
