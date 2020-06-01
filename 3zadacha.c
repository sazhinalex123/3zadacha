#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int stroki_stolbci (const char* filename){
int  i=0;
int** arr;
int* zn;
char c;
int j=0;
int e;
int a=0;
int tmp=-2;
int forR=-1;
int t;
int m,n;
int q;
int h;

FILE*input_file;
FILE*output_file;
output_file=fopen("asd.txt","w");
input_file=fopen(filename,"r");
if(!input_file){
    printf("ne udalos' otkrit'\n");
    exit(0);
}
if(fscanf(input_file,"%d",&e)!=1){
    printf("Pustoi fail\n");
    return 2;
}
rewind(input_file);
e=0;
while(!feof(input_file)){
    c=fgetc(input_file);
    if(c=='\n'){
    ++i;
}
}

arr=(int**)malloc((i+1)*sizeof(int*));
if(arr==NULL){
    free(arr);
}
zn=(int*)malloc((i+1)*sizeof(int));
if(zn==NULL){
    free(zn);
}
rewind(input_file);
i=0;
while(!feof(input_file)){
    fscanf(input_file,"%d",&e);
    c=fgetc(input_file);
    j++;
    if(c=='\n'){
        zn[i]=j;
        arr[i]=(int*)malloc(j*sizeof(int));
        if(arr[i]==NULL){
            for(int w=0;w<=i;w++){
                free(arr[i]);
            }
            return(3);
        }
        printf("zn[i]= %d\n",zn[i]);
    ++i;
    printf("j= %d\n",j);
    j=0;
}
}


rewind(input_file);
for(int m=0;m<i;m++){
    for(int n=0;n<zn[m];n++){
        fscanf(input_file,"%d",&arr[m][n]);
        printf("element[%d][%d] = %d\n",m,n,arr[m][n]);
    }
}

for(m=0;m<i;m++){
        for(n=0;n<zn[m];n++){
            if(n==0){
                q=arr[m][0];
            }
            else{
                if(q<arr[m][n]){
                    q=arr[m][n];
                    if(tmp<n){
                    tmp=n;
                    }
                }
            }
                if(n==zn[m]-1){
                    if(tmp!=-2){
                        break;
                    }
                    if((q==arr[m][0])&&(zn[m]!=0)){
                        tmp=0;
                        break;
                    }
                }
        }
    }
q=0;
for(m=0;m<i;m++){
    if(q==-1){
        break;
    }
    for(n=0;n<zn[m];n++){
        q=0;
        if(zn[m]>tmp){
            if(tmp!=n){
            if(arr[m][tmp]>arr[m][n]){
                q++;
            }
            else{
                q=-1;
                break;
            }
            }
        }
        else{
            q=0;
        }
    }
}
if(q!=-1){
    forR=tmp;
    printf("for remove=%d\n",forR);
    for(m=0;m<i;m++){
        if((forR<zn[m])&&(zn[m]!=1)){
        for(n=forR;n<zn[m];n++){
                arr[m][n]=arr[m][n+1];
        }
        }
    }
    for(m=0;m<i;m++){
        if(forR<zn[m]){
            zn[m]=zn[m]-1;
            printf("zn[%d]=%d\n",m,zn[m]);
                arr[m]=realloc(arr[m],(zn[m])*sizeof(int));
            }
    }
    for(m=0;m<i;m++){
        for(n=0;n<zn[m];n++){
            fprintf(output_file,"%d ",arr[m][n]);
        }
        fprintf(output_file,"\n");
    }
}
if (q==-1){
    for(m=0;m<i;m++){
        for(n=0;n<zn[m];n++){
            fprintf(output_file,"%d ",arr[m][n]);
        }
        fprintf(output_file,"\n");
    }
}
for(m=0;m<i;m++){
    free(arr[m]);
}
free(arr);
free(zn);
fclose(input_file);
fclose(output_file);
return i;
}
void autotest(void){
    int u;
   FILE*input_file;
   FILE*output_file;
   input_file=fopen("zxc.txt","r");
   stroki_stolbci("zxc.txt");
   output_file=fopen("asd.txt","r");
   fscanf(output_file,"%d",&u);
   printf("u=%d\n",u);
   fclose(output_file);
   fclose(input_file);
   if(u==1){
       printf("Autotest passed\n");
   }
   else{
       printf("Autotest failed\n");
   }
}

int main(void){
    autotest();
    stroki_stolbci("zxc.txt");
    return 0;
}


