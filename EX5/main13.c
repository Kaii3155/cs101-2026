#include <stdio.h>
int muti(int i, int j){
    if(j == 1){
        printf("%d*%d=%d\n", i, j, i*j);
    }else{
        muti(i, j-1);
        printf("%d*%d=%d\n", i, j, i*j);
    }
}

int main()
{
    muti(1, 9);
    return 0;
}
