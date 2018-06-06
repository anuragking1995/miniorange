#include<bits/stdc++.h>
using namespace std;
void calcSum(int **arr,int m,int n,int k)
{
	if(k>n || k>m)
	{
		printf("Sub-matrix of size k doesn't exist");
		return;
	}
	int temp[m][n];//temprary array to store vertical elements i.e k vertical elements
	int i,j,total,r1,c1,msum,bsum,i1,j1;
	for(i=0;i<n;i++)
	{
		total=0;
		for(j=0;j<k;j++)
		{
			total+=arr[j][i];
		}
		temp[0][i]=total;
		for(j=1;j<m-k+1;j++)
		{
			total+=(arr[j+k-1][i]-arr[j-1][i]);
			temp[j][i]=total;
		}
	}
//	for(i=0;i<m-k+1;i++)
//	{
//		for(j=0;j<n;j++)
//		{
//			cout<<temp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	i1=j1=0;
	//i2=j2=k-1;
	msum=-1;
	for(i=0;i<m-k+1;i++)
	{
		total=0;
		for(j=0;j<k;j++)
		{
			total+=temp[i][j];
		}
		bsum=total;
		for(i1=i+1;i1<i+k-1;i1++)
		{
			for(j1=1;j1<k-1;j1++)
			{
				bsum-=arr[i1][j1];
			}	
		}
		if(bsum>msum)
		{
			msum=bsum;
			r1=i;
			c1=0;
		}
		for(j=1;j<n-k+1;j++)
		{
			total+=(temp[i][j+k-1]-temp[i][j-1]);
			bsum=total;
			for(i1=i+1;i1<i+k-1;i1++)
				{
					for(j1=j+1;j1<j+k-1;j1++)
						{
							bsum-=arr[i1][j1];
						}	
				}
			if(bsum>msum)
			{
				msum=bsum;
				r1=i;
				c1=j;
			}
		}
	}
	printf("Largest sum  with boundary is matrix\n");
	for(i=r1;i<r1+k;i++)
	{
		for(j=c1;j<c1+k;j++)
		{
			printf("%d ",arr[i][j]);
			
		}
		cout<<endl;
	}
	
}
int main()
{
	int m,n,k,i,j;
	printf("Input width i.e number of columns");
	scanf("%d",&n);
	printf("Input height i.e number of rows");
	scanf("%d",&m);
	int arr[m][n],*parr[m];
//	{{2,0,6,1,2,5},{1,0,5,0,1,3},{3,0,1,2,4,1},{0,1,3,1,1,9},{4,1,0,8,5,2},{0,1,0,1,2,3},{6,5,3,1,0,2},{0,0,1,6,0,4}};
	printf("Input mtrix with numbers from 0 to 9:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
		parr[i]=arr[i];
		
	}
		printf("Enter submatrix size");
		scanf("%d",&k);
		calcSum(parr,m,n,k);
	
	
	return 0;
}
