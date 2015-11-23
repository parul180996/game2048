#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

class game{

	int s[4][4];

	public :
	  void start();
	  void press(char ch);
	  void left();
	  void right();
	  void up();
	  void down();
	  void end();
	  void create();
	  void check();
	  void display();

} ;

void game :: display(){
  int i,j;

  for(i=0;i<4;i++){
    cout<<"\n";
    for(j=0;j<4;j++)
      cout<<"     "<<s[i][j];
  }
}

void game :: start(){

  int i,j,i1=0,i2=0,j1=0,j2=0;

  while(i1==i2 && j1==j2){
    i1 = rand()%4;  i2 = rand()%4;   j1 = rand()%4;   j2 = rand()%4;
  }
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){

      if(i==i1 && j==j1)
	s[i][j] = 2;

      else if(i==i2 && j==j2)
	s[i][j] = 2;

      else
	s[i][j] = 0;
    }
  }
  display();
}

void game :: create(){
  int i,j,num;

  do{
    i = rand()%4;  j = rand()%4;
  } while(s[i][j] != 0);

  num = (rand()%2 + 1)*2;

  s[i][j] = num;

  display();
}

void game :: press(char c){

  switch(c){
    case 'a' : left();
    break;
    case 'w' : up();
    break;
    case 's' : right();
    break;
    case 'z' : down();
    break;
    case 'p' : exit(0);
  }
}

void game :: check(){
  int flag=0,key=0,i,j;

  for(i=0;i<4;i++){
    for(j=0;j<4;j++){

      if (s[i][j] == 2048){
	cout<<"\n  You have won the game !!";
	getch();
	exit(0);
      }
      if(s[i][j] == 0)
	flag=1;
    }
  }
  if(flag == 0){
    for(i=0;i<4;i++){
      for(j=0;j<3;j++){
	if(s[i][j]==s[i][j+1])
	  key=1;
      }
    }
    for(j=0;j<4;j++){
      for(i=0;i<3;i++){
	if(s[i][j]==s[i+1][j])
	  key=1;
      }
    }
  }
  if(flag == 1 || key ==1)
    create();
}

void game :: left(){
  int flag=0,key=0,i,j,temp;

  for(i=0;i<4;i++){
    for(j=1;j<4;j++){
      temp = j;
      while(s[i][j]>0 && s[i][j-1]==0 && j>0){
	key = 1;
	s[i][j-1]=s[i][j];
	s[i][j]=0;
	j--;
      }
      j=temp;
    }
  }

  for(i=0;i<4;i++){
    flag = 0;
    for(j=1;j<4;j++){
      temp = j;
      if(flag == 0){
	if(s[i][j] == s[i][j-1] && s[i][j]!=0){
	  key = 1;
	  flag=1;
	  s[i][j-1] += s[i][j];
	  while(j<3){
	    s[i][j] = s[i][j+1];
	    j++;
	  }
	  s[i][j] = 0;
	}
      }
      j = temp;
    }
  }
  if(key == 1)
    check();
}

void game :: right(){
  int flag=0,key=0,i,j,temp;

  for(i=0;i<4;i++){
    for(j=2;j>=0;j--){
      temp = j;
      while(s[i][j]>0 && s[i][j+1]==0 && j<3){
	key = 1;
	s[i][j+1]=s[i][j];
	s[i][j]=0;
	j++;
      }
      j=temp;
    }
  }

  for(i=0;i<4;i++){
    flag = 0;
    for(j=2;j>=0;j--){
      temp = j;
      if(flag == 0){
	if(s[i][j] == s[i][j+1] && s[i][j] !=0){
	  key = 1;
	  flag=1;
	  s[i][j+1] += s[i][j];
	  while(j>0){
	    s[i][j] = s[i][j-1];
	    j--;
	  }
	  s[i][j] = 0;
	}
      }
      j = temp;
    }
  }
  if(key == 1)
    check();
}

void game :: down(){
  int flag=0,key=0,i,j,temp;

  for(j=0;j<4;j++){
    for(i=2;i>=0;i--){
      temp = i;
      while(s[i][j]>0 && s[i+1][j]==0 && i<3){
	key = 1;
	s[i+1][j]=s[i][j];
	s[i][j]=0;
	i++;
      }
      i=temp;
    }
  }

  for(j=0;j<4;j++){
    flag = 0;
    for(i=2;i>=0;i--){
      temp = i;
      if(flag == 0){
	if(s[i][j] == s[i+1][j] && s[i][j]!=0){
	  key = 1;
	  flag=1;
	  s[i+1][j] += s[i][j];
	  while(i>0){
	    s[i][j] = s[i-1][j];
	    i--;
	  }
	  s[i][j] = 0;
	}
      }
      i = temp;
    }
  }
  if(key == 1)
    check();
}

void game :: up(){
  int flag=0,key=0,i,j,temp;

  for(j=0;j<4;j++){
    for(i=1;i<4;i++){
      temp = i;
      while(s[i][j]>0 && s[i-1][j]==0 && i>0){
	key = 1;
	s[i-1][j]=s[i][j];
	s[i][j]=0;
	i--;
      }
      i=temp;
    }
  }

  for(j=0;j<4;j++){
    flag = 0;
    for(i=1;i<4;i++){
      temp = i;
      if(flag == 0){
	if(s[i][j] == s[i-1][j] && s[i][j] != 0){
	  key = 1;
	  flag=1;
	  s[i-1][j] += s[i][j];
	  while(i<3){
	    s[i][j] = s[i+1][j];
	    i++;
	  }
	  s[i][j] = 0;
	}
      }
      i = temp;
    }
  }
  if(key == 1)
    check();
}

void main(){
  char ch;

  game p;

  clrscr();

  cout<<"\n\t\t\t\t2048" ;

  cout<<"\n Use a,s,w,z to move and p to exit :=) ";
  cout<<"\n If nothing moves after pressing all keys, you have lost :=( You may exit \n\n";

  p.start();

  cin>>ch;

  while(1){
    p.press(ch);
    cin>>ch;
  }
}