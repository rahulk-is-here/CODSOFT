#include<iostream>
#include<random>
using namespace std;

// TASK 1 - Number Guessing Game

int generate_random_number(int min,int max){
    random_device rnd; // seed for the random number engine
    mt19937 generate(rnd()); // seeding mt19937 object with the rnd
    uniform_int_distribution<> random(min,max); // distributer that produces uniformly distributed integers between the range(min to max)
    int random_number = random(generate); // random number generator
    return random_number;
}
int main(){
    cout<<"WELCOME TO GUESS THE NUMBER GAME!"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Enter the range(for e.g. 50 to 100)-->"<<endl;
    int min,max;
    cout<<"Enter the minimum value: ";
    cin>>min;
    cout<<"Enter the maximum value: ";
    cin>>max;
    
    int randomNumber = generate_random_number(min,max);

    printf("Enter your guess(between %d and %d): ",min,max);
    int guess;
    cin>>guess;

    int attempts = 1;

    while(guess != randomNumber){
        if(guess < min || guess > max){
            printf("INVALID INPUT! (Will be counted as an Attempt!) --> PLEASE ENTER A NUMBER BETWEEN %d and %d: ",min,max);
            cin>>guess;
            attempts++;
            continue;
        }
        if(guess > randomNumber){
            printf("TOO HIGH! --> Enter a number lower than your previous guess(previous guess: %d): ",guess);
            attempts++;
            cin>>guess;
        }else if(guess < randomNumber){
            printf("TOO LOW! --> Enter a number higher than your previous guess(previous guess: %d): ",guess);
            attempts++;
            cin>>guess;
        }
    }
    printf("\n-----------------------------------------\nCONGRATS!!! You Guessed the Correct Number in %d Attempt/s!!\n-----------------------------------------", attempts);
    return 0;
}