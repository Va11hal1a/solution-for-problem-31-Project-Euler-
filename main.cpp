#include <iostream>
#include <vector>

using namespace std;

int coin_value [] = {1, 2, 5, 10, 20, 50, 100, 200};
int count = 8;

int func2(int pound){
    int** table = new int*[pound];
    for(int i = 0; i <= pound; i++){
        table[i] = new int[count];
        table[i][0] = 1;
    }
    for(int i = 0; i <= pound; i++){
        for(int j = 1; j < count; j++){
            table[i][j] = table[i][j-1];
            if(coin_value[j] <= i){
                    table[i][j] += table[i - coin_value[j]][j];
            }
        }
    }
    for(int i = 0; i <= pound; i++){
        for(int j = 0; j < count; j++){
               cout << i <<" |   "<< table[i][j] << "    |";
        }
        cout << "" << endl;
    }
    return table[pound][count - 1];
}

int main()
{
    cout << func2(200) << endl;
    int a;
    cin >> a;
    return 0;
}
