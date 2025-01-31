#include<stdio.h>
int mul(int count,int a[], int b[],int A[],int q);
void add(int A[], int a[]);
void sub(int A[], int a[]);
int  main(){
    int a[4],b[4];
    for (int i = 0; i <4; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i <4; i++)
    {
        scanf("%d",&b[i]);
    }
    int q=0;
    int A[4]={0,0,0,0}; 
int count =4;
    mul(count,a,b,A,q);
    return 0;
}

int mul(int count,int a[], int b[],int A[],int q){
    
    if(b[3]==0&&q==0){

       q=b[3];
       for(int i=3;i>0;i--){
        b[i]=b[i-1];
       }
       b[0]=A[3];
       for(int i=3;i>0;i--){
        A[i]=A[i-1];
       }

       count--;
       if(count ==0){
        for(int i=0; i<4; i++){
        printf("%d",A[i]);
        }
        for(int i=0; i<4; i++){
        printf("%d",b[i]);
        }
       return 0;
       }
       else{
        return mul(count,a,b,A,q);
       }
    }

    else if(b[3]==1&&q==1){
       q=b[3];
       for(int i=3;i>0;i--){
        b[i]=b[i-1];
       }
       b[0]=A[3];
       for(int i=3;i>0;i--){
        A[i]=A[i-1];
       }
  count--;
       if(count ==0){
        for(int i=0; i<4; i++){
        printf("%d",A[i]);
        }
        for(int i=0; i<4; i++){
        printf("%d",b[i]);
        }
       return 0;
       }
       else{
        return mul(count,a,b,A,q);
       }
    
    }
    else if(b[3]==0&& q==1){
        add(A,a);
  q=b[3];
       for(int i=3;i>0;i--){
        b[i]=b[i-1];
       }
       b[0]=A[3];
       for(int i=3;i>0;i--){
        A[i]=A[i-1];
       }

       count--;
       if(count ==0){
        for(int i=0; i<4; i++){
        printf("%d",A[i]);
        }
        for(int i=0; i<4; i++){
        printf("%d",b[i]);
        }
       return 0;
       }
       else{
        return mul(count,a,b,A,q);
       }
    }
    else{
        sub(A,a);
  q=b[3];
       for(int i=3;i>0;i--){
        b[i]=b[i-1];
       }
       b[0]=A[3];
       for(int i=3;i>0;i--){
        A[i]=A[i-1];
       }
       count--;
       if(count ==0){
        for(int i=0; i<4; i++){
        printf("%d",A[i]);
        }
        for(int i=0; i<4; i++){
        printf("%d",b[i]);
        }
       return 0;
       }
       else{
        return mul(count,a,b,A,q);
       }
    }
}

void sub(int A[], int a[]){
    int k[4];
    for(int i=0; i<4; i++){
        k[i]=a[i];
    }
   for(int i=0; i<4; i++){
    if(k[i]==0){
        k[i]=1;
    }
    else{
        k[i]=0;
    }
   }
   int carry=1;
    for(int i=3; i>=0; i--){
         if(k[i]==0){
            if(carry==1){
            k[i]=1;
            carry=0;
            }
            else{
                continue;
            }
         }
         else {
            if(carry==1){
                  k[i]=0;
                  carry =1;
            }
            else{
                continue;
            }
         }
   }
   add(A,k);  
}

void add(int A[],int a[]){
    int carry =0;
    for(int i=3;i>=0; i--){
        if(A[i]==1){
            if(a[i]==0){
                if(carry==0){
                A[i]=1;
                }
                else{
                    A[i]=0;
                    carry=1;
                }
            }
            else{
                if(carry==0){
                    A[i]=0;
                    carry=1;
                }
                else{
                    A[i]=1;
                    carry=1;
                }
            }
        }
        else{
            if(a[i]==0){
                if(carry==0){
                A[i]=0;
                carry=0;
                }
                else{
                    A[i]=1;
                    carry=0;
                }
            }
            else{
                if(carry==0){
                A[i]=1;
                carry=0;
                }
                else{
                    A[i]=0;
                    carry =1;
                }
            }
        }
    }
    
}