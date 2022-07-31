/* Computer Science Investigatory Project: Medical reports */
#include<fstream.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<graphics.h>
#include<iomanip.h>
#include<process.h>

fstream k,g;
int checkID;
char in;

class patient
{
char name[20];
int age;
char gender[2]; //Enter M or F.
char DOB[11]; //Enter as DD/MM/YYYY.
int patientID;
char status[10]; //Enter routine or whatever specifications.
char orderingdr[30];
public:
char* retname() { return name; }
char* retgender() { return gender;}
int retage() { return age; }
int retpatID() { return patientID; }
void input();
void display();
void calculate();
}p,p1;

class test: public patient
{
int patientID;
float height, weight; //height in cms.
double bmi;
public:
int retpatID() { return patientID; }
int specno;
char colndate[10]; //String. Enter as DD MM YYYY.
float RBC;
int heartrate;
int sbp, dbp;
int sodlevel, potlevel;
long int plateletcount;
int LDL, HDL;
int bsl; //Enter bsl on fasting.
double calbmi() { bmi=weight/(pow((height/100),2));
		  return bmi; }
void inputt();
void displayt();
void analysis();
void file();
}t;

void patient::input()
{
cout<<"Enter patient details:"<<endl;
cout<<setw(11)<<"Name: "; gets(name);
cout<<setw(11)<<"Age: "; cin>>age;
cout<<setw(11)<<"Gender: "; cin>>gender;
cout<<setw(11)<<"DOB: "; gets(DOB);
cout<<setw(11)<<"Patient ID: "; cin>>patientID;
cout<<setw(11)<<"Status: "; gets(status);
cout<<setw(11)<<"Doctor: "; gets(orderingdr);
}

void patient::display()
{
clrscr();
cout<<setw(11)<<"Name: "; puts(name);
cout<<setw(11)<<"Age: "; cout<<age<<endl;
cout<<setw(11)<<"Gender: "; cout<<gender<<endl;
cout<<setw(11)<<"DOB: "; puts(DOB);
cout<<setw(11)<<"Patient ID: "; cout<<patientID<<endl;
cout<<setw(11)<<"Status: "; puts(status);
cout<<setw(11)<<"Doctor: "; puts(orderingdr);
}

void test::inputt()
{
cout<<"Comprehensive test details:"<<endl<<endl;
cout<<"Patient ID: "; cin>>patientID;
cout<<"Specimen no.: "; cin>>specno;
cout<<"Height (in cm): "; cin>>height;
cout<<"Weight (in kg): "; cin>>weight;
cout<<"Heart rate: "; cin>>heartrate;
cout<<"Sys. blood pressure: "; cin>>sbp;
cout<<"Dia. blood pressure: "; cin>>dbp;
cout<<"Sodium level: "; cin>>sodlevel;
cout<<"Potassium level: "; cin>>potlevel;
cout<<"Platelet count: "; cin>>plateletcount;
cout<<"LDL: "; cin>>LDL;
cout<<"HDL: "; cin>>HDL;
cout<<"RBC: "; cin>>RBC;
cout<<"Blood Sugar Level: "; cin>>bsl;
cout<<"Collection date: "; gets(colndate);
}

void test::displayt()
{
clrscr();
cout<<"Comprehensive test details:"<<endl<<endl;
cout<<"Specimen no.: "<<specno<<endl;
cout<<"Height (in cm): "<<height<<endl;
cout<<"Weight (in kg): "<<weight<<endl;
cout<<"Heart rate: "<<heartrate<<endl;
cout<<"Sys. blood pressure: "<<sbp<<endl;
cout<<"Dia. blood pressure: "<<dbp<<endl;
cout<<"Sodium level: "<<sodlevel<<endl;
cout<<"Potassium level: "<<potlevel<<endl;
cout<<"Platelet count: "<<plateletcount<<endl;
cout<<"LDL: "<<LDL<<endl;
cout<<"HDL: "<<HDL<<endl;
cout<<"RBC: "<<RBC<<endl;
cout<<"Blood Sugar Level: "<<bsl<<endl;
cout<<"Collection date: "; puts(colndate);
}

