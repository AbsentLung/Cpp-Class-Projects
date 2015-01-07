/** CS515 Assignment 4
 * File: evaluation.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 10/09/13
 * Collaboration Declaration:
 *              No partner.  Help from PAC.
 */
#include "stack.h"

bool leftPar(string str){ //Search for a left parenthesis
	if (str[0]=='('||str[0]=='['||str[0]=='{')
		return true;
	return false;
}

int main(){
	string input; //Declare variables
	cout << "Expression: ";
	bool valid;
	string inStr;
	while (getline (cin, input, '\n')) { //Loop until user exits
		stack outputQueue;
		stack opStack;
		valid=true;
		for (int i = 0; input[i]; i++) {
			inStr=input[i];
			if ((int)input[i] >= 48 && (int)input[i] <= 57) { //If token is a number
				while((int)input[i+1] >= 48 && (int)input[i+1] <= 57){
					inStr+=input[i+1];
					i++;
				}
				outputQueue.push(inStr); //Push it to the output queue
			}
			else {
				switch (input[i]) {
					case ' ':
						break;
					case '*': case '/': //If higher precedence
						while (!opStack.empty()&&!leftPar(opStack.top())&&opStack.top()!="+"&&opStack.top()!="-") {
							outputQueue.push(opStack.top());//Push.top() onto output queue
							opStack.pop(); //And off of operator stack
						} // Repeats loop until empty or.top() of OS is lower precendence
						opStack.push(inStr);
						break;
					case '+': case '-': //If lower precedence
						while (!opStack.empty()&&!leftPar(opStack.top())) { //To everything on operator stack
							outputQueue.push(opStack.top());//Push.top() onto output queue
							opStack.pop(); //And off of operator stack
						}
						opStack.push(inStr);
						break;
					case '(': case '[': case '{': //If token is a left parenthesis
						//cout << "1:" << opStack.top() << opStack.empty() << opStack._tos << endl;
						opStack.push(inStr); //Push it onto the operator stack
						break;
					case '}': case ')': case ']':
						while (!opStack.empty()&&!leftPar(opStack.top())) { //While the.top() of the stack isn't a left parenthesis
							outputQueue.push(opStack.top());//Push.top() onto output queue
							opStack.pop(); //And off of operator stack
						}
						if (opStack.empty())//If no parenthesis are found
							valid=false;
						else
							opStack.pop(); //Pop the left parenthesis
						break;
					default: //If character is invalid
						valid = false;
						break;
				}
			}
		}
		while (!opStack.empty()) { //To everything on operator stack
			if (leftPar(opStack.top())) //If there is an extra left parenthesis
				valid=false;
			outputQueue.push(opStack.top());//Push.top() onto output queue
			opStack.pop(); //And off of operator stack
		}
		if(valid) {
			stack solveStack; //Create more variables
			char num[40];
			int a;
			int b;
			for(int i = 0; i<outputQueue._tos; i++) { //This is where the numbers are added
				if ((int)outputQueue._arr[i][0] >= 48 && (int)outputQueue._arr[i][0] <= 57) //If token is a number
					solveStack.push(outputQueue._arr[i]); //Push onto the stack
				else { //Otherwise it is an operator
					b = atof(solveStack.top().c_str()); //Assign integers
					solveStack.pop();
					a = atof(solveStack.top().c_str());
					solveStack.pop();
					if (outputQueue._arr[i]=="+") //Add, subtract, multiply, or divide
						sprintf(num, "%i", a+b);
					else if (outputQueue._arr[i]=="-")
						sprintf(num, "%i", a-b);
					else if (outputQueue._arr[i]=="*")
						sprintf(num, "%i", a*b);
					else
						sprintf(num, "%i", a/b);
					solveStack.push(num); //Push the resulting value onto the stack
				}
			}
			cout << "Answer: " << solveStack.top() << endl; //The answer is the top value
			//outputQueue.print(cout);//Prints what's in the stack before everything is popped
		}
		else
			cout << "Invalid characters.  Try again." << endl;//Any invalid characters and you have to try again.
		cout << "Expression: "; //Prompt the user to give another expression
	}
	cout << endl;
}
