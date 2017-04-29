class officer:public staff,public education{                            //derived class officer of base class staff
	string rank;
	public:
    officer(){};
	void officer1(string n,string c,string r,string ss1,string ss2){              //constructor for initializing the various officer attributes
		set_name(n);
		set_code(c);
		rank=r;
		set_gen_q(ss1);
		set_prof_q(ss2);
	}
	void display(void );                                    //display function for displaying the information of officer
};
void officer::display(void ){
	cout<<"The name of officer is "<<get_name()<<endl;
	cout<<"The code of officer is "<<get_code()<<endl;
	cout<<"The rank of officer is "<<rank<<endl;
    cout<<"The general qualification of officer is "<<get_gen_q()<<endl;
	cout<<"The professional qualification of officer is "<<get_prof_q()<<endl;
}
