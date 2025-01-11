export module MyMod2;

export class C;
export void print(const C& c);

module :private; // private module fragment begins here

import <print>;

class C
{
public:
	void print() const { std::print("C({})", m_value); };

private:
	int m_value;
};

void print(const C& c)
{
	c.print();
}