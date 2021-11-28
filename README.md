


## ^_!"^!*^_!
```c
#include "stdio.h"
#define r(v) return v
#define f(l,v,expr) for(int i=l;i<v;i++){expr}
int contains(int *tab,int ts,int n){f(1,ts+1,if(tab[i] == n){r(1);})r(0);}void empt(char *ln){f(0,65,ln[i]=' ';)}void replace_char2(char *ln, int *arr, char ch){ln[64]='\0';if(!arr)r();f(0,64,if(contains(arr, arr[0],i))ln[i]=ch;)}
int main(){char lns[6][65];int l1l[]={26,6,7,20,21,23,24,25,26,27,28,31,32,33,34,35,38,48,49,54,55,56,57,58,59,60,61};int l2f[]={14,5,7,19,21,22,29,30,36,37,39,47,49,53,61}; int l2l[]={13,24,25,32,33,34,35,48,55,56,57,58,59,60};int l3f[]={14,4,6,18,20,21,23,26,28,29,31,36,38,52,54};int l3l[]={9,11,16,32,46,47,56,57,58,59};int l4f[]={19,3,5,15,17,19,20,22,25,27,28,32,35,37,45,47,51,53,55,59};int l4l[]={5,11,30,31,56,57};int l4b[]={1,6};int l4p[]={2,10,12};int l5f[]={20,2,4,7,14,16,18,19,21,24,26,27,29,34,36,44,46,50,52,56,58};int l5l[]={16,11,22,23,30,31,32,37,38,39,41,42,47,48,53,54,55};int l5b[]={2,5,7};int l6f[]={18,1,3,13,17,18,25,26,32,33,39,40,42,43,45,46,48,49,57};int l6l[]={32,2,7,11,14,15,16,19,20,21,22,23,24,27,28,29,30,31,34,35,36,37,38,41,44,47,50,51,52,53,54,55,56};int l6b[]={2,6,8};int l6p[]={2,10,12};int *line1[4]={NULL,l1l,NULL,NULL};int *line2[4]={l2f,l2l,NULL,NULL};int *line3[4]={l3f,l3l,NULL,NULL};int *line4[4]={l4f,l4l,l4b,l4p};int *line5[4]={l5f,l5l,l5b,NULL};int *line6[4]={l6f,l6l,l6b,l6p};int **lines_arr[6]={line1,line2,line3,line4,line5,line6};char c[4] = "/_\\|";f(0,6,empt(lns[i]);for(int j=0;j<4;j++){replace_char2(lns[i],lines_arr[i][j],c[j]);})f(0,6,printf("%s\n",lns[i]);)r(0);}
```



