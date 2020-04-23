#include <iostream> 
#include <stack> 
#include <vector>
#include <algorithm>

using namespace std; 

int main (){

int N[3]; 

stack <int> one;
stack <int> two;
stack <int> three;

int sumone = 0; 
int sumtwo = 0 ; 
int sumthree = 0;

for(int i=0; i<3; i++){
  cin>>N[i]; 
}

int f[N[0]];
int s[N[1]];
int t[N[2]];


for(int i=0; i<N[0]; i++){
  cin>>f[i]; 
  sumone+= f[i]; 
}


for(int i=0; i<N[1]; i++){
  cin>>s[i];
  sumtwo+= s[i]; 
}


for(int i=0; i<N[2]; i++){
  cin>>t[i]; 
  sumthree+= t[i];
}

for(int j=N[0]-1; j>=0; j--){
  one.push(f[j]);
}


for(int j=N[1]-1; j>=0; j--){
  two.push(s[j]);
}


for(int j=N[2]-1; j>=0; j--){
  three.push(t[j]);
}


bool checker = true; 

if(sumone == sumtwo && sumtwo == sumthree){
    checker = false; 
}

while (checker){
    if(sumone>=sumtwo && sumone>=sumthree){
    sumone -= one.top();
    one.pop();
    }
    else if(sumtwo>=sumone && sumtwo>=sumthree){
    sumtwo -= two.top();
    two.pop();
    }
    else if(sumthree>=sumtwo && sumthree>=sumone){
    sumthree -= three.top();
    three.pop();
    }

    if((sumone==sumtwo && sumtwo==sumthree) || (sumone == 0 && sumtwo ==0 && sumthree ==0)){
    checker = false; 
    }
}
cout<<sumone; 

}