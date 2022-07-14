//Matthew Buehring
//11/23/2021
//Algorithms
//Dr. Huang

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void swap(int *x, int *y)//function for swapping the integers in the queue
{
        int temp = *x;
        *x = *y;
        *y = temp;
}


class miniheap
{
       
public:

        int *priorityqueue; // array of elements pointer/access to queue
        int MAXSIZE; 
        int SIZE; 
       
        miniheap(int MAXSIZE);

       
        void miniheapify(int newsize);//does a minheapify on a subtree
		
		
        void dKey(int index);//deletes key
		
		
        void deckey(int index, int newvalue);//decreases key value

		
        void inKey(int key);//inserts a key
		
		 
        int rightnodes(int index) //gets the right nodes
		{ 
		   return (2 * index + 2); 
		}
		
		 
        int exMinroot();//extracts the roots

        int parentnodes(int index) //gets parent nodes
		{ 
		   return (index - 1) / 2; 
		}


		 int getMinkey() 
		{ 
		    return priorityqueue[0]; //root and would be at first index
		}

       
        int leftnodes(int index)//gets the left nodes
		{ 
		  return (2 * index + 1);
		}

       void print() {
                for (int i = 0; i < SIZE; ++i) {
                        cout << priorityqueue[i] << " ";
                }
                cout << endl;

                return;
        }

};



void miniheap::miniheapify(int i)
{
        int l = leftnodes(i);//sets left and right nodes
        int r = rightnodes(i);
        int smallest = i;//holds the smallest element
        if (l < SIZE && priorityqueue[l] < priorityqueue[i])
                smallest = l;
        if (r < SIZE && priorityqueue[r] < priorityqueue[smallest])
                smallest = r;
        if (smallest != i)
        {
                swap(&priorityqueue[i], &priorityqueue[smallest]);
                miniheapify(smallest);
        }
}



miniheap::miniheap(int newsize)
{
        SIZE = 0;
        MAXSIZE = newsize;
        priorityqueue = new int[newsize];
}




void miniheap::deckey(int i, int new_val)
{
        priorityqueue[i] = new_val;
        while (i != 0 && priorityqueue[parentnodes(i)] > priorityqueue[i])
        {
                swap(&priorityqueue[i], &priorityqueue[parentnodes(i)]);
                i = parentnodes(i);
        }
}





void miniheap::dKey(int i)
{
        deckey(i, INT_MIN);//decrements key with call
        exMinroot();
}


// Inserts a new key 'k'
void miniheap::inKey(int k)
{
        if (SIZE == MAXSIZE)
        {
                cout << "cannot insert key";
                return;
        }

        
        SIZE++;
        int i = SIZE - 1;
        priorityqueue[i] = k;//insert new key at end

      
        while (i != 0 && priorityqueue[parentnodes(i)] > priorityqueue[i])
        {
                swap(&priorityqueue[i], &priorityqueue[parentnodes(i)]);
                i = parentnodes(i);
        }
}





int miniheap::exMinroot()
{
        if (SIZE <= 0)
                return INT_MAX;
        if (SIZE == 1)
        {
                SIZE--;
                return priorityqueue[0];
        }

       
        int root = priorityqueue[0];//store min value and remove it
        priorityqueue[0] = priorityqueue[SIZE - 1];
        SIZE--;
        miniheapify(0);

        return root;
}


int main()
{
	
        srand(time(NULL));
        miniheap obj(20);//heap size of 20

        for (int i = 0; i < 20; ++i) //put everything into the queue and make it random from 11 to 31
		{
                int tempnumbers = 11 + rand() % 21;
                obj.inKey(tempnumbers);
        }

	  
	   obj.print();
      
                      
        

        return 0;
}