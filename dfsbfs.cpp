#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct node
{
    string c;
    node *next;
};

class graph
{
    public:
    int x;
     graph()
    {
      cout<<"Enter number of node:";
      cin>>x;
    }
    node *head[10];
    int visited[10]; 
    void initial();
    void create();
    void display();
    void bfs();
    void dfs();
};

void graph::initial()
{   
    for(int i=0;i<x;i++)
    {   head[i]=new node;
        head[i]->c='x';
        head[i]->next=NULL;
    }
}

void graph::create()
{
    int n;
    node *temp;
    for(int i=0;i<x;i++)
    {
            cout<<"Enter node:";
            cin>>head[i]->c;
           // visited[i]=head[i]->c;
            cout<<"Enter no of node are connected "<<head[i]->c<<":";
            cin>>n;

        for(int j=0;j<n;j++)
        {
            node *nnode=new node;
            nnode->next=NULL;
            cout<<"\nEnter connected node:"<<" ";
            cin>>nnode->c;
            temp=head[i];
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nnode;
        }
    }

}

void graph::display()
{
    node *temp=new node;
    for(int i=0;i<x;i++)
    {
        temp=head[i];
        cout<<temp->c<<": ";
        temp=temp->next;
        while(temp!=NULL)
        {
        cout<<" "<<temp->c;
        temp=temp->next; 
        } 
        cout<<endl;     
    }
}

void graph::bfs()
{
     node *temp;
     queue<string>q1;
     int flag=0,i=0;
    for(int i=0;i<x;i++)
     {
        visited[i]=0;
     }
     string a;

    temp=head[0];
    q1.push(head[0]->c);
    visited[0]=1;
   
    while(!q1.empty())
    {   
        a=q1.front();
        q1.pop();
        cout<<a;
        i=0;
      while(a!=head[i]->c)
        i++;

    //cout<<"2i2"<<i;       
    temp=head[i];
    while(temp!=NULL)
    {    i=0;
        while(temp->c!=head[i]->c)
            i++;
        
        //cout<<"3i3"<<i;
        if(visited[i]==0)
        {   
        visited[i]=1;
        q1.push(temp->c);
        } 
        temp=temp->next; 
     }
    }
    
}

void graph::dfs()
{
    node *temp;
    stack<string>q1;
     int flag=0,i=0,j=0,count=0;
    for(int i=0;i<x;i++)
     {
        visited[i]=0;
     }
     string a;

    temp=head[0];
    q1.push(head[0]->c);
    visited[0]=1;
    cout<<q1.top();
    count++;

    while(temp!=NULL)
    {
    //temp=temp->next;
    i=0;
    while(temp->c!=head[i]->c)
            i++;
    if(visited[i]==0)
    {
    q1.push(temp->c);
    cout<<temp->c;
    //count++;
    temp=head[i];
    visited[i]=1;
    }
     temp=temp->next;

    }
  

    while(!q1.empty())
    {
        a=q1.top();
        q1.pop();
        i=0;
    while(a!=head[i]->c)
            i++;
    temp=head[i];
    while(temp!=NULL)
    {  
         j=0;
         while(temp->c!=head[j]->c)
            j++;
        if(visited[j]==0)
        {   
            q1.push(temp->c);
            cout<<temp->c;
            visited[j]=1;
        }
        temp=temp->next;
    }

    }
}
int main()
{
    graph ob;
    ob.initial();
    ob.create();
    
    ob.display();
    cout<<"\n BFS: ";
    ob.bfs();
    cout<<"\n DFS: ";
   ob.dfs();
    return 0;
}