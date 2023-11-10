#include "Infix_To_Postfix.h"
#include <sstream>
#include <cctype>
#include <iostream>
#include <stdexcept>

using namespace std;

const string Infix_To_Postfix::OPERATORS = "+-*/%(){}[]";
const int Infix_To_Postfix::PRECEDENCE[] = { 1, 1, 2, 2, 2, -1, -1, -1, -1, -1, -1 };

/** Extracts and processes each token in infix and returns the
equivalent postfix string.
@param expression The infix expression
@return The equivalent postfix expression
*/
string Infix_To_Postfix::convert(const string& expression) {
	if (!isBalanced(expression)) throw invalid_argument("Expression is not balanced");
	postfix = "";
	while (!operator_stack.empty())
		operator_stack.pop();
	istringstream infix_tokens(expression);
	string next_token;
	while (infix_tokens >> next_token) {
		if (isalnum(next_token[0])) {
			postfix += next_token;
			postfix += " ";
		}
		else if (is_operator(next_token[0])) {
			process_operator(next_token[0]);
		}
		else {
			throw invalid_argument("Unexpected Character Encountered");
		}
	} 
	// Pop any remaining operators and append them to postfix
	while (!operator_stack.empty()) {
		char op = operator_stack.top();
		operator_stack.pop();
		postfix += op;
		postfix += " ";
	}
	return postfix;
}

/** Function to process operators.
@param op The operator
*/
void Infix_To_Postfix::process_operator(char op) {
	if (operator_stack.empty() || (op == '(') || (op == '{') || (op == '[')) {
		if ((op == ')') || (op == '}') || (op == ']')) {
			throw invalid_argument("Unmatched close parenthesis");
		}
		operator_stack.push(op);
	}
	else {
		if (precedence(op) > precedence(operator_stack.top())) {
			operator_stack.push(op);
		}
		else {
			// Pop all stacked operators with equal
			// or higher precedence than op.
			while (!operator_stack.empty()
				&& (operator_stack.top() != '(')
				&& (operator_stack.top() != '{')
				&& (operator_stack.top() != '[')
				&& (precedence(op) <= precedence(operator_stack.top()))) {
				postfix += operator_stack.top();
				postfix += " ";
				operator_stack.pop();
			}
			// assert: Operator stack is empty or
			// top of stack is open parenthesis (any type) or current
			// operator precedence > top of stack operator
			// precedence;
			if (op == ')' || op == '}' || op == ']') {
				if (!operator_stack.empty()
					&& (operator_stack.top() == '('
						|| operator_stack.top() == '{' 
						|| operator_stack.top() == '[')) {
					operator_stack.pop();
				}
				else {
					throw invalid_argument("Unmatched close parentheses");
				}
			}
			else {
				operator_stack.push(op);
			}
		}
	}
}

bool Infix_To_Postfix::isBalanced(const string& expression) {
	stack<char> strStack;
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
			strStack.push(expression[i]);
		}
		else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
			if (expression[i] == findClosingParenthesis(strStack.top())) {
				strStack.pop();
			}
			else {
				return false;
			}
		}
	}
	return strStack.empty();
}

char Infix_To_Postfix::findClosingParenthesis(char c) {
	if (c == '(') return ')';
	if (c == '[') return ']';
	if (c == '{') return '}';
	return 'f';
}