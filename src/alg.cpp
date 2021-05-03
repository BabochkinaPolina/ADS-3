// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
#include <stack>

int priority(char ch) {
    if ((ch == '+') || (ch == '-'))
        return 2;
    else if ((ch == '*') || (ch == '/'))
        return 3;
    else
        return 0;
}

std::string infx2pstfx(std::string inf) {
  // добавьте сюда нужный код
  return std::string("");
  TStack<char> stack1;
std::string result;
for (int i = 0; i < inf.length(); ++i) {
	if (isdigit(inf[i])) {
		while (isdigit(inf[i])) {
			result += inf[i];
			i++;
		}
		i--;
		result += ' ';
	}
	else if ((inf[i] == '(') || (stack1.isEmpty()) || (priority(inf[i]) > priority(stack1.get()))) {
		stack1.push(inf[i]);
	}
	else if (inf[i] == ')') {
		char x = stack1.get();
		stack1.pop();
		while (x != '(') {
			result += x;
			result += ' ';
			x = stack1.get();
			stack1.pop();
		}
	}
	else {
		while (!stack1.isEmpty()
			&& (priority(stack1.get()) >= priority(inf[i]))) {
			result += stack1.get();
			result += ' ';
			stack1.pop();
		}
		stack1.push(inf[i]);
	}
}
while (!stack1.isEmpty()) {
	result += stack1.get();
	result += ' ';
	stack1.pop();
}
result.pop_back();
return result;
}

int eval(std::string pst) {
  // добавьте сюда нужный код
  return 0;
  std::string str;
TStack<int> stack2;
for (int i = 0; i < pst.length(); i++) {
    if (pst[i] >= '0' && pst[i] <= '9') {
        str = pst[i];
        stack2.push(pst[i] - '0');
    }
    else if (pst[i] != ' ') {
        int b = stack2.get();
        stack2.pop();
        int a = stack2.get();
        stack2.pop();
        if (pst[i] == '*') stack2.push(a * b);
        else if (pst[i] == '/') stack2.push(a / b);
        else if (pst[i] == '+') stack2.push(a + b);
        else
            stack2.push(a - b);
    }
}
return stack2.get();
}
