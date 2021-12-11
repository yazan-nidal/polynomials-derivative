#include<iostream>
using namespace std;
void parameterx(int &i,char x[100],char x1[100],int &b){
	int y;
	b=0;
	if(i==0)
	{y=i+1;}
	else
		{y=i+2;}
	int j=0;
	for (;x[i]!='x';i++)
	{ x1[j]=x[i];
	if (i>=y)
	{ b*=10;
	b+=(x1[j]-48);
	}
	else
		b=(x1[j]-48);
	j++;
	}
	x1[j]=NULL;
}//end parameterx
void pwoerx(int &i,char x[100],char x2[100],int &p){
	p=0;
i+=2;
int y=i+1;
int j=0;
for(;x[i]!='+'&&x[i]!='-'&&x[i]!=NULL;i++)
{ x2[j]=x[i];
if(i>=y)
{ p*=10;
p+=(x2[j]-48); }
else 
	p=(x2[j]-48);
j++;

}
x2[j]=NULL;
}//end powerx
void fun0(char x[100],int x3[100],int x4[100],int x5[100],int &j){
	char x1[100];
char x2[100];
int i=0;
int b=0;
int p=0;
j=0;
while(x[i]!=NULL){parameterx(i,x,x1,b);
pwoerx(i,x,x2,p);
x3[j]=p;
x4[j]=b;
x5[j]=x[i];
j++;}//storde parameterx in x4 and power x in x3 and signal in x5
for(int b=0;b<j;b++){if(x5[b]==45){x4[b+1]=x4[b+1]*(-1);}}//get parameterx signal indepand last signal
cout<<"\n";
int op1=0;
int op2=0;
for(int b=0;b<j;b++){for(int b1=b+1;b1<j;b1++){if(x3[b1]>x3[b]){op1=x3[b];
x3[b]=x3[b1];
x3[b1]=op1;
op2=x4[b];
x4[b]=x4[b1];
x4[b1]=op2;
}// swap power if x3[b1]>x3[b]
else{if(x3[b1]==x3[b]){if(x4[b1]>x4[b]){op1=x3[b];
x3[b]=x3[b1];
x3[b1]=op1;
op2=x4[b];
x4[b]=x4[b1];
x4[b1]=op2;
}}}// swap power in x3[b1]==x3[b] if x4[b1]>x4[b]
}}//finsh Arrangement
}//end fun0
void fun1(char x[100],char x1[100],char x2[100],int &b,int&p,double cpoint[100],int &cpcont){
	double mn=0;
	double su=0;
	double w=0;
	int w1=0;
	cpcont=0;
	for(double fg=100;fg>=-100;fg--){
		for(double rt=fg;rt>=(fg-1);rt=rt-0.01){ mn=0;
		for(int i=0;x[i]!=NULL;){ w1=i;
		parameterx(i,x,x1,b);
		pwoerx(i,x,x2,p);
		w=p-1;
		if(w==-1){(double)su=0;}
		else {
		su=(double)((double)p*(double)b)*pow(rt,(double)w);
		if(x[w1]=='-'){(double)mn=(double)mn-(double)su;}
		else{if(x[w1]=='+'){(double)mn=(double)mn+(double)su;}
		else{mn=su;}}}}
		if(mn==0){cpoint[cpcont]=(double)rt;
		cpcont++;}}
}//stored cirtical point in cpoint[cpcont]
}//end fun1
void fun2(int &cpcont,double cpoint[100],char x[100],char x1[100],char x2[100],int &b,int&p){
	int w1=0;
	double su=0;
	double mn1=0;
	int cpcont1=0;
	double mnp[20000];
	for(int si=0;si<=(cpcont-1);si++){
		for(int i=0;x[i]!=NULL;){ w1=i;
		parameterx(i,x,x1,b);
		pwoerx(i,x,x2,p);
		if(p==-1){(double)su=0;}
		else {
			double px=(double)cpoint[si];
		(double)su=(double)b*(double)pow((double)px,(double)p);
		if(x[w1]=='-'){(double)mn1=(double)mn1-(double)su;}
		else{if(x[w1]=='+'){mn1=mn1+su;}
		else{mn1=su;}}}}
		(double)mnp[cpcont1]=(double)mn1;
		cpcont1++;
	}//find f(x) for cirtical point
	for(int si1=0;si1<=(cpcont1-1);si1++){for(int si2=si1+1;si2<=(cpcont1-1);si2++){if(mnp[si2]>mnp[si1]){int tg=mnp[si1];
	mnp[si1]=mnp[si2];
	mnp[si2]=tg;
	}}}//Arrangement f(x) for cirtical point 
	cout<<"\n"<<mnp[0];// max value
}//end fun2
void print0(int x3[100],int x4[100],int j){for(int b=0;b<j;b++){
	if(x4[b]==0) {cout<<"0";
	if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}}
	else {
	int w;
	w=x3[b];
	switch (w) {
	case -1: { cout<<"0";
		if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}
		break ; }
	case 0:
		{ if(b==0){cout<<x4[b];}
		else{
			if(x4[b]<0){x4[b]=x4[b]*(-1);}
			cout<<x4[b];}
		if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}
			break ; }
	case 1:
		{if(b==0){if(x4[b]==1){cout<<"x";}else{ if(x4[b]==(-1)){cout<<"-x";}else cout<<x4[b]<<"x";}}
		else{if(x4[b]<0){x4[b]=x4[b]*(-1);}
			if(x4[b]==1){cout<<"x";}else{cout<<x4[b]<<"x";}}
		if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}
			break ; }
	default :{if(b==0){if(x4[b]==1){cout<<"x^"<<w;}else{ if(x4[b]==(-1)){cout<<"-x^"<<w;}else cout<<x4[b]<<"x^"<<w;}}
			 else {if(x4[b]<0){x4[b]=x4[b]*(-1);}
	if(x4[b]==1){cout<<"x^"<<w;}else{cout<<x4[b]<<"x^"<<w;}}
			 if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}}
	}}}}//end print0 to cout the palynomyal in arrangemnt
