#include<iostream>
#include<vector>
using namespace std;

#define MAX 10   // maximum size of stack
class stack{
   private:
       
       vector<char> v;
   
    public:
    
    void push(char c){
        v.push_back(c);
    }
    void pop(){
        v.pop_back();
    }
    char top(){
        return v.back();
    }
    bool isEmpty(){
        return v.empty();
    }
    void display() {
            for (int i = top(); i >= 0; i--) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
      bool isFull() {
        return (top() == MAX - 1);
    }
};

int main() {
    stack s;
    int choice, value;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                if (s.isEmpty())
                    cout << "Stack is Empty." << endl;
                else
                    cout << "Stack is NOT Empty." << endl;
                break;

            case 4:
                if (s.isFull())
                    cout << "Stack is Full." << endl;
                else
                    cout << "Stack is NOT Full." << endl;
                break;

            case 5:
                s.display();
                break;

            case 6:
                s.top();

                break;

            case 7:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    while (choice != 7);

    return 0;
}