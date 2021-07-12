#include <iostream>
#include<string>
#include<fstream>
using namespace std;

const int maxrow=10;

string employeename[maxrow]={};
string employeeID[maxrow]={};
string employeedep[maxrow]={};
string employeejob[maxrow]={};
string employeesalary[maxrow]={};


void readfile(){

	ifstream ffile;
	ffile.open("IOT.doc");
	while(!ffile.eof()){
		for(int i=0; i<maxrow; ++i){
			ffile>>employeeID[i]>>employeename[i]>>employeedep[i]>>employeejob[i]>>employeesalary[i];
		}
	}
	 cout<< "EMPLOYEERS DATA"<<endl;
     cout<<"|===========================================================================================|"<<endl;

     int counter=0;
     cout<<"No. |       ID       |      Name      |    Departement   |      job        |    salary      "<<endl;
	 cout<<"|___________________________________________________________________________________________|\n";
	for(int i=0; i<maxrow; ++i){
		counter++;
	 cout<<" " <<counter<<"        "<<employeeID[i]<<"        "<<employeename[i]<<"             "<<employeedep[i]<<"                   "<<employeejob[i]<<"         "<<employeesalary[i]<<endl; 
break;
}
}


 void display(){
     cout<< "EMPLOYEERS DATA"<<endl;
     cout<<"|===========================================================================================|"<<endl;

     int counter=0;
     cout<<"No. |       ID       |      Name      |    Departement   |      job        |    salary      "<<endl;
	 cout<<"|___________________________________________________________________________________________|\n";
     for (int i=0; i<maxrow; ++i){
        if (employeeID[i]!="\0"){
            counter++;
            cout<<" " <<counter<<"        "<<employeeID[i]<<"        "<<employeename[i]<<"             "<<employeedep[i]<<"                   "<<employeejob[i]<<"         "<<employeesalary[i]<<endl;
        }
     }
     if(counter==0){
        cout<<"oooooops!!!! their is no employees data"<<endl;
     }
 }
 
 
void Register(){
    char name[50];
    char ID[10];
    char dep[50];
    char job[10];
    char salary[10];

    cin.ignore();
    cout<<"employee ID: ";
    cin.getline(ID, 10);
    cout<<"employee Name: ";
    cin.getline(name, 50);
    cout<<"employee Departement: ";
    cin.getline(dep, 50);
    cout<<"employee job: ";
    cin.getline(job, 50);
    cout<<"emplyee salary: ";
    cin.getline(salary,10);
    for (int i=0; i<maxrow; ++i){
        if (employeeID[i]=="\0"){
            employeeID[i]=ID;
            employeename[i]=name;
            employeedep[i]=dep;
            employeejob[i]=job;
            employeesalary[i]=salary;

            break;
        }
    }

}


void searchregistered(string sid){
	int counter=0;
     cout<< "EMPLOYEERS DATA"<<endl;
     cout<<"|===========================================================================================|"<<endl;

     cout<<"  No. |       ID       |      Name      |    Departement   |      job        |    salary      "<<endl;
	 cout<<"|___________________________________________________________________________________________|\n";
    cout<<"                            current employee datas "<<endl;
    cout<<"|===========================================================================================|"<<endl;
    for(int i=0; i<maxrow; ++i){
            
        if(employeeID[i]==sid){
            counter++;
         cout<<" " <<counter<<"        "<<employeeID[i]<<"        "<<employeename[i]<<"             "<<employeedep[i]<<"                   "<<employeejob[i]<<"         "<<employeesalary[i]<<endl;
        break;
    }
}
if(counter==0){
    cout<<"ooops NO match value "<<endl;
    cout<<"if want to register new employeers press [ 1 ]"<<endl;
}

}


void savefile(){
    ofstream file;
    file.open("IOT.doc");
    for(int i=0; i<maxrow; i++){
        if (employeeID[i]=="\0"){
            break;
        }
        else {
            file<<employeeID[i] + "\n" + employeename[i]+"\n" + employeedep[i]+"\n" + employeejob[i] +"\n" + employeesalary[i]<<endl;
        }
    }
}


int main(){
	string employeeID;
	cout<<endl<<endl;
            cout<<" ============================================================================"<<endl;
            cout<<"||                             menu option                                  ||"<<endl;
            cout<<"||               welcome to employee registration office                    ||"<<endl;
            cout<<" ============================================================================"<<endl;
            cout<<endl<<endl;
    int login;
do{
        cout<<"                          enter [ 1 ] to register "<<endl;
        cout<<"                          enter [ 2 ] to display"<<endl;
        cout<<"                          enter [ 3 ] to display from file"<<endl;
        cout<<"                          enter [ 4] to serarch"<<endl;
        cout<<"                          enter [ 5 ] to save and exit"<<endl;

        cout<<"                         [please log in to option]"<<endl<<endl<<endl;
        cout<<"                                 ";
        cin>>login;
        if (!login>5){
        	cout<<"                  invalid login please retry again!!!!!! "<<endl;
		}

    switch (login){
    case 1: Register();
        break;
        case 2:
		display();
        break;
        case 3:
		 readfile();
        case 4:
            cin.ignore();
            cout<<"search by ID number=>";
            getline(cin, employeeID);
            searchregistered(employeeID);
            break;
        }
        
}while(login !=5);
savefile();
cout<<"exit...........saving to file!"<<endl;
return 0;
}
