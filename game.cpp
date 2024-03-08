#include<bits/stdc++.h>
using namespace std;


char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token= 'x';
bool tiee=false;
string s1="";
string s2="";

void functionOne()
{
  
  cout<< "   |       |     \n";
  cout<<" "<<space[0][0]<<" |  "<<space[0][1]<<"    |  "<<space[0][2]<<"  \n";
  cout<< "___|_______|_______\n";
  cout<< "   |       |     \n";
  cout<<" "<<space[0][0]<<" |  "<<space[0][1]<<"    |  "<<space[0][2]<<"  \n";
  cout<< "___|_______|_______\n";
  cout<< "   |       |     \n";
  cout<<" "<<space[0][0]<<" |  "<<space[0][1]<<"    |  "<<space[0][2]<<"  \n";
  cout<< "   |       |     \n";
  cout<<endl;
}

void functionTwo()
{
  int digit;

  if(token=='x')
  {
    cout<<s1<<": please enter: ";
    cin>>digit;
  }

  if(token=='0')
  {
    cout<<s2<<": please enter: ";
    cin>>digit;
  }

  if(digit==1)
  {
    row=0;
    column=0;
  }
  if(digit==2)
  {
    row=0;
    column=1;
  }
   if(digit==3)
  {
    row=0;
    column=2;
  }
   if(digit==4)
  {
    row=1;
    column=0;
  }
   if(digit==5)
  {
    row=1;
    column=1;
  }
   if(digit==6)
  {
    row=1;
    column=2;
  }
   if(digit==7)
  {
    row=2;
    column=0;
  }
   if(digit==8)
  {
    row=2;
    column=1;
  }
   if(digit==9)
  {
    row=2;
    column=2;
  }
  else if(digit<0 || digit>9)
  {
    cout<<" Invalid !!!"<<endl;
  }
  if(token=='x' && space[row][column]!='x' && space[row][column]!='0')
  {
    space[row][column]='x';
    token='0';
  }
  else if(token=='0' && space[row][column]!='x' && space[row][column]!='0')
  {
    space[row][column]='0';
    token='x';
  }
  else
  {
    cout<<" There is no empty space!"<<endl;
    functionTwo();
  }
  functionOne();
}


// bool functionThree()
// {
//   for(int i=0;i<3;i++)
//   {
//     if((space[i][0]==space[i][1] && space[i][0]==space[i][2])|| (space[0][i]==space[1][i]&&space[0][i]==space[2][i]))
//     {
//         return true;
//     }
//     if((space[0][0]==space[1][1] && space[1][1]==space[2][2])|| (space[0][2]==space[1][1]&&space[1][1]==space[2][0]))
//     {
//         return true;
//     }
//     for(int i=0;i<3;i++)
//     {
//       for(int j=0;j<3;j++)
//       {
//         if(space[i][j]!='x'&&space[i][j]!='0')
//         {
//           return false;
//         }
//       }
//     }
//     tiee=true;
//     return false;
//   }
// }

bool functionThree()
{
    for(int i=0;i<3;i++)
    {
        if((space[i][0]==space[i][1] && space[i][0]==space[i][2])|| (space[0][i]==space[1][i]&&space[0][i]==space[2][i]))
        {
            return true;
        }
    }
    
    if((space[0][0]==space[1][1] && space[1][1]==space[2][2])|| (space[0][2]==space[1][1]&&space[1][1]==space[2][0]))
    {
        return true;
    }
    
    // Check for tie condition
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(space[i][j]!='x'&&space[i][j]!='0')
            {
                return false;
            }
        }
    }
    
    // If no winner and no empty cells, it's a tie
    return true;
}

int main()
{
  cout<<"Enter the name of the first player : \n";
  getline(cin,s1);
  cout<<"Enter the name of the second player : \n";
  getline(cin,s2);
  cout<<s1<<" is player1 so he/she will play first \n";
  cout<<s2<<" is player2 so he/she will play second \n";

  while(!functionThree())
  {
    functionOne();
    functionTwo();
    functionThree();
  }

  if(token=='x' && tiee==false)
  {
    cout<<s1<<" wins!!"<<endl;
  }
  else if(token=='0' && tiee==false)
  {
    cout<<s2<<" wins!!"<<endl;
  }
  else
  {
    cout<<"It's a draw"<<endl;
  }
  return 0;
}

