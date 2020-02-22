#include "../include/Graph.h"
int main() {
    int n;
    cin>>n;
    Graph G(n);
    int e;
    cin>>e;
    int a,b,c;
    int val1=0,val2=0;
    while(e)
    {    
        cin>>a>>b>>c;
        G.insert(a-1,b-1,c);
        if(val1==0)
            val1=c;
        if(val1!=c)
            val2=c;
        e--;
    }
    G.val2=(val2)?val2:val1;
    G.val1=val1;
    int p;
    cin>>p;
    while(p)
    {   
        cin>>a>>b;
        G.insert(a-1,b-1,-1);
        p--;
    }
    G.buildcomponents();
    int g=G.returnsize();
    if(g>1)
    { 
      cout<<g<<" "<<G.findcost();
    }
    else
        cout<<-1;
    return 0;
}
