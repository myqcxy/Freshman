#include <stdio.h>  
#include <stdlib.h>  
   
typedef int DataType;  
   
typedef struct B1Tree{  
    DataType data;  
    struct B1Tree *Tleft;  
    struct B1Tree *Tright;     
}*BTree;  
  
BTree CreateTree(); //����   
BTree insert(BTree root, DataType data);//����ڵ�   
void InBTree(BTree root); //�������   
void PreBTree(BTree root); //�������   
void PostBTree(BTree root);//�������   
BTree findPostion(BTree root, int deleteNode, int *flags);//Ѱ�Һ��ʵĲ����   
BTree delNode(BTree root, BTree parent, int flags); //ɾ�����ڵ�   
  
int main(){  
    BTree root = NULL;  
    int flags = 0;  
    int deleteNode = 0;   
    BTree parent = NULL;//��ɾ���ڵ�ĸ��ڵ�   
    char choiceAgain = 'Y';   
    root = CreateTree();  
    printf("\n�������: ");  
    InBTree(root);   
    printf("\nǰ�����: ");   
    PreBTree(root);  
    printf("\n�������: ");  
    PostBTree(root);  
    printf("\n");   
      
    do{   
        printf("��Ҫɾ���Ľڵ�: ");  
        scanf("%d", &deleteNode);   
        parent = findPostion(root, deleteNode, &flags);  
        root = delNode(root, parent, flags);   
        printf("ɾ����Ľ��: ");   
        printf("\n�������: ");  
        InBTree(root);   
        printf("\nǰ�����: ");  
        PreBTree(root);   
        printf("\n�������: ");  
        PostBTree(root);  
        choiceAgain = 'N';  
        printf("\nDelete Again(Y) or N?: ");  
        getchar();   
        scanf("%c", &choiceAgain);   
    }while(choiceAgain == 'Y' || choiceAgain == 'y');   
      
    printf("\nDone!\n");   
    return 0;   
}  
  
BTree CreateTree(){  
    BTree root = NULL;  
    DataType temp = 0;  
    printf("������ڵ�,��0��β:\n");   
    scanf("%d", &temp);   
    while(temp != 0){  
        root = insert(root, temp);    
        scanf("%d", &temp);    
    }  
      
    return root;   
}   
  
BTree insert(BTree root, DataType data){  
    BTree ptr = root;  
    BTree tempNode;   
    BTree newNode = (BTree)malloc(sizeof(struct B1Tree));   
    newNode->data = data ;  
    newNode->Tleft = NULL;  
    newNode->Tright = NULL;  
      
    if(ptr == NULL){  
        return newNode;   
    }else{  
        while(ptr != NULL){  
            tempNode = ptr;   
            if(ptr->data >= data){  
                ptr = ptr->Tleft;   
            }else{  
                ptr = ptr->Tright;   
            }   
        }   
          
        if(tempNode->data >= data){  
            tempNode->Tleft =  newNode;   
        }else{  
            tempNode->Tright =  newNode;   
        }   
    }  
    return root;   
}  
  
BTree findPostion(BTree root, int deleteNode, int *flags){  
    BTree parentNode = root;  
    BTree temp = root;   
    *flags = 0;  
      
    while(temp != NULL){  
        if(temp->data == deleteNode){  
            return parentNode;         
        }else{  
            parentNode = temp;   
            if(temp->data > deleteNode){  
                temp = temp->Tleft;  
                *flags = -1;   
            }else{  
                temp = temp->Tright;   
                *flags = 1;  
            }  
        }      
    }  
      
    return NULL;   
}   
  
BTree delNode(BTree root, BTree parent, int flags){  
    BTree deleteNode = NULL;  
       
    if(parent == NULL){  
        printf("δ�ҵ�ɾ���Ľڵ�!\n");  
        return root;   
    }  
      
    switch(flags){  
    case -1:  
        deleteNode = parent->Tleft;  
        break;  
    case 0:  
        deleteNode = parent;  
        break;  
    case 1:   
        deleteNode = parent->Tright;  
        break;  
    default:  
        printf("ERROR!\n");   
        exit(1);   
    }  
      
    if(deleteNode->Tleft == NULL && deleteNode->Tright == NULL){  
        if(parent->Tleft == deleteNode){  
            parent->Tleft = NULL;   
        }else if(parent->Tright == deleteNode){  
            parent->Tright = NULL;   
        }else{  
            parent = NULL;   
        }   
        free(deleteNode);  
    }else if(deleteNode->Tleft == NULL && deleteNode->Tright != NULL){  
        if(deleteNode->data == root->data){  
            root = deleteNode->Tright;   
        }else{  
            if(parent->Tleft->data == deleteNode->data){  
                parent->Tleft = deleteNode->Tright;  
            }else{  
                parent->Tright = deleteNode->Tright;  
            }  
        }   
        free(deleteNode);  
    }else if(deleteNode->Tleft != NULL && deleteNode->Tright == NULL){  
        if(deleteNode->data == root->data){  
            root = deleteNode->Tleft;  
        }else{  
            if(parent->Tleft->data == deleteNode->data){  
                parent->Tleft = deleteNode->Tleft;  
            }else{  
                parent->Tright = deleteNode->Tleft;  
            }  
        }  
        free(deleteNode);  
    }else{  
        BTree temp = deleteNode->Tleft;  
        BTree tempParent = deleteNode;  
        while(temp->Tright != NULL){  
            tempParent = temp;  
            temp = temp->Tright;  
        }  
          
        deleteNode->data = temp->data;  
        if(tempParent->Tleft == temp){  
            tempParent->Tleft = temp->Tleft;    
        }else{  
            tempParent->Tright = temp->Tleft;  
        }  
          
        printf("temp = %d\n", temp->data);  
        free(temp);  
    }   
      
    return root;      
}   
  
void InBTree(BTree root){  
    if(root != NULL){  
        InBTree(root->Tleft);   
        printf("%d ", root->data);   
        InBTree(root->Tright);  
    }  
}  
  
void PreBTree(BTree root){  
    if(root != NULL){  
        printf("%d ", root->data);   
        PreBTree(root->Tleft);   
        PreBTree(root->Tright);  
    }  
}   
  
void PostBTree(BTree root){  
    if(root != NULL){  
        PostBTree(root->Tleft);   
        PostBTree(root->Tright);  
        printf("%d ", root->data);  
    }  
}
