#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <string>
#include <fstream>

using namespace std;

struct employee {
	int id;
	int age;
	string name;
	employee(int d = 0,int a = 23,const string&s = ""):id{d},age{a},name{s}{}
	template<class Archive>
	void serialize(Archive&ar, const unsigned int version) {
		ar & id;
		ar & age;
		ar & name;
	}
};

void save(const employee&e) {
	ofstream o("h://mingyue.xml");
	boost::archive::text_oarchive oa(o);
	oa << e;
}
void load(employee&e) {
	std::ifstream in("h://mingyue.xml");
	boost::archive::text_iarchive ia(in);
	ia >> e;
}
int main() {
	employee e{ 10,23,"kebi" };
	save(e);
	employee e2;
	load(e2);
	cout << e2.age << endl;
	cout << e2.id << endl;
	cout << e2.name << endl;
	return 0;
}