int chage; char chagen[2];
void test::analysis()
{
clrscr();
//BMI analysis
if (chage>18)
 {
 if (calbmi()<18.5)
  {
   cout<<"BMI: "<<calbmi()<<endl;
   cout<<"Underweight"<<endl;
  }
 else if (calbmi()>=18.5 && calbmi()<=24.9)
 {
   cout<<"BMI: "<<calbmi()<<endl;
   cout<<"Healthy weight"<<endl;
 }
 else if (calbmi()>=25 && calbmi()<30)
 {
  cout<<"BMI: "<<calbmi()<<endl;
  cout<<"Overweight"<<endl;
 }
 else
 {
   cout<<"BMI: "<<calbmi()<<endl;
   cout<<"Obese"<<endl;
 }
 }
else
 cout<< "BMI cannot be calculated."<<endl;
 getch(); clrscr();
//Heartrate analysis
if (chage>=1 && chage<=4)
 {
 if (heartrate>=80 && heartrate<=125)
 {
  cout<<"Heart Rate: "<<heartrate<<endl;
  cout<<"Normal"<<endl;
 }
 else
 {
  cout<<"Heart Rate: "<<heartrate<<endl;
  cout<<"Abnormal. Please consult Dr.Sam, Senior Cardiologist at KG Hospitals. For appointments, call 8754431590"<<endl;
 }
 }
else if (chage>=5 && chage<=6)
 {
 if (heartrate>=75 && heartrate <=115)
 {
  cout<<"Heart Rate: "<<heartrate<<endl;
  cout<<"Normal"<<endl;
 }
 else
 {
  cout<<"Heart Rate: "<<heartrate<<endl;
  cout<<"Abnormal. Please consult Dr.Sam, Senior Cardiologist at KG Hospitals. For appointments, call 8754431590"<<endl;
  }
 }
else if (chage>=7 && chage<=9)
 {
 if (heartrate>=70 && heartrate <=110)
 {
  cout<<"Heart Rate: "<<heartrate<<endl;
  cout<<"Normal"<<endl;
 }
 else
 {
 cout<<"Heart Rate: "<<heartrate<<endl;
 cout<<"Abnormal. Please consult Dr.Sam, Senior Cardiologist at KG Hospitals. For appointments, call 8754431590"<<endl;
 }
 }
else if (chage>=10)
 {
 if (heartrate>=60 && heartrate<=100)
 {
  cout<<"Heart Rate: "<<heartrate<<endl;
  cout<<"Normal"<<endl;
 }
 else
 {
  cout<<"Heart Rate: "<<heartrate<<endl;
  cout<<"Abnormal. Please consult Dr.Sam, Senior Cardiologist at KG Hospitals. For appointments, call 8754431590"<<endl;
 }
 }
cout<<endl<<"Abnormal heart rates- also called Arrhythmia- could mean your heart is beating too fast, too slow, or with an irregular pattern. ";
getch(); clrscr();
//RBC count
if (chage<18)
 {
 if (RBC>=4 && RBC<=5.5)
  {
  cout<<"RBC: "<<RBC<<endl;
  cout<<"Normal"<<endl;
  }
 else
  {
  cout<<"RBC: "<<RBC<<endl;
  cout<<"Abnormal"<<endl<<"Normal levels lie between 4 and 5.5. Please meet Dr. Tarly, General Physician at KG Hospitals.";
  cout<<" For appointments, call 04424465154."<<endl;
  }
 }

else if (strcmpi(chagen,"M")==0)
 {
 if (RBC>=4.7 && RBC<=6.1)
 {
 cout<<"RBC: "<<RBC<<endl;
 cout<<"Normal"<< endl;
 }
 else
 {
 cout<<"RBC: "<<RBC<<endl;
 cout<<"Abnormal Levels. Normal levels lie between 4.7 and 6.1. Please meet Dr. Tarly, General Physician at KG Hospitals.";
 cout<<"We strongly recommend you to consult a doctor as soon as possible. ";
 cout<<endl<<"If your RBC count is lower than the normal levels, you could be anaemic. Anaemia is a condition where there is a ";
 cout<<"deficiency of RBC or haemoglobin in the blood, resulting in pallor and weariness"<<endl;
 cout<<endl<<"If your RBC count is higher than the normal levels, you might be diagnosed with erythrocytosis, which can make your blood ";
 cout<<"thicker than normal and lead to blood clots and other complications."<<endl;
 cout<<" For appointments, call 04424465154."<<endl;
 }
 }
else if (strcmpi (chagen,"F")==0)
 {
 if (RBC>=4.2 && RBC<=5.4)
 {
 cout<<"RBC: "<<RBC<<endl;
 cout<<"Normal"<<endl;
 }
 else
 {
 cout<<"RBC: "<<RBC<<endl;
 cout<<"Abnormal Levels. Normal levels lie between 4.2 and 5.4. Please meet Dr. Tarly, General Physician at KG Hospitals.";
 cout<<"We strongly recommend you to consult the doctor as soon as possible. ";
 cout<<endl<<"If your RBC count is lower than the normal levels, you could be anaemic. Anaemia is a condition where there is a ";
 cout<<"deficiency of RBC or haemoglobin in the blood, resulting in pallor and weariness"<<endl;
 cout<<endl<<"If your RBC count is higher than the normal levels, you might be diagnosed with erythrocytosis, which can make your blood ";
 cout<<"thicker than normal and lead to blood clots and other complications."<<endl;
 cout<<endl<<"For appointments, call 04424465154."<<endl;
 }
}
getch(); clrscr();
//Blood pressure check
if (sbp<120 && dbp<80)
{
 cout<<"Systolic Blood Pressure: "<<sbp<<'\t'<<"Diastolic Blood Pressure: "<<dbp<<endl;
 cout<<"Normal BP"<<endl;
}
else if ((sbp>=120 && sbp<=129) && (dbp<80))
{
 cout<<"Systolic Blood Pressure: "<<sbp<<'\t'<<"Diastolic Blood Pressure: "<<dbp<<endl;
 cout<<"Elevated BP"<<endl<<"Consult a doctor and take prescribed medicines properly."<<endl;
}
else if ((sbp>=130 && sbp<=139) || (dbp>=80 && dbp<=89))
{
 cout<<"Systolic Blood Pressure: "<<sbp<<'\t'<<"Diastolic Blood Pressure: "<<dbp<<endl;
 cout<<"High BP (Hypertension Stage 1)"<<endl<<"Consult a doctor immediately and take prescribed mediines without fail."<<endl;
 cout<<endl<<"Hypertension is a long term medical condition in which the blood pressure in the arteries is persistently elevated."<<endl;
 cout<<"High blood pressure does not have any symptons."<<endl;
 cout<<"Over time, if left untreated, it can cause health conditions such as heart disesase and stroke."<<endl;
}
else if ((sbp>=140 && sbp<180) || (dbp>=90 && dbp<120))
{
 cout<<"Systolic Blood Pressure: "<<sbp<<'\t'<<"Diastolic Blood Pressure: "<<dbp<<endl;
 cout<<"High BP (Hypertension Stage 2)"<<endl<<"Consult a doctor immediately and take prescribed medicines without fail."<<endl;
 cout<<endl<<"Hypertension is a long term medical condition in which the blood pressure in the arteries is persistently elevated."<<endl;
 cout<<"High blood pressure does not have any symptons."<<endl;
 cout<<"Over time, if left untreated, it can cause health conditions such as heart disesase and stroke."<<endl;
}
else if (sbp>=180 || dbp>=120)
{
 cout<<"Systolic Blood Pressure: "<<sbp<<'\t'<<"Diastolic Blood Pressure: "<<dbp<<endl;
 cout<<"Hypertensive crisis. Seek emergency care. Consult a miracle-performing doctor immediately and take prescribed medicines without fail or your heart will fail."<<endl;
 cout<<endl<<"Hypertension is a long term medical condition in which the blood pressure in the arteries is persistently elevated."<<endl;
 cout<<"High blood pressure does not have any symptons."<<endl;
 cout<<"Over time, if left untreated, it can cause health conditions such as heart disesase and stroke."<<endl;
}
getch(); clrscr();
//LDL Check
if (LDL<129)
 {
 cout<<"LDL: "<<LDL<<endl;
 cout<<"Normal"<<endl;
 }
else if (LDL>=129 && LDL<=159)
 {
 cout<<"LDL: "<<LDL<<endl;
 cout<<"Borderline high. Consult a doctor."<<endl;
 }
else if (LDL>=160 && LDL<=189)
 {
 cout<<"LDL: "<<LDL<<endl;
 cout<<"High. Consult a doctor immediately."<<endl<<endl;
 cout<<"High cholestrol can limit blood flow, increasing the risk of a heart attack or stroke. ";
 cout<<"High cholestrol may cause heart attack and stroke."<<endl;
 }
getch(); clrscr();
//HDL Check
if (HDL>=40 && HDL<60)
 {
 cout<<"HDL: "<<HDL<<endl;
 cout<<"Normal"<<endl;
 }
else if (HDL<40)
 {
 cout<<"HDL: "<<HDL<<endl;
 cout<<"Low. Increased risk of heart disease. Consult a doctor immediately."<<endl<<endl;
 cout<<"Smoking and lack of physical activity leads to lower HDL. Lower levels are associated with increased risk of cardiovascular death."<<endl;
 }
cout<<endl<<"HDL cholestrol is good cholestrol. A higher number means lower risk.";
getch(); clrscr();
//Platelet levels Check
if (plateletcount>=150000 && plateletcount<=450000)
 {
 cout<<"Platelet count: "<<plateletcount<<endl;
 cout<<"Normal"<<endl;
 }
else if (plateletcount>=450000)
 {
 cout<<"Platelet count: "<<plateletcount<<endl;
 cout<<"High. Thrombocytosis."<<endl<<endl;
 cout<<"Thrombocytosis is a condition in which there are an excessive number of platelets in the blood."<<endl;
 cout<<"Too many platelets can lead to certain conditions, including stroke, heart attack, or a clot in the blood vessels."<<endl;
 }
else if (plateletcount<150000)
 {
 cout<<"Platelet count: "<<plateletcount<<endl;
 cout<<"Low. Thrombocytopenia"<<endl<<endl;
 cout<<"Thrombocytopenia is a condition in which you have low blood platelet count."<<endl;
 cout<<"Symptoms can include severe bleeding and are possibly fatal if they're not treated."<<endl;
 }
 getch(); clrscr();
//Sodium Level Check
if (sodlevel>=135 && sodlevel<=145)
 {
 cout<<"Sodium level: "<<sodlevel<<endl;
 cout<<"Normal"<<endl;
 }
else if (sodlevel<135)
 {
 cout<<"Sodium level: "<<sodlevel<<endl;
 cout<<"Low. Hyponatremia"<<endl;
 cout<<"Hyponatremia is a condition that occurs when the body holds on to too much water.";
 cout<<" This dilutes the amount of sodium in the blood and causes levels to be low."<<endl;
 }
 getch(); clrscr();
//Potassium Level Check
if (potlevel>=3.5 && potlevel<=5)
 {
 cout<<"Potassium level: "<<potlevel<<endl;
 cout<<"Normal"<<endl;
 }
else if (potlevel>=5.1 && potlevel<=6)
 {
 cout<<"Potassium level: "<<potlevel<<endl;
 cout<<"Mildly high. Mild Hyperkalemia"<<endl;
 cout<<"Mild Hyperkalemia is asymptomatic."<<endl;
 }
else if (potlevel>=6.1 && potlevel<=7)
 {
  cout<<"Potassium level: "<<potlevel<<endl;
  cout<<"High. Hyperkalemia"<<endl;
  cout<<"Symptoms can include tiredness, numbness, nausea, chest pain and palpitations."<<endl;
 }
 getch(); clrscr();
//Diabetes Check
if (bsl>=80 && bsl<=100)
 {
 cout<<"Blood Sugar Level: "<<bsl<<endl;
 cout<<"Normal"<<endl;
 }
else if (bsl>=101 && bsl<=125)
 {
 cout<<"Blood Sugar Level: "<<bsl<<endl;
 cout<<"Impaired Glucose"<<endl;
 cout<<"Diabetes is a disease in which your blood sugar levels are too high. Glucose comes from the foods you eat. Insulin is a hormone that helps the glucose get into your cells to give them energy."<<endl;
 cout<<"If you're a person diagnosed with diabetes, make sure you visit a doctor as soon as possible and take all the prescribed medicines on time."<<endl;
 }
else if (bsl>=126)
 {
 cout<<"Blood Sugar Level: "<<bsl<<endl;
 cout<<"Diabetic"<<endl;
 cout<<"Diabetes is a disease in which your blood sugar levels are too high. Glucose comes from the foods you eat. Insulin is a hormone that helps the glucose get into your cells to give them energy."<<endl;
 cout<<"If you're a person diagnosed with diabetes, make sure you visit a doctor as soon as possible and take all the prescribed medicines on time."<<endl;
 }
}

