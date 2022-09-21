#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
  int elem;
  node *next = NULL;
};

/* Implement the shuffle function here */
node *shuffle(node *head, int N)
{
  int len = 0;
  node *curr_node = head;
  if (N == 0)
  {
    return head;
  }

  node *middle_node = head;
  curr_node = head;
  for (int i = 1; i < N / 2; i++)
  {
    curr_node = curr_node->next;
  }
  middle_node = curr_node;
  curr_node = head;
  for (int i = 0; i < N / 2 - 1; i++)
  {
    node *n2_node = middle_node->next;
    node *n1_node = curr_node->next;
    middle_node->next = middle_node->next->next;
    curr_node->next = n2_node;
    n2_node->next =n1_node;
    curr_node = curr_node->next->next;
  }
  return head;
}

int main()
{
  int N, i;
  node *n;
  node *tail = NULL;
  node *head = NULL;
  cin >> N;
  for (i = 0; i < N; i++)
  {
    n = new node;
    cin >> n->elem;
    n->next = NULL;
    if (tail != NULL)
      tail->next = n;
    if (head == NULL)
      head = n;
    tail = n;
  }
  node *iter = shuffle(head, N);
  for (i = 0; i < N; i++)
  {
    cout << iter->elem << " ";
    iter = iter->next;
  }
}
