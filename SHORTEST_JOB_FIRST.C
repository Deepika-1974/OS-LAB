#include<stdio.h>
int main(){
	int wt[20],bt[20],tat[20],i,j,n,k,p[20],temp;
	float avgtat,avgwt;
	printf("\n Enter no.of process...");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		p[i]=i;
		printf("burst time for process %d....",i+1);
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n;i++){
		for(k=i+1;k<n;k++){
			if(bt[i]>bt[j]){
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
			}
		}
	}
	wt[0]=avgwt=0;
	tat[0]=avgtat=bt[0];
	for(i=1;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=tat[i-1]+bt[i];
		avgwt+=wt[i];
		avgtat+=tat[i];
	}
	printf("\t PROCESS \t BURST TIME \t WAITING TIME \t TURN AROUND TIME\n");
	for (i=0;i<n;i++){
		printf("\n\tp%d\t\t%d\t\t%d\t\t%d\t\t",p[i]+1,bt[i],wt[i],tat[i]);
	}
	printf("\n Average waiting Time..%f",avgwt/n);
	printf("\n Average Turnaround Time..%f",avgtat/n);
}
