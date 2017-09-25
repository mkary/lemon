#include <iostream>
#include <lemon/list_graph.h>
#include <lemon/lgf_writer.h>
#include <vector>

using namespace std;
using namespace lemon;

void bt(ListDigraph& g, ListDigraph::Node& s,vector<int>& result)
{
    static ListDigraph::NodeMap<bool> visited(g,false);
    if(visited[s] == true) return;
    if(visited[s] == false)
    {
        //cout << g.id(s) << endl;
        result.push_back(g.id(s));
        visited[s] = true;
    }
    ListDigraph::OutArcIt a(g, s);
    while(a!=INVALID)
    {
        ListDigraph::Node nextNode = g.target(a);
        bt(g,nextNode,result);
        ++a;
    }
    //return false backtrack
    //és ha vége hogyan ellenőrizzünk pl bool visszatérek
}

void test(vector<int>& result,int size)
{
    if(result.size() != size)
    {
        cout << "wrong " << result.size();
    }
    else
    {
        for(int i = 0; i < result.size()-1; ++i)
        {
            if(result[i]%(size/10) != result[i+1]/(size/100))
            {
                cout << result[i] << " " << result[i+1]<< endl;
            } else cout << result[i] << endl;
        }
    }
}

int main()
{
    typedef ListDigraph::Node Node;
    typedef ListDigraph::Arc Arc;

    ListDigraph g;

    Node n;
    vector<Node> Nodes;
    
    for(int i=0; i<100; ++i) {
        n = g.addNode();
        Nodes.push_back(n);
    }

    Arc a;
    for(int i=0; i<100; ++i)
    {
        for(int j=0; j<10; ++j)
        {
            a  = g.addArc(Nodes[i],Nodes[i%10*10+j]);
        }
    }

    /* for(int i=0; i<1000; ++i) {
        n = g.addNode();
        Nodes.push_back(n);
    }

    Arc a;
    for(int i=0; i<1000; ++i)
    {
        for(int j=0; j<10; ++j)
        {
            a  = g.addArc(Nodes[i],Nodes[i%100*10+j]);
            //cout << i << " " << i%100*10+j << endl;
        }
    } */

    vector<int> result;
    bt(g,Nodes[0],result);

    test(result,100);


   //digraphWriter(g).run();

}