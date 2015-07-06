//author:- Siddharth Gupta
// email:- siddharthgupta234@gmail.com
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define rep(i,n) for(int i=0;i<(lli)(n);i++)
#define rep1(i,n) for(int i=1;i<=(lli)(n);i++)
#define repa(i,a,b) for(int i=a;i<(lli)(b);i++)
#define repa1(i,a,b) for(int i=a;i<=(lli)(b);i++)
#define pb push_back
#define fs first
#define sc second
//freopen("input_file_name.in""","r""","stdin);
//freopen("output_file_name.out""","w""","stdout);

string answer(int);
string question(string);
string compare(string,string,char);
bool isin(string, char);
vector<string> movielist;

int main(){
	srand (time(NULL));
	ifstream infile("movielist.txt");
	string line;

	while (getline(infile, line)){
    	istringstream iss(line);
    	string line;

		while (getline(infile, line)){
   			movielist.pb(line);
		}
	}

	cout<<"-------------The HOLLYWOOD Game-------------"<<endl;
	cout<<"Rules of the Game"<<endl;
	cout<<"The objective of the game is to guess the name of the HOLLYWOOD movie."<<endl;
	cout<<"Only the placement of the vowels in the movie name would be given to you."<<endl;
	cout<<"For example for the movie the breakfast club you would be given --e  --ea--a-- / --u-" <<endl;
	cout<<"With every correct guess, the revelation of the letters will take place."<<endl;
    cout<<"Buckle Up"<<endl;
    cout<<"Press 'y' to start the game"<<endl;
    char y;
    cin>>y;
    cin.clear();
    lli chances=10;
    lli level=1;

    if(y=='y'){
		while(1){
	        cout<<"You are on Level "<<level<<endl;
	        cout<<"Chances Remaining "<<chances<<endl;
			string questionstring, answerstring;
			answerstring=answer(rand()&1205);
			questionstring=question(answerstring);
			cout<<"Guess This Movie "<<questionstring<<endl;
	        set <char> a;
	        char vowels[]={'a','e','i','o','u'};
	        char k;
	        rep(i,5)
	            a.insert(vowels[i]);

	        while(chances){
	        	char temp;
				cin>>temp;

				if(a.find(temp)!= a.end())
					cout<<"letter "<<temp<<" has already been used"<<endl;

				else if(isin(answerstring,temp)){
					questionstring=compare(questionstring,answerstring,temp);
					a.insert(temp);
				}

				else if(temp<97 || temp>122){
                    cout<<"only enter small case letters"<<endl;
				}

				else{
					chances--;
					cout<<"letter "<<temp<<" is not"<<" present in the moviename"<<endl;
					cout<<"Chances Remaining "<<chances<<endl;
					a.insert(temp);
				}

				if(questionstring==answerstring){
					cout<<questionstring<<endl;
					cout<<"Congratulations you have got the correct answer"<<endl;
					level++;
					break;
				}

				cout<<questionstring<<endl;
		    }

		    if(chances==0){
		    	cout<<"Sorry you have lost the game"<<endl;
		    	cout<<"The Correct answer is "<<answerstring<<endl;
                cout<<"To play again press 'y'"<<endl;
                cout<<"To leave the game, accepting the defeat press 'q'"<<endl;
                cin>>k;
                //cin.clear();

                do{
                	if(k=='y'){
                    	chances=10;
                    	level=1;
                	}

                	else if(k=='q')
                		break;

                	else{
                		cout<<"Kindly press either 'y' or 'q' only."<<endl;
                	}

                }while(k!='q' && k!='y');
		    }
		}
    }

	return 0;
}

string answer(int num){
	string questionstring=movielist[num];
	return questionstring;
}

string question(string answerstring){
	rep(i,answerstring.length()){
		if(answerstring[i]==32)
            answerstring[i]=' ';

		else if (!(answerstring[i]=='a' || answerstring[i]=='e' || answerstring[i]=='i' ||
			answerstring[i]=='o' || answerstring[i]=='u'))
			answerstring[i]='-';

	}
	return answerstring;
}

string compare(string questionstring, string answerstring,char x){
    rep(i,answerstring.length()){
        if(answerstring[i]==x){
            questionstring[i]=x;
        }
    }
    return questionstring;
}

bool isin(string answerstring, char a){
	//cout<<answerstring<<endl;
	rep(i,answerstring.length()){
		if(answerstring[i]==a)
			return true;
	}
	return false;
}
