#include <stdio.h>
int maxQuotient(float [], int, int []);
int sum(int []);
int main() {
    int party_num, deputy_num, i, j, max=-1, max_index;
    int current_seat[50] = {0}, partys[50], votes[50];
    float quotient[50];
    scanf("%d %d", &party_num, &deputy_num);
    for (i=0; i<party_num; i++){
        partys[i] = 65+i;
        scanf("%d", &votes[i]);
    }
    for(j=0; j<deputy_num; j++){
        for (i=0; i<party_num; i++){
            quotient[i]=(float)votes[i]/(float)(current_seat[i]+1);
        }
        current_seat[maxQuotient(quotient,party_num,votes)]+=1;
    }
    while(sum(current_seat)!=0){
        for(i=0; i<party_num; i++){
            if (current_seat[i]>max){
                max_index=i;
                max=current_seat[i];
            }
        }
        if (max!=0){
            printf("%c: %d\n", partys[max_index], max);
        }
        current_seat[max_index]=0;
        max=0;
    }
    return 0;
}
int maxQuotient(float quoArr[], int size, int voteArr[]){
    int i;
    float max = -1;
    int max_index;
    for(i=0; i<size; i++){
        if (quoArr[i]>max){
            max_index=i;
            max=quoArr[i];
        }
        else if(quoArr[i]==max){
            if (voteArr[i]>voteArr[max_index]){
                max_index=i;
                max=quoArr[i];
            }
        }
        else{
            max_index=max_index;
            max=max;
        }
    }
    return max_index;
}
int sum(int arr[]){
    int i, sum=0;
    for(i=0; i<50; i++){
        sum += arr[i];
    }
    return sum;
}