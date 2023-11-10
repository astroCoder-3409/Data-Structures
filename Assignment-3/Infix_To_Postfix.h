#pragma once
#include <string>
#include <stack>

using namespace std;

/** Class to convert infix expressions to postfix expressions. */
class Infix_To_Postfix {
public:
	/** Extracts and processes each token in infix and returns the
	equivalent postfix string.
	@param expression The infix expression
	@return The equivalent postfix expression
	*/
	string convert(const string& expression);
private:
	/** Function to process operators.
	@param op The operator
	*/
	void process_operator(char op);
	
	/** Determines whether a character is an operator.
	@param ch The character to be tested
	@return true if the character is an operator
	*/
	bool is_operator(char ch) const {
		return OPERATORS.find(ch) != string::npos;
	}
	/** Determines the precedence of an operator.
	@param op The operator
	@return The precedence
	*/
	int precedence(char op) const {
		return PRECEDENCE[OPERATORS.find(op)];
	}

	char findClosingParenthesis(char c);
	bool isBalanced(const string& expression);
	// Data fields
	stack<char> operator_stack;
	string postfix;
	static const string OPERATORS;
	static const int PRECEDENCE[];
};