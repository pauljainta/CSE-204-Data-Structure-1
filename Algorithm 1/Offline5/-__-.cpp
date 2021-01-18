#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define Infinity 999999999;
class leaf
{

public:
 leaf * l;
 leaf * r;
 double f;
 string ch;
 string hcode;


};


vector<leaf>Array;


leaf  findMin()
{
     double temp = Infinity;
     vector<leaf>::iterator i1,i2;
    for(i1 =Array.begin();i1!=Array.end();i1++)
    {

         if(temp>(*i1).f)
          {
            i2 = i1;
            temp = (*i1).f;
          }

    }



 leaf tempNode = (*i2);
 Array.erase(i2);



 return tempNode;
}



leaf Tree()
{




 while(!Array.empty())
 {


   leaf * tempNode = new leaf;
    leaf * tempNode1 = new leaf;
   leaf * tempNode2 = new leaf;
      *tempNode1 = findMin();
   *tempNode2 = findMin();


   tempNode->l = tempNode1;
   tempNode->r = tempNode2;
   tempNode->f = tempNode1->f+tempNode2->f;
   Array.push_back(*tempNode);
   if(Array.size() == 1)
   {
    break;
   }
 }
    return Array[0];
}







void constCode(leaf * temproot,string s)
{
   leaf * root1 = new leaf;
   root1 = temproot;

   root1->hcode = s;
    if(root1->l == NULL && root1->r == NULL)
   {

    cout<<root1->ch<<"  "<<root1->hcode<<endl;
   }
   else
   {

      root1->l->hcode = s.append("0");
   s.erase(s.end()-1);
   root1->r->hcode = s.append("1");
   s.erase(s.end()-1);


      constCode(root1->l,s.append("0"));
   s.erase(s.end()-1);
      constCode(root1->r,s.append("1"));
   s.erase(s.end()-1);
 }

}








void Code()
{


 int size,i;
 double tempDouble;
 string tempString = "";

 cin>>size;

 for(i = 0;i<size;i++)
 {
  leaf tempNode;
  cin>>tempString;
  cin>>tempDouble;


  tempNode.f = tempDouble;
  tempNode.ch = tempString;
  tempNode.l = NULL;
  tempNode.r= NULL;
  Array.push_back(tempNode);
 }


 leaf root = Tree();


 constCode(&root,"");

}


int main()
{

 Code();
 return 0;
}



