export module ModReach;		// declare module ModReach

struct Data					// declare a type not exported
{
public:
	int m_value;
};

export struct Customer		// declare an exported type
{
public:
	Customer(int i)
		: m_data{i}
	{ }

	Data get_data() const	// yield a type not exported
	{
		return m_data;
	}

private:
	Data m_data;
};