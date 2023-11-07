#include <stdio.h>
#include <string.h>

void OrderSystem() {
    int input;
    int count;
    int pleces[10][20];
    int notAvailableSpaces[10];
    int flag = 0;
    for (int i = 0; i < 10; i++) {
        notAvailableSpaces[i] = 0;
        for (int j = 0; j < 20; j++) {
            pleces[i][j] = 0;
        }

    }
    scanf("%d", &input);
    while (input > 0) {

        for (int i = 0; i < 10; i++) {
            if (20 - notAvailableSpaces[i] >= input) {
                for (int j = notAvailableSpaces[i]; j < notAvailableSpaces[i] + input; j++) {
                    pleces[i][j] = 1;
                    printf("place: row %d column %d\n ", i + 1, j + 1);
                }
                notAvailableSpaces[i] += input;
                flag = 1;
                break;
            }

        }
        if (!flag) { printf("no place for %d \n", input); }
        flag = 0;

        scanf("%d", &input);
    }
}

void snakePrint() {
    int multiplicationTable[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            multiplicationTable[i][j] = (i + 1) * (j + 1);

        }
    }

    int k = 0, l = 0, m = 8, n = 8;
    while (k < m && l < n) {

        for (int i = l; i < n; ++i)

            printf("%d ", multiplicationTable[k][i]);

        k++;


        for (int i = k; i < m; ++i)

            printf("%d ", multiplicationTable[i][n - 1]);
        n--;

        if (k < m) {
            for (int i = n - 1; i >= l; --i)
                printf("%d ", multiplicationTable[m - 1][i]);
            m--;
        }

        if (l < n) {
            for (int i = m - 1; i >= k; --i)
                printf("%d ", multiplicationTable[i][l]);
            l++;
        }
    }
}

int MagicSquare(int mat[3][3]) {
    int sum = 0;
    int privateSumRow = 0;
    int privateSumColumn = 0;
    int privateSumSlantFirst = 0;
    int privateSumSlantSecond = 0;
    for (int i = 0; i < 3; i++) {
        sum += mat[0][i];
    }
    for (int i = 0; i < 3; i++) {
        privateSumRow = privateSumColumn = 0;
        for (int j = 0; j < 3; j++) {
            privateSumRow += mat[i][j];
            privateSumColumn += mat[j][i];
            if (i == j) {
                privateSumSlantFirst += mat[i][j];
            }
            if (i + j == 2) {
                privateSumSlantSecond += mat[i][j];
            }
        }

        if (privateSumRow != sum || privateSumColumn != sum) {

            return 0;
        }

    }
    if (privateSumSlantFirst != sum || privateSumSlantSecond != sum) {
        return 0;
    }
    return 1;

}

void XO() {
    //X = 1,  O = 2
    int mat[3][3];
    int currentPlayer = 1;
    int victory = 0;
    int numSteps = 0;
    int i = 0, j = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat[i][j] = 0;
        }
    }
    while ( victory == 0 && numSteps != 9) {
        printf("enter a place %d\n", currentPlayer);
        scanf("%d %d", &i, &j);
        if (mat[i][j] != 0) {
            printf("this place is not available\n");
        } else {
            mat[i][j] = currentPlayer;
            numSteps++;
            int privateSumRow = 0;
            int privateSumColumn = 0;
            int privateSumSlantFirst = 0;
            int privateSumSlantSecond = 0;
            for (int k = 0; k < 3; k++) {
                privateSumRow = privateSumColumn = 0;
                for (int s = 0; s < 3; s++) {
                    if (mat[k][s] == currentPlayer) {
                        privateSumRow++;
                    }
                    if (mat[s][k] == currentPlayer) {
                        privateSumColumn++;
                    }
                    if (k == s && mat[k][s] == currentPlayer) {
                        privateSumSlantFirst++;
                    }
                    if (k + s == 2 && mat[k][s] == currentPlayer) {
                        privateSumSlantSecond++;
                    }
                }
                if (privateSumRow == 3 || privateSumColumn == 3) {

                    victory = 1;
                    printf(""
                           "The winner is %d ", currentPlayer);
                }
            }
            if (privateSumSlantFirst == 3 || privateSumSlantSecond == 3) {
                victory = 1;
                printf("The winner is %d",currentPlayer);
            }
            if (currentPlayer == 1) {
                currentPlayer = 2;
            } else {
                currentPlayer = 1;
            }

        }

    }
    if(victory == 0){
        printf("game over!");
    }
}
int doubleNumber(int *arr){
    size_t length = sizeof(arr)/sizeof(arr[0]);
    int num = 0;
//    printf("%d",length);
    for (int i = length; i >=0; i--) {
        num*=10;
        num+=arr[i];
    }
    return num*2;

}
#define N (3)
void sumsMat(int arr[N], int sums[N][N]){
    int sum = 0;
    for (int i = 0; i <N ; i++) {
        sum = 0;
        for (int j =i; j < N; j++) {
            sum += arr[j];
            sums[i][j]=sum;
            sums[j][i]=sum;
            printf("%d %d\n", sum, sums[i][j]);
        }
    }
}

int main() {
    printf("Hello, World!\n");
//    CheckPassword();
//    my_strlen("aaa");
//    char a[] = "hello ";
//    char b[] = "world!";
//    printf("%s",strcat1(a, b));
//    OrderSystem();
//snakePrint();
//    int mat[3][3];
//    mat[0][0] = 4;
//    mat[0][1] = 3;
//    mat[0][2] = 8;
//    mat[1][0] = 9;
//    mat[1][1] = 5;
//    mat[1][2] = 1;
//    mat[2][0] = 2;
//    mat[2][1] = 7;
//    mat[2][2] = 6;
//    printf("%d" , MagicSquare( mat));
//XO();
//int arr[3]={1,2,3};
//    printf("%d",doubleNumber(arr));
    int arr[N]={1,2,3};
    int mat[3][3];
    sumsMat(arr,mat);
    return 0;
}

