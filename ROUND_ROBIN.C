#include<stdio.h>
int main(){
	int wt[20],bt[20],tat[20],i,j,n,k,t,p[20],temp=0,max,ct[20];
	float avgtat,avgwt;
	printf("\n Enter no.of process...");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("burst time for process %d....",i+1);
		scanf("%d",&bt[i]);
		ct[i]=bt[i];
	}
	printf("Enter the time slice...");
	scanf("%d",&t);
	max=bt[0];
	for(i=1;i<n;i++){
		if(max<bt[i]){
			max=bt[i];
		}
	}
	for(j=0;j<(max/t)+1;j++){
		for(i=0;i<n;i++){
			if(bt[i]!=0){
				if(bt[i]<=t){
					tat[i]=temp+bt[i];
					temp=temp+bt[i];
					bt[i]=0;
				}else{
					bt[i]=bt[i]-t;
					temp=temp+t;
				}
			}
		}
	}
	for(i=0;i<n;i++){
		wt[i]=tat[i]-ct[i];
		avgwt+=wt[i];
		avgtat+=tat[i];
	}
	printf("\t PROCESS \t BURST TIME \t WAITING TIME \t TURN AROUND TIME\n");
	for (i=0;i<n;i++){
		printf("\n\t%d\t\t%d\t\t%d\t\t%d\t\t",i+1,bt[i],wt[i],tat[i]);
	}
	printf("\n Average waiting Time..%f",avgwt/n);
	printf("\n Average Turnaround Time..%f",avgtat/n);
}
