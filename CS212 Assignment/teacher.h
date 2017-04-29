class teacher:public staff,public education{                         //derived class teacher of base class staff
string subject;
	string publish;
	public:
    teacher(){};
	void teacher1(string n,string c,string s,string p,string ss1,string ss2){     //constructor for initializing the attributes of teacher
		set_name(n);
		set_code(c);
		subject=s;
		publish=p;
		set_gen_q(ss1);
		set_prof_q(ss2);
	}
	void display(void);                                     //display function for displaying the information related to teacher
};
void teacher::display(void ){
	cout<<"The name of teacher is "<<get_name()<<endl;
	cout<<"The code of teacher is "<<get_code()<<endl;
	cout<<"The subject of teacher is "<<subject<<endl;
	cout<<"The publish of teacher is "<<publish<<endl;
	cout<<"The general qualification of teacher is "<<get_gen_q()<<endl;
	cout<<"The professional qualification of teacher is "<<get_prof_q()<<endl;
}
