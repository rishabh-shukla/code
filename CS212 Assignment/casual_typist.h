class casual_typist:public typist{                      //derived class regular_typist of base class typist
	int daily_wage;
	public:
    casual_typist(){};
	void casual_typist1(string n,string c,int d_w){     //constructor for initializing the attributes of casual typist
		set_name(n);
		set_code(c);
		daily_wage=d_w;

	}
	void display(void);                             //display function for displaying the information related to casual_typist
};
void casual_typist::display(void ){
	cout<<"The name of casual_typist is "<<get_name()<<endl;
	cout<<"The code of casual_typist is "<<get_code()<<endl;
	cout<<"The daily_wage of casual_typist is "<<daily_wage<<endl;
}
