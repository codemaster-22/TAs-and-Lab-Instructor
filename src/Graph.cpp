#include "../include/Graph.h"
   Graph:: Graph(int x)
    {
        n=x;
        vector<pair<int,int> > p= vector<pair<int,int > >();
        while(x)
        {
            V.push_back(p);
            b.push_back(false);
            visited.push_back(-1);
            x--;
        }
        counter=0;
        counter1=0;
    }


long long int Graph::cost(const vector<int> &vv)
{
  int j=(val1>val2)?val1:val2;
    for(auto ii:vv)
    {
        for(int i=0;i<V[ii].size();++i)
        {
            if(V[ii][i].second==j)
                V[ii][i].second=-1;
        }
    }
    counter=0;
    counter1=0;
    int size=0;
    for(auto it:vv)
    {   
        if(!b[it])
            DFS(it,false);
        size++;
    }
    long long  int k=(j==val2)?val1:val2;
    return ((ll)size-counter)*k+(counter-1)*(ll)j;
}
int Graph::returnsize()
{
    int sum=0;
    for(auto it:components)
    {  
        if(sum<it.size())
            sum=it.size();
    }
    return sum;
}
void Graph::buildcomponents()
{   
    counter1=0;
    for(int i=0;i<n;++i)
    {
        if(!b[i])
        {
            DFS(i,true);
        }
    }
}
long long int Graph::findcost()
{   
    int j=returnsize();
    long long  int sum=0;
    for(int i=0;i<n;++i)
   {
       b[i]=false;
   }
    for(auto it:components)
    {   
        if(j==it.size())
        {   
           long long  int k=cost(it);
            if(sum==0)
                sum=k;
            if(sum>k)
                sum=k;
        }
    }
    return sum;
}
void Graph::DFS(int i,bool flag)
{
    vector<int> vv;
    counter1++;
    stack<int> S;
    S.push(i);
    bool g=true;
    while(!S.empty())
    {
        int j=S.top();
        S.pop();
        if(!b[j])
        {
          if(flag) vv.push_back(j);
            b[j]=true;
            visited[j]=counter1;
            for(auto it:V[j])
            {
                int x=it.first;
                int e=it.second;
                if(!b[x])
                {
                    if(e!=(-1))
                    {
                        S.push(x);
                    }
                }
                if(visited[x]==counter1)
                {
                    if(e==-1)
                        if(flag)
                            g=false;
                          
                }
            }
        }
    }
    if(flag&&g)
      components.push_back(vv);
    else
        counter++;
}
void Graph::insert(int u,int v,int z)
{
    V[u].push_back(pair<int,int>(v,z));
    V[v].push_back(pair<int,int>(u,z));
}
