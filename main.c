#include <stdio.h>

int main(void) {
  FILE* fptr;
  fptr=fopen("data.txt","r");
  if(fptr==NULL){
    printf("File bad, plz fix");
  }
  else{ //We were able to open the File
  char s[10];
  fscanf(fptr,"%s",s);
  printf("%s\n",s);
  while(!feof(fptr)){
    //feof checks for end of file
    fscanf(fptr,"%s",s);
    printf("%s\n",s);
  }
  }
  fclose(fptr);
  program();
  //as text
  FILE* fptr5=fopen("textdata.txt","w");
  fprintf(fptr5,"%s","-12345");
  fclose(fptr5);
  //as binary
  FILE* fptr6=fopen("binarydata.test","wb");
  //extension doesn't matter here, it's just binary
  int arr[3]={100,200,300};
  int num=-12345;
  fwrite(&num,sizeof(int),1,fptr6);
  fwrite(&arr,sizeof(int),3,fptr6);
  fclose(fptr6);

  FILE* fptr7=fopen("binarydata.test","rb");
  if(fptr7==NULL){
    printf("asdkfjlasdkjflaksdjfl");
    return 0;
  }
  int number;
  fread(&number,sizeof(int),1,fptr7);
  printf("%d\n",number);
  fread(&number,sizeof(int),1,fptr7);
  printf("%d\n",number);
  fread(&number,sizeof(int),1,fptr7);
  printf("%d\n",number);
  printf("%ld\n",ftell(fptr7)); //which byte are you at?
  fseek(fptr7,-8,SEEK_CUR);
  fread(&arr,sizeof(int)*3,3,fptr7);
  printf("%d\n",*arr);
  fclose(fptr7);
  FILE* fptr8=fopen("binarydata.test","rb");
  fclose(fptr8);
  structure();
  read();
  return 0;