void print1(int x3[100],int x4[100],int j){for(int b=0;b<j;b++){
	if(x4[b]==0) {cout<<"0";
	if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}}
	else {

	int w;
	w=x3[b]-1;
	switch (w) {
	case -1: { cout<<"0";
		if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}
		break ; }
	case 0:
		{ if(b==0){cout<<x4[b]*x3[b];}
		else{
			if(x4[b]<0){x4[b]=x4[b]*(-1);}
			cout<<x4[b]*x3[b];}
		if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}
			break ; }
	case 1:
		{if(b==0){if((x4[b]*x3[b])==1){cout<<"x";}else{if((x4[b]*x3[b])==(-1)){cout<<"-x";}else cout<<x4[b]*x3[b]<<"x";}}
		else{if(x4[b]<0){x4[b]=x4[b]*(-1);}
			if((x4[b]*x3[b])==1){cout<<"x";}else{cout<<x4[b]*x3[b]<<"x";}}
		if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}
			break ; }
	default :{if(b==0){if((x4[b]*x3[b])==1){cout<<"x^"<<w;}else{if((x4[b]*x3[b])==(-1)){cout<<"-x^"<<w;}else cout<<x4[b]*x3[b]<<"x^"<<w;}}
			 else {if(x4[b]<0){x4[b]=x4[b]*(-1);}
			 if((x4[b]*x3[b])==1){cout<<"x^"<<w;}else{cout<<x4[b]*x3[b]<<"x^"<<w;}}
			 if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}}
	}}}}// print1 to cout drivet 1 in arrangemnt
void print2(int x3[100],int x4[100],int j)
{for(int b=0;b<j;b++){
	if(x4[b]==0) {cout<<"0";
	if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}}
	else {int w;
	w=x3[b]-2;
	switch (w) {
		case -2: { cout<<"0";
		if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}
		break ; }

	case -1: { cout<<"0";
		if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}
		break ; }
	case 0:
		{ if(b==0){cout<<x4[b]*x3[b]*(x3[b]-1);}
		else{if(x4[b]<0){x4[b]=x4[b]*(-1);}
			cout<<x4[b]*x3[b]*(x3[b]-1);}
		if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}
			break ; }
	case 1:
		{if(b==0){if((x4[b]*x3[b]*(x3[b]-1))==1){cout<<"x";}else{if((x4[b]*x3[b]*(x3[b]-1))==(-1)){cout<<"-x";}else cout<<x4[b]*x3[b]*(x3[b]-1)<<"x";}}
		else{if(x4[b]<0){x4[b]=x4[b]*(-1);}
			if((x4[b]*x3[b]*(x3[b]-1))==1){cout<<"x";}else{cout<<x4[b]*x3[b]*(x3[b]-1)<<"x";}}
		if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}
			break ; }
	default :{if(b==0){if(b==0){if((x4[b]*x3[b]*(x3[b]-1))==1){cout<<"x^"<<w;}else{if((x4[b]*x3[b]*(x3[b]-1))==(-1)){cout<<"-x^"<<w;}else cout<<x4[b]*x3[b]*(x3[b]-1)<<"x^"<<w;}}
			 else {
if(x4[b]<0){x4[b]=x4[b]*(-1);}
		if((x4[b]*x3[b]*(x3[b]-1))==1){cout<<"x^"<<w;}else{cout<<x4[b]*x3[b]*(x3[b]-1)<<"x^"<<w;}}
			 if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}}
			 }}}}}// print1 to cout drivet 2 in arrangemnt
