export module SquareNamespace;

// specify everything you want to export in a namespace declared with 'export'
int square(int i);

export namespace Square
{
	export class Square
	{
	public:
		Square(int i)
			: m_value{ square(i) }
		{
		}

		int get_value() const { return m_value; }

	private:
		int m_value;
	};

	export template<typename T>
		Square to_square(const T& x)
	{
		return Square{ x };
	}
}


int square(int i)
{
	return i * i;
}