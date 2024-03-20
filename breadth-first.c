void BFS(VLink G[ ], int v)  // BFS algorithm starting from source v in G
{ int w;
   visit v; d[v]=0;    ADDQ(Q, v);            // v is added into queue Q
   while (!EMPTYQ(Q))     // while queue Q is not empty, visit other vertices
  { v=DELQ(Q);          // the front is deleted from queue Q
     Get the first adjacent vertex w for vertex v ( if there is no adjacent vertex for v, w=-1);
     while (w != -1) 
    {  if (d[w] == -1)       // if vertex w hasn’t been visited
      {  visit w;
         ADDQ(Q,w);     // adjacent vertex w is added into queue Q
         d[w] =d[v]+1;    // distance d[w]
      }
      Get the next adjacent vertex w for vertex v;
    }
  }  
}
