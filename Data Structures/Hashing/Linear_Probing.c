#include <stdio.h>

const int n = 10;
int hash[n];

void insert_key(int key){
    int h = key % 10;
    while(1){
        if(hash[h] != 0){
            if(h < n){
                h++;
                h = h % 10;
            }else{
                h = 0;
            }
        }else if(hash[h] == 0){
            hash[h] = key;
            break;
        }
    }
}

void search_key(int key){
    int h = key % 10;
    int index;
    while(1){
        if(hash[h] != key){
            if(h < n){
                h++;
                h = h % 10;
            }else{
                h = 0;
            }
        }else if(hash[h] == key){
            hash[h] = key;
            index = h;
            break;
        }
    }
    printf("Index of %d is %d", key, index);
}

void print(){
    for(int i = 0; i < n; i++){
        printf("%d ", hash[i]);
    }
    printf("\n");
}


int main() {

    print();
    insert_key(89);
    print();
    insert_key(1);
    print();
    search_key(89);

    return 0;
}
