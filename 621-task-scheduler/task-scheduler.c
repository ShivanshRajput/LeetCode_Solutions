int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26]={0};
    for(int i=0;i<tasksSize;i++){
        freq[tasks[i]-'A']++;
    }
    qsort(freq , 26 , sizeof(int) , cmpfunc);
    int chunk = freq[25] - 1;
    int idel = chunk * n;
    for(int i=24;i>=0;i--){
        idel -= fmin(chunk , freq[i]);
    } 
    if(idel < 0){
        return tasksSize;
    }
    return tasksSize + idel;
}