// Find the smallest island size  
#include<iostream>
#include<queue>
#include<set>
#include<unordered_map>
using namespace std; 


void Show_visited(int Visited[6][6])
{
	static uint32_t u= 1;
	cout <<"Called : " << u<<"\n";
	u++;
		for(int i=0 ; i<6 ; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << Visited[i][j]<<" ";

		}
		cout << endl; 
	}

}

void count_island(int i, int j, char M[6][6], int Visited[6][6] , int &min_island)
{   
	int Num_of_lands_in_one_island = 0; 
	queue<int> q_x,q_y , q_x2 , q_y2;
	q_x.push(i);
	q_y.push(j);
	Visited[i][j] = 1; 

	while (!q_x.empty() && !q_y.empty())
	{   
		Num_of_lands_in_one_island++;
		// i and j of the source node
		int tempx = q_x.front();
		int tempy = q_y.front();	
		
		if(!q_x.empty())
		q_x.pop();
		if(!q_y.empty())
		q_y.pop();
		
		Visited[tempx][tempy] = 1; 

	 
			if ( ( tempx-1>=0) &&  M[tempx - 1][tempy] == 'l' && Visited[tempx-1][tempy] == 0 )
			{   
				cout << "Fun 1  Up\n";
				q_x.push(tempx - 1);
				q_y.push(tempy);
			}
			 if((tempx + 1 < 6) && M[tempx + 1 ][tempy] == 'l' && Visited[tempx + 1][tempy] == 0)
			{
				cout << "Fun 2  Down\n";
				q_x.push(tempx +1);
				q_y.push(tempy);
			}
			 if ((tempy - 1 >= 0) && M[tempx ][tempy -1 ] == 'l' && Visited[tempx][tempy-1] == 0)
			{
				cout << "Fun 3  Back\n";
				q_x.push(tempx);
				q_y.push(tempy - 1);
			}
			if ((tempy +1 <6 ) && M[tempx][tempy + 1] == 'l' && Visited[tempx][tempy + 1] == 0)
			{
				cout << "Fun 4  Front\n";
				q_x.push(tempx );
				q_y.push(tempy + 1);
			}
			q_x2 = q_x; 
			q_y2 = q_y;

			while (!q_x2.empty())
			{
				cout << " x = " << q_x2.front() << " y = "<<q_y2.front()<<endl;
				q_x2.pop(); q_y2.pop();
			}
			
	}
	Show_visited(Visited);
	min_island = min(Num_of_lands_in_one_island, min_island); 
}

void something(char M[6][6] , int Visited[6][6])
{   

	int island_ctr = 0 , min_island = INT_MAX ; 
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{   
			/*
			if (M[i][j] == 'w')
			{
				Visited[i][j] == 1; 
				
			}
			*/

			if (M[i][j] == 'l' && Visited[i][j] == 0)
			{
				count_island(i, j, M ,Visited ,min_island); 
				island_ctr++;
			}
		}
	}
	cout << "\nTotal island = " << island_ctr << endl;
	cout << "\nMin Island size = " << min_island << endl; 
}

int main()
{
	
	int Visited[6][6] = { 0 };
	char M[6][6] = { 
		{'w','l','w','w','w','w'},
		{'l','l','w','w','w','l'},
		{'w','w','w','w','l','l'},
		{'w','w','l','l','w','l'},
		{'w','w','l','l','w','l'},
		{'l','w','w','w','w','w'},
	};
	

	something(M, Visited);
	
	return 0; 
}