char ch;
void test::file()
{
k.open("Patient_record.dat", ios::binary | ios::app);
p.input();
k.write((char*)&p, sizeof(p));
cout<<"Has patient taken a test?"<<endl;
cin>>ch;
if (ch=='y'||ch=='Y')
{
g.open("Test_details.dat", ios::binary | ios::app);
t.inputt();
g.write((char*)&t, sizeof(t));
g.close();
}
k.close();
}

void dispall()
{
k.open("Patient_record.dat", ios::binary|ios::in);
cout<<"Displaying all records..."<<endl;
while (k.read((char*)&p,sizeof(p)))
 {
 clrscr();
 p.display();
 getch();
 }
k.close();
}

void search()
{
int flag=0;
char sname[20];
k.open("Patient_record.dat", ios::binary|ios::in);
cout<<"Enter patient name to search for."<<endl;
gets(sname);
checkID=0;
while (k.read((char*)&p,sizeof(p)))
 {
 if (strcmpi(p.retname(),sname)==0)
  { p.display(); getch();
    checkID=p.retpatID();
    break; }
 }
k.close();
g.open("Test_details.dat", ios::binary|ios::in );
while (g.read((char*)&t,sizeof(t)))
 {
 if (checkID==t.retpatID())
    {
     flag=1;
     t.displayt();
     getch(); break; }
 }
 if (flag==0)
  { cout<<"Patient hasn't taken a test yet."<<endl; getch(); }
g.close();
}

