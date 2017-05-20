#include <iostream> //cout
#include <string.h> //strlen

using namespace std;

//����in-place�滻��length��ʾΪstr��������ռ�
char* replaceSpace(char *str, int length){ //in-place copy,length����
    if(str == NULL || length <= 0){
        return NULL;
    }
    int count = 0, oldLen = 0, newLen;
    while(str[oldLen] != '\0'){
        if(str[oldLen] == ' '){
            count++;
        }
        oldLen++;
    }
    newLen = count*2 + oldLen;
    char *dst = str;
    if(newLen >= length){
        dst = (char *)malloc((newLen+1) * sizeof(char));
    }

    dst[newLen] = '\0';
    for(int i = oldLen-1, j = newLen-1; i >= 0; i--,j--){
        if(str[i] == ' '){
            dst[j] = '0';
            dst[j-1] = '2';
            dst[j-2] = '%';
            j -= 2;
        }else{
            dst[j] = str[i];
        }
    }
    cout<<dst<<endl;
    return dst;
}

int main(){
    char src[15] = "we are happy ";
    cout<<src<<' '<<strlen(src)<<endl;
    char *dst = replaceSpace(src, 15); //ֻ�����ַ
    cout<<dst<<endl;
}
