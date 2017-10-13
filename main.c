#include <stdio.h>
#include <stdlib.h>

#define MAX 12
#define MIN 1

int Factorial(int);
int n_choose_r(int, int);
int getInputInRange(int, int);

int main(void) {
    int size, space, count, control, row = 0;

    size = getInputInRange(MIN, MAX);

    space = size - 1;
    control = 1;
    while(row < size){
        count = 0;
        while(count < space){
            printf("  ");
            count++;
        }
        space--;

        count = 0;
        while(count < control){
            printf("%3d ", n_choose_r(row, count));
            count++;
        }
        control++;
        row++;
        printf("\n");
    }


    return 0;
}

int Factorial(int toFactorial){
    int sum = 1,count = 1;
    while(count <= toFactorial){
        sum *= count;
        count++;
    }
    return sum;
}

int n_choose_r(int n, int r){
    return (Factorial(n))/(Factorial(r)*(Factorial(n-r)));
}
int getInputInRange(int min, int max){
    int userNum;
    printf("Ener a number between %d and %d: ",min,max);
    scanf("%d", &userNum);

    while(!(userNum >= min && userNum <= max)){
        printf("Error, your number must be between %d and %d, try again: ",min,max);
        scanf("%d", &userNum);
    }
    return userNum;
}