void delrec()
{
 fstream o,l;
 int psidd;
 cout<<"Enter PatientID to delete patient record."<<endl;
 cin>>psidd;
 k.open("Patient_record.dat", ios::binary|ios::in);
 g.open("Test_details.dat",ios::binary|ios::in);
 o.open("TempP.dat", ios::binary|ios::out);
 l.open("TempT.dat", ios::binary|ios::out);

 while (k.read((char*)&p,sizeof(p)))
 {
 if (p.retpatID()!=psidd)
  { o.write((char*)&p,sizeof(p));  }
 }
k.close(); o.close();
remove("Patient_record.dat");
rename("TempP.dat","Patient_record.dat");

 while (g.read((char*)&t, sizeof(t)))
 {
 if (t.retpatID()!=psidd)
  { l.write((char*)&t,sizeof(t));  }
 }
g.close(); l.close();
remove("Test_details.dat");
rename("TempT.dat","Test_details.dat");
}

void update()
{
 cout<<"Do you want to delete a record?"<<endl;
 char a; cin>>a;
 if (a=='y'|| a=='Y')
  delrec();
 else
 {
 int flaug=0;
 fstream o;
 int psid;
 cout<<"Enter PatientID to update blood test results"<<endl;
 cin>>psid;
 k.open("Patient_record.dat", ios::binary|ios::in);
 g.open("Test_details.dat",ios::binary|ios::in);
 o.open("Temp.dat", ios::binary|ios::out);
 while (g.read((char*)&t, sizeof(t)))
 {
 if (t.retpatID()==psid)
  { t.inputt();
    o.write((char*)&t,sizeof(t));
    flaug=1;
    break; }
 else if (t.retpatID()>1)
  {
    o.write((char*)&t, sizeof(t));
    break;
  }
 }
 if (flaug==0)
  {
    t.inputt();
    o.write((char*)&t,sizeof(t));
  }
 k.close(); o.close(); g.close();
 remove("Test_details.dat");
 rename("Temp.dat","Test_details.dat");
 }
}

