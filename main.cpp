#include <iostream>
#include<mysql.h>
#include<mysqld_error.h>
#include<bits/stdc++.h>
using namespace std;

ostream& operator<<(ostream& os, vector<char>& v)
{
	os<<v;
	return os;
}


//defining the global variables
char HOST[] = "localhost";
char USER[] = "root";
char PASS[] = "arun123";


int main() {
	MYSQL *m;
	char choice;
	vector<string> v1;
    map<string, vector<string> > Map;
    map<string, vector<string> >::iterator itr;
    
    
		//connectivity check
		//we will check whether creation of a object happens or not?
		//ie mysql_init(0) will return a object rather than returning NULL
		if(!(m = mysql_init(0)))
		{
			cout<<"Error : MYSQL OBJECT COULD NOT BE CREATED!!"<<endl;
		}
		else
		{
			if(!(mysql_real_connect(m,HOST,USER,PASS,"USER",3306,NULL,0)))
			{
				cout<<"Error: some database info is wrong or do not exist!!"<<endl;
				cout<<mysql_error(m)<<endl;
			}
			else{
				cout<<"Logged in!! "<<endl;
				std::string n, add, phn, eml, gen, a, query;
				string Name,Age,Address,Phone,Email,Gender;
				/*
		     	char Age[10];
				char Address[80];
				char Phone[40];
				char Email[40];
			    char Gender[6];
			    */
				char* final_query;
				char* intermediate_query;
				
				std::ifstream is;
			    //create a input file stream object
				is.open("fake.txt");
				if(is.is_open())
				{
					//to store all the names to get the particular person details
					vector<string> v1;
					vector<string> v2;
				    while(getline(is,Name))  
				    {
						//const char* Name = n.c_str();
					    getline(is,Age);  /*const char* Age =  a.c_str() ; */ v1.push_back(Age);  // here im using const char* to store because im converting from string to converting to char* 
						//cout<<"age while reading from the file is "<<*Age<<endl; 
						getline(is,Address); /*const char* Address = add.c_str(); */ v1.push_back(Address);
						getline(is,Phone);  /*const char* Phone = phn.c_str();*/  v1.push_back(Phone);
						getline(is,Email);	/*const char* Email = eml.c_str(); */ v1.push_back(Email);
					    getline(is,Gender); /* const char* Gender = gen.c_str();*/  v1.push_back(Gender);
						Map[Name] = v1;
						v2.push_back(Name);
						query = "INSERT INTO user(Name,Age,Address,Phone,Gender,Email) VALUES('%s','%s','%s','%s','%s','%s')";
					    //copy this query string to char* so make a new space for char*
						intermediate_query = new char[query.length()+1];
						strcpy(intermediate_query, query.c_str());
								            
						//now the intermediate query is modified with variables with actual values by access specifiers ( %s ...)
						final_query = new char[strlen(intermediate_query) + Name.length() + Address.length() + Phone.length() + Gender.length() + Email.length() + Age.length()];
						sprintf(final_query,intermediate_query,Name.c_str(),Age.c_str(),Address.c_str(),Phone.c_str(),Gender.c_str(),Email.c_str());
								            
						//next to check for the connection with mysql server like using mysql_ping() that returns 0 if everything is fine and returns positive if something is wrong!
						if(mysql_ping(m))
					    {
							cout<<"Error: Impossible to connect!"<<endl;
							cout<< mysql_error(m)<<endl;
						}
					    if(mysql_query(m, final_query))
					    {
							cout<<"Error:Query not executed"<<endl;
							cout<<mysql_error(m)<<endl;
							rewind(stdin);
							getchar();
						}
						else
					    {
							cout<<"Info successfully added!!"<<endl;
						}
						mysql_store_result(m);
						cout<<"BYEE!!"<<endl;
								            
											
					}
											
				}
			    else
				{
					cout<<"Error opening the file!!"<<endl;
				}
				
				do
				{
				    cout<<"Enter your choice:  1.  See for a match \n   2.Register Yourself  \n\n";
				    cin>>choice;		
				    string query;
				    string Name,Age,Address,Phone,Email,Gender,age_person;
				    /*
                    char Name[30];
					char Age[10];
					char Address[80];
					char Phone[40];
					char Email[40];
					char Gender[6];
					*/
					char* final_query;
	     			char* intermediate_query;
					switch(choice)
		            {
					        
							
							case '1':
								    char g;
								    
								    //We are going to see  and pick up a perfect match for you based on the age and gender of the person...
								    cout<<"-----**********************************************************------"<<endl;
							
									cout<<"Enter the Gender(M/F):  ";
								    cin>>g;
								    //vector<char> v1;
    								//map<char, vector<char> > Map;
								    switch(g)
								    {
								    	case 'M':
								    		vector<string> store_name;
								    		vector<string>::iterator new_itr;
								    		//vector<string>::iterator vec_it = store_name.begin();
								    		//map<char, vector<char> >::iterator itr;
								    		for(itr = Map.begin() ; itr != Map.end(); itr++)
								    		{
								    			//this itr has itr -> first as "name" and itr -> second as "{Name,Age,Address,Phone, Email,Gender}"
								    			const vector<string>& values = itr->second;
								    			for(vector<string>::const_iterator it = values.begin() ; it != values.end(); it++)
								    			{
								    				if(*it == "F")
								    				{
								    					//we are looking a female for male if so store her name in a vector to get her details using "map" later..
								    					store_name.push_back(itr->first); //store the name(itr->first is the key which is the "name" here!!....
								    					
													}
												}
											}
											cout<<"Enter your age: ";
											cin>>age_person;
											cout<<"Perfect matches names are :"<<endl;
											for(new_itr = store_name.begin(); new_itr != store_name.end(); new_itr++)
											{
												cout<<*new_itr<<endl;
											}
											cout<<"*********************************-- Your perfect matches are  --*****************************************";
											
                                            for(new_itr = store_name.begin() ; new_itr != store_name.end(); new_itr++)
											{
												vector<string> original = Map[*new_itr];
												//cout<<original[0]<<endl;
												//cout<<"hello "<<endl;
												
													//cout<<"hiii"<<endl;
												cout<<"Name : "<<*new_itr <<"\t"<<"Age : "<<original[0]<<"\t"<<"Address: "<<original[1]<<"\t"<<"Phone :"<<original[2]<<"\t"<<"Email : "<<original[3]<<endl;
												
											}											
								            break;
							
						            }
						            break;
							
							
							case '2':
								
									//Register the user and store in the database//
								    cout<<"Please enter your Name: "; cin>>Name; cout<<endl;  //const char* Name = n.c_str(); cout<<endl;  // here im not using const char* because directly getting input of character array!  ...
								    cout<<"Please enter your Age: "; cin>>Age;   cout<<endl; //const char* Age = a.c_str(); cout<<endl;
								    cout<<"Please enter your Address: "; cin>>Address; cout<<endl;  //const char* Address = add.c_str(); cout<<endl;
									cout<<"Please enter your Phone number: "; cin>>Phone; cout<<endl;  //const char* Phone = phn.c_str(); cout<<endl;											cout<<"Please enter your Email: "; cin>>Email; cout<<endl; //const char* Email = eml.c_str(); cout<<endl;
									cout<<"Please enter your Gender: "; cin>>Gender; cout<<endl; //const char* Gender = gen.c_str(); cout<<endl;
								    cout<<"Please enter your Email: "; cin>>Email; cout<<endl; //const char* Gender = gen.c_str(); cout<<endl;

												
									//create a query to update in your database
									query = "Insert into user(Name,Age,Address,Phone,Gender,Email) VALUES('%s','%s','%s','%s','%s','%s')";
									intermediate_query = new char[query.length() + 1];
									strcpy(intermediate_query,query.c_str());
												
									final_query = new char[strlen(intermediate_query) + Name.length() + Address.length() + Phone.length() + Gender.length() + Email.length() + Age.length()];
									sprintf(final_query,intermediate_query,Name.c_str(),Age.c_str(),Address.c_str(),Phone.c_str(),Gender.c_str(),Email.c_str());
											    
											    
									//next to check for the connection with mysql server like using mysql_ping() that returns 0 if everything is fine and returns positive if something is wrong!
									if(mysql_ping(m))
									{
										cout<<"Error: Impossible to connect!"<<endl;
										cout<< mysql_error(m)<<endl;
									}
									if(mysql_query(m, final_query))
									{
									    cout<<"Error:Query not executed"<<endl;
										cout<<mysql_error(m)<<endl;
										rewind(stdin);
										getchar();
									}
									else
									{
								     	cout<<"User Successfully registered!!"<<endl;
									}
									mysql_store_result(m);
									cout<<"BYEE!!"<<endl;
											            
									break;
										    
							
					}
			                
		        }while(choice == '1' || choice == '2' || choice == '3');
	        }
	    }

        /*
		//print the values for the keys
		map<string, vector<string> >::iterator itr;
		for(itr = Map.begin(); itr != Map.end(); ++itr)
		{
		    cout<<itr->first<<" ";
		    const vector<string>& value = itr->second;
		    for(vector<string>::const_iterator it = value.begin(); it != value.end(); ++it)
		    {
		    	cout<<*it<<endl;
			}
		}
		*/
		
	
	
	return 0;
}
