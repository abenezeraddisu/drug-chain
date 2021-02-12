#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    /* data */
    char value[80];
    struct node* left;
    struct node* right;
};

struct node* search (struct node* head, char string[]){
    if(head ==NULL) return NULL; 
    if(strcmp(head->value, string)==0) return head; 
    struct node* s1 = search(head->left, string);
    if(s1!=NULL) return s1;

    struct node* s2 = search(head->right, string);
    if(s2!=NULL) return s2;

}
void BST(struct node* child, struct node* curr){
        if(curr->left==NULL && curr->right == NULL) curr->left = child;
        else if(curr->left!=NULL){
            struct node* lft = curr -> left;
           if((strcmp(lft->value, child->value)<0)){
               curr->right = child;
           }
           else if((strcmp(lft->value, child->value)>0)){
               curr->left = child;
               curr->right = lft;
           }
        }
    }
void printer(struct node* head){
    if(head!=NULL){
        printf("%s\n", head->value);
        printer(head->left);
        
        printer(head-> right);
    }
}
void freeAll(struct node* head){
    if(head==NULL) return;
    struct node* lf = head-> left;
    struct node* rt = head-> right;
    free(head);
    freeAll(lf);
    freeAll(rt);

}
int main(int argc, char* argv[]){
    struct node* head = (struct node*) malloc(sizeof(struct node));
    char father[] = "First User";
    strcpy(head->value, father); //strcpy
    head ->right = NULL;
    head->left= NULL;
    struct node* temp = head;
  
    int len = 80;
    char new_addict[len];
    char introducer[len];
    FILE* ptr = fopen(argv[1], "r");
    if(ptr==NULL) return 0;
    while(fscanf(ptr, "%s", new_addict)!=EOF){
        if(strcmp(new_addict, "DONE")==0)break;
        fscanf(ptr, "%s", introducer);
        struct node* child = (struct node*) malloc(sizeof(struct node));
        strcpy(child->value, new_addict);  //strcpy
        child->right = NULL;
        child->left=    NULL;

        struct node* curr = search(temp, introducer);  
        BST(child, curr);
    }
    fclose(ptr);
    printer(head);
    freeAll(head);
    return 0;
}
