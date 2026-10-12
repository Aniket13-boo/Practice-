#include<iostream>
using namespace std;

class emp{
	
	private:
	int a,b;
	char C;
	
	public:
		int e,f;
		void setV(int a1,int b1,char c1);
		void disV();
};

void emp :: setV(int a1,int b1,char c1){
	a=a1;
	b=b1;
	C=c1;
}
void emp :: disV(){ cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
            cout<<"The value of c is "<<C<<endl;
            cout<<"The value of f is "<<f<<endl;
            cout<<"The value of e is "<<e<<endl;
}


class binary
{
private:
    string s;
    void chk_bin(void);

public:
    void read(void);
    void ones_compliment(void);
    void display(void);
};

void binary::read(void)
{
    cout << "Enter a binary number" << endl;
    cin >> s;
}

void binary::chk_bin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect binary format" << endl;
            exit(0);
        }
    }
}

void binary::ones_compliment(void)
{
    chk_bin();
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
       else
        {
            s.at(i) = '0';
        }
    }
}

void binary::display(void)
{
    cout<<"Displaying your binary number"<<endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout<<endl;
}

int main()
{
	 emp harry;
    // harry.a = 134; -->This will throw error as a is private
    harry.f = 34;
    harry.e = 89;
    harry.setV(1,2,'S');
    harry.disV();
    
    binary b;
    b.read();
    // b.chk_bin();
    b.display();
    b.ones_compliment();
    b.display();
    
    return 0;
}
