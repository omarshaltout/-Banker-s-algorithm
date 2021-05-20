// Banker's Algorithm
#include <stdio.h>

#define n 5 
#define m 4

int main()
{
	// P0, P1, P2, P3, P4....etc  are the Process names.

	int  i, j, k; 
	       // n: Number of processes 
		   // m: Number of resources

	// (1)Allocation matrix.
	int alloc[n][m]; 

	// take allocation matrix from the user.
	printf("Enter allocation matrix: \n");

	for (i = 0; i < n; i++) {


		for (j = 0; j < m; j++)
		{
			scanf_s("%d", &alloc[i][j]);

		}

	}

	

	// (2)max matrix.
	int max[n][m];

	// take max matrix from the user.
	printf("Enter max matrix: \n");

	for (i = 0; i < n; i++) {


		for (j = 0; j < m; j++)
		{
			scanf_s("%d", &max[i][j]);

		}

	}

	

	//(3)Available matrix.

	int avail[m];  // Available Resources.

	// take available matrix from the user.
	printf("Enter the available matrix: \n");
	
	for (i = 0; i < m; i++)
	{
		scanf_s("%d", &avail[i]);
	}
	
	
	
	// print Allocation matrix.
	printf("Allocation matrix: \n");
	for (i = 0; i < n; i++) {


		for (j = 0; j < m; j++)
		{
			printf("%d ", alloc[i][j]);

		}
		printf("\n");

	}

	// print max matrix.
	printf("Maximum matrix: \n");
	for (i = 0; i < n; i++) {


		for (j = 0; j < m; j++)
		{
			printf("%d ", max[i][j]);

		}
		printf("\n");

	}

	//print available matrix.
	printf("available matrix: \n");
	for (i = 0; i < m; i++)
	{
		printf("%d ", avail[i]);
	}
	printf("\n");


	int finish[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		finish[k] = 0;
	}

	// (4) Need matrix.

	//calculate need matrix. 
	int need[n][m];

	printf("need matrix: \n");
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < m; j++) 
		{

			need[i][j] = max[i][j] - alloc[i][j];
			printf("%d ", need[i][j]);
		}
		
		printf("\n");
	}


	int y = 0;
	for (k = 0; k < 5; k++) 
	{
		for (i = 0; i < n; i++) 
		{
			if (finish[i] == 0) 
			{

				int flag = 0;
				for (j = 0; j < m; j++) 
				{
					if (need[i][j] > avail[j]) 
					{
						flag = 1;
						break;
					}
				}

				if (flag == 0) 
				{
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					finish[i] = 1;
				}
			}
		}
	}

	printf("your sequence of processes is safe\n");
	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n - 1]);

	return (0);

	// OmarShaltout 1600849 
}
