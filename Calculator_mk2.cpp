#include<iostream>
#include<cstring>
#include<string>

using namespace std;


struct Node{
    double data;
    Node *next;
};

Node* createNode(){
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data = 0;
    newNode->next = NULL;

    return newNode;
}

void insertAtEnd(Node *top, double num){
    if (top == NULL){
        top->data = num;
        top->next = NULL;
    }

    Node *curr = top;

    while (curr->next != NULL){
        curr = curr->next;
    }

    Node *newnode = createNode();

    curr->next = newnode;
    newnode->data = num;
}



void charconverter(Node *top, string equation){
    int charnums = equation.length();
    double multiple, div;
    Node *curr = top;
    int i = 0;


    while (i < charnums){
        multiple = 10; 
        div = 0.1;
        for(i; i < charnums; i++){
            if ((equation[i]=='+') || (equation[i]=='-') || (equation[i]=='x') || (equation[i]=='/') || (equation[i]=='(') || (equation[i]==')') || (equation[i]=='=') || (equation[i]=='.') || (equation[i]==' ')){
                break;
            }
            else{
                curr->data = curr->data*multiple;   
                curr->data += equation[i]-48; 
            }
        }

        if (equation[i] == '.'){
            i++;
            for(i; i < charnums; i++){
                if((equation[i]=='+') || (equation[i]=='-') || (equation[i]=='x') || (equation[i]=='/') || (equation[i]=='(') || (equation[i]==')') || (equation[i]=='=') || (equation[i]==' ')){
                    break;
                }
                else{
                    curr->data += (equation[i]-48)*div;
                    div /= 10;
                }
            }
        }

        if((equation[i]=='+') || (equation[i]=='-') || (equation[i]=='x') || (equation[i]=='/') || (equation[i]=='(') || (equation[i]==')')){
           i++;
           insertAtEnd(top, 0);
           curr = curr->next;
           continue; 
        }

        if(equation[i] == '='){
            break;
        }

        if(equation[i] == ' '){
            i++;
            continue;
        }

    }

}

void calcultaions(Node **top, string equation){
    Node *curr = *top, *prev1 = *top, *prev2 = *top;
    int operatornums = 0, charnums = equation.length(), repeat = 0;
    double num1, num2, ans;
    char key;

    while (curr->next != NULL){
        key = '/';
        for (int i = 0; i < charnums; i++){
            if (equation[i] == key){ 
                repeat++;                                
            }
        }
        if (repeat > 0){
            for (int y = 1; y <= repeat; y++){
                for (int i = 0; i < charnums; i++){
                    if ((equation[i] == '/') || (equation[i] == 'x') || (equation[i] == '+') || (equation[i] == '-')){
                        operatornums++;                    
                    }
                    if(equation[i] != key){
                        continue;
                    }
                    else{
                        for (int j = 1; j <= operatornums; j++){
                            if (j != 1){
                            prev2 = prev1; 
                            }
                            prev1 = curr;
                            curr = curr->next;  
                        }
                
                        num1 = prev1->data;
                        num2 = curr->data;
                        ans = num1/num2;
                        curr->data = ans;
                
                        if (operatornums == 1){
                            free(prev1);
                            *top = curr;
                        }
                        else{
                            prev2->next = curr;
                            free(prev1);
                        }

                        equation[i] = ' ';
                        operatornums = 0;
                        prev1 = *top;
                        prev2 = *top;
                        curr = *top;
                        break;
                    }
                }
            }                            
        } 
        repeat = 0;

        key = 'x';
        for (int i = 0; i < charnums; i++){
            if (equation[i] == key){ 
                repeat++;                                
            }
        }
        if (repeat > 0){
            for (int y = 1; y <= repeat; y++){
                for (int i = 0; i < charnums; i++){
                    if ((equation[i] == '/') || (equation[i] == 'x') || (equation[i] == '+') || (equation[i] == '-')){
                        operatornums++;                    
                    }
                    if(equation[i] != key){
                        continue;
                    }
                    else{
                        for (int j = 1; j <= operatornums; j++){
                            if (j != 1){
                            prev2 = prev1; 
                            }
                            prev1 = curr;
                            curr = curr->next;  
                        }
                
                        num1 = prev1->data;
                        num2 = curr->data;
                        ans = num1*num2;
                        curr->data = ans;
                
                        if (operatornums == 1){
                            free(prev1);
                            *top = curr;
                        }
                        else{
                            prev2->next = curr;
                            free(prev1);
                        }

                        equation[i] = ' ';
                        operatornums = 0;
                        prev1 = *top;
                        prev2 = *top;
                        curr = *top;
                        break;
                    }
                }
            }                            
        } 
        repeat = 0;

        key = '+';
        for (int i = 0; i < charnums; i++){
            if (equation[i] == key){ 
                repeat++;                                
            }
        }
        if (repeat > 0){
            for (int y = 1; y <= repeat; y++){
                for (int i = 0; i < charnums; i++){
                    if ((equation[i] == '/') || (equation[i] == 'x') || (equation[i] == '+') || (equation[i] == '-')){
                        operatornums++;                    
                    }
                    if(equation[i] != key){
                        continue;
                    }
                    else{
                        for (int j = 1; j <= operatornums; j++){
                            if (j != 1){
                            prev2 = prev1; 
                            }
                            prev1 = curr;
                            curr = curr->next;  
                        }
                
                        num1 = prev1->data;
                        num2 = curr->data;
                        ans = num1+num2;
                        curr->data = ans;
                
                        if (operatornums == 1){
                            free(prev1);
                            *top = curr;
                        }
                        else{
                            prev2->next = curr;
                            free(prev1);
                        }

                        equation[i] = ' ';
                        operatornums = 0;
                        prev1 = *top;
                        prev2 = *top;
                        curr = *top;
                        break;
                    }
                }
            }                            
        } 
        repeat = 0;

        key = '-';
        for (int i = 0; i < charnums; i++){
            if (equation[i] == key){ 
                repeat++;                                
            }
        }
        if (repeat > 0){
            for (int y = 1; y <= repeat; y++){
                for (int i = 0; i < charnums; i++){
                    if ((equation[i] == '/') || (equation[i] == 'x') || (equation[i] == '+') || (equation[i] == '-')){
                        operatornums++;                    
                    }
                    if(equation[i] != key){
                        continue;
                    }
                    else{
                        for (int j = 1; j <= operatornums; j++){
                            if (j != 1){
                            prev2 = prev1; 
                            }
                            prev1 = curr;
                            curr = curr->next;  
                        }
                
                        num1 = prev1->data;
                        num2 = curr->data;
                        ans = num1-num2;
                        curr->data = ans;
                
                        if (operatornums == 1){
                            free(prev1);
                            *top = curr;
                        }
                        else{
                            prev2->next = curr;
                            free(prev1);
                        }

                        equation[i] = ' ';
                        operatornums = 0;
                        prev1 = *top;
                        prev2 = *top;
                        curr = *top;
                        break;
                    }
                }
            }                            
        } 
        repeat = 0;
    }     
}


int main(){

    Node *numbers = createNode();

    Node *top = numbers;

    string equation;

    cout << "Enter your equation below: ";
    getline(cin, equation);

    cout << equation << endl;

    charconverter(top, equation);


    Node *curr = top;
    while (curr != NULL){
        cout << curr->data << endl;
        curr = curr->next;
    }

    cout << endl;

    calcultaions(&top, equation);

    cout << "Answer = " << top->data;

    return 0;
}