int chID;
void asearch()
{
cout<<"Enter patient ID to search to display the test analysis."<<endl;
cin>>chID; int fl=0;
k.open("Patient_record.dat", ios::binary|ios::in);
g.open("Test_details.dat", ios::binary|ios::in );
while (g.read((char*)&t,sizeof(t)))
 {
 if (chID==t.retpatID())
  { fl=1;
    while (k.read((char*)&p,sizeof(p)))
     {
     if (chID==p.retpatID())
       {
       chage=p.retage();
       strcpy(chagen,p.retgender());
       }
     }
    t.analysis();
    cout<<endl;
    getch();    }
 }
 if (fl==0)
  { cout<<"Patient hasn't taken a test yet."<<endl; getch(); }
g.close();
}

void main()
{
int gd=DETECT, gm;
int choice;
do
{
clrscr();
initgraph (&gd,&gm,"C:\\TC\\BGI");  //For graphics, especially alignment.

//Printed
cout<<setw(140)<<"MEDICAL RECORDS- HISTORY, REPORT AND ANALYSIS"<<endl<<endl<<endl;
line(120,40,480,40);
cout<<setw(200)<<"Please choose from the following:" <<endl
<<setw(200)<<'\t'<<"1. Add new patient record"<<endl
<<setw(200)<<'\t'<<"2. Display patient record"<<endl
<<setw(191)<<'\t'<<"3. Update record"<<endl
<<setw(202)<<'\t'<<"4. Show analysis of results"<<endl
<<setw(182)<<'\t'<<"5. Exit"<<endl;
rectangle(100,120,500,370);

cout<<endl<<endl<<"Enter your choice:"<<endl;
cin>>choice;
switch(choice)
{
case 1: { cleardevice();
	  closegraph();
	  t.file();
	  break;
	  }
case 2: { cleardevice();
	  closegraph();
	  char x;
	  cout<<"Display all patient records? "; cin>>ch;
	  if (ch=='y'|| ch=='Y')
	   dispall();
	  else
	   search();
	  break;
	  }
case 3: { cleardevice();
	  closegraph();
	  update();
	  break; }
case 4: { cleardevice();
	  closegraph();
	  asearch();
	  break; }
case 5: { exit(0);
	  break; }
default:{ cout<<"Invalid choice. Exiting program."<<endl;
	  exit(0); }
}
} while(choice<5);
getch();
cleardevice();
closegraph();
restorecrtmode();
}