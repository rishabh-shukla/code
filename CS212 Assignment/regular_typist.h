class regular_typist:public typist{                         //derived class regular_typist of base class typist
	int monthly_salary;
	public:
    regular_typist(){};
	void regular_typist1(string n,string c,int m_s){        //constructor for initializing the attributes of casual typist
		set_name(n);
		set_code(c);
		monthly_salary=m_s;
	}
	void display(void);                 //display function for displaying the information related to regular_typist
};
void regular_typist::display(void ){
	cout<<"The name of regular_typist is "<<get_name()<<endl;
	cout<<"The code of regular_typist is "<<get_code()<<endl;
	cout<<"The monthly salary of regular_typist is "<<monthly_salary<<endl;
}
