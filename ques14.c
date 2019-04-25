#include<stdio.h>
int main(
{
	int i=0,k,n=1,c=-2,m,tt=0,at=0,bt=0,mina=1000,minp=100000,tar=0,sumt=0,sumw=0,j,flag=1,flag1=0,flag2=0,flag4=0;
		
	printf("ENTER THE NUMBER OF PROCESSES\n");
	scanf("%d",&n);
	
	int p[n],a[n],b[n],rt[n],turn[n],wt[n],d[n],g[n];
	
	for(i=0;i<n;i++)
	{
	printf("ENTER ARRIVAL TIME AND BURST TIME AND PRIORITY FOR PROCESS %d\n",i);
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
		scanf("%d",&p[i]);
	}
		
	printf("PNO.\tARR\tBUR\tPRI\n");

	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\n",i,a[i],b[i],p[i]);
	}
	
	for(i=0;i<n;i++)
	{
	rt[i]=b[i];
	wt[i]=0;
	g[i]=0;
	d[i]=0;
	}
	
	for(i=0;i<n;i++)
	{
		if(a[i]<mina)
		{
			mina=a[i];
			tar=i;
			minp=p[i];
			d[i]=0;
		}
		else
		if(a[i]==mina)
		{
			if(p[i]<minp)
			{
			mina=a[i];
			tar=i;
			minp=p[i];
			d[i]=0;
			}
			else
			if(p[i]==minp)
			{
				if(rt[i]<rt[tar])
				{
					tar=i;
					minp=p[i];
				}
			}
		}
		else
		{
			continue;
		}
	}
		
	tt=mina;
	
	while(flag==1)
	{
		   //                                          	printf("%d\t%d\t%d\t%d\n",tar,tt,wt[tar],p[tar]);
		
		
		rt[tar]=rt[tar]-1;
		tt++;
		
			 for(k=0;k<n;k++)
	          {
	          	if(k!=tar&&a[k]<=tt)
	        	{
	               d[k]=d[k]+1;		
			    }
			    
			    if(d[k]%2==0 && d[k]!=0 && a[k]<=tt && k!=tar)
			    {
			    	p[k]--;
			    	d[k]=0;
				}
		      
	          }
	          
	          
	    if(rt[tar]==0)
		{
			//g[tar]=wt[tar];
			turn[tar]=tt-a[tar];
			g[tar]=turn[tar]-b[tar]; // g is waiting time
			p[tar]=100000;
			minp=100000;
			
			
		for(i=0;i<n;i++)
		{
			if(a[i]<=tt && minp>p[i])
			{
				minp=p[i];
				tar=i;
				c++;
				
			}
			else
			if(a[i]<=tt && minp==p[i])
			{
				if(rt[tar]>rt[i])
				{
				tar=i;
				minp=p[i];
				c++;
			}
				
			}
			else
			{
				continue;
			}
																														minp=1000;
		}
					
		}
		else
		{
			
			for(i=0;i<n;i++)
		   {
			if(p[i]<p[tar]&&a[i]<=tt)
			{
				tar=i;
				minp=p[i];
				flag1=1;
			}
			else
			if(p[i]==p[tar]&&a[i]<=tt)
			{
				if(rt[i]<rt[tar])
				{
				tar=i;
				minp=p[i];
				flag1=1;
				}
			}
			else
			{
				continue;
			}
			
		                minp=10000;
		}
		
		if(flag1==1)
		{
			tt=tt+2;
			flag1=0;
						
	          for(k=0;k<n;k++)
	          {
	          	for(m=0;m<2;m++)
	          	{
	          	if(a[k]<=tt)
	        	{
	               d[k]=d[k]+1;		
			    }
			    if(d[k]%2==0&&d[k]!=0&&a[k]<=tt)
			    {
			    	p[k]--;
			    	d[k]=0;
				}
		      
				  }
	          	
	          }
					
		}
			
			
		}
		
		flag=0;
		for(j=0;j<n;j++)
		{
		    if(rt[j]!=0)
		    {
		    	flag=1;
		    	break;
			}
		}
		
	}
	
		printf("\n\n");
	printf("PNO.\t TUR\t WAIT \n");
	
	for(j=0;j<n;j++)
	{
		printf("P%d\t%d\t%d\n",j,turn[j],g[j]);
		sumt=sumt+turn[j];
		sumw=sumw+g[j];
	}
	

	printf("\n\n");		
	double att=sumt/(n);
	double awt=sumw/(n);
	printf("\n");
	printf("TOTAL TIME = %d\n",(tt));
	printf("AVERAGE TURNAROUND TIME = %.2f\n",att);
	printf("AVERAGE WAITING TIME = %.2f\n",awt);
	
	
}
	
	
	
	
	