void print3(int x3[100],int x4[100],int j){for(int b=0;b<j;b++){
	if(x4[b]==0) {cout<<"0";
	if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}}
	else {
	int w;
	w=x3[b]+1;
	double cv=0;
	switch (w) {
	case 1:
		{if(b==0){cv=(double)x4[b]/(double)w;
			if(cv==1){cout<<"x";}else{if(cv==-1){cout<<"-x";}else{cout<<cv<<"x";}}}
		else{if(x4[b]<0){x4[b]=x4[b]*(-1);}
			cv=(double)x4[b]/(double)w;
			if(cv==1){
				cout<<"x";}else{cout<<cv<<"x";}}
		if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}
			break ; }
	default :{if(b==0){cv=(double)x4[b]/(double)w;
			if(cv==1){cout<<"x^"<<w;}else{if(cv==-1){cout<<"-x^"<<w;}else{cout<<cv<<"x^"<<w;}}}
			 else {
		if(x4[b]<0){x4[b]=x4[b]*(-1);}
		cv=(double)x4[b]/(double)w;
			if(cv==1){
				cout<<"x^"<<w;}else{cout<<cv<<"x^"<<w;}}
			 if(x4[b+1]>0)cout<<"+";
	else {if(x4[b+1]<0)cout<<"-";}}
	}}}cout<<"+c\n";}
void main (){
char x[100];
char x1[100];
int i=0;
int b=0;//add to parametex
char x2[100];
int p=0;//add to powerx
int x3[100];
int x4[100];
int x5[100];
int j=0;//add to fun0
double cpoint[100];
int cpcont=0;//add to fun1 not thing add to fun2and print0 and print1 and print2 and print3
int q=0;//for switch mean
int li=0;
cout<<"\n\\-------------------------------------------------------------------\n";
	cout<<"	0. Insert a first or a new polynomial \n";
    cout<<"	1. Yor polynomials \n";
	cout<<"	2. First derivative\n";
	cout<<"	3. Scand derivative\n";
	cout<<"	4. Integration polynomials \n";
	cout<<"	5. Critical points \n";
	cout<<"	6. Max extreme value \n";
	cout<<"	7. End of program  \n";
cout<<"\\-------------------------------------------------------------------\n\n";
	q=0;
	cout<<"\n";
	while(q!=7){
	switch (q){case 0:{char l[100];
		cout<<"Please enter a polynomial in the format (ax^b +||- a1x^b1 :(a,a1,......)parameter ,(b,b1,..........)power :\n\n";
			cin>>l;
			for (li=0;l[li]!=NULL;li++){x[li]=l[li];}
			x[li]=NULL;
			   break;}
				case 1 :{ fun0(x,x3,x4,x5,j);
			print0(x3,x4,j);
		break;}
				case 2:{fun0(x,x3,x4,x5,j);
		print1(x3,x4,j);
	break ;}
		 case 3:{fun0(x,x3,x4,x5,j);
			print2(x3,x4,j);
		break ; }
			case 4:{fun0(x,x3,x4,x5,j);
			print3(x3,x4,j);
			   break ;}	  
				   case 5:{fun1(x,x1,x2,b,p,cpoint,cpcont);
			for(int jj=0;jj<=(cpcont-1);jj++){cout<<cpoint[jj]<<"\t";}
			   break;}
			   case 6:{fun1(x,x1,x2,b,p,cpoint,cpcont);
				   fun2(cpcont,cpoint,x,x1,x2,b,p);
			   break;}
			   default :{cout<<"\n error selected  "; }
	}//end switch maen
cout<<"\n\n\\-------------------------------------------------------------------\n\n";
		cout<<" other selected = "; 
	cin>>q;
	cout<<"\n";}//end while


}//end main
