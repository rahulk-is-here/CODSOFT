#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// TASK 4 - To Do List

vector<pair<string,string>> tasks_list;
int len = 0;

void display_tasks(){
	if(len == 0){
		cout<<"\nThe To-Do-List is Empty!"<<endl;
		return;
	}
    cout<<"\n\t\t\tTo-Do-List"<<endl;
    int temp = 1;
	for(int i=0;i<len;i++){
        cout<<"\n\tTask "<<temp<<": "<<tasks_list[i].first<<"\t\tStatus: "<<tasks_list[i].second<<endl;
        temp++;
	}
}
void add_task(){
	printf("Enter Task-%d: ",len+1);
	string task;
	cin>>task;
	pair<string,string> p = {task,"pending..."};
	tasks_list.push_back(p);
	len++;
	printf("Task-%d has been Entered!\n",len);
}
void remove_task(){
    if(len == 0){
        cout<<"\nThe To-Do-List is Empty!"<<endl;
		return;
    }
    display_tasks();
    cout<<"\nWhich task you want to remove?: ";
    int n;
    cin>>n;
    if(cin.fail()){
        cout << "ERROR -- You did not enter an integer"<<endl;
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if(n < 1 or n > len){
        cout<<"Invalid Task Number!"<<endl;
        return;
    }
    tasks_list.erase(tasks_list.begin()+(n-1));
    len--;
    display_tasks();
}
void remove_task(int n){
    tasks_list.erase(tasks_list.begin()+(n-1));
    len--;
    display_tasks();
}
void mark_task_completed(){
    if(len == 0){
        cout<<"\nThe To-Do-List is Empty!"<<endl;
		return;
    }
    display_tasks();
    cout<<"\nEnter the task number you want to mark 'completed': ";
    int n;
    cin>>n;
    if(cin.fail()){
        cout << "ERROR -- You did not enter an integer"<<endl;
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if(n < 1 or n > len){
        cout<<"Invalid Task Number!"<<endl;
        return;
    }
    tasks_list[n-1].second = "COMPLETED!";
    display_tasks();
    printf("\nWant to remove Task %d(1 or 0): ",n);
    int choice;
    cin>>choice;
    if(cin.fail()){
        cout << "ERROR -- You did not enter an integer"<<endl;
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if(choice == 1){
        remove_task(n);
    }else if(choice == 0){
        return;
    }else{
        cout<<"Invalid Input!!"<<endl;
        return;
    }
}
int main() {
	cout<<"\n\t\tWelcome to your personal To-Do-List!"<<endl;
    bool flag = true;
    while(flag){
        cout<<"\n1. Add Task\n"<<"2. Mark Completed\n"<<"3. Remove Task\n"<<"4. Display Tasks\n"<<"5. Exit\n"<<endl;
        cout<<"Enter Choice: ";
        int choice;
        cin>>choice;
        if(cin.fail()){
            cout << "ERROR -- You did not enter an integer"<<endl;
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(choice == 1){
            add_task();
        }else if(choice == 2){
            mark_task_completed();
        }else if(choice == 3){
            remove_task();
        }else if(choice == 4){
            display_tasks();
            cout<<"\nEnter the Menu(enter 1 when ready): ";
            int choice;
            cin>>choice;
            if(cin.fail()){
                cout << "ERROR -- You did not enter an integer"<<endl;
                cin.clear(); 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if(choice >= 1){
                continue;
            }else{
                cout<<"Invalid Input!"<<endl;
                continue;
            }
        }else if(choice == 5){
            cout<<"You sure you want to Exit?(1 or 0): ";
            int choice;
            cin>>choice;
            if(cin.fail()){
                cout << "ERROR -- You did not enter an integer"<<endl;
                cin.clear(); 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if(choice == 1){
                if(len != 0){
                    cout<<"\nDisplaying the tasks before exiting..."<<endl;
                    display_tasks();
                }
                flag = false;
            }else if(choice == 0){
                continue;
            }else{
                cout<<"Invalid Input!!"<<endl;
                continue;
            }
        }else{
            cout<<"Invalid Input!"<<endl;
            continue;
        }
    }
    cout<<"\n\nThank you for using the To-Do-List!!\n"<<endl;
	return 0;
}