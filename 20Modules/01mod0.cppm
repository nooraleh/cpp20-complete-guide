export module Square; // module declaration

int square(int x);

export class Square
{
public:
	Square(int i)
		: m_value{square(i)}
	{ }

	int get_value() const { return m_value; }

private:
	int m_value;
};

export template<typename T>
Square to_square(const T& x)
{
	return Square{ x };
}

int square(int i)
{
	return i * i;
}