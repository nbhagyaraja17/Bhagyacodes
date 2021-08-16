#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

class node{
    public:
    int val;
    node *next;
    node(int v = 0)
    {
        val = v;
        next = NULL;
    }
};

void append(int pos, node **root, int key){
    node *newtemp = new node(key);
    node *temp = new node();
    temp = *root;
    if(pos == 0){
        newtemp->next = *root;
        *root = newtemp;
        return;
    }
    else{
        int c = 0;
        while(c < pos-1)
        {
            temp = temp->next;
            c++;
        }
        newtemp->next = temp->next;
        temp->next = newtemp;
    }
}

void remove(int pos, node **root){
    node *temp = new node();
    temp = *root;
    if(pos == 0){
        *root = temp->next;
    }
    else{
        int c = 0;
        while(c < pos - 1){
            temp = temp->next;
            c++;
        }
        node *tempnex = temp->next;
        temp->next = tempnex->next;
    }
}

void print(node *root)
{
    node *temp = new node();
    temp = root;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
}
int len(node *root)
{
    if(root == NULL)return 0;
    return 1+len(root->next);
}
node middle(node *root)
{
    node *fas = new node();
    node *slo = new node();
    if(root->next == NULL)return *root;
    slo = root; fas = root->next;
    while(fas->next != NULL){
        slo = slo->next;
        fas = fas->next;
        if(fas->next)
        {
            fas = fas->next;
        }
    }
    return *slo;
}
void middle_split(node *root, node **l1, node **l2){
    node *fas;
    node *slo;
    if (root->next == NULL)
        return;
    slo = root;
    fas = root->next;
    while (fas->next != NULL)
    {
        slo = slo->next;
        fas = fas->next;
        if (fas->next)
        {
            fas = fas->next;
        }
    }
    *l1 = root;
    *l2 = slo->next;
    slo->next = NULL;
}

void reverse_linked_list(node *p, node **head)
{
    if(p == NULL){
        *head = NULL;return;
    }
    if(p->next == NULL){
        *head = p;
        return;
    }
    reverse_linked_list(p->next, head);
    p->next->next = p;
    p->next = NULL;
}

node* common_node(node *head1, node *head2){
    node *cur1 = head1;
    node *cur2 = head2;
    while(cur1 != NULL && cur2!= NULL){
        cur1=cur1->next;
        cur2=cur2->next;
    }
    node *temp1,*temp2;
    if(cur1 == NULL){
        swap(cur1, cur2);
        temp1 = head2;
        temp2 = head1;   
    }
    else{
        temp1 = head1;
        temp2 = head2;
    }  
    while(cur1 != NULL){
        cur1 = cur1->next;
        temp1=temp1->next;
    }
    while(temp1 != NULL && temp2 != NULL){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == temp2)return temp1;
    } 
}

node *merge_alternative_list(node *l1, node*l2){
    node *head = l1;
    node *temp1,*temp2;
    temp1 = l1; temp2 = l2;
    while(temp1!= NULL && temp2!=NULL){
        node *next1 = temp1->next;
        node *next2 = temp2->next;
        temp1->next = temp2;
        temp2->next = next1;
        temp1 = next1;
        temp2 = next2;
    }
    return head;
}
node *fold(node *head){
    if(head == NULL)return NULL;
    node *temp1, *temp2, *temp3;
    middle_split(head, &temp1, &temp2);
    reverse_linked_list(temp2, &temp3);
    print(temp3);cout<<"\n";
    return merge_alternative_list(temp1,temp3);
}

void divide(node *head, node **l1, node **l2){
    node *temp1 = head;
    node *temp2 = head->next;
    while(temp1->next->next != NULL && temp2->next->next != NULL)
    {
        temp1->next = temp1->next->next;
        temp2->next = temp2->next->next;
    }
    temp1->next = NULL;
    temp2->next = NULL;
    *l1 = head;
    *l2 = head->next;
}
node *merge_both(node *l1, node *l2){
    node *temp = l1;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = l2;
    return l1;
}
node *unfold(node *head){
    node *head1, *head2;
    divide(head, &head1, &head2);
    return merge_both(head1, head2);

}

void solve()
{
    node *head = new node(1);
    node *temp = new node(2);
    head->next = temp;
    append(0,&head, 0);
    append(1,&head, 3);
    append(1,&head, 4);
    // append(1,&head, 5);
    print(head); cout << "\n";
    cout << len(head) << "\n";
    cout << middle(head).val << "\n";
    reverse_linked_list(head, &head);
    print(head); cout << "\n";
    head = fold(head);
    head = unfold(head);
    print(head);
}

signed main()
{
    fast;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}