#include<string>
class staff{                    //base class staff
	string name;                //attributes of staff class
	string code;
	public:
	staff(){};
	void set_name(string);         //set function for setting the private variable name of staff  class
	void set_code(string);          //set function for setting the private variable code of staff  class
	string get_name(void);          //get function for setting the private variable name of staff  class
	string get_code(void);          //get function for setting the private variable code of staff  class
};
void staff::set_name(string n){        //definition of set_name function
	name=n;
}
string staff::get_name(void){          //definition of get_name function
	return name;
}
string staff::get_code(void){           //definition of get_code function
	return code;
}
void staff::set_code(string c){     //definition of set_code function
	code=c;
}
