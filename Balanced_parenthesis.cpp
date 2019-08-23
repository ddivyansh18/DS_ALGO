#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string str)
{
    stack<char> s;
    char c;
    int l = str.length();

    for(int i = 0; i < l; i++)
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            s.push(str[i]);
            continue;
        }

        if(s.empty())
            return false;

        switch(str[i])
        {
        case ')' :
            c = s.top();
            s.pop();

            if(c == '{' || c == '[')
                return false;
            break;

        case '}' :
            c = s.top();
            s.pop();
            if(c == '(' || c == '[')
                return false;
            break;

        case ']' :
            c = s.top();
            s.pop();
            if(c == '(' || c == '{')
                return false;
            break;
        }
    }

    return s.empty();
}

int main()
{
    string str = "{()}[]";

    if(isBalanced(str))
        cout<<"Given expression is balanced.";
    else
        cout<<"Given expression is not balanced.";

    return 0;
}
