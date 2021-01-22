#include<iostream>
#include<string>
using namespace std;
template<class T>
class Node
{
public:
    T data;
    Node<T>* next;
};
template<class T>
class stack
{
    Node<T>* top;
public:
    stack()
    {
        top = NULL;
    }
    void push(T x);
    T pop();
    T peek(int pos);
    int isEmpty();
    T stacktop();
};
template<class T>
void stack<T>::push(T x)
{
    Node<T>* p = new Node<T>;
    if (p == NULL)
        cout << "stack overflow" << endl;
    else
    {
        p->data = x;
        p->next = top;
        top = p;
    }
}
template<class T>
T stack<T>::stacktop()
{
    char x = '&';
    if (top == NULL)
        return x;
    else
        return top->data;
}
template<class T>
int stack<T>::isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
int isparenthesis(string s)           //NOT check for proper parenthsisation check for balance parenthsisation
{
    stack <char>st;
    for (int i = 0; s[i] != '\0'; i++)  //i.e balance parenthesisation
    {
        if (s[i] == '(')
            st.push('(');
        else if (s[i] == ')')
        {
            if (st.isEmpty())
                return 0;
            else
                st.pop();
        }
    }
    return st.isEmpty() ? 1 : 0;
}
template<class T>
T stack<T>::pop()
{
    T x;
    Node<T>* p = top;
    if (top == NULL)
        cout << "stack is empty or stack underflow" << endl;
    else
    {
        top = top->next;
        x = p->data;
        delete p;
    }
    return x;
}
template<class T>
T stack<T>::peek(int pos)
{
    Node<T>* p = top;
    for (int i = 0; i < pos - 1 && p != NULL; i++)
        p = p->next;
    if (p != NULL)
        return p->data;
    else
        cout << "entered invalid position " << endl;
}
int isoperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}
int precdence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return -1;
}
int evaluate(string postfix)
{
    stack <int> st;
    int i,x,y,r;
    for(i=0;postfix[i]!='\0';i++)
    {
      if(isoperand(postfix[i]))
        st.push(postfix[i]-'0');
       else
       {
        x=st.pop();
        y=st.pop();
        switch(postfix[i])
        {
        case '+': r=x+y;
                  st.push(r);
        break;
        case '-': r=y-x;
               st.push(r);
        break;
        case '*': r=x*y;
               st.push(r);
        break;
        case '/': r=y/x;
               st.push(r);
        break;
        }
       }
    }
    return st.pop();
}
string postfix(string infix)
{
    stack <char> st;
    string postfix;
    int i, j;
    i = 0;
    while (infix[i] != '\0')             //the purpose of writing an expreesion in postfix form is that we evluate an expression in a single go for evaluating it we did not need to iterate through it multiple times
    {
        if (isoperand(infix[i]))
            postfix.push_back(infix[i++]);
        else
        {
            if (precdence(infix[i]) > precdence(st.stacktop()))
                st.push(infix[i++]);
            else
            {
                postfix.push_back(st.pop());
            }
        }
    }
    while (!st.isEmpty())
    {
        postfix.push_back(st.pop());
    }
    postfix.push_back('\0');
    return postfix;
}

int main()
{
    stack <int>st;
    st.push(34);
    st.push(456);
    st.push(435534);
    st.push(345657463);
    cout << st.pop() << endl;
    cout << "values at different indices :- " << st.peek(1) << " " << st.peek(2) << " " << st.peek(3) << endl;
    string s = "(a+(b))";
    cout << "checking for balence parenthesisation Not check proper parenthesiasation " << endl;
    cout << isparenthesis(s);
    string l = "a+b*c-d/e";
    string r = postfix(l);
    cout << " postfix expression is : -" << r << endl;
    string m="234*+82/-";
    int res=evaluate(m);
    cout<<"The result of a postfix expression is : -"<<res<<endl;
}