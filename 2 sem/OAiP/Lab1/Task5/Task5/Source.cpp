#include <iostream>


class Expression
{
public:
	virtual double evaluate() const = 0;
	virtual ~Expression() {};
};

class Number : public Expression
{
public:
	Number(double value) : m_value(value) {};
	 ~Number() {};
	double evaluate() const
	{
		return m_value;
	}
	

private:
	double m_value;
};
class BinaryOperation : public Expression
{
public:
	BinaryOperation(Expression const* left, char op, Expression const* right)
		: m_left(left), m_op(op), m_right(right) {}

	
	double evaluate() const{
		if (m_op == '+') {
			return m_left->evaluate() + m_right->evaluate();
		}
		if (m_op == '-') {
			return m_left->evaluate() - m_right->evaluate();
		}
		if (m_op == '*') {
			return m_left->evaluate() * m_right->evaluate();
		}
		if (m_op == '/') {
			return m_left->evaluate() / m_right->evaluate();
		}
	}
	~BinaryOperation()
	{
		delete m_left;
		delete m_right;
	}


private:
	Expression const* m_left;
	Expression const* m_right;
	char m_op;
};

//Task 6
bool check_equals(Expression const* left, Expression const* right)
{
	return *(size_t**)left == *(size_t**)right;
}
//
int main()
{
	Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
	Expression* expr = new BinaryOperation(new Number(3), '+', sube);
	std::cout << expr->evaluate() << std::endl;
	delete expr;
}