#include<iostream>
using namespace std;
using namespace std;

// TASK 2 - Simple Calculator

class SimpleCalculator{
private:
    double a,b;
public:
    SimpleCalculator(){
        cout<<"SIMPLE CALCULATOR\n-----------------\n"<<endl;
        cout<<"Enter the first number: ";
        while(!(cin >> this->a)){
            cout<<"Error: Please enter a valid first number: ";
            cin.clear();
            cin.ignore(123,'\n');
        }
        cout<<"Enter the second number: ";
        while(!(cin >> this->b)){
            cout<<"Error: Please enter a valid second number: ";
            cin.clear();
            cin.ignore(123,'\n');
        }
        
        cout<<"Choose the operation to perform-->"<<endl;
        cout<<"1. Addition\n2. Subtraction\n3. Multiplication\n4. Division"<<endl;
        cout<<"Enter Choice: ";
        int choice;
        cin>>choice;
        if(choice < 1 || choice > 4){
            cout<<"Invalid Choice!"<<endl;
            exit(0);
        }
        if(choice == 1){ // addition
            double ans = this->a + this->b;
            printf("%lf + %lf = %lf",this->a,this->b,ans);
        }else if(choice == 2){ // subtraction
            double ans = this->a - this->b;
            printf("%lf - %lf = %lf",this->a,this->b,ans);
        }else if(choice == 3){ // multiplication
            double ans = this->a * this->b;
            printf("%lf * %lf = %lf",this->a,this->b,ans);
        }else{ // division
            if(a==0 and b == 0){
                printf("%lf / %lf = Undefined",this->a,this->b);
                cout<<"\n\nThank you for using the Simple Calculator!"<<endl;
                exit(0);
            }
            if(b == 0){
                cout<<"Invalid! Cannot divide by 0."<<endl;
                cout<<"\nThank you for using the Simple Calculator!"<<endl;
                exit(0);
            }
            double ans = this->a / this->b;
            printf("%lf / %lf = %lf",this->a,this->b,ans);
        }
        cout<<"\n\nThank you for using the Simple Calculator!"<<endl;
    }
};
int main(){

    SimpleCalculator sc;

    return 0;
}