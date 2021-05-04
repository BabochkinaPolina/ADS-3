// Copyright 2021 NNTU-CS
#include <string>
#include <stack>

int priority(char x) {
	if ((x == '-') || (x == '+'))
		return 2;
	else if ((x == '/') || (x == '*'))
		return 3;
	else
		return 0;
}

std::string infx2pstfx(std::string inf) {
  // добавьте сюда нужный код
  std::stack<char> stack1;
	std::string str;
	for (int i = 0; i < inf.length(); i++) {
		if ((inf[i] >= '0') && (inf[i] <= '9')) {
			str = str + inf[i];
			str = str + " ";
		} else if ((stack1.empty()) || (inf[i] == '(')
			|| (priority(inf[i] > priority(stack1.top())))) {
			stack1.push(inf[i]);
		} else if (inf[i] == ')') {
			while (stack1.top() != '(') {
				str = str  + stack1.top();
				str = str  + ' ';
				stack1.pop();
			}
			stack1.pop();
		} else {
			while (!stack1.empty() && (priority(stack1.top()) >= priority(inf[i]))) {
				str = str + stack1.top();
				str = str + ' ';
				stack1.pop();
			}
			stack1.push(inf[i]);
		}
	}
	if (!stack1.empty()) {
		while (!stack1.empty()) {
			str = str + stack1.top();
			str = str + ' ';
			stack1.pop();
		}
	}
	str.pop_back();
	return str;
}

int eval(std::string pst) {
  // добавьте сюда нужный код
  std::stack<char> stack2;
	int result, a, b;
	for (int i = 0; i < pst.length(); i++) {
		if ((pst[i] >= '0') && (pst[i] <= '9')) {
			stack2.push(pst[i] - '0');
		} else if (pst[i] != ' ') {
			b = stack2.top();
			stack2.pop();
			a = stack2.top();
			stack2.pop();
			if (pst[i] == '+')
				stack2.push(a + b);
			if (pst[i] == '-')
				stack2.push(a - b);
			if (pst[i] == '*')
				stack2.push(a * b);
			if (pst[i] == '/')
				stack2.push(a / b);
		}
	}
	result = stack2.top();
	return result;
}
