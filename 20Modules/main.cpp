import <iostream>;
import <print>;
import <concepts>;
//import Square;
//import ModReach;
//import SquareNamespace;
//import mod4;
import ModPerson;
import ModPerson2;

void for_main1()
{
/*	Square sq{ 4 };
	std::println("Square of 4 is: {}", sq.get_value())*/;
}

void for_main2()
{
	////Data d{ 11 }; // COMPILE ERROR, `Data` not visible
	//Customer c{ 42 };
	//auto data = c.get_data(); // fine, `Data` is reachable
	//std::println("{}", data.m_value);

	//// backdoor way of declaring 'Data'
	//decltype(std::declval<Customer>().get_data()) data2{2};
}

void for_main3()
{
	//Square::Square sq{ 4 };
	//std::println("Square of 4 is: {}", sq.get_value());
}

void for_main4()
{
	//Customer c1{ "Kim" };
	//c1.buy("table", 59.90);
	//c1.buy(4, "chair", 9.20);
	//c1.print();
	//std::cout << " Average: " << c1.average_price() << '\n';

}

void for_main5()
{
	//C* obj_ptr; // User knows that `C` exists but doesn't see its internals
	//print(obj); // Can only use the public API
}

void for_main6()
{
	auto p3 = get_person("Tana");
	std::cout << p3 << '\n';
}

void for_main7()
{
	auto p4 = get_person("Tana");
	auto p5 = get_person2("Tana");

	std::println("std::same_as<decltype(p4), decltype(p5)>: {}", std::same_as<decltype(p4), decltype(p5)>);
}

int main()
{
	for_main7();
	return 0;